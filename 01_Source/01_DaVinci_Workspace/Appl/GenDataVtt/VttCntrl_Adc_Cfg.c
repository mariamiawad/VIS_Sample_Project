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
 *              File: VttCntrl_Adc_Cfg.c
 *   Generation Time: 2019-11-13 15:54:52
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


#define VTTADC_CFG_SOURCE

/*********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/

#include "VttCntrl_Adc.h"

/**********************************************************************************************************************
*  PRAGMAS
*********************************************************************************************************************/
/* The following pragmas ensure that all variables of this module are places in memory that is not cleared during a
 * simulated ECU reset/poweron */
#pragma bss_seg()
#pragma data_seg()

/*********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/

/* Check the version of VttCntrl_Adc header file */
#if (  (VTTADC_SW_MAJOR_VERSION != (0x03u)) \
    || (VTTADC_SW_MINOR_VERSION != (0x01u)) \
    || (VTTADC_SW_PATCH_VERSION != (0x01u)) )
# error "Vendor specific version numbers of VttCntrl_Adc_Cfg.c and VttCntrl_Adc.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VTTADC_CFG_MAJOR_VERSION != (0x14u)) \
    || (VTTADC_CFG_MINOR_VERSION != (0x00u)) \
    || (VTTADC_CFG_PATCH_VERSION != (0x01u)))
  #error "Version numbers of VttCntrl_Adc_Cfg.c and VttCntrl_Adc_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
*  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
*  Buffer for values of the last complete measurement
**********************************************************************************************************************/
/*
Naming convention: VttAdc_<HWUnitName>_<GroupName>_Values[<NumberOfChannelsInGroup>]
*/

Adc_ValueType VttAdc_AdcHwUnit_0_SYS_MON_Values[12] = 
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};


/**********************************************************************************************************************
*  Channel configuration
**********************************************************************************************************************/
/*
Naming convention: VttAdc_ChannelType VttAdc_<ChannelName>
Hint: Group Name is unique for all HWUnits and for all ConfigSets. Channel names are unique for one ConfigSet.
*/

VttAdc_ChannelType VttAdc_Channel_MC_2V8_IMA_ADC =    	
{
  "MC_2V8_IMA_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_1V1_ADC =    	
{
  "MC_1V1_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_1V0_ADC =    	
{
  "MC_1V0_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_TEMP_INSIDE_ADC =    	
{
  "MC_TEMP_INSIDE_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_VBAT_mon_ADC =    	
{
  "MC_VBAT_mon_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_TEMP_DDR_ADC =    	
{
  "MC_TEMP_DDR_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_1V2_IMA_RB_ADC =    	
{
  "MC_1V2_IMA_RB_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_5V0_ADC =    	
{
  "MC_5V0_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_2V8_RB_ADC =    	
{
  "MC_2V8_RB_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_1V25_ADC =    	
{
  "MC_1V25_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_1V8_ADC =    	
{
  "MC_1V8_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_TEMP_EQ4_ADC =    	
{
  "MC_TEMP_EQ4_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };

VttAdc_ChannelType VttAdc_Channel_MC_3V3_IP_ADC =    	
{
  "MC_3V3_IP_ADC",
  12,
  (double) 0.0,
  (double) 0.0,
  (double) 5.0,
  0,
  0,
  1000,
  };


/**********************************************************************************************************************
*  Array of all channels
**********************************************************************************************************************/


VttAdc_ChannelType *VttAdc_AllChannels[VTTADC_CHANNELS] =
{
  &VttAdc_Channel_MC_2V8_IMA_ADC,
  &VttAdc_Channel_MC_1V1_ADC,
  &VttAdc_Channel_MC_1V0_ADC,
  &VttAdc_Channel_MC_TEMP_INSIDE_ADC,
  &VttAdc_Channel_MC_VBAT_mon_ADC,
  &VttAdc_Channel_MC_TEMP_DDR_ADC,
  &VttAdc_Channel_MC_1V2_IMA_RB_ADC,
  &VttAdc_Channel_MC_5V0_ADC,
  &VttAdc_Channel_MC_2V8_RB_ADC,
  &VttAdc_Channel_MC_1V25_ADC,
  &VttAdc_Channel_MC_1V8_ADC,
  &VttAdc_Channel_MC_TEMP_EQ4_ADC,
  &VttAdc_Channel_MC_3V3_IP_ADC,
};

/**********************************************************************************************************************
*  Group Channel References 
**********************************************************************************************************************/

VttAdc_ChannelType *VttAdc_Group_ChReference_SYS_MON[] = 
{
   &VttAdc_Channel_MC_VBAT_mon_ADC,
   &VttAdc_Channel_MC_5V0_ADC,
   &VttAdc_Channel_MC_3V3_IP_ADC,
   &VttAdc_Channel_MC_1V8_ADC,
   &VttAdc_Channel_MC_1V25_ADC,
   &VttAdc_Channel_MC_1V1_ADC,
   &VttAdc_Channel_MC_1V0_ADC,
   &VttAdc_Channel_MC_TEMP_EQ4_ADC,
   &VttAdc_Channel_MC_TEMP_DDR_ADC,
   &VttAdc_Channel_MC_1V2_IMA_RB_ADC,
   &VttAdc_Channel_MC_2V8_IMA_ADC,
   &VttAdc_Channel_MC_2V8_RB_ADC,
};


/**********************************************************************************************************************
*  Group configuration
**********************************************************************************************************************/

VttAdc_CntrlType VttAdc_Cntrl[VTTADC_GROUPS] = 
{
  {
    "SYS_MON",
    12,
    0,
    0,
    0,
    0,
    VTTADC_TRIGG_SRC_SW,
    0,
    VttAdc_OpMode_Stopped,
    &VttAdc_AdcHwUnit_0_SYS_MON_Values[0],
    VttAdc_Group_ChReference_SYS_MON,
  },
};

/**********************************************************************************************************************
*  END OF FILE: VttCntrl_Adc_Cfg.c
**********************************************************************************************************************/


