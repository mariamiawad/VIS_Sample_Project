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
 *            Module: Fee
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_PrivateCfg.h
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
 *  PRIVATE SECTION
 *********************************************************************************************************************/
#if (!defined FEE_PRIVATE_CFG_H)
# define FEE_PRIVATE_CFG_H

  /****************************************************************************
   * VERSION IDENTIFICATION
   ***************************************************************************/
# define FEE_PRIVATE_CFG_MAJOR_VERSION                                (8u)
# define FEE_PRIVATE_CFG_MINOR_VERSION                                (1u)
# define FEE_PRIVATE_CFG_PATCH_VERSION                                (0u)

#ifndef FEE_USE_DUMMY_FUNCTIONS
#define FEE_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FEE_USE_DUMMY_STATEMENT
#define FEE_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FEE_DUMMY_STATEMENT
#define FEE_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT_CONST
#define FEE_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FEE_ATOMIC_VARIABLE_ACCESS
#define FEE_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FEE_PROCESSOR_CANOEEMU
#define FEE_PROCESSOR_CANOEEMU
#endif
#ifndef FEE_COMP_ANSI
#define FEE_COMP_ANSI
#endif
#ifndef FEE_GEN_GENERATOR_MSR
#define FEE_GEN_GENERATOR_MSR
#endif
#ifndef FEE_CPUTYPE_BITORDER_LSB2MSB
#define FEE_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef FEE_CONFIGURATION_VARIANT_PRECOMPILE
#define FEE_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FEE_CONFIGURATION_VARIANT_LINKTIME
#define FEE_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FEE_CONFIGURATION_VARIANT
#define FEE_CONFIGURATION_VARIANT FEE_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FEE_POSTBUILD_VARIANT_SUPPORT
#define FEE_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


  /****************************************************************************
   * Data consistency 
   ***************************************************************************/
#include "SchM_Fee.h"

#define Fee_GlobalSuspend() SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_0() 
#define Fee_GlobalRestore() SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_0() 


  /****************************************************************************
   * Configurations for Development mode
   ***************************************************************************/

#include "Det.h"

/* PRQA S 3453 1 *//* MD_MSR_19.7 */
#define Fee_Errorhook(funcId, errId) Det_ReportError((FEE_MODULE_ID), (FEE_INSTANCE_ID), (funcId), (errId))


  /*******************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   ******************************************************************************************************************/
   
# define FEE_INTERNAL_BUFFER_SIZE                        			  (64U)
   
  /****************************************************************************
   * LOWER LAYER CONFIGURATION PARAMETERS
   ***************************************************************************/
# define FEE_POLLING_MODE                              (STD_OFF)

# define Fee_FlsRead                                          Fls_Read
# define Fee_FlsWrite                                         Fls_Write
# define Fee_FlsErase                                         Fls_Erase
# define Fee_FlsCompare                                       Fls_Compare
# define Fee_FlsCancel                                        Fls_Cancel
# define Fee_FlsGetStatus                                     Fls_GetStatus
# define Fee_FlsGetJobResult                                  Fls_GetJobResult


  /****************************************************************************
   * UPPER LAYER CONFIGURATION PARAMETERS
   ***************************************************************************/
# define FEE_NVM_POLLING_MODE                          (STD_ON)

# if (STD_OFF == FEE_NVM_POLLING_MODE)
#  define Fee_NvMJobEndNotification()         			NvM_JobEndNotification()
#  define Fee_NvMJobErrorNotification()     			NvM_JobErrorNotification()
# endif

  /****************************************************************************
   * Error Callback Notification
   ***************************************************************************/
# define FEE_USE_APPL_ERROR_CALLBACK            		(STD_OFF)

# if (STD_ON == FEE_USE_APPL_ERROR_CALLBACK)
#  include "ApplMain.h"
# endif

  /********************************************************************************************************************
   *  INCLUDES
   *******************************************************************************************************************/


#include "Fls.h" 


# if (STD_OFF == FEE_NVM_POLLING_MODE)

# endif

#endif /* (!defined FEE_PRIVATE_CFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Fee_PrivateCfg.h
 *********************************************************************************************************************/
 
