//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dynamic_model.h
//
// Code generated for Simulink model 'dynamic_model'.
//
// Model version                  : 1.2334
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Thu Sep 13 12:17:43 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_dynamic_model_h_
#define RTW_HEADER_dynamic_model_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef dynamic_model_COMMON_INCLUDES_
# define dynamic_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // dynamic_model_COMMON_INCLUDES_

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

#define dynamic_model_M                (rtM)

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

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

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real_T ZeroOrderHold1[3];            // '<S79>/Zero-Order Hold1'
  real_T ZeroOrderHold2[3];            // '<S79>/Zero-Order Hold2'
  real_T ZeroOrderHold[3];             // '<S79>/Zero-Order Hold'
  real_T Product2[3];                  // '<S20>/Product2'
  real_T ZeroOrderHold3[3];            // '<S79>/Zero-Order Hold3'
  real_T ZeroOrderHold_g[3];           // '<S80>/Zero-Order Hold'
  real_T ZeroOrderHold1_o[3];          // '<S80>/Zero-Order Hold1'
  real_T Add5[3];                      // '<Root>/Add5'
  real_T RateTransition8[3];           // '<Root>/Rate Transition8'
  real_T RateTransition10[3];          // '<Root>/Rate Transition10'
  real_T Merge[4];                     // '<S11>/Merge'
  real_T Sum[3];                       // '<S1>/Sum'
  real_T Product_j[3];                 // '<S25>/Product'
  real_T TmpRTBAtAdd8Inport2[3];       // '<Root>/Band-Limited White Noise2'
  real_T Add8[3];                      // '<Root>/Add8'
  real_T RateTransition11[3];          // '<Root>/Rate Transition11'
  real_T TmpRTBAtProductOutport1[8];   // '<S18>/Product'
  real_T TransferFcn3_states[2];       // '<S18>/Transfer Fcn3'
  real_T TransferFcn1_states[2];       // '<S18>/Transfer Fcn1'
  real_T TransferFcn2_states[2];       // '<S18>/Transfer Fcn2'
  real_T TransferFcn4_states[2];       // '<S18>/Transfer Fcn4'
  real_T TransferFcn5_states[2];       // '<S18>/Transfer Fcn5'
  real_T TransferFcn6_states[2];       // '<S18>/Transfer Fcn6'
  real_T TransferFcn7_states[2];       // '<S18>/Transfer Fcn7'
  real_T TransferFcn8_states[2];       // '<S18>/Transfer Fcn8'
  real_T Product2_DWORK4[9];           // '<S20>/Product2'
  real_T NextOutput[3];                // '<S82>/White Noise'
  real_T NextOutput_p[3];              // '<S99>/White Noise'
  real_T RateTransition10_Buffer0[3];  // '<Root>/Rate Transition10'
  real_T TmpRTBAtAdd8Inport2_Buffer0[3];// synthesized block
  real_T NextOutput_ls[3];             // '<S6>/White Noise'
  real_T TmpRTBAtProductOutport1_Buffer0[8];// synthesized block
  real_T VectorConcatenate[9];         // '<S39>/Vector Concatenate'
  real_T A[9];
  real_T thrust[8];
  real_T mx[8];
  real_T mz[8];
  real_T TmpSignalConversionAtSFunctionInport5[8];// '<Root>/multicopter'
  real_T forces[3];                    // '<Root>/multicopter'
  real_T Sum_p[3];                     // '<S22>/Sum'
  real_T dv0[3];
  real_T dv1[3];
  real_T y[8];
  real_T TmpSignalConversionAtSFunctionInport1[8];// '<Root>/LiPo Battery'
  real_T Product_o[8];                 // '<S18>/Product'
  real_T Saturation_p[3];              // '<S80>/Saturation'
  real_T WhiteNoise_f[3];              // '<S6>/White Noise'
  real_T Output_g2[3];                 // '<S6>/Output'
  real_T TransferFcn3;                 // '<S18>/Transfer Fcn3'
  real_T TransferFcn1;                 // '<S18>/Transfer Fcn1'
  real_T TransferFcn2;                 // '<S18>/Transfer Fcn2'
  real_T TransferFcn4;                 // '<S18>/Transfer Fcn4'
  real_T TransferFcn5;                 // '<S18>/Transfer Fcn5'
  real_T TransferFcn6;                 // '<S18>/Transfer Fcn6'
  real_T TransferFcn7;                 // '<S18>/Transfer Fcn7'
  real_T TransferFcn8;                 // '<S18>/Transfer Fcn8'
  real_T TmpRTBAtAdd5Inport2;          // '<Root>/Band-Limited White Noise1'
  real_T q0dot;                        // '<S29>/q0dot'
  real_T q1dot;                        // '<S29>/q1dot'
  real_T q2dot;                        // '<S29>/q2dot'
  real_T q3dot;                        // '<S29>/q3dot'
  real_T TmpRTBAtAdd2Inport2;          // '<Root>/Band-Limited White Noise3'
  real_T Saturation2;                  // '<Root>/Saturation2'
  real_T RateTransition2;              // '<Root>/Rate Transition2'
  real_T SimulationPace;               // '<Root>/Simulation Pace'
  real_T TmpRTBAtAdd5Inport2_Buffer0;  // synthesized block
  real_T RateTransition7_Buffer0;      // '<Root>/Rate Transition7'
  real_T TmpRTBAtAdd2Inport2_Buffer0;  // synthesized block
  real_T NextOutput_l;                 // '<S5>/White Noise'
  real_T NextOutput_m;                 // '<S7>/White Noise'
  real_T discharge;                    // '<Root>/LiPo Battery'
  real_T jxi_a;                        // '<S52>/j x i'
  real_T ixk_b;                        // '<S52>/i x k'
  real_T kxj_m;                        // '<S52>/k x j'
  real_T ixj_i;                        // '<S51>/i x j'
  real_T kxi_c;                        // '<S51>/k x i'
  real_T supply_voltage;
  real_T b_y;
  int_T q0q1q2q3_IWORK;                // '<S19>/q0 q1 q2 q3'
  uint32_T RandSeed[3];                // '<S82>/White Noise'
  uint32_T RandSeed_j[3];              // '<S99>/White Noise'
  uint32_T RandSeed_li[3];             // '<S6>/White Noise'
  uint32_T RandSeed_l;                 // '<S5>/White Noise'
  uint32_T RandSeed_o;                 // '<S7>/White Noise'
  int8_T If_ActiveSubsystem;           // '<S11>/If'
  int8_T FindMaximumDiagonalValue_ActiveSubsystem;// '<S53>/Find Maximum Diagonal Value' 
} DW;

// Continuous states (auto storage)
typedef struct {
  real_T pqr_CSTATE[3];                // '<S1>/p,q,r '
  real_T q0q1q2q3_CSTATE[4];           // '<S19>/q0 q1 q2 q3'
  real_T ubvbwb_CSTATE[3];             // '<S1>/ub,vb,wb'
  real_T xeyeze_CSTATE[3];             // '<S1>/xe,ye,ze'
} X;

// State derivatives (auto storage)
typedef struct {
  real_T pqr_CSTATE[3];                // '<S1>/p,q,r '
  real_T q0q1q2q3_CSTATE[4];           // '<S19>/q0 q1 q2 q3'
  real_T ubvbwb_CSTATE[3];             // '<S1>/ub,vb,wb'
  real_T xeyeze_CSTATE[3];             // '<S1>/xe,ye,ze'
} XDot;

// State disabled
typedef struct {
  boolean_T pqr_CSTATE[3];             // '<S1>/p,q,r '
  boolean_T q0q1q2q3_CSTATE[4];        // '<S19>/q0 q1 q2 q3'
  boolean_T ubvbwb_CSTATE[3];          // '<S1>/ub,vb,wb'
  boolean_T xeyeze_CSTATE[3];          // '<S1>/xe,ye,ze'
} XDis;

// Invariant block signals (auto storage)
typedef const struct tag_ConstB {
  real_T q0;                           // '<S28>/q0'
  real_T q1;                           // '<S28>/q1'
  real_T q2;                           // '<S28>/q2'
  real_T q3;                           // '<S28>/q3'
  real_T Selector[9];                  // '<S20>/Selector'
  real_T Selector2[9];                 // '<S20>/Selector2'
  real_T Saturation6;                  // '<S17>/Saturation6'
  real_T Saturation7;                  // '<S17>/Saturation7'
  real_T Saturation8;                  // '<S17>/Saturation8'
  real_T Saturation9;                  // '<S17>/Saturation9'
} ConstB;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Constant parameters (auto storage)
typedef struct {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S79>/Scale factors & Cross-coupling  errors'
  //    '<S80>/Scale factors & Cross-coupling  errors '

  real_T pooled5[9];
} ConstP;

// External inputs (root inport signals with auto storage)
typedef struct {
  Motor_Bus controls;                  // '<Root>/pwm_cmd'
} ExtU;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  Sensor_Bus measurements;             // '<Root>/measurements'
  real_T position_O[3];                // '<Root>/position_O'
  real_T attitude_O[4];                // '<Root>/attitude_O'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
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
    boolean_T firstInitCondFlag;
    struct {
      uint16_T TID[6];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
      boolean_T TID1_4;
      boolean_T TID1_5;
      boolean_T TID2_4;
      boolean_T TID2_5;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[6];
  } Timing;
};

// Continuous states (auto storage)
extern X rtX;

// Block signals and states (auto storage)
extern DW rtDW;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with auto storage)
  extern ExtU rtU;

  // External outputs (root outports fed by signals with auto storage)
  extern ExtY rtY;

#ifdef __cplusplus

}
#endif

extern const ConstB rtConstB;          // constant block i/o

// Constant parameters (auto storage)
extern const ConstP rtConstP;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void dynamic_model_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void dynamic_model_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void dynamic_model_initialize(void);
  extern void dynamic_model_step0(void);
  extern void dynamic_model_step(int_T tid);
  extern void dynamic_model_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S24>/Unit Conversion' : Unused code path elimination
//  Block '<Root>/Add1' : Unused code path elimination
//  Block '<Root>/Add3' : Unused code path elimination
//  Block '<S2>/Unit Conversion' : Unused code path elimination
//  Block '<S3>/Unit Conversion' : Unused code path elimination
//  Block '<S4>/Unit Conversion' : Unused code path elimination
//  Block '<S8>/Output' : Unused code path elimination
//  Block '<S8>/White Noise' : Unused code path elimination
//  Block '<S9>/Output' : Unused code path elimination
//  Block '<S9>/White Noise' : Unused code path elimination
//  Block '<S10>/Output' : Unused code path elimination
//  Block '<S10>/White Noise' : Unused code path elimination
//  Block '<Root>/Constant' : Unused code path elimination
//  Block '<Root>/Fcn' : Unused code path elimination
//  Block '<Root>/Gain1' : Unused code path elimination
//  Block '<Root>/Gain2' : Unused code path elimination
//  Block '<S12>/P0' : Unused code path elimination
//  Block '<S12>/Product2' : Unused code path elimination
//  Block '<S12>/a' : Unused code path elimination
//  Block '<S12>/gamma*R' : Unused code path elimination
//  Block '<Root>/LiPo Cell Voltage' : Unused code path elimination
//  Block '<Root>/Rate Transition3' : Unused code path elimination
//  Block '<Root>/Rate Transition4' : Unused code path elimination
//  Block '<Root>/Rate Transition6' : Unused code path elimination
//  Block '<Root>/Rate Transition9' : Unused code path elimination
//  Block '<Root>/Saturation1' : Unused code path elimination
//  Block '<Root>/pace error' : Unused code path elimination
//  Block '<Root>/runtime' : Unused code path elimination
//  Block '<Root>/simulation_data' : Unused code path elimination
//  Block '<S39>/Reshape (9) to [3x3] column-major' : Reshape block reduction
//  Block '<S29>/High Gain Quaternion Normalization' : Eliminated nontunable gain of 1
//  Block '<S46>/Reshape1' : Reshape block reduction
//  Block '<S46>/Reshape2' : Reshape block reduction
//  Block '<S47>/Reshape1' : Reshape block reduction
//  Block '<S47>/Reshape2' : Reshape block reduction
//  Block '<S20>/Reshape' : Reshape block reduction
//  Block '<S20>/Reshape1' : Reshape block reduction
//  Block '<S23>/Unit Conversion' : Eliminated nontunable gain of 1
//  Block '<S25>/Reshape1' : Reshape block reduction
//  Block '<S25>/Reshape2' : Reshape block reduction
//  Block '<S11>/Reshape 3x3 -> 9' : Reshape block reduction
//  Block '<S81>/Switch' : Eliminated due to constant selection input
//  Block '<S79>/Reshape1' : Reshape block reduction
//  Block '<S79>/Zero-Order Hold4' : Eliminated since input and output rates are identical
//  Block '<S98>/Switch' : Eliminated due to constant selection input
//  Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
//  Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
//  Block '<S81>/Constant' : Unused code path elimination
//  Block '<S87>/Discrete Transfer Fcn' : Unused code path elimination
//  Block '<S88>/Discrete Transfer Fcn' : Unused code path elimination
//  Block '<S89>/Discrete Transfer Fcn' : Unused code path elimination
//  Block '<S98>/Constant' : Unused code path elimination
//  Block '<S102>/Discrete Transfer Fcn' : Unused code path elimination
//  Block '<S103>/Discrete Transfer Fcn' : Unused code path elimination
//  Block '<S104>/Discrete Transfer Fcn' : Unused code path elimination


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
//  '<Root>' : 'dynamic_model'
//  '<S1>'   : 'dynamic_model/6DoF (Quaternion)'
//  '<S2>'   : 'dynamic_model/Angle Conversion'
//  '<S3>'   : 'dynamic_model/Angular Velocity Conversion1'
//  '<S4>'   : 'dynamic_model/Angular Velocity Conversion2'
//  '<S5>'   : 'dynamic_model/Band-Limited White Noise1'
//  '<S6>'   : 'dynamic_model/Band-Limited White Noise2'
//  '<S7>'   : 'dynamic_model/Band-Limited White Noise3'
//  '<S8>'   : 'dynamic_model/Band-Limited White Noise4'
//  '<S9>'   : 'dynamic_model/Band-Limited White Noise5'
//  '<S10>'  : 'dynamic_model/Band-Limited White Noise6'
//  '<S11>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions'
//  '<S12>'  : 'dynamic_model/ISA Atmosphere Model'
//  '<S13>'  : 'dynamic_model/Invensense MPU-6000'
//  '<S14>'  : 'dynamic_model/LiPo Battery'
//  '<S15>'  : 'dynamic_model/MATLAB Function'
//  '<S16>'  : 'dynamic_model/multicopter'
//  '<S17>'  : 'dynamic_model/normalize'
//  '<S18>'  : 'dynamic_model/transfer_function'
//  '<S19>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles'
//  '<S20>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot'
//  '<S21>'  : 'dynamic_model/6DoF (Quaternion)/Determine Force,  Mass & Inertia'
//  '<S22>'  : 'dynamic_model/6DoF (Quaternion)/Vbxw'
//  '<S23>'  : 'dynamic_model/6DoF (Quaternion)/Velocity Conversion'
//  '<S24>'  : 'dynamic_model/6DoF (Quaternion)/Velocity Conversion1'
//  '<S25>'  : 'dynamic_model/6DoF (Quaternion)/transform to Inertial axes '
//  '<S26>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix'
//  '<S27>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles'
//  '<S28>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Rotation Angles to Quaternions'
//  '<S29>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/qdot'
//  '<S30>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A11'
//  '<S31>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A12'
//  '<S32>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A13'
//  '<S33>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A21'
//  '<S34>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A22'
//  '<S35>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A23'
//  '<S36>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A31'
//  '<S37>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A32'
//  '<S38>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/A33'
//  '<S39>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Create Transformation Matrix'
//  '<S40>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
//  '<S41>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
//  '<S42>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S43>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S44>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S45>'  : 'dynamic_model/6DoF (Quaternion)/Calculate DCM & Euler Angles/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S46>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot/I x w'
//  '<S47>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot/I x w1'
//  '<S48>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot/wx(Iw)'
//  '<S49>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot/wx(Iw)/Subsystem'
//  '<S50>'  : 'dynamic_model/6DoF (Quaternion)/Calculate omega_dot/wx(Iw)/Subsystem1'
//  '<S51>'  : 'dynamic_model/6DoF (Quaternion)/Vbxw/Subsystem'
//  '<S52>'  : 'dynamic_model/6DoF (Quaternion)/Vbxw/Subsystem1'
//  '<S53>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace'
//  '<S54>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Positive Trace'
//  '<S55>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/trace(DCM)'
//  '<S56>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
//  '<S57>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
//  '<S58>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
//  '<S59>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
//  '<S60>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S61>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S62>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S63>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
//  '<S64>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
//  '<S65>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S66>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S67>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S68>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
//  '<S69>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
//  '<S70>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
//  '<S71>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S72>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S73>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
//  '<S74>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
//  '<S75>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
//  '<S76>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
//  '<S77>'  : 'dynamic_model/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
//  '<S78>'  : 'dynamic_model/Invensense MPU-6000/Acceleration Conversion'
//  '<S79>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer'
//  '<S80>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope'
//  '<S81>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics'
//  '<S82>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Random bias'
//  '<S83>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)'
//  '<S84>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/wdot x d'
//  '<S85>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics/No Dynamics'
//  '<S86>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics/Second-order Dynamics'
//  '<S87>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics/Second-order Dynamics/Transfer Fcn X'
//  '<S88>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics/Second-order Dynamics/Transfer Fcn Y'
//  '<S89>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/Dynamics/Second-order Dynamics/Transfer Fcn Z'
//  '<S90>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x (w x d)'
//  '<S91>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x d'
//  '<S92>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem'
//  '<S93>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem1'
//  '<S94>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem'
//  '<S95>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem1'
//  '<S96>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/wdot x d/Subsystem'
//  '<S97>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Accelerometer/wdot x d/Subsystem1'
//  '<S98>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics'
//  '<S99>'  : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Random bias'
//  '<S100>' : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics/No Dynamics'
//  '<S101>' : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics/Second-order Dynamics'
//  '<S102>' : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics/Second-order Dynamics/Transfer Fcn X'
//  '<S103>' : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics/Second-order Dynamics/Transfer Fcn Y'
//  '<S104>' : 'dynamic_model/Invensense MPU-6000/Three-axis Gyroscope/Dynamics/Second-order Dynamics/Transfer Fcn Z'

#endif                                 // RTW_HEADER_dynamic_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
