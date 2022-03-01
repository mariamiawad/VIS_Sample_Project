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
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2019-11-13 15:54:55
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

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif

/* -----------------------------------------------------------------------------
    &&&~ MACROS
 ----------------------------------------------------------------------------- */
/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_SetIpduGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComIPduGroupState, (pduId), (bitVal))
/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_SetIpduReinitGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComIPduGroupReinitState, (pduId), (bitVal))
#define BswM_SetIpduDMGroup(pduId, bitVal)

/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_MarkPduGroupControlInvocation(control) BswM_PduGroupControlInvocation |= (control)
#define BswM_MarkDmControlInvocation() BswM_PduGroupControlInvocation |= BSWM_GROUPCONTROL_DM



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId    Id of the rule to update.
 * \param[in]   state     New state of the rule.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state);


/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_BswM_0779 */

/**********************************************************************************************************************
 *  ImmediateSwcNotification
 *********************************************************************************************************************/
/*! \defgroup    ImmediateSwcNotification
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ImmediateSwcNotification
 *********************************************************************************************************************/
/*!
 * \brief       Arbitrates depending immediate rules of a Swc Mode Notification port.
 * \details     Checks if port is valid and arbitrates depending immediate rules.
 * \param[IN]   notificationId  Index of a swc mode notification port.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Function called by immediate swc notification functions (BswMRteNotificationFunctions).
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcNotification(BswM_SizeOfModeNotificationMappingType notificationId);
/*! \} */ /* End of group ImmediateSwcNotification */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Godown_AL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_OffActionList(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_NoComActionList(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_FullComActionList(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Generic_completeinit_AL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_ExtendSession_AL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_DefaultSession_AL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_ProgSession_AL(void);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_NvMWriteAllFinished(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_BusOffRule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_NoComRule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_FullComRule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Generic_completeInit_Rule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_DefaultSession_Rule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_ExtendSession_Rule(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_ProgSession_Rule(void);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/* PRQA S 0779 VARIABLEDECLARATIONS */ /* MD_BswM_0779 */ 

#define BSWM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

BSWM_LOCAL VAR(uint8, BSWM_VAR_NOINIT) BswM_PduGroupControlInvocation;

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



BSWM_LOCAL VAR(Rte_ModeType_DcmDiagnosticSessionControl, BSWM_VAR_NOINIT) BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl;


/* PRQA S 3218 3 */ /* MD_BswM_3218 */
BSWM_LOCAL VAR(Com_IpduGroupVector, BSWM_VAR_NOINIT) BswM_ComIPduGroupState;
BSWM_LOCAL VAR(Com_IpduGroupVector, BSWM_VAR_NOINIT) BswM_ComIPduGroupReinitState;

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* PRQA L:VARIABLEDECLARATIONS */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BswM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[8] = {
    /* Index    FctPtr                                             Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_Godown_AL                   },  /* [Priority: 0] */  /* [AL_Godown_AL] */
  { /*     1 */ BswM_ActionList_CanSM_Ch1_OffActionList     },  /* [Priority: 0] */  /* [AL_CanSM_Ch1_OffActionList] */
  { /*     2 */ BswM_ActionList_CanSM_Ch1_NoComActionList   },  /* [Priority: 0] */  /* [AL_CanSM_Ch1_NoComActionList] */
  { /*     3 */ BswM_ActionList_CanSM_Ch1_FullComActionList },  /* [Priority: 0] */  /* [AL_CanSM_Ch1_FullComActionList] */
  { /*     4 */ BswM_ActionList_Generic_completeinit_AL     },  /* [Priority: 0] */  /* [AL_Generic_completeinit_AL] */
  { /*     5 */ BswM_ActionList_Dcm_DSC_ExtendSession_AL    },  /* [Priority: 0] */  /* [AL_Dcm_DSC_ExtendSession_AL] */
  { /*     6 */ BswM_ActionList_Dcm_DSC_DefaultSession_AL   },  /* [Priority: 0] */  /* [AL_Dcm_DSC_DefaultSession_AL] */
  { /*     7 */ BswM_ActionList_Dcm_DSC_ProgSession_AL      }   /* [Priority: 0] */  /* [AL_Dcm_DSC_ProgSession_AL] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[4] = {
    /* Index    RulesIndEndIdx  RulesIndStartIdx        Comment                                           Referable Keys */
  { /*     0 */             3U,               0U },  /* [Name: CanSMIndication_Ch1_CanFD3_RP] */  /* [MRP_CanSMIndication_Ch1_CanFD3_RP, CANSM_CHANNEL_0] */
  { /*     1 */             4U,               3U },  /* [Name: Generic_CompleteInit_RP]       */  /* [MRP_Generic_CompleteInit_RP, GENERIC_0] */
  { /*     2 */             5U,               4U },  /* [Name: NvM_WriteAll_RP]               */  /* [MRP_NvM_WriteAll_RP, NVM_JOB_0] */
  { /*     3 */             8U,               5U }   /* [Name: Dcm_DiagSessionControl_RP]     */  /* [MRP_Dcm_DiagSessionControl_RP, SWC_NOTIFICATION_0] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element    Description
  Id         External id of rule.
  Init       Initialization value of rule state (TRUE, FALSE, UNDEFINED or DEACTIVATED).
  FctPtr     Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[8] = {
    /* Index    Id  Init            FctPtr                                       Referable Keys */
  { /*     0 */ 7U, BSWM_FALSE    , BswM_Rule_NvMWriteAllFinished         },  /* [R_NvMWriteAllFinished, MRP_NvM_WriteAll_RP] */
  { /*     1 */ 0U, BSWM_UNDEFINED, BswM_Rule_CanSM_Ch1_BusOffRule        },  /* [R_CanSM_Ch1_BusOffRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  { /*     2 */ 2U, BSWM_UNDEFINED, BswM_Rule_CanSM_Ch1_NoComRule         },  /* [R_CanSM_Ch1_NoComRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  { /*     3 */ 1U, BSWM_FALSE    , BswM_Rule_CanSM_Ch1_FullComRule       },  /* [R_CanSM_Ch1_FullComRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  { /*     4 */ 6U, BSWM_FALSE    , BswM_Rule_Generic_completeInit_Rule   },  /* [R_Generic_completeInit_Rule, MRP_Generic_CompleteInit_RP] */
  { /*     5 */ 3U, BSWM_FALSE    , BswM_Rule_Dcm_DSC_DefaultSession_Rule },  /* [R_Dcm_DSC_DefaultSession_Rule, MRP_Dcm_DiagSessionControl_RP] */
  { /*     6 */ 4U, BSWM_FALSE    , BswM_Rule_Dcm_DSC_ExtendSession_Rule  },  /* [R_Dcm_DSC_ExtendSession_Rule, MRP_Dcm_DiagSessionControl_RP] */
  { /*     7 */ 5U, BSWM_FALSE    , BswM_Rule_Dcm_DSC_ProgSession_Rule    }   /* [R_Dcm_DSC_ProgSession_Rule, MRP_Dcm_DiagSessionControl_RP] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[8] = {
  /* Index    RulesInd      Referable Keys */
  /*     0 */       1U,  /* [MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     1 */       2U,  /* [MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     2 */       3U,  /* [MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     3 */       4U,  /* [MRP_Generic_CompleteInit_RP] */
  /*     4 */       0U,  /* [MRP_NvM_WriteAll_RP] */
  /*     5 */       5U,  /* [MRP_Dcm_DiagSessionControl_RP] */
  /*     6 */       6U,  /* [MRP_Dcm_DiagSessionControl_RP] */
  /*     7 */       7U   /* [MRP_Dcm_DiagSessionControl_RP] */
};
#define BSWM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_ActionListQueueType, BSWM_VAR_NOINIT) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [AL_Godown_AL] */
  /*     1 */  /* [AL_CanSM_Ch1_OffActionList] */
  /*     2 */  /* [AL_CanSM_Ch1_NoComActionList] */
  /*     3 */  /* [AL_CanSM_Ch1_FullComActionList] */
  /*     4 */  /* [AL_Generic_completeinit_AL] */
  /*     5 */  /* [AL_Dcm_DSC_ExtendSession_AL] */
  /*     6 */  /* [AL_Dcm_DSC_DefaultSession_AL] */
  /*     7 */  /* [AL_Dcm_DSC_ProgSession_AL] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NOINIT) BswM_CanSMChannelState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CanSMIndication_Ch1_CanFD3_RP] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NOINIT) BswM_GenericState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [GENERIC_0, MRP_Generic_CompleteInit_RP] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_ZERO_INIT) BswM_Initialized = FALSE;
#define BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NOINIT) BswM_ModeRequestQueue[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_CanSMIndication_Ch1_CanFD3_RP, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_Generic_CompleteInit_RP, GENERIC_0] */
  /*     2 */  /* [MRP_NvM_WriteAll_RP, NVM_JOB_0] */
  /*     3 */  /* [MRP_Dcm_DiagSessionControl_RP, SWC_NOTIFICATION_0] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(NvM_RequestResultType, BSWM_VAR_NOINIT) BswM_NvMJobState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [NVM_JOB_0, MRP_NvM_WriteAll_RP] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_RuleStatesType, BSWM_VAR_NOINIT) BswM_RuleStates[8];
  /* Index        Referable Keys  */
  /*     0 */  /* [R_NvMWriteAllFinished, MRP_NvM_WriteAll_RP] */
  /*     1 */  /* [R_CanSM_Ch1_BusOffRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     2 */  /* [R_CanSM_Ch1_NoComRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     3 */  /* [R_CanSM_Ch1_FullComRule, MRP_CanSMIndication_Ch1_CanFD3_RP] */
  /*     4 */  /* [R_Generic_completeInit_Rule, MRP_Generic_CompleteInit_RP] */
  /*     5 */  /* [R_Dcm_DSC_DefaultSession_Rule, MRP_Dcm_DiagSessionControl_RP] */
  /*     6 */  /* [R_Dcm_DSC_ExtendSession_Rule, MRP_Dcm_DiagSessionControl_RP] */
  /*     7 */  /* [R_Dcm_DSC_ProgSession_Rule, MRP_Dcm_DiagSessionControl_RP] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_ExecuteIpduGroupControl()
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ExecuteIpduGroupControl(void)
{
  Com_IpduGroupVector ipduGroupReinitState;
  Com_IpduGroupVector ipduGroupState;
  uint16 iCnt;
  uint8 controlInvocation = BSWM_GROUPCONTROL_IDLE;

  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if(BswM_PduGroupControlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_REINIT) != 0u)
    {
      iCnt = BSWM_IPDUGROUPVECTORSIZE;
      while(iCnt-- > (uint16)0x0000) /* PRQA S 3440 */ /* MD_BswM_3440 */
      {
        ipduGroupReinitState[iCnt] = BswM_ComIPduGroupReinitState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
      }
    }
    /* Check if also PDU control actions without reinitialization flag were performed.
     * If yes, execute them too and update BswM_ComIPduGroupReinitState */
    if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      iCnt = BSWM_IPDUGROUPVECTORSIZE;
      while(iCnt-- > (uint16)0x0000) /* PRQA S 3440 */ /* MD_BswM_3440 */
      {
        ipduGroupState[iCnt] = BswM_ComIPduGroupState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
        BswM_ComIPduGroupReinitState[iCnt] = BswM_ComIPduGroupState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
      }
    }
    controlInvocation = BswM_PduGroupControlInvocation;
    BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;
  }
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(controlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((controlInvocation & BSWM_GROUPCONTROL_REINIT) != 0u)
    {
      Com_IpduGroupControl(ipduGroupReinitState, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
    }
    if((controlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      Com_IpduGroupControl(ipduGroupState, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
    }
  }
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */


/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state)
{
  if (ruleId < BswM_GetSizeOfRuleStates())
  {
    BswM_SetRuleStates(ruleId, state); /* SBSW_BSWM_SETRULESTATE */
  }
}


/**********************************************************************************************************************
 *  BswM_Init_Gen
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Init_Gen(void)
{

  BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;

  /* PRQA S 3109 COMCLEARIPDU */ /* MD_BswM_3109 */
  Com_ClearIpduGroupVector(BswM_ComIPduGroupState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  Com_ClearIpduGroupVector(BswM_ComIPduGroupReinitState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMCLEARIPDU */
}

/**********************************************************************************************************************
 *  BswMRteNotificationFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Notification_Dcm_DiagSessionControl_RP
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Notification_Dcm_DiagSessionControl_RP(void)
{
  Rte_ModeType_DcmDiagnosticSessionControl previous;
  (void)Rte_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl(&previous, &BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl);  /* SBSW_BSWM_RTE_MODE */
  BswM_ImmediateSwcNotification(0);
}

/**********************************************************************************************************************
 *  BswM_ImmediateSwcNotification
 *********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcNotification(BswM_SizeOfModeNotificationMappingType notificationId)
{
  if(notificationId < BswM_GetSizeOfModeNotificationMapping())
  {
    BswM_ImmediateModeRequest(BswM_GetImmediateUserStartIdxOfModeNotificationMapping(notificationId), BswM_GetImmediateUserEndIdxOfModeNotificationMapping(notificationId), BSWM_SWCREQUESTMODE_ID);
  }
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_Godown_AL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Godown_AL(void)
{
  BswM_GoDownByEcuM();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CanSM_Ch1_OffActionList
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_OffActionList(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PSA_FC_Ch1_BusOffHandling();
  /*lint -restore */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CanSM_Ch1_NoComActionList
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_NoComActionList(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PSA_FC_Ch1_NoComHandling();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CanSM_Ch1_FullComActionList
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CanSM_Ch1_FullComActionList(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PSA_FC_Ch1_FullComHandling();
  /*lint -restore */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduReinitGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Rx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduReinitGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_SCU_oCAN00_Tx_fcef2243, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_REINIT);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_Generic_completeinit_AL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Generic_completeinit_AL(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  BswM_UC_CompleteInit();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_Dcm_DSC_ExtendSession_AL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_ExtendSession_AL(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  BswM_Dcm_ExtendedSessionEntryAction();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_Dcm_DSC_DefaultSession_AL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_DefaultSession_AL(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  BswM_Dcm_DefaultSessionEntryAction();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_Dcm_DSC_ProgSession_AL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_Dcm_DSC_ProgSession_AL(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  BswM_Dcm_ProgrammingSessionEntryAction();
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_NvMWriteAllFinished
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_NvMWriteAllFinished(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression NvMWriteAllFinished_LE. */
  if(BswM_GetNvMJobState(0) != NVM_REQ_PENDING)
  {
    /* Return conditional action list BswM_ActionList_Godown_AL. */
    retVal = BSWM_ID_AL_Godown_AL;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CanSM_Ch1_BusOffRule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_BusOffRule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CanSM_Ch1_OffLogicalExpression. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_BUS_OFF)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CanSM_Ch1_BusOffRule) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_BusOffRule, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CanSM_Ch1_OffActionList. */
      retVal = BSWM_ID_AL_CanSM_Ch1_OffActionList;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_BusOffRule, BSWM_FALSE);
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CanSM_Ch1_NoComRule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_NoComRule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CanSM_Ch1_NoComLogicalExpression. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_NO_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CanSM_Ch1_NoComRule) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_NoComRule, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CanSM_Ch1_NoComActionList. */
      retVal = BSWM_ID_AL_CanSM_Ch1_NoComActionList;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_NoComRule, BSWM_FALSE);
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CanSM_Ch1_FullComRule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CanSM_Ch1_FullComRule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression CanSM_Ch1_FullComLogicalExpression. */
  if(BswM_GetCanSMChannelState(0) == CANSM_BSWM_FULL_COMMUNICATION)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_CanSM_Ch1_FullComRule) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_FullComRule, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_CanSM_Ch1_FullComActionList. */
      retVal = BSWM_ID_AL_CanSM_Ch1_FullComActionList;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_CanSM_Ch1_FullComRule, BSWM_FALSE);
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Generic_completeInit_Rule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Generic_completeInit_Rule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression Generic_CompleteInit_LE. */
  if(BswM_GetGenericState(0) == 1u)
  {
    if( BswM_GetRuleStates(BSWM_ID_RULE_Generic_completeInit_Rule) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Generic_completeInit_Rule, BSWM_TRUE);
      /* Return triggered action list BswM_ActionList_Generic_completeinit_AL. */
      retVal = BSWM_ID_AL_Generic_completeinit_AL;
    }
  }
  else
  {
    BswM_UpdateRuleStates(BSWM_ID_RULE_Generic_completeInit_Rule, BSWM_FALSE);
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Dcm_DSC_DefaultSession_Rule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_DefaultSession_Rule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression Dcm_DSC_DefaultSession_LE. */
  if(BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl == RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION)
  {
    /* Return conditional action list BswM_ActionList_Dcm_DSC_DefaultSession_AL. */
    retVal = BSWM_ID_AL_Dcm_DSC_DefaultSession_AL;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Dcm_DSC_ExtendSession_Rule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_ExtendSession_Rule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression Dcm_DSC_ExtendSession_LE. */
  if(BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl == RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION)
  {
    /* Return conditional action list BswM_ActionList_Dcm_DSC_ExtendSession_AL. */
    retVal = BSWM_ID_AL_Dcm_DSC_ExtendSession_AL;
  }
  /* No false action list configured. */
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Dcm_DSC_ProgSession_Rule
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Dcm_DSC_ProgSession_Rule(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  /* Evaluate logical expression Dcm_DSC_ProgSession_LE. */
  if(BswM_Mode_Notification_Dcm_DiagSessionControl_RP_DcmDiagnosticSessionControl == RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION)
  {
    /* Return conditional action list BswM_ActionList_Dcm_DSC_ProgSession_AL. */
    retVal = BSWM_ID_AL_Dcm_DSC_ProgSession_AL;
  }
  /* No false action list configured. */
  return retVal;
}



#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

