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
 *          File:  ComXf_MemMap.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR ComXf Generator Version 1.8.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  COMXF Memory Mapping header file
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_ComXf_0883 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * COMXF specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: COMXF_START_SEC_CODE
 *********************************************************************************************************************/

#ifdef COMXF_START_SEC_CODE
# undef COMXF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: COMXF_STOP_SEC_CODE
 *********************************************************************************************************************/

#ifdef COMXF_STOP_SEC_CODE
# undef COMXF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_0883:  MISRA rule: 19.15
     Reason:       AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                   select appropriate #pragma directives.
     Risk:         MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention:   The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                   the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
