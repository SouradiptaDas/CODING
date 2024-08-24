#include "__cf_P_O_Algorithm.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( struct_UYYMc2aeEAvPnDQuQ8RiDB
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "struct_UYYMc2aeEAvPnDQuQ8RiDB" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . d0bpobslze
) , 0 , 0 , 38 } , { ( char_T * ) ( & rtDW . knu05efaia ) , 0 , 0 , 16 } , {
( char_T * ) ( & rtDW . kfvpshvioz . AS ) , 11 , 0 , 5 } , { ( char_T * ) ( &
rtDW . jmio3su4bh [ 0 ] ) , 10 , 0 , 11 } , { ( char_T * ) ( & rtDW .
hvnlljol2x ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . mnxr2r3vae ) , 3 , 0 ,
1 } , { ( char_T * ) ( & rtDW . gvp50ey4nq ) , 8 , 0 , 1 } } ; static
DataTypeTransitionTable rtBTransTable = { 7U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
Battery_BatType ) , 0 , 0 , 183 } } ; static DataTypeTransitionTable
rtPTransTable = { 1U , rtPTransitions } ;
