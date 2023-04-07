/*******************************************************************************
  BMX055 IMU Sensor module Magnetometer Registers

  Company:
    Microchip Technology Inc.

  File Name:
    drv_mag_regs.h

  Summary:
    BMX055 IMU Sensor module Magnetometer Registers File

  Description:
    The header file contains the BMX055 IMU sensor Magnetometer register mapping.
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

#ifndef DRV_MAG_REGS_H
#define DRV_MAG_REGS_H

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

#define BMX055_REG_MAG_WHO_AM_I                                     0x40
#define BMX055_REG_MAG_DATA_START                                   0x42
#define BMX055_REG_MAG_XOUT_LSB                                     0x42
#define BMX055_REG_MAG_XOUT_MSB                                     0x43
#define BMX055_REG_MAG_YOUT_LSB                                     0x44
#define BMX055_REG_MAG_YOUT_MSB                                     0x45
#define BMX055_REG_MAG_ZOUT_LSB                                     0x46
#define BMX055_REG_MAG_ZOUT_MSB                                     0x47
#define BMX055_REG_MAG_ROUT_LSB                                     0x48
#define BMX055_REG_MAG_ROUT_MSB                                     0x49
#define BMX055_REG_MAG_INT_STATUS                                   0x4A
#define BMX055_REG_MAG_PWR_CNTL1                                    0x4B
#define BMX055_REG_MAG_PWR_CNTL2                                    0x4C
#define BMX055_REG_MAG_INT_EN_1                                     0x4D
#define BMX055_REG_MAG_INT_EN_2                                     0x4E
#define BMX055_REG_MAG_LOW_THS                                      0x4F
#define BMX055_REG_MAG_HIGH_THS                                     0x50
#define BMX055_REG_MAG_REP_XY                                       0x51
#define BMX055_REG_MAG_REP_Z                                        0x52
        
/* Mag Power Control Parameter */
#define BMX055_MAG_POW_CTL_SOFT_RESET                               0x82
#define BMX055_MAG_POW_CTL_SLEEP_MODE                               0x01
#define BMX055_MAG_POW_CTL_SUSPEND_MODE                             0x00   
 
/* Mag Datarate Control Parameter */     
#define BMX055_MAG_DATA_RATE_10                                     0x00
#define BMX055_MAG_DATA_RATE_2                                      0x08
#define BMX055_MAG_DATA_RATE_6                                      0x10
#define BMX055_MAG_DATA_RATE_8                                      0x18
#define BMX055_MAG_DATA_RATE_15                                     0x20
#define BMX055_MAG_DATA_RATE_20                                     0x28
#define BMX055_MAG_DATA_RATE_25                                     0x30
#define BMX055_MAG_DATA_RATE_30                                     0x38

/* Mag Repetitions for X-Y-Z Axis */        
#define BMX055_MAG_XY_REPET_9                                       0x04
#define BMX055_MAG_Z_REPET_15                                       0x0F
        
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
#endif // #ifndef DRV_MAG_REGS_H       