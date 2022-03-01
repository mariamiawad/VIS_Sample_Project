# *********************************************************************************************************************
#   COPYRIGHT
#   -------------------------------------------------------------------------------------------------------------------
# 
#                 This software is copyright protected and proprietary to Vector Informatik GmbH.
#                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
#                 All other rights remain with Vector Informatik GmbH.
#   -------------------------------------------------------------------------------------------------------------------
#   FILE DESCRIPTION
#   -------------------------------------------------------------------------------------------------------------------
#           File:  E2EXf_rules.mak
#         Config:  Bootcamp.dpa
#    ECU-Project:  SCU
# 
#      Generator:  MICROSAR E2EXf Generator Version 1.3.0
#                  RTE Core Version 1.16.0
#        License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
# 
#    Description:  GNU MAKEFILE (rules)
# *********************************************************************************************************************


LIBRARIES_TO_BUILD           += E2EXf
E2EXf_FILES                  += E2EXf\E2EXf.c

CC_FILES_TO_BUILD            += E2EXf\E2EXf.c

GENERATED_SOURCE_FILES       += $(GENDATA_DIR)\E2EXf_LCfg.c
