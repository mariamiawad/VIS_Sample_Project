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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2019-11-13 15:54:55
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
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA S 0342 EOF */ /* MD_Com_0342 */
/* PRQA S 0612 EOF */ /* MD_Com_0612 */
/* PRQA S 0639 EOF */ /* MD_MSR_1.1_639 */
/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 2006 EOF */ /* MD_MSR_14.7 */
/* PRQA S 3109 EOF */ /* MD_MSR_14.3 */
/* PRQA S 3453 EOF */ /* MD_CSL_3453 */
/* PRQA S 3458 EOF */ /* MD_MSR_19.4 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"


#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1] = {
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000U   /* [/ActiveEcuC/Com/ComConfig/EMSpeedGradientESAInitValue, /ActiveEcuC/Com/ComConfig/EMSpeedGradientESARxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/IDCMax_2882480fInitValue, /ActiveEcuC/Com/ComConfig/IDCMax_2882480fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/IDCMin_2882480fInitValue, /ActiveEcuC/Com/ComConfig/IDCMin_2882480fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SpdGrdtLim_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/SpdGrdtLim_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SpdReq_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/SpdReq_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TqGrdtLim_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/TqGrdtLim_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TqMax_2882480fInitValue, /ActiveEcuC/Com/ComConfig/TqMax_2882480fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TqMin_2882480fInitValue, /ActiveEcuC/Com/ComConfig/TqMin_2882480fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TqReq_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/TqReq_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/UDCMax_Lim0Nm_451170b4InitValue, /ActiveEcuC/Com/ComConfig/UDCMax_Lim0Nm_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/UDCMax_Unlim_2882480fInitValue, /ActiveEcuC/Com/ComConfig/UDCMax_Unlim_2882480fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/UDCMin_Lim0Nm_451170b4InitValue, /ActiveEcuC/Com/ComConfig/UDCMin_Lim0Nm_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/UDCMin_Unlim_2882480fInitValue, /ActiveEcuC/Com/ComConfig/UDCMin_Unlim_2882480fRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1] = {
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */      0x00000000UL   /* [/ActiveEcuC/Com/ComConfig/NotUsed1_1_fb8d44d5InitValue, /ActiveEcuC/Com/ComConfig/NotUsed1_1_fb8d44d5RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed1_2_fb8d44d5InitValue, /ActiveEcuC/Com/ComConfig/NotUsed1_2_fb8d44d5RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed2_1_75024336InitValue, /ActiveEcuC/Com/ComConfig/NotUsed2_1_75024336RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed2_2_75024336InitValue, /ActiveEcuC/Com/ComConfig/NotUsed2_2_75024336RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed3_1_b9a843a8InitValue, /ActiveEcuC/Com/ComConfig/NotUsed3_1_b9a843a8RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed3_2_b9a843a8InitValue, /ActiveEcuC/Com/ComConfig/NotUsed3_2_b9a843a8RxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1] = {
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x00U   /* [/ActiveEcuC/Com/ComConfig/EMDurationMaxESAInitValue, /ActiveEcuC/Com/ComConfig/EMDurationMaxESARxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EMEndSpeedESAInitValue, /ActiveEcuC/Com/ComConfig/EMEndSpeedESARxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/EMTorqueLimitESAInitValue, /ActiveEcuC/Com/ComConfig/EMTorqueLimitESARxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/InverterCoolgFlowRate_451170b4InitValue, /ActiveEcuC/Com/ComConfig/InverterCoolgFlowRate_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/InverterCoolgT_451170b4InitValue, /ActiveEcuC/Com/ComConfig/InverterCoolgT_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ModReq_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/ModReq_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed1_34a7daa1InitValue, /ActiveEcuC/Com/ComConfig/NotUsed1_34a7daa1RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/NotUsed2_451170b4InitValue, /ActiveEcuC/Com/ComConfig/NotUsed2_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/OilFlowRate_451170b4InitValue, /ActiveEcuC/Com/ComConfig/OilFlowRate_451170b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/OilT_451170b4InitValue, /ActiveEcuC/Com/ComConfig/OilT_451170b4RxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[2] = {
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x02U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*     1 */         0x01U   /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                              Description
  InitValueUsed                        TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  ApplType                             Application data type.
  BitLength                            Bit length of the signal or group signal.
  BitPosition                          Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                            the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  BusAcc                               BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                           Byte length of the signal or group signal.
  BytePosition                         Little endian byte position of the signal or group signal within the I-PDU.
  RxDataTimeoutSubstitutionValueIdx    the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxPduInfoIdx                         the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition               Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[29] = {
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BufferIdx  BusAcc                                 ByteLength  BytePosition  RxDataTimeoutSubstitutionValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        5U,         34U,        0U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           4U,                                0U,           6U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/EMDurationMaxESA, /ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*     1 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        7U,         16U,        1U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           2U,                                0U,           6U,                     2U },  /* [/ActiveEcuC/Com/ComConfig/EMEndSpeedESA, /ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*     2 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         56U,        0U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U,                                0U,           6U,                     6U },  /* [/ActiveEcuC/Com/ComConfig/EMSpeedGradientESA, /ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*     3 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         50U,        2U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           6U,                                0U,           6U,                     6U },  /* [/ActiveEcuC/Com/ComConfig/EMTorqueLimitESA, /ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*     4 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         27U,        1U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           3U,                                0U,           1U,                     2U },  /* [/ActiveEcuC/Com/ComConfig/IDCMax_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*     5 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,        9U,         34U,        2U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           4U,                                0U,           1U,                     3U },  /* [/ActiveEcuC/Com/ComConfig/IDCMin_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*     6 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,        3U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           2U,                                0U,           0U,                     2U },  /* [/ActiveEcuC/Com/ComConfig/InverterCoolgFlowRate_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     7 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,        4U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           0U,                                0U,           0U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/InverterCoolgT_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     8 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,        5U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           0U,                                0U,           2U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/ModReq_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*     9 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         24U,        0U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           3U,                                0U,           3U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_1_fb8d44d5, /ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  { /*    10 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         56U,        1U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           7U,                                0U,           3U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_2_fb8d44d5, /ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  { /*    11 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         56U,        6U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U,                                0U,           2U,                     7U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    12 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         24U,        2U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           3U,                                0U,           4U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_1_75024336, /ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  { /*    13 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         56U,        3U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           7U,                                0U,           4U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_2_75024336, /ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  { /*    14 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,         56U,        7U,         COM_NBIT_BUSACCOFRXACCESSINFO,         0U,           7U,                                0U,           0U,                     7U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*    15 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         24U,        4U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           3U,                                0U,           5U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed3_1_b9a843a8, /ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  { /*    16 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         56U,        5U,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         4U,           7U,                                0U,           5U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed3_2_b9a843a8, /ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  { /*    17 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         24U,        8U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           3U,                                0U,           0U,                     3U },  /* [/ActiveEcuC/Com/ComConfig/OilFlowRate_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*    18 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          8U,        9U,         COM_BYTE_BUSACCOFRXACCESSINFO,         1U,           1U,                                0U,           0U,                     1U },  /* [/ActiveEcuC/Com/ComConfig/OilT_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*    19 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       11U,         59U,        3U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U,                                0U,           2U,                     6U },  /* [/ActiveEcuC/Com/ComConfig/SpdGrdtLim_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    20 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       15U,         54U,        4U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           6U,                                0U,           2U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/SpdReq_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    21 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         37U,        5U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         2U,           4U,                                0U,           2U,                     2U },  /* [/ActiveEcuC/Com/ComConfig/TqGrdtLim_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    22 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         14U,        6U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           1U,                                0U,           1U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/TqMax_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    23 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       10U,         20U,        7U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           2U,                                0U,           1U,                     1U },  /* [/ActiveEcuC/Com/ComConfig/TqMin_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    24 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       11U,         21U,        8U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           2U,                                0U,           2U,                     1U },  /* [/ActiveEcuC/Com/ComConfig/TqReq_34a7daa1, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    25 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13U,         43U,        9U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           5U,                                0U,           0U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/UDCMax_Lim0Nm_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*    26 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13U,         53U,       10U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           6U,                                0U,           1U,                     4U },  /* [/ActiveEcuC/Com/ComConfig/UDCMax_Unlim_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    27 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13U,         62U,       11U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U,                                0U,           0U,                     5U },  /* [/ActiveEcuC/Com/ComConfig/UDCMin_Lim0Nm_451170b4, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*    28 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13U,         56U,       12U, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1U,           7U,                                0U,           1U,                     6U }   /* [/ActiveEcuC/Com/ComConfig/UDCMin_Unlim_2882480f, /ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[29] = {
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               6U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     1 */               7U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     2 */              14U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     3 */              17U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     4 */              18U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     5 */              25U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     6 */              27U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     7 */               4U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*     8 */               5U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*     9 */              22U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    10 */              23U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    11 */              26U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    12 */              28U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    13 */               8U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    14 */              11U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    15 */              19U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    16 */              20U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    17 */              21U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    18 */              24U,  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    19 */               9U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    20 */              10U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    21 */              12U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    22 */              13U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    23 */              15U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    24 */              16U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    25 */               0U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  /*    26 */               1U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  /*    27 */               2U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  /*    28 */               3U   /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[7] = {
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   1U },
  { /*     1 */                   1U },
  { /*     2 */                   1U },
  { /*     3 */                   1U },
  { /*     4 */                   1U },
  { /*     5 */                   1U },
  { /*     6 */                   1U }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxDefPduBufferUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer
  RxSigInfoUsed             TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo
  HandleRxPduDeferredIdx    the index of the 0:1 relation pointing to Com_HandleRxPduDeferred
  RxDefPduBufferEndIdx      the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  SignalProcessing          Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion.
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[7] = {
    /* Index    RxDefPduBufferUsed  RxSigInfoUsed  HandleRxPduDeferredIdx                    RxDefPduBufferEndIdx                    RxDefPduBufferStartIdx                    RxSigInfoEndIdx  RxSigInfoStartIdx  SignalProcessing                           Type                              Referable Keys */
  { /*     0 */               TRUE,          TRUE,                                       0U,                                     8U,                                       0U,              7U,                0U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     1 */               TRUE,          TRUE,                                       1U,                                    16U,                                       8U,             13U,                7U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     2 */               TRUE,          TRUE,                                       2U,                                    24U,                                      16U,             19U,               13U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     3 */               TRUE,          TRUE,                                       3U,                                    32U,                                      24U,             21U,               19U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     4 */               TRUE,          TRUE,                                       4U,                                    40U,                                      32U,             23U,               21U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     5 */               TRUE,          TRUE,                                       5U,                                    48U,                                      40U,             25U,               23U,  COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  { /*     6 */              FALSE,          TRUE, COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO, COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO, COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO,             29U,               25U, COM_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[29] = {
    /* Index    RxAccessInfoIdx  SignalProcessing                           ValidDlc        Referable Keys */
  { /*     0 */              6U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     1 */              7U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     2 */             14U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     3 */             17U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     4 */             18U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     5 */             25U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     6 */             27U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  { /*     7 */              4U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*     8 */              5U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*     9 */             22U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    10 */             23U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    11 */             26U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    12 */             28U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  { /*    13 */              8U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    14 */             11U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    15 */             19U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    16 */             20U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    17 */             21U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    18 */             24U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  { /*    19 */              9U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  { /*    20 */             10U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  { /*    21 */             12U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  { /*    22 */             13U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  { /*    23 */             15U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  { /*    24 */             16U,  COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  { /*    25 */              0U, COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*    26 */              1U, COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*    27 */              2U, COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
  { /*    28 */              3U, COM_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO,       7U }   /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  TimeOffset    Initial time offset factor for cyclic transmission.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[6] = {
    /* Index    TimeOffset  TimePeriod        Referable Keys */
  { /*     0 */         2U,         2U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  { /*     1 */         2U,         8U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     2 */         2U,         6U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     3 */         2U,        10U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*     4 */         1U,         0U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*     5 */         2U,         4U }   /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element            Description
  TxModeFalseUsed    TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeFalse
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[6] = {
    /* Index    TxModeFalseUsed        Referable Keys */
  { /*     0 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  { /*     1 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     2 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     3 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*     4 */            TRUE },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*     5 */            TRUE }   /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimeOffset    Initial time offset factor for cyclic transmission.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[6] = {
    /* Index    TimeOffset  TimePeriod        Referable Keys */
  { /*     0 */         2U,         2U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  { /*     1 */         2U,         8U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     2 */         2U,         6U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     3 */         2U,        10U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*     4 */         1U,         0U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*     5 */         2U,         4U }   /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[6] = {
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   0U },
  { /*     1 */                   0U },
  { /*     2 */                   0U },
  { /*     3 */                   0U },
  { /*     4 */                   0U },
  { /*     5 */                   0U }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                   Description
  TxPduInitValueUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                External ID used to call PduR_ComTransmit().
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx      the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx    the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[6] = {
    /* Index    TxPduInitValueUsed  ExternalId                                                     TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */               TRUE,          PduRConf_PduRSrcPdu_SRC_Can_PT_RESERVED_ID5_0fb271d2,             8U,                   8U,                     0U },  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  { /*     1 */               TRUE, PduRConf_PduRSrcPdu_SRC_Can_PT_SCU_DATA_AVAILABILITY_0fb271d2,             8U,                  16U,                     8U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  { /*     2 */               TRUE,         PduRConf_PduRSrcPdu_SRC_Can_PT_SCU_DATA_DIAG_0fb271d2,             8U,                  24U,                    16U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  { /*     3 */               TRUE,       PduRConf_PduRSrcPdu_SRC_Can_PT_SCU_DATA_STATUS_0fb271d2,             8U,                  32U,                    24U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  { /*     4 */               TRUE,                                PduRConf_PduRSrcPdu_PduRSrcPdu,             8U,                  40U,                    32U },  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  { /*     5 */               TRUE,        PduRConf_PduRSrcPdu_SRC_Can_PT_SCU_MOTOR_DIAG_0fb271d2,             8U,                  48U,                    40U }   /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[48] = {
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     1 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     2 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     3 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     4 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     5 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     6 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     7 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  /*     8 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*     9 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    10 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    11 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    12 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    13 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    14 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    15 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  /*    16 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    17 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    18 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    19 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    20 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    21 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    22 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    23 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  /*    24 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    25 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    26 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    27 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    28 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    29 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    30 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    31 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  /*    32 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    33 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    34 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    35 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    36 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    37 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    38 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    39 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    40 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    41 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    42 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    43 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    44 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    45 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    46 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  /*    47 */           0x00U   /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[98] = {
    /* Index    ApplType                        BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         48U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/CAN_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     1 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         37U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/CPLD_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     2 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,         56U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            24U,              23U,           2U },  /* [/ActiveEcuC/Com/ComConfig/CalibVersion_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*     3 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         15U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            34U,              33U,           4U },  /* [/ActiveEcuC/Com/ComConfig/CarMode, /ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*     4 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          0U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            33U,              32U,           4U },  /* [/ActiveEcuC/Com/ComConfig/CarModeHS, /ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*     5 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         41U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            14U,              13U,           1U },  /* [/ActiveEcuC/Com/ComConfig/CtrlBdDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     6 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           2U,                     2U,            11U,              10U,           1U },  /* [/ActiveEcuC/Com/ComConfig/CtrlBdT_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     7 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            14U,              13U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcCtrlBdDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     8 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         63U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            16U,              15U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcIDCCANDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*     9 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         50U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcMaxSpdDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    10 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         54U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcPwrModuleDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    11 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         52U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcRotorDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    12 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         42U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            14U,              13U,           1U },  /* [/ActiveEcuC/Com/ComConfig/EfcStatorDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    13 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         48U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/IDCCANDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    14 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         63U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           7U,                     5U,            32U,              29U,           3U },  /* [/ActiveEcuC/Com/ComConfig/IDCEstimd_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    15 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         51U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/MaxSpdDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    16 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,            25U,              24U,           3U },  /* [/ActiveEcuC/Com/ComConfig/ModSts_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    17 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        7U,         56U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            32U,              31U,           3U },  /* [/ActiveEcuC/Com/ComConfig/MsgCntr_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    18 */ COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         24U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         4U,           3U,                     0U,             4U,               0U,           0U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed5_1_7fc74a2f, /ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  { /*    19 */ COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         56U,     COM_NBYTE_SW_BUSACCOFTXSIGINFO,         4U,           7U,                     4U,             8U,               4U,           0U },  /* [/ActiveEcuC/Com/ComConfig/NotUsed5_2_7fc74a2f, /ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be] */
  { /*    20 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         51U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_DC_CAN_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    21 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          3U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    22 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          2U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_U_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    23 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          1U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_V_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    24 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          0U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_W_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    25 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         15U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_X_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    26 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         14U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_Y_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    27 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         13U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_Z_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    28 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         26U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_1_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    29 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         25U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_2_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    30 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         24U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_3_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    31 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         39U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_4_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    32 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         38U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_5_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    33 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         12U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    34 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         22U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    35 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         16U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    36 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         11U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    37 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         21U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    38 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         31U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    39 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         10U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    40 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         20U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    41 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         30U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    42 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          9U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    43 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         19U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    44 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         29U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    45 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          8U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           1U,                     1U,            18U,              17U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    46 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         18U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    47 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         28U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    48 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         23U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_FAST_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    49 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         17U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           2U,                     2U,            19U,              18U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_MED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
    /* Index    ApplType                        BitLength  BitPosition  BusAcc                              ByteLength  BytePosition  StartByteInPduPosition  TxBufferEndIdx  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*    50 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         27U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           3U,                     3U,            20U,              19U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    51 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         49U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_SPEED_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    52 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          6U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_TEMP_CMD_BOARD_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    53 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          7U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_TEMP_PWR_MODULES_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    54 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          4U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_TEMP_ROTOR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    55 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,          5U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           0U,                     0U,            17U,              16U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_TEMP_STATOR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    56 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         32U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_DC_48V_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    57 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         50U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_DC_CAN_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    58 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         33U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    59 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        7U,         56U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            16U,              15U,           1U },  /* [/ActiveEcuC/Com/ComConfig/OilFlowReq_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    60 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         49U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/OverIACAnticip_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    61 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         34U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_ERROR_H_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    62 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         36U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_ERROR_L_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    63 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         35U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            21U,              20U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_ERROR_M_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    64 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         43U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_U_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    65 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         42U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_V_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    66 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         41U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_W_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    67 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_X_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    68 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         55U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_Y_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    69 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         54U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/PHASE_Z_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    70 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         63U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            24U,              23U,           2U },  /* [/ActiveEcuC/Com/ComConfig/POSITION_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    71 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         33U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           4U,                     4U,            37U,              36U,           4U },  /* [/ActiveEcuC/Com/ComConfig/PowerMode, /ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*    72 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        5U,         40U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            38U,              37U,           4U },  /* [/ActiveEcuC/Com/ComConfig/PowerMode2, /ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  { /*    73 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         55U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/PwrModuleDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    74 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           1U,                     1U,            10U,               9U,           1U },  /* [/ActiveEcuC/Com/ComConfig/PwrModuleT_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    75 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         53U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            15U,              14U,           1U },  /* [/ActiveEcuC/Com/ComConfig/RotorDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    76 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         52U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/SPEED_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    77 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       15U,         36U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           4U,                     2U,            29U,              26U,           3U },  /* [/ActiveEcuC/Com/ComConfig/SpdMeas_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    78 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         43U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            14U,              13U,           1U },  /* [/ActiveEcuC/Com/ComConfig/StatorDerating_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    79 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,         COM_BYTE_BUSACCOFTXSIGINFO,         1U,           0U,                     0U,             9U,               8U,           1U },  /* [/ActiveEcuC/Com/ComConfig/StatorT_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    80 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        3U,         59U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            24U,              23U,           2U },  /* [/ActiveEcuC/Com/ComConfig/SwVersion_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    81 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         45U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/TEMP_CMD_BOARD_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    82 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         46U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/TEMP_PWR_MODULES_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    83 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         53U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           6U,                     6U,            23U,              22U,           2U },  /* [/ActiveEcuC/Com/ComConfig/TEMP_STATOR_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    84 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         62U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           7U,                     7U,            24U,              23U,           2U },  /* [/ActiveEcuC/Com/ComConfig/TRIM_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    85 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       11U,         41U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,            30U,              28U,           3U },  /* [/ActiveEcuC/Com/ComConfig/TrqEstimd_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    86 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         38U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           4U,                     3U,            13U,              11U,           1U },  /* [/ActiveEcuC/Com/ComConfig/TrqMaxAllwdEstimd_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    87 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         44U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,            14U,              12U,           1U },  /* [/ActiveEcuC/Com/ComConfig/TrqMinAllwdEstimd_244f648b, /ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be] */
  { /*    88 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       13U,         19U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           2U,                     1U,            27U,              25U,           3U },  /* [/ActiveEcuC/Com/ComConfig/UDCMeas_42f7a63c, /ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be] */
  { /*    89 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         47U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/UNDER_VOLTAGE_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    90 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        1U,         44U,         COM_NBIT_BUSACCOFTXSIGINFO,         0U,           5U,                     5U,            22U,              21U,           2U },  /* [/ActiveEcuC/Com/ComConfig/VOLTAGE_SENSOR_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be] */
  { /*    91 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         43U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           5U,                     4U,            46U,              44U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pIdSetpoint_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    92 */  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         28U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           3U,                     2U,            44U,              42U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pId_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    93 */ COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         50U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           6U,                     5U,            47U,              45U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pIqSetpoint_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    94 */ COM_UINT16_APPLTYPEOFTXSIGINFO,        9U,         35U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           4U,                     3U,            45U,              43U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pIq_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    95 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         56U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           7U,                     6U,            48U,              46U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pTrqSetPoint_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    96 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         14U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           1U,                     0U,            42U,              40U,           5U },  /* [/ActiveEcuC/Com/ComConfig/pVd_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
  { /*    97 */ COM_UINT16_APPLTYPEOFTXSIGINFO,       10U,         20U, COM_NBITNBYTE_SW_BUSACCOFTXSIGINFO,         1U,           2U,                     1U,            43U,              41U,           5U }   /* [/ActiveEcuC/Com/ComConfig/pVq_3037eb73, /ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayDescriptionProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayDescriptionProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayDescriptionProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GwEventCacheIndex
**********************************************************************************************************************/
/** 
  \var    Com_GwEventCacheIndex
  \brief  Index for deferred gw description event cache
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GwEventCacheIndexType, COM_VAR_NOINIT) Com_GwEventCacheIndex;
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[7];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_INFORMATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_LIMITATION_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MASTER_CTRL_REQ_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID1_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID2_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID3_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_RX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Rx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[13];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/EMSpeedGradientESA, /ActiveEcuC/Com/ComConfig/EMSpeedGradientESA_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/IDCMax_2882480f, /ActiveEcuC/Com/ComConfig/IDCMax_2882480f_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/IDCMin_2882480f, /ActiveEcuC/Com/ComConfig/IDCMin_2882480f_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SpdGrdtLim_34a7daa1, /ActiveEcuC/Com/ComConfig/SpdGrdtLim_34a7daa1_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SpdReq_34a7daa1, /ActiveEcuC/Com/ComConfig/SpdReq_34a7daa1_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/TqGrdtLim_34a7daa1, /ActiveEcuC/Com/ComConfig/TqGrdtLim_34a7daa1_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/TqMax_2882480f, /ActiveEcuC/Com/ComConfig/TqMax_2882480f_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/TqMin_2882480f, /ActiveEcuC/Com/ComConfig/TqMin_2882480f_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/TqReq_34a7daa1, /ActiveEcuC/Com/ComConfig/TqReq_34a7daa1_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/UDCMax_Lim0Nm_451170b4, /ActiveEcuC/Com/ComConfig/UDCMax_Lim0Nm_451170b4_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/UDCMax_Unlim_2882480f, /ActiveEcuC/Com/ComConfig/UDCMax_Unlim_2882480f_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/UDCMin_Lim0Nm_451170b4, /ActiveEcuC/Com/ComConfig/UDCMin_Lim0Nm_451170b4_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/UDCMin_Unlim_2882480f, /ActiveEcuC/Com/ComConfig/UDCMin_Unlim_2882480f_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_1_fb8d44d5, /ActiveEcuC/Com/ComConfig/NotUsed1_1_fb8d44d5_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_2_fb8d44d5, /ActiveEcuC/Com/ComConfig/NotUsed1_2_fb8d44d5_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_1_75024336, /ActiveEcuC/Com/ComConfig/NotUsed2_1_75024336_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_2_75024336, /ActiveEcuC/Com/ComConfig/NotUsed2_2_75024336_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed3_1_b9a843a8, /ActiveEcuC/Com/ComConfig/NotUsed3_1_b9a843a8_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed3_2_b9a843a8, /ActiveEcuC/Com/ComConfig/NotUsed3_2_b9a843a8_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[10];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/EMDurationMaxESA, /ActiveEcuC/Com/ComConfig/EMDurationMaxESA_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EMEndSpeedESA, /ActiveEcuC/Com/ComConfig/EMEndSpeedESA_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/EMTorqueLimitESA, /ActiveEcuC/Com/ComConfig/EMTorqueLimitESA_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/InverterCoolgFlowRate_451170b4, /ActiveEcuC/Com/ComConfig/InverterCoolgFlowRate_451170b4_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/InverterCoolgT_451170b4, /ActiveEcuC/Com/ComConfig/InverterCoolgT_451170b4_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ModReq_34a7daa1, /ActiveEcuC/Com/ComConfig/ModReq_34a7daa1_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed1_34a7daa1, /ActiveEcuC/Com/ComConfig/NotUsed1_34a7daa1_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/NotUsed2_451170b4, /ActiveEcuC/Com/ComConfig/NotUsed2_451170b4_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/OilFlowRate_451170b4, /ActiveEcuC/Com/ComConfig/OilFlowRate_451170b4_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/OilT_451170b4, /ActiveEcuC/Com/ComConfig/OilT_451170b4_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[48];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_1_7fc74a2f] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_1_7fc74a2f] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_1_7fc74a2f] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_1_7fc74a2f] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_2_7fc74a2f] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_2_7fc74a2f] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_2_7fc74a2f] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/NotUsed5_2_7fc74a2f] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/StatorT_244f648b] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/PwrModuleT_244f648b] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/CtrlBdT_244f648b] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/TrqMaxAllwdEstimd_244f648b] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/TrqMaxAllwdEstimd_244f648b, /ActiveEcuC/Com/ComConfig/TrqMinAllwdEstimd_244f648b] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/CtrlBdDerating_244f648b, /ActiveEcuC/Com/ComConfig/EfcCtrlBdDerating_244f648b, /ActiveEcuC/Com/ComConfig/EfcStatorDerating_244f648b, /ActiveEcuC/Com/ComConfig/StatorDerating_244f648b, /ActiveEcuC/Com/ComConfig/TrqMinAllwdEstimd_244f648b] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EfcMaxSpdDerating_244f648b, /ActiveEcuC/Com/ComConfig/EfcPwrModuleDerating_244f648b, /ActiveEcuC/Com/ComConfig/EfcRotorDerating_244f648b, /ActiveEcuC/Com/ComConfig/IDCCANDerating_244f648b, /ActiveEcuC/Com/ComConfig/MaxSpdDerating_244f648b, /ActiveEcuC/Com/ComConfig/OverIACAnticip_244f648b, /ActiveEcuC/Com/ComConfig/PwrModuleDerating_244f648b, /ActiveEcuC/Com/ComConfig/RotorDerating_244f648b] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/EfcIDCCANDerating_244f648b, /ActiveEcuC/Com/ComConfig/OilFlowReq_244f648b] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_U_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_V_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_W_98325e63, /ActiveEcuC/Com/ComConfig/OVER_TEMP_CMD_BOARD_98325e63, /ActiveEcuC/Com/ComConfig/OVER_TEMP_PWR_MODULES_98325e63, /ActiveEcuC/Com/ComConfig/OVER_TEMP_ROTOR_98325e63, /ActiveEcuC/Com/ComConfig/OVER_TEMP_STATOR_98325e63] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_X_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_Y_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PEAK_PHASE_Z_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_FAST_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_FAST_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_FAST_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_FAST_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_FAST_98325e63] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_MED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_U_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_MED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_MED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_MED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_MED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_FAST_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_MED_98325e63] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_1_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_2_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_3_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_V_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_W_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_X_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Y_SLOW_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_Z_SLOW_98325e63] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/CPLD_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_4_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_PHASE_RMS_5_98325e63, /ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_DC_48V_98325e63, /ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_ERROR_H_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_ERROR_L_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_ERROR_M_98325e63] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/PHASE_U_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_V_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_W_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_X_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/TEMP_CMD_BOARD_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/TEMP_PWR_MODULES_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/UNDER_VOLTAGE_HW_48V_98325e63, /ActiveEcuC/Com/ComConfig/VOLTAGE_SENSOR_ERROR_98325e63] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/CAN_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/OVER_CURRENT_DC_CAN_98325e63, /ActiveEcuC/Com/ComConfig/OVER_SPEED_98325e63, /ActiveEcuC/Com/ComConfig/OVER_VOLTAGE_DC_CAN_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_Y_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/PHASE_Z_CURRENT_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SPEED_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/TEMP_STATOR_ERROR_98325e63] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/CalibVersion_98325e63, /ActiveEcuC/Com/ComConfig/POSITION_ERROR_98325e63, /ActiveEcuC/Com/ComConfig/SwVersion_98325e63, /ActiveEcuC/Com/ComConfig/TRIM_ERROR_98325e63] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/ModSts_42f7a63c] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/UDCMeas_42f7a63c] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SpdMeas_42f7a63c, /ActiveEcuC/Com/ComConfig/UDCMeas_42f7a63c] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SpdMeas_42f7a63c] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SpdMeas_42f7a63c, /ActiveEcuC/Com/ComConfig/TrqEstimd_42f7a63c] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IDCEstimd_42f7a63c, /ActiveEcuC/Com/ComConfig/TrqEstimd_42f7a63c] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IDCEstimd_42f7a63c] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/IDCEstimd_42f7a63c, /ActiveEcuC/Com/ComConfig/MsgCntr_42f7a63c] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/CarModeHS] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/CarMode] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/PowerMode] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/PowerMode2] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pVd_3037eb73] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pVd_3037eb73, /ActiveEcuC/Com/ComConfig/pVq_3037eb73] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pId_3037eb73, /ActiveEcuC/Com/ComConfig/pVq_3037eb73] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pId_3037eb73, /ActiveEcuC/Com/ComConfig/pIq_3037eb73] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pIdSetpoint_3037eb73, /ActiveEcuC/Com/ComConfig/pIq_3037eb73] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pIdSetpoint_3037eb73, /ActiveEcuC/Com/ComConfig/pIqSetpoint_3037eb73] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pIqSetpoint_3037eb73, /ActiveEcuC/Com/ComConfig/pTrqSetPoint_3037eb73] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/pTrqSetPoint_3037eb73] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[6];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/RESERVED_ID5_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_AVAILABILITY_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_STATUS_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/SCU_DATA_TX, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/SCU_MOTOR_DIAG_oCAN00_3abd61be, /ActiveEcuC/Com/ComConfig/SCU_oCAN00_Tx_fcef2243] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

