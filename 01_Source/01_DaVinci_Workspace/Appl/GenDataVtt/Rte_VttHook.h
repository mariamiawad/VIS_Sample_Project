/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_VttHook.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  Header file containing definitions for VTT VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available Vtt VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 *  Rte_Vtt_Task_Dispatch
 *  Rte_Vtt_Task_WaitEventRet
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_VTTHOOK_H
# define _RTE_VTTHOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"


# define RTE_START_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_APPL_CODE) Rte_Vtt_Task_Dispatch(TaskType task); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_MSR_5.1_777 */
FUNC(void, RTE_APPL_CODE) Rte_Vtt_Task_WaitEventRet(TaskType task, EventMaskType ev); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_MSR_5.1_777 */

# define RTE_STOP_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_VTTHOOK_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
