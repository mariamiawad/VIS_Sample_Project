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
 *          File:  Rte_Hook.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 * Not configured:
 *
 *  Rte_Task_Dispatch
 *  Rte_Task_WaitEventRet
 *  Rte_CallHook_Dcm_DataServices_ECU_Core_Assembly_No_Data_ConditionCheckRead_Return
 *  Rte_CallHook_Dcm_DataServices_ECU_Core_Assembly_No_Data_ConditionCheckRead_Start
 *  Rte_CallHook_Dcm_DataServices_ECU_Core_Assembly_No_Data_ReadData_Return
 *  Rte_CallHook_Dcm_DataServices_ECU_Core_Assembly_No_Data_ReadData_Start
 *  Rte_CallHook_Dcm_DataServices_ECU_Delivery_Assembly_No_Data_ConditionCheckRead_Return
 *  Rte_CallHook_Dcm_DataServices_ECU_Delivery_Assembly_No_Data_ConditionCheckRead_Start
 *  Rte_CallHook_Dcm_DataServices_ECU_Delivery_Assembly_No_Data_ReadData_Return
 *  Rte_CallHook_Dcm_DataServices_ECU_Delivery_Assembly_No_Data_ReadData_Start
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_RequestResults_Return
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_RequestResults_Start
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_Start_Return
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_Start_Start
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_Stop_Return
 *  Rte_CallHook_Dcm_RoutineServices_DcmDspRoutine_Stop_Start
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_ABSOLUTE_TIME_ReadData_Return
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_ABSOLUTE_TIME_ReadData_Start
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_AGING_COUNTER_ReadData_Return
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_AGING_COUNTER_ReadData_Start
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_KILOMETER_ReadData_Return
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_KILOMETER_ReadData_Start
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_OCCURRENCE_COUNTER_ReadData_Return
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_OCCURRENCE_COUNTER_ReadData_Start
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_OVERFLOW_BYTE_ReadData_Return
 *  Rte_CallHook_DemMaster_0_CBReadData_DemDataClass_OVERFLOW_BYTE_ReadData_Start
 *  Rte_CallHook_NvM_NvM_RpNotifyInit_Product_Life_Data_InitBlock_Return
 *  Rte_CallHook_NvM_NvM_RpNotifyInit_Product_Life_Data_InitBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_EraseBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_EraseBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_GetErrorStatus_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_GetErrorStatus_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_InvalidateNvBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_InvalidateNvBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_ReadBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_ReadBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_RestoreBlockDefaults_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_RestoreBlockDefaults_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_SetRamBlockStatus_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_SetRamBlockStatus_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_WriteBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_EEPROM_Version_WriteBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_EraseBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_EraseBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_GetErrorStatus_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_GetErrorStatus_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_InvalidateNvBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_InvalidateNvBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_ReadBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_ReadBlock_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_RestoreBlockDefaults_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_RestoreBlockDefaults_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_SetRamBlockStatus_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_SetRamBlockStatus_Start
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_WriteBlock_Return
 *  Rte_CallHook_Test_Component_NvMService_AC3_SRBS_Defs_Product_Life_WriteBlock_Start
 *  Rte_ComHook_CalibVersion_98325e63_SigTx
 *  Rte_ComHook_InverterCoolgFlowRate_451170b4_SigRx
 *  Rte_ReadHook_Test_Component_InverterCoolgFlowRate_EMDurationMaxESA_Return
 *  Rte_ReadHook_Test_Component_InverterCoolgFlowRate_EMDurationMaxESA_Start
 *  Rte_Runnable_BswM_BswM_MainFunction_Return
 *  Rte_Runnable_BswM_BswM_MainFunction_Start
 *  Rte_Runnable_BswM_BswM_Notification_Dcm_DiagSessionControl_RP_Return
 *  Rte_Runnable_BswM_BswM_Notification_Dcm_DiagSessionControl_RP_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Start
 *  Rte_Runnable_ComM_GetCurrentComMode_Return
 *  Rte_Runnable_ComM_GetCurrentComMode_Start
 *  Rte_Runnable_ComM_GetInhibitionStatus_Return
 *  Rte_Runnable_ComM_GetInhibitionStatus_Start
 *  Rte_Runnable_ComM_GetMaxComMode_Return
 *  Rte_Runnable_ComM_GetMaxComMode_Start
 *  Rte_Runnable_ComM_GetRequestedComMode_Return
 *  Rte_Runnable_ComM_GetRequestedComMode_Start
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Return
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Start
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Return
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Start
 *  Rte_Runnable_ComM_PreventWakeUp_Return
 *  Rte_Runnable_ComM_PreventWakeUp_Start
 *  Rte_Runnable_ComM_ReadInhibitCounter_Return
 *  Rte_Runnable_ComM_ReadInhibitCounter_Start
 *  Rte_Runnable_ComM_RequestComMode_Return
 *  Rte_Runnable_ComM_RequestComMode_Start
 *  Rte_Runnable_ComM_ResetInhibitCounter_Return
 *  Rte_Runnable_ComM_ResetInhibitCounter_Start
 *  Rte_Runnable_ComM_SetECUGroupClassification_Return
 *  Rte_Runnable_ComM_SetECUGroupClassification_Start
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Return
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Start
 *  Rte_Runnable_Dcm_GetActiveProtocol_Return
 *  Rte_Runnable_Dcm_GetActiveProtocol_Start
 *  Rte_Runnable_Dcm_GetRequestKind_Return
 *  Rte_Runnable_Dcm_GetRequestKind_Start
 *  Rte_Runnable_Dcm_GetSesCtrlType_Return
 *  Rte_Runnable_Dcm_GetSesCtrlType_Start
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Return
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Start
 *  Rte_Runnable_Dcm_SetActiveDiagnostic_Return
 *  Rte_Runnable_Dcm_SetActiveDiagnostic_Start
 *  Rte_Runnable_DemMaster_0_ClearDTC_Return
 *  Rte_Runnable_DemMaster_0_ClearDTC_Start
 *  Rte_Runnable_DemMaster_0_Dem_MasterMainFunction_Return
 *  Rte_Runnable_DemMaster_0_Dem_MasterMainFunction_Start
 *  Rte_Runnable_DemMaster_0_GetDTCOfEvent_Return
 *  Rte_Runnable_DemMaster_0_GetDTCOfEvent_Start
 *  Rte_Runnable_DemMaster_0_GetDTCStatusAvailabilityMask_Return
 *  Rte_Runnable_DemMaster_0_GetDTCStatusAvailabilityMask_Start
 *  Rte_Runnable_DemMaster_0_GetDebouncingOfEvent_Return
 *  Rte_Runnable_DemMaster_0_GetDebouncingOfEvent_Start
 *  Rte_Runnable_DemMaster_0_GetEventEnableCondition_Return
 *  Rte_Runnable_DemMaster_0_GetEventEnableCondition_Start
 *  Rte_Runnable_DemMaster_0_GetEventExtendedDataRecordEx_Return
 *  Rte_Runnable_DemMaster_0_GetEventExtendedDataRecordEx_Start
 *  Rte_Runnable_DemMaster_0_GetEventFailed_Return
 *  Rte_Runnable_DemMaster_0_GetEventFailed_Start
 *  Rte_Runnable_DemMaster_0_GetEventFreezeFrameDataEx_Return
 *  Rte_Runnable_DemMaster_0_GetEventFreezeFrameDataEx_Start
 *  Rte_Runnable_DemMaster_0_GetEventMemoryOverflow_Return
 *  Rte_Runnable_DemMaster_0_GetEventMemoryOverflow_Start
 *  Rte_Runnable_DemMaster_0_GetEventStatus_Return
 *  Rte_Runnable_DemMaster_0_GetEventStatus_Start
 *  Rte_Runnable_DemMaster_0_GetEventTested_Return
 *  Rte_Runnable_DemMaster_0_GetEventTested_Start
 *  Rte_Runnable_DemMaster_0_GetEventUdsStatus_Return
 *  Rte_Runnable_DemMaster_0_GetEventUdsStatus_Start
 *  Rte_Runnable_DemMaster_0_GetFaultDetectionCounter_Return
 *  Rte_Runnable_DemMaster_0_GetFaultDetectionCounter_Start
 *  Rte_Runnable_DemMaster_0_GetMonitorStatus_Return
 *  Rte_Runnable_DemMaster_0_GetMonitorStatus_Start
 *  Rte_Runnable_DemMaster_0_GetNumberOfEventMemoryEntries_Return
 *  Rte_Runnable_DemMaster_0_GetNumberOfEventMemoryEntries_Start
 *  Rte_Runnable_DemMaster_0_GetOperationCycleState_Return
 *  Rte_Runnable_DemMaster_0_GetOperationCycleState_Start
 *  Rte_Runnable_DemMaster_0_PostRunRequested_Return
 *  Rte_Runnable_DemMaster_0_PostRunRequested_Start
 *  Rte_Runnable_DemMaster_0_SelectDTC_Return
 *  Rte_Runnable_DemMaster_0_SelectDTC_Start
 *  Rte_Runnable_DemMaster_0_SetOperationCycleState_Return
 *  Rte_Runnable_DemMaster_0_SetOperationCycleState_Start
 *  Rte_Runnable_DemSatellite_0_Dem_SatelliteMainFunction_Return
 *  Rte_Runnable_DemSatellite_0_Dem_SatelliteMainFunction_Start
 *  Rte_Runnable_DemSatellite_0_GetDTCOfEvent_Return
 *  Rte_Runnable_DemSatellite_0_GetDTCOfEvent_Start
 *  Rte_Runnable_DemSatellite_0_GetDebouncingOfEvent_Return
 *  Rte_Runnable_DemSatellite_0_GetDebouncingOfEvent_Start
 *  Rte_Runnable_DemSatellite_0_GetEventEnableCondition_Return
 *  Rte_Runnable_DemSatellite_0_GetEventEnableCondition_Start
 *  Rte_Runnable_DemSatellite_0_GetEventExtendedDataRecordEx_Return
 *  Rte_Runnable_DemSatellite_0_GetEventExtendedDataRecordEx_Start
 *  Rte_Runnable_DemSatellite_0_GetEventFailed_Return
 *  Rte_Runnable_DemSatellite_0_GetEventFailed_Start
 *  Rte_Runnable_DemSatellite_0_GetEventFreezeFrameDataEx_Return
 *  Rte_Runnable_DemSatellite_0_GetEventFreezeFrameDataEx_Start
 *  Rte_Runnable_DemSatellite_0_GetEventStatus_Return
 *  Rte_Runnable_DemSatellite_0_GetEventStatus_Start
 *  Rte_Runnable_DemSatellite_0_GetEventTested_Return
 *  Rte_Runnable_DemSatellite_0_GetEventTested_Start
 *  Rte_Runnable_DemSatellite_0_GetEventUdsStatus_Return
 *  Rte_Runnable_DemSatellite_0_GetEventUdsStatus_Start
 *  Rte_Runnable_DemSatellite_0_GetFaultDetectionCounter_Return
 *  Rte_Runnable_DemSatellite_0_GetFaultDetectionCounter_Start
 *  Rte_Runnable_DemSatellite_0_GetMonitorStatus_Return
 *  Rte_Runnable_DemSatellite_0_GetMonitorStatus_Start
 *  Rte_Runnable_DemSatellite_0_ResetEventDebounceStatus_Return
 *  Rte_Runnable_DemSatellite_0_ResetEventDebounceStatus_Start
 *  Rte_Runnable_DemSatellite_0_ResetEventStatus_Return
 *  Rte_Runnable_DemSatellite_0_ResetEventStatus_Start
 *  Rte_Runnable_DemSatellite_0_SetEventStatus_Return
 *  Rte_Runnable_DemSatellite_0_SetEventStatus_Start
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Return
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Start
 *  Rte_Runnable_EcuM_GetBootTarget_Return
 *  Rte_Runnable_EcuM_GetBootTarget_Start
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetShutdownCause_Return
 *  Rte_Runnable_EcuM_GetShutdownCause_Start
 *  Rte_Runnable_EcuM_GetShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetShutdownTarget_Start
 *  Rte_Runnable_EcuM_SelectBootTarget_Return
 *  Rte_Runnable_EcuM_SelectBootTarget_Start
 *  Rte_Runnable_EcuM_SelectShutdownCause_Return
 *  Rte_Runnable_EcuM_SelectShutdownCause_Start
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Return
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Start
 *  Rte_Runnable_NvM_EraseBlock_Return
 *  Rte_Runnable_NvM_EraseBlock_Start
 *  Rte_Runnable_NvM_GetErrorStatus_Return
 *  Rte_Runnable_NvM_GetErrorStatus_Start
 *  Rte_Runnable_NvM_InvalidateNvBlock_Return
 *  Rte_Runnable_NvM_InvalidateNvBlock_Start
 *  Rte_Runnable_NvM_NvM_MainFunction_Return
 *  Rte_Runnable_NvM_NvM_MainFunction_Start
 *  Rte_Runnable_NvM_ReadBlock_Return
 *  Rte_Runnable_NvM_ReadBlock_Start
 *  Rte_Runnable_NvM_RestoreBlockDefaults_Return
 *  Rte_Runnable_NvM_RestoreBlockDefaults_Start
 *  Rte_Runnable_NvM_SetBlockProtection_Return
 *  Rte_Runnable_NvM_SetBlockProtection_Start
 *  Rte_Runnable_NvM_SetRamBlockStatus_Return
 *  Rte_Runnable_NvM_SetRamBlockStatus_Start
 *  Rte_Runnable_NvM_WriteBlock_Return
 *  Rte_Runnable_NvM_WriteBlock_Start
 *  Rte_Runnable_Test_Component_ABS_MainFunction_Return
 *  Rte_Runnable_Test_Component_ABS_MainFunction_Start
 *  Rte_Runnable_Test_Component_ABS_StatusUpdate_Return
 *  Rte_Runnable_Test_Component_ABS_StatusUpdate_Start
 *  Rte_Runnable_Test_Component_DID_DID_ECU_Core_Assembly_ConditionCheckRead_Runnable_Return
 *  Rte_Runnable_Test_Component_DID_DID_ECU_Core_Assembly_ConditionCheckRead_Runnable_Start
 *  Rte_Runnable_Test_Component_DID_ECU_Core_Assembly_Read_Runnable_Return
 *  Rte_Runnable_Test_Component_DID_ECU_Core_Assembly_Read_Runnable_Start
 *  Rte_Runnable_Test_Component_DID_ECU_Delivery_Assembly_ConditionCheckRead_Runnable_Return
 *  Rte_Runnable_Test_Component_DID_ECU_Delivery_Assembly_ConditionCheckRead_Runnable_Start
 *  Rte_Runnable_Test_Component_DID_ECU_Delivery_Assembly_Read_Runnable_Return
 *  Rte_Runnable_Test_Component_DID_ECU_Delivery_Assembly_Read_Runnable_Start
 *  Rte_Runnable_Test_Component_Test_Runnable_Return
 *  Rte_Runnable_Test_Component_Test_Runnable_Start
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start
 *  Rte_Task_Activate
 *  Rte_Task_SetEvent
 *  Rte_Task_WaitEvent
 *  Rte_WriteHook_Test_Component_CalibVer_CalibVer_Return
 *  Rte_WriteHook_Test_Component_CalibVer_CalibVer_Start
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanNm_CANNM_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_EnterHook_Dcm_DCM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Dcm_DCM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_Dem_DEM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_Det_DET_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Det_DET_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Fee_FEE_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Fee_FEE_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Nm_NM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Nm_NM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Nm_NM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Nm_NM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_NvM_NVM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_NvM_NVM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanNm_CANNM_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_ExitHook_Dcm_DCM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Dcm_DCM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_Dem_DEM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_Det_DET_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Det_DET_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Fee_FEE_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Fee_FEE_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Nm_NM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Nm_NM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Nm_NM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Nm_NM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_NvM_NVM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_NvM_NVM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_Schedulable_BswM_BswM_MainFunction_Return
 *  SchM_Schedulable_BswM_BswM_MainFunction_Start
 *  SchM_Schedulable_CanNm_CanNm_MainFunction_Return
 *  SchM_Schedulable_CanNm_CanNm_MainFunction_Start
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Return
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Start
 *  SchM_Schedulable_CanTp_CanTp_MainFunction_Return
 *  SchM_Schedulable_CanTp_CanTp_MainFunction_Start
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Return
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Start
 *  SchM_Schedulable_Com_Com_MainFunctionRx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionRx_Start
 *  SchM_Schedulable_Com_Com_MainFunctionTx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionTx_Start
 *  SchM_Schedulable_Dcm_Dcm_MainFunction_Return
 *  SchM_Schedulable_Dcm_Dcm_MainFunction_Start
 *  SchM_Schedulable_Dem_Dem_MasterMainFunction_Return
 *  SchM_Schedulable_Dem_Dem_MasterMainFunction_Start
 *  SchM_Schedulable_Dem_Dem_SatelliteMainFunction_Return
 *  SchM_Schedulable_Dem_Dem_SatelliteMainFunction_Start
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Return
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Start
 *  SchM_Schedulable_Fee_Fee_MainFunction_Return
 *  SchM_Schedulable_Fee_Fee_MainFunction_Start
 *  SchM_Schedulable_Fls_Fls_MainFunction_Return
 *  SchM_Schedulable_Fls_Fls_MainFunction_Start
 *  SchM_Schedulable_NvM_NvM_MainFunction_Return
 *  SchM_Schedulable_NvM_NvM_MainFunction_Start
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Return
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HOOK_H
# define _RTE_HOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

# define RTE_START_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_STOP_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_HOOK_H */

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
