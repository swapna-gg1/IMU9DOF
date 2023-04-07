/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include <stdio.h>
#include "driver/imu/drv_imu.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
BMX055_data_t accel_data;
BMX055_data_t gyro_data;
BMX055_data_t mag_data;
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            printf("IMU 9DoF Example. \r\n");
            /* Initialize the BMX055 IMU sensors */
            if(DRV_BMX055_Init()==0)
            {
                appData.state = APP_STATE_ERROR;
            }
            else if (appInitialized)
            {
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            DRV_BMX055_Get_Data(BMX055_ACCEL, &accel_data);  
            DRV_BMX055_Get_Data(BMX055_GYRO, &gyro_data);
            DRV_BMX055_Get_Data(BMX055_MAG, &mag_data);
            printf("------------------------------------------\r\n" );
            printf(" Accel X: %d | Gyro X: %d |  Mag X: %d\r\n", accel_data.x, gyro_data.x, mag_data.x );
            printf(" Accel Y: %d | Gyro Y: %d |  Mag Y: %d\r\n", accel_data.y, gyro_data.y, mag_data.y );
            printf(" Accel Z: %d | Gyro Z: %d |  Mag Z: %d\r\n", accel_data.z, gyro_data.z, mag_data.z );
            printf("------------------------------------------\r\n" );
    
    
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        case APP_STATE_ERROR:
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
