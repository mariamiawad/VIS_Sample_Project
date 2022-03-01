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
 *            Module: MemIf
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: MemIf_Cfg.c
 *   Generation Time: 2019-11-13 15:54:53
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

    
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MemIf.h"

/****  Include of MemHwA Modules  ************************************************************************************/
#include "Fee.h" 



/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (MEMIF_CFG_MAJOR_VERSION != (5u)) \
     || (MEMIF_CFG_MINOR_VERSION != (2u)))
# error "Version numbers of MemIf_Cfg.c and MemIf_Cfg.h are inconsistent!"
#endif

#if (   (MEMIF_SW_MAJOR_VERSION != (3u)) \
     || (MEMIF_SW_MINOR_VERSION != (3u)))
# error "Version numbers of MemIf_Cfg.c and MemIf.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
#ifndef MEMIF_LOCAL /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL static
#endif

#if !defined (MEMIF_LOCAL_INLINE) /* COV_MEMIF_COMPATIBILITY */
# define MEMIF_LOCAL_INLINE LOCAL_INLINE
#endif
 
#define MEMIF_START_SEC_CONST_8BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices = MEMIF_NUMBER_OF_DEVICES;

#define MEMIF_STOP_SEC_CONST_8BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  MemHwA Function Pointer Tables
 *********************************************************************************************************************/
#define MEMIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**-- MemHwA Write Wrapper Functions --**/
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr); 

 
MEMIF_LOCAL_INLINE FUNC (Std_ReturnType, MEMIF_PRIVATE_CODE) MemIf_Fee_WriteWrapper(uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr) /* PRQA S 3673 */ /* MD_MEMIF_16.7 */ 
{ 
    return Fee_Write(BlockNumber, DataBufferPtr); /* SBSW_MEMIF_04 */ 
}
 

#define MEMIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define MEMIF_START_SEC_CONST_32BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/**-- MemHwA Function Pointers --**/
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis[MEMIF_NUMBER_OF_DEVICES] =
{
   /*  Fee  */ {
    Fee_Read, 
    MemIf_Fee_WriteWrapper, 
    Fee_EraseImmediateBlock, 
    Fee_InvalidateBlock, 
    Fee_Cancel, 
    Fee_GetStatus, 
    Fee_GetJobResult, 
    Fee_SetMode
  }
};
    
#define MEMIF_STOP_SEC_CONST_32BIT
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */
    
/* Justification for module-specific MISRA deviations:     
  MD_MEMIF_16.7: rule 16.7
      Reason:     Buffer pointer is not declared const in order to support EA/FEE write interfaces with const and non-const buffers.
      Risk:       No risk. By using this wrapper functions without const pointers compiler warnings are solved.
      Prevention: Program flow has been verified by component tests and review.
*/
        
/**********************************************************************************************************************
 *  END OF FILE: MemIf_Cfg.c
 *********************************************************************************************************************/   

