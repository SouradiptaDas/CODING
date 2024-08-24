#include "__cf_P_O_Algorithm.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "P_O_Algorithm_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "P_O_Algorithm.h"
#include "P_O_Algorithm_capi.h"
#include "P_O_Algorithm_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 8 , TARGET_STRING (
"P_O_Algorithm/mppt " ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "P_O_Algorithm/Product" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "P_O_Algorithm/Unit Delay1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"P_O_Algorithm/Repeating Sequence/Look-Up Table1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Current Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 5 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Data Type Conversion1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 2 } , { 6 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Data Type Conversion2" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 2 } , { 7 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 8 , 0 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Gain2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 9 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/R" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2
} , { 10 , 0 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/R1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Memory2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 2 } , { 12 , 0 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/it init" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 13 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Saturation" ) , TARGET_STRING ( "SOC (%)" ) , 0
, 0 , 0 , 0 , 3 } , { 14 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Add" ) , TARGET_STRING ( "Voltage (V)" ) , 0 , 0
, 0 , 0 , 3 } , { 15 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Current filter" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 2 } , { 16 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/VT_ref_array" ) , TARGET_STRING ( "VT" ) ,
0 , 0 , 0 , 0 , 4 } , { 17 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/Product4" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 4 } , { 18 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 19 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/IL ctrl/1//Sref" ) , TARGET_STRING ( "S/Sref" ) , 0 ,
0 , 0 , 0 , 4 } , { 20 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/IL ctrl/Product1" ) , TARGET_STRING ( "IL" ) , 0 , 0
, 0 , 0 , 4 } , { 21 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/I_PV/do not delete this gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 22 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 23 , 0 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 2 } , { 24 , 0 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( ""
) , 1 , 0 , 2 , 0 , 2 } , { 25 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Discrete-Time Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 2 } , { 27 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Saturation Dynamic/Switch2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 28 , 0 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Saturation Dynamic1/Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 2 } , { 29 , 0 , TARGET_STRING (
"P_O_Algorithm/Mosfet/Ideal Switch/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 30 , 0 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/BAL/Unit Delay" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 31 ,
TARGET_STRING ( "P_O_Algorithm/Battery" ) , TARGET_STRING ( "BatType" ) , 0 ,
0 , 0 } , { 32 , TARGET_STRING ( "P_O_Algorithm/Battery" ) , TARGET_STRING (
"SOC" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING ( "P_O_Algorithm/PV Array" ) ,
TARGET_STRING ( "Npar" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"P_O_Algorithm/PV Array" ) , TARGET_STRING ( "Nser" ) , 0 , 0 , 0 } , { 35 ,
TARGET_STRING ( "P_O_Algorithm/Repeating Sequence" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 3 , 0 } , { 36 , TARGET_STRING (
"P_O_Algorithm/Irradiance" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 37
, TARGET_STRING ( "P_O_Algorithm/Temperature " ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 38 , TARGET_STRING ( "P_O_Algorithm/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"P_O_Algorithm/Unit Delay1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0
, 0 } , { 40 , TARGET_STRING ( "P_O_Algorithm/Repeating Sequence/Constant" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"P_O_Algorithm/Repeating Sequence/Look-Up Table1" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 3 , 0 } , { 42 , TARGET_STRING (
"P_O_Algorithm/Battery/Current Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 44 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Constant12" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 46 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Constant9" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/int(i)" ) , TARGET_STRING ( "gainval" ) , 0 , 0
, 0 } , { 48 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/int(i)" ) ,
TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING
( "P_O_Algorithm/Battery/Model/int(i)" ) , TARGET_STRING (
"LowerSaturationLimit" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 51 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/R" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 53 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/R1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/R2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 55 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/R3" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/R4" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 57 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Memory2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/it init1" ) , TARGET_STRING ( "InitialCondition"
) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Saturation" ) , TARGET_STRING ( "UpperLimit" ) ,
0 , 0 , 0 } , { 60 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Saturation"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Current filter" ) , TARGET_STRING ( "Numerator"
) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Current filter" ) , TARGET_STRING (
"Denominator" ) , 0 , 3 , 0 } , { 63 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Current filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"P_O_Algorithm/Diode/Model/eee" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 65 , TARGET_STRING ( "P_O_Algorithm/PV Array/Diode Rsh/Rsh_array_5%Sref" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/Tref_K1" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 67 , TARGET_STRING ( "P_O_Algorithm/PV Array/Diode Rsh/Tref_K2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/one" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 69 , TARGET_STRING ( "P_O_Algorithm/PV Array/Diode Rsh/one1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/EgRef" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 71 , TARGET_STRING ( "P_O_Algorithm/PV Array/Diode Rsh/dEgdT" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"P_O_Algorithm/PV Array/IL ctrl/0_K" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 73 , TARGET_STRING ( "P_O_Algorithm/PV Array/IL ctrl/IL_module" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"P_O_Algorithm/PV Array/IL ctrl/Tref_K" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 75 , TARGET_STRING ( "P_O_Algorithm/PV Array/IL ctrl/1//Sref" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"P_O_Algorithm/PV Array/IL ctrl/alpha_Isc" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 77 , TARGET_STRING (
"P_O_Algorithm/PV Array/I_PV/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"P_O_Algorithm/PV Array/V_PV/do not delete this gain" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"AS_param" ) , 0 , 4 , 0 } , { 80 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"BS_param" ) , 0 , 5 , 0 } , { 81 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"CS_param" ) , 0 , 6 , 0 } , { 82 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"DS_param" ) , 0 , 7 , 0 } , { 83 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING (
"X0_param" ) , 0 , 8 , 0 } , { 84 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Compare To Zero/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Compare To Zero2/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/E_dyn Charge/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/E_dyn Charge/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/E_dyn Charge/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/E_dyn Charge/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Discrete-Time Integrator" ) , TARGET_STRING
( "gainval" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 92 , TARGET_STRING ( "P_O_Algorithm/Battery/Model/Exp/Gain4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Saturation" ) , TARGET_STRING ( "UpperLimit"
) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Saturation" ) , TARGET_STRING ( "LowerLimit"
) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/BAL/Unit Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/Subsystem/EgRef" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"P_O_Algorithm/PV Array/Diode Rsh/Subsystem/k1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 98 , TARGET_STRING (
"P_O_Algorithm/powergui/EquivalentModel1/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 99 , TARGET_STRING (
"P_O_Algorithm/Battery/Model/Exp/Compare To Zero2/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL )
, 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . adwlkt4aji , & rtB . iabhbltntc ,
& rtB . fbx0qo0g3f , & rtB . iedo3uzdki , & rtB . em2nnuuz40 , & rtB .
bsarhrs4kr , & rtB . ljtvghxtux , & rtB . n5qsf2ppfq , & rtB . h5bixvn1me , &
rtB . h42gj14eth , & rtB . dpwivq0fds , & rtB . lqkgfyhkru , & rtB .
koobqpf22y , & rtB . hilvlxo5dw , & rtB . kvt5zhgzbi , & rtB . d0bpobslze , &
rtB . dfm0cs3350 , & rtB . n5yaxbsj3n , & rtB . f1zgdmvpbp , & rtB .
ngemnoz21l , & rtB . eunl3qcjlh , & rtB . okf5iwwvho , & rtB . hzgt3pwgdg , &
rtB . mxi5esqlco [ 0 ] , & rtB . hsenihq3bi [ 0 ] , & rtB . e32yfly1mg , &
rtB . iwtvfahc01 , & rtB . a0f1utn1ur , & rtB . lygq3ygt2j , & rtB .
jdiw3tifo0 , & rtB . npzp2nktgj , & rtP . Battery_BatType , & rtP .
Battery_SOC , & rtP . PVArray_Npar , & rtP . PVArray_Nser , & rtP .
RepeatingSequence_rep_seq_y [ 0 ] , & rtP . Irradiance_Value , & rtP .
Temperature_Value , & rtP . UnitDelay_InitialCondition_hsukbc1fti , & rtP .
UnitDelay1_InitialCondition , & rtP . Constant_Value_g20vuihr23 , & rtP .
LookUpTable1_bp01Data [ 0 ] , & rtP . donotdeletethisgain_Gain , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . Constant12_Value , & rtP .
Constant9_Value , & rtP . inti_gainval , & rtP . inti_UpperSat , & rtP .
inti_LowerSat , & rtP . Gain_Gain , & rtP . Gain2_Gain , & rtP . R_Gain , &
rtP . R1_Gain , & rtP . R2_Gain , & rtP . R3_Gain , & rtP . R4_Gain , & rtP .
Memory2_InitialCondition , & rtP . itinit1_InitialCondition , & rtP .
Saturation_UpperSat_gfnwdnhivs , & rtP . Saturation_LowerSat_ofwy2u1vqp , &
rtP . Currentfilter_NumCoef , & rtP . Currentfilter_DenCoef [ 0 ] , & rtP .
Currentfilter_InitialStates , & rtP . eee_Value , & rtP .
Rsh_array_5Sref_Value , & rtP . Tref_K1_Value , & rtP . Tref_K2_Value , & rtP
. one_Value , & rtP . one1_Value , & rtP . EgRef_Gain , & rtP . dEgdT_Gain ,
& rtP . u_K_Value , & rtP . IL_module_Value , & rtP . Tref_K_Value , & rtP .
uSref_Gain , & rtP . alpha_Isc_Gain , & rtP .
donotdeletethisgain_Gain_aicr253wuj , & rtP .
donotdeletethisgain_Gain_oumtwrk3lg , & rtP . StateSpace_AS_param [ 0 ] , &
rtP . StateSpace_BS_param [ 0 ] , & rtP . StateSpace_CS_param [ 0 ] , & rtP .
StateSpace_DS_param [ 0 ] , & rtP . StateSpace_X0_param [ 0 ] , & rtP .
Constant_Value_n3bn4aqtv0 , & rtP . Constant_Value_iuuok2jfzc , & rtP .
Constant1_Value_drkiaq15p3 , & rtP . Constant2_Value , & rtP .
Constant3_Value , & rtP . Constant4_Value , & rtP .
DiscreteTimeIntegrator_gainval , & rtP . Gain1_Gain , & rtP . Gain4_Gain , &
rtP . Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
UnitDelay_InitialCondition , & rtP . EgRef_Value , & rtP . k1_Gain , & rtP .
SwitchCurrents_Value [ 0 ] , & rtP . Constant_Value_jqsaqx4mlv , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 14 , 2 , 0 } , { rtwCAPI_VECTOR , 16 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 1 , 6 , 1 , 3 , 1 , 1 , 2 ,
4 , 4 , 4 , 7 , 6 , 4 , 6 , 7 , 4 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0001 , 0.0 , 1.0E-6 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 3 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 2 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 3 ] , 1 , 0 } , { ( NULL ) ,
( NULL ) , 4 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 31 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters ,
69 , rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 3620723121U , 3273175510U , 974960485U ,
1462179910U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
P_O_Algorithm_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void P_O_Algorithm_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void P_O_Algorithm_host_InitializeDataMapInfo (
P_O_Algorithm_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
