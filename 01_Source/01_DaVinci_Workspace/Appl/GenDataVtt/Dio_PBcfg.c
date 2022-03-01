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
 *            Module: VTTDio
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dio_PBcfg.c
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

#define DIO_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Dio.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define DIO_CFG_C_MAJOR_VERSION    (4u) 
#define DIO_CFG_C_MINOR_VERSION    (1u) 
#define DIO_CFG_C_PATCH_VERSION    (0u) 

#if (  (DIO_SW_MAJOR_VERSION != (2u)) \
    || (DIO_SW_MINOR_VERSION != (3u)))
  #error "Version numbers of Dio_PBcfg.c and Dio.h are inconsistent!"
#endif

#if (  (DIO_CFG_MAJOR_VERSION != DIO_CFG_C_MAJOR_VERSION) \
    || (DIO_CFG_MINOR_VERSION != DIO_CFG_C_MINOR_VERSION))
  #error "Version numbers of Dio_PBcfg.c and Dio_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
CONST(Dio_ChannelGroupType, DIO_APPL_CONST) DioConf_DioChannelGroup_DIO_O_IP_RESET_EQ_NTRST = { 0, 9UL,0x00000600UL }; 
CONST(Dio_ChannelGroupType, DIO_APPL_CONST) DioConf_DioChannelGroup_DIO_I_MC_VER = { 0, 0UL,0x0000007FUL }; 

P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupArray[DIO_MAX_CHANNELGROUP_COUNT] =  
{
  &DioConf_DioChannelGroup_DIO_O_IP_RESET_EQ_NTRST, 
  &DioConf_DioChannelGroup_DIO_I_MC_VER
};

CONST(Dio_ConfigType, DIO_APPL_CONST) DioConfig_0 = 0;

/**********************************************************************************************************************
 *  END OF FILE: DIO_PBCFG.C
 **********************************************************************************************************************/
