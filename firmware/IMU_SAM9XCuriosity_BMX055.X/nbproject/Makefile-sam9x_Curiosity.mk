#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-sam9x_Curiosity.mk)" "nbproject/Makefile-local-sam9x_Curiosity.mk"
include nbproject/Makefile-local-sam9x_Curiosity.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=sam9x_Curiosity
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/sam9x_Curiosity/driver/imu/drv_imu.c ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c ../src/config/sam9x_Curiosity/system/cache/sys_cache.c ../src/config/sam9x_Curiosity/system/int/src/sys_int.c ../src/config/sam9x_Curiosity/system/time/src/sys_time.c ../src/config/sam9x_Curiosity/cstartup.S ../src/config/sam9x_Curiosity/tasks.c ../src/config/sam9x_Curiosity/initialization.c ../src/config/sam9x_Curiosity/interrupts.c ../src/config/sam9x_Curiosity/fault_handlers.c ../src/app.c ../src/main.c ../src/config/sam9x_Curiosity/bsp/bsp.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1128182572/drv_imu.o ${OBJECTDIR}/_ext/1722030300/drv_spi.o ${OBJECTDIR}/_ext/441841942/plib_aic.o ${OBJECTDIR}/_ext/441839919/plib_clk.o ${OBJECTDIR}/_ext/812115427/plib_dbgu.o ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o ${OBJECTDIR}/_ext/441830268/plib_mmu.o ${OBJECTDIR}/_ext/441827515/plib_pio.o ${OBJECTDIR}/_ext/2092462368/plib_tc0.o ${OBJECTDIR}/_ext/745456519/xc32_monitor.o ${OBJECTDIR}/_ext/1300519140/sys_cache.o ${OBJECTDIR}/_ext/1379663014/sys_int.o ${OBJECTDIR}/_ext/1515815680/sys_time.o ${OBJECTDIR}/_ext/1437643379/cstartup.o ${OBJECTDIR}/_ext/1437643379/tasks.o ${OBJECTDIR}/_ext/1437643379/initialization.o ${OBJECTDIR}/_ext/1437643379/interrupts.o ${OBJECTDIR}/_ext/1437643379/fault_handlers.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/800758461/bsp.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1128182572/drv_imu.o.d ${OBJECTDIR}/_ext/1722030300/drv_spi.o.d ${OBJECTDIR}/_ext/441841942/plib_aic.o.d ${OBJECTDIR}/_ext/441839919/plib_clk.o.d ${OBJECTDIR}/_ext/812115427/plib_dbgu.o.d ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o.d ${OBJECTDIR}/_ext/441830268/plib_mmu.o.d ${OBJECTDIR}/_ext/441827515/plib_pio.o.d ${OBJECTDIR}/_ext/2092462368/plib_tc0.o.d ${OBJECTDIR}/_ext/745456519/xc32_monitor.o.d ${OBJECTDIR}/_ext/1300519140/sys_cache.o.d ${OBJECTDIR}/_ext/1379663014/sys_int.o.d ${OBJECTDIR}/_ext/1515815680/sys_time.o.d ${OBJECTDIR}/_ext/1437643379/cstartup.o.d ${OBJECTDIR}/_ext/1437643379/tasks.o.d ${OBJECTDIR}/_ext/1437643379/initialization.o.d ${OBJECTDIR}/_ext/1437643379/interrupts.o.d ${OBJECTDIR}/_ext/1437643379/fault_handlers.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/800758461/bsp.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1128182572/drv_imu.o ${OBJECTDIR}/_ext/1722030300/drv_spi.o ${OBJECTDIR}/_ext/441841942/plib_aic.o ${OBJECTDIR}/_ext/441839919/plib_clk.o ${OBJECTDIR}/_ext/812115427/plib_dbgu.o ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o ${OBJECTDIR}/_ext/441830268/plib_mmu.o ${OBJECTDIR}/_ext/441827515/plib_pio.o ${OBJECTDIR}/_ext/2092462368/plib_tc0.o ${OBJECTDIR}/_ext/745456519/xc32_monitor.o ${OBJECTDIR}/_ext/1300519140/sys_cache.o ${OBJECTDIR}/_ext/1379663014/sys_int.o ${OBJECTDIR}/_ext/1515815680/sys_time.o ${OBJECTDIR}/_ext/1437643379/cstartup.o ${OBJECTDIR}/_ext/1437643379/tasks.o ${OBJECTDIR}/_ext/1437643379/initialization.o ${OBJECTDIR}/_ext/1437643379/interrupts.o ${OBJECTDIR}/_ext/1437643379/fault_handlers.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/800758461/bsp.o

# Source Files
SOURCEFILES=../src/config/sam9x_Curiosity/driver/imu/drv_imu.c ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c ../src/config/sam9x_Curiosity/system/cache/sys_cache.c ../src/config/sam9x_Curiosity/system/int/src/sys_int.c ../src/config/sam9x_Curiosity/system/time/src/sys_time.c ../src/config/sam9x_Curiosity/cstartup.S ../src/config/sam9x_Curiosity/tasks.c ../src/config/sam9x_Curiosity/initialization.c ../src/config/sam9x_Curiosity/interrupts.c ../src/config/sam9x_Curiosity/fault_handlers.c ../src/app.c ../src/main.c ../src/config/sam9x_Curiosity/bsp/bsp.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-sam9x_Curiosity.mk ${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=SAM9X60D1G
MP_LINKER_FILE_OPTION=,--script="..\src\config\sam9x_Curiosity\ddram.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1437643379/cstartup.o: ../src/config/sam9x_Curiosity/cstartup.S  .generated_files/flags/sam9x_Curiosity/2bed4411d0e923fd0c6308ebc8d18e6cdc8de224 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o.ok ${OBJECTDIR}/_ext/1437643379/cstartup.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1437643379/cstartup.o.d"  -o ${OBJECTDIR}/_ext/1437643379/cstartup.o ../src/config/sam9x_Curiosity/cstartup.S  -DXPRJ_sam9x_Curiosity=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1437643379/cstartup.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437643379/cstartup.o.d" "${OBJECTDIR}/_ext/1437643379/cstartup.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1437643379/cstartup.o: ../src/config/sam9x_Curiosity/cstartup.S  .generated_files/flags/sam9x_Curiosity/9084a62d189b68d2b24d7c06263747de239b94ae .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o 
	@${RM} ${OBJECTDIR}/_ext/1437643379/cstartup.o.ok ${OBJECTDIR}/_ext/1437643379/cstartup.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1437643379/cstartup.o.d"  -o ${OBJECTDIR}/_ext/1437643379/cstartup.o ../src/config/sam9x_Curiosity/cstartup.S  -DXPRJ_sam9x_Curiosity=$(CND_CONF)    -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1437643379/cstartup.o.asm.d",--gdwarf-2 -mdfp="${DFP_DIR}"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1437643379/cstartup.o.d" "${OBJECTDIR}/_ext/1437643379/cstartup.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1128182572/drv_imu.o: ../src/config/sam9x_Curiosity/driver/imu/drv_imu.c  .generated_files/flags/sam9x_Curiosity/231d4ae86acd90977bfeb2a0e6d0dcd70951d2d2 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1128182572" 
	@${RM} ${OBJECTDIR}/_ext/1128182572/drv_imu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1128182572/drv_imu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1128182572/drv_imu.o.d" -o ${OBJECTDIR}/_ext/1128182572/drv_imu.o ../src/config/sam9x_Curiosity/driver/imu/drv_imu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1722030300/drv_spi.o: ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c  .generated_files/flags/sam9x_Curiosity/21804bd32e0c2b7931c4f817c8a92cc0aff2e4e3 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1722030300" 
	@${RM} ${OBJECTDIR}/_ext/1722030300/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1722030300/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1722030300/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1722030300/drv_spi.o ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441841942/plib_aic.o: ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c  .generated_files/flags/sam9x_Curiosity/feb085f5b5b6f2affc99e043437290123143a57b .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441841942" 
	@${RM} ${OBJECTDIR}/_ext/441841942/plib_aic.o.d 
	@${RM} ${OBJECTDIR}/_ext/441841942/plib_aic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441841942/plib_aic.o.d" -o ${OBJECTDIR}/_ext/441841942/plib_aic.o ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441839919/plib_clk.o: ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c  .generated_files/flags/sam9x_Curiosity/13a2e6308e6713b779b6cc53839a4042b4b3b0c9 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441839919" 
	@${RM} ${OBJECTDIR}/_ext/441839919/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/441839919/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441839919/plib_clk.o.d" -o ${OBJECTDIR}/_ext/441839919/plib_clk.o ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/812115427/plib_dbgu.o: ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c  .generated_files/flags/sam9x_Curiosity/d34f83df4c16ee12e237e7fcb8ee8be47ff49fef .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/812115427" 
	@${RM} ${OBJECTDIR}/_ext/812115427/plib_dbgu.o.d 
	@${RM} ${OBJECTDIR}/_ext/812115427/plib_dbgu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/812115427/plib_dbgu.o.d" -o ${OBJECTDIR}/_ext/812115427/plib_dbgu.o ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o: ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c  .generated_files/flags/sam9x_Curiosity/9af99d9e6ce30039d3748af3e07735fa6d897e51 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/583233565" 
	@${RM} ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441830268/plib_mmu.o: ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c  .generated_files/flags/sam9x_Curiosity/71344666ba718f9c7dfa5f07231b702e29dbf42b .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441830268" 
	@${RM} ${OBJECTDIR}/_ext/441830268/plib_mmu.o.d 
	@${RM} ${OBJECTDIR}/_ext/441830268/plib_mmu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441830268/plib_mmu.o.d" -o ${OBJECTDIR}/_ext/441830268/plib_mmu.o ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441827515/plib_pio.o: ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c  .generated_files/flags/sam9x_Curiosity/a6662481880998da276ccb71f6162185964cbbac .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441827515" 
	@${RM} ${OBJECTDIR}/_ext/441827515/plib_pio.o.d 
	@${RM} ${OBJECTDIR}/_ext/441827515/plib_pio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441827515/plib_pio.o.d" -o ${OBJECTDIR}/_ext/441827515/plib_pio.o ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2092462368/plib_tc0.o: ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c  .generated_files/flags/sam9x_Curiosity/92dd535c7f2a0be41f96cc44a031bef2bdcd83e1 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2092462368" 
	@${RM} ${OBJECTDIR}/_ext/2092462368/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092462368/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2092462368/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/2092462368/plib_tc0.o ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/745456519/xc32_monitor.o: ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c  .generated_files/flags/sam9x_Curiosity/851e15222422f49c1b9eb51aaa3c097210d196 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/745456519" 
	@${RM} ${OBJECTDIR}/_ext/745456519/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/745456519/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/745456519/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/745456519/xc32_monitor.o ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1300519140/sys_cache.o: ../src/config/sam9x_Curiosity/system/cache/sys_cache.c  .generated_files/flags/sam9x_Curiosity/2e8df0fadbeb5ca6f3b912babcfa238176d28c14 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1300519140" 
	@${RM} ${OBJECTDIR}/_ext/1300519140/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1300519140/sys_cache.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1300519140/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1300519140/sys_cache.o ../src/config/sam9x_Curiosity/system/cache/sys_cache.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1379663014/sys_int.o: ../src/config/sam9x_Curiosity/system/int/src/sys_int.c  .generated_files/flags/sam9x_Curiosity/155710cd0a458479377afb75be7617d57ed07732 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1379663014" 
	@${RM} ${OBJECTDIR}/_ext/1379663014/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1379663014/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1379663014/sys_int.o.d" -o ${OBJECTDIR}/_ext/1379663014/sys_int.o ../src/config/sam9x_Curiosity/system/int/src/sys_int.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1515815680/sys_time.o: ../src/config/sam9x_Curiosity/system/time/src/sys_time.c  .generated_files/flags/sam9x_Curiosity/5a300ed570187f056bf4e9c97a53684b2ca7559 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1515815680" 
	@${RM} ${OBJECTDIR}/_ext/1515815680/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515815680/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1515815680/sys_time.o.d" -o ${OBJECTDIR}/_ext/1515815680/sys_time.o ../src/config/sam9x_Curiosity/system/time/src/sys_time.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/tasks.o: ../src/config/sam9x_Curiosity/tasks.c  .generated_files/flags/sam9x_Curiosity/6940faefd958e0dc63bdda4b3bed9397f293c218 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/tasks.o.d" -o ${OBJECTDIR}/_ext/1437643379/tasks.o ../src/config/sam9x_Curiosity/tasks.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/initialization.o: ../src/config/sam9x_Curiosity/initialization.c  .generated_files/flags/sam9x_Curiosity/6e4a44667f57ed0327952808180f22bb21d8726f .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/initialization.o.d" -o ${OBJECTDIR}/_ext/1437643379/initialization.o ../src/config/sam9x_Curiosity/initialization.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/interrupts.o: ../src/config/sam9x_Curiosity/interrupts.c  .generated_files/flags/sam9x_Curiosity/fa5132e1c10e38552b645b464e802ea09a598927 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/interrupts.o.d" -o ${OBJECTDIR}/_ext/1437643379/interrupts.o ../src/config/sam9x_Curiosity/interrupts.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/fault_handlers.o: ../src/config/sam9x_Curiosity/fault_handlers.c  .generated_files/flags/sam9x_Curiosity/b99aeadff5b1c417786d94713f0c98fac2553795 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/fault_handlers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/fault_handlers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/fault_handlers.o.d" -o ${OBJECTDIR}/_ext/1437643379/fault_handlers.o ../src/config/sam9x_Curiosity/fault_handlers.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam9x_Curiosity/842c2e6fab2d259c0af8e09edda6d2b519362a0b .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam9x_Curiosity/2917eb1a15568e0151b646bbe12523b6a4577cdd .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/800758461/bsp.o: ../src/config/sam9x_Curiosity/bsp/bsp.c  .generated_files/flags/sam9x_Curiosity/ca35b0fc1800b3c35985f5fe65e9a2b2ffdcc815 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/800758461" 
	@${RM} ${OBJECTDIR}/_ext/800758461/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/800758461/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/800758461/bsp.o.d" -o ${OBJECTDIR}/_ext/800758461/bsp.o ../src/config/sam9x_Curiosity/bsp/bsp.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1128182572/drv_imu.o: ../src/config/sam9x_Curiosity/driver/imu/drv_imu.c  .generated_files/flags/sam9x_Curiosity/8941300a8a3ffafb7bfc2aa1747a6596a522e246 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1128182572" 
	@${RM} ${OBJECTDIR}/_ext/1128182572/drv_imu.o.d 
	@${RM} ${OBJECTDIR}/_ext/1128182572/drv_imu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1128182572/drv_imu.o.d" -o ${OBJECTDIR}/_ext/1128182572/drv_imu.o ../src/config/sam9x_Curiosity/driver/imu/drv_imu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1722030300/drv_spi.o: ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c  .generated_files/flags/sam9x_Curiosity/d220972462aeb12dab87169904f873ddcea6581 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1722030300" 
	@${RM} ${OBJECTDIR}/_ext/1722030300/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1722030300/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1722030300/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1722030300/drv_spi.o ../src/config/sam9x_Curiosity/driver/spi/src/drv_spi.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441841942/plib_aic.o: ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c  .generated_files/flags/sam9x_Curiosity/15f7b830167395a2f91ded643bc4c741194d832a .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441841942" 
	@${RM} ${OBJECTDIR}/_ext/441841942/plib_aic.o.d 
	@${RM} ${OBJECTDIR}/_ext/441841942/plib_aic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441841942/plib_aic.o.d" -o ${OBJECTDIR}/_ext/441841942/plib_aic.o ../src/config/sam9x_Curiosity/peripheral/aic/plib_aic.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441839919/plib_clk.o: ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c  .generated_files/flags/sam9x_Curiosity/6feb70946030a4109d44020e598075ddf0bf971e .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441839919" 
	@${RM} ${OBJECTDIR}/_ext/441839919/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/441839919/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441839919/plib_clk.o.d" -o ${OBJECTDIR}/_ext/441839919/plib_clk.o ../src/config/sam9x_Curiosity/peripheral/clk/plib_clk.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/812115427/plib_dbgu.o: ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c  .generated_files/flags/sam9x_Curiosity/55e7bb24ecf16a52f6ab86f1955b4219cc564bcf .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/812115427" 
	@${RM} ${OBJECTDIR}/_ext/812115427/plib_dbgu.o.d 
	@${RM} ${OBJECTDIR}/_ext/812115427/plib_dbgu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/812115427/plib_dbgu.o.d" -o ${OBJECTDIR}/_ext/812115427/plib_dbgu.o ../src/config/sam9x_Curiosity/peripheral/dbgu/plib_dbgu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o: ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c  .generated_files/flags/sam9x_Curiosity/eb47b35712f7dc3c42ad5cfc43c03846af5df80c .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/583233565" 
	@${RM} ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/583233565/plib_flexcom5_spi_master.o ../src/config/sam9x_Curiosity/peripheral/flexcom/spi/master/plib_flexcom5_spi_master.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441830268/plib_mmu.o: ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c  .generated_files/flags/sam9x_Curiosity/483de287e9e824edd8539a8fabdcd09d5cbd6c2c .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441830268" 
	@${RM} ${OBJECTDIR}/_ext/441830268/plib_mmu.o.d 
	@${RM} ${OBJECTDIR}/_ext/441830268/plib_mmu.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441830268/plib_mmu.o.d" -o ${OBJECTDIR}/_ext/441830268/plib_mmu.o ../src/config/sam9x_Curiosity/peripheral/mmu/plib_mmu.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/441827515/plib_pio.o: ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c  .generated_files/flags/sam9x_Curiosity/3bf6c927659eba4415a11e5bb54e88a7b14e7e11 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/441827515" 
	@${RM} ${OBJECTDIR}/_ext/441827515/plib_pio.o.d 
	@${RM} ${OBJECTDIR}/_ext/441827515/plib_pio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/441827515/plib_pio.o.d" -o ${OBJECTDIR}/_ext/441827515/plib_pio.o ../src/config/sam9x_Curiosity/peripheral/pio/plib_pio.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2092462368/plib_tc0.o: ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c  .generated_files/flags/sam9x_Curiosity/608c737c137aadb3727dbc21240f54e69ae65025 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2092462368" 
	@${RM} ${OBJECTDIR}/_ext/2092462368/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/2092462368/plib_tc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2092462368/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/2092462368/plib_tc0.o ../src/config/sam9x_Curiosity/peripheral/tc/plib_tc0.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/745456519/xc32_monitor.o: ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c  .generated_files/flags/sam9x_Curiosity/739ee3ab6285b013d495207a5448c91988b6fe83 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/745456519" 
	@${RM} ${OBJECTDIR}/_ext/745456519/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/745456519/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/745456519/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/745456519/xc32_monitor.o ../src/config/sam9x_Curiosity/stdio/xc32_monitor.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1300519140/sys_cache.o: ../src/config/sam9x_Curiosity/system/cache/sys_cache.c  .generated_files/flags/sam9x_Curiosity/c767a3fbc17859cd94ad7052b1f0990d26f3c27a .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1300519140" 
	@${RM} ${OBJECTDIR}/_ext/1300519140/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1300519140/sys_cache.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1300519140/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1300519140/sys_cache.o ../src/config/sam9x_Curiosity/system/cache/sys_cache.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1379663014/sys_int.o: ../src/config/sam9x_Curiosity/system/int/src/sys_int.c  .generated_files/flags/sam9x_Curiosity/1953dea1af3444b6d5120aebde79d25bce807864 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1379663014" 
	@${RM} ${OBJECTDIR}/_ext/1379663014/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1379663014/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1379663014/sys_int.o.d" -o ${OBJECTDIR}/_ext/1379663014/sys_int.o ../src/config/sam9x_Curiosity/system/int/src/sys_int.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1515815680/sys_time.o: ../src/config/sam9x_Curiosity/system/time/src/sys_time.c  .generated_files/flags/sam9x_Curiosity/c291c733abea8d40dd01dd533960091af22baaa4 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1515815680" 
	@${RM} ${OBJECTDIR}/_ext/1515815680/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515815680/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1515815680/sys_time.o.d" -o ${OBJECTDIR}/_ext/1515815680/sys_time.o ../src/config/sam9x_Curiosity/system/time/src/sys_time.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/tasks.o: ../src/config/sam9x_Curiosity/tasks.c  .generated_files/flags/sam9x_Curiosity/cfdf10fe37f5468d9bd2b067d94d6b69764e0144 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/tasks.o.d" -o ${OBJECTDIR}/_ext/1437643379/tasks.o ../src/config/sam9x_Curiosity/tasks.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/initialization.o: ../src/config/sam9x_Curiosity/initialization.c  .generated_files/flags/sam9x_Curiosity/fb238c40c7c5175ce1e91171937ea5d93bd655cf .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/initialization.o.d" -o ${OBJECTDIR}/_ext/1437643379/initialization.o ../src/config/sam9x_Curiosity/initialization.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/interrupts.o: ../src/config/sam9x_Curiosity/interrupts.c  .generated_files/flags/sam9x_Curiosity/feeec29e3cfb067ef66c6e3654342c8f2f586740 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/interrupts.o.d" -o ${OBJECTDIR}/_ext/1437643379/interrupts.o ../src/config/sam9x_Curiosity/interrupts.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1437643379/fault_handlers.o: ../src/config/sam9x_Curiosity/fault_handlers.c  .generated_files/flags/sam9x_Curiosity/49fdc683fddc277733f8b007effcfc220bcbf275 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1437643379" 
	@${RM} ${OBJECTDIR}/_ext/1437643379/fault_handlers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1437643379/fault_handlers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1437643379/fault_handlers.o.d" -o ${OBJECTDIR}/_ext/1437643379/fault_handlers.o ../src/config/sam9x_Curiosity/fault_handlers.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/sam9x_Curiosity/74b6793d00bb9f129e63173dc74f6c6939763ab .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/sam9x_Curiosity/b27375b736efc1c2a80446d65cce5151d1f8607f .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/800758461/bsp.o: ../src/config/sam9x_Curiosity/bsp/bsp.c  .generated_files/flags/sam9x_Curiosity/c248057f7b1c4831327897b76c0ff3ebf2c41bb0 .generated_files/flags/sam9x_Curiosity/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/800758461" 
	@${RM} ${OBJECTDIR}/_ext/800758461/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/800758461/bsp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -fno-common -I"../src" -I"../src/config/sam9x_Curiosity" -I"../src/packs/SAM9X60D1G_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/800758461/bsp.o.d" -o ${OBJECTDIR}/_ext/800758461/bsp.o ../src/config/sam9x_Curiosity/bsp/bsp.c    -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/sam9x_Curiosity/ddram.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/sam9x_Curiosity/ddram.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o ${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam9x_Curiosity=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/IMU_SAM9XCuriosity_BMX055.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
