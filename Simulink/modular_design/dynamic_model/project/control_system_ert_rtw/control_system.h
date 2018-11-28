/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_system.h
 *
 * Code generated for Simulink model 'control_system'.
 *
 * Model version                  : 1.2836
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Aug  2 15:30:27 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_control_system_h_
#define RTW_HEADER_control_system_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef control_system_COMMON_INCLUDES_
# define control_system_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* control_system_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

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

#ifndef DEFINED_TYPEDEF_FOR_Twist_Bus_
#define DEFINED_TYPEDEF_FOR_Twist_Bus_

typedef struct {
  real_T roll;
  real_T pitch;
  real_T yaw;
  real_T thrust;
} Twist_Bus;

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

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T RateTransition3[2];           /* '<S7>/Rate Transition3' */
  real_T RateTransition1[2];           /* '<S7>/Rate Transition1' */
  real_T Diff[2];                      /* '<S21>/Diff' */
  real_T Delay_DSTATE[6];              /* '<Root>/Delay' */
  real_T UD_DSTATE[2];                 /* '<S21>/UD' */
  real_T Integrator_DSTATE[2];         /* '<S22>/Integrator' */
  real_T x[6];                         /* '<Root>/PoseEstimator ' */
  real_T sigma[36];                    /* '<Root>/PoseEstimator ' */
  real_T last_measurement[4];          /* '<Root>/PoseEstimator ' */
  real_T D;                            /* '<S8>/D' */
  real_T UD_DSTATE_f;                  /* '<S24>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S18>/Integrator' */
  real_T Integrator_DSTATE_l;          /* '<S19>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S15>/Integrator' */
  real_T Integrator_DSTATE_k4;         /* '<S16>/Integrator' */
  real_T Integrator_DSTATE_d;          /* '<S20>/Integrator' */
  real_T t_act_sonar;                  /* '<Root>/PoseEstimator ' */
  real_T t_act_gps;                    /* '<Root>/PoseEstimator ' */
  real_T current;                      /* '<Root>/MATLAB Function' */
  boolean_T last_measurement_not_empty;/* '<Root>/PoseEstimator ' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: nodes
   * Referenced by: '<Root>/MATLAB Function'
   */
  real_T MATLABFunction_nodes[33];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  Sensor_Bus measurements;             /* '<Root>/measurements' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  Motor_Bus pwm_cmd;                   /* '<Root>/pwm_cmd' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void control_system_initialize(void);
extern void control_system_step(void);
extern void control_system_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/GPSz_Position_abs' : Unused code path elimination
 * Block '<Root>/Pos_est-mu' : Unused code path elimination
 * Block '<Root>/Pos_est-sigma' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S8>/Manual Switch' : Eliminated due to constant selection input
 * Block '<Root>/XY Graph' : Eliminate redundant data type conversion
 * Block '<Root>/XY Graph' : Eliminate redundant data type conversion
 * Block '<Root>/XY Graph1' : Eliminate redundant data type conversion
 * Block '<Root>/XY Graph1' : Eliminate redundant data type conversion
 * Block '<S8>/Nicolas Ziegler' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'control_system'
 * '<S1>'   : 'control_system/CalcThrust '
 * '<S2>'   : 'control_system/Complementary Filter'
 * '<S3>'   : 'control_system/MATLAB Function'
 * '<S4>'   : 'control_system/PoseEstimator '
 * '<S5>'   : 'control_system/XY Graph2'
 * '<S6>'   : 'control_system/reactive controller'
 * '<S7>'   : 'control_system/simple_path_tracker '
 * '<S8>'   : 'control_system/z-controller'
 * '<S9>'   : 'control_system/Complementary Filter/MATLAB Function1'
 * '<S10>'  : 'control_system/Complementary Filter/MATLAB Function2'
 * '<S11>'  : 'control_system/Complementary Filter/MATLAB Function3'
 * '<S12>'  : 'control_system/Complementary Filter/MATLAB Function4'
 * '<S13>'  : 'control_system/Complementary Filter/MATLAB Function5'
 * '<S14>'  : 'control_system/Complementary Filter/angles from accel'
 * '<S15>'  : 'control_system/reactive controller/pitch_attitude'
 * '<S16>'  : 'control_system/reactive controller/pitch_rate'
 * '<S17>'  : 'control_system/reactive controller/pwm_out1'
 * '<S18>'  : 'control_system/reactive controller/roll_attitude'
 * '<S19>'  : 'control_system/reactive controller/roll_rate'
 * '<S20>'  : 'control_system/reactive controller/yaw_rate'
 * '<S21>'  : 'control_system/simple_path_tracker /Difference'
 * '<S22>'  : 'control_system/simple_path_tracker /Discrete PID Controller'
 * '<S23>'  : 'control_system/simple_path_tracker /MATLAB Function'
 * '<S24>'  : 'control_system/z-controller/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_control_system_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
