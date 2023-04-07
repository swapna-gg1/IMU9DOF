/*
 * MikroSDK - MikroE Software Development Kit
 * Copyright© 2020 MikroElektronika d.o.o.
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
 * OR OTHER DEALINGS IN THE SOFTWARE. 
 */

/*!
 * \file
 *
 */

#include "c9dof3.h"

// ------------------------------------------------------------- PRIVATE MACROS 

#define C9DOF3_DUMMY 0

// ---------------------------------------------- PRIVATE FUNCTION DECLARATIONS 

static void c9dof3_i2c_write ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len );

static void c9dof3_i2c_read ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len );

static void c9dof3_spi_write ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len );

static void c9dof3_spi_read ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len );

static void dev_soft_reset_delay ( void );

static void dev_mag_wake_up_delay ( void );

static void dev_set_slave_addr ( c9dof3_t *ctx );

static void dev_start_chip_select ( c9dof3_t *ctx );

static void dev_stop_chip_select ( c9dof3_t *ctx );

// ------------------------------------------------ PUBLIC FUNCTION DEFINITIONS

void c9dof3_cfg_setup ( c9dof3_cfg_t *cfg )
{
    // Communication gpio pins 

    cfg->scl  = HAL_PIN_NC;
    cfg->sda  = HAL_PIN_NC;
    cfg->sck  = HAL_PIN_NC;
    cfg->miso = HAL_PIN_NC;
    cfg->mosi = HAL_PIN_NC;
    cfg->cs1  = HAL_PIN_NC;
    cfg->cs2  = HAL_PIN_NC;
    cfg->cs3  = HAL_PIN_NC;
    
    // Additional gpio pins

    cfg->int_pin = HAL_PIN_NC;

    cfg->i2c_speed   = I2C_MASTER_SPEED_FULL;
    cfg->i2c_address = C9DOF3_ACC_I2C_SLAVE_ADDRESS;

    cfg->spi_speed   = 100000;
    cfg->spi_mode    = SPI_MASTER_MODE_0;
    cfg->cs_polarity = SPI_MASTER_CHIP_SELECT_POLARITY_ACTIVE_LOW;

    cfg->drv_sel = C9DOF3_DRV_SEL_SPI;
}

void c9dof3_drv_interface_selection ( c9dof3_cfg_t *cfg, c9dof3_drv_t drv_sel ) 
{
    cfg->drv_sel = drv_sel;
}

C9DOF3_RETVAL c9dof3_init ( c9dof3_t *ctx, c9dof3_cfg_t *cfg )
{
    // Only in case it is necessary to check somewhere which communication is set
    ctx->drv_sel = cfg->drv_sel;

    // Output pins 
    
    digital_out_init( &ctx->cs1, cfg->cs1 );
    digital_out_init( &ctx->cs2, cfg->cs2 );
    digital_out_init( &ctx->cs3, cfg->cs3 );
    
    digital_out_high( &ctx->cs1 );
    digital_out_high( &ctx->cs2 );
    digital_out_high( &ctx->cs3 );
    
    // Input pins

    digital_in_init( &ctx->int_pin, cfg->int_pin );
    
    if ( ctx->drv_sel == C9DOF3_DRV_SEL_I2C ) 
    {
        i2c_master_config_t i2c_cfg;

        i2c_master_configure_default( &i2c_cfg );

        i2c_cfg.scl = cfg->scl;
        i2c_cfg.sda = cfg->sda;

        ctx->slave_address = cfg->i2c_address;

        if ( i2c_master_open( &ctx->i2c, &i2c_cfg ) == I2C_MASTER_ERROR ) 
        {
            return I2C_MASTER_ERROR;
        }

        if ( i2c_master_set_slave_address( &ctx->i2c, ctx->slave_address ) == I2C_MASTER_ERROR ) 
        {
            return I2C_MASTER_ERROR;
        }

        if ( i2c_master_set_speed( &ctx->i2c, cfg->i2c_speed ) == I2C_MASTER_ERROR ) 
        {
            return I2C_MASTER_ERROR;
        }

        ctx->read_f  = c9dof3_i2c_read;
        ctx->write_f = c9dof3_i2c_write;
    } 
    else 
    {
        spi_master_config_t spi_cfg;

        spi_master_configure_default( &spi_cfg );

        spi_cfg.sck  = cfg->sck;
        spi_cfg.miso = cfg->miso;
        spi_cfg.mosi = cfg->mosi;

        ctx->chip_select = cfg->cs1;

        if ( spi_master_open( &ctx->spi, &spi_cfg ) == SPI_MASTER_ERROR ) 
        {
            return SPI_MASTER_ERROR;
        }

        if ( spi_master_set_default_write_data( &ctx->spi, C9DOF3_DUMMY ) == SPI_MASTER_ERROR ) 
        {
            return SPI_MASTER_ERROR;
        }

        if ( spi_master_set_mode( &ctx->spi, cfg->spi_mode ) == SPI_MASTER_ERROR ) 
        {
            return SPI_MASTER_ERROR;
        }

        if ( spi_master_set_speed( &ctx->spi, cfg->spi_speed ) == SPI_MASTER_ERROR ) 
        {
            return SPI_MASTER_ERROR;
        }

        spi_master_set_chip_select_polarity( cfg->cs_polarity );
        spi_master_deselect_device( ctx->chip_select );

        ctx->read_f  = c9dof3_spi_read;
        ctx->write_f = c9dof3_spi_write;
    }
    
    return C9DOF3_OK;
}

void c9dof3_default_cfg ( c9dof3_t *ctx )
{
    uint8_t write_data;

    // Accel Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_ACCEL;
    write_data = C9DOF3_INITIATED_SOFT_RESET;
    c9dof3_generic_write ( ctx, C9DOF3_REG_ACC_BGW_SOFTRESET, &write_data, 1 );
    dev_soft_reset_delay( );
  
    // Gyro Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_GYRO;
    c9dof3_generic_write( ctx, C9DOF3_REG_GYRO_BGW_SOFTRESET, &write_data, 1 );
    dev_soft_reset_delay( );
  
    // Mag Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_MAG;
    write_data = C9DOF3_MAG_POW_CTL_SOFT_RESET;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_PWR_CNTL1, &write_data, 1 );
    dev_soft_reset_delay( );

    // Accel Default Configuration
    // Select Accel PMU Range( +-2 )
    ctx->sel_mode = COMMUNICATION_MODE_ACCEL;
    write_data = C9DOF3_ACC_RANGE_2;
    c9dof3_generic_write( ctx, C9DOF3_REG_ACC_PMU_RANGE, &write_data, 1 );
    
    // Select Accel PMU_BW   ( 7.81Hz )
    write_data = C9DOF3_ACC_PMU_BW_7_81;
    c9dof3_generic_write( ctx, C9DOF3_REG_ACC_PMU_BW, &write_data, 1 );
  
    // Select Accel PMU_LPW  ( NomalMode, SleepDuration 0.5ms )
    write_data =  C9DOF3_ACC_PMU_LPW_MODE_NOMAL | C9DOF3_ACC_PMU_LPW_SLEEP_DUR_0_5MS;
    c9dof3_generic_write( ctx, C9DOF3_REG_ACC_PMU_LPW, &write_data, 1 );

    // Gyro Default Configuration
    // Select Gyro Range( 262.4 LSB/�/s )
    ctx->sel_mode = COMMUNICATION_MODE_GYRO;
    write_data = C9DOF3_GYRO_RANGE_262_4;
    c9dof3_generic_write( ctx, C9DOF3_REG_GYRO_RANGE, &write_data, 1 );
    
    // Select Gyro BW   ( 32Hz )
    write_data = C9DOF3_GYRO_BW_32;
    c9dof3_generic_write( ctx, C9DOF3_REG_GYRO_BW, &write_data, 1 );
    
    // Select Gyro LPM1 ( NomalMode, SleepDuration 2ms )
    write_data = C9DOF3_GYRO_LPM1_MODE_NOMAL | C9DOF3_GYRO_LPM1_SLEEP_DUR_2MS;
    c9dof3_generic_write( ctx, C9DOF3_REG_GYRO_LPM1, &write_data, 1 );

    // Mag Default Configuration
    // Set sleep mode
    ctx->sel_mode = COMMUNICATION_MODE_MAG;
    write_data = C9DOF3_MAG_POW_CTL_SLEEP_MODE;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_PWR_CNTL1, &write_data, 1 );
    dev_mag_wake_up_delay( );
  
    // Adv. st., DataRate, OperationMode, SelfTest ( NomalMode, ODR 10Hz )
    write_data = C9DOF3_MAG_DATA_RATE_10;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_PWR_CNTL2, &write_data, 1 );
    
    // Repetitions for X-Y Axis: 0x04 -> ( 1 + 2 ( 2 ^ 2 ) ) = 9
    write_data = C9DOF3_MAG_XY_REPET_9;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_REP_XY, &write_data, 1 );
    
    // Repetition for Z-Axis: 0x0F -> ( 1 +( 2 ^ 0 + 2 ^ 1 + 2 ^ 2 + 2 ^ 3) = 15
    write_data = C9DOF3_MAG_Z_REPET_15;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_REP_Z, &write_data, 1 );
}

void c9dof3_generic_write ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    ctx->write_f( ctx, reg, data_buf, len ); 
}

void c9dof3_generic_read ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    ctx->read_f( ctx, reg, data_buf, len );
}

uint8_t c9dof3_check_communication ( c9dof3_t *ctx )
{
    uint8_t accel_id;
    uint8_t gyro_id;
    uint8_t mag_id;
    uint8_t comm_status;
    uint8_t write_data;

    // Accel Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_ACCEL;
    write_data = C9DOF3_INITIATED_SOFT_RESET;
    c9dof3_generic_write ( ctx, C9DOF3_REG_ACC_BGW_SOFTRESET, &write_data, 1 );
    dev_soft_reset_delay( );
  
    // Gyro Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_GYRO;
    c9dof3_generic_write( ctx, C9DOF3_REG_GYRO_BGW_SOFTRESET, &write_data, 1 );
    dev_soft_reset_delay( );
  
    // Mag Soft Reset
    ctx->sel_mode = COMMUNICATION_MODE_MAG;
    write_data = C9DOF3_MAG_POW_CTL_SOFT_RESET;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_PWR_CNTL1, &write_data, 1 );
    dev_soft_reset_delay( );
    
    write_data = C9DOF3_MAG_POW_CTL_SLEEP_MODE;
    c9dof3_generic_write( ctx, C9DOF3_REG_MAG_PWR_CNTL1, &write_data, 1 );
    dev_mag_wake_up_delay( );
    
    comm_status = 0;

    ctx->sel_mode = COMMUNICATION_MODE_ACCEL;
    c9dof3_generic_read( ctx, C9DOF3_REG_ACC_WHO_AM_I, &accel_id, 1 );

    if ( accel_id == C9DOF3_ACC_DEVICE )
    {
        accel_id = C9DOF3_ID_CHECK_SUCCESS;
    }
    else
    {
        accel_id = C9DOF3_ID_CHECK_ERROR;
    }

    ctx->sel_mode = COMMUNICATION_MODE_GYRO;
    c9dof3_generic_read( ctx, C9DOF3_REG_GYRO_WHO_AM_I, &gyro_id, 1 );

    if ( gyro_id == C9DOF3_GYRO_DEVICE )
    {
        gyro_id = C9DOF3_ID_CHECK_SUCCESS;
    }
    else
    {
        gyro_id = C9DOF3_ID_CHECK_ERROR;
    }
    
    ctx->sel_mode = COMMUNICATION_MODE_MAG;
    c9dof3_generic_read( ctx, C9DOF3_REG_MAG_WHO_AM_I, &mag_id, 1 );

    if ( mag_id == C9DOF3_MAG_DEVICE )
    {
        mag_id = C9DOF3_ID_CHECK_SUCCESS;
    }
    else
    {
        mag_id = C9DOF3_ID_CHECK_ERROR;
    }
    
    comm_status = accel_id;
    comm_status <<= 1;
    comm_status |= gyro_id;
    comm_status <<= 1;
    comm_status |= mag_id;
    
    return comm_status;
}


void c9dof3_read_accel_data ( c9dof3_t *ctx, c9dof3_accel_t *accel_data )
{
    uint8_t rx_buf[ 6 ];
    uint16_t tmp;
    int16_t sign_res;

    ctx->sel_mode = COMMUNICATION_MODE_ACCEL;
    c9dof3_generic_read( ctx, C9DOF3_REG_ACC_DATA_START, rx_buf, 6 );

    tmp = rx_buf[ 1 ];
    tmp <<= 8;
    tmp |= rx_buf[ 0 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 4;
    accel_data->x = sign_res;

    tmp = rx_buf[ 3 ];
    tmp <<= 8;
    tmp |= rx_buf[ 2 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 4;
    accel_data->y = sign_res;

    tmp = rx_buf[ 5 ];
    tmp <<= 8;
    tmp |= rx_buf[ 4 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 4;
    accel_data->z = sign_res;
}

void c9dof3_read_gyro_data ( c9dof3_t *ctx, c9dof3_gyro_t *gyro_data )
{
    uint8_t rx_buf[ 6 ];
    uint16_t tmp;
    int16_t sign_res;

    ctx->sel_mode = COMMUNICATION_MODE_GYRO;
    c9dof3_generic_read( ctx, C9DOF3_REG_GYRO_DATA_START, rx_buf, 6 );

    tmp = rx_buf[ 1 ];
    tmp <<= 8;
    tmp |= rx_buf[ 0 ];
    sign_res = ( int16_t ) tmp;
    gyro_data->x = sign_res;

    tmp = rx_buf[ 3 ];
    tmp <<= 8;
    tmp |= rx_buf[ 2 ];
    sign_res = ( int16_t ) tmp;
    gyro_data->y = sign_res;

    tmp = rx_buf[ 5 ];
    tmp <<= 8;
    tmp |= rx_buf[ 4 ];
    sign_res = ( int16_t ) tmp;
    gyro_data->z = sign_res;
}

void c9dof3_read_mag_data ( c9dof3_t *ctx, c9dof3_mag_t *mag_data )
{
    uint8_t rx_buf[ 6 ];
    uint16_t tmp;
    int16_t sign_res;

    ctx->sel_mode = COMMUNICATION_MODE_MAG;
    c9dof3_generic_read( ctx, C9DOF3_REG_MAG_DATA_START, rx_buf, 6 );

    tmp = rx_buf[ 1 ];
    tmp <<= 8;
    tmp |= rx_buf[ 0 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 3;
    mag_data->x = sign_res;

    tmp = rx_buf[ 3 ];
    tmp <<= 8;
    tmp |= rx_buf[ 2 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 3;
    mag_data->y = sign_res;

    tmp = rx_buf[ 5 ];
    tmp <<= 8;
    tmp |= rx_buf[ 4 ];
    sign_res = ( int16_t ) tmp;
    sign_res >>= 3;
    mag_data->z = sign_res;
}

void c9dof3_get_data ( c9dof3_t *ctx, c9dof3_accel_t *accel_data, c9dof3_gyro_t *gyro_data, c9dof3_mag_t *mag_data )
{
    c9dof3_read_accel_data( ctx, accel_data );
    
    c9dof3_read_gyro_data( ctx, gyro_data );

    c9dof3_read_mag_data( ctx, mag_data );
}

uint8_t c9dof3_check_interrupt ( c9dof3_t *ctx )
{
    return digital_in_read( &ctx->int_pin );
}

// ----------------------------------------------- PRIVATE FUNCTION DEFINITIONS

static void c9dof3_i2c_write ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    uint8_t tx_buf[ 257 ];
    uint8_t cnt;

    tx_buf[ 0 ] = reg;

    for ( cnt = 1; cnt <= len; cnt++ ) 
    {
        tx_buf[ cnt ] = data_buf[ cnt - 1 ];
    }
    dev_set_slave_addr( ctx );

    i2c_master_write( &ctx->i2c, tx_buf, len + 1 );
}

static void c9dof3_i2c_read ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    dev_set_slave_addr( ctx );
    
    i2c_master_write( &ctx->i2c, &reg, 1 );
    i2c_master_read( &ctx->i2c, data_buf, len );
}

static void c9dof3_spi_write ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    uint8_t tx_buf[ 257 ];
    uint8_t cnt;

    tx_buf[ 0 ] = reg & C9DOF3_BIT_MASK_SPI_CMD_WRITE;
    for ( cnt = 1; cnt <= len; cnt++ )
    {
        tx_buf[ cnt ] = data_buf[ cnt - 1 ]; 
    }

    dev_start_chip_select( ctx );
    spi_master_write( &ctx->spi, tx_buf, len + 1 );
    dev_stop_chip_select( ctx );    
}

static void c9dof3_spi_read ( c9dof3_t *ctx, uint8_t reg, uint8_t *data_buf, uint8_t len )
{
    uint8_t tx_buf;

    tx_buf = reg | C9DOF3_BIT_MASK_SPI_CMD_READ;
    
    dev_start_chip_select( ctx );
    spi_master_write_then_read( &ctx->spi, &tx_buf, 1, data_buf, len );
    dev_stop_chip_select( ctx );  
}

static void dev_soft_reset_delay ( void )
{
    Delay_1ms( );
    Delay_1ms( );
}

static void dev_mag_wake_up_delay ( void )
{
    Delay_100ms();
}

static void dev_set_slave_addr ( c9dof3_t *ctx )
{
    switch ( ctx->sel_mode )
    {
        case COMMUNICATION_MODE_ACCEL:
        {
            ctx->slave_address = C9DOF3_ACC_I2C_SLAVE_ADDRESS;
            break;
        }
        case COMMUNICATION_MODE_GYRO:
        {
            ctx->slave_address = C9DOF3_GYRO_I2C_SLAVE_ADDRESS;
            break;
        }
        case COMMUNICATION_MODE_MAG:
        {
            ctx->slave_address = C9DOF3_MAG_I2C_SLAVE_ADDRESS;
            break;
        }
        default:
        {
            ctx->slave_address = C9DOF3_ACC_I2C_SLAVE_ADDRESS;
            break;
        }
    }
    
    i2c_master_set_slave_address( &ctx->i2c, ctx->slave_address );
    Delay_1ms( );
}

static void dev_start_chip_select ( c9dof3_t *ctx )
{
    switch ( ctx->sel_mode )
    {
        case COMMUNICATION_MODE_ACCEL:
        {
            digital_out_low( &ctx->cs1 );
            break;
        }
        case COMMUNICATION_MODE_GYRO:
        {
            digital_out_low( &ctx->cs2 );
            break;
        }
        case COMMUNICATION_MODE_MAG:
        {
            digital_out_low( &ctx->cs3 );
            break;
        }
        default:
        {
            digital_out_low( &ctx->cs1 );
            break;
        }
    }
    Delay_1ms( );
}

static void dev_stop_chip_select ( c9dof3_t *ctx )
{
    switch ( ctx->sel_mode )
    {
        case COMMUNICATION_MODE_ACCEL:
        {
            digital_out_high( &ctx->cs1 );
            break;
        }
        case COMMUNICATION_MODE_GYRO:
        {
            digital_out_high( &ctx->cs2 );
            break;
        }
        case COMMUNICATION_MODE_MAG:
        {
            digital_out_high( &ctx->cs3 );
            break;
        }
        default:
        {
            digital_out_high( &ctx->cs1 );
            digital_out_high( &ctx->cs2 );
            digital_out_high( &ctx->cs3 );
            break;
        }
    }
    Delay_1ms( );
}

// ------------------------------------------------------------------------- END

