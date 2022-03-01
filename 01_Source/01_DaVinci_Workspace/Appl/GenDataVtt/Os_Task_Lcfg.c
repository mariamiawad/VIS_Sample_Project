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
 *            Module: VTTOs
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Task_Lcfg.c
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

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic task data: BSW_OIEsTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BSW_OIEsTask_Dyn;

/*! Dynamic task data: BSW_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BSW_Task_Dyn;

/*! Dynamic task data: OsTask_App */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_App_Dyn;

/*! Dynamic task data: OsTask_Init */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Init_Dyn;

/*! Dynamic task data: OsTask_Nv_Data */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Nv_Data_Dyn;

/*! Dynamic task data: Os_IdleTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Os_IdleTask_Dyn;

/*! Dynamic task data: SWCsInitTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_SWCsInitTask_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task configuration data: BSW_OIEsTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BSW_OIEsTask =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BSW_OIEsTask,
    /* .Context               = */ &OsCfg_Hal_Context_BSW_OIEsTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Task_Prio0,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BSW_OIEsTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 0UL,
  /* .TaskId                = */ BSW_OIEsTask,
  /* .RunningPriority       = */ 0UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: BSW_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BSW_Task =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BSW_Task,
    /* .Context               = */ &OsCfg_Hal_Context_BSW_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_BSW_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BSW_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 2UL,
  /* .TaskId                = */ BSW_Task,
  /* .RunningPriority       = */ 2UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ TRUE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: OsTask_App */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_App =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_App,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_App_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_App,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_App_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 4UL,
  /* .TaskId                = */ OsTask_App,
  /* .RunningPriority       = */ 4UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ TRUE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: OsTask_Init */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Init =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Init,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Init_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Task_Prio1,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Init_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 1UL,
  /* .TaskId                = */ OsTask_Init,
  /* .RunningPriority       = */ 1UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OSDEFAULTAPPMODE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: OsTask_Nv_Data */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Nv_Data =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Nv_Data,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Nv_Data_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Task_Prio5,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Nv_Data_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 5UL,
  /* .TaskId                = */ OsTask_Nv_Data,
  /* .RunningPriority       = */ 5UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: Os_IdleTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Os_IdleTask =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Os_IdleTask,
    /* .Context               = */ &OsCfg_Hal_Context_Os_IdleTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Task_Prio6,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Os_IdleTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 6UL,
  /* .TaskId                = */ Os_IdleTask,
  /* .RunningPriority       = */ 6UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_ANY,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

/*! Task configuration data: SWCsInitTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_SWCsInitTask =
{
  /* .Thread                = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SWCsInitTask,
    /* .Context               = */ &OsCfg_Hal_Context_SWCsInitTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore_CORE0_Task_Prio3,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_SWCsInitTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore_CORE0,
    /* .Core                  = */ &OsCfg_Core_OsCore_CORE0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore_CORE0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE
  },
  /* .HomePriority          = */ 3UL,
  /* .TaskId                = */ SWCsInitTask,
  /* .RunningPriority       = */ 3UL,
  /* .MaxActivations        = */ 1UL,
  /* .AutostartModes        = */ OS_APPMODE_NONE,
  /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore_CORE0),
  /* .IsExtended            = */ FALSE,
  /* .StackSharing          = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_OIEsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_App),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Nv_Data),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Os_IdleTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SWCsInitTask),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
