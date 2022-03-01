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
 *              File: MemIf_Cfg.h
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


/**** Protection against multiple inclusion **************************************************************************/
#if !defined (MEMIF_CFG_H)    
# define MEMIF_CFG_H

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
#ifndef MEMIF_USE_DUMMY_FUNCTIONS
#define MEMIF_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyFunction */
#endif
#ifndef MEMIF_USE_DUMMY_STATEMENT
#define MEMIF_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatement */
#endif
#ifndef MEMIF_DUMMY_STATEMENT
#define MEMIF_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef MEMIF_DUMMY_STATEMENT_CONST
#define MEMIF_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef MEMIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define MEMIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef MEMIF_ATOMIC_VARIABLE_ACCESS
#define MEMIF_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef MEMIF_PROCESSOR_CANOEEMU
#define MEMIF_PROCESSOR_CANOEEMU
#endif
#ifndef MEMIF_COMP_ANSI
#define MEMIF_COMP_ANSI
#endif
#ifndef MEMIF_GEN_GENERATOR_MSR
#define MEMIF_GEN_GENERATOR_MSR
#endif
#ifndef MEMIF_CPUTYPE_BITORDER_LSB2MSB
#define MEMIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/VTT/VTTEcuC/EcucGeneral/BitOrder */
#endif
#ifndef MEMIF_CONFIGURATION_VARIANT_PRECOMPILE
#define MEMIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef MEMIF_CONFIGURATION_VARIANT_LINKTIME
#define MEMIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef MEMIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define MEMIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef MEMIF_CONFIGURATION_VARIANT
#define MEMIF_CONFIGURATION_VARIANT MEMIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef MEMIF_POSTBUILD_VARIANT_SUPPORT
#define MEMIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
# define MEMIF_CFG_MAJOR_VERSION	(5u) 
# define MEMIF_CFG_MINOR_VERSION	(2u) 

/**** Pre-compile switches for EA development error checks ***********************************************************/

# define MEMIF_DEV_ERROR_DETECT       (STD_ON)
# define MEMIF_DEV_ERROR_REPORT       (STD_ON)      
#include "Det.h"  

/***** Optional API functions ****************************************************************************************/

# define MEMIF_VERSION_INFO_API  (STD_OFF)

/**** Generation of symbolic device names ****************************************************************************/
#define MEMIF_Fee (0U) 


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define MEMIF_NUMBER_OF_DEVICES      (1U)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Function pointer prototypes for MemHwA API services */
 
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiReadType) (uint16 BlockNumber, uint16 BlockOffset, MemIf_DataPtr_pu8 DataBufferPtr, uint16 Length);
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiWriteType) (uint16 BlockNumber, MemIf_DataPtr_pu8 DataBufferPtr);
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiEraseImmediateBlockType) (uint16 BlockNumber);
typedef P2FUNC (Std_ReturnType, MEMIF_CODE, MemIf_ApiInvalidateBlockType) (uint16 BlockNumber);
typedef P2FUNC (void, MEMIF_CODE, MemIf_ApiCancelType)(void);
typedef P2FUNC (MemIf_StatusType, MEMIF_CODE, MemIf_ApiGetStatusType)(void);
typedef P2FUNC (MemIf_JobResultType, MEMIF_CODE, MemIf_ApiGetJobResultType)(void);
typedef P2FUNC (void, MEMIF_CODE, MemIf_ApiSetModeType)(MemIf_ModeType Mode);


typedef struct
{
	MemIf_ApiReadType                   Read;
	MemIf_ApiWriteType                  Write;
	MemIf_ApiEraseImmediateBlockType    EraseImmediateBlock;
	MemIf_ApiInvalidateBlockType        InvalidateBlock; 
	MemIf_ApiCancelType                 Cancel;
	MemIf_ApiGetStatusType              GetStatus;
	MemIf_ApiGetJobResultType           GetJobResult;
	MemIf_ApiSetModeType                SetMode;
} MemIf_MemHwAApi_Type;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define MEMIF_START_SEC_CONST_8BIT
# include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(uint8, MEMIF_CONST) MemIf_NumberOfDevices;
    
# define MEMIF_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



# define MEMIF_START_SEC_CONST_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis[MEMIF_NUMBER_OF_DEVICES];

# define MEMIF_STOP_SEC_CONST_32BIT
# include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* MEMIF_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: MemIf_Cfg.h
 *********************************************************************************************************************/

