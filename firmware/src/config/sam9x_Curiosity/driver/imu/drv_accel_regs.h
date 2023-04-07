/*******************************************************************************
  BMX055 IMU Sensor module Accel Registers

  Company:
    Microchip Technology Inc.

  File Name:
    drv_accel_regs.h

  Summary:
    BMX055 IMU Sensor module Accel Registers File

  Description:
    The header file contains the BMX055 IMU sensor accel register mapping.
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

#ifndef DRV_ACCEL_REGS_H
#define DRV_ACCEL_REGS_H

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
        
#define BMX055_REG_ACC_WHO_AM_I                                     0x00
#define BMX055_REG_ACC_DATA_START                                   0x02
#define BMX055_REG_ACC_D_X_LSB                                      0x02
#define BMX055_REG_ACC_D_X_MSB                                      0x03
#define BMX055_REG_ACC_D_Y_LSB                                      0x04
#define BMX055_REG_ACC_D_Y_MSB                                      0x05
#define BMX055_REG_ACC_D_Z_LSB                                      0x06
#define BMX055_REG_ACC_D_Z_MSB                                      0x07
#define BMX055_REG_ACC_D_TEMP                                       0x08
#define BMX055_REG_ACC_INT_STATUS_0                                 0x09
#define BMX055_REG_ACC_INT_STATUS_1                                 0x0A
#define BMX055_REG_ACC_INT_STATUS_2                                 0x0B
#define BMX055_REG_ACC_INT_STATUS_3                                 0x0C
#define BMX055_REG_ACC_FIFO_STATUS                                  0x0E
#define BMX055_REG_ACC_PMU_RANGE                                    0x0F
#define BMX055_REG_ACC_PMU_BW                                       0x10
#define BMX055_REG_ACC_PMU_LPW                                      0x11
#define BMX055_REG_ACC_PMU_LOW_POWER                                0x12
#define BMX055_REG_ACC_D_HBW                                        0x13
#define BMX055_REG_ACC_BGW_SOFTRESET                                0x14
#define BMX055_REG_ACC_INT_EN_0                                     0x16
#define BMX055_REG_ACC_INT_EN_1                                     0x17
#define BMX055_REG_ACC_INT_EN_2                                     0x18
#define BMX055_REG_ACC_INT_MAP_0                                    0x19
#define BMX055_REG_ACC_INT_MAP_1                                    0x1A
#define BMX055_REG_ACC_INT_MAP_2                                    0x1B
#define BMX055_REG_ACC_INT_SRC                                      0x1E
#define BMX055_REG_ACC_INT_OUT_CTRL                                 0x20
#define BMX055_REG_ACC_INT_RST_LATCH                                0x21
#define BMX055_REG_ACC_INT_0                                        0x22
#define BMX055_REG_ACC_INT_1                                        0x23
#define BMX055_REG_ACC_INT_2                                        0x24
#define BMX055_REG_ACC_INT_3                                        0x25
#define BMX055_REG_ACC_INT_4                                        0x26
#define BMX055_REG_ACC_INT_5                                        0x27
#define BMX055_REG_ACC_INT_6                                        0x28
#define BMX055_REG_ACC_INT_7                                        0x29
#define BMX055_REG_ACC_INT_8                                        0x2A
#define BMX055_REG_ACC_INT_9                                        0x2B
#define BMX055_REG_ACC_INT_A                                        0x2C
#define BMX055_REG_ACC_INT_B                                        0x2D
#define BMX055_REG_ACC_INT_C                                        0x2E
#define BMX055_REG_ACC_INT_D                                        0x2F
#define BMX055_REG_ACC_FIFO_CONFIG_0                                0x30
#define BMX055_REG_ACC_PMU_SELF_TEST                                0x32
#define BMX055_REG_ACC_TRIM_NVM_CTRL                                0x33
#define BMX055_REG_ACC_BGW_SPI3_WDT                                 0x34
#define BMX055_REG_ACC_OFC_CTRL                                     0x36
#define BMX055_REG_ACC_OFC_SETTING                                  0x37
#define BMX055_REG_ACC_OFC_OFFSET_X                                 0x38
#define BMX055_REG_ACC_OFC_OFFSET_Y                                 0x39
#define BMX055_REG_ACC_OFC_OFFSET_Z                                 0x3A
#define BMX055_REG_ACC_TRIM_GPO                                     0x3B
#define BMX055_REG_ACC_TRIM_GP1                                     0x3C
#define BMX055_REG_ACC_FIFO_CONFIG_1                                0x3E
#define BMX055_REG_ACC_FIFO_DATA                                    0x3F        

/* Accel MPU Range Parameter */  
#define BMX055_ACC_RANGE_2                                          0x03
#define BMX055_ACC_RANGE_4                                          0x05
#define BMX055_ACC_RANGE_8                                          0x08
#define BMX055_ACC_RANGE_16                                         0x0C

/* Accel MPU Band Width Parameter ( Hz ) */
#define BMX055_ACC_PMU_BW_7_81                                      0x08
#define BMX055_ACC_PMU_BW_15_63                                     0x09
#define BMX055_ACC_PMU_BW_31_25                                     0x0A
#define BMX055_ACC_PMU_BW_62_5                                      0x0B
#define BMX055_ACC_PMU_BW_125                                       0x0C
#define BMX055_ACC_PMU_BW_250                                       0x0D
#define BMX055_ACC_PMU_BW_500                                       0x0E
#define BMX055_ACC_PMU_BW_1000                                      0x0F    
        
 /* Accel Low Power Mode Parameter */
#define BMX055_ACC_PMU_LPW_MODE_NOMAL                               0x00
#define BMX055_ACC_PMU_LPW_MODE_DEEP_SUSPEND                        0x20
#define BMX055_ACC_PMU_LPW_MODE_LOW_POWER                           0x40
#define BMX055_ACC_PMU_LPW_MODE_SUSPEND                             0x80      

/* Accel Low Power Mode sleep phase duration Parameter */        
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_0_5MS                          0x00
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_1MS                            0x0C
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_2MS                            0x0E
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_4MS                            0x10
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_6MS                            0x12
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_10MS                           0x14
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_25MS                           0x16
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_50MS                           0x18
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_100MS                          0x1A
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_500MS                          0x1C
#define BMX055_ACC_PMU_LPW_SLEEP_DUR_1S                             0x1E        
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif // #ifndef DRV_ACCEL_REGS_H        