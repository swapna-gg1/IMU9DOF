/*******************************************************************************
  IMU Sensor BMX055 Driver Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    drv_imu.h

  Summary:
    Inertial Measurement Unit Sensor BMX055 Driver Interface Header File

  Description:
    The IMU Sensor driver provides APIs for application to sets up 
    and read the accel, gyro, mag sensor data.
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

#ifndef DRV_IMU_H
#define DRV_IMU_H

// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
#include "driver/driver.h"
#include "driver/driver_common.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END


/* Accel Chip ID */
#define BMX055_ACCEL_CHIP_ID                                        0xFA
/* Gyro  Chip ID */
#define BMX055_GYRO_CHIP_ID                                         0x0F    
/* Magnatometer  Chip ID */
#define BMX055_MAG_CHIP_ID                                          0x32        
    
/* BMX055 Soft reset parameter */    
#define BMX055_INITIATED_SOFT_RESET                                 0xB6    
    
// *****************************************************************************
/* IMU Sensor Type

  Summary:
    The sensor to communicate with

  Description:
    This data type decides which sensor to communicate with - accel, gyro or mag.

  Remarks:
    None.
*/

typedef enum
{
    /* accel */
    BMX055_ACCEL,

    /* Gyro */
    BMX055_GYRO,

    /* Mag */
    BMX055_MAG,

} BMX055_Sensor;   

/* sensor DATA */
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
}
BMX055_data_t;


// *****************************************************************************
// *****************************************************************************
// Section: IMU Sensor Driver Interface Routines (Abstraction)
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void DRV_BMX055_Get_Data(BMX055_Sensor sensor, BMX055_data_t* data_buff)
    

  Summary:
    Get IMU sensor data.

  Description:
    This function reads the sensor data from the I2C register of the 
    corresponding sensor.
  
  Precondition:
    Function DRV_BMX055_Get_Data must be called after DRV_BMX055_Init() is called.

  Parameters:
    sensor - Sensor Type.
    data_buff - pointer to data buffer.

  Returns:
    None.

  Example:
    <code>
    BMX055_accel_t accel_data;
    DRV_BMX055_Get_Data(BMX055_ACCEL, &accel_data);
    </code>

 */
void DRV_BMX055_Get_Data(BMX055_Sensor sensor, BMX055_data_t *data_buff);   

/* Function:
    int DRV_BMX055_Init(void)
    

  Summary:
    Initialize the IMU sensor.

  Description:
    This function checks if the supported IMU sensor can be detected and if so, 
 its initial setup is done.
  
  Precondition:
    Function DRV_BMX055_Init must be called after DRV_I2C_Initialize() is called in 
    SYS_Initialize().

  Parameters:
    None.

  Returns:
    Success/Failure.

  Example:
    <code>
    DRV_BMX055_Init();
    </code>

 */
int DRV_BMX055_Init(void);    
        
// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END    
    
    
#endif // DRV_CAM