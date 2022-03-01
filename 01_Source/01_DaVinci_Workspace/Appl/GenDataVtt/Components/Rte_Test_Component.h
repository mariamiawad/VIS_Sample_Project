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
 *          File:  Rte_Test_Component.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  Application header file for SW-C <Test_Component>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TEST_COMPONENT_H
# define _RTE_TEST_COMPONENT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Test_Component_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CalibVer_CalibVer (0U)
#  define Rte_InitValue_InverterCoolgFlowRate_EMDurationMaxESA (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Test_Component_CalibVer_CalibVer(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_InverterCoolgFlowRate_EMDurationMaxESA Rte_Read_Test_Component_InverterCoolgFlowRate_EMDurationMaxESA
#  define Rte_Read_Test_Component_InverterCoolgFlowRate_EMDurationMaxESA(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_InverterCoolgFlowRate_451170b4, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CalibVer_CalibVer Rte_Write_Test_Component_CalibVer_CalibVer


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)5)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)5)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_EEPROM_Version_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)4)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)4)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_Product_Life_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Test_Component_START_SEC_CODE
# include "Test_Component_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ABS_MainFunction ABS_MainFunction
#  define RTE_RUNNABLE_ABS_StatusUpdate ABS_StatusUpdate
#  define RTE_RUNNABLE_DID_DID_ECU_Core_Assembly_ConditionCheckRead_Runnable DID_DID_ECU_Core_Assembly_ConditionCheckRead_Runnable
#  define RTE_RUNNABLE_DID_ECU_Core_Assembly_Read_Runnable DID_ECU_Core_Assembly_Read_Runnable
#  define RTE_RUNNABLE_DID_ECU_Delivery_Assembly_ConditionCheckRead_Runnable DID_ECU_Delivery_Assembly_ConditionCheckRead_Runnable
#  define RTE_RUNNABLE_DID_ECU_Delivery_Assembly_Read_Runnable DID_ECU_Delivery_Assembly_Read_Runnable
#  define RTE_RUNNABLE_Test_Runnable Test_Runnable
# endif

FUNC(void, Test_Component_CODE) ABS_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Test_Component_CODE) ABS_StatusUpdate(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Test_Component_CODE) DID_DID_ECU_Core_Assembly_ConditionCheckRead_Runnable(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Test_Component_CODE) DID_ECU_Core_Assembly_Read_Runnable(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Test_Component_CODE) DID_ECU_Core_Assembly_Read_Runnable(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Test_Component_CODE) DID_ECU_Delivery_Assembly_ConditionCheckRead_Runnable(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Test_Component_CODE) DID_ECU_Delivery_Assembly_Read_Runnable(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Test_Component_CODE) DID_ECU_Delivery_Assembly_Read_Runnable(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_TEST_COMPONENT_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Test_Component_CODE) Test_Runnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Test_Component_STOP_SEC_CODE
# include "Test_Component_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_ECU_Core_Assembly_No_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_Core_Assembly_No_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_Delivery_Assembly_No_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_Delivery_Assembly_No_Data_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TEST_COMPONENT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
