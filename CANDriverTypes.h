#ifndef CAN_DRIVER_TYPES_H
#define CAN_DRIVER_TYPES_H

/* !!! TEMP STUBS !!! */
#define PduIdType uint8



/*
    8.2.1 Can_ConfigType
    This is the type of the external data structure containing
    the overall initialization data for the CAN driver and SFR
    settings affecting all controllers. Furthermore it contains
    pointers to controller configuration structures. The contents
    of the initialization data structure are CAN hardware specific.
*/
typedef struct
{
    /* Implementation specific. */
}Can_ConfigType;

/*
    8.2.2 Can_PduType
    This type unites PduId (swPduHandle), SduLength (length),
    SduData (sdu) and CanId (id) for any CAN L-SDU.
*/
typedef struct
{
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8 *sdu;
}Can_PduType;

/*
    8.2.3 Can_IdType
    Represents the Identifier of an L-PDU. The two most significant
    bits specify the frame type:
    00 CAN message with Standard CAN ID
    01 CAN FD frame with Standard CAN ID
    10 CAN message with Extended CAN ID
    Range:
    Standard32Bit - 0..0x400007FF
    Extended32Bit - 0..0xDFFFFFFF
*/
typedef uint32 Can_IdType;

/*
    8.2.4 Can_HwHandleType
    Represents the hardware object handles of a CAN hardware unit.
    For CAN hardware units with more than 255 HW objects use extended range.
    Range:
    Standard - 0..0x0FF
    Extended - 0..0xFFFF
*/
typedef uint16 Can_HwHandleType;

/*
    8.2.5 Can_HwType
    This type defines a data structure which clearly provides an Hardware
    Object Handle including its corresponding CAN Controller and therefore
    CanDrv as well as the specific CanId.
*/
typedef struct
{
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
}Can_HwType;

/*
    8.2.6 Can_ReturnType
    Overlayed return value of Std_ReturnType for CAN driver API Can_Write()
*/
enum Can_ReturnType
{
    CAN_BUSY = 0x2U
};

/*
    8.2.7 Can_ErrorStateType
    Error states of a CAN controller.
    Range:
    CAN_ERRORSTATE_ACTIVE - The CAN controller takes fully part in communication.
    CAN_ERRORSTATE_PASSIVE - The CAN controller takes part in communication,
                             but does not send active error frames.
    CAN_ERRORSTATE_BUSOFF - The CAN controller does not take part in communication.
*/
enum Can_ErrorStateType
{
    CAN_ERRORSTATE_ACTIVE,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
};

/*
    8.2.8 Can_ControllerStateType
    States that are used by the several ControllerMode functions.
    Range:
    CAN_CS_UNINIT 0x00 - CAN controller state UNINIT.
    CAN_CS_STARTED 0x01 - CAN controller state STARTED.
    CAN_CS_STOPPED 0x02 - CAN controller state STOPPED.
    CAN_CS_SLEEP 0x03 - CAN controller state SLEEP.
*/
enum Can_ControllerStateType
{
    CAN_CS_UNINIT,
    CAN_CS_STARTED,
    CAN_CS_STOPPED,
    CAN_CS_SLEEP
};











#endif