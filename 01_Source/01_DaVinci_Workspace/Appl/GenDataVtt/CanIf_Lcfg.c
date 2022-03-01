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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
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

#define CANIF_LCFG_SOURCE

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0779 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 1330, 1334 EOF */ /* MD_CanIf_16.4, MD_CanIf_16.4 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

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
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {
    /* Index    MappedTxBuffersConfigEndIdx                                                 MappedTxBuffersConfigStartIdx                                                       Referable Keys */
  { /*     0 */                         1UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,                           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */ }   /* [/ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {
    /* Index    CtrlStatesIdx                                                 PduIdFirst                           PduIdLast                           TxBufferCfgIdx                                                                                        TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,         0U  /* Unused, TxPduId 0 */,        0U  /* Unused, TxPduId 7 */,                                    0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx] */
  { /*     1 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,         0U  /* RxPduId */          ,        9U  /* RxPduId  */         , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                          , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Rx_Std] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {
    /* Index    MailBoxConfigIdx                                                                 Referable Keys */
  { /*     0 */              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */ }   /* [/ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4] = {
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                            Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [CanTp_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[10] = {
    /* Index    RxPduCanId                                                                    RxPduMask                                                    UpperPduId                                                       Dlc  RxIndicationFctListIdx                                      Comment                                                                     Referable Keys */
  { /*     0 */    0x0705U  /* DiagReq_FUNC_Can2Tp_1797R, 2.0- or FD-PDU */                 ,   0x47FFU  /* DiagReq_FUNC_Can2Tp_1797R */                 , CanTpConf_CanTpRxNPdu_DiagReq_Func_Can2TpNpdu_2047R            ,  8U,                    2UL  /* CanTp_RxIndication */     },  /* [PDU: DiagReq_FUNC_Can2Tp_1797R, CanId: 0x705]                  */  /* [CanIfConf_CanIfRxPduCfg_DiagReq_FUNC_Can2Tp_1797R] */
  { /*     1 */    0x0704U  /* DiagReq_Phy_Can2Tp_1796R, 2.0- or FD-PDU */                  ,   0x07FFU  /* DiagReq_Phy_Can2Tp_1796R */                  , CanTpConf_CanTpRxNPdu_DiagReq_PhyNpdu_Can2Tp_1796R             ,  8U,                    2UL  /* CanTp_RxIndication */     },  /* [PDU: DiagReq_Phy_Can2Tp_1796R, CanId: 0x704]                   */  /* [CanIfConf_CanIfRxPduCfg_DiagReq_Phy_Can2Tp_1796R] */
  { /*     2 */    0x0556U  /* SCU_DATA_RX, 2.0- or FD-PDU */                               ,   0x07FFU  /* SCU_DATA_RX */                               , PduRConf_PduRSrcPdu_PduRSrcPdu_1                               ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: SCU_DATA_RX, CanId: 0x556]                                */  /* [CanIfConf_CanIfRxPduCfg_SCU_DATA_RX] */
  { /*     3 */    0x0555U  /* RESERVED_ID3_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */           ,   0x07FFU  /* RESERVED_ID3_oCAN00_Rx_3abd61be */           , PduRConf_PduRSrcPdu_SRC_Can_PT_RESERVED_ID3_0fb271d2           ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: RESERVED_ID3_oCAN00_Rx_3abd61be, CanId: 0x555]            */  /* [CanIfConf_CanIfRxPduCfg_RESERVED_ID3_oCAN00_Rx_3abd61be] */
  { /*     4 */    0x0554U  /* MASTER_CTRL_INFORMATION_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */,   0x07FFU  /* MASTER_CTRL_INFORMATION_oCAN00_Rx_3abd61be */, PduRConf_PduRSrcPdu_SRC_Can_PT_MASTER_CTRL_INFORMATION_0fb271d2,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: MASTER_CTRL_INFORMATION_oCAN00_Rx_3abd61be, CanId: 0x554] */  /* [CanIfConf_CanIfRxPduCfg_MASTER_CTRL_INFORMATION_oCAN00_Rx_3abd61be] */
  { /*     5 */    0x0553U  /* RESERVED_ID2_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */           ,   0x07FFU  /* RESERVED_ID2_oCAN00_Rx_3abd61be */           , PduRConf_PduRSrcPdu_SRC_Can_PT_RESERVED_ID2_0fb271d2           ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: RESERVED_ID2_oCAN00_Rx_3abd61be, CanId: 0x553]            */  /* [CanIfConf_CanIfRxPduCfg_RESERVED_ID2_oCAN00_Rx_3abd61be] */
  { /*     6 */    0x0552U  /* MASTER_CTRL_LIMITATION_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */ ,   0x07FFU  /* MASTER_CTRL_LIMITATION_oCAN00_Rx_3abd61be */ , PduRConf_PduRSrcPdu_SRC_Can_PT_MASTER_CTRL_LIMITATION_0fb271d2 ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: MASTER_CTRL_LIMITATION_oCAN00_Rx_3abd61be, CanId: 0x552]  */  /* [CanIfConf_CanIfRxPduCfg_MASTER_CTRL_LIMITATION_oCAN00_Rx_3abd61be] */
  { /*     7 */    0x0551U  /* RESERVED_ID1_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */           ,   0x07FFU  /* RESERVED_ID1_oCAN00_Rx_3abd61be */           , PduRConf_PduRSrcPdu_SRC_Can_PT_RESERVED_ID1_0fb271d2           ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: RESERVED_ID1_oCAN00_Rx_3abd61be, CanId: 0x551]            */  /* [CanIfConf_CanIfRxPduCfg_RESERVED_ID1_oCAN00_Rx_3abd61be] */
  { /*     8 */    0x0550U  /* MASTER_CTRL_REQ_oCAN00_Rx_3abd61be, 2.0- or FD-PDU */        ,   0x07FFU  /* MASTER_CTRL_REQ_oCAN00_Rx_3abd61be */        , PduRConf_PduRSrcPdu_SRC_Can_PT_MASTER_CTRL_REQ_0fb271d2        ,  8U,                    3UL  /* PduR_CanIfRxIndication */ },  /* [PDU: MASTER_CTRL_REQ_oCAN00_Rx_3abd61be, CanId: 0x550]         */  /* [CanIfConf_CanIfRxPduCfg_MASTER_CTRL_REQ_oCAN00_Rx_3abd61be] */
  { /*     9 */    0x01F1U  /* MASTER_Nm, 2.0- or FD-PDU */                                 ,   0x07FFU  /* MASTER_Nm */                                 , CanNmConf_CanNmRxPdu_CanNmRxPdu                                ,  8U,                    1UL  /* CanNm_RxIndication */     }   /* [PDU: MASTER_Nm, CanId: 0x1f1]                                  */  /* [CanIfConf_CanIfRxPduCfg_MASTER_Nm] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {
    /* Index    TxBufferPrioByCanIdBaseIdx                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                                      Referable Keys */
  { /*     0 */                        0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2 */,                                            8UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2 */,                                            8UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2 */,                                              0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[8] = {
    /* Index    TxPduConfigIdx                                                                                       Referable Keys */
  { /*     0 */            0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/TXDiagValeo_Tp2CanResp_D_1860T */           },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     1 */            1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_TX */                              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     2 */            2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/RESERVED_ID5_oCAN00_Tx_3abd61be */          },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     3 */            3UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be */        },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     4 */            4UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_DIAG_oCAN00_Tx_3abd61be */         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     5 */            5UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     6 */            6UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_STATUS_oCAN00_Tx_3abd61be */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
  { /*     7 */            7UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_NM_oCAN00_Tx_3abd61be */                }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[3] = {
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[8] = {
    /* Index    CanId    UpperLayerTxPduId                                               CtrlStatesIdx                                                 Dlc  MailBoxConfigIdx                                                           TxConfirmationFctListIdx                                    Comment                                                     Referable Keys */
  { /*     0 */ 0x0744U, CanTpConf_CanTpTxFcNPdu_TXDiagValeoNpdu_1860T                 ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      2UL  /* CanTp_TxConfirmation */ },  /* [PDU: TXDiagValeo_Tp2CanResp_D_1860T]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/TXDiagValeo_Tp2CanResp_D_1860T] */
  { /*     1 */ 0x0655U, PduRConf_PduRDestPdu_PduRDestPdu                              ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: SCU_DATA_TX]                              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_TX] */
  { /*     2 */ 0x0654U, PduRConf_PduRDestPdu_DST_Can_PT_RESERVED_ID5_0fb271d2         ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: RESERVED_ID5_oCAN00_Tx_3abd61be]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RESERVED_ID5_oCAN00_Tx_3abd61be] */
  { /*     3 */ 0x0653U, PduRConf_PduRDestPdu_DST_Can_PT_SCU_MOTOR_DIAG_0fb271d2       ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be] */
  { /*     4 */ 0x0652U, PduRConf_PduRDestPdu_DST_Can_PT_SCU_DATA_DIAG_0fb271d2        ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: SCU_DATA_DIAG_oCAN00_Tx_3abd61be]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_DIAG_oCAN00_Tx_3abd61be] */
  { /*     5 */ 0x0651U, PduRConf_PduRDestPdu_DST_Can_PT_SCU_DATA_AVAILABILITY_0fb271d2,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be] */
  { /*     6 */ 0x0650U, PduRConf_PduRDestPdu_DST_Can_PT_SCU_DATA_STATUS_0fb271d2      ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      0UL  /* NULL_PTR */             },  /* [PDU: SCU_DATA_STATUS_oCAN00_Tx_3abd61be]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_STATUS_oCAN00_Tx_3abd61be] */
  { /*     7 */ 0x01F2U, CanNmConf_CanNmTxPdu_CanNmTxPdu                               ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08 */,  8U,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_7c865b08_Tx */,                      1UL  /* CanNm_TxConfirmation */ }   /* [PDU: SCU_NM_oCAN00_Tx_3abd61be]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_NM_oCAN00_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[8] = {
    /* Index    TxQueueIdx                                                                                       Comment                                                                               Referable Keys */
  { /*     0 */        0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/TXDiagValeo_Tp2CanResp_D_1860T */           },  /* [TXDiagValeo_Tp2CanResp_D_1860T, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/TXDiagValeo_Tp2CanResp_D_1860T, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     1 */        1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_TX */                              },  /* [SCU_DATA_TX, BasicCAN TxPdu with Tx-buffer]                              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_TX, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     2 */        2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/RESERVED_ID5_oCAN00_Tx_3abd61be */          },  /* [RESERVED_ID5_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RESERVED_ID5_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     3 */        3UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be */        },  /* [SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]        */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     4 */        4UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_DIAG_oCAN00_Tx_3abd61be */         },  /* [SCU_DATA_DIAG_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_DIAG_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     5 */        5UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be */ },  /* [SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     6 */        6UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_STATUS_oCAN00_Tx_3abd61be */       },  /* [SCU_DATA_STATUS_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_STATUS_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
  { /*     7 */        7UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/SCU_NM_oCAN00_Tx_3abd61be */                }   /* [SCU_NM_oCAN00_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_NM_oCAN00_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN00_7c865b08] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_0fb271d2] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/TXDiagValeo_Tp2CanResp_D_1860T] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_TX] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RESERVED_ID5_oCAN00_Tx_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_MOTOR_DIAG_oCAN00_Tx_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_DIAG_oCAN00_Tx_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_AVAILABILITY_oCAN00_Tx_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_DATA_STATUS_oCAN00_Tx_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SCU_NM_oCAN00_Tx_3abd61be] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



