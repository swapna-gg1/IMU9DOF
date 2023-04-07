/*******************************************************************************
  Inertial Measurement Unit Sensor abstraction layer Driver Implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_imu.c

  Summary:
    Source code for the IMU sensor driver.

  Description:
    This file contains the source code for setup of the IMU sensor module BMX055. 
    It allows application to read accel, gyro and mag sensor data.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "driver/imu/drv_imu.h"
#include "driver/imu/drv_accel_regs.h"
#include "driver/imu/drv_gyro_regs.h"
#include "driver/imu/drv_mag_regs.h"
#include "system/time/sys_time.h"
#include "driver/spi/drv_spi.h"
/* SPI bus driver handle for ACCEL */
static DRV_HANDLE drvSPIHandle_ACCEL;
/* SPI bus driver handle for Gyro */
static DRV_HANDLE drvSPIHandle_GYRO;
/* SPI bus driver handle for Mag */
static DRV_HANDLE drvSPIHandle_MAG;
/* SPI bus setup */
DRV_SPI_TRANSFER_SETUP  accel_setup;
DRV_SPI_TRANSFER_SETUP  gyro_setup;
DRV_SPI_TRANSFER_SETUP  mag_setup;

/* SPI Transfer handle */
DRV_SPI_TRANSFER_HANDLE accel_transferHandle;
DRV_SPI_TRANSFER_HANDLE gyro_transferHandle;
DRV_SPI_TRANSFER_HANDLE mag_transferHandle;
static volatile bool _transferLock;
static volatile bool _transferSuccess;

static inline void _sleep(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    
    while (SYS_TIME_DelayIsComplete(timer) == false);
}
static void SPI_Accel_EventHandler( DRV_SPI_TRANSFER_EVENT event,
                                   DRV_SPI_TRANSFER_HANDLE transferHandle,
                                   uintptr_t context)
{
    _transferSuccess = (event == DRV_SPI_TRANSFER_EVENT_COMPLETE);
    
    _transferLock = false;
}

static void SPI_Gyro_EventHandler( DRV_SPI_TRANSFER_EVENT event,
                                   DRV_SPI_TRANSFER_HANDLE transferHandle,
                                   uintptr_t context)
{
    _transferSuccess = (event == DRV_SPI_TRANSFER_EVENT_COMPLETE);
    
    _transferLock = false;
}

static void SPI_Mag_EventHandler( DRV_SPI_TRANSFER_EVENT event,
                                   DRV_SPI_TRANSFER_HANDLE transferHandle,
                                   uintptr_t context)
{
    _transferSuccess = (event == DRV_SPI_TRANSFER_EVENT_COMPLETE);
    
    _transferLock = false;
}

static bool _write(BMX055_Sensor sensor, uint8_t addr, uint8_t val)
{
    uint8_t buf[2];
    bool status= true;
    buf[0] = addr;
    buf[1] = val;
  
    uint32_t timeout = 0;
    _transferLock = true;
    
    switch(sensor)
    {
        case BMX055_ACCEL:
            DRV_SPI_WriteTransferAdd(drvSPIHandle_ACCEL, buf, 2, &accel_transferHandle);
            if(accel_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
        case BMX055_GYRO:
            DRV_SPI_WriteTransferAdd(drvSPIHandle_GYRO, buf, 2, &gyro_transferHandle);
            if(gyro_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
        case BMX055_MAG:
            DRV_SPI_WriteTransferAdd(drvSPIHandle_MAG, buf, 2, &mag_transferHandle);
            if(mag_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
    }
       
    if (status == false)
        return false;
    
    while(_transferLock == true)
    {
        timeout += 1;
        
        if(timeout == 100000)
        {
            break;
        }
    }
    
    return _transferSuccess;
}





static bool _read(BMX055_Sensor sensor, 
                  uint8_t addr,
                  uint8_t* readBuf,
                  uint32_t sz)
{
    bool status= true;
    uint8_t addrBuf;
    addrBuf = addr;
    _transferLock = true;
    switch(sensor)
    {
        case BMX055_ACCEL:
            DRV_SPI_WriteReadTransferAdd(drvSPIHandle_ACCEL, &addrBuf, 1,readBuf, sz, &accel_transferHandle);
            if(accel_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
        case BMX055_GYRO:
            DRV_SPI_WriteReadTransferAdd(drvSPIHandle_GYRO, &addrBuf, 1, readBuf, sz, &gyro_transferHandle);
            if(gyro_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
        case BMX055_MAG:
            DRV_SPI_WriteReadTransferAdd(drvSPIHandle_MAG, &addrBuf, 1, readBuf, sz, &mag_transferHandle);
            if(mag_transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID)
                status = false;
            break;
    }
 
    if (status == false)
        return false;
   
    
    while(_transferLock == true);
    return _transferSuccess;
}



void _config_sensor(BMX055_Sensor imu_sensor)
{
    uint8_t write_data;
    switch(imu_sensor)
    {
        case BMX055_ACCEL:
            /* Accel PMU Range( +-2 ) */
            write_data = BMX055_ACC_RANGE_2;
            _write( BMX055_ACCEL, BMX055_REG_ACC_PMU_RANGE, write_data );
            /* Accel PMU_BW   ( 7.81Hz ) */
            write_data = BMX055_ACC_PMU_BW_7_81;
            _write( BMX055_ACCEL, BMX055_REG_ACC_PMU_BW, write_data );
            /* Accel Low Power Mode - Normal Mode, SleepDuration 0.5ms */
            write_data = BMX055_ACC_PMU_LPW_MODE_NOMAL | BMX055_ACC_PMU_LPW_SLEEP_DUR_0_5MS;
            _write( BMX055_ACCEL, BMX055_REG_ACC_PMU_LPW, write_data );
            break;
        case BMX055_GYRO:
            /* Gyro Angular rate range and res( 262.4 LSB/deg/s ) */
            write_data = BMX055_GYRO_RANGE_262_4;
            _write(BMX055_GYRO, BMX055_REG_GYRO_RANGE, write_data );
            /* Gyro BW   ( 32Hz ) */
            write_data = BMX055_GYRO_BW_32;
            _write(BMX055_GYRO, BMX055_REG_GYRO_BW, write_data );
            /* Gyro set LP mode - NomalMode, SleepDuration 2ms */
            write_data = BMX055_GYRO_LPM1_MODE_NOMAL | BMX055_GYRO_LPM1_SLEEP_DUR_2MS;
            _write(BMX055_GYRO, BMX055_REG_GYRO_LPM1, write_data );
            break;
        case BMX055_MAG:
            /* Set Mag sleep mode */
            write_data = BMX055_MAG_POW_CTL_SLEEP_MODE;
            _write(BMX055_MAG, BMX055_REG_MAG_PWR_CNTL1, write_data );
            /* DataRate, OperationMode, SelfTest ( NomalMode, ODR 10Hz ) */
            write_data = BMX055_MAG_DATA_RATE_10;
            _write(BMX055_MAG, BMX055_REG_MAG_PWR_CNTL2, write_data );
            /* Repetitions for X-Y Axis: 0x04 -> ( 1 + 2 ( 2 ^ 2 ) ) = 9 */
            write_data = BMX055_MAG_XY_REPET_9;
            _write(BMX055_MAG, BMX055_REG_MAG_REP_XY, write_data );
            /* Repetition for Z-Axis: 0x0F -> ( 1 +( 2 ^ 0 + 2 ^ 1 + 2 ^ 2 + 2 ^ 3) = 15 */
            write_data = BMX055_MAG_Z_REPET_15;
            _write(BMX055_MAG, BMX055_REG_MAG_REP_Z, write_data );
            break;                        
    }
}


int _check_sensors_id(void)
{
    uint8_t accel_id[2];
    uint8_t gyro_id[2];
    uint8_t mag_id[2];
    uint8_t temp1, temp2;
    _read(BMX055_ACCEL, BMX055_REG_ACC_WHO_AM_I, accel_id, 2 );
    temp1 = (accel_id[0]<<7)|accel_id[1]>>1;
    if ( temp1 != BMX055_ACCEL_CHIP_ID )
    {
        //return 0;
    }
    _read(BMX055_GYRO, BMX055_REG_GYRO_WHO_AM_I, gyro_id, 2 );
    temp2 = (gyro_id[0]<<7)|gyro_id[1]>>1;
    if ( temp2 != BMX055_GYRO_CHIP_ID )
    {
        return 0;
    }
    _read(BMX055_MAG, BMX055_REG_MAG_WHO_AM_I, mag_id,  2);
   // if ( mag_id != BMX055_MAG_CHIP_ID )
    {
        //return 0;
    }
    return 1;
}

static void _reset_all_sensors(void)
{
     uint8_t write_data = BMX055_INITIATED_SOFT_RESET;
    /* Reset the Accel */
    _write(BMX055_ACCEL, BMX055_REG_ACC_BGW_SOFTRESET, write_data );
    _sleep(2);
    /* Reset the Gyro */
    _write(BMX055_GYRO, BMX055_REG_GYRO_BGW_SOFTRESET, write_data );
    _sleep(2);
    write_data = BMX055_MAG_POW_CTL_SOFT_RESET;
    _write(BMX055_MAG, BMX055_REG_MAG_PWR_CNTL1, write_data );
    _sleep(2);
    write_data = BMX055_MAG_POW_CTL_SLEEP_MODE;
    _write(BMX055_MAG, BMX055_REG_MAG_PWR_CNTL1, write_data );
    _sleep(100);
}

void _bmx055_spi_init(void)
{
    CS_ACCEL_Set();
    CS_ACCEL_Clear();
    CS_GYRO_Set();
    CS_GYRO_Clear();
    CS_MAG_Set();
    CS_MAG_Clear();
    drvSPIHandle_ACCEL = DRV_SPI_Open(DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE);
    drvSPIHandle_GYRO = DRV_SPI_Open(DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE);
    drvSPIHandle_MAG = DRV_SPI_Open(DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE);

    accel_setup.baudRateInHz = 100000;
    accel_setup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_TRAILING_EDGE;
    accel_setup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
    accel_setup.dataBits      = DRV_SPI_DATA_BITS_8;
    accel_setup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;
    accel_setup.chipSelect    = (SYS_PORT_PIN)CS_ACCEL_PIN;
    
    gyro_setup.baudRateInHz = 100000;
    gyro_setup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_TRAILING_EDGE;
    gyro_setup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
    gyro_setup.dataBits      = DRV_SPI_DATA_BITS_8;
    gyro_setup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;
    gyro_setup.chipSelect    = (SYS_PORT_PIN)CS_GYRO_PIN;
    
    mag_setup.baudRateInHz = 100000;
    mag_setup.clockPhase    = DRV_SPI_CLOCK_PHASE_VALID_TRAILING_EDGE;
    mag_setup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
    mag_setup.dataBits      = DRV_SPI_DATA_BITS_8;
    mag_setup.csPolarity    = DRV_SPI_CS_POLARITY_ACTIVE_LOW;
    mag_setup.chipSelect    = (SYS_PORT_PIN)CS_MAG_PIN;
    
    DRV_SPI_TransferSetup(drvSPIHandle_ACCEL, &accel_setup);
    DRV_SPI_TransferSetup(drvSPIHandle_GYRO, &gyro_setup);
    DRV_SPI_TransferSetup(drvSPIHandle_MAG, &mag_setup);
    DRV_SPI_TransferEventHandlerSet(drvSPIHandle_ACCEL, SPI_Accel_EventHandler, (uintptr_t)0);
    DRV_SPI_TransferEventHandlerSet(drvSPIHandle_GYRO, SPI_Gyro_EventHandler, (uintptr_t)0);
    DRV_SPI_TransferEventHandlerSet(drvSPIHandle_MAG, SPI_Mag_EventHandler, (uintptr_t)0);
}

// *****************************************************************************
// *****************************************************************************
// Section: IMU Sensor Driver Common Interface Implementation called by the ap
// *****************************************************************************
// *****************************************************************************
void DRV_BMX055_Get_Data(BMX055_Sensor sensor, BMX055_data_t *data_buff)
{
    uint8_t rx_buf[ 6 ];
    uint8_t imu_sensor_data_reg;
    uint16_t tmp;
    uint16_t sign_res;
    BMX055_data_t sensor_data;
    switch(sensor)
    {
        case BMX055_ACCEL:
            imu_sensor_data_reg = BMX055_REG_ACC_DATA_START;
            break;
        case BMX055_GYRO:
            imu_sensor_data_reg = BMX055_REG_GYRO_DATA_START;
            break;
        case BMX055_MAG:
            imu_sensor_data_reg = BMX055_REG_MAG_DATA_START;
            break;                        
    }
    _read(sensor, imu_sensor_data_reg, rx_buf, 6 );
#if 0
    /* Fix bit shifts */
    uint8_t t0, t1;
    t0 = rx_buf[0] & 1;
    t1 = rx_buf[1] & 1;
    rx_buf[ 1 ] = rx_buf[1] >> 1 | (t0 <<7);
    rx_buf[ 0 ] = rx_buf[0] >> 1 | (t1 <<7);
    
    t0 = rx_buf[2] & 1;
    t1 = rx_buf[3] & 1;
    rx_buf[ 3 ] = rx_buf[3] >> 1 | (t0 <<7);
    rx_buf[ 2 ] = rx_buf[2] >> 1 | (t1 <<7);
    
    t0 = rx_buf[4] & 1;
    t1 = rx_buf[5] & 1;
    rx_buf[ 5 ] = rx_buf[5] >> 1 | (t0 <<7);
    rx_buf[ 4 ] = rx_buf[4] >> 1 | (t1 <<7);
       
    /* END */
#endif    
    
    tmp = rx_buf[ 1 ];
    tmp <<= 8;
    tmp |= rx_buf[ 0 ];
    sign_res = ( int16_t ) tmp;
    sensor_data.x = sign_res;

    tmp = rx_buf[ 3 ];
    tmp <<= 8;
    tmp |= rx_buf[ 2 ];
    sign_res = ( int16_t ) tmp;
    sensor_data.y = sign_res;

    tmp = rx_buf[ 5 ];
    tmp <<= 8;
    tmp |= rx_buf[ 4 ];
    sign_res = ( int16_t ) tmp;
    sensor_data.z = sign_res;
    *data_buff = sensor_data;
}


int DRV_BMX055_Init(void)
{
    int ret = 0;
    _bmx055_spi_init();
    /* Perform soft reset of all sensors - Accel, Gyro, Mag */
    _reset_all_sensors();        
   
    /* Check if the BMX055 is connected by checking the WHO_AM_I registers
        of Accel, Gyro and Mag */
    ret = _check_sensors_id(); 
    //if (ret ==0)
    //    return 0;
   _reset_all_sensors();
    /* Set Accel default configuration */
    _config_sensor(BMX055_ACCEL);
    /* Set Gyro default configuration */
    _config_sensor(BMX055_GYRO);
    /* Set Mag default configuration */
    _config_sensor(BMX055_MAG);
    _sleep(100);

    return 1;
}