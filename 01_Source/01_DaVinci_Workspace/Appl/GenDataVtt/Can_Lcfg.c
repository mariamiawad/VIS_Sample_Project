/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2019-11-13 15:54:54
 *           Project: Bootcamp - Version 1.0
 *          Delivery: CBD1500710_D05
 *      Tool Version: DaVinci Configurator (beta) 5.16.27
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#define CAN_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_Can_0857 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */
/* HW specific CT global C file */

/* PRQA S 0612 EOF */ /* Can_gCanController variable exceed 32kByte of space, but is OK for CANoeEmulation/VTT */

/* !HW specific CT global C file */


/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1] = {
  /* Index    CanIfChannelId      Comment */
  /*     0 */             0U   /* [CT_CAN00_7c865b08] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                         Description
  CanControllerDefaultBaudrate
  MailboxRxBasicEndIdx            the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength            the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx          the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx            the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength            the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx          the start index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedEndIdx             the end index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedLength             the number of relations pointing to Can_Mailbox
  MailboxUnusedStartIdx           the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart              
  RxBasicHwStop               
  RxFullHwStart               
  RxFullHwStop                
  TxBasicHwStart              
  TxBasicHwStop               
  TxFullHwStart               
  TxFullHwStop                
  UnusedHwStart               
  UnusedHwStop                
  BusName                         controller to hardware mapping
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1] = {
    /* Index    CanControllerDefaultBaudrate  MailboxRxBasicEndIdx                                                                                                                                     MailboxRxBasicLength                                                                                                                                     MailboxRxBasicStartIdx                                                                                                                                     MailboxTxBasicEndIdx                                                                                                                                     MailboxTxBasicLength                                                                                                                                     MailboxTxBasicStartIdx                                                                                                                                     MailboxUnusedEndIdx                                                                                                                                    MailboxUnusedLength                                                                                                                                    MailboxUnusedStartIdx                                                                                                                                    RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop  BusName                                             Comment                         Referable Keys */
  { /*     0 */                         500U,                   2U  /* RX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                   1U  /* RX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                     1U  /* RX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                   1U  /* TX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                   1U  /* TX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                     0U  /* TX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                  3U  /* UNUSED_CAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                  1U  /* UNUSED_CAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,                    2U  /* UNUSED_CAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController) */,             1U,            3U,            1U,           1U,             0U,            1U,            0U,           0U,            3U,         250U, {67,65,78,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} }   /* [CT_CAN00_7c865b08] */  /* [/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Filter
**********************************************************************************************************************/
/** 
  \var    Can_Filter
  \brief  filter configuration
  \details
  Element       Description
  Code      
  Mask      
  BCanHwIdx 
  BCanHwSize
  BCanLogIdx
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_FilterType, CAN_CONST) Can_Filter[1] = {
    /* Index    Code          Mask          BCanHwIdx  BCanHwSize  BCanLogIdx        Comment */
  { /*     0 */ 0x00000000UL, 0x80000000UL,        1U,         2U,         0U }   /* [CT_CAN00_7c865b08 - CN_CAN00_7c865b08_Rx_Std - CanFilterMask] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_FilterStartIdx
**********************************************************************************************************************/
/** 
  \var    Can_FilterStartIdx
  \brief  Start index for filters (Controller - BasicCAN - indexed)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_FilterStartIdxType, CAN_CONST) Can_FilterStartIdx[2] = {
  /* Index    FilterStartIdx      Comment */
  /*     0 */             0U,  /* [CT_CAN00_7c865b08] */
  /*     1 */             1U   /* [Stop Index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObject
**********************************************************************************************************************/
/** 
  \var    Can_InitObject
  \brief  baudrate settings
  \details
  Element        Description
  arbBaudrate
  dbrBaudrate
  arbSam     
  arbSjw     
  arbTseg1   
  arbTseg2   
  dbrSam     
  dbrSjw     
  dbrTseg1   
  dbrTseg2   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectType, CAN_CONST) Can_InitObject[1] = {
    /* Index    arbBaudrate  dbrBaudrate  arbSam  arbSjw  arbTseg1  arbTseg2  dbrSam  dbrSjw  dbrTseg1  dbrTseg2        Comment */
  { /*     0 */    500000UL,         0UL,     0U,     1U,      11U,       4U,     0U,     0U,       0U,       0U }   /* [CT_CAN00_7c865b08 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1] = {
  /* Index    InitObjectBaudrate      Comment */
  /*     0 */               500U   /* [CT_CAN00_7c865b08 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2] = {
  /* Index    InitObjectStartIndex      Comment */
  /*     0 */                   0U,  /* [CT_CAN00_7c865b08] */
  /*     1 */                   1U   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  IDValue            
  DLC_FIFO           
  HwHandle           
  MailboxType        
  MaxDataLen         
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[3] = {
    /* Index    ControllerConfigIdx                                                           IDValue  DLC_FIFO  HwHandle  MailboxType                                MaxDataLen        Comment                                Referable Keys */
  { /*     0 */                  0U  /* /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 */, 0x0000U,       1U,       0U, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U },  /* [CN_CAN00_7c865b08_Tx]     */  /* [/ActiveEcuC/VTTCan/CanConfigSet/CN_CAN00_7c865b08_Tx (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanHardwareObject), /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08, TX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController)] */
  { /*     1 */                  0U  /* /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 */, 0x0000U,       2U,       1U, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8U },  /* [CN_CAN00_7c865b08_Rx_Std] */  /* [/ActiveEcuC/VTTCan/CanConfigSet/CN_CAN00_7c865b08_Rx_Std (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanHardwareObject), /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08, RX_BASICCAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController)] */
  { /*     2 */                  0U  /* /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 */, 0x0000U,     247U,       3U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U }   /* []                         */  /* [undefined, /ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08, UNUSED_CAN_TYPE/ActiveEcuC/VTTCan/CanConfigSet/CT_CAN00_7c865b08 (DefRef: /MICROSAR/VTT/VTTCan/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxOffsetHwToLog
**********************************************************************************************************************/
/** 
  \var    Can_TxOffsetHwToLog
  \brief  tx hardware to logical handle indirection table
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_TxOffsetHwToLogType, CAN_CONST) Can_TxOffsetHwToLog[1] = {
  /* Index    TxOffsetHwToLog      Comment */
  /*     0 */               0   /* [CT_CAN00_7c865b08] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  Pdu        buffered PduId for confirmation or cancellation
  State      send state like cancelled or send activ
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[2];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                  Description
  CanInterruptCounter      CAN interrupt disable counter for each controller
  IsBusOff                 CAN state for each controller: busoff occur
  LastInitObject           last set baudrate for reinit
  LogStatus                CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  StatusReq                CAN state request for each controller: START=0x01, STOP=0x02, WAKEUP=0x08, SLEEP=0x80
  CanInterruptOldStatus    last CAN interrupt status for restore interrupt for each controller
  RxMsg                    received data buffer
  gCanController           emulated hardware layout and status
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




