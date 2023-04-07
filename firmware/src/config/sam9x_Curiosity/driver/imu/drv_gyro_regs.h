/*******************************************************************************
  BMX055 IMU Sensor module GYRO Registers

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gyro_regs.h

  Summary:
    BMX055 IMU Sensor module GYRO Registers File

  Description:
    The header file contains the BMX055 IMU sensor GYRO register mapping.
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

#ifndef DRV_GYRO_REGS_H
#define DRV_GYRO_REGS_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END
        
#define BMX055_REG_GYRO_WHO_AM_I                                    0x00
#define BMX055_REG_GYRO_DATA_START                                  0x02
#define BMX055_REG_GYRO_RATE_X_LSB                                  0x02
#define BMX055_REG_GYRO_RATE_X_MSB                                  0x03
#define BMX055_REG_GYRO_RATE_Y_LSB                                  0x04
#define BMX055_REG_GYRO_RATE_Y_MSB                                  0x05
#define BMX055_REG_GYRO_RATE_Z_LSB                                  0x06
#define BMX055_REG_GYRO_RATE_Z_MSB                                  0x07
#define BMX055_REG_GYRO_INT_STATUS_0                                0x09
#define BMX055_REG_GYRO_INT_STATUS_1                                0x0A
#define BMX055_REG_GYRO_INT_STATUS_2                                0x0B
#define BMX055_REG_GYRO_INT_STATUS_3                                0x0C
#define BMX055_REG_GYRO_FIFO_STATUS                                 0x0E
#define BMX055_REG_GYRO_RANGE                                       0x0F
#define BMX055_REG_GYRO_BW                                          0x10
#define BMX055_REG_GYRO_LPM1                                        0x11
#define BMX055_REG_GYRO_LPM2                                        0x12
#define BMX055_REG_GYRO_RATE_HBW                                    0x13
#define BMX055_REG_GYRO_BGW_SOFTRESET                               0x14
#define BMX055_REG_GYRO_INT_EN_0                                    0x15
#define BMX055_REG_GYRO_INT_EN_1                                    0x16
#define BMX055_REG_GYRO_INT_MAP_0                                   0x17
#define BMX055_REG_GYRO_INT_MAP_1                                   0x18
#define BMX055_REG_GYRO_INT_MAP_2                                   0x19
#define BMX055_REG_GYRO_INT_SRC_1                                   0x1A
#define BMX055_REG_GYRO_INT_SRC_2                                   0x1B
#define BMX055_REG_GYRO_INT_SRC_3                                   0x1C
#define BMX055_REG_GYRO_FIFO_EN                                     0x1E
#define BMX055_REG_GYRO_INT_RST_LATCH                               0x21
#define BMX055_REG_GYRO_HIGH_TH_X                                   0x22
#define BMX055_REG_GYRO_HIGH_DUR_X                                  0x23
#define BMX055_REG_GYRO_HIGH_TH_Y                                   0x24
#define BMX055_REG_GYRO_HIGH_DUR_Y                                  0x25
#define BMX055_REG_GYRO_HIGH_TH_Z                                   0x26
#define BMX055_REG_GYRO_HIGH_DUR_Z                                  0x27
#define BMX055_REG_GYRO_SOC                                         0x31
#define BMX055_REG_GYRO_A_FOC                                       0x32
#define BMX055_REG_GYRO_TRIM_NVM_CTRL                               0x33
#define BMX055_REG_GYRO_BGW_SPI3_WDT                                0x34
#define BMX055_REG_GYRO_OFC1                                        0x36
#define BMX055_REG_GYRO_OFC2                                        0x37
#define BMX055_REG_GYRO_OFC3                                        0x38
#define BMX055_REG_GYRO_OFC4                                        0x39
#define BMX055_REG_GYRO_TRIM_GP0                                    0x3A
#define BMX055_REG_GYRO_TRIM_GP1                                    0x3B
#define BMX055_REG_GYRO_BIST                                        0x3C
#define BMX055_REG_GYRO_FIFO_CONFIG_0                               0x3D
#define BMX055_REG_GYRO_FIFO_CONFIG_1                               0x3E        

/* Gyro Measurement Range Parameter-Angular rate measurement ranges(Resolution: LSB/degree/s) */
#define BMX055_GYRO_RANGE_16_4                                      0x00
#define BMX055_GYRO_RANGE_32_8                                      0x01
#define BMX055_GYRO_RANGE_65_6                                      0x02
#define BMX055_GYRO_RANGE_131_2                                     0x03
#define BMX055_GYRO_RANGE_262_4                                     0x04 

/* Gyro MPU Band Width Parameter ( Hz ) */        
#define BMX055_GYRO_BW_32                                           0x07
#define BMX055_GYRO_BW_64                                           0x06
#define BMX055_GYRO_BW_12                                           0x05
#define BMX055_GYRO_BW_23                                           0x04
#define BMX055_GYRO_BW_47                                           0x03
#define BMX055_GYRO_BW_116                                          0x02
#define BMX055_GYRO_BW_230                                          0x01
#define BMX055_GYRO_BW_523                                          0x00

/* Gyro Low Power Mode Parameter */        
#define BMX055_GYRO_LPM1_MODE_NOMAL                                 0x00
#define BMX055_GYRO_LPM1_MODE_DEEP_SUSPEND                          0x01
#define BMX055_GYRO_LPM1_MODE_SUSPEND                               0x10

/* Gyro Sleep Duration Parameter ( ms ) */        
#define BMX055_GYRO_LPM1_SLEEP_DUR_2MS                              0x00
#define BMX055_GYRO_LPM1_SLEEP_DUR_4MS                              0x01
#define BMX055_GYRO_LPM1_SLEEP_DUR_5MS                              0x02
#define BMX055_GYRO_LPM1_SLEEP_DUR_8MS                              0x03
#define BMX055_GYRO_LPM1_SLEEP_DUR_10MS                             0x04
#define BMX055_GYRO_LPM1_SLEEP_DUR_15MS                             0x05
#define BMX055_GYRO_LPM1_SLEEP_DUR_18MS                             0x06
#define BMX055_GYRO_LPM1_SLEEP_DUR_20MS                             0x07        
        
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif // #ifndef DRV_GYRO_REGS_H            