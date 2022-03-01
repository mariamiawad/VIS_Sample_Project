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
 *            Module: EcuC
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: v_cfg.h
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

#if !defined(__V_CFG_H__)
#define __V_CFG_H__


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef V_USE_DUMMY_FUNCTIONS
#define V_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef V_USE_DUMMY_STATEMENT
#define V_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef V_DUMMY_STATEMENT
#define V_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_DUMMY_STATEMENT_CONST
#define V_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define V_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef V_ATOMIC_VARIABLE_ACCESS
#define V_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef V_PROCESSOR_CANOEEMU
#define V_PROCESSOR_CANOEEMU
#endif
#ifndef V_COMP_ANSI
#define V_COMP_ANSI
#endif
#ifndef V_GEN_GENERATOR_MSR
#define V_GEN_GENERATOR_MSR
#endif
#ifndef V_CPUTYPE_BITORDER_LSB2MSB
#define V_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef V_CONFIGURATION_VARIANT_PRECOMPILE
#define V_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef V_CONFIGURATION_VARIANT_LINKTIME
#define V_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef V_CONFIGURATION_VARIANT
#define V_CONFIGURATION_VARIANT V_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef V_POSTBUILD_VARIANT_SUPPORT
#define V_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef C_USE_DUMMY_FUNCTIONS
#define C_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef C_USE_DUMMY_STATEMENT
#define C_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef C_DUMMY_STATEMENT
#define C_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_DUMMY_STATEMENT_CONST
#define C_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define C_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef C_ATOMIC_VARIABLE_ACCESS
#define C_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef C_PROCESSOR_CANOEEMU
#define C_PROCESSOR_CANOEEMU
#endif
#ifndef C_COMP_ANSI
#define C_COMP_ANSI
#endif
#ifndef C_GEN_GENERATOR_MSR
#define C_GEN_GENERATOR_MSR
#endif
#ifndef C_CPUTYPE_BITORDER_LSB2MSB
#define C_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef C_CONFIGURATION_VARIANT_PRECOMPILE
#define C_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef C_CONFIGURATION_VARIANT_LINKTIME
#define C_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef C_CONFIGURATION_VARIANT
#define C_CONFIGURATION_VARIANT C_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef C_POSTBUILD_VARIANT_SUPPORT
#define C_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define V_DISABLE_USE_DUMMY_FUNCTIONS
#define V_ENABLE_USE_DUMMY_STATEMENT
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* __V_CFG_H__ */
/**********************************************************************************************************************
 *  END OF FILE: v_cfg.h
 *********************************************************************************************************************/    

