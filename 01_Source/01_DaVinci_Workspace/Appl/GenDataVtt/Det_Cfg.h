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
 *            Module: Det
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Det_Cfg.h
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

 
#if !defined(DET_CFG_H)
#define DET_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define DET_GENERATOR_CFG5
#define DET_AUTOSARVERSION                       4U
#define DET_ENABLED                              STD_ON
#define DET_VERSION_INFO_API                     STD_OFF
#define DET_DEBUG_ENABLED                        STD_OFF
#define DET_DLTFILTERSIZE                        0U
#define DET_GLOBALFILTERSIZE                     0U
#define DET_BREAKFILTERSIZE                      0U
#define DET_LOGBUFFERSIZE                        0U
#define DET_FORWARD_TO_DLT                       STD_OFF
#define DET_REPORT_ERROR_RECURSIONLIMIT          0U
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT   0U
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT 0U

/*! DetModuleId symbolic name defines */


/*! Service port defines */


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DetPCDataSwitches  Det Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DET_ERRORHOOKTABLE                                            STD_OFF  /**< Deactivateable: 'Det_ErrorHookTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Det_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Det_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define DET_RUNTIMEERRORCALLOUTTABLE                                  STD_OFF  /**< Deactivateable: 'Det_RuntimeErrorCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_TRANSIENTFAULTCALLOUTTABLE                                STD_OFF  /**< Deactivateable: 'Det_TransientFaultCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_PCCONFIG                                                  STD_ON
#define DET_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Det_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Det_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCSymbolicInitializationPointers  Det Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Det_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Det' */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCInitializationSymbols  Det Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Det_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Det */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCGeneral  Det General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define DET_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define DET_FINAL_MAGIC_NUMBER                                        0x0F1EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Det */
#define DET_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Det' is not configured to be postbuild capable. */
#define DET_INIT_DATA                                                 DET_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define DET_INIT_DATA_HASH_CODE                                       651877085L  /**< the precompile constant to validate the initialization structure at initialization time of Det with a hashcode. The seed value is '0x0F1EU' */
#define DET_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define DET_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Det shall be used. */
/** 
  \}
*/ 



#ifndef DET_USE_DUMMY_FUNCTIONS
#define DET_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef DET_USE_DUMMY_STATEMENT
#define DET_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef DET_DUMMY_STATEMENT
#define DET_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DET_DUMMY_STATEMENT_CONST
#define DET_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DET_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DET_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef DET_ATOMIC_VARIABLE_ACCESS
#define DET_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef DET_PROCESSOR_CANOEEMU
#define DET_PROCESSOR_CANOEEMU
#endif
#ifndef DET_COMP_ANSI
#define DET_COMP_ANSI
#endif
#ifndef DET_GEN_GENERATOR_MSR
#define DET_GEN_GENERATOR_MSR
#endif
#ifndef DET_CPUTYPE_BITORDER_LSB2MSB
#define DET_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef DET_CONFIGURATION_VARIANT_PRECOMPILE
#define DET_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DET_CONFIGURATION_VARIANT_LINKTIME
#define DET_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DET_CONFIGURATION_VARIANT
#define DET_CONFIGURATION_VARIANT DET_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DET_POSTBUILD_VARIANT_SUPPORT
#define DET_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/*! Compatibility defines */
#define DET_RUNTIME_ERROR_CALLOUT_ENABLED        DET_RUNTIMEERRORCALLOUTTABLE
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED      DET_TRANSIENTFAULTCALLOUTTABLE
#define DET_ERROR_HOOK_ENABLED                   DET_ERRORHOOKTABLE

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DetPCHasMacros  Det Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Det_HasPCConfig()                                             (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Function pointer type for callouts */
typedef P2FUNC(Std_ReturnType, DET_CODE, Det_CalloutTableType )( uint16, uint8, uint8, uint8 );


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  DetPCRootValueTypes  Det Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Det_PCConfig */
typedef struct sDet_PCConfigType
{
  uint8 Det_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Det_PCConfigType;

typedef Det_PCConfigType Det_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 

 


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
 

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

 
#define DET_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */




#define DET_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DET_CFG_H */
