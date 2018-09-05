#include "std_types.h"
#include "CANDriverTypes.h"

/* !!! TEMP STUBS !!! */
typedef uint8 Std_ReturnType;
#define E_OK 0U
#define E_NOT_OK 1U

#define CAN_ID_STANDARD     (0U << 31U)
#define CAN_ID_FD_STANDARD  (1U << 31U)
#define CAN_ID_EXTENDED     (1U << 32U)

#define CAN_NOT_INITIALIZED 0U
#define CAN_INITIALIZED     1U

/* Internal static variables */
static uint8 CanState_u8 = CAN_NOT_INITIALIZED;

/*
    8.3.1.1 Can_Init
    This function initializes the module.
*/
void Can_Init( const Can_ConfigType* Config )
{
    CanState_u8 = CAN_INITIALIZED;
}

/*
    8.3.1.2 Can_GetVersionInfo
    This function returns the version information of this module.
*/
void Can_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
    ;
}

/*
    8.3.1.3 Can_DeInit
    This function de-initializes the module.
*/
void Can_DeInit( void )
{
    ;
}

/*
    8.3.2.1 Can_SetBaudrate
    This service shall set the baud rate configuration of the CAN controller.
    Depending on necessary baud rate modifications the controller might have to reset.
*/
Std_ReturnType Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID)
{
    return E_OK;
}

/*
    8.3.2.2 Can_SetControllerMode
    This function performs software triggered state transitions of the CAN controller
    State machine.
*/
Std_ReturnType Can_SetControllerMode( uint8 Controller, Can_ControllerStateType Transition)
{
    return E_OK;
}

/*
    8.3.2.3 Can_DisableControllerInterrupts
    This function disables all interrupts for this CAN controller.
*/
void Can_DisableControllerInterrupts( uint8 Controller )
{
    ;
}

/*
    8.3.2.4 Can_EnableControllerInterrupts
    This function enables all allowed interrupts.
*/
void Can_EnableControllerInterrupts( uint8 Controller )
{
    ;
}

/*
    8.3.2.5 Can_CheckWakeup
    This function checks if a wakeup has occurred for the given controller.
*/
Std_ReturnType Can_CheckWakeup(( uint8 Controller )
{
    return E_OK;
}

/*
    8.3.2.6 Can_GetControllerErrorState
    This service obtains the error state of the CAN controller.
*/
Std_ReturnType Can_GetControllerErrorState( uint8 ControllerId, Can_ErrorStateType* ErrorStatePtr )
{
    return E_OK;
}

/*
    8.3.2.7 Can_GetControllerMode
    This service reports about the current status of the requested CAN controller.
*/
Std_ReturnType Can_GetControllerMode( uint8 Controller, Can_ControllerStateType* ControllerModePtr )
{
    return E_OK;
}

/*
    8.3.3.1 Can_Write
    This function is called by CanIf to pass a CAN message to CanDrv for transmission.
*/
Std_ReturnType Can_Write( Can_HwHandleType Hth, const Can_PduType* PduInfo )
{
    Std_ReturnType retVal = E_NOT_OK;

    //HTH: Standard - 0..0x0FF
    //HTH: Extended - 0..0xFFFF

    if()
    {
        //reportError("CAN_E_UNINIT");
    } else
    {
        //PduInfo->id
        //The two most significant
        //bits specify the frame type:
        //00 CAN message with Standard CAN ID
        //01 CAN FD frame with Standard CAN ID
        //10 CAN message with Extended CAN ID
        switch((PduInfo->id) & )
        {
            case CAN_ID_STANDARD:
            {
                if(Hth <= 0xFF)
                {

                } else
                {
                    //reportError("Hth higher than 0xFF for PduInfo->id which is standard id");
                }
                break;
            }

            case CAN_ID_FD_STANDARD:
            {
                if(Hth <= 0xFF)
                {

                } else
                {
                    //reportError("Hth higher than 0xFF for PduInfo->id which is FD standard id");
                }
                break;
            }

            case CAN_ID_EXTENDED:
            {
                break;
            }

            default:
            {
                retVal = E_NOT_OK;
                //reportError("Wrong PduInfo->id");
            }
        }
    }

    return retVal;
}

/*
    8.5.1.1 Can_MainFunction_Write
    This function performs the polling of TX confirmation when CAN_TX_PROCESSING is set to POLLING.
*/
void Can_MainFunction_Write( void )
{
    ;
}

/*
    8.5.1.2 Can_MainFunction_Read
    This function performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
*/
void Can_MainFunction_Read( void )
{
    ;
}

/*
    8.5.1.3 Can_MainFunction_BusOff
    This function performs the polling of bus-off events that are configured statically as 'to be polled'.
*/
void Can_MainFunction_BusOff( void )
{
    ;
}

/*
    8.5.1.4 Can_MainFunction_Wakeup
    This function performs the polling of wake-up events that are configured statically as 'to be polled'.
*/
void Can_MainFunction_Wakeup( void )
{
    ;
}

/*
    8.5.1.5 Can_MainFunction_Mode
    This function performs the polling of CAN controller mode transitions.
*/
void Can_MainFunction_Mode( void )
{
    ;
}



