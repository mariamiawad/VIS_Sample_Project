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
 *          File:  SchM_CanIf.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  Header of BSW Scheduler for BSW Module <CanIf>
 *********************************************************************************************************************/
#ifndef SCHM_CANIF_H
# define SCHM_CANIF_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_CanIf_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_2() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_2() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_4() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_4() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_5() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_5() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_6() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_6() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_7() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_7() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_CANIF_H */

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
