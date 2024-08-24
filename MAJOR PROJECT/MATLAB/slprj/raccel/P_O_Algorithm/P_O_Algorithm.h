#include "__cf_P_O_Algorithm.h"
#ifndef RTW_HEADER_P_O_Algorithm_h_
#define RTW_HEADER_P_O_Algorithm_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef P_O_Algorithm_COMMON_INCLUDES_
#define P_O_Algorithm_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "P_O_Algorithm_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#define MODEL_NAME P_O_Algorithm
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (31) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T d0bpobslze ; real_T ljtvghxtux ; real_T koobqpf22y ;
real_T n5qsf2ppfq ; real_T lygq3ygt2j ; real_T bsarhrs4kr ; real_T e32yfly1mg
; real_T lqkgfyhkru ; real_T a0f1utn1ur ; real_T ngemnoz21l ; real_T
eunl3qcjlh ; real_T npzp2nktgj ; real_T mxi5esqlco [ 6 ] ; real_T hsenihq3bi
[ 3 ] ; real_T em2nnuuz40 ; real_T fbx0qo0g3f ; real_T iabhbltntc ; real_T
hilvlxo5dw ; real_T h42gj14eth ; real_T kvt5zhgzbi ; real_T okf5iwwvho ;
real_T iwtvfahc01 ; real_T h5bixvn1me ; real_T dpwivq0fds ; real_T iedo3uzdki
; real_T jdiw3tifo0 ; real_T hzgt3pwgdg ; real_T dfm0cs3350 ; real_T
n5yaxbsj3n ; real_T f1zgdmvpbp ; real_T adwlkt4aji ; } B ; typedef struct {
real_T knu05efaia ; real_T ocfkalkmt1 ; real_T kzb1bipvzc ; real_T kxq3i3a5e0
; real_T ba0fhn43mf [ 4 ] ; real_T ef5gie5krl ; real_T mpwvjztsbx ; real_T
fccnxrfig4 ; real_T dtaijnbgzm ; real_T oz5r5rhz1r ; real_T gxtljmpzqd ;
real_T bojdogcykn ; real_T gnlmv2t1lw ; struct { void * AS ; void * BS ; void
* CS ; void * DS ; void * DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2
; void * XTMP ; void * SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void *
SW_CHG ; void * G_STATE ; void * USWLAST ; void * XKM12 ; void * XKP12 ; void
* XLAST ; void * ULAST ; void * IDX_SW_CHG ; void * Y_SWITCH ; void *
SWITCH_TYPES ; void * IDX_OUT_SW ; void * SWITCH_TOPO_SAVED_IDX ; void *
SWITCH_MAP ; } kfvpshvioz ; struct { void * LoggedData [ 4 ] ; } lkeccsk1xw ;
int_T jmio3su4bh [ 11 ] ; int8_T hvnlljol2x ; uint8_T mnxr2r3vae ; boolean_T
gvp50ey4nq ; } DW ; typedef struct { real_T eway5lh1bc ; } ZCV ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
Battery_BatType ; real_T PVArray_Npar ; real_T PVArray_Nser ; real_T
Battery_SOC ; real_T RepeatingSequence_rep_seq_y [ 2 ] ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
SwitchCurrents_Value [ 3 ] ; real_T Constant1_Value ; real_T Constant_Value ;
real_T itinit1_InitialCondition ; real_T R2_Gain ; real_T
Currentfilter_NumCoef ; real_T Currentfilter_DenCoef [ 2 ] ; real_T
Currentfilter_InitialStates ; real_T Constant_Value_n3bn4aqtv0 ; real_T
inti_gainval ; real_T inti_UpperSat ; real_T inti_LowerSat ; real_T Gain_Gain
; real_T Constant9_Value ; real_T Constant4_Value ; real_T R3_Gain ; real_T
Constant_Value_iuuok2jfzc ; real_T Constant1_Value_drkiaq15p3 ; real_T
Constant3_Value ; real_T Constant2_Value ; real_T
DiscreteTimeIntegrator_gainval ; real_T Memory2_InitialCondition ; real_T
Temperature_Value ; real_T u_K_Value ; real_T Tref_K_Value ; real_T
alpha_Isc_Gain ; real_T IL_module_Value ; real_T Irradiance_Value ; real_T
uSref_Gain ; real_T UnitDelay_InitialCondition ; real_T eee_Value ; real_T
StateSpace_AS_param [ 16 ] ; real_T StateSpace_BS_param [ 28 ] ; real_T
StateSpace_CS_param [ 24 ] ; real_T StateSpace_DS_param [ 42 ] ; real_T
StateSpace_X0_param [ 4 ] ; real_T donotdeletethisgain_Gain ; real_T
UnitDelay_InitialCondition_hsukbc1fti ; real_T UnitDelay1_InitialCondition ;
real_T R4_Gain ; real_T Saturation_UpperSat_gfnwdnhivs ; real_T
Saturation_LowerSat_ofwy2u1vqp ; real_T R_Gain ; real_T
donotdeletethisgain_Gain_aicr253wuj ; real_T Constant12_Value ; real_T
Constant_Value_jqsaqx4mlv ; real_T Gain4_Gain ; real_T Gain1_Gain ; real_T
Gain2_Gain ; real_T R1_Gain ; real_T Constant_Value_g20vuihr23 ; real_T
LookUpTable1_bp01Data [ 2 ] ; real_T donotdeletethisgain_Gain_oumtwrk3lg ;
real_T Tref_K2_Value ; real_T one_Value ; real_T EgRef_Value ; real_T
one1_Value ; real_T Tref_K1_Value ; real_T dEgdT_Gain ; real_T EgRef_Gain ;
real_T k1_Gain ; real_T Rsh_array_5Sref_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * P_O_Algorithm_GetCAPIStaticMap
( void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
