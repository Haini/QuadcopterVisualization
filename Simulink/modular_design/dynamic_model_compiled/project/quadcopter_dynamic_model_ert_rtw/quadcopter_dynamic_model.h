//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: quadcopter_dynamic_model.h
//
// Code generated for Simulink model 'quadcopter_dynamic_model'.
//
// Model version                  : 1.2393
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Thu Sep 13 12:16:23 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_quadcopter_dynamic_model_h_
#define RTW_HEADER_quadcopter_dynamic_model_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef quadcopter_dynamic_model_COMMON_INCLUDES_
# define quadcopter_dynamic_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // quadcopter_dynamic_model_COMMON_INCLUDES_ 

// Shared type includes
#include "model_reference_types.h"

// Child system includes
#define dynamic_model_MDLREF_HIDE_CHILD_
#include "dynamic_model.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_modd_snf.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Forward declaration for rtModel
typedef struct tag_RTM_quadcopter_dynamic_model_T
  RT_MODEL_quadcopter_dynamic_model_T;

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_MultiArrayDimension_atxfxt_
#define DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_MultiArrayDimension_atxfxt_

// MsgType=std_msgs/MultiArrayDimension
typedef struct {
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Label_SL_Info:TruncateAction=warn 
  uint8_T Label[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Label
  SL_Bus_ROSVariableLengthArrayInfo Label_SL_Info;
  uint32_T Size;
  uint32_T Stride;
} SL_Bus_quadcopter_dynamic_model_MultiArrayDimension_atxfxt;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_std_msgs_MultiArrayLayout_
#define DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_std_msgs_MultiArrayLayout_

// MsgType=std_msgs/MultiArrayLayout
typedef struct {
  uint32_T DataOffset;

  // MsgType=std_msgs/MultiArrayDimension:IsVarLen=1:VarLenCategory=data:VarLenElem=Dim_SL_Info:TruncateAction=warn 
  SL_Bus_quadcopter_dynamic_model_MultiArrayDimension_atxfxt Dim[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Dim
  SL_Bus_ROSVariableLengthArrayInfo Dim_SL_Info;
} SL_Bus_quadcopter_dynamic_model_std_msgs_MultiArrayLayout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray_

// MsgType=std_msgs/Float32MultiArray
typedef struct {
  // IsVarLen=1:VarLenCategory=data:VarLenElem=Data_SL_Info:TruncateAction=warn
  real32_T Data[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Data
  SL_Bus_ROSVariableLengthArrayInfo Data_SL_Info;

  // MsgType=std_msgs/MultiArrayLayout
  SL_Bus_quadcopter_dynamic_model_std_msgs_MultiArrayLayout Layout;
} SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_quadcopter_dynamic_model_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_quadcopter_dynamic_model_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_quadcopter_dynamic_model_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Motor_Bus_
#define DEFINED_TYPEDEF_FOR_Motor_Bus_

typedef struct {
  real_T pwm1;
  real_T pwm2;
  real_T pwm3;
  real_T pwm4;
} Motor_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sensor_Bus_
#define DEFINED_TYPEDEF_FOR_Sensor_Bus_

typedef struct {
  real_T acc_x;
  real_T acc_y;
  real_T acc_z;
  real_T gyro_x;
  real_T gyro_y;
  real_T gyro_z;
  real_T att_x;
  real_T att_y;
  real_T att_z;
  real_T gps_n;
  real_T gps_e;
  real_T gps_d;
  real_T sonar_z;
  real_T bat_volt;
} Sensor_Bus;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T
#define typedef_robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH
  robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T;

#endif                                 //typedef_robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_Subscriber_quadcopter_dynamic_model_T
#define typedef_robotics_slros_internal_block_Subscriber_quadcopter_dynamic_model_T

typedef struct tag_saG5948SFTrUFnIbVUb0TZH
  robotics_slros_internal_block_Subscriber_quadcopter_dynamic_model_T;

#endif                                 //typedef_robotics_slros_internal_block_Subscriber_quadcopter_dynamic_model_T

#ifndef typedef_struct_T_quadcopter_dynamic_model_T
#define typedef_struct_T_quadcopter_dynamic_model_T

typedef struct {
  real_T f0[2];
} struct_T_quadcopter_dynamic_model_T;

#endif                                 //typedef_struct_T_quadcopter_dynamic_model_T

#ifndef typedef_struct_T_quadcopter_dynamic_model_i_T
#define typedef_struct_T_quadcopter_dynamic_model_i_T

typedef struct {
  char_T f0[4];
} struct_T_quadcopter_dynamic_model_i_T;

#endif                                 //typedef_struct_T_quadcopter_dynamic_model_i_T

#ifndef typedef_struct_T_quadcopter_dynamic_model_id_T
#define typedef_struct_T_quadcopter_dynamic_model_id_T

typedef struct {
  char_T f0[8];
} struct_T_quadcopter_dynamic_model_id_T;

#endif                                 //typedef_struct_T_quadcopter_dynamic_model_id_T

#ifndef typedef_struct_T_quadcopter_dynamic_model_idx_T
#define typedef_struct_T_quadcopter_dynamic_model_idx_T

typedef struct {
  char_T f0[7];
} struct_T_quadcopter_dynamic_model_idx_T;

#endif                                 //typedef_struct_T_quadcopter_dynamic_model_idx_T

#ifndef typedef_struct_T_quadcopter_dynamic_model_idxx_T
#define typedef_struct_T_quadcopter_dynamic_model_idxx_T

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_quadcopter_dynamic_model_idxx_T;

#endif                                 //typedef_struct_T_quadcopter_dynamic_model_idxx_T

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray In1;// '<S20>/In1'
  SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_quadcopter_dynamic_model_geometry_msgs_Quaternion BusAssignment1;// '<S4>/Bus Assignment1' 
  SL_Bus_quadcopter_dynamic_model_geometry_msgs_Point BusAssignment_a;// '<S4>/Bus Assignment' 
  robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T obj;// '<S11>/SinkBlock' 
  robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T obj_h;// '<S10>/SinkBlock' 
  robotics_slros_internal_block_Publisher_quadcopter_dynamic_model_T obj_n;// '<S3>/SinkBlock' 
  robotics_slros_internal_block_Subscriber_quadcopter_dynamic_model_T obj_g;// '<S5>/SourceBlock' 
  real_T DataTypeConversion1[4];       // '<Root>/Data Type Conversion1'
  real_T dynamic_model_o15[3];         // '<Root>/dynamic_model'
  real_T dynamic_model_o16[4];         // '<Root>/dynamic_model'
  real_T y[128];                       // '<Root>/MATLAB Function'
  real_T TmpSignalConversionAtSFunctionInport1[14];// '<Root>/MATLAB Function'
  real_T Switch3[3];                   // '<S13>/Switch3'
  real_T GainKu[3];                    // '<S12>/Gain K*u'
  real_T acc_x;                        // '<Root>/dynamic_model'
  real_T acc_y;                        // '<Root>/dynamic_model'
  real_T acc_z;                        // '<Root>/dynamic_model'
  real_T gyro_x;                       // '<Root>/dynamic_model'
  real_T gyro_y;                       // '<Root>/dynamic_model'
  real_T gyro_z;                       // '<Root>/dynamic_model'
  real_T att_x;                        // '<Root>/dynamic_model'
  real_T att_y;                        // '<Root>/dynamic_model'
  real_T att_z;                        // '<Root>/dynamic_model'
  real_T gps_n;                        // '<Root>/dynamic_model'
  real_T gps_e;                        // '<Root>/dynamic_model'
  real_T gps_d;                        // '<Root>/dynamic_model'
  real_T sonar_z;                      // '<Root>/dynamic_model'
  real_T bat_volt;                     // '<Root>/dynamic_model'
  void *SourceBlock_PWORK;             // '<S5>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S11>/SinkBlock'
  void *SinkBlock_PWORK_e;             // '<S10>/SinkBlock'
  void *SinkBlock_PWORK_a;             // '<S3>/SinkBlock'
  int32_T i;
  char_T cv0[23];
  char_T cv1[20];
  boolean_T objisempty;                // '<S5>/SourceBlock'
  boolean_T objisempty_m;              // '<S11>/SinkBlock'
  boolean_T objisempty_g;              // '<S10>/SinkBlock'
  boolean_T objisempty_a;              // '<S3>/SinkBlock'
} DW_quadcopter_dynamic_model_T;

// Continuous states (auto storage)
typedef struct {
  real_T dynamic_model_CSTATE[13];     // '<Root>/dynamic_model'
} X_quadcopter_dynamic_model_T;

// State derivatives (auto storage)
typedef struct {
  real_T dynamic_model_CSTATE[13];     // '<Root>/dynamic_model'
} XDot_quadcopter_dynamic_model_T;

// State disabled
typedef struct {
  boolean_T dynamic_model_CSTATE[13];  // '<Root>/dynamic_model'
} XDis_quadcopter_dynamic_model_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Real-time Model Data Structure
struct tag_RTM_quadcopter_dynamic_model_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_quadcopter_dynamic_model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[13];
  real_T odeF[3][13];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick5;
    uint32_T clockTick6;
    boolean_T firstInitCondFlag;
    struct {
      uint32_T TID[7];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
      boolean_T TID1_5;
      boolean_T TID1_6;
      boolean_T TID2_5;
      boolean_T TID2_6;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[7];
  } Timing;
};

extern rtTimingBridge quadcopter_dynamic_model_TimingBrdg;

// Continuous states (auto storage)
extern X_quadcopter_dynamic_model_T quadcopter_dynamic_model_X;

// Block signals and states (auto storage)
extern DW_quadcopter_dynamic_model_T quadcopter_dynamic_model_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// External data declarations for dependent source files
extern const SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray
  quadcopter_dynamic_model_rtZSL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray;// SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray ground 

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void quadcopter_dynamic_model_SetEventsForThisBaseStep(boolean_T
    *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void quadcopter_dynamic_model_SetEventsForThisBaseStep(boolean_T
    *eventFlags);
  extern void quadcopter_dynamic_model_initialize(void);
  extern void quadcopter_dynamic_model_step0(void);
  extern void quadcopter_dynamic_model_step(int_T tid);
  extern void quadcopter_dynamic_model_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_quadcopter_dynamic_model_T *const quadcopter_dynamic_model_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S4>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S4>/Rate Transition1' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'quadcopter_dynamic_model'
//  '<S1>'   : 'quadcopter_dynamic_model/Blank Message'
//  '<S2>'   : 'quadcopter_dynamic_model/MATLAB Function'
//  '<S3>'   : 'quadcopter_dynamic_model/Publish'
//  '<S4>'   : 'quadcopter_dynamic_model/ROS'
//  '<S5>'   : 'quadcopter_dynamic_model/Subscribe'
//  '<S6>'   : 'quadcopter_dynamic_model/ROS/NED to VR-vector1'
//  '<S7>'   : 'quadcopter_dynamic_model/ROS/Point Message Template'
//  '<S8>'   : 'quadcopter_dynamic_model/ROS/Quat to VR'
//  '<S9>'   : 'quadcopter_dynamic_model/ROS/Quaternion Message Template'
//  '<S10>'  : 'quadcopter_dynamic_model/ROS/attitude'
//  '<S11>'  : 'quadcopter_dynamic_model/ROS/position'
//  '<S12>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/NED to VR-vector'
//  '<S13>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose'
//  '<S14>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Compare To Constant'
//  '<S15>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Quat Abs'
//  '<S16>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Quat Normalize'
//  '<S17>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Quat Abs/Euclidean_Norm'
//  '<S18>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Quat Normalize/Quat Abs'
//  '<S19>'  : 'quadcopter_dynamic_model/ROS/Quat to VR/Quat Decompose/Quat Normalize/Quat Abs/Euclidean_Norm'
//  '<S20>'  : 'quadcopter_dynamic_model/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_quadcopter_dynamic_model_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
