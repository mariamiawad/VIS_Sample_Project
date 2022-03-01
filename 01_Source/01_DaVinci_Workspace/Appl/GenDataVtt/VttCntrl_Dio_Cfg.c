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
 *            Module: VTTCntrl
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: VttCntrl_Dio_Cfg.c
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


#define VTTDIO_CFG_SOURCE

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "VttCntrl_Dio.h"

/**********************************************************************************************************************
*  PRAGMAS
*********************************************************************************************************************/
/* The following pragmas ensure that all variables of this module are places in memory that is not cleared during a
 * simulated ECU reset/poweron */
#pragma bss_seg()
#pragma data_seg()

/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
/* Check the version of VttCntrl_Dio header file */
#if (  (VTTDIO_SW_MAJOR_VERSION != (0x03u)) \
    || (VTTDIO_SW_MINOR_VERSION != (0x00u)) \
    || (VTTDIO_SW_PATCH_VERSION != (0x06u)) )
# error "Vendor specific version numbers of VttCntrl_Dio_Cfg.c and VttCntrl_Dio.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VTTDIO_CFG_MAJOR_VERSION != (0x13u)) \
    || (VTTDIO_CFG_MINOR_VERSION != (0x00u)) \
    || (VTTDIO_CFG_PATCH_VERSION != (0x02u)))
  #error "Version numbers of VttCntrl_Dio_Cfg.c and VttCntrl_Dio_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
*  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

STATIC const char *VttDio_Channels[] = {
  "DIO_I_GPIO_EQ2",
  "DIO_I_MC_LOW_VBAT",
  "DIO_I_GPIO_EQ3",
  "DIO_I_GPIO_EQ4",
  "DIO_I_MC_FSH_ENA_FB",
  "DIO_O_MC_FSH_ENA",
  "DIO_I_EQ_ERROUT",
  "DIO_O_IP_RESET",
  "DIO_O_EQ_NTRST",
  "DIO_I_MC_VER_0",
  "DIO_I_MC_VER_1",
  "DIO_I_MC_VER_2",
  "DIO_I_MC_VER_6",
  "DIO_I_MC_VER_4",
  "DIO_I_MC_VER_5",
  "DIO_I_MC_VER_3",
  "DIO_O_MC_WDI",
  "DIO_O_1V8_DIG_ENA",
  "DIO_O_1V1_ENA",
  "DIO_O_3V3_IP_ENA",
  "DIO_O_1V0_ENA",
  "UC_CAN2_STB",
  "UC_CAN1_EN",
  "UC_CAN1_STB",
  "DIO_I_GPIO_EQ1",
  "TP404",
};

STATIC const char *VttDio_Groups[] = {
  "DIO_O_IP_RESET_EQ_NTRST",
  "DIO_I_MC_VER",
};

STATIC const char *VttDio_Ports[] = {
  "DioPort_4",
  "DioPort_1",
  "DioPort_9",
  "DioPort_0",
  "DioPort_6",
  "DioPort_2",
  "DioPort_5",
  "DioPort_7",
};

/**********************************************************************************************************************
*  GLOBAL DATA
**********************************************************************************************************************/

sint32 VttDio_ChannelHandle[VTTDIO_CHANNELS];
sint32 VttDio_GroupHandle[VTTDIO_CHANNELGROUPS];
sint32 VttDio_PortHandle[VTTDIO_PORTS];

extern uint8 VttDio_EcuState;

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
*  VttDio_MapChannel
**********************************************************************************************************************/
/*! \brief     Maps the channels defined by the User in DaVinci Configurator on the
*              channels of CANoe.
*  \return     no return 
*  \context    Function shall be called in CANoeAPI_InitHook().
*  \note       
**********************************************************************************************************************/
void VttDio_MapChannel(void)
{
  int i;

  /* Declare Channels as System Variables */
  for(i = 0; i < VTTDIO_CHANNELS; i++)
  {
    VttDio_ChannelHandle[i] = CANoeAPI_SysVar_DeclareInt("Dio", VttDio_Channels[i], 0);
  }

  /* Declare Ports as System Variables */
  for(i = 0; i < VTTDIO_PORTS; i++)
  {
    VttDio_PortHandle[i] = CANoeAPI_SysVar_DeclareInt("Dio", VttDio_Ports[i], 0);
  }


  /* Declare GroupChannels as System Variables */
  for(i = 0; i < VTTDIO_CHANNELGROUPS; i++)
  {
    VttDio_GroupHandle[i] = CANoeAPI_SysVar_DeclareInt("Dio", VttDio_Groups[i], 0);
  }
}

/***********************************************************************************************************************
*  VttDio_ReadChannel
**********************************************************************************************************************/
/*! \brief     Initialize all Vtt CAN Controllers.
*  \return     no return 
*  \context    Function is called by State Machine of VTT.
*  \note       CANoeAPI returns 0, when the given handle is unknown.
**********************************************************************************************************************/
uint32 VttDio_ReadChannel(Dio_ChannelType ChannelId)
{
  if((ChannelId >= VTTDIO_CHANNELS) || (VttDio_EcuState != CANOEAPI_ECUSTATE_PROCESSING))
  {
    return 0;
  }
 
  return CANoeAPI_SysVar_GetInt(VttDio_ChannelHandle[ChannelId]);
}

/***********************************************************************************************************************
*  VttDio_WriteChannel
**********************************************************************************************************************/
/*! \brief     Initialize all Vtt CAN Controllers.
*  \return     no return 
*  \context    Function is called by State Machine of VTT.
*  \note       Is called when the Node Layer DLL is loaded by CANoe.
**********************************************************************************************************************/
void VttDio_WriteChannel(Dio_ChannelType ChannelId, uint32 Level)
{
  if((ChannelId >= VTTDIO_CHANNELS) || (VttDio_EcuState != CANOEAPI_ECUSTATE_PROCESSING))
  {
    return;
  }

  CANoeAPI_SysVar_SetInt(VttDio_ChannelHandle[ChannelId], Level);
}

/**********************************************************************************************************************
*  END OF FILE: VttCntrl_Dio_Cfg.c
*********************************************************************************************************************/

