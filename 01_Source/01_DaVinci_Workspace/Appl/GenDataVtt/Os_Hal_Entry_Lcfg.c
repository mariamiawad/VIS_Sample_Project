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
 *              File: Os_Hal_Entry_Lcfg.c
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

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/

/* EMPTY FOR PLATFORM STUB exc*/


/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


/*******************
 * Category 0 ISRs
 *******************/

/*******************
 * Category 1 ISRs
 *******************/

/*******************
 * Category 2 ISRs
 *******************/

/* CANoe IRQ Task: AdcIsr_0 (Level: 1) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_AdcIsr_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_AdcIsr_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: AdcIsr_0 (Level: 1) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_AdcIsr_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("AdcIsr_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_AdcIsr_0);
}



/* CANoe IRQ Task: CanIsrErr_0 (Level: 2) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_CanIsrErr_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_CanIsrErr_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: CanIsrErr_0 (Level: 2) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_CanIsrErr_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("CanIsrErr_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_CanIsrErr_0);
}



/* CANoe IRQ Task: CanIsrRx_0 (Level: 3) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_CanIsrRx_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_CanIsrRx_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: CanIsrRx_0 (Level: 3) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_CanIsrRx_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("CanIsrRx_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_CanIsrRx_0);
}



/* CANoe IRQ Task: CanIsrTx_0 (Level: 4) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_CanIsrTx_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_CanIsrTx_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: CanIsrTx_0 (Level: 4) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_CanIsrTx_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("CanIsrTx_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_CanIsrTx_0);
}



/* CANoe IRQ Task: CounterIsr_SystemTimer (Level: 10) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_CounterIsr_SystemTimer(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_CounterIsr_SystemTimer);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: CounterIsr_SystemTimer (Level: 10) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_CounterIsr_SystemTimer(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("CounterIsr_SystemTimer"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_CounterIsr_SystemTimer);
}



/* CANoe IRQ Task: GptIsr_0 (Level: 5) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_GptIsr_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_GptIsr_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: GptIsr_0 (Level: 5) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_GptIsr_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("GptIsr_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_GptIsr_0);
}



/* CANoe IRQ Task: IcuIsr_0 (Level: 1) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_IcuIsr_0(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_IcuIsr_0);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: IcuIsr_0 (Level: 1) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_IcuIsr_0(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("IcuIsr_0"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_IcuIsr_0);
}



/* CANoe IRQ Task: SpiIsrTx_1 (Level: 7) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_SpiIsrTx_1(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_SpiIsrTx_1);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: SpiIsrTx_1 (Level: 7) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_SpiIsrTx_1(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("SpiIsrTx_1"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_SpiIsrTx_1);
}



/* CANoe IRQ Task: SpiIsrTx_2 (Level: 8) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqTask_SpiIsrTx_2(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadToResume;
  Os_IsrRun((Os_IsrConfigType *)&OsCfg_Isr_SpiIsrTx_2);
  threadToResume = Os_CoreGetThread();
  CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(threadToResume->ContextConfig->CANoeEmuTaskId);
  CANoeEmuProcessor_RollbackStack();
  Os_Hal_CoreFreeze();
}

/* CANoe IRQ Handler: SpiIsrTx_2 (Level: 8) */
FUNC(void, OS_CODE) Os_Hal_CanoeIrqHandler_SpiIsrTx_2(void)
{
  Os_Hal_Debug_CanoeIrqHandler_Entry("SpiIsrTx_2"); 
  CANoeEmuProcessor_SetTaskToRun(CANoeTaskId_SpiIsrTx_2);
}






/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
