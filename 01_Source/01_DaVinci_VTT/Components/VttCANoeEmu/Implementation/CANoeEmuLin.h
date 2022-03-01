/*-----------------------------------------------------------------------------
Module: CANoeEmu - AUTOSAR platform emulator for CANoe and VTT
Interfaces: all
-------------------------------------------------------------------------------
This header file provides APIs for the emulated LIN controller.

General:

- The emulated controller is for use with an Autosar 4 Lin Driver

- The API conforms to the LIN 2.1 Protocol Specification as specified in
  "LIN Specification Package Revision 2.1, November 24, 2006 http://www.lin-subbus.org/". This applies to
  LIN 2.1 Master nodes only.

- The API initiates transmission and receive data without blocking. The upper layer polls the function
  CANoeEmuLin_GetStatus to get any state of the CANoe/CANoeAPI.

- Wake-up detection is not supported, the emulated controller does not monitor the bus for a wake-up request on channel.

-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/

#ifndef CANOEEMULIN_H
#define CANOEEMULIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"

/***********************************************************************************************************************
 * Types
 **********************************************************************************************************************/
 
/*! LIN operation states and transmission,reception states for a LIN channel or frame, as returned by the API service
    Lin_GetStatus(). */
typedef enum CANoeEmuLin_StatusTypeTag
{
  /*! Transmission and reception states (operating state = LIN_CH_OPERATIONAL): */
  CANOEEMULIN_TX_OK           = 0x00U, /*<! Successful transmission of a TX or S2S frame. */
  CANOEEMULIN_TX_BUSY         = 0x01U, /*<! Ongoing transmission (Header or Response). */
  CANOEEMULIN_TX_HEADER_ERROR = 0x02U, /*<! Erroneous header transmission such as: bit error, parity error of PID, physical bus error */
  CANOEEMULIN_TX_ERROR        = 0x03U, /*<! Erroneous response transmission such as: bit error, physical bus error */
  CANOEEMULIN_RX_OK           = 0x04U, /*<! Reception of correct response. */
  CANOEEMULIN_RX_BUSY         = 0x05U, /*<! Ongoing reception: at least one response byte has been received, but the checksum byte has not been received. */
  CANOEEMULIN_RX_ERROR        = 0x06U, /*<! Erroneous response reception such as: framing, overrun, checksum error or a short response (not all response bytes received) */
  CANOEEMULIN_RX_NO_RESPONSE  = 0x07U, /*<! No response byte has been received so far. */
 
  /*! Operating states: */
  CANOEEMULIN_OPERATIONAL     = 0x09U, /*<! Normal operation; the related LIN channel is ready to transmit next header. No data from previous frame available (e.g. after initialization) */
  CANOEEMULIN_CH_SLEEP        = 0x0AU, /*<! Sleep state operation, sending of a wakeup frame is possible */
  /*! Error: */
  CANOEEMULIN_NOT_OK          = 0x0BU, /*<! Error occurred on CANoeEmuLin_GetStatus (if SduPtr is a NULL pointer) */
} CANoeEmuLin_StatusType;


/*! This type is used to specify the Checksum model to be used for the LIN Frame. */
typedef enum CANoeEmuLin_FrameCsModelTypeTag
{
  CANOEEMULIN_ENHANCED_CS = 0, /*<! Enhanced checksum model */
  CANOEEMULIN_CLASSIC_CS  = 1  /*<! Classic checksum model */
} CANoeEmuLin_FrameCsModelType;


/*! This type is used to specify whether the frame processor is required to transmit the response part of the LIN frame. */
typedef enum CANoeEmuLin_FrameResponseTypeTag
{
  CANOEEMULIN_MASTER_RESPONSE = 0, /*<! Response is generated from this (master) node */
  CANOEEMULIN_SLAVE_RESPONSE  = 1, /*<! Response is generated from a remote slave node */
  CANOEEMULIN_SLAVE_TO_SLAVE  = 2  /*<! Response is generated from one slave to another slave */
} CANoeEmuLin_FrameResponseType;

/*! This Type is used to provide PID, checksum model, data length and SDU pointer of a LIN frame. */
typedef struct CANoeEmuLin_PduTypeTag
{
  uint8                         Pid;    /*<! Valid protected identifier */
  CANoeEmuLin_FrameCsModelType  Cs;     /*<! Specified checksum model */
  CANoeEmuLin_FrameResponseType Drc;    /*<! Type of response part */
  uint8                         Dl;     /*<! SDU data bytes to copy */
  uint8*                        SduPtr; /*<! Pointer to SDU data bytes */
} CANoeEmuLin_PduType;

/* return values */
#define CANOEEMULIN_E_OK      0u
#define CANOEEMULIN_E_NOT_OK  1u

#define CANOEEMULIN_LIN_MAX_CHANNELS 32

/***********************************************************************************************************************
 *   Init
 **********************************************************************************************************************/
/*!

*/

/***********************************************************************************************************************
 *  CANoeEmuLin_Init (optional)
 **********************************************************************************************************************/
/*! \brief       Initialize the CANoeAPI.
 *
 *  \details     Returns if CANoe could send LIN Frames from this API (blocking, using for synchronize reasons).
 *               
 *  \param[in]   BreakFieldLength: Break-Field-Length from 13 to 26 TBits
 *  \param[in]   BreakDelimiterLength: Break-Field-Delimiter-Length form 1 to 14 TBits
 *  \param[in]   BaudRate: Baud rate from 1000 to 20000 baud. If invalid the baud rate of CANoe Lin DB must use.
 *
 *  \return      -
 **********************************************************************************************************************/
void CANoeEmuLin_Init( uint8 BreakFieldLength, uint8 BreakDelimiterLength, uint16 BaudRate);


/***********************************************************************************************************************
 *   Frame processing (CANoeAPI_SendFrame/CANoeEmuLin_GetStatus)
 **********************************************************************************************************************/
/*!
 - The received data shall be consistent until either next LIN frame has been received successfully or LIN channel state
   has changed.
 
 - The complete LIN frame receive processing (including copying to destination layer) can be implemented in the
   "Handler" and/or in CANoeEmuLin_GetStatus.  
 
 - Data mapping between memory and the LIN frame is defined in a way that the array element 0 is containing the LSB
   (the data byte to send/receive first) and the array element (n-1) is containing the MSB (the data byte to
   send/receive last).
*/


/***********************************************************************************************************************
 *  CANoeEmuLin_SendFrame
 **********************************************************************************************************************/
/*! \brief       Sends a LIN header and a LIN response, if necessary. The direction of the frame response
 *               (master response, slave response, slave-to-slave communication) is provided by the PduInfoPtr. 
 *
 *  \details     The function shall send the header part (Break Field, Synch Byte Field and PID Field) and, depending on
 *               the direction of the frame response, a complete LIN response part of a LIN frame on the addressed LIN 
 *               channel.
 *               In case of receiving data the corresponding response part of the LIN frame can be received by polling the
 *               function CANoeEmuLin_GetStatus after using the function CANoeAPI_SendFrame.
 *               
 *               Deviating from the ASR4 specification, an ongoing transmission can not be canceled. An ongoing 
 *               transmission will always succeed. The new frame will always be queued for transmission. Transmission
 *               will occur as soon as the bus is idle (recessive for a given time).
 *
 *               The data of PduInfoPtr shall directly copy from the upper layer buffers. The upper layer has to keep
 *               the buffer data consistent until return of function call.
 *
 *  \param[in]   Channel: Channel to be addressed.
 *  \param[in]   PduInfoPtr: Pointer to PDU containing the PID, Checksum model, Response type, Dl and SDU data pointer.
 *
 *  \return      E_OK: send command has been accepted.
 *               E_NOT_OK: send command has not been accepted:
 *                           - PduInfoPtr parameter is a NULL pointer
 *                           - SduPtr parameter is a NULL pointer in case of a master response frame (TX)
 *                           - Data length parameter of PduInfoPtr is not in range (1-8 data bytes)
 *                           - Channel is in sleep state
 **********************************************************************************************************************/
uint8 CANoeEmuLin_SendFrame( uint8 Channel, CANoeEmuLin_PduType* PduInfoPtr );



/***********************************************************************************************************************
 *  CANoeEmuLin_GetStatus
 **********************************************************************************************************************/
/*! \brief       Gets the status of the LIN driver and current frame. 
 *
 *  \details     The function CANoeEmuLin_GetStatus returns the current transmission, reception or operation status
 *               of the LIN driver.
 *  
 *               If a SDU has been successfully received (current reception status is LIN_RX_OK), the function shall
 *               store the SDU of the received frame in a internal shadow buffer (if not done by a event handler) and
 *               set the given SduPtr parameter to the internal shadow buffer reference. The internal buffer will only
 *               be valid and must be read by the upper layer until the next CANoeAPI_SendFrame function call or the
 *               LIN channel state has changed.
 *               
 *               If channel state LIN_CH_SLEEP_PENDING enter the state LIN_CH_SLEEP (see CANoeEmuLin_GoToSleep).
 *
 *               The function checks the parameter SduPtr for not being a NULL pointer. If SduPtr is a NULL
 *               pointer, the function returns LIN_NOT_OK.
 *               
 *  \param[in]   Channel: LIN channel to be addressed
 *  \param[out]  SduPtr: Pointer to pointer to internal shadow buffer of the CANoeAPI receive buffer.
 *  \return      CANoeEmuLin_StatusType: Information about the current state.
 **********************************************************************************************************************/
CANoeEmuLin_StatusType CANoeEmuLin_GetStatus( uint8 Channel, uint8** SduPtr );

/***********************************************************************************************************************
 *   Sleep and wake-up functionality (CANoeEmuLin_GoToSleep/CANoeEmuLin_GoToSleepInternal/CANoeEmuLin_Wakeup/CANoeEmuLin_WakeupInternal)
 **********************************************************************************************************************/
/*!
 - The function CANoeEmuLin_GetStatus returns the current state of a LIN channel.
 
 - Each LIN channel shall be able to accept a sleep/wake up request independently of the other channel states.
*/

/***********************************************************************************************************************
 *  CANoeEmuLin_GoToSleep
 **********************************************************************************************************************/
/*! \brief       Transmits a go-to-sleep command and sets the channel state to LIN_CH_SLEEP.
 * 
 *  \details     The function Lin_GoToSleep sends a go-to-sleep-command on the addressed LIN channel as defined in
 *               LIN Specification 2.1.
 *
 *               The function Lin_GoToSleep sets the channel state to LIN_CH_SLEEP_PENDING, even in case of an
 *               erroneous transmission of the go-to-sleep-command. The LIN channel shall enter the state LIN_CH_SLEEP
 *               the next time CANoeEmuLin_GetStatus is called, independent of the success of the transmission of the 
 *               goto-sleep-command on the bus.
 *
 *               Deviating from the ASR4 specification, an ongoing transmission can not be canceled. Also,
 *               an ongoing transmission will always succeed. The goto-sleep master request will always be 
 *               queued for transmission.
 *
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Sleep command has been accepted.
 *  \return      E_NOT_OK: Sleep command has not been accepted, ongoing transmission could not stopped.
 **********************************************************************************************************************/
uint8 CANoeEmuLin_GoToSleep( uint8 Channel );

/***********************************************************************************************************************
 *  CANoeEmuLin_GoToSleepInternal
 **********************************************************************************************************************/
/*! \brief       Sets the channel to sleep mode without sending a go-to-sleep command.
 *
 *  \details     The function Lin_GoToSleepInternal sets the channel state to LIN_CH_SLEEP.
 *
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Sleep command has been accepted
 *  \return      E_NOT_OK: Sleep command has not been accepted
 **********************************************************************************************************************/
uint8 CANoeEmuLin_GoToSleepInternal( uint8 Channel );

/***********************************************************************************************************************
 *  CANoeEmuLin_Wakeup
 **********************************************************************************************************************/
/*! \brief       Sends a wakeup frame and sets the channel state to LIN_CH_OPERATIONAL. 
 *
 *  \details     Sends a wakeup frame on the addressed LIN channel and sets the channel state to LIN_CH_OPERATIONAL.
 *               The function returns E_NOT_OK if the channel state is not in the state LIN_CH_SLEEP.
 *
 *  \param[in]   Channel: LIN Channel ID of hardware channel to be addressed.
 *  \return      E_OK: Wake-up request has been accepted.
 *  \return      E_NOT_OK: Wake-up request has not been accepted or channel state is not LIN_CH_SLEEP.
 **********************************************************************************************************************/
uint8 CANoeEmuLin_Wakeup( uint8 Channel );

/***********************************************************************************************************************
 *  CANoeEmuLin_WakeupInternal
 **********************************************************************************************************************/
/*! \brief       Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *
 *  \details     Sets the addressed LIN channel to state LIN_CH_OPERATIONAL without generating a wake up pulse.
 *               The function returns E_NOT_OK if the channel state is not in the state LIN_CH_SLEEP.
 *
 *  \param[in]   Channel: LIN Channel   ID of hardware channel to be addressed.
 *  \return      E_OK: Wake-up request has been accepted
 *  \return      E_NOT_OK: Wake-up request has not been accepted or channel state is not LIN_CH_SLEEP.
 **********************************************************************************************************************/
uint8 CANoeEmuLin_WakeupInternal( uint8 Channel );

/***********************************************************************************************************************
 *  CANoeEmuLin Controller Layer
 **********************************************************************************************************************/
/*! \brief       The following set of functions provide Controller-like interrupt functionality.
 *
 *  \details     There is one virtual controller per channel. Each controller can be assigned to distinct interrupts.
 *               There is, per controller, one separate interrupt for Tx acknowledgment, frame reception, 
 *               error reception and reception of wakeup signals. There is no specific notification of 
 *               CANoe sleep/wakeup mode changes (as these should be modeled inside the ECU software).
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  CANoeEmuLin_EnableInterrupts
 **********************************************************************************************************************/
/*! \brief       Returns the current interrupt state of the specified controller and resets the interrupt flag.
 *
 *  \details     The Interrupt flag remains set until this function is called to query it. Interrupt queueing
 *               is *not* implemented. This function can be called from an ISR to find out the LIN controller
 *               which has flagged the interrupt.
 *
 *  \param[in]   Channel: LIN Channel   ID of hardware channel to be addressed.
 *  \return      1: Interrupt flag set
 *  \return      0: Interrupt flag not set
 **********************************************************************************************************************/
uint8 CANoeEmuLin_EnableInterrupts(uint8 channel, uint8 enable);

/***********************************************************************************************************************
 *  CANoeEmuLin_ConfigureInterrupts
 **********************************************************************************************************************/
/*! \brief       Set interrupt numbers for the specified LIN Controller.
 *
 *  \details     The Interrupt flag remains set until this function is called to query it. Interrupt queueing
 *               is *not* implemented. This function can be called from an ISR to find out the LIN controller
 *               which has flagged the interrupt.
 *
 *  \param[in]   Channel: LIN Channel   ID of hardware channel to be addressed.
 *  \param[in]   rxIrqNo: interrupt to set when a RX event occurs.
 *  \param[in]   txIrqNo: interrupt to set when a TX event occurs.
 *  \param[in]   errIrqNo: interrupt to set when an error event occurs.
 *  \param[in]   wakeupIrqNo: IRQ number signalling reception of wakeup frames. Note this does *not* flag controller
 *               sleep/wakeup changes.
 *  \return      1: Interrupt flag set
 *  \return      0: Interrupt flag not set
 **********************************************************************************************************************/
uint8 CANoeEmuLin_ConfigureInterrupts(uint8 channel, uint8 rxIrqNo, uint8 txIrqNo, uint8 errIrqNo, uint8 wakeupIrqNo);

/***********************************************************************************************************************
 *  CANoeEmuLin_IsInterruptSet
 **********************************************************************************************************************/
/*! \brief       Returns the current interrupt state of the specified controller and resets the interrupt flag.
 *
 *  \details     The Interrupt flag remains set until this function is called to query it. Interrupt queueing
 *               is *not* implemented. This function can be called from an ISR to find out the LIN controller
 *               which has flagged the interrupt.
 *
 *  \param[in]   Channel: LIN Channel   ID of hardware channel to be addressed.
 *  \return      1: Interrupt flag set
 *  \return      0: Interrupt flag not set
 **********************************************************************************************************************/
uint8 CANoeEmuLin_IsInterruptSet(uint8 channel);

/***********************************************************************************************************************
 *  CANoeEmuLin_Reset
 **********************************************************************************************************************/
/*! \brief       Resets all LIN controllers.
 *
 *  \details     Sets all configured LIN controllers to their initial state. When CANOEAPI_ECUACTION_RESET occurs,
 *               this is done automatically. However, one can use this function to reset the LIN controller at any time.
 *
 **********************************************************************************************************************/
void CANoeEmuLin_Reset();

/***********************************************************************************************************************
 *  CANoeEmuLin_EnableStateTracking
 **********************************************************************************************************************/
/*! \brief       Enable/Disable LIN channel state tracking through predefined system variables.
 *
 *  \details     When enabled, CANoeEmuLin will update a per-channel struct-type systemvariable named 
 *               <root namespace>::LINController::LIN_<channel number> to the new LIN state on each change.
 *               This systemvariable has the members State (which is the current LIN state) and isAwake (reflecting
 *               the HW/simulated channel's wake state.
 *
 *  \param[in]   fEnable: Flags whether or not to trace LIN channel state changes through predefined system variables.
 *  \return      1: Interrupt flag set
 *  \return      0: Interrupt flag not set
 **********************************************************************************************************************/
void CANoeEmuLin_EnableStateTracking(uint8 fEnable);

#ifdef __cplusplus
};
#endif

#endif // CANOEEMULIN_H
