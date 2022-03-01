/*-----------------------------------------------------------------------------
Module: CANoeEmu - AUTOSAR platform emulator for CANoe and VTT
Interfaces: all
-------------------------------------------------------------------------------
  Description: Header files contains prototypes for CANoe APIs

-------------------------------------------------------------------------------
                A U T H O R   I D E N T I T Y
 -----------------------------------------------------------------------------
  Initials     Name                      Company
  --------     ---------------------     -------------------------------------
  Lm           Marc Lobmeyer             Vector Informatik GmbH
  As           Stefan Albus              Vector Informatik GmbH
  Ph           Peter Hajsani             Vector Informatik GmbH
  Lpa          Paul Lawitzki             Vector Informatik GmbH
  Sn           Michael Stephan           Vector Informatik GmbH
 -----------------------------------------------------------------------------
                R E V I S I O N   H I S T O R Y
 -----------------------------------------------------------------------------
  Date         Ver   Author  Description
 -----------   ----  ------  -------------------------------------------------
  18.05.1998   1.00    Lm    Created
  11.04.2000   1.01    As    Restructured
  25.08.2000   1.02    As    WriteToLog and WriteSysState added
  19.06.2001   1.03    As    Flags at function SendMessage added
  04.02.2003   1.04    As    Multibus support added
  07.02.2003   1.05    As    Support for bus system LIN added
  14.04.2003   1.06    As    CAN API extended (CanReset, bus off, SetBtr, ...)
  24.04.2003   1.07    As    LIN API extended  
  07.07.2008   1.08    Ph    FlexRay support added
  15.07.2008   1.09    Ph    Support for UserTimer added
  25.08.2008   1.10    Ph    Added FrameFlags access for the FlexRay frame receive 
  11.12.2008   1.11    As    DebugBreak added 
  09.04.2008   1.12    Ph    Function added to request the CANoe simulation mode 
  07.12.2010   1.13    Ph    Function added to set the FR POCState and KeySlot 
  12.02.2013   2.00    As    Redesign for preemptive emulation
  27.02.2013   2.01    Lpa   Ethernet support added
  13.11.2013   2.02    As    Redesign for preemptive emulation completed
  11.12.2013   2.03    As    Function CANoeAPI_SetVersionOfEcuInstance removed
  07.02.2014   2.04    As    Support for CAN FD added
  20.06.2014   2.05    As    Function CANoeAPI_GetLibraryVersion added
  26.06.2014   2.06    Sn    SysVar struct definitions
  17.07.2014   2.07    As    CANoeAPI_BaseAddressOfDLL added.
  26.07.2014   2.08    Sn    Support for nested SysVar structures
  30.07.2014   2.09    Sn    Support for array members of SysVar structures
  01.08.2014   2.10    Sn    Init values for SysVars
  02.09.2014   2.11    Sn    Syntax changes for SysVar arrays & structures
  20.11.2014   2.12    As    Function CANoeAPI_WriteToDebugger added
                             Function CANoeAPI_ConsumeTime added
                             Function CANoeAPI_GetTimeInfo added
                             SystemVariable 'Det::LastError' added
  05.01.2015   2.13    As    Non preemptive execution modes added
                             CANoeAPI_SetInitValueOfPowerSupply added
  07.01.2015   2.14    Sn    LIN & Channel API extended
  17.01.2015   2.15    Sn    SystemVariable 'computation methods' added
  19.01.2015   2.16    Sn    LIN API extended
  29.04.2015   2.17    As    CANoeAPI_ConfigureTiming added
  26.06.2015   2.18    Sn    CANoeAPI_ReInitializeSectionOnReset added
  28.07.2015   2.19    As    Support for SysVars of type uint32, sint64 and uint64
                             Support for sint64 and uint64 members of SysVar structures
                             Function CANoeAPI_Printf added
                             Function CANoeAPI_PrintfToLog added
                             Function CANoeAPI_PrintfToDebugger added
                             Function CANoeAPI_SysVar_SetHandlerStruct added
  19.10.2015   2.20    As    NVRAM API extended (CANoeAPI_OpenNvRamInstance, 
                             CANoeAPI_CloseNvRamInstance)
  26.10.2015   2.21    As    Support for High Resolution Timer added
                             Interlocked functions added
                             Dump function for interrupt controller added
  10.12.2015   2.22    As    Multi core support added
                             Multiple instances of High Resolution Timer (Breaking 
                             change because an additional index parameter is needed)
                             Support for non-maskable interrupts (NMI) added
                             Function CANoeAPI_FileNameOfDLL added
                             Function CANoeAPI_TestFileNameOfDLL added
  26.01.2016   2.23    As    USERTIMER2 API added, which allows more than 255 user timer
                             Function CANoeEmuHRTimer_GetCompareValue added
                             Function CANoeEmuProcessor_RollbackStackOfTask added
  13.04.2016   2.24    As    Additional functions for Det error reporting added:
                               - CANoeAPI_DetSetInstance
                               - CANoeAPI_DetSetFunction2
                               - CANoeAPI_DetSetError2
  18.08.2016   2.25    As    Physical limits added to system variable declaration
                             Function CANoeEmuProcessor_DisableInterruptsAtStartOfISR added
                             Function CANoeEmuProcessor_RollbackStackOfIsr added
                             Function CANoeAPI_DumpNvRam added
  29.11.2016   2.26    As    Configurable frequency for high resolution timer
                             Error detection of CANoe 'Drift and Jitter' feature
  12.01.2017   2.27    As    Function CANoeAPI_RandomNumbers added
                             Function CANoeAPI_SetTaskToRun added
  13.02.2017   2.28    As    Function CANoeAPI_FreezeChannelMapping added
                             Function CANoeAPI_IsChannelMappingFrozen added
                             Function CANoeAPI_VariantName added
                             Function CANoeAPI_SetVariantName added
                             Function CANoeAPI_TestVariantName added
  13.06.2017   2.29    As    LIN controller added (header CANoeEmuLin.h)
  19.06.2017   2.30    Arr   Functions CANoeAPI_FunctionBus_* added for FunctionBus access
                             Function CANoeAPI_RequestRuntimeCallback added
                             Function CANoeAPI_RequestRuntimeDeltaCycle added
                             Function CANoeAPI_WriteString2 added
                             Function CANoeAPI_Printf2 added
                             Function CANoeAPI_SetDllInstanceHandle added
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/

#ifndef __CANOEAPI_H
#define __CANOEAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"

// ============================================================================
// Version
// ============================================================================

// Interface version of this header file ('CANoeAPI.h').
#define CANOEAPI_VERSION  230

// Version of the CANoeEmu Library
#define CANOEEMU_MAJOR_VERSION  2
#define CANOEEMU_MINOR_VERSION  30
#define CANOEEMU_PATCH_VERSION  0

// Version of the CANoeEmu-Library
// majorVersion: output parameter for the define CANOEEMU_MAJOR_VERSION
// minorVersion: output parameter for the define CANOEEMU_MINOR_VERSION
// patchVersion: output parameter for the define CANOEEMU_PATCH_VERSION
extern void CANoeAPI_GetLibraryVersion(unsigned int* majorVersion,
                                       unsigned int* minorVersion,
                                       unsigned int* patchVersion);									   
// ============================================================================
// Constants used by several APIs
// ============================================================================

#define CANOEAPI_BUSTYPE_CAN  0x0001
#define CANOEAPI_BUSTYPE_LIN  0x0005
#define CANOEAPI_BUSTYPE_FLEXRAY  0x0007
#define CANOEAPI_BUSTYPE_ETHERNET 0x000B

#define CANOEAPI_INVALIDDRIVERINDEX 0xff

#define CANOEAPI_DIR_RX       0
#define CANOEAPI_DIR_TX       1
#define CANOEAPI_DIR_TXRQ     2

  // ============================================================================
  // General CANoe Services 
  // ============================================================================


  // Icons supported by the 'write' window of CANoe, used by functions CANoeAPI_WriteString2, CANoeAPI_Printf2
#define CANOEAPI_TABICON_SUCCESS        0
#define CANOEAPI_TABICON_INFORMATIONAL  1
#define CANOEAPI_TABICON_WARNING        2
#define CANOEAPI_TABICON_ERROR          3

  // Type of access operations to the 'write' window of CANoe, used by functions CANoeAPI_WriteString2, CANoeAPI_Printf2
#define CANOEAPI_TABACCESS_IMMEDIATE  0
#define CANOEAPI_TABACCESS_DEFERRED   1

// Write text to the 'write' window of CANoe
extern void CANoeAPI_WriteString(const char* s);
extern void CANoeAPI_WriteString2(unsigned int access, unsigned int type, const char* s);

// Write formatted text to the 'write' window of CANoe
extern void CANoeAPI_Printf(const char* format, ...);
extern void CANoeAPI_Printf2(unsigned int access, unsigned int type, const char* format, ...);

// Write text to the logging file of CANoe
extern void CANoeAPI_WriteToLog(const char* s);

// Write formated text to the logging file of CANoe
extern void CANoeAPI_PrintfToLog(const char* format, ...);

// Write text to the 'Output' windows of an attached Debugger
extern void CANoeAPI_WriteToDebugger(const char* s);

//  Write formated text to the 'Output' windows of an attached Debugger
extern void CANoeAPI_PrintfToDebugger(const char* format, ...);


// Simulation modes of CANoe, used by function CANoeAPI_GetSimulationMode
#define CANOEAPI_SIMMODE_UNKNOWN    0
#define CANOEAPI_SIMMODE_SIMULATE   1
#define CANOEAPI_SIMMODE_REAL       2

// Returns the current Simulation Mode
// CANOEAPI_SIMMODE_UNKNOWN    0    CANoes older than 7.1 SP3 will not return this value
// CANOEAPI_SIMMODE_SIMULATE   1    CANoe is in simulation mode
// CANOEAPI_SIMMODE_REAL       2    CANoe is in real mode
extern int CANoeAPI_GetSimulationMode(void);


// In simulated mode of CANoe, the function CANoeAPI_DebugBreak causes 
// a stop of the simulation for analysis purposes. It has the same behavior as
// the CAPL function 'halt()'. 
// A CANoe 7.0.72 or newer is required for this function.
extern void CANoeAPI_DebugBreak(void);

// Begin of an atomic operation.
// A function called in the context of an AUTOSAR task can be suspended at
// arbitrary position, even when it hold essential locks like the lock from the
// heap management. To avoid dead locks, emulation code can call the
// functions CANoeAPI_AtomicBegin and CANoeAPI_AtomicEnd to avoid suspension.
extern void CANoeAPI_AtomicBegin(void);

// End of atomic operation
extern void CANoeAPI_AtomicEnd(void);


// The function CANoeAPI_BaseAddressOfDLL returns the address where the 
// emulation DLL is loaded into memory. Windows DLLs are typically relocated in
// memory, when they are loaded into a process. XCP uses this function to 
// adjust the addresses from the a2l file to the relocation effect.
extern uint32 CANoeAPI_BaseAddressOfDLL(void);


// The function CANoeAPI_FileNameOfDLL returns the filename of the emulation DLL.
// return value:  the filename (without extension) of the DLL.
extern const char* CANoeAPI_FileNameOfDLL(void);

// CANoeAPI_TestFileNameOfDLL performs a lower case comparison of the filename
// of the emulation DLL (without extension) with the given parameter.
// parameter name: The name, that should be compared with the filename of the DLL.
//                 The name must not contain the file extension '.dll'.
// return value  : The function returns true, if the DLL name matches the given 
//                  parameter, otherwise it returns false;
extern boolean CANoeAPI_TestFileNameOfDLL(const char* name);


// The function CANoeAPI_RandomNumbers fills the given byte array with random numbers.
// parameters length: number of bytes, that should be generated
// parameters numbers: pointer to an array of at least length bytes.
// return values 
//   CANOEAPI_RANDOM_OK: the random numbers are successfully generated
//   CANOEAPI_RANDOM_WRONGPARAMETERS: parameter numbers is a null pointer
//   CANOEAPI_RANDOM_FAILURE: the internal random number generator from windows operation system
//   failed to generate numbers.
#define CANOEAPI_RANDOM_OK  0UL
#define CANOEAPI_RANDOM_WRONGPARAMETERS 1UL
#define CANOEAPI_RANDOM_FAILURE 2UL
extern uint32 CANoeAPI_RandomNumbers(uint32 length, uint8* numbers);


// The function CANoeAPI_VariantName returns the name of the variant, that was configured in VTT for the currently
// running simulation instance. VTT 2.0 or newer is required for this feature.
// return value:  the variant name for the currently running simulation instance.
extern const char* CANoeAPI_VariantName(void);

// Set the variant name for the simulation instance.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// parameter variant: The name of the variant, that should be set
extern void CANoeAPI_SetVariantName(const char* variant);

// CANoeAPI_TestVariantName performs a case sensitive comparison of the variant name with the given parameter.
// parameter name: The name, that should be compared with the variant name.
// return value  : The function returns true, if the variant name matches the given 
//                 parameter, otherwise it returns false;
extern boolean CANoeAPI_TestVariantName(const char* variant);

// Configure the CANoeEmu-Library with the instance handle of the DLL.
// The function CANoeAPI_SetDllInstanceHandle should be called by the VTT framework, when the DLL is loaded into a 
// windows process. The call is normally done in the call out function 'DllMain' of the Visual Studio C Runtime.
extern void CANoeAPI_SetDllInstanceHandle(void* dllInstanceHandle);

// ============================================================================
// Access to FlexRay Bus
//
// ============================================================================

// FlexRay State of the frame header
#define CANOEAPI_FLEXRAY_HEADERFLAG_SYNC         0x01
#define CANOEAPI_FLEXRAY_HEADERFLAG_STARTUP      0x02
#define CANOEAPI_FLEXRAY_HEADERFLAG_EVENTDRIVEN  0x10
#define CANOEAPI_FLEXRAY_HEADERFLAG_NMI          0x20


// This function will be called when a message has been received
typedef void (*VFlexRayFrameHandler) (uint8  channel,        // FlexRay cluster 
                                      uint32 channelABMask,  // 1: CH A, 2: CH B, 3: CH A&B 
                                      uint32 slotId, 
                                      uint16 cycle, 
                                      sint16 segment,
                                      sint32 flags,
                                      uint16 payloadLen, 
                                      const uint8 data[]);

// Cycle event handler for cycle start on the FlexRay bus
typedef void (*VFlexRayStartCycleHandler) (uint8  channel,  // FlexRay cluster
                                           uint16 cycle,    // cycle counter
                                           sint64 time); // time in nanoseconds (synchronized with clock of user timers)
 
// Nm Vector handler for NM Vector start on the FlexRay bus
typedef void (*VFlexRayNmVectorHandler) (uint8  channel, // FlexRay cluster
                                         uint16 len, 
                                         const  uint8 nmVec[12] );
 
// Status event handler on the FlexRay bus
typedef void (*VFlexRayStatusHandler) (uint8  channel, // FlexRay cluster
                                       uint32 state);  // 1 = sync, 0 = no sync ?

typedef void (*VFlexRaySlotHandler) (uint8  channel,   // FlexRay cluster
                                     uint32 slotId, 
                                     uint16  cycle);

// POCState event handler on the FlexRay bus
typedef void (*VFlexRayPOCStateHandler) (uint8 channel,     // FlexRay cluster
                                         uint32  pocState,  // POC state
                                         uint32  Fr_Info1,  // 0= synchronized, passive, 1= synchronized, active, 2= not synchronized, 3= Unknown 
                                         uint32  Fr_Info2); // 0= WAKEUP UNDEFINED, 1= WAKEUP RECEIVED HEADER, 2= WAKEUP RECEIVED WUP,  3= WAKEUP COLLISION HEADER, 
                                                            // 4= WAKEUP COLLISION WUP, 5= WAKEUP COLLISION UNKNOWN, 6= WAKEUP TRANSMITTED, 7=  WAKEUP RECEIVED


// Send a FlexRay message to the bus
// channel: channel index as used by the FlexRay driver, range 0-3 ? 
//        (Note: This is not the canoe channel)
extern void CANoeAPI_SendFlexRayMessage(uint8 channel,         // FlexRay cluster
                                        uint32 channelABMask,  // 1: CH A, 2: CH B, 3: CH A&B
                                        uint32 slotId, 
                                        uint32 baseCycle,  
                                        uint32 cycleRepetition,
                                        uint32 flags, 
                                        uint16 payloadLen,     // in bytes
                                        const uint8 data[]);


// Register a FlexRay message for transmission on the bus
// channel: channel index as used by the FlexRay driver, range 0-3 ?
//         (Note: This is not the canoe channel)
// MAY ONLY BE CALLED IN: MeasurementInit action of the VEcuStateHandler
extern void CANoeAPI_RegisterFlexRayMessage(uint8 channel,         // FlexRay cluster 
                                            uint32 channelABMask,  // 1: CH A, 2: CH B, 3: CH A&B 
                                            uint32 slotId, 
                                            uint32 baseCycle,  
                                            uint32 cycleRepetition,
                                            uint32 flags,          // see defines CANOEAPI_FLEXRAY_HEADERFLAG_XXX
                                            uint16 payloadLen);    // in bytes 


// Reset the FlexRay communication controller and send a Wakeup Pattern
extern void CANoeAPI_ResetFlexRayCCAndSendWUP(uint8 channel,       // FlexRay cluster 
                                              int wuChMask, 
                                              uint16 wuCount, 
                                              uint16 wuTxIdle, 
                                              uint16 wuTxLow, 
                                              char* cfg );         // not used 


// Reset the FlexRay communication controller and send a Wakeup Pattern
extern void CANoeAPI_ResetFlexRayCC(uint8 channel);                // FlexRay cluster 


// Parameter mode for function CANoeAPI_SetFlexRayMode
#define CANOEAPI_FLEXRAYTRANSCEIVERMODE_ACTIVE    0
#define CANOEAPI_FLEXRAYTRANSCEIVERMODE_NOTACTIVE 1


// Set the FlexRay transceiver to normal mode (CANOEAPI_FLEXRAYTRANSCEIVERMODE_ACTIVE) 
// or sleep mode (CANOEAPI_FLEXRAYTRANSCEIVERMODE_NOTACTIVE)
extern void CANoeAPI_SetFlexRayMode(uint8 channel, uint32 channelMask, uint32 mode);

// Set the FlexRay POC State 
extern void CANoeAPI_SetFlexRayPOCState(uint8 channel, sint32 ccNo, sint32 pocState);

// Set the FlexRay KeySlot
// MAY ONLY BE CALLED IN: MeasurementInit action of the VEcuStateHandler
extern void CANoeAPI_SetFlexRayKeySlot(uint8 channel,        // FlexRay cluster 
                                       uint32 channelMask,   //
                                       uint32 keySlotIndex,  //Index of the key slot to be configured (1=key slot 1, 2=key slot 2)
                                       uint32 slotId,        //Slot id of key slot   
                                       uint32 keySlotUsage); //0=None, 1=Startup/Sync/LeadingColdstart, 2=Sync, 3=Startup/Sync


// Register callback functions for the FlexRay bus
extern void CANoeAPI_SetFlexRayFrameHandler(VFlexRayFrameHandler frameHandler);
extern void CANoeAPI_SetFlexRayCycleHandler(VFlexRayStartCycleHandler startCycleHandler, VFlexRayNmVectorHandler nmVectorHandler);
extern void CANoeAPI_SetFlexRayStatusHandler(VFlexRayStatusHandler statusHandler);
extern void CANoeAPI_SetFlexRayPOCStateHandler(VFlexRayPOCStateHandler pocstateHandler);
extern void CANoeAPI_SetFlexRaySlotHandler(VFlexRaySlotHandler slotHandler);


// Register the slot ids for the slot event handler (VFlexRaySlotHandler)
// MAY ONLY BE CALLED IN: Load action of the VEcuStateHandler
extern void CANoeAPI_SetRequestedFlexRaySlotIDs(uint32 channel, uint32 lengthOfSlotNumberArray, uint16 *slotNumber);


// ============================================================================
// Access to LIN Bus
//
// ============================================================================

#define CANOEAPI_LINAPPLYHEADER     0x01
#define CANOEAPI_LINRECONFIGUREDATA 0x02

#define CANOEAPI_LINRESPONSEALWAYS  0xff

// error codes for the LIN error handler  VLinErrorHandler
#define CANOEAPI_LINTRANSMITERROR      1
#define CANOEAPI_LINCHECKSUMERROR      2
#define CANOEAPI_LINRECEIVEERROR       3
#define CANOEAPI_LINSYNCHERROR         4

// event handler for a transmission on the LIN bus
typedef void (*VLinMsgHandler) (uint8 channel, uint8 dir, uint32 id, uint8 dlc, uint8 data[]);

// event handler for receiving a wakeup frame on a LIN bus
typedef void (*VLinWakeupHandler) (uint8 channel, uint8 external);

// event handler for receiving a sleep mode frame on a LIN bus
typedef void (*VLinSleepHandler) (uint8 channel, uint8 external, uint8 isAwake, uint8 wasAwake, uint8 reason);

// Event handler for error indication on the LIN bus. The handler is called in several situations
//
// Transmission error on the LIN bus
//   The transmission error indication is called when no Slave responded to a transmission request.
//   (see also 'VIAOnLinTransmissionError::OnTransmError' at VIA interface and CAPL event procedure 'on linTransmError')
//   parameter error code: CANOEAPI_LINTRANSMITERROR (1)
//   parameter subcode:    unused, value is always zero
//   parameter id:         LIN Frame identifier,  Value range: 0..63
//
// Checksum error on the LIN bus
//   The checksum error indication is called when a frame was transmitted without a failure, but with an incorrect
//   checksum.
//   (see also 'VIAOnLinCheckSumError::OnCsError' at VIA interface and CAPL event procedure 'on linCsError')
//   parameter error code: CANOEAPI_LINCHECKSUMERROR (2)
//   parameter subcode:    Direction of transmission
//                         CANoeAPI_DIR_TX (1): Frame was transmitted by LIN hardware
//                         CANoeAPI_DIR_RX (0): Frame was received
//   parameter id:         LIN Frame identifier,  Value range: 0..63
//
// Receive error on the LIN bus
//   The receive error indication is called when an error occurred during a frame transmission.
//   (see also 'VIAOnLinReceiveError::OnReceiveError' at VIA interface and CAPL event procedure 'on linReceiveError')
//   parameter error code: CANOEAPI_LINRECEIVEERROR (3)
//   parameter subcode:    State and reason of the error. The bits 0-3 indicate the LIN hardware state at the time
//                         the error has occurred, while the bits 4-7 indicate the reason of the error. (see also
//                         CAPL selector lin_StateReason at linReceiveError)
//          Value for the states:
//                         0: Bus idle
//                         1: Waiting for SynchBreak
//                         2: Waiting for SynchField
//                         3: Waiting for frame ID
//                         4-12: Waiting for data byte or checksum byte depending on the frame DLC 
//                               (4: DLC 0,  12: DLC 8 - the checksum byte)
//                         14: Consecutive event (i.e. event resulting from further data interpretation, after already
//                             notified error for first offending byte).
//                         15: SleepMode. Only possible if the LIN hardware is in Master mode. In Slave mode, the LIN 
//                             hardware can be wakened by any type of bus traffic.
//          Values for the reason:
//                         0: Timeout
//                         1: Received an unexpected byte violating protocol. 
//                         2: Received a byte with framing error (with dominant stop bit).
//                         3: Unexpected Break field
//                         4: Unidentified error
//   parameter id:         LIN Frame identifier,  Value range: 0..63
//
//  Sync error Frame on the LIN bus
//  The sync error indication is called when the LIN hardware was unable to become synchronized to an external master.
//  (see also 'VIAOnLinSyncError::OnSyncError' at VIA interface and CAPL event procedure 'on linSyncError')
//   parameter error code: CANOEAPI_LINSYNCHERROR (4)
//   parameter subcode:    unused, value is always zero
//   parameter id:         unused, the value is always 0xffffffff
typedef void (*VLinErrorHandler) (uint8 channel, uint32 errorCode, uint32 subcode, uint32 id);


// Register callback functions for the LIN bus
extern void CANoeAPI_SetLinHandler(VLinMsgHandler messageHandler,
                                   VLinWakeupHandler wakeupHandler,
                                   VLinSleepHandler sleepHandler,
                                   VLinErrorHandler errorHandler);

// Set the node type. The function can only be called 
// in the 'INITMEASUREMENT' action of the ECU state change handler.
extern void CANoeAPI_SetLinNodeType(uint8 channel, boolean isMaster, uint8 wakeupID, uint8 frameCount, uint32 scheduleDuration);

// Send a LIN message to the LIN bus
extern void CANoeAPI_SendLinMessage(uint8 channel, uint32 id, uint32 flags, uint8 response, 
                                    uint8 dlc, uint8 data[8] );

// Send a wakeup frame on a LIN channel
extern void CANoeAPI_SendLinWakeupFrame(uint8 channel, uint32 ttobrk, uint32 count);

// Send a sleep mode from on a LIN channel
extern void CANoeAPI_SendLinSleepModeFrame(uint8 channel, uint8 silent, uint8 restartScheduler, uint32 id);


// ============================================================================
// Access to Ethernet
//
// ============================================================================

// Callback function for incoming Ethernet packet
typedef void (*VEthernetPacketHandler)(uint8 channel, uint8 dir, uint32 packetSize, const uint8 *packetData);

// Callback function for Ethernet adapter status update
// Possible states are:  status unknown = 0
//                       not connected  = 1
//                       connected      = 2
typedef void (*VEthernetStatusHandler)(uint8 channel, uint32 status );

// Register callback for incoming Ethernet packet
extern void CANoeAPI_RegisterEthernetPacket(VEthernetPacketHandler handler);

// Register callback for Ethernet status update
extern void CANoeAPI_RegisterEthernetStatus(VEthernetStatusHandler handler);

// Put an Ethernet packet on the bus
extern void CANoeAPI_OutputEthernetPacket(uint8 channel, uint32 packetSize, const uint8 *packetData);

// ============================================================================
// Access to CAN Bus
//
// ============================================================================
// Error codes for callback handler VCanErrHandler.
#define CANOEAPI_CANERRORACTIVE     1
#define CANOEAPI_CANERRORPASSIVE    2
#define CANOEAPI_CANWARNINGLIMIT    3
#define CANOEAPI_CANBUSOFF          4

// CAN message flags for handler VCanMsgHandler and function CANoeAPI_SendCanMessage
#define CANOEAPI_CAN_NERR              0x04  // NERR active during this message (single wire)
#define CANOEAPI_CAN_Wakeup            0x08  // message received in wakeup mode (high voltage)
#define CANOEAPI_CAN_RemoteFrame       0x10  // message is a remote frame
#define CANOEAPI_CAN_Srr             0x0200  // SRR (substitute remote request) bit for ExtId Can msgs, SRR is sent dominant if set
#define CANOEAPI_CAN_R0              0x0400  // R0 bit
#define CANOEAPI_CAN_R1              0x0800  // R1 bit
#define CANOEAPI_CAN_EDL             0x1000  // EDL (extended data length) bit for CAN FD
#define CANOEAPI_CAN_BRS             0x2000  // BRS (bit rate switch) bit for CAN FD
#define CANOEAPI_CAN_ESI             0x4000  // ESI (error state indicator) bit for CAN FD
#define CANOEAPI_CAN_ESICtrl         0x8000  // ESI control; if flag is set use ESI flag, else use node state
#define CANOEAPI_CAN_Consecutive    0x20000  // msg is a consecutive frame of a burst on the bus

// receive a rx-message from a can bus
// obsolete, use VCanMsgHandler
typedef void (*VCanRxHandler) (uint8 channel, uint32 id, uint8 dlc, uint8 data[]);

// receive a tx-indication from a can bus
// obsolete, use VCanMsgHandler
typedef void (*VCanTxHandler) (uint8 channel, uint32 id);

// Receive a status indication of the can controller.
// channel:    channel index as used by the can driver (Note: This is not the canoe channel)
// errCode     error code (use defines CANOEAPI_CANERRORACTIVE, CANOEAPI_CANERRORPASSIVE, CANOEAPI_CANWARNINGLIMIT, CANOEAPI_CANBUSOFF)
// errCntTx    transmit error counter
// errCntRx    receive error counter
typedef void (*VCanErrHandler) (uint8 channel, uint32 errCode, uint8 errCntTx, uint8 errCntRx);

// indication of a CAN frame (contains rx and tx events, works with CAN and CAN FD)
// channel:    channel index as used by the can driver (Note: This is not the canoe channel)
// id:         CAN identifier
// dir:        direction Rx or Tx  (use the defines CANOEAPI_DIR_RX and CANOEAPI_DIR_TX)
// flags:      CAN message flags (see above) 
// dataLength: Data length, 0 .. 64
// data:       Data bytes of the message
typedef void (*VCanMsgHandler) (uint8 channel, uint32 id, uint8 dir, uint32 flags,
                                uint8 dataLength, const uint8* data);

// Send a CAN message to the bus 
// channel: channel index as used by the can driver, range 0-3 
//          (Note: This is not the canoe channel)
// obsolete, use CANoeAPI_SendCanMessage
extern void CANoeAPI_SendMessage(uint8 channel, uint32 id, int dlc, volatile uint8 data[8], uint32 flags);

// Send a message to the CAN bus. The Function can be used for CAN and CAN FD frames.
// channel:    channel index as used by the can driver (Note: This is not the canoe channel)
// id:         CAN identifier
// flags:      CAN message flags (see above)
// txReqCount: Maximum number of transmission attempts. 
//             Range 0 .. 15,
//             With value 0 the message will be repeated until it has been sent successfully once.
// dataLength: Data length, 0 .. 64
// data:       Data bytes of the message
extern void CANoeAPI_SendCanMessage(uint8 channel, uint32 id, uint32 flags, uint8 txReqCount,
                                    uint8 dataLength, const uint8* data);

// Reset CAN controller (for example after a bus off)
// channel:    channel index as used by the can driver (Note: This is not the canoe channel)
extern void CANoeAPI_ResetCan(uint8 channel);

// Sets another baud rate. The values do not become active until the next call 
// of the function CANoeAPI_ResetCan.
extern void CANoeAPI_SetCanBtr(uint8 channel, uint8 btr0, uint8 btr1);

// Configure the the CAN controller parameters for arbitration and data phase.
// Additionally the acknowledgment can be switch on or off.
// The function performs an automatic reset of the CAN controller.
// Parameters:
//   channel           channel index as used by the can driver (Note: This is not the canoe channel)
//   arbBaudrate       baudrate for arbitration phase in Baud/s
//   arbTseg1          bit timing configuration for arbitration phase (TSEG1)
//   arbTseg2          bit timing configuration for arbitration phase (TSEG2)
//   arbSjw            bit timing configuration for arbitration phase (SJW)
//   arbSam            Samples for arbitration phase (0: one sample, 1: three samples)
//   arbFlags          flags for arbitration arbitration phase (normal or silent mode)
//   dbrBaudrate       baudrate for data phase in Baud/s
//   dbrTseg1          bit timing configuration for data phase (TSEG1)
//   dbrTseg2          bit timing configuration for data phase (TSEG2)
//   dbrSjw            bit timing configuration for data phase (SJW)
//   dbrSam            Samples for data phase (0: one sample, 1: three samples)
//   dbrFlags          flags for data arbitration phase:
//                     Bit 0:  CANOEAPI_CAN_NORMALMODE  normal mode, acknowledge is created
//                             CANOEAPI_CAN_SILENTMODE  silent mode, acknowledge is not created
//                     Bits 1-31:  unused, must be set to zero.
#define CANOEAPI_CAN_NORMALMODE 0
#define CANOEAPI_CAN_SILENTMODE 1
extern void CANoeAPI_SetCanConfiguration(uint8 channel,
                                         double arbBaudrate, uint8 arbTseg1, uint8 arbTseg2,
                                         uint8 arbSjw, uint8 arbSam, uint32 arbFlags,
                                         double dbrBaudrate, uint8 dbrTseg1, uint8 dbrTseg2,
                                         uint8 dbrSjw, uint8 dbrSam, uint32 dbrFlags);

// Switch the mode of the transceiver (see CAPL function SetCanCabsMode)
extern void CANoeAPI_SetCanCabsMode(uint8 channel, sint32 type, sint32 mode, sint32 flags);

// Register callback functions for the CAN bus (Rx and Tx events)
// obsolete, use CANoeAPI_SetCanMsgHandler
extern void CANoeAPI_SetCanHandler(VCanRxHandler, VCanTxHandler);

// Register callback function for the CAN bus (Data-Frames for CAN and CAN FD)
extern void CANoeAPI_SetCanMsgHandler(VCanMsgHandler);

// Register callback functions for the CAN bus (error handler)
extern void CANoeAPI_SetCanErrHandler(VCanErrHandler);

// ============================================================================
// Access to system variables
//
// Before using a system variable, you must declare its usage. The declaration 
// must be done in the 'LOAD' action of the ECU state change handler with the
// functions CANoeAPI_SysVar_DeclareInt and CANoeAPI_SysVar_DeclareFloat. These
// functions return a handle to the system variable that is needed to access 
// the value of the system variable.
//
// TODO: Describe the deferred behavior of setting a variable value.
//        E.g. a written value cannot be read back immediately...
//
// ============================================================================

#define CANOEAPI_SYSVAR_INVALIDHANDLE -1

// Declare a system variable of type 'Integer (32 Bit signed)'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// If the system variable can be successfully created, the a handle to the 
// system variable is returned. In case of a failure, the function returns 
// CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareInt(const char* nameSpace, const char* name, sint32 initValue);

// Declare a system variable of type 'Integer (32 Bit unsigned)'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// If the system variable can be successfully created, the a handle to the 
// system variable is returned. In case of a failure, the function returns 
// CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareUInt32(const char* nameSpace, const char* name, uint32 initValue);

// Declare a system variable of type 'Integer (64 Bit signed)'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// If the system variable can be successfully created, the a handle to the 
// system variable is returned. In case of a failure, the function returns 
// CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareSInt64(const char* nameSpace, const char* name, sint64 initValue);

// Declare a system variable of type 'Integer (64 Bit unsigned)'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// If the system variable can be successfully created, the a handle to the 
// system variable is returned. In case of a failure, the function returns 
// CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareUInt64(const char* nameSpace, const char* name, uint64 initValue);

// Declare a system variable of type 'Float'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// If the system variable can be successfully created, the a handle to the 
// system variable is returned. In case of a failure, the function returns 
// CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareFloat(const char* nameSpace, const char* name, double initValue);

// Structured system variables
//
// In order to use a structured system variable its type has to be defined first.
// You may use an existing type definition and its definition path or you may
// define your own struct type. Structured types may be nested, i.e. a struct
// member is either a POD or a structure.
//
// Enumeration for system variable struct member types
typedef enum eCANoeAPI_SysVar_StructMemberType
{
  SV_TYPE_BOOLEAN = 0,
  SV_TYPE_SINT8,
  SV_TYPE_UINT8,
  SV_TYPE_SINT16,
  SV_TYPE_UINT16,
  SV_TYPE_SINT32,
  SV_TYPE_UINT32,
  SV_TYPE_SINT64,
  SV_TYPE_UINT64,
  SV_TYPE_FLOAT32,
  SV_TYPE_FLOAT64,
  SV_TYPE_STRUCT,
} CANoeAPI_SysVar_StructMemberType;

// Flags for properties of system variable struct members
typedef enum eCANoeAPI_SysVar_StructMemberFlags
{
  CANOEAPI_SV_NOFLAGS = 0,
  CANOEAPI_SV_HAS_MIN_VALUE = 1,   // indicate that a physical limit exists (minimum is defined)
  CANOEAPI_SV_HAS_MAX_VALUE = 2,   // indicate that a physical limit exists (maximum is defined)
} CANoeAPI_SysVar_StructMemberFlags;

// A system variable value scale
typedef struct sCANoeAPI_SysVar_Scale
{
    sint64      lowerlimit;
    sint64      upperlimit;
    double      factor;
    double      offset;
    const char* unit;
    void*       reserved;
} CANoeAPI_SysVar_StructMember_Scale;

// A system variable value table entry
typedef struct sCANoeAPI_SysVar_ValueText
{
    sint64      value;
    const char* name;
    void*       reserved;
} CANoeAPI_SysVar_ValueText;

// A computation method
typedef struct sCANoeAPI_SysVar_CompuMethod
{
    CANoeAPI_SysVar_StructMember_Scale* scales;
    uint32                              scalecount;
    CANoeAPI_SysVar_ValueText*          values;
    uint32                              valuecount;
} CANoeAPI_SysVar_CompuMethod;

// Core struct to setup a system variable struct member definition
// Each struct member is defined by its name, an optional namespace
// name for nested struct definitions, a member type and bitlength
typedef struct sCANoeAPI_SysVar_StructMember
{
    const char*                       name;
    const char*                       nameSpace;
    CANoeAPI_SysVar_StructMemberType  type;
    uint32                            bitlength;
    CANoeAPI_SysVar_CompuMethod*      compumethod;
    CANoeAPI_SysVar_StructMemberFlags flags;
    double                            minValue;
    double                            maxValue;
} CANoeAPI_SysVar_StructMember;

// Helper macros to set a CANoeAPI_SysVar_StructMember
// The simplest struct member definition consisting of only 
// one member using the macros below would be:
//
// CANoeAPI_SysVar_StructMember myStructDefinition[] =
// {
//   SV_STRUCT_DEFINE_MEMBER( "Member", SV_TYPE_SINT16, 12),
// }
//
// Use the SV_STRUCT_BEGIN_DEFINITION macro to begin a nested struct definition
// and use SV_STRUCT_END_DEFINITION likewise to end it.
#define SV_STRUCT_DEFINE_MEMBER(name, type, length)                               { name, 0, type, length, 0, CANOEAPI_SV_NOFLAGS, 0.0, 0.0}
#define SV_STRUCT_DEFINE_MEMBER_AND_COMPUMETHOD(name, type, length, compumethod)  { name, 0, type, length, compumethod, CANOEAPI_SV_NOFLAGS, 0.0, 0.0}
#define SV_STRUCT_DEFINE_MEMBER_WITH_LIMITS(name, type, length, compumethod, flags, min, max) { name, 0, type, length, compumethod, flags, min, max}
#define SV_STRUCT_BEGIN_DEFINITION(name, nameSpace)                               { name, nameSpace, SV_TYPE_STRUCT, 0, 0, CANOEAPI_SV_NOFLAGS, 0.0, 0.0 }
#define SV_STRUCT_END_DEFINITION()                                                { 0, 0, 0, 0, 0, CANOEAPI_SV_NOFLAGS, 0.0, 0.0}

// Helper struct to setup a system variable struct definition
// A struct is defined by its name and an array of structure members
typedef struct sCANoeAPI_SysVar_StructDefinition
{
    const char*                   name;
    CANoeAPI_SysVar_StructMember* members;
    uint32                        membercount;
} CANoeAPI_SysVar_StructDefinition;

// Helper macros to set a CANoeAPI_SysVar_StructDefinition
// Using these macros you may define an array of struct definitions:
//
// CANoeAPI_SysVar_StructDefinition myStructDefinitions[] =
// {
//   SV_STRUCT_DEFINE( "myStruct", myStructDefinition),
//   SV_STRUCT_DEFINE( "myOtherStruct", myOtherStructDefinition),
// }
#define SV_STRUCT_MEMBER_COUNT( definition) ( sizeof( definition) / sizeof( definition[0]))
#define SV_STRUCT_DEFINE( name, definition) { name, definition, SV_STRUCT_MEMBER_COUNT( definition)}

// A storage union which holds a struct member value
typedef union sCANoeAPI_SysVar_StructMemberStorage
{
    boolean vBoolean;
    sint8   vSint8;
    uint8   vUint8;
    sint16  vSint16;
    uint16  vUint16;
    sint32  vSint32;
    uint32  vUint32;
    sint64  vSint64;
    uint64  vUint64;
    float32 vFloat32;
    float64 vFloat64;
    void*   vBuffer;
} CANoeAPI_SysVar_StructMemberStorage;

// A typed struct member value (e.g. the type and array field selects the union member)
typedef struct sCANoeAPI_SysVar_StructMemberValue
{
    CANoeAPI_SysVar_StructMemberType    type;
    char                                padding[4];
    CANoeAPI_SysVar_StructMemberStorage storage;
} CANoeAPI_SysVar_StructMemberValue;

// An untyped struct member location (may be used for direct copies into C structures)
typedef struct sCANoeAPI_SysVar_StructMemberLocation
{
    void*  address;
    uint32 size;
} CANoeAPI_SysVar_StructMemberLocation;

// A named struct member value used to identify a member value within a struct
// To setup an array of named member values you may write:
//
// CANoeAPI_SysVar_StructMemberNamedValue myStructValues[] =
// {
//   { "Member", 0, { SV_TYPE_SINT16, {0}, 1}},
// }
//
// NOTE: Designated structure/union member initializations aren't supported
//       in Visual C++ prior to VS2013 so you cannot set the value right away
typedef struct sCANoeAPI_SysVar_StructMemberNamedValue
{
    const char*                       name;
    uint32                            size;
    CANoeAPI_SysVar_StructMemberValue value;
} CANoeAPI_SysVar_StructMemberNamedValue;

// Helper macros to set struct member values
#define SV_STRUCT_SET_BOOLEAN( m, x)           m.size = 0; m.value.type = SV_TYPE_BOOLEAN; m.value.storage.vBoolean = x
#define SV_STRUCT_SET_BOOLEAN_BUFFER( m, x, s) m.size = s; m.value.type = SV_TYPE_BOOLEAN; m.value.storage.vBuffer = x
#define SV_STRUCT_SET_SINT8( m, x)             m.size = 0; m.value.type = SV_TYPE_SINT8;   m.value.storage.vSint8 = x
#define SV_STRUCT_SET_SINT8_BUFFER( m, x, s)   m.size = s; m.value.type = SV_TYPE_SINT8;   m.value.storage.vBuffer = x
#define SV_STRUCT_SET_UINT8( m, x)             m.size = 0; m.value.type = SV_TYPE_UINT8;   m.value.storage.vUint8 = x
#define SV_STRUCT_SET_UINT8_BUFFER( m, x, s)   m.size = s; m.value.type = SV_TYPE_UINT8;   m.value.storage.vBuffer = x
#define SV_STRUCT_SET_SINT16( m, x)            m.size = 0; m.value.type = SV_TYPE_SINT16;  m.value.storage.vSint16 = x
#define SV_STRUCT_SET_SINT16_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_SINT16;  m.value.storage.vBuffer = x
#define SV_STRUCT_SET_UINT16( m, x)            m.size = 0; m.value.type = SV_TYPE_UINT16;  m.value.storage.vUint16 = x
#define SV_STRUCT_SET_UINT16_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_UINT16;  m.value.storage.vBuffer = x;
#define SV_STRUCT_SET_SINT32( m, x)            m.size = 0; m.value.type = SV_TYPE_SINT32;  m.value.storage.vSint32 = x
#define SV_STRUCT_SET_SINT32_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_SINT32;  m.value.storage.vBuffer = x
#define SV_STRUCT_SET_UINT32( m, x)            m.size = 0; m.value.type = SV_TYPE_UINT32;  m.value.storage.vUint32 = x
#define SV_STRUCT_SET_UINT32_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_UINT32;  m.value.storage.vBuffer = x
#define SV_STRUCT_SET_SINT64( m, x)            m.size = 0; m.value.type = SV_TYPE_SINT64;  m.value.storage.vSint64 = x
#define SV_STRUCT_SET_SINT64_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_SINT64;  m.value.storage.vBuffer = x
#define SV_STRUCT_SET_UINT64( m, x)            m.size = 0; m.value.type = SV_TYPE_UINT64;  m.value.storage.vUint64 = x
#define SV_STRUCT_SET_UINT64_BUFFER( m, x, s)  m.size = s; m.value.type = SV_TYPE_UINT64;  m.value.storage.vBuffer = x
#define SV_STRUCT_SET_FLOAT32( m, x)           m.size = 0; m.value.type = SV_TYPE_FLOAT32; m.value.storage.vFloat32 = x
#define SV_STRUCT_SET_FLOAT32_BUFFER( m, x, s) m.size = s; m.value.type = SV_TYPE_FLOAT32; m.value.storage.vBuffer = x
#define SV_STRUCT_SET_FLOAT64( m, x)           m.size = 0; m.value.type = SV_TYPE_FLOAT64; m.value.storage.vFloat64 = x
#define SV_STRUCT_SET_FLOAT64_BUFFER( m, x, s) m.size = s; m.value.type = SV_TYPE_FLOAT64; m.value.storage.vBuffer = x

// Helper struct to setup a system variable struct declaration
// A structured system variable is declared inside a namespace
// with its name, definition and (optional) initialization values
typedef struct sCANoeAPI_SysVar_Struct
{
    const char*                             nameSpace;
    const char*                             name;
    const char*                             definition;
    CANoeAPI_SysVar_StructMemberNamedValue* initValues;
    uint32                                  count;
} CANoeAPI_SysVar_Struct;

// Helper macro to set a CANoeAPI_SysVar_Struct
#define SV_STRUCT( nameSpace, name, definition, initValues, count) { nameSpace, name, definition, initValues, count}

// Define a system variable struct with 'structure'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler.
// Returns TRUE if the system variable struct can be successfully defined
// In case of a failure, the function returns FALSE.
extern boolean CANoeAPI_SysVar_DefineStruct(const char* nameSpace, const char* name, const CANoeAPI_SysVar_StructMember* structure, uint32 count);

// Declare a system variable struct of type 'definition'. The function can only be called 
// in the 'LOAD' action of the ECU state change handler. The initValues are optional.
// If the system variable can be successfully created, the handle to the system variable 
// is returned. In case of a failure, the function returns CANOEAPI_SYSVAR_INVALIDHANDLE.
extern sint32 CANoeAPI_SysVar_DeclareStruct(const char* nameSpace, const char* name, const char* definition,
                                            const CANoeAPI_SysVar_StructMemberNamedValue* initValues, uint32 count);

// Set the value of system variable of type 'Integer (32 Bit signed)'.
extern void CANoeAPI_SysVar_SetInt(sint32 svhandle, sint32 value);

// Set the value of system variable of type 'Integer (32 Bit unsigned)'.
extern void CANoeAPI_SysVar_SetUInt32(sint32 svhandle, uint32 value);

// Set the value of system variable of type 'Integer 64 Bit signed)'.
extern void CANoeAPI_SysVar_SetSInt64(sint32 svhandle, sint64 value);

// Set the value of system variable of type 'Integer (64 Bit unsigned)'.
extern void CANoeAPI_SysVar_SetUInt64(sint32 svhandle, uint64 value);

// Set the value of system variable of type 'Double (64 Bit)'.
extern void CANoeAPI_SysVar_SetFloat(sint32 svhandle, double value);

// Set the value(s) of the indexed system variable struct member of type boolean.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetBoolean(sint32 svhandle, uint32 index, boolean value);
extern void CANoeAPI_SysVar_Struct_SetBoolean_Array(sint32 svhandle, uint32 index, const boolean* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type sint8.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetSint8(sint32 svhandle, uint32 index, sint8 value);
extern void CANoeAPI_SysVar_Struct_SetSint8_Array(sint32 svhandle, uint32 index, const sint8* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type uint8.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetUint8(sint32 svhandle, uint32 index, uint8 value);
extern void CANoeAPI_SysVar_Struct_SetUint8_Array(sint32 svhandle, uint32 index, const uint8* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type sint16.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetSint16(sint32 svhandle, uint32 index, sint16 value);
extern void CANoeAPI_SysVar_Struct_SetSint16_Array(sint32 svhandle, uint32 index, const sint16* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type uint16.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetUint16(sint32 svhandle, uint32 index, uint16 value);
extern void CANoeAPI_SysVar_Struct_SetUint16_Array(sint32 svhandle, uint32 index, const uint16* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type sint32.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetSint32(sint32 svhandle, uint32 index, sint32 value);
extern void CANoeAPI_SysVar_Struct_SetSint32_Array(sint32 svhandle, uint32 index, const sint32* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type uint32.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetUint32(sint32 svhandle, uint32 index, uint32 value);
extern void CANoeAPI_SysVar_Struct_SetUint32_Array(sint32 svhandle, uint32 index, const uint32* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type sint64.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetSint64(sint32 svhandle, uint32 index, sint64 value);
extern void CANoeAPI_SysVar_Struct_SetSint64_Array(sint32 svhandle, uint32 index, const sint64* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type uint64.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetUint64(sint32 svhandle, uint32 index, uint64 value);
extern void CANoeAPI_SysVar_Struct_SetUint64_Array(sint32 svhandle, uint32 index, const uint64* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type float32.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetFloat32(sint32 svhandle, uint32 index, float32 value);
extern void CANoeAPI_SysVar_Struct_SetFloat32_Array(sint32 svhandle, uint32 index, const float32* address, uint32 size);

// Set the value(s) of the indexed system variable struct member of type float64.
// The size parameter specifies the array length in bytes.
extern void CANoeAPI_SysVar_Struct_SetFloat64(sint32 svhandle, uint32 index, float64 value);
extern void CANoeAPI_SysVar_Struct_SetFloat64_Array(sint32 svhandle, uint32 index, const float64* address, uint32 size);

// Set the values of the indexed system variable struct member of type struct from a buffer
// The size parameter specifies the number of bytes.
extern void CANoeAPI_SysVar_Struct_SetStruct_From_Buffer(sint32 svhandle, uint32 index, const void* address, uint32 size);

// Set the values of the indexed system variable struct member of type struct from the specified locations
// The count parameter specifies the number of locations.
extern void CANoeAPI_SysVar_Struct_SetStruct_From_Locations(sint32 svhandle, uint32 index, CANoeAPI_SysVar_StructMemberLocation* locations, uint32 count);

// Get the value of system variable of type 'Integer (32 Bit signed)'.
extern sint32 CANoeAPI_SysVar_GetInt(sint32 svhandle);

// Get the value of system variable of type 'Integer (32 Bit unsigned)'.
extern uint32 CANoeAPI_SysVar_GetUInt32(sint32 svhandle);

// Get the value of system variable of type 'Integer (64 Bit signed)'.
extern sint64 CANoeAPI_SysVar_GetSInt64(sint32 svhandle);

// Get the value of system variable of type 'Integer (64 Bit unsigned)'.
extern uint64 CANoeAPI_SysVar_GetUInt64(sint32 svhandle);

// Get the value of system variable of type 'Double (64 Bit)'.
extern double CANoeAPI_SysVar_GetFloat(sint32 svhandle);

// Get the value(s) of the indexed system variable struct member of type boolean.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern boolean CANoeAPI_SysVar_Struct_GetBoolean(sint32 svhandle, uint32 index);
extern uint32  CANoeAPI_SysVar_Struct_GetBoolean_Array(sint32 svhandle, uint32 index, boolean* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type sint8.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern sint8  CANoeAPI_SysVar_Struct_GetSint8(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetSint8_Array(sint32 svhandle, uint32 index, sint8* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type uint8.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern uint8  CANoeAPI_SysVar_Struct_GetUint8(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetUint8_Array(sint32 svhandle, uint32 index, uint8* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type sint16.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern sint16 CANoeAPI_SysVar_Struct_GetSint16(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetSint16_Array(sint32 svhandle, uint32 index, sint16* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type uint16.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern uint16 CANoeAPI_SysVar_Struct_GetUint16(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetUint16_Array(sint32 svhandle, uint32 index, uint16* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type sint32.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern sint32 CANoeAPI_SysVar_Struct_GetSint32(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetSint32_Array(sint32 svhandle, uint32 index, sint32* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type uint32.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern uint32 CANoeAPI_SysVar_Struct_GetUint32(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetUint32_Array(sint32 svhandle, uint32 index, uint32* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type sint64.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern sint64 CANoeAPI_SysVar_Struct_GetSint64(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetSint64_Array(sint32 svhandle, uint32 index, sint64* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type uint64.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern uint64 CANoeAPI_SysVar_Struct_GetUint64(sint32 svhandle, uint32 index);
extern uint32 CANoeAPI_SysVar_Struct_GetUint64_Array(sint32 svhandle, uint32 index, uint64* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type float32.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern float32 CANoeAPI_SysVar_Struct_GetFloat32(sint32 svhandle, uint32 index);
extern uint32  CANoeAPI_SysVar_Struct_GetFloat32_Array(sint32 svhandle, uint32 index, float32* address, uint32 size);

// Get the value(s) of the indexed system variable struct member of type float64.
// The size parameter specifies the array length in bytes.
// The *_Array function returns the number of bytes copied.
extern float64 CANoeAPI_SysVar_Struct_GetFloat64(sint32 svhandle, uint32 index);
extern uint32  CANoeAPI_SysVar_Struct_GetFloat64_Array(sint32 svhandle, uint32 index, float64* address, uint32 size);

// Get the values of the indexed system variable struct member of type struct.
// The size parameter specifies the number of bytes.
// The number of copied bytes is returned.
extern uint32 CANoeAPI_SysVar_Struct_GetStruct_Into_Buffer(sint32 svhandle, uint32 index, void* address, uint32 size);

// Get the values of the indexed system variable struct member of type struct
// into the specified locations.
// The count parameter specifies the number of locations.
// The number of copied structure elements is returned.
extern uint32 CANoeAPI_SysVar_Struct_GetStruct_Into_Locations(sint32 svhandle, uint32 index, CANoeAPI_SysVar_StructMemberLocation* locations, uint32 count);

// Set a callback handler function for changes of a system variable of type 'Integer (32 Bit signed)'.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareInt
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// value       The new value of the system variable.
typedef void (*VSysVarHandlerInt) (sint32 param, sint32 value);
extern void CANoeAPI_SysVar_SetHandlerInt(sint32 svhandle, VSysVarHandlerInt f, sint32 param);

// Set a callback handler function for changes of a system variable of type 'Integer (32 Bit unsigned)'.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareUInt32
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// value       The new value of the system variable.
typedef void (*VSysVarHandlerUInt32) (sint32 param, uint32 value);
extern void CANoeAPI_SysVar_SetHandlerUInt32(sint32 svhandle, VSysVarHandlerUInt32 f, sint32 param);

// Set a callback handler function for changes of a system variable of type 'Integer (64 Bit signed)'.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareSInt64
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// value       The new value of the system variable.
typedef void (*VSysVarHandlerSInt64) (sint32 param, sint64 value);
extern void CANoeAPI_SysVar_SetHandlerSInt64(sint32 svhandle, VSysVarHandlerSInt64 f, sint32 param);

// Set a callback handler function for changes of a system variable of type 'Integer (64 Bit unsigned)'.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareUInt64
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// value       The new value of the system variable.
typedef void (*VSysVarHandlerUInt64) (sint32 param, uint64 value);
extern void CANoeAPI_SysVar_SetHandlerUInt64(sint32 svhandle, VSysVarHandlerUInt64 f, sint32 param);

// Set a callback handler function for changes of a system variable of type float.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareFloat
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// value       The new value of the system variable.
typedef void (*VSysVarHandlerFloat)(sint32 param, double value);
extern void CANoeAPI_SysVar_SetHandlerFloat(sint32 svhandle, VSysVarHandlerFloat f, sint32 param);

// Set a callback handler function for changes of a system variable of type struct.
// svhandle    Handle of the system variable returned by function CANoeAPI_SysVar_DeclareStruct
// f           The function, that should be called.
// param       A user defined parameter. When registering the callback function, you can specify
//             a value that is later given to the callback function as first parameter.
// buffer      Pointer to the buffer of the new value of the system variable.
// count       Number of bytes to copy from the buffer.
typedef void (*VSysVarHandlerStruct)(sint32 param, uint8* buffer, uint32 count);
extern void CANoeAPI_SysVar_SetHandlerStruct(sint32 svhandle, VSysVarHandlerStruct f, sint32 param);

// Applies the init value(s) as specified in the system variable declaration
extern void CANoeAPI_SysVar_ApplyInitValue(sint32 svhandle);


  // ============================================================================
  // Access to CANoe FunctionBus
  // ============================================================================

  // Type definitions and constants

  // Time constants
  typedef sint64 CANoeAPI_Time;
  typedef CANoeAPI_Time CANoeAPI_TimeDiff;
#define CANOEAPI_FUNCTIONBUS_TIMEDELTANOW ((CANoeAPI_TimeDiff)0)
#define CANOEAPI_FUNCTIONBUS_TIMEDELTANEVER ((CANoeAPI_TimeDiff)-1)
#define CANOEAPI_FUNCTIONBUS_TIMEUNDEFINED ((CANoeAPI_Time)-1)

  // Byte order for system variable members. Default is Intel byte order.
  typedef enum eCANoeAPI_ByteOrder
  {
    BYTEORDER_INTEL = 0,
    BYTEORDER_MOTOROLA = 1
  } CANoeAPI_ByteOrder;

  // Supported encodings for strings in system variable members. Default is UTF8.
  typedef enum eCANoeAPI_StringEncoding
  {
    STRINGENCODING_UTF8 = 65001,
    STRINGENCODING_UTF16 = 1200,
    STRINGENCODING_ISO88591 = 28591,
    STRINGENCODING_ISO88592 = 28592,
    STRINGENCODING_WINDOWS1252 = 1252
  } CANoeAPI_StringEncoding;

  // FunctionBus types
  typedef enum eCANoeAPI_FunctionBus_TypeTag
  {
    FB_TYPE_SIGNEDINTEGER = 0,  // Encoding: 2C
    FB_TYPE_UNSIGNEDINTEGER,    // Encoding: none
    FB_TYPE_FLOAT,              // Encoding: IEEE754
    FB_TYPE_STRING,             // Encoding: To be determined by GetEncoding
    FB_TYPE_ARRAY,
    FB_TYPE_STRUCT,
    FB_TYPE_UNION,
  } CANoeAPI_FunctionBus_TypeTag;
  // The representational type used to access a value
  typedef enum eCANoeAPI_FunctionBus_TypeLevel
  {
    FB_TYPELEVEL_PHYS = 0,  // Physical representation, restricted to Integer and Float
    FB_TYPELEVEL_IMPL,      // Implementation representation
    FB_TYPELEVEL_RAW,       // Bit-serialized representation
  } CANoeAPI_FunctionBus_TypeLevel;

  // Class of information available on a generic value port
  typedef enum eCANoeAPI_FunctionBus_ValueClass
  {
    FB_VALUECLASS_PORTVALUE = 0,     // The value entity directly related with the addressed PDU, Signal or Event port
    FB_VALUECLASS_SERVICESTATE,      // Service state of Service provider side FEP
    FB_VALUECLASS_CONNECTIONSTATE,   // Connection state of Service AP
    FB_VALUECLASS_SUBSCRIPTIONSTATE, // Subscription state of PDU/Event AP
    FB_VALUECLASS_LATESTCALL,        // Latest call input parameters of function AP
    FB_VALUECLASS_LATESTRETURN,      // Latest call return parameters of function AP
    FB_VALUECLASS_PARAMDEFAULTS      // VSIM configuration of function provider side AP
  } CANoeAPI_FunctionBus_ValueClass;

  // Mode with that notifications about value changes are sent
  typedef enum eCANoeAPI_FunctionBus_UpdateMode
  {
    FB_UPDATEMODE_NOTIFYONUPDATE = 0,  // Notify whenever value is set (on update)
    FB_UPDATEMODE_NOTIFYONCHANGE,      // Notify whenever value is set and the new value is different from the old value (on change)
  } CANoeAPI_FunctionBus_UpdateMode;

  // States a FunctionBus service call can be in
  typedef enum eCANoeAPI_FunctionBus_FunctionCallState
  {
    FB_FUNCTIONCALLSTATE_UNDEFINED = 0,
    FB_FUNCTIONCALLSTATE_CALLING,
    FB_FUNCTIONCALLSTATE_CALLED,
    FB_FUNCTIONCALLSTATE_RETURNING,
    FB_FUNCTIONCALLSTATE_RETURNED,
    FB_FUNCTIONCALLSTATE_FINALIZING,
  } CANoeAPI_FunctionBus_FunctionCallState;

  // Update state of a value
  typedef enum eCANoeAPI_FunctionBus_ValueState
  {
    FB_VALUESTATE_OFFLINE = 0,     // Value is still offline
    FB_VALUESTATE_MEASURED,  // Value has been updated
  } CANoeAPI_FunctionBus_ValueState;

  // Handles (opaque pointers) for call contexts, callbacks, ports, values and types
  typedef struct CANoeAPI_FunctionBus_SignalSenderPort* CANoeAPI_FunctionBus_SignalSenderPortHandle;
  typedef struct CANoeAPI_FunctionBus_SignalReceiverPort* CANoeAPI_FunctionBus_SignalReceiverPortHandle;
  typedef struct CANoeAPI_FunctionBus_FunctionClientPort* CANoeAPI_FunctionBus_FunctionClientPortHandle;
  typedef struct CANoeAPI_FunctionBus_FunctionServerPort* CANoeAPI_FunctionBus_FunctionServerPortHandle;
  typedef struct CANoeAPI_FunctionBus_ValuePort* CANoeAPI_FunctionBus_ValuePortHandle;
  typedef struct CANoeAPI_FunctionBus_Value* CANoeAPI_FunctionBus_ValueHandle;
  typedef struct CANoeAPI_FunctionBus_Status* CANoeAPI_FunctionBus_StatusHandle;
  typedef struct CANoeAPI_FunctionBus_Type* CANoeAPI_FunctionBus_TypeHandle;
  typedef struct CANoeAPI_FunctionBus_CallContext* CANoeAPI_FunctionBus_CallContextHandle;
  typedef struct CANoeAPI_FunctionBus_SignalReceiverCallback* CANoeAPI_FunctionBus_SignalReceiverCallbackHandle;
  typedef struct CANoeAPI_FunctionBus_FunctionServerCallback* CANoeAPI_FunctionBus_FunctionServerCallbackHandle;
  typedef struct CANoeAPI_FunctionBus_StatusCallback* CANoeAPI_FunctionBus_StatusCallbackHandle;
#define CANOEAPI_FUNCTIONBUS_SIGNALSENDERPORTHANDLEINVALID ((const CANoeAPI_FunctionBus_SignalSenderPortHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_SIGNALRECEIVERPORTHANDLEINVALID ((const CANoeAPI_FunctionBus_SignalReceiverPortHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_FUNCTIONCLIENTPORTHANDLEINVALID ((const CANoeAPI_FunctionBus_FunctionClientPortHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_FUNCTIONSERVERPORTHANDLEINVALID ((const CANoeAPI_FunctionBus_FunctionServerPortHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_VALUEPORTHANDLEINVALID ((const CANoeAPI_FunctionBus_ValuePortHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_VALUEHANDLEINVALID ((const CANoeAPI_FunctionBus_ValueHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_STATUSHANDLEINVALID ((const CANoeAPI_FunctionBus_StatusHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_TYPEHANDLEINVALID ((const CANoeAPI_FunctionBus_TypeHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_CALLCONTEXTHANDLEINVALID ((const CANoeAPI_FunctionBus_CallContextHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_SIGNALRECEIVERCALLBACKHANDLEINVALID ((const CANoeAPI_FunctionBus_SignalReceiverCallbackHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_FUNCTIONSERVERCALLBACKHANDLEINVALID ((const CANoeAPI_FunctionBus_FunctionServerCallbackHandle)nullptr)
#define CANOEAPI_FUNCTIONBUS_STATUSCALLBACKHANDLEINVALID ((const CANoeAPI_FunctionBus_StatusCallbackHandle)nullptr)
  // Handle for type members
  typedef long CANoeAPI_FunctionBus_TypeMemberHandle;
#define CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEWHOLE ((const CANoeAPI_FunctionBus_TypeMemberHandle)-1)
#define CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEINVALID ((const CANoeAPI_FunctionBus_TypeMemberHandle)-2)

#define CANOEAPI_FUNCTIONBUS_SIGNALRECEIVERCALLBACKFUNCTION_UNDEFINED ((CANoeAPI_FunctionBus_SignalReceiverCallbackFunction)nullptr)
#define CANOEAPI_FUNCTIONBUS_FUNCTIONCLIENTCALLBACKFUNCTION_UNDEFINED ((CANoeAPI_FunctionBus_FunctionClientCallbackFunction)nullptr)
#define CANOEAPI_FUNCTIONBUS_FUNCTIONSERVERCALLBACKFUNCTION_UNDEFINED ((CANoeAPI_FunctionBus_FunctionServerCallbackFunction)nullptr)
#define CANOEAPI_FUNCTIONBUS_STATUSCALLBACKFUNCTION_UNDEFINED ((CANoeAPI_FunctionBus_StatusCallbackFunction)nullptr)

  // Observer functions

  // Callback handler to notify observers whenever a FunctionBus signal port receives a value.
  // Indicates that the signal value at the receiver port has changed
  // [IN] inUserData:  User data pointer, specified when this callback was registered
  // [IN] inTime: Absolute time the signal value was updated
  // [IN] inReceiverPortHandle: Handle of receiving signal port
  typedef void(*CANoeAPI_FunctionBus_SignalReceiverCallbackFunction)(
    const void* inUserData,
    CANoeAPI_Time inTime,
    const CANoeAPI_FunctionBus_SignalReceiverPortHandle inReceiverPortHandle);

  // Callback handler to notify client-side observers when the called server-side FunctionBus service port receives 
  // the call or either an error or the result arrives. 
  // Indicates that the invocation initiated at the client port changed its state.
  // Note: The obtained inCallContextHandle will be released implicitly.
  // [IN] inUserData:  User data pointer, specified when this callback was registered
  // [IN] inTime: Absolute time this state change was observed
  // [IN] inCallContextHandle: Call context of the affected call
  // [IN] inCallState: State reached
  // [IN] inClientPortHandle: Handle of client function port
  typedef void(*CANoeAPI_FunctionBus_FunctionClientCallbackFunction)(
    const void* inUserData,
    CANoeAPI_Time inTime,
    const CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_FunctionBus_FunctionCallState inCallState,
    const CANoeAPI_FunctionBus_FunctionClientPortHandle inClientPortHandle);

  // Callback handler to notify server-side observers whenever a FunctionBus service port 
  // receives a call from a client to be handled.
  // Indicates that an invocation request arrived at the server port
  // Note: The obtained inCallContextHandle will be released implicitly, if not made permanent via CANoeAPI_FunctionBus_CallContext_Keep.
  //       This allows to defer the actual return via CANoeAPI_FunctionBus_FunctionServerPort_SetTimeToReply after returning from this handler.
  // [IN] inUserData:  User data pointer, specified when this callback was registered
  // [IN] inTime: Absolute time this state change was observed
  // [IN] inCallContextHandle: Call context of the affected call
  // [IN] inCallState: State reached
  // [IN] inServerPortHandle: Handle of server function port
  typedef void(*CANoeAPI_FunctionBus_FunctionServerCallbackFunction)(
    const void* inUserData,
    CANoeAPI_Time inTime,
    const CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_FunctionBus_FunctionCallState inCallState,
    const CANoeAPI_FunctionBus_FunctionServerPortHandle inServerPortHandle);

  // Callback handler to notify value observers whenever a value changes or updates.
  // Indicates that an invocation request arrived at the server port
  // [IN] inUserData:  User data pointer, specified when this callback was registered
  // [IN] inTime: Absolute time this value update was observed
  // [IN] inState: Updated value entity status object (provides access to the current value)
  typedef void(*CANoeAPI_FunctionBus_StatusCallbackFunction)(
    const void* inUserData,
    CANoeAPI_Time inTime,
    const CANoeAPI_FunctionBus_StatusHandle inStatus);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Factory service

  // Obtain access to a functional end point sending a signal.
  // [IN] inPath: FunctionBus model path identifier, pointer to a zero-terminated ASCII string
  // [OUT] outPortHandle: Valid port handle, if successful, an invalid handle if it could not be retrieved or in case of another error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_GetSignalSenderPort(
    const char* inPath,
    CANoeAPI_FunctionBus_SignalSenderPortHandle* outPortHandle);

  // Obtain access to a functional end point receiving a signal.
  // [IN] inPath: FunctionBus model path identifier, pointer to a zero-terminated ASCII string
  // [OUT] outPortHandle: Valid port handle, if successful, an invalid handle if it could not be retrieved or in case of another error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_GetSignalReceiverPort(
    const char* inPath,
    CANoeAPI_FunctionBus_SignalReceiverPortHandle* outPortHandle);

  // Obtain access to a functional end point requiring a service function.
  // Path must refer to a specific end point of a service *function*, e.g. someNs::someObj[someClient,someServer].someFunc"
  // [IN] inPath: FunctionBus model path identifier, pointer to a zero-terminated ASCII string
  // [OUT] outPortHandle: Valid port handle, if successful, or an invalid handle 
  //          if it could not be retrieved or in case of another error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_GetFunctionClientPort(
    const char* inPath,
    CANoeAPI_FunctionBus_FunctionClientPortHandle* outPortHandle);

  // Obtain access to a functional end point providing a service function.
  // Path must refer to a specific end point of a service *function*, e.g. someNs::someObj[someClient,someServer].someFunc"
  // [IN] inPath: FunctionBus model path identifier, pointer to a zero-terminated ASCII string
  // [OUT] outPortHandle: Valid port handle, if successful, or an invalid handle 
  //          if it could not be retrieved or in case of another error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_GetFunctionServerPort(
    const char* inPath,
    CANoeAPI_FunctionBus_FunctionServerPortHandle* outPortHandle);

  // Obtain access to a port generically for reading and writing values.
  // [IN] inPath: FunctionBus model path identifier, pointer to a zero-terminated ASCII string
  // [OUT] outPortHandle: Valid port handle, if successful, or an invalid handle 
  //          if it could not be retrieved or in case of another error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_GetValuePort(
    const char* inPath,
    CANoeAPI_FunctionBus_ValuePortHandle* outPortHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Signal sender ports

  // Release the port instance, must be called for any port instance obtained from this API to free resources after use.
  // [IN] inPortHandle: Handle to the port to be released
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_SignalSenderPort_Release(
    CANoeAPI_FunctionBus_SignalSenderPortHandle inPortHandle);

  // Retrieve the value of this signal sender port that was last set.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: Decide on which type level this value is accessed
  // [IN] inMemberHandle: Handle of the member to access
  // [OUT] outValueHandle: The value object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalSenderPort_GetValue(
    CANoeAPI_FunctionBus_SignalSenderPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueHandle* outValueHandle);

  // Retrieve the type of this signal sender port signal.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The signal's type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalSenderPort_GetType(
    CANoeAPI_FunctionBus_SignalSenderPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Update the value of a signal's sender port to be send. Depending on the signal port's configuration, 
  // the updated value will be sent either immediately or with the upcoming cycle.
  // If the value on a particular sub member was retrieved, only that member of the overall signal value will be updated.
  // Value may not be updated in case of error.
  // [IN] inPortHandle: Handle of the port
  // [IN] inValueHandle: The value object containing the new value
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_SignalSenderPort_SetValue(
    CANoeAPI_FunctionBus_SignalSenderPortHandle inPortHandle,
    const CANoeAPI_FunctionBus_ValueHandle inValueHandle);

  // Retrieve status information of this port.
  // [IN] Handle to a member if this is a composite type
  // [OUT] The status object, if successful
  // [RET] kVIA_OK if the query was successful, kVIA_ParameterInvalid in case of a bad parameter
  extern boolean CANoeAPI_FunctionBus_SignalSenderPort_GetStatus(
    CANoeAPI_FunctionBus_SignalSenderPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_StatusHandle* outStatusHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Signal receiver ports

  // Release the port instance, must be called for any port instance obtained from this API to free resources after use.
  // [IN] inPortHandle: Handle to the port to be released
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_Release(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle);

  // Retrieve the value that was last received of a signal receiver port .
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: Decide on which type level this value is accessed
  // [IN] inMemberHandle: Handle of the member to access
  // [OUT] outValueHandle: The value object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_GetValue(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueHandle* outValueHandle);

  // Retrieve the type of this signal receiver port signal.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The signal's type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_GetType(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Retrieve status information of this port.
  // [IN] Handle to a member if this is a composite type
  // [OUT] The status object, if successful
  // [RET] kVIA_OK if the query was successful, kVIA_ParameterInvalid in case of a bad parameter
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_GetStatus(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_StatusHandle* outStatus);

  // Register an observer to be notified when this signal port is updated, or the updated value changes.
  // The time the value is received depends on the port's binding properties (e.g., cyclic, immediately).
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallbackFunction: The observer callback function
  // [IN] inUpdateMode: Decide to observe only changes in value or any value updates
  // [IN] inUserData:  User data pointer, extra argument provided on callbacks
  // [OUT] outCallbackHandle: Handle to the callback, if successful, else an invalid handle
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_RegisterObserver(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle,
    CANoeAPI_FunctionBus_SignalReceiverCallbackFunction inCallbackFunction,
    CANoeAPI_FunctionBus_UpdateMode inUpdateMode,
    const void* inUserData,
    CANoeAPI_FunctionBus_SignalReceiverCallbackHandle* outCallbackHandle);

  // Unregister a previously registered observer.
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallbackHandle: Handle from a previously registered observer callback
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_SignalReceiverPort_UnregisterObserver(
    CANoeAPI_FunctionBus_SignalReceiverPortHandle inPortHandle,
    const CANoeAPI_FunctionBus_SignalReceiverCallbackHandle inCallbackHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Function client ports

  // Release the port instance, must be called for any port instance obtained from this API to free resources after use.
  // [IN] Handle of the port to be released
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_FunctionClientPort_Release(
    CANoeAPI_FunctionBus_FunctionClientPortHandle inPortHandle);

  // Retrieve the type of this function's in parameters.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionClientPort_GetInParamsType(
    CANoeAPI_FunctionBus_FunctionClientPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Retrieve the type of this function's out parameters.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionClientPort_GetOutParamsType(
    CANoeAPI_FunctionBus_FunctionClientPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Initiate a function call. The call is invoked by calling InvokeCall on the handle obtained. 
  // Note: The obtained outCallContextHandle must be released explicitly via CANoeAPI_FunctionBus_CallContext_Release after use,
  //       typically after CANoeAPI_FunctionBus_FunctionClientPort_InvokeCall.
  // [IN] inPortHandle: Handle of the port
  // [OUT] outCallContextHandle: Context of the call, if successful; or CANOEAPI_FUNCTIONBUS_CALLCONTEXTHANDLEINVALID if not successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionClientPort_BeginCall(
    CANoeAPI_FunctionBus_FunctionClientPortHandle inPortHandle,
    CANoeAPI_FunctionBus_CallContextHandle* outCallContextHandle);

  // Trigger function call that was previously initiated, typically after all in arguments are updated.
  // The observer is notified about all state changes for this call.
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallbackFunction: Observer callback function (optional, can be CANOEAPI_FUNCTIONBUS_FUNCTIONCLIENTCALLBACKFUNCTION_UNDEFINED)
  // [IN] inCallContextHandle: Context of a call obtained from BeginCall
  // [IN] inUserData:  User data pointer, extra argument provided on callbacks
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_FunctionClientPort_InvokeCall(
    CANoeAPI_FunctionBus_FunctionClientPortHandle inPortHandle,
    CANoeAPI_FunctionBus_FunctionClientCallbackFunction inCallbackFunction,
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    const void* inUserData);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Function server ports

  // Release the port instance, must be called for any port instance obtained from this API to free resources after use.
  // [IN] Handle of the port to be released
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_Release(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle);

  // Retrieve the type of this function's in parameters.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_GetInParamsType(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Retrieve the type of this function's out parameters.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The type level the returned type will represent
  // [OUT] outTypeHandle: The type object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_GetOutParamsType(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Obtain a value handle containing all default output arguments of this port.
  // The first members is a struct with default values for all in/inout arguments (in the same order as the struct obtained from GetOutParams).
  // Inout arguments are accessible as a struct named by the argument. The struct can be used to configure the VSIM for automatic replies:
  // * struct member named "Value" of argument type: value to reply
  // * struct member named "Behavior" with values "UseDefaultValue" = 0, "UseInValue" = 1
  // Additional members of the VSIM functionality are appended: 
  // * A special member named "ReturnValue" refers to the return value, it is only defined if the signature's return type is not void.
  // * A special member named "ServerSimulatorMode" with values "Auto" = 0, "OffOrManual" = 1, "Discard" = 2
  // * A special member named "ReturnDelay" with the return to reply time in nano seconds
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallContextHandle: Context of a call obtained from BeginCall
  // [IN] inLevel: Decide on which type level this value is accessed
  // [OUT] outDefaultOutParamsValueHandle: The value handle, if successful, or an invalid handle if not successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_GetDefaultOutParams(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_ValueHandle* outDefaultOutParamsValueHandle);

  // Update the default output arguments for this port.
  // [IN] inPortHandle: Handle of the port
  // [IN] inDefaultOutParamsValueHandle: Handle of the value to be set
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_SetDefaultOutParams(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    const CANoeAPI_FunctionBus_ValueHandle inDefaultOutParamsValueHandle);

  // Register an observer to be notified when calls handled by this port change their state.
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallbackFunction: Pointer to a callback method
  // [IN] inStateToObserve: The observer is triggered for any call reaching this state
  // [IN] inUserData:  User data pointer, extra argument provided on callbacks
  // [OUT] outCallbackHandle: Handle to the callback, if successful; CANOEAPI_FUNCTIONBUS_CALLBACKHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_RegisterObserver(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    CANoeAPI_FunctionBus_FunctionServerCallbackFunction inCallbackFunction,
    CANoeAPI_FunctionBus_FunctionCallState inStateToObserve,
    const void* inUserData,
    CANoeAPI_FunctionBus_FunctionServerCallbackHandle* outCallbackHandle);

  // Unregister a previously registered observer.
  // [IN] inPortHandle: Handle of the port
  // [IN] Handle from a previously registered observer callback 
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_FunctionServerPort_UnregisterObserver(
    CANoeAPI_FunctionBus_FunctionServerPortHandle inPortHandle,
    const CANoeAPI_FunctionBus_FunctionServerCallbackHandle inCallbackHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Generic value ports (signal, PDU, service FEP, ...)

  // Release the port instance, must be called for any port instance obtained from this API to free resources after use.
  // [IN] Handle of the port to be released
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_ValuePort_Release(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle);

  // Retrieve the value of this port that was last set.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: Decide on which type level this value is accessed
  // [IN] inMemberHandle: Handle to a member if this is a composite type
  // [IN] inValueClass: Identifies the specific value entity associated with the port
  // [OUT] outValueHandle: The value object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_ValuePort_GetValue(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueClass inValueClass,
    CANoeAPI_FunctionBus_ValueHandle* outValueHandle);

  // Obtain access to a FunctionBus data type for reflection purposes.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: The type level the returned type will represent
  // [IN] inValueClass: Identifies the specific value entity associated with the port
  // [OUT] outTypeHandle: Type handle, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_ValuePort_GetType(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_ValueClass inValueClass,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Update the value of the port. Depending on the port and value class this may fail (read-only values).
  // [IN] inPortHandle: Handle of the port
  // [IN] inValueHandle: The value object containing the new value
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_ValuePort_SetValue(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle,
    const CANoeAPI_FunctionBus_ValueHandle inValueHandle);

  // Retrieve status information of this port.
  // [IN] inPortHandle: Handle of the port
  // [IN] inMemberHandle: Handle to a member if this is a composite type
  // [IN] inValueClass: Identifies the specific value entity associated with the port
  // [OUT] outStatusHandle: The status object, if successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_ValuePort_GetStatus(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueClass inValueClass,
    CANoeAPI_FunctionBus_StatusHandle* outStatusHandle);

  // Retrieve the statically configured initialization value of this port.
  // [IN] inPortHandle: Handle of the port
  // [IN] inLevel: Decide on which type level this value is accessed
  // [IN] inMemberHandle: Handle to a member if this is a composite type
  // [IN] inValueClass: Identifies the specific value entity associated with the port
  // [OUT] outValueHandle: The initial value object, if successful, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_ValuePort_GetInitValue(
    CANoeAPI_FunctionBus_ValuePortHandle inPortHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueClass inValueClass,
    CANoeAPI_FunctionBus_ValueHandle* outValueHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: A call context. 

  // Release the call context obtained within a server 
  // CANoeAPI_FunctionBus_FunctionServerCallbackFunction or a client's BeginCall.
  // This allows to prolong the lifetime of a call context beyond the return from the 
  // callback handler or after InvokeCall.
  // [IN] inCallContextHandle: Handle of the call context to be released
  // [RET] True iff succeeded
  extern boolean CANoeAPI_FunctionBus_CallContext_Release(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle);

  // Create a permanent call context from this, which can be used beyond the lifetime of a callback 
  // (e.g., CANoeAPI_FunctionBus_FunctionServerCallbackFunction) and must be released explicitly.
  // You must manually call CANoeAPI_FunctionBus_CallContext_Release to release the obtained handle.
  // [IN] inCallContextHandle: Handle of the call context to make permanent.
  // [OUT] outPermanentCallContextHandle: Handle of the permanent call context.
  // [RET] True iff succeeded
  extern boolean CANoeAPI_FunctionBus_CallContext_MakePermanent(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_FunctionBus_CallContextHandle* outPermanentCallContextHandle);

  // Obtain a value handle containing all input arguments of this call.
  // * A special member named "RequestId" refers to the internal ID used to identify this call instance, 
  //   it is ascertained to be globally unique per simulation run.
  // [IN] inCallContextHandle: Context of a call obtained from BeginCall
  // [IN] inLevel: Decide on which type level this value is accessed
  // [OUT] outInParamsValueHandle: The value handle, if successful, or an invalid handle if not successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_CallContext_GetInParams(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_ValueHandle* outInParamsValueHandle);

  // Obtain a value handle containing all output arguments of this call.
  // Additional members of the VSIM functionality are appended: 
  // * A special member named "RequestId" refers to the internal ID used to identify this call instance, 
  //   it is ascertained to be globally unique per simulation run.
  // * A special member named "ReturnValue" refers to the return value, it is only defined if the 
  //   signature's return type is not void.
  // [IN] inCallContextHandle: Context of a call obtained from BeginCall
  // [IN] inLevel: Decide on which type level this value is accessed
  // [OUT] outOutParamsValueHandle: The value handle, if successful, or an invalid handle if not successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_CallContext_GetOutParams(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_ValueHandle* outOutParamsValueHandle);

  // Update the in parameters value for a particular call.
  // [IN] inCallContextHandle: Handle of a call obtained from BeginCall
  // [IN] inInParamsValueHandle: The handle of the value to be set
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_CallContext_SetInParams(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    const CANoeAPI_FunctionBus_ValueHandle inInParamsValueHandle);

  // Update the out parameters value for a particular call.
  // [IN] inCallContextHandle: Handle of a call obtained from BeginCall
  // [IN] inOutParamsValueHandle: The value handle, or an invalid handle if not successful
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_CallContext_SetOutParams(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    const CANoeAPI_FunctionBus_ValueHandle inOutParamsValueHandle);

  // Update a call's time to reply.
  // [IN] inCallContextHandle: Handle of the call context for which the reply time is to be set.
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_CallContext_SetTimeToReply(
    CANoeAPI_FunctionBus_CallContextHandle inCallContextHandle,
    CANoeAPI_TimeDiff inRelativeTimeToReply);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: A ValueEntity's value. 

  // Release the value, must be called for any obtained value to free resources after use.
  // [IN] inValueHandle: Handle of the value to be released
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_Value_Release(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle);

  // Retrieve type of this particular value. Reflection on type is required to obtain a member handle.
  // [IN] inValueHandle: Handle of the value
  // [OUT] outTypeHandle: Type of this value, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetType(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Get the access level of this type (Impl/Phys/Raw). To access values at a different level, another value must be retrieved from the port.
  // [IN] inValueHandle: Handle of the value
  // [OUT] outLevel: Type level used when accessing this value
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetLevel(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeLevel* outLevel);

  // Getting/setting value of members and root (the latter when inMemberHandle is nullptr)

  // Set value. Value the member handle is pointing to must be of type signed integer.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] inValue: Value to be set
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetSignedInteger(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    sint64  inValue);

  // Get value. Value the member handle is pointing to must be of type signed integer.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outValue: Pointer to a variable the value will be written to; left unchanged in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetSignedInteger(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    sint64* outValue);

  // Set value. Value the member handle is pointing to must be of type unsigned integer.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] inValue: Value to be set
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetUnsignedInteger(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint64  inValue);

  // Get value. Value the member handle is pointing to must be of type unsigned integer.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outValue: Pointer to a variable the value will be written to; left unchanged in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetUnsignedInteger(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint64* outValue);

  // Set value. Value the member handle is pointing to must be of type float.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] inValue: Value to be set
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetFloat(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    double  inValue);

  // Get value. Value the member handle is pointing to must be of type float.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outValue: Pointer to a variable the value will be written to; left unchanged in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetFloat(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    double* outValue);

  // Set value to data in internally used serialization. Value the member handle is pointing to must be of type array or string.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] inValueBuffer: Pointer to a memory buffer of values to be set
  // [IN] inNumBytes: Size of memory buffer in bytes
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetData(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    const void* inValueBuffer,
    uint32 inNumBytes);

  // Get data of value as internally serialized. Value the member handle is pointing to must be of type array or string.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outValueBuffer: Pointer to a memory buffer the values will be written to; left unchanged if buffer is too small or failed
  // [IN] inNumBytes: Size of memory buffer in bytes
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetData(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    void* outValueBuffer,
    uint32 inNumBytes);

  // Getting/setting length of array

  // Set array length. This value must be an array type.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] Array length to be set for this value
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetArrayLength(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint32  inLength);

  // Get array length. This value must be an array type.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outLength: Array length of this value; -1 if array length could be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetArrayLength(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint32* outLength);

  // Check/Set if struct member is valid

  // Set a member of this value as a valid member. Value must be of composite type.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [IN] inFlag: Flag that is true iff this member is valid
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_SetIsValid(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    boolean inFlag);

  // Determine if a member of this value is a valid. Value must be of composite type.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outFlag: Flag that is true iff this member is valid; left unchanged if value could not be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_IsValid(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    boolean* outFlag);

  // Get currently valid member of a union. Value must be of union type.
  // [IN] inValueHandle: Handle of the value
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outIndex: Index of the member that is valid, -1 if index could not be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Value_GetValidMemberIndex(
    CANoeAPI_FunctionBus_ValueHandle inValueHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint32* outIndex);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: A Value entity's live status.

  // Release the status, must be called for any obtained status to free resources after use.
  // [IN] inStatusHandle: Handle of the status to be released
  // [RET] True iff queuing succeeded
  extern boolean CANoeAPI_FunctionBus_Status_Release(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle);

  // Retrieve the value of the associated value entity.
  // [IN] inStatusHandle: Handle of the status
  // [IN] inLevel: Decide on which type level this value is accessed
  // [IN] inMemberHandle: Handle of the member to access
  // [OUT] outValueHandle: Value of this value entity, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_GetValue(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_ValueHandle* outValueHandle);

  // Retrieve the value of the associated value entity.
  // [IN] inStatusHandle: Handle of the status
  // [IN] inLevel: The type level the returned type will represent
  // [OUT] outTypeHandle: Type of this value entity, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_GetType(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_FunctionBus_TypeLevel inLevel,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Get the current value state, i.e. whether the value entity was measured or is offline
  // [IN] inStatusHandle: Handle of the status
  // [OUT] outState: Current state of the value entity
  // [RET] Always true
  extern boolean CANoeAPI_FunctionBus_Status_GetValueState(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_FunctionBus_ValueState* outState);

  // Retrieve the absolute time in nanoseconds when this value entity was last updated.
  // [IN] inStatusHandle: Handle of the status
  // [OUT] Time of last update, if update occurred
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_GetLastUpdateTimestamp(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_Time* outTime);

  // Retrieve the absolute time in nanoseconds when this value entity was last changed.
  // [IN] inStatusHandle: Handle of the status
  // [OUT] Time of last change, if change occurred
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_GetLastChangeTimestamp(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_Time* outTime);

  // Register an observer to be notified about value entity changes.
  // [IN] inPortHandle: Handle of the port
  // [IN] inCallbackFunction: Pointer to a callback method
  // [IN] inUpdateModeToObserve: Decide to observe only changes in value or any value updates
  // [IN] inUserData:  User data pointer, extra argument provided on callbacks
  // [OUT] outCallbackHandle: Handle to the callback, if successful; CANOEAPI_FUNCTIONBUS_CALLBACKHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_RegisterObserver(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    CANoeAPI_FunctionBus_StatusCallbackFunction inCallbackFunction,
    CANoeAPI_FunctionBus_UpdateMode inUpdateModeToObserve,
    const void* inUserData,
    CANoeAPI_FunctionBus_StatusCallbackHandle* outCallbackHandle);

  // Unregister a previously registered observer.
  // [IN] inPortHandle: Handle of the port
  // [IN] Handle from a previously registered observer callback 
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Status_UnregisterObserver(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle,
    const CANoeAPI_FunctionBus_StatusCallbackHandle inCallbackHandle);

  // Reset the status to a state similar to the one at measurement start:
  // Sets the value to the initial value (or zero); sets the value state to Offline; resets change / update counters and flags.
  // The new value is propagated to the CANoe clients, but the binding block doesn't transmit it.
  // [RET] True iff successful
  extern boolean CANoeAPI_FunctionBus_Status_ResetStatus(
    CANoeAPI_FunctionBus_StatusHandle inStatusHandle);

  // -------------------------------------------------------------------
  // CANoe FunctionBus: Type reflection and value access

  // Release the type, must be called for any obtained type to free resources after use.
  // [IN] inTypeHandle: Handle of the type to be released
  extern boolean CANoeAPI_FunctionBus_Type_Release(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle);

  // General type information

  // Retrieve the name of this type
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outBuffer: Pointer to the string buffer to be filled, 
  // [IN] inBufferLength: Size in bytes of the string buffer, not written to if buffer too small or in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetName(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    char* outBuffer,
    uint32 inBufferLength);

  // Retrieve the name of this type including the full FunctionBus path.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outBuffer: Pointer to the string buffer to be filled, not written to if buffer too small or in case of error
  // [IN] inBufferLength: Size in bytes of the string buffer
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetFullName(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    char* outBuffer,
    uint32 inBufferLength);

  // Determine this type's type tag.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outTypeTag: Type tag
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetTypeTag(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeTag* outTypeTag);

  // Simple types: Integer, Float, String

  // Retrieve the number of bits reserved for this type.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outCount: Number of bits, -1 in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetBitCount(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32* outCount);

  // Determine for an integer type if it is signed or unsigned.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outFlag: True iff this type is signed, left unchanged if this type is not an integer type
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_IsSigned(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    boolean* outFlag);

  // Determine the length of a string type.
  // This is equivalent to GetArrayMaxLength, because a string is internally defined as an array of uint8.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outLength: Number of 8 bit characters this string can hold, left unchanged if this type is not a string type
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetStringMaxLength(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32* outLength);

  // Determine the string encoding as Microsoft code page identifier used for display, e.g. 65001 for UTF-8.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outStringEncoding: Encoding enum value, value is not set in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetStringEncoding(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_StringEncoding* outStringEncoding);

  // Array type

  // Retrieve type of the members of this array type.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outType: Type of this particular member, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetArrayBaseType(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Retrieve maximum number of members specified for this array type.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outLength: Maximum number of members this array type can hold, -1 if number could not be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetArrayMaxLength(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32* outLength);

  // Retrieve minimum number of members specified for this array type.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outLength: Minimum number of members this array type must hold, or -1 if number could not be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetArrayMinLength(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32* outLength);

  // Determine if values of this array type have minimum and maximum length set to an equal value.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outFlag: Flag that is true iff arrays of this type are of static size, left unchanged if it cannot be determined
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_HasArrayFixedLength(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    boolean* outFlag);

  // Composite types: Struct, Union

  // Get member handle of this type (relative position within the value entity).
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outMemberHandle: Member handle of this type, CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberHandle(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle* outMemberHandle);

  // Obtain parent member of a previously obtained member handle. This type must be a composite type.
  // [IN] inTypeHandle: Handle of the type
  // [INOUT] inoutMemberHandle: Parent member of ingoing member (can be set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEWHOLE for root),
  //                    Value is set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetParentMember(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle* inoutMemberHandle);

  // Obtain a member handle relative to a previously obtained member handle, or relative to the root of this composite type.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inRelativePath: Relative FunctionBus path
  // [INOUT] inoutMemberHandle: Member relative to ingoing member, can be set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEWHOLE for root)
  //                    Value is set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMember(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    char* inRelativePath,
    CANoeAPI_FunctionBus_TypeMemberHandle* inoutMemberHandle);

  // Obtain a member handle relative to a previously obtained member handle, or relative to the root of this composite type.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inIndex: Index of n - th sub member of the member specified by the given member handle
  // [INOUT] inoutMemberHandle: Member relative to ingoing member, can be set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEWHOLE for root)
  //                    Value is set to CANOEAPI_FUNCTIONBUS_TYPEMEMBERHANDLEINVALID in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberByIndex(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32 inIndex,
    CANoeAPI_FunctionBus_TypeMemberHandle* inoutMemberHandle);

  // Retrieve type of a member of this composite type.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outTypeHandle: Type of this particular member, or an invalid handle in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberType(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_FunctionBus_TypeHandle* outTypeHandle);

  // Get number of directly specified members of this composite type.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outCount: Number of directly contained members
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberCount(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    uint32* outCount);

  // Composite types: Memory layout applied on raw and implementation type level

  // Determine if a member of this composite type is an optional member. Type must not have a fixed binary layout.
  // [IN] inTypeHandle: Handle of the type
  // [OUT] outFlag: Flag that is true iff layout is fixed, remains unset in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_HasFixedBinaryLayout(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    boolean* outFlag);

  // Determine padding of a member of this composite type relative to the preceding member. Binary layout must be fixed.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outOffset: Position relative to previous member, -1 in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberRelativeBitOffset(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint32* outOffset);

  // Determine position of a member of this composite type relative to this composite type. Binary layout must be fixed.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outOffset: Position relative to this composite type, -1 in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberAbsoluteBitOffset(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    uint32* outOffset);

  // For composite types with fixed binary layout: Determine whether a member's byte order is Big-Endian instead of Little-Endian
  // [IN] inTypeHandle: Handle of the type
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outByteOrder: Byte order of the member, remains unset in case of error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_GetMemberByteOrder(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    CANoeAPI_ByteOrder* outByteOrder);

  // Determine if a member of this composite type is an optional member.
  // [IN] inTypeHandle: Handle of the type
  // [IN] inMemberHandle: Handle to a member of this composite type
  // [OUT] outFlag: Flag that is true iff this member is optional, remains unset in case error
  // [RET] True iff successful, else false
  extern boolean CANoeAPI_FunctionBus_Type_IsMemberOptional(
    CANoeAPI_FunctionBus_TypeHandle inTypeHandle,
    CANoeAPI_FunctionBus_TypeMemberHandle inMemberHandle,
    boolean* outFlag);


  // ============================================================================
  // CANoe Runtime callbacks
  // ============================================================================

  // Callback function for a runtime callback handler, that is called as soon as returning to CANoe Runtime from CANoeEmu.
  // [IN] inUserData: Custom data provided when this callback was registered
  typedef void(*VRuntimeCallbackHandler)(void* userData);

  // Callback function for a delta handler, called after pending timers have been processed by CANoe Runtime.
  // [IN] inUserData: Custom data provided when this callback was registered
  // [RET] True iff CANoe should immediately check for pending timers that we have added, false otherwise.
  typedef boolean(*VRuntimeDeltaHandler)(void* userData);

  // Register a one-time callback that is called the next time we return to CANoe Runtime from CANoeEmu.
  // This is particularly useful to execute FunctionBus API that is not flagged as 
  // thread-safe from CANoeEmu's simulation context, or which is not queued to the action queue
  // because it is part of a complex transaction with data and control dependencies.
  // Example: BeginCall(&cco) -> ... -> SetInParams(cco, ...) -> ... -> InvokeCall(cco) -> Release(cco)
  // [IN] inCallbackHandler: The callback handler
  // [IN] inUserData: Custom user data
  extern void CANoeAPI_RequestRuntimeCallback(
    VRuntimeCallbackHandler inCallbackHandler,
    void* inUserData);

  // Register a one-time callback that is called after all pending timers of CANoe Runtime have been processed.
  // Use case example: When handling an event from CANoe Runtime, we would like to collect further pending events 
  // without proceeding in simulation time.
  // [IN] inDeltaHandler: The handler called immediately after the delta cycle
  // [IN] inUserData: Custom user data
  extern void CANoeAPI_RequestRuntimeDeltaCycle(
    VRuntimeDeltaHandler inDeltaHandler,
    void* inUserData);

// ============================================================================
// Obsolete:  Access to CANoe user timer (UserTimer)
//
// Legacy API for old code. 
// New code should use UserTimer2 API (see section below)
//
// Timers are identified by a timer index (uint8).
// ============================================================================

#define CANOEAPI_USERTIMER_INVALID         0xFF
#define CANOEAPI_USERTIMER_WRONGINDEX      0x01
#define CANOEAPI_USERTIMER_WRONGDURATION   0x02
#define CANOEAPI_USERTIMER_ALREADYEXPIRED  0x03
#define CANOEAPI_USERTIMER_SET             0x04


// Create a user timer with the given name. 
// The name of all user timers must be unique.
// If a user timer with the same name already exists, then no new timer is created but the 
// timer index of the existing user timer is returned. The function fails, if the existing timer
// was created with the API function CANoeAPI_UserTimer2_Create.
// If the given name has 255 or more characters, the function fails.
// The legacy UserTimer API is limited to 255 timers. If all timers are currently in use, then 
// the creation of a new timer fails.
// parameter name: The name of the new timer. The name must have less than 255 characters.
// return value:   Index of the created timer or CANOEAPI_USERTIMER_INVALID if function fails.
extern uint8 CANoeAPI_UserTimer_Create(const char* name);

// Search for a previously created user timer
// parameter name: The name of the timer that we are looking for.
// return value:   Index of the user timer with the given name or CANOEAPI_USERTIMER_INVALID if
//                 a timer with the given name does not exists or was created with the API 
//                 function CANoeAPI_UserTimer2_Create.
extern uint8 CANoeAPI_UserTimer_Find(const char* name);

// Destroy a User timer
// parameter index: Index of the timer, that should be destroyed.
extern void CANoeAPI_UserTimer_Destroy(uint8 index);

// Callback function for a user timer, that is called, when a timer expires.
// parameter index: Index of the expired timer
// parameter name:  The name of the expired timer.
typedef void (*VUserTimerHandler)(uint8 index, const char* name);

// Configure a callback function for a given timer. The function is called every time
// the timer expires.
// parameter index: Index of the timer, that is used for the alarm
// parameter f: The callback function
extern void CANoeAPI_UserTimer_SetCallbackFunction(uint8 index, VUserTimerHandler f);

// Set a one shot alarm giving a time span relative from now
// parameter index: Index of the timer, that is used for the alarm
// parameter microSeconds: duration of the timer in microseconds (must be greater than zero)
// return value: CANOEAPI_USERTIMER_WRONGINDEX       parameter index is invalid
//               CANOEAPI_USERTIMER_WRONGDURATION    parameter microSeconds is invalid
//               CANOEAPI_USERTIMER_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer_SetRelative(uint8 index, uint32 microSeconds);

// Set a cyclic alarm
// parameter index: Index of the timer, that is used for the alarm
// parameter microSeconds: duration of the timer in microseconds (must be greater than zero)
// return value: CANOEAPI_USERTIMER_WRONGINDEX       parameter index is invalid
//               CANOEAPI_USERTIMER_WRONGDURATION    parameter microSeconds is invalid
//               CANOEAPI_USERTIMER_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer_SetCyclic(uint8 index, uint32 microSeconds);

// Set a one shot alarm given by a time specification in nanoseconds since start of measurement.
// parameter index: Index of the timer, that is used for the alarm
// parameter nanoSeconds: absolute time in nanoseconds, when the timer should expire. The value 
//                        must be greater than the value of CANoeAPI_UserTimer_CurrentTime(). 
// return value: CANOEAPI_USERTIMER_WRONGINDEX       parameter index is invalid
//               CANOEAPI_USERTIMER_ALREADYEXPIRED   time specification is in the past
//               CANOEAPI_USERTIMER_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer_SetAbsolute(uint8 index, sint64 nanoSeconds);

// Stop a running timer.
// parameter index: Index of the timer, that should be stopped.
extern void CANoeAPI_UserTimer_Cancel(uint8 index);

// Get the time until the given timer expires
// parameter index: Index of the timer
// return value: time in microseconds until the timer expires or 0 if the
//               timer is not running.
extern uint32 CANoeAPI_UserTimer_GetRemaining(uint8 index);

// Get the current value of the clock that triggers all the user timers.
// return value: time in nanoseconds since start of measurement.
extern sint64 CANoeAPI_UserTimer_CurrentTime(void);


// ============================================================================
// Access to CANoe user timer (USERTIMER2)
//
// Timers are identified by a user timer handle (sint32).
// ============================================================================

#define CANOEAPI_USERTIMER2_INVALIDHANDLE     -1
#define CANOEAPI_USERTIMER2_WRONGHANDLE        1
#define CANOEAPI_USERTIMER2_WRONGDURATION      2
#define CANOEAPI_USERTIMER2_ALREADYEXPIRED     3
#define CANOEAPI_USERTIMER2_SET                4
#define CANOEAPI_USERTIMER2_CANCELED           5
#define CANOEAPI_USERTIMER2_TIMERNOTRUNNING    6

// Type for the handle of a user timer.
typedef sint32 CANoeAPI_UserTimer2_Handle;

// Time conversion macros for USERTIMER2 API.
// The following macros create a parameter of type sint64 with unit nanoseconds that could be use with the 
// USERTIMER2 API functions.
#define CANOEAPI_USERTIMER2_NANOSECONDS(x)    ((sint64)(x))
#define CANOEAPI_USERTIMER2_MICROSECONDS(x)   ((sint64)(x) * 1000)
#define CANOEAPI_USERTIMER2_MILLISECONDS(x)   ((sint64)(x) * 1000000)
#define CANOEAPI_USERTIMER2_SECONDS(x)        ((sint64)(x) * 1000000000)


// Create a user timer with the given name.
// The name of all user timers must be unique.
// If a user timer with the same name already exists, then no new timer is created but the 
// timer index of the existing user timer is returned. This can also be a timer, that was previously created 
// with the legacy API CANoeAPI_UserTimer_Create.
// If the given name has 255 or more characters, the function fails.
// parameter name: The name of the new timer. The name must have less than 255 characters.
// return value:   Handle of the created user timer (utHandle) or CANOEAPI_USERTIMER2_INVALIDHANDLE
//                 if the function fails.
extern CANoeAPI_UserTimer2_Handle CANoeAPI_UserTimer2_Create(const char* name);

// Search for a previously created user timer
// parameter name: The name of the timer that we are looking for.
// return value:   Handle of the user timer with the given name or CANOEAPI_USERTIMER2_INVALIDHANDLE if
//                 a timer with the given name does not exists.
extern CANoeAPI_UserTimer2_Handle CANoeAPI_UserTimer2_Find(const char* name);

// Destroy a User timer
// parameter utHandle: Handle of the timer, that should be destroyed.
extern void CANoeAPI_UserTimer2_Destroy(CANoeAPI_UserTimer2_Handle utHandle);

// Callback function for a user timer, that is called, when a timer expires.
// parameter userparam:  A user defined parameter. When registering the callback function, you can specify
//                       a value that is later given this callback function as first parameter.
// parameter name:       The name of the expired timer.
typedef void(*CANoeAPI_UserTimer2_Handler)(sint32 userparam, const char* name);

// Configure a callback function for a given timer. The function is called every time the timer expires.
// parameter utHandle:   Handle of the user timer, for which the callback should be set
// parameter f:          The callback function
// parameter userparam:  A user defined parameter. When registering the callback function, you can specify
//                       a value that is later given to the callback function as first parameter.
extern void CANoeAPI_UserTimer2_SetCallbackFunction(CANoeAPI_UserTimer2_Handle utHandle, 
                                                    CANoeAPI_UserTimer2_Handler f, 
                                                    sint32 userparam);

// Set a one shot alarm giving a time span relative from now
// parameter utHandle:     Handle of the user timer, that is used for the alarm
// parameter nanoSeconds:  duration of the timer in nanoSeconds (must be greater than zero)
// return value: CANOEAPI_USERTIMER2_WRONGHANDLE      parameter utHandle is invalid
//               CANOEAPI_USERTIMER2_WRONGDURATION    parameter nanoSeconds is invalid
//               CANOEAPI_USERTIMER2_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer2_SetRelative(CANoeAPI_UserTimer2_Handle utHandle, sint64 nanoSeconds);

// Set a cyclic alarm
// parameter utHandle:     Handle of the user timer, that is used for the alarm
// parameter nanoSeconds: duration of the timer in nanoSeconds (must be greater than zero)
// return value: CANOEAPI_USERTIMER2_WRONGHANDLE      parameter utHandle is invalid
//               CANOEAPI_USERTIMER2_WRONGDURATION    parameter nanoSeconds is invalid
//               CANOEAPI_USERTIMER2_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer2_SetCyclic(CANoeAPI_UserTimer2_Handle utHandle, sint64 nanoSeconds);

// Set a one shot alarm given by a time specification in nanoseconds since start of measurement.
// parameter utHandle:    Handle of of the user timer, that is used for the alarm
// parameter nanoSeconds: absolute time in nanoseconds, when the timer should expire. The value 
//                        must be greater than the value of CANoeAPI_UserTimer_CurrentTime(). 
// return value: CANOEAPI_USERTIMER2_WRONGHANDLE      parameter utHandle is invalid
//               CANOEAPI_USERTIMER2_ALREADYEXPIRED   time specification is in the past
//               CANOEAPI_USERTIMER2_SET              timer was successfully set
extern sint32 CANoeAPI_UserTimer2_SetAbsolute(CANoeAPI_UserTimer2_Handle utHandle, sint64 nanoSeconds);

// Stop a running timer.
// parameter utHandle: Handle of the user timer, that should be stopped.
// return value: CANOEAPI_USERTIMER2_WRONGHANDLE      parameter utHandle is invalid
//               CANOEAPI_USERTIMER2_TIMERNOTRUNNING  timer was not running, so cancel has no effect.
//               CANOEAPI_USERTIMER2_CANCELED         timer was successfully canceled
extern sint32 CANoeAPI_UserTimer2_Cancel(CANoeAPI_UserTimer2_Handle utHandle);

// Get the time until the given timer expires
// parameter utHandle:  Handle of of the user timer.
// return value:        Time in nanoseconds until the timer expires.
//                      If the timer is not running, the function returns 0.
//                      If parameter utHandle is invalid, the function returns 0.
extern sint64 CANoeAPI_UserTimer2_GetRemaining(CANoeAPI_UserTimer2_Handle utHandle);

// Get the current value of the clock that triggers all the user timers.
// return value: time in nanoseconds since start of measurement.
extern sint64 CANoeAPI_UserTimer2_CurrentTime(void);


// ============================================================================
// Access to NVRAM
//
// The NVRAM file is named "<nameofecuinstance>.nvram" if the name has been 
// set before with CANoeAPI_SetNameOfEcuInstance (see below). if not, the
// NVRAM file is named "<dllname>.nvram".
// ============================================================================

// opens or creates the NVRAM file with the given totalSize. if the file already
// exists its former file size is returned in existingSize.
//
// on success, the start address of the NVRAM is returned. NULL otherwise.
extern void* CANoeAPI_OpenNvRam(uint32 totalSize, uint32* existingSize);

// closes a previously opened NVRAM file
extern void CANoeAPI_CloseNvRam(void);

// opens or creates a named NVRAM file with the given totalSize and ID. if the
// file already exists its former file size is returned in existingSize.
// The NVRAM file is named "<nameofecuinstance>.<id>.nvram"
//
// on success, the start address of the NVRAM is returned. NULL otherwise.
extern void* CANoeAPI_OpenNvRamInstance(const char* id, uint32 totalSize, uint32* existingSize);

// closes a previously opened NVRAM file with the given ID.
extern void CANoeAPI_CloseNvRamInstance(const char* id);

// ============================================================================
// ECU state change handler
//
// Application can register a handler, that is called, when the global state 
// of the emulation changes. 
// See the state diagram in 'Enterprise Architect' for details of the state 
// machine.
// ============================================================================

#define CANOEAPI_ECUSTATE_INITIAL            0
#define CANOEAPI_ECUSTATE_NOMEASUREMENT      1
#define CANOEAPI_ECUSTATE_PRESTART           2
#define CANOEAPI_ECUSTATE_POWEROFF           3
#define CANOEAPI_ECUSTATE_PROCESSING         4
#define CANOEAPI_ECUSTATE_SLEEPING           5
#define CANOEAPI_ECUSTATE_FINAL              6

#define CANOEAPI_ECUACTION_NOACTION          0
#define CANOEAPI_ECUACTION_LOAD              1
#define CANOEAPI_ECUACTION_UNLOAD            2
#define CANOEAPI_ECUACTION_INITMEASUREMENT   3
#define CANOEAPI_ECUACTION_STARTMEASUREMENT  4
#define CANOEAPI_ECUACTION_STOPMEASUREMENT   5
#define CANOEAPI_ECUACTION_SWITCHON          6
#define CANOEAPI_ECUACTION_SWITCHOFF         7
#define CANOEAPI_ECUACTION_GOTOSLEEP         8
#define CANOEAPI_ECUACTION_WAKEUP            9
#define CANOEAPI_ECUACTION_RESET            10

// change of top level state of ECU emulation
//   oldState and newState see defines CANOEAPI_ECUSTATE_xxx
//   action see defines CANOEAPI_ECUACTION_xxx
typedef void (*VEcuStateHandler)( uint8 action, uint8 oldState, uint8 newState);


// Set callback function for the state changing actions of the emulation
// This function should only be called inside function CANoeAPI_InitHook.
extern void CANoeAPI_SetEcuStateHandler( VEcuStateHandler handler );

// ============================================================================
// Init hook of CANoeEmu
// 
// The function CANoeAPI_InitHook must be implemented by the application which 
// is  using the CANoe emulation Library. It is the central initialization hook
// of the emulation.
// Inside the init hook, the init functions (see section below) can be used 
// to configure several topics of the emulation.
// After processing the init hook, the ECU state change handler is called
// with action CANOEAPI_ECUACTION_LOAD.
// ============================================================================
extern void CANoeAPI_InitHook(void);


// ============================================================================
// Init functions of CANoeEmu
// The following functions should be called in the CANoeAPI_InitHook()
// function
// ============================================================================

// Set the name of the emulated ECU.
// This should be the AUTOSAR ShortName of the ECUInstance.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook() 
// Parameters
//   name: name of ECU.
extern void CANoeAPI_SetNameOfEcuInstance(char* name);

// Name of the Write-Windows Tab inside CANoe, that is used for Write-messages.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook() 
// Parameters
//   name: name of the Write-Windows Tab.
extern void CANoeAPI_SetNameOfWriteTab(char* name);

// Root namespace that is used for system variables. All system variables,
// That are created or accessed by the emulation are located below of this root.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook() 
// Parameters
//   name: name of the rote namespace.
extern void CANoeAPI_SetRootNameSpaceOfSystemVariables(char* name);

// Pointer to the main function, that is executed after a reset of the emulated
// processor.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// Parameters
//   main: pointer to the function, that should be executed.
extern void CANoeAPI_SetMainFunction( void (*main)(void) );

// Configure interrupt controller
// Set amount of interrupt numbers that the controller can handle and
// also set the number of execution levels for the interrupts.
// You must configure at least one interrupt and one interrupt level
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook() 
// Parameters
//   numberOfInterrupts:  number of interrupts, range 1 - 10000
//   numberOfLevels:      number of interrupt levels, range 1 - 200
extern void CANoeAPI_ConfigureInterruptController(sint32 numberOfInterrupts, sint32 numberOfLevels);

// Configure non-maskable interrupt levels of the interrupt controller
// Set the amount of interrupt levels, that are 'non-maskable'. The non-maskable interrupt levels are
// always the interrupt levels with the highest priority of the virtual processor.
// Restrictions: The virtual processor does not need any non-maskable interrupt level, but it needs at
// least one maskable interrupt level.
// Example: You have a processor with 5 interrupt levels and two of them are configured non-maskable,
// then the interrupts on levels 1, 2 and 3 are maskable interrupts, whereas the interrupts on 
// levels 4 and 5 are non-maskable interrupts (NMI).
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// Parameters
//   numberOfNonMaskableLevels:  number of interrupt levels used for non-maskable interrupts (NMI),
//                               range 0 - number of interrupt levels - 1.
extern void CANoeAPI_ConfigureNumberOfNonMaskableInterruptLevels(sint32 numberOfNonMaskableLevels);

// Configure the number of processing cores of the virtual ECU
// Parameters
//   numberOfCores:  number of processor cores, that the virtual  ECU has, range 1 - 32
extern void CANoeAPI_ConfigureNumberOfCores(sint32 numberOfCores);

// Configure the number of 'System Timer' of the virtual ECU.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// Parameters
//   numberOfSystemTimers:  number of system timers, that the virtual  ECU has, 
//                          range 0 - 1
extern void CANoeAPI_ConfigureNumberOfSystemTimers(sint32 numberOfSystemTimers);

// Configure the number of 'High Resolution Timer' of the virtual ECU.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// Parameters
//   numberOfHRTimers:  number of high resolution timers, that the virtual  ECU has, 
//                      range 0 - 256
extern void CANoeAPI_ConfigureNumberOfHRTimers(sint32 numberOfHRTimers);

// Connect a channel for a bus system to a bus inside CANoe.
// MAY ONLY BE CALLED IN: InitHook() or the Load action of the VEcuStateHandler. The function must be called befor
// the function CANoeAPI_FreezeChannelMapping is called, otherwise the function has no effect.
// Parameters
//   name: name of the bus inside simulation setup of CANoe 
//   bustype: CANOEAPI_BUSTYPE_CAN , CANOEAPI_BUSTYPE_LIN, CANOEAPI_BUSTYPE_FLEXRAY 
//            or CANOEAPI_BUSTYPE_ETHERNET
//   channel: channel index of the emulated driver (This is not the CANoe application 
//            channel number)
extern void CANoeAPI_MapChannel(const char* name, sint32 bustype, uint8 channel);

// Query whether a channel was successfully mapped or not
// Parameters
//   bustype: CANOEAPI_BUSTYPE_CAN , CANOEAPI_BUSTYPE_LIN, CANOEAPI_BUSTYPE_FLEXRAY 
//            or CANOEAPI_BUSTYPE_ETHERNET
//   channel: channel index of the emulated driver (This is not the CANoe application 
//            channel number)
// Returns non-zero if the channel was mapped successfully, zero otherwise
extern boolean CANoeAPI_IsChannelMapped(sint32 bustype, uint8 channel);

// Freeze the channel mapping configuration. After calling the function CANoeAPI_FreezeChannelMapping further
// calls to the function CANoeAPI_MapChannel have no effects.
// MAY ONLY BE CALLED IN: InitHook() or the Load action of the VEcuStateHandler
extern void CANoeAPI_FreezeChannelMapping(void);

// Query whether the function CANoeAPI_FreezeChannelMapping was called or not.
// Returns a non-zero value if the function CANoeAPI_FreezeChannelMapping was called, zero otherwise.
boolean CANoeAPI_IsChannelMappingFrozen(void);

// Configure the execution mode of the Emulation. The mode determines, how interrupt routines 
// and task are executed. There are three modes available.
// * PREEMPTIVE_MULTITHREAD
//   Every interrupt level and every task uses an own thread from the windows operating system.
//   The remaining bus simulation in CANoe is running in parallel to this threads. Events from 
//   the remaining bus simulation can cause an interrupt in the emulation, that preempts running tasks 
//   or interrupts.
// * NONPREEMPTIVE_SINGLETHREAD
//   Every interrupt level and every task uses a fiber from the windows operating system. 
//   Every fiber is running on the thread, that is running the remaining bus simulation in CANoe.
//   In this mode, there is nearly no synchronization overhead. But because everything is executed in 
//   a single thread, we get no benefit from modern multi core CPUs.
// * NONPREEMPTIVE_WORKERTHREAD
//   Every interrupt level and every task uses a fiber from the windows operating system. Every fiber 
//   is running on a single worker thread. So we have one thread for the remaining bus simulation in CANoe 
//   and one worker thread for every simulated ECU, that uses this mode.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook()
// Parameters
//   mode:  the execution mode, one of the following values
//            CANOEAPI_EXECUTE_PREEMPTIVE_MULTITHREAD
//            CANOEAPI_EXECUTE_NONPREEMPTIVE_SINGLETHREAD
//            CANOEAPI_EXECUTE_NONPREEMPTIVE_WORKERTHREAD
void CANoeAPI_SetExecutionMode(uint8 mode);
#define CANOEAPI_EXECUTE_PREEMPTIVE_MULTITHREAD      1
#define CANOEAPI_EXECUTE_NONPREEMPTIVE_SINGLETHREAD  2
#define CANOEAPI_EXECUTE_NONPREEMPTIVE_WORKERTHREAD  3

// Configure the initial value for the simulated power supply.
// MAY ONLY BE CALLED IN: CANoeAPI_InitHook() 
// Parameters
//  value:  0  power supply is switched off at start of the CANoe measurement.
//          1  power supply is switched on  at start of the CANoe measurement.
void CANoeAPI_SetInitValueOfPowerSupply(uint8 value);

// ============================================================================
// Manipulate ECU state from a emulated hardware unit
// Emulated hardware units (like  a CAN Controller) can change the state of
// the simulated processor. 
// Examples:  - Set an interrupt
//            - Wakeup processor from sleep mode
//            - Reset processor
// ============================================================================

// Wakeup the emulated processor from sleep mode
extern void CANoeAPI_WakeupProcessor(void);

// Reset the emulated processor. Emulated processor could be in processing mode 
// or in sleep mode.
extern void CANoeAPI_ResetProcessor(void);

// Reinitialize a (initialized or uninitialized) data section on processor
// reset. The default sections '.bss' or '.data' cannot be reinitialized.
// The function has to be called in the CANOEAPI_ECUACTION_LOAD phase.
// Section names longer than 7 characters are not supported (yet).
// Returns TRUE if the data section can be reinitialized.
// In case of a failure, the function returns FALSE.
extern boolean CANoeAPI_ReInitializeSectionOnReset(const char* sectionName);

// Set the interrupt with the given number. The interrupt router is used to
// deliver the interrupt request to a specific processor core.
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
extern void CANoeAPI_SetInterrupt(sint32 irqNumber);

// Manipulate the task scheduler of the CANoeEmu from within an event handler.
// This function is used in the VTT .pro use case when the AUTOSAR OS is not emulated but
// a simplified scheduler from the VTT .pro runtime is used.
// parameter coreNumber: number of the processor core, that should be manipulated
// parameter taskNr: The task, that should be executed on the specified processing core or
//   CANOEEMUPROCESSOR_IDLE if no task should be executed.
// Note: This function doesn't consume any ticks, because we don't have any activity context
// when running an event handler. Currently only activities are allowed to consume execution time
// and possibly block the execution.
extern void CANoeAPI_SetTaskToRun(sint32 coreNumber, sint32 taskNr);

// ============================================================================
// Timing behavior of the emulation
// ============================================================================

// Consume resources (processing time) as part of the code execution model.
// Parameters:
//  ticks:   processing time be consumed, unit ticks
// Note:
//  The duration of a tick is configured with the function CANoeAPI_ConfigureTiming
extern void CANoeAPI_ConsumeTicks(sint32 ticks);

// Consume resources as part of the code execution model.
// Parameters:
//  nanoseconds:  processing time be consumed, unit nanoseconds
extern void CANoeAPI_ConsumeTime(sint64 nanoseconds);


// The struct CANoeAPI_TimeInfo for the function CANoeAPI_GetTimeInfo contains the
// values of the internal time counters of the emulation.
typedef struct sCANoeAPI_TimeInfo
{
  sint64 syncTime;   //  Remaining time till synchronization with CANoe, unit nanoseconds
  sint64 userTimer;  //  Remaining time till next CANoeAPI_UserTimer expires, unit nanoseconds
  sint64 clock;      //  Clock of virtual ECU, unit nanoseconds
} CANoeAPI_TimeInfo;

// Retrieve the values of the internal time counters of the emulation.
// Parameters
//   TimeInfo: output parameter, a pointer to struct CANoeAPI_TimeInfo, where
//             the values of of the internal time counters are stored.
extern void CANoeAPI_GetTimeInfo(CANoeAPI_TimeInfo* timeInfo);

// Configure several timing values of the emulation
// Parameters:
//   timing:  select the timing parameter, that should be configured
//   value:   the value to which the timing parameter should be set
//  The following Timing parameters are available:
//    CANOEAPI_TIMING_TICKDURATION 
//      Configure the duration in nanoseconds of a single 'Tick'.
//      The unit Tick is used by function CANoeAPI_ConsumeTicks and some of the 
//      timing parameters of this function.
//    CANOEAPI_TIMING_PREISR
//      Processing time in ticks, that is consumed every time an interrupt service routine (ISR)
//      starts execution.
//    CANOEAPI_TIMING_POSTISR
//      Processing time in ticks, that is consumed every time an interrupt service routine (ISR)
//      ends execution.
//    CANOEAPI_TIMING_PRETASK
//      Processing time in ticks, that is consumed every time a task starts execution.
//    CANOEAPI_TIMING_TASKSWITCH
//      Processing time in ticks, that is consumed when execution of tasks should switch to another task.
//      In more details, the processing time is consumed every time the function CANoeEmuProcessor_SetTaskToRun
//      or CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts is called.
//    CANOEAPI_TIMING_SYNCTIME
//      Configure the time span in nanoseconds between two synchronization points between CANoe and CANoeEmu.
#define CANOEAPI_TIMING_TICKDURATION           1
#define CANOEAPI_TIMING_PREISR                 2
#define CANOEAPI_TIMING_POSTISR                3
#define CANOEAPI_TIMING_PRETASK                4
#define CANOEAPI_TIMING_TASKSWITCH             5
#define CANOEAPI_TIMING_SYNCTIME               6
extern void CANoeAPI_ConfigureTiming(sint32 timing, sint64 value);

// ============================================================================
// Set AUTOSAR DET messages
// 
// For textual output in Det error reporting the names for modules, module 
// instances, api services and errors can be configured in the CANoe Emu library.
// 
// Names for API services and errors can be configured in the context of a 
// module without the context of a module instance (CANoeAPI_DetSetFunction, 
// CANoeAPI_DetSetError) but also with the context of (CANoeAPI_DetSetFunction2, 
// CANoeAPI_DetSetError2). When the function CANoeAPI_DetReportError is used to 
// report an error, then names with a context of a module instance are preferred
// to the names without a context of a module instance.
// ============================================================================

// Configure the name of a module.
// Parameters:
//   moduleId:    Module ID of the module
//   name:        The name of the module
extern void CANoeAPI_DetSetModule(uint16 moduleId, const char* name);

// Configure the name of a module instance
// Parameters:
//   moduleId:    Module ID of the module
//   instanceId:  Identifier of the module instance
//   name:        The name of the module instance
extern void CANoeAPI_DetSetInstance(uint16 moduleId, uint8 instanceId, const char* name);

// Configure the API service name of a module without the context of a module instance.
// Parameters:
//   moduleId:    Module ID of the module
//   apiId:       ID of the API service
//   name:        The name of the API service
extern void CANoeAPI_DetSetFunction(uint16 moduleId, uint8 apiId, const char* name);

// Configure the API service name of a module in the context of a module instance.
// Parameters:
//   moduleId:    Module ID of the module
//   instanceId:  Identifier of the module instance
//   apiId:       ID of the API service
//   name:        The name of the API service
extern void CANoeAPI_DetSetFunction2(uint16 moduleId, uint8 instanceId, uint8 apiID, const char* name);

// Configure the name of an error without the context of a module instance.
// Parameters:
//   moduleId:    Module ID of the module
//   errorId:     ID of the API service
//   name:        The name of the error
extern void CANoeAPI_DetSetError(uint16 moduleId, uint8 errorId, const char* name);

// Configure the name of an error in the context of a module instance.
//   moduleId:    Module ID of the module
//   instanceId:  Identifier of the module instance
//   errorId:     ID of the API service
//   name:        The name of the error
extern void CANoeAPI_DetSetError2(uint16 moduleId, uint8 instanceId, uint8 errorId, const char* name);


// Output an error message from the 'Default Error Trace' (Det) to the write window of CANoe. If 
// possible, the previously configured names are used in the error message.
// Parameters:
//   moduleId:    Module ID of the module, that calls the error reporting functionality
//   instanceId:  Identifier of the module instance
//   apiId:       ID of the API service, in which the error was detected
//   errorId:     ID of the detected development error.
// return value:
//   The return value indicates, if there are configured names available for the parameters moduleId,
//   apiId and errorId. The instanceID has no influence on the return value.
//   CANOEAPI_DETREPORT_OK              The name for the module, the name for the API service and 
//                                      the name for the error was configured.
//   CANOEAPI_DETREPORT_ERRORUNKNOWN    One or more of the names for module, API service or error
//                                      was not configured.
#define CANOEAPI_DETREPORT_OK            0
#define CANOEAPI_DETREPORT_ERRORUNKNOWN -1
extern sint32 CANoeAPI_DetReportError(uint16 moduleId, uint8 instanceId, uint8 apiId, uint8 errorId);


// ============================================================================
// Debugging Support
// 
// In a debugging session, you can use the following functions to get detailed
// information about the state of the virtual ECU. 
// 
// Example: You are debugging the SUT.dll. Set a break point in one of your 
// Task and wait, until you reach the break point and execution is stopped.
// Then go the the 'Immediate Window' of the Visual Studio Debugger and call:
//    SUT.dll!CANoeAPI_DumpInterruptController()
// This should dump the complete state of the virtual interrupt controller.
// ============================================================================

// Dump the state of the virtual interrupt controller to the output window of 
// the debugger.
// This function should only be called from the debugger and when the execution 
// was stopped.
extern void CANoeAPI_DumpInterruptController(void);

// Dump the state of the virtual interrupt router to the output window of 
// the debugger.
// This function should only be called from the debugger and when the execution 
// was stopped.
extern void CANoeAPI_DumpInterruptRouter(void);

// Dump the state of the high resolution timer to the output window of 
// the debugger.
// This function should only be called from the debugger and when the execution 
// was stopped.
extern void CANoeAPI_DumpHighResolutionTimer(void);

// Dump the state of the system timer to the output window of the debugger.
// This function should only be called from the debugger and when the execution 
// was stopped.
extern void CANoeAPI_DumpSystemTimer(void);

// Dump the state of the virtual processor to the output window of the debugger.
// This function should only be called from the debugger and when the execution 
// was stopped.
extern void CANoeAPI_DumpProcessor(void);

// Dump the addresses of the used NvRAM instances
// This function should only be called from the debugger and when the execution 
// was stopped.
void CANoeAPI_DumpNvRam(void);


#ifdef __cplusplus
};
#endif

#endif // __CANOEAPI_H
