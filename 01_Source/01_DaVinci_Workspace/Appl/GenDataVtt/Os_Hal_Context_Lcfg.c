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
 *              File: Os_Hal_Context_Lcfg.c
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

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore_CORE0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level7_Dyn;

/*! HAL dynamic ISR2 level context data: Level8 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_Isr_Level8_Dyn;

/*! HAL dynamic task context data: BSW_OIEsTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_OIEsTask_Dyn;

/*! HAL dynamic task context data: BSW_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_Task_Dyn;

/*! HAL dynamic task context data: OsTask_App */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_App_Dyn;

/*! HAL dynamic task context data: OsTask_Init */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Init_Dyn;

/*! HAL dynamic task context data: OsTask_Nv_Data */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Nv_Data_Dyn;

/*! HAL dynamic task context data: Os_IdleTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_IdleTask_Dyn;

/*! HAL dynamic task context data: SWCsInitTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SWCsInitTask_Dyn;

/*! HAL exception context data: OsCore_CORE0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_CORE0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore_CORE0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_CORE0 =
{

  /* Type =              */ Hook,
  /* Name =              */ "Os_CoreInitHook_OsCore_CORE0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_Os_CoreInitHook_OsCore_CORE0,
  /* CANoeTaskFunction = */ Os_Hal_CANoeTaskWrapper,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) Os_HookWrapperOs_CoreInitHook,
  /* ReturnAddress =     */ Os_TrapHookReturn,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Init
};

/*! HAL ISR2 context configuration data: AdcIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AdcIsr_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "AdcIsr_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_AdcIsr_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_AdcIsr_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_AdcIsr_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: CanIsrErr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrErr_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "CanIsrErr_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_CanIsrErr_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_CanIsrErr_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_CanIsrErr_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: CanIsrRx_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrRx_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "CanIsrRx_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_CanIsrRx_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_CanIsrRx_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_CanIsrRx_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: CanIsrTx_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrTx_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "CanIsrTx_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_CanIsrTx_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_CanIsrTx_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_CanIsrTx_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* Type =              */ Isr,
  /* Name =              */ "CounterIsr_SystemTimer",
  /* CANoeEmuTaskId =    */ CANoeTaskId_CounterIsr_SystemTimer,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_CounterIsr_SystemTimer,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_Os_TimerPitIsr,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: GptIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GptIsr_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "GptIsr_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_GptIsr_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_GptIsr_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_GptIsr_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: IcuIsr_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IcuIsr_0 =
{
  /* Type =              */ Isr,
  /* Name =              */ "IcuIsr_0",
  /* CANoeEmuTaskId =    */ CANoeTaskId_IcuIsr_0,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_IcuIsr_0,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_IcuIsr_0,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: SpiIsrTx_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SpiIsrTx_1 =
{
  /* Type =              */ Isr,
  /* Name =              */ "SpiIsrTx_1",
  /* CANoeEmuTaskId =    */ CANoeTaskId_SpiIsrTx_1,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_SpiIsrTx_1,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_SpiIsrTx_1,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL ISR2 context configuration data: SpiIsrTx_2 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SpiIsrTx_2 =
{
  /* Type =              */ Isr,
  /* Name =              */ "SpiIsrTx_2",
  /* CANoeEmuTaskId =    */ CANoeTaskId_SpiIsrTx_2,
  /* CANoeTaskFunction = */ &Os_Hal_CanoeIrqTask_SpiIsrTx_2,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Isr_SpiIsrTx_2,
  /* ReturnAddress =     */ &Os_IsrEpilogue,
  /* IntLockLevel =      */ 10,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Isr_Core
};

/*! HAL task context configuration data: BSW_OIEsTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_OIEsTask =
{
  /* Type =              */ Task,
  /* Name =              */ "BSW_OIEsTask",
  /* CANoeEmuTaskId =    */ CANoeTaskId_BSW_OIEsTask,
  /* CANoeTaskFunction = */ &Os_Task_BSW_OIEsTask,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_BSW_OIEsTask,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Task_Prio0
};

/*! HAL task context configuration data: BSW_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_Task =
{
  /* Type =              */ Task,
  /* Name =              */ "BSW_Task",
  /* CANoeEmuTaskId =    */ CANoeTaskId_BSW_Task,
  /* CANoeTaskFunction = */ &Os_Task_BSW_Task,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_BSW_Task,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_BSW_Task
};

/*! HAL task context configuration data: OsTask_App */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_App =
{
  /* Type =              */ Task,
  /* Name =              */ "OsTask_App",
  /* CANoeEmuTaskId =    */ CANoeTaskId_OsTask_App,
  /* CANoeTaskFunction = */ &Os_Task_OsTask_App,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_OsTask_App,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsTask_App
};

/*! HAL task context configuration data: OsTask_Init */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Init =
{
  /* Type =              */ Task,
  /* Name =              */ "OsTask_Init",
  /* CANoeEmuTaskId =    */ CANoeTaskId_OsTask_Init,
  /* CANoeTaskFunction = */ &Os_Task_OsTask_Init,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_OsTask_Init,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Task_Prio1
};

/*! HAL task context configuration data: OsTask_Nv_Data */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Nv_Data =
{
  /* Type =              */ Task,
  /* Name =              */ "OsTask_Nv_Data",
  /* CANoeEmuTaskId =    */ CANoeTaskId_OsTask_Nv_Data,
  /* CANoeTaskFunction = */ &Os_Task_OsTask_Nv_Data,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_OsTask_Nv_Data,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Task_Prio5
};

/*! HAL task context configuration data: Os_IdleTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_IdleTask =
{
  /* Type =              */ Task,
  /* Name =              */ "Os_IdleTask",
  /* CANoeEmuTaskId =    */ CANoeTaskId_Os_IdleTask,
  /* CANoeTaskFunction = */ &Os_Task_Os_IdleTask,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_Os_IdleTask,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Task_Prio6
};

/*! HAL task context configuration data: SWCsInitTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SWCsInitTask =
{
  /* Type =              */ Task,
  /* Name =              */ "SWCsInitTask",
  /* CANoeEmuTaskId =    */ CANoeTaskId_SWCsInitTask,
  /* CANoeTaskFunction = */ &Os_Task_SWCsInitTask,
  /* Entry =             */ (Os_Hal_ContextEntryCBType) &Os_Task_SWCsInitTask,
  /* ReturnAddress =     */ &Os_TaskMissingTerminateTask,
  /* IntLockLevel =      */ 0,
  /* Stack =             */ &OsCfg_Stack_OsCore_CORE0_Task_Prio3
};

/*! HAL kernel stack configuration data: OsCore_CORE0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore_CORE0_Kernel =
{
  /* .Dummy = */ (uint32)NULL_PTR,  /* OsCore_CORE0_Kernel */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1] =
{
  &OsCfg_Hal_Context_OsCore_CORE0_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
