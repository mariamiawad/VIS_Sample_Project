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
 *          File:  ComXf.c
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR ComXf Generator Version 1.8.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  MICROSAR ComXf implementation file
 *********************************************************************************************************************/

/* PRQA S 0715, 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_1.1_715, MD_MSR_5.1_777, MD_MSR_5.1_779, MD_ComXf_0781, MD_MSR_1.1_857 */

#include "ComXf.h" /* PRQA S 0828, 0810 */ /* MD_MSR_1.1_828, MD_MSR_1.1_810 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#ifndef COMXF_DUMMY_STATEMENT
# define COMXF_DUMMY_STATEMENT(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif
#ifndef COMXF_DUMMY_STATEMENT_CONST
# define COMXF_DUMMY_STATEMENT_CONST(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#define COMXF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config)
{
  COMXF_DUMMY_STATEMENT(config); /* PRQA S 3199 */ /* MD_MSR_14.2 */
}

FUNC(void, COMXF_CODE) ComXf_DeInit(void)
{
}

#define COMXF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_0781:  MISRA rule: 5.6
     Reason:       The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                   The compliance to this rule is under user's control.
     Risk:         Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention:   Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

*/
