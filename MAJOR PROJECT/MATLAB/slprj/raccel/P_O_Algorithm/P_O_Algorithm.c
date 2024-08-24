#include "__cf_P_O_Algorithm.h"
#include "rt_logging_mmi.h"
#include "P_O_Algorithm_capi.h"
#include <math.h>
#include "P_O_Algorithm.h"
#include "P_O_Algorithm_private.h"
#include "P_O_Algorithm_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "8.14 (R2018a) 06-Feb-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\P_O_Algorithm\\P_O_Algorithm_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ;
uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [
maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while
( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [
iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] )
* frac + table [ iLeft ] ; } void MdlInitialize ( void ) { rtDW . fccnxrfig4
= rtP . itinit1_InitialCondition ; rtDW . knu05efaia = rtP .
Currentfilter_InitialStates ; rtDW . dtaijnbgzm = ( 1.0 - rtP . Battery_SOC /
100.0 ) * 2.5849999999999933 * 0.96711798839458663 * 3600.0 ; rtDW .
mnxr2r3vae = 1U ; rtDW . hvnlljol2x = 2 ; rtDW . kzb1bipvzc =
muDoubleScalarExp ( ( 1.0 - rtP . Battery_SOC / 100.0 ) * -
24.424778761061944 * 2.5849999999999933 ) * 1.0077115567411321 ; rtDW .
oz5r5rhz1r = rtP . Memory2_InitialCondition ; rtDW . kxq3i3a5e0 = rtP .
UnitDelay_InitialCondition ; { int32_T i , j ; real_T * As = ( real_T * )
rtDW . kfvpshvioz . AS ; real_T * Bs = ( real_T * ) rtDW . kfvpshvioz . BS ;
real_T * Cs = ( real_T * ) rtDW . kfvpshvioz . CS ; real_T * Ds = ( real_T *
) rtDW . kfvpshvioz . DS ; real_T * X0 = ( real_T * ) & rtDW . ba0fhn43mf [ 0
] ; for ( i = 0 ; i < 4 ; i ++ ) { X0 [ i ] = ( rtP . StateSpace_X0_param [ i
] ) ; } for ( i = 0 ; i < 4 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) As [ i *
4 + j ] = ( rtP . StateSpace_AS_param [ i + j * 4 ] ) ; for ( j = 0 ; j < 7 ;
j ++ ) Bs [ i * 7 + j ] = ( rtP . StateSpace_BS_param [ i + j * 4 ] ) ; } for
( i = 0 ; i < 6 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) Cs [ i * 4 + j ] = (
rtP . StateSpace_CS_param [ i + j * 6 ] ) ; } for ( i = 0 ; i < 6 ; i ++ ) {
for ( j = 0 ; j < 7 ; j ++ ) Ds [ i * 7 + j ] = ( rtP . StateSpace_DS_param [
i + j * 6 ] ) ; } { int_T * switch_status = ( int_T * ) rtDW . kfvpshvioz .
SWITCH_STATUS ; int_T * gState = ( int_T * ) rtDW . kfvpshvioz . G_STATE ;
real_T * yswitch = ( real_T * ) rtDW . kfvpshvioz . Y_SWITCH ; int_T *
switchTypes = ( int_T * ) rtDW . kfvpshvioz . SWITCH_TYPES ; int_T * idxOutSw
= ( int_T * ) rtDW . kfvpshvioz . IDX_OUT_SW ; int_T * switch_status_init = (
int_T * ) rtDW . kfvpshvioz . SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ;
switch_status_init [ 0 ] = 0 ; gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] =
1 / 0.1 ; switchTypes [ 0 ] = ( int_T ) 1.0 ; idxOutSw [ 0 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 1 ] = 0 ; switch_status_init [ 1 ] = 0 ; gState [
1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] = 1 / 0.001 ; switchTypes [ 1 ] = ( int_T
) 3.0 ; idxOutSw [ 1 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 2 ] = 0 ;
switch_status_init [ 2 ] = 0 ; gState [ 2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] =
1 / 0.01 ; switchTypes [ 2 ] = ( int_T ) 3.0 ; idxOutSw [ 2 ] = ( ( int_T )
0.0 ) - 1 ; } } rtDW . ef5gie5krl = rtP .
UnitDelay_InitialCondition_hsukbc1fti ; rtDW . mpwvjztsbx = rtP .
UnitDelay1_InitialCondition ; rtDW . gxtljmpzqd = 0.0 ; rtDW . bojdogcykn =
0.0 ; rtDW . gnlmv2t1lw = 0.95 ; } void MdlStart ( void ) { { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void *
* pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { rtDW . kfvpshvioz . AS = ( real_T *
) calloc ( 4 * 4 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . BS = ( real_T *
) calloc ( 4 * 7 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . CS = ( real_T *
) calloc ( 6 * 4 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . DS = ( real_T *
) calloc ( 6 * 7 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . DX_COL = (
real_T * ) calloc ( 6 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . TMP2 = (
real_T * ) calloc ( 7 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . BD_COL = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . TMP1 = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz . XTMP = (
real_T * ) calloc ( 4 , sizeof ( real_T ) ) ; rtDW . kfvpshvioz .
SWITCH_STATUS = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
kfvpshvioz . SW_CHG = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
kfvpshvioz . G_STATE = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ; rtDW .
kfvpshvioz . Y_SWITCH = ( real_T * ) calloc ( 3 , sizeof ( real_T ) ) ; rtDW
. kfvpshvioz . SWITCH_TYPES = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ;
rtDW . kfvpshvioz . IDX_OUT_SW = ( int_T * ) calloc ( 3 , sizeof ( int_T ) )
; rtDW . kfvpshvioz . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 3 , sizeof (
int_T ) ) ; rtDW . kfvpshvioz . USWLAST = ( real_T * ) calloc ( 3 , sizeof (
real_T ) ) ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T
nuoqd30sma ; real_T db3fz3sdqw ; real_T hqwy54gyk3 ; boolean_T dybafv3u5e ;
real_T bdifwf0ops ; real_T bx4gf0nsr5 ; real_T p5crghwysx ; real_T kwqld4h3mx
; real_T pp1rifiy3h ; real_T ilchr0izxz ; boolean_T mpxrxexzvb ; real_T
mnfuqm3pjv ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { nuoqd30sma = rtDW .
fccnxrfig4 ; db3fz3sdqw = rtP . R2_Gain * rtDW . fccnxrfig4 ; hqwy54gyk3 =
1.000001 * db3fz3sdqw * 0.96711798839458663 / 0.9999 ; rtB . koobqpf22y =
rtDW . dtaijnbgzm ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . d0bpobslze
= rtP . Currentfilter_NumCoef * rtDW . knu05efaia ; rtB . ljtvghxtux = ( rtB
. d0bpobslze > rtP . Constant_Value_n3bn4aqtv0 ) ; if ( rtDW . mnxr2r3vae !=
0 ) { rtDW . ocfkalkmt1 = rtB . koobqpf22y ; if ( rtDW . ocfkalkmt1 >= rtP .
inti_UpperSat ) { rtDW . ocfkalkmt1 = rtP . inti_UpperSat ; } else { if (
rtDW . ocfkalkmt1 <= rtP . inti_LowerSat ) { rtDW . ocfkalkmt1 = rtP .
inti_LowerSat ; } } } if ( ( rtB . ljtvghxtux > 0.0 ) && ( rtDW . hvnlljol2x
<= 0 ) ) { rtDW . ocfkalkmt1 = rtB . koobqpf22y ; if ( rtDW . ocfkalkmt1 >=
rtP . inti_UpperSat ) { rtDW . ocfkalkmt1 = rtP . inti_UpperSat ; } else { if
( rtDW . ocfkalkmt1 <= rtP . inti_LowerSat ) { rtDW . ocfkalkmt1 = rtP .
inti_LowerSat ; } } } if ( rtDW . ocfkalkmt1 >= rtP . inti_UpperSat ) { rtDW
. ocfkalkmt1 = rtP . inti_UpperSat ; } else { if ( rtDW . ocfkalkmt1 <= rtP .
inti_LowerSat ) { rtDW . ocfkalkmt1 = rtP . inti_LowerSat ; } } rtB .
n5qsf2ppfq = rtP . Gain_Gain * rtDW . ocfkalkmt1 ; } if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { dybafv3u5e = ( rtB . n5qsf2ppfq > db3fz3sdqw ) ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { if ( rtB . n5qsf2ppfq < rtP .
Constant9_Value ) { rtB . lygq3ygt2j = rtP . Constant9_Value ; } else { rtB .
lygq3ygt2j = rtB . n5qsf2ppfq ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( dybafv3u5e ) { bdifwf0ops = db3fz3sdqw ; } else { bdifwf0ops = rtB .
lygq3ygt2j ; } if ( hqwy54gyk3 <= bdifwf0ops ) { bdifwf0ops = db3fz3sdqw ; }
bx4gf0nsr5 = - 0.0359607110631378 * nuoqd30sma / ( nuoqd30sma - bdifwf0ops )
* bdifwf0ops ; p5crghwysx = - rtB . ljtvghxtux * 0.0359607110631378 * rtB .
d0bpobslze * nuoqd30sma / ( nuoqd30sma - bdifwf0ops ) ; kwqld4h3mx = rtP .
R3_Gain * nuoqd30sma ; if ( ! ( rtB . n5qsf2ppfq > kwqld4h3mx ) ) {
db3fz3sdqw = - kwqld4h3mx * 0.999 * 0.1 * 0.9999 ; if ( rtB . n5qsf2ppfq <
db3fz3sdqw ) { kwqld4h3mx = db3fz3sdqw ; } else { kwqld4h3mx = rtB .
n5qsf2ppfq ; } } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . bsarhrs4kr =
( rtB . d0bpobslze < rtP . Constant_Value_iuuok2jfzc ) ; rtB . e32yfly1mg =
rtDW . kzb1bipvzc ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { switch ( (
int32_T ) rtP . Battery_BatType ) { case 1 : pp1rifiy3h = - ( rtP .
Constant4_Value * rtB . bsarhrs4kr ) * 0.0359607110631378 * ( rtP .
Constant4_Value * rtB . d0bpobslze ) * ( 2.5849999999999933 / ( rtP .
Constant4_Value * kwqld4h3mx + 0.25849999999999934 ) ) ; break ; case 2 :
pp1rifiy3h = rtP . Constant1_Value_drkiaq15p3 * nuoqd30sma ; pp1rifiy3h = - (
rtP . Constant1_Value_drkiaq15p3 * rtB . bsarhrs4kr ) * 0.0359607110631378 *
( rtP . Constant1_Value_drkiaq15p3 * rtB . d0bpobslze ) * pp1rifiy3h / ( rtP
. Constant1_Value_drkiaq15p3 * kwqld4h3mx + pp1rifiy3h * 0.1 ) ; break ; case
3 : pp1rifiy3h = - ( rtP . Constant3_Value * rtB . bsarhrs4kr ) *
0.0359607110631378 * ( rtP . Constant3_Value * rtB . d0bpobslze ) * (
2.5849999999999933 / ( muDoubleScalarAbs ( rtP . Constant3_Value * kwqld4h3mx
) + 0.25849999999999934 ) ) ; break ; default : pp1rifiy3h = - ( rtP .
Constant2_Value * rtB . bsarhrs4kr ) * 0.0359607110631378 * ( rtP .
Constant2_Value * rtB . d0bpobslze ) * ( 2.5849999999999933 / (
muDoubleScalarAbs ( rtP . Constant2_Value * kwqld4h3mx ) +
0.25849999999999934 ) ) ; break ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
rtB . lqkgfyhkru = rtDW . oz5r5rhz1r ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ switch ( ( int32_T ) rtP . Battery_BatType ) { case 1 : ilchr0izxz = rtB .
e32yfly1mg ; break ; case 2 : if ( bdifwf0ops > rtP . Saturation_UpperSat ) {
kwqld4h3mx = rtP . Saturation_UpperSat ; } else if ( bdifwf0ops < rtP .
Saturation_LowerSat ) { kwqld4h3mx = rtP . Saturation_LowerSat ; } else {
kwqld4h3mx = bdifwf0ops ; } ilchr0izxz = muDoubleScalarExp ( -
24.424778761061944 * kwqld4h3mx ) * 1.0077115567411321 ; break ; case 3 :
ilchr0izxz = rtB . e32yfly1mg ; break ; default : ilchr0izxz = rtB .
e32yfly1mg ; break ; } ilchr0izxz = ( ( ( ( bx4gf0nsr5 + p5crghwysx ) +
pp1rifiy3h ) + ilchr0izxz ) + - 0.0 * bdifwf0ops ) + rtP . Constant_Value ;
mpxrxexzvb = ( ilchr0izxz > rtP . Constant1_Value ) ; if ( mpxrxexzvb ) { rtB
. a0f1utn1ur = rtP . Constant1_Value ; } else if ( ilchr0izxz < rtB .
lqkgfyhkru ) { rtB . a0f1utn1ur = rtB . lqkgfyhkru ; } else { rtB .
a0f1utn1ur = ilchr0izxz ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB .
npzp2nktgj = rtDW . kxq3i3a5e0 ; { real_T accum ; int_T * switch_status = (
int_T * ) rtDW . kfvpshvioz . SWITCH_STATUS ; int_T * switch_status_init = (
int_T * ) rtDW . kfvpshvioz . SWITCH_STATUS_INIT ; int_T * SwitchChange = (
int_T * ) rtDW . kfvpshvioz . SW_CHG ; int_T * gState = ( int_T * ) rtDW .
kfvpshvioz . G_STATE ; real_T * yswitch = ( real_T * ) rtDW . kfvpshvioz .
Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . kfvpshvioz . SWITCH_TYPES
; int_T * idxOutSw = ( int_T * ) rtDW . kfvpshvioz . IDX_OUT_SW ; real_T *
DxCol = ( real_T * ) rtDW . kfvpshvioz . DX_COL ; real_T * tmp2 = ( real_T *
) rtDW . kfvpshvioz . TMP2 ; real_T * BDcol = ( real_T * ) rtDW . kfvpshvioz
. BD_COL ; real_T * tmp1 = ( real_T * ) rtDW . kfvpshvioz . TMP1 ; real_T *
uswlast = ( real_T * ) rtDW . kfvpshvioz . USWLAST ; int_T newState ; int_T
swChanged = 0 ; int loopsToDo = 20 ; real_T temp ; memcpy (
switch_status_init , switch_status , 3 * sizeof ( int_T ) ) ; memcpy (
uswlast , & rtB . mxi5esqlco [ 0 ] , 3 * sizeof ( real_T ) ) ; do { if (
loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0 ; i1 < 3 ; i1 ++
) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init [ i1 ] -
switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ] =
switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
kfvpshvioz . CS ; real_T * Ds = ( real_T * ) rtDW . kfvpshvioz . DS ; { int_T
i1 ; real_T * y0 = & rtB . mxi5esqlco [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * (
Cs ++ ) * rtDW . ba0fhn43mf [ 1 ] ; accum += * ( Cs ++ ) * rtDW . ba0fhn43mf
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Ds ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Ds ++ ) * rtB . eunl3qcjlh ; accum += * ( Ds ++ ) * rtB . npzp2nktgj ;
accum += * ( Ds ++ ) * rtP . eee_Value ; y0 [ i1 ] = accum ; } } swChanged =
0 ; newState = gState [ 0 ] > 0 ? 1 : 0 ; swChanged = ( ( SwitchChange [ 0 ]
= newState - switch_status [ 0 ] ) != 0 ) ? 1 : swChanged ; switch_status [ 0
] = newState ; newState = rtB . mxi5esqlco [ 1 ] > 0.0 ? 1 : ( ( rtB .
mxi5esqlco [ 1 ] < 0.0 ) ? 0 : switch_status [ 1 ] ) ; swChanged = ( (
SwitchChange [ 1 ] = newState - switch_status [ 1 ] ) != 0 ) ? 1 : swChanged
; switch_status [ 1 ] = newState ; newState = rtB . mxi5esqlco [ 2 ] > 0.0 ?
1 : ( ( rtB . mxi5esqlco [ 2 ] < 0.0 ) ? 0 : switch_status [ 2 ] ) ;
swChanged = ( ( SwitchChange [ 2 ] = newState - switch_status [ 2 ] ) != 0 )
? 1 : swChanged ; switch_status [ 2 ] = newState ; } if ( swChanged ) {
real_T * As = ( real_T * ) rtDW . kfvpshvioz . AS ; real_T * Cs = ( real_T *
) rtDW . kfvpshvioz . CS ; real_T * Bs = ( real_T * ) rtDW . kfvpshvioz . BS
; real_T * Ds = ( real_T * ) rtDW . kfvpshvioz . DS ; real_T a1 ; { int_T i1
; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { if ( SwitchChange [ i1 ] != 0 ) { a1 =
yswitch [ i1 ] * SwitchChange [ i1 ] ; temp = 1 / ( 1 - Ds [ i1 * 8 ] * a1 )
; { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { DxCol [ i2 ] = Ds [ i2 * 7 +
i1 ] * temp * a1 ; } } DxCol [ i1 ] = temp ; BDcol [ 0 ] = Bs [ 0 + i1 ] * a1
; BDcol [ 1 ] = Bs [ 7 + i1 ] * a1 ; BDcol [ 2 ] = Bs [ 14 + i1 ] * a1 ;
BDcol [ 3 ] = Bs [ 21 + i1 ] * a1 ; memcpy ( tmp1 , & Cs [ i1 * 4 ] , 4 *
sizeof ( real_T ) ) ; memset ( & Cs [ i1 * 4 ] , '\0' , 4 * sizeof ( real_T )
) ; memcpy ( tmp2 , & Ds [ i1 * 7 ] , 7 * sizeof ( real_T ) ) ; memset ( & Ds
[ i1 * 7 ] , '\0' , 7 * sizeof ( real_T ) ) ; { int_T i2 ; for ( i2 = 0 ; i2
< 6 ; i2 ++ ) { a1 = DxCol [ i2 ] ; Cs [ i2 * 4 + 0 ] += a1 * tmp1 [ 0 ] ; Cs
[ i2 * 4 + 1 ] += a1 * tmp1 [ 1 ] ; Cs [ i2 * 4 + 2 ] += a1 * tmp1 [ 2 ] ; Cs
[ i2 * 4 + 3 ] += a1 * tmp1 [ 3 ] ; { int_T i3 ; for ( i3 = 0 ; i3 < 7 ; i3
++ ) { Ds [ i2 * 7 + i3 ] += a1 * tmp2 [ i3 ] ; } } } } a1 = BDcol [ 0 ] ; As
[ 0 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 0 + 1 ] += a1 * Cs [ i1 * 4 + 1 ]
; As [ 0 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 0 + 3 ] += a1 * Cs [ i1 * 4 +
3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 7 ; i2 ++ ) { Bs [ 0 + i2 ] += a1 * Ds
[ i1 * 7 + i2 ] ; } } a1 = BDcol [ 1 ] ; As [ 4 + 0 ] += a1 * Cs [ i1 * 4 + 0
] ; As [ 4 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 4 + 2 ] += a1 * Cs [ i1 * 4
+ 2 ] ; As [ 4 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ;
i2 < 7 ; i2 ++ ) { Bs [ 7 + i2 ] += a1 * Ds [ i1 * 7 + i2 ] ; } } a1 = BDcol
[ 2 ] ; As [ 8 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 8 + 1 ] += a1 * Cs [ i1
* 4 + 1 ] ; As [ 8 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 8 + 3 ] += a1 * Cs
[ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 7 ; i2 ++ ) { Bs [ 14 + i2
] += a1 * Ds [ i1 * 7 + i2 ] ; } } a1 = BDcol [ 3 ] ; As [ 12 + 0 ] += a1 *
Cs [ i1 * 4 + 0 ] ; As [ 12 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 12 + 2 ]
+= a1 * Cs [ i1 * 4 + 2 ] ; As [ 12 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T
i2 ; for ( i2 = 0 ; i2 < 7 ; i2 ++ ) { Bs [ 21 + i2 ] += a1 * Ds [ i1 * 7 +
i2 ] ; } } } } } } } while ( swChanged > 0 && -- loopsToDo > 0 ) ; if (
loopsToDo == 0 ) { real_T * Cs = ( real_T * ) rtDW . kfvpshvioz . CS ; real_T
* Ds = ( real_T * ) rtDW . kfvpshvioz . DS ; { int_T i1 ; real_T * y0 = & rtB
. mxi5esqlco [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ ) { accum = 0.0 ; accum +=
* ( Cs ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * ( Cs ++ ) * rtDW .
ba0fhn43mf [ 1 ] ; accum += * ( Cs ++ ) * rtDW . ba0fhn43mf [ 2 ] ; accum +=
* ( Cs ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Ds ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Ds ++ ) * rtB . eunl3qcjlh ; accum += * ( Ds ++ ) * rtB . npzp2nktgj ;
accum += * ( Ds ++ ) * rtP . eee_Value ; y0 [ i1 ] = accum ; } } } rtB .
hsenihq3bi [ 0 ] = ( real_T ) switch_status [ 0 ] ; rtB . hsenihq3bi [ 1 ] =
( real_T ) switch_status [ 1 ] ; rtB . hsenihq3bi [ 2 ] = ( real_T )
switch_status [ 2 ] ; } rtB . em2nnuuz40 = rtP . donotdeletethisgain_Gain *
rtB . mxi5esqlco [ 4 ] ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { mnfuqm3pjv
= rtDW . ef5gie5krl ; rtB . fbx0qo0g3f = rtDW . mpwvjztsbx ; rtB . iabhbltntc
= rtDW . ef5gie5krl * rtB . fbx0qo0g3f ; } if ( ssIsSampleHit ( rtS , 2 , 0 )
) { rtB . h42gj14eth = rtP . R_Gain * rtB . em2nnuuz40 ; } if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { nuoqd30sma *= rtP . R4_Gain ; nuoqd30sma = ( 1.0 -
bdifwf0ops / nuoqd30sma ) * 100.0 ; if ( nuoqd30sma > rtP .
Saturation_UpperSat_gfnwdnhivs ) { rtB . hilvlxo5dw = rtP .
Saturation_UpperSat_gfnwdnhivs ; } else if ( nuoqd30sma < rtP .
Saturation_LowerSat_ofwy2u1vqp ) { rtB . hilvlxo5dw = rtP .
Saturation_LowerSat_ofwy2u1vqp ; } else { rtB . hilvlxo5dw = nuoqd30sma ; }
rtB . kvt5zhgzbi = rtB . a0f1utn1ur - rtB . h42gj14eth ; rtB . h5bixvn1me =
rtP . Gain2_Gain * bdifwf0ops ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB
. okf5iwwvho = rtP . donotdeletethisgain_Gain_aicr253wuj * rtB . mxi5esqlco [
5 ] ; rtB . iwtvfahc01 = ( ( real_T ) ( rtB . em2nnuuz40 < rtP .
Constant_Value_jqsaqx4mlv ) * rtP . Gain4_Gain - rtB . e32yfly1mg ) *
muDoubleScalarAbs ( rtB . em2nnuuz40 ) * rtP . Gain1_Gain ; rtB . dpwivq0fds
= rtP . R1_Gain * rtB . em2nnuuz40 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
nuoqd30sma = mnfuqm3pjv * rtB . fbx0qo0g3f ; pp1rifiy3h = nuoqd30sma - rtDW .
bojdogcykn ; if ( pp1rifiy3h != 0.0 ) { if ( pp1rifiy3h < 0.0 ) { if (
mnfuqm3pjv - rtDW . gxtljmpzqd < 0.0 ) { rtB . adwlkt4aji = rtDW . gnlmv2t1lw
- 0.0001 ; } else { rtB . adwlkt4aji = rtDW . gnlmv2t1lw + 0.0001 ; } } else
if ( mnfuqm3pjv - rtDW . gxtljmpzqd < 0.0 ) { rtB . adwlkt4aji = rtDW .
gnlmv2t1lw + 0.0001 ; } else { rtB . adwlkt4aji = rtDW . gnlmv2t1lw - 0.0001
; } } else { rtB . adwlkt4aji = rtDW . gnlmv2t1lw ; } if ( ( rtB . adwlkt4aji
>= 0.95 ) || ( rtB . adwlkt4aji < 0.0 ) ) { rtB . adwlkt4aji = rtDW .
gnlmv2t1lw ; } rtDW . gxtljmpzqd = mnfuqm3pjv ; rtDW . bojdogcykn =
nuoqd30sma ; rtDW . gnlmv2t1lw = rtB . adwlkt4aji ; } rtB . iedo3uzdki =
look1_binlxpw ( muDoubleScalarRem ( ssGetT ( rtS ) - 0.0 , rtP .
Constant_Value_g20vuihr23 ) , rtP . LookUpTable1_bp01Data , rtP .
RepeatingSequence_rep_seq_y , 1U ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . gvp50ey4nq = ( rtB . adwlkt4aji >=
rtB . iedo3uzdki ) ; } rtB . jdiw3tifo0 = rtDW . gvp50ey4nq ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . hzgt3pwgdg = rtP .
donotdeletethisgain_Gain_oumtwrk3lg * rtB . mxi5esqlco [ 3 ] ; mnfuqm3pjv =
0.39381 * rtP . PVArray_Nser / rtP . PVArray_Npar * rtB . okf5iwwvho + rtB .
hzgt3pwgdg ; rtB . f1zgdmvpbp = ( ( muDoubleScalarExp ( 1.0 / rtB .
dfm0cs3350 * mnfuqm3pjv ) - rtP . one_Value ) * rtB . n5yaxbsj3n + mnfuqm3pjv
/ ( 313.0553 * rtP . PVArray_Nser / rtP . PVArray_Npar ) * rtB . ngemnoz21l )
- mnfuqm3pjv / rtP . Rsh_array_5Sref_Value ; } UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID4 ( int_T tid ) { real_T pptgizxxl1 ; real_T c0dicviy2w ;
pptgizxxl1 = rtP . Temperature_Value + rtP . u_K_Value ; rtB . ngemnoz21l =
rtP . uSref_Gain * rtP . Irradiance_Value ; rtB . eunl3qcjlh = ( ( pptgizxxl1
- rtP . Tref_K_Value ) * rtP . alpha_Isc_Gain + rtP . IL_module_Value ) * rtP
. PVArray_Npar * rtB . ngemnoz21l ; c0dicviy2w = pptgizxxl1 / rtP .
Tref_K2_Value ; rtB . dfm0cs3350 = 1.5124823630349515 * rtP . PVArray_Nser *
c0dicviy2w ; rtB . n5yaxbsj3n = muDoubleScalarExp ( rtP . EgRef_Value - ( (
pptgizxxl1 - rtP . Tref_K1_Value ) * rtP . dEgdT_Gain + rtP . one1_Value ) *
rtP . EgRef_Gain / ( rtP . k1_Gain * pptgizxxl1 ) ) * ( 2.9273E-10 * rtP .
PVArray_Npar * muDoubleScalarPower ( c0dicviy2w , 3.0 ) ) ; UNUSED_PARAMETER
( tid ) ; } void MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 )
) { rtDW . fccnxrfig4 = rtP . Constant12_Value ; rtDW . dtaijnbgzm = rtB .
h5bixvn1me ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . knu05efaia = (
rtB . em2nnuuz40 - rtP . Currentfilter_DenCoef [ 1 ] * rtDW . knu05efaia ) /
rtP . Currentfilter_DenCoef [ 0 ] ; rtDW . mnxr2r3vae = 0U ; rtDW .
ocfkalkmt1 += rtP . inti_gainval * rtB . em2nnuuz40 ; if ( rtDW . ocfkalkmt1
>= rtP . inti_UpperSat ) { rtDW . ocfkalkmt1 = rtP . inti_UpperSat ; } else {
if ( rtDW . ocfkalkmt1 <= rtP . inti_LowerSat ) { rtDW . ocfkalkmt1 = rtP .
inti_LowerSat ; } } if ( rtB . ljtvghxtux > 0.0 ) { rtDW . hvnlljol2x = 1 ; }
else if ( rtB . ljtvghxtux < 0.0 ) { rtDW . hvnlljol2x = - 1 ; } else if (
rtB . ljtvghxtux == 0.0 ) { rtDW . hvnlljol2x = 0 ; } else { rtDW .
hvnlljol2x = 2 ; } rtDW . kzb1bipvzc += rtP . DiscreteTimeIntegrator_gainval
* rtB . iwtvfahc01 ; rtDW . oz5r5rhz1r = rtB . dpwivq0fds ; rtDW . kxq3i3a5e0
= rtB . f1zgdmvpbp ; { const real_T * As = ( real_T * ) rtDW . kfvpshvioz .
AS ; const real_T * Bs = ( real_T * ) rtDW . kfvpshvioz . BS ; real_T * xtmp
= ( real_T * ) rtDW . kfvpshvioz . XTMP ; real_T accum ; accum = 0.0 ; accum
+= * ( As ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * ( As ++ ) * rtDW .
ba0fhn43mf [ 1 ] ; accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 2 ] ; accum +=
* ( As ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Bs ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Bs ++ ) * rtB . eunl3qcjlh ; accum += * ( Bs ++ ) * rtB . npzp2nktgj ;
accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 0 ] = accum ; accum = 0.0 ;
accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * ( As ++ ) * rtDW
. ba0fhn43mf [ 1 ] ; accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 2 ] ; accum
+= * ( As ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Bs ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Bs ++ ) * rtB . eunl3qcjlh ; accum += * ( Bs ++ ) * rtB . npzp2nktgj ;
accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 1 ] = accum ; accum = 0.0 ;
accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * ( As ++ ) * rtDW
. ba0fhn43mf [ 1 ] ; accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 2 ] ; accum
+= * ( As ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Bs ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Bs ++ ) * rtB . eunl3qcjlh ; accum += * ( Bs ++ ) * rtB . npzp2nktgj ;
accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 2 ] = accum ; accum = 0.0 ;
accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 0 ] ; accum += * ( As ++ ) * rtDW
. ba0fhn43mf [ 1 ] ; accum += * ( As ++ ) * rtDW . ba0fhn43mf [ 2 ] ; accum
+= * ( As ++ ) * rtDW . ba0fhn43mf [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value [ 2 ] ; accum += * ( Bs ++ ) * rtB . a0f1utn1ur ; accum
+= * ( Bs ++ ) * rtB . eunl3qcjlh ; accum += * ( Bs ++ ) * rtB . npzp2nktgj ;
accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 3 ] = accum ; rtDW .
ba0fhn43mf [ 0 ] = xtmp [ 0 ] ; rtDW . ba0fhn43mf [ 1 ] = xtmp [ 1 ] ; rtDW .
ba0fhn43mf [ 2 ] = xtmp [ 2 ] ; rtDW . ba0fhn43mf [ 3 ] = xtmp [ 3 ] ; {
int_T * gState = ( int_T * ) rtDW . kfvpshvioz . G_STATE ; * ( gState ++ ) =
( int_T ) rtB . jdiw3tifo0 ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++
) = ( int_T ) 0.0 ; } } } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW .
ef5gie5krl = rtB . hzgt3pwgdg ; rtDW . mpwvjztsbx = rtB . okf5iwwvho ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV ->
eway5lh1bc = rtB . adwlkt4aji - rtB . iedo3uzdki ; } void MdlTerminate ( void
) { { free ( rtDW . kfvpshvioz . AS ) ; free ( rtDW . kfvpshvioz . BS ) ;
free ( rtDW . kfvpshvioz . CS ) ; free ( rtDW . kfvpshvioz . DS ) ; free (
rtDW . kfvpshvioz . DX_COL ) ; free ( rtDW . kfvpshvioz . TMP2 ) ; free (
rtDW . kfvpshvioz . BD_COL ) ; free ( rtDW . kfvpshvioz . TMP1 ) ; free (
rtDW . kfvpshvioz . XTMP ) ; free ( rtDW . kfvpshvioz . G_STATE ) ; free (
rtDW . kfvpshvioz . SWITCH_STATUS ) ; free ( rtDW . kfvpshvioz . SW_CHG ) ;
free ( rtDW . kfvpshvioz . SWITCH_STATUS_INIT ) ; } if ( rt_slioCatalogue ( )
!= ( NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 4 ) ; ssSetNumBlocks ( rtS , 192 ) ;
ssSetNumBlockIO ( rtS , 31 ) ; ssSetNumBlockParams ( rtS , 183 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 1.0E-6 ) ;
ssSetSampleTime ( rtS , 3 , 0.0001 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 3620723121U ) ; ssSetChecksumVal ( rtS , 1 ,
3273175510U ) ; ssSetChecksumVal ( rtS , 2 , 974960485U ) ; ssSetChecksumVal
( rtS , 3 , 1462179910U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork =
( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork
, 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset
( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo (
rtS , & dtInfo ) ; dtInfo . numDataTypes = 15 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } P_O_Algorithm_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"P_O_Algorithm" ) ; ssSetPath ( rtS , "P_O_Algorithm" ) ; ssSetTStart ( rtS ,
0.0 ) ; ssSetTFinal ( rtS , 3600.0 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; static uint8_T zcAttributes [ 1 ] = { ( ZC_EVENT_ALL
) } ; ssSetStepSize ( rtS , 1.0E-6 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 1.0E-6 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetSolverZcSignalAttrib ( rtS ,
zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 1 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 1 ) ; } ssSetChecksumVal ( rtS , 0 ,
3620723121U ) ; ssSetChecksumVal ( rtS , 1 , 3273175510U ) ; ssSetChecksumVal
( rtS , 2 , 974960485U ) ; ssSetChecksumVal ( rtS , 3 , 1462179910U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 9 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } rtP . Saturation_LowerSat = rtMinusInf ; rtP .
inti_LowerSat = rtMinusInf ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
