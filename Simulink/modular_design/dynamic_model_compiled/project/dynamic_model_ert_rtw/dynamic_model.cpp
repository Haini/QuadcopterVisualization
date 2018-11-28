//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dynamic_model.cpp
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
#include "dynamic_model.h"
#define NumBitsPerChar                 8U

// Private macros used by the generated code to access rtModel
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

// Continuous states
X rtX;

// Block signals and states (auto storage)
DW rtDW;

// External inputs (root inport signals with auto storage)
ExtU rtU;

// External outputs (root outports fed by signals with auto storage)
ExtY rtY;

// Real-time model
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern void dynamic_model_step0(void);
extern void dynamic_model_step2(void);
extern void dynamic_model_step3(void);
extern void dynamic_model_step4(void);
extern void dynamic_model_step5(void); // private model entry point functions
extern void dynamic_model_derivatives(void);

// Forward declaration for local functions
static void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf_i(const real_T u0[3], const
  real_T u1[9], real_T y[3]);
static void rate_monotonic_scheduler(void);
extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   // do nothing
# else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    return (boolean_T)((value!=value) ? 1U : 0U);
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    return (boolean_T)(((value!=value) ? 1U : 0U));
  }
}
//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
  void dynamic_model_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[2] = ((boolean_T)rtmStepTask(rtM, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(rtM, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(rtM, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(rtM, 5));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 2
  rtM->Timing.RateInteraction.TID0_2 = (rtM->Timing.TaskCounters.TID[2] == 0);

  // tid 1 shares data with slower tid rates: 2, 4, 5
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtM->Timing.RateInteraction.TID1_2 = (rtM->Timing.TaskCounters.TID[2] == 0);
    rtM->Timing.RateInteraction.TID1_4 = (rtM->Timing.TaskCounters.TID[4] == 0);
    rtM->Timing.RateInteraction.TID1_5 = (rtM->Timing.TaskCounters.TID[5] == 0);
  }

  // tid 2 shares data with slower tid rates: 4, 5
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    rtM->Timing.RateInteraction.TID2_4 = (rtM->Timing.TaskCounters.TID[4] == 0);
    rtM->Timing.RateInteraction.TID2_5 = (rtM->Timing.TaskCounters.TID[5] == 0);
  }

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 3) {// Sample time: [0.004s, 0.0s]
    rtM->Timing.TaskCounters.TID[2] = 0;
  }

  (rtM->Timing.TaskCounters.TID[3])++;
  if ((rtM->Timing.TaskCounters.TID[3]) > 7) {// Sample time: [0.008s, 0.0s]
    rtM->Timing.TaskCounters.TID[3] = 0;
  }

  (rtM->Timing.TaskCounters.TID[4])++;
  if ((rtM->Timing.TaskCounters.TID[4]) > 99) {// Sample time: [0.1s, 0.0s]
    rtM->Timing.TaskCounters.TID[4] = 0;
  }

  (rtM->Timing.TaskCounters.TID[5])++;
  if ((rtM->Timing.TaskCounters.TID[5]) > 199) {// Sample time: [0.2s, 0.0s]
    rtM->Timing.TaskCounters.TID[5] = 0;
  }
}

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  dynamic_model_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  dynamic_model_step0();
  dynamic_model_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  dynamic_model_step0();
  dynamic_model_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf_i(const real_T u0[3], const
  real_T u1[9], real_T y[3])
{
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&rtDW.A[0], &u1[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u1[0]);
  a21 = fabs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  rtDW.A[r2] = u1[r2] / u1[r1];
  rtDW.A[r3] /= rtDW.A[r1];
  rtDW.A[3 + r2] -= rtDW.A[3 + r1] * rtDW.A[r2];
  rtDW.A[3 + r3] -= rtDW.A[3 + r1] * rtDW.A[r3];
  rtDW.A[6 + r2] -= rtDW.A[6 + r1] * rtDW.A[r2];
  rtDW.A[6 + r3] -= rtDW.A[6 + r1] * rtDW.A[r3];
  if (fabs(rtDW.A[3 + r3]) > fabs(rtDW.A[3 + r2])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  rtDW.A[3 + r3] /= rtDW.A[3 + r2];
  rtDW.A[6 + r3] -= rtDW.A[3 + r3] * rtDW.A[6 + r2];
  y[r1] = u0[0] / rtDW.A[r1];
  y[r2] = u0[1] - rtDW.A[3 + r1] * y[r1];
  y[r3] = u0[2] - rtDW.A[6 + r1] * y[r1];
  y[r2] /= rtDW.A[3 + r2];
  y[r3] -= rtDW.A[6 + r2] * y[r2];
  y[r3] /= rtDW.A[6 + r3];
  y[r2] -= rtDW.A[3 + r3] * y[r3];
  y[r1] -= y[r3] * rtDW.A[r3];
  y[r1] -= y[r2] * rtDW.A[r2];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

// Model step function for TID0
void dynamic_model_step0(void)         // Sample time: [0.0s, 0.0s]
{
  if (rtmIsMajorTimeStep(rtM)) {
    // set solver stop time
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));

    {                                  // Sample time: [0.0s, 0.0s]
      rate_monotonic_scheduler();
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    static const real_T b[8] = { -2.5E-6, 2.5E-6, -2.5E-6, 2.5E-6, 0.0, 0.0, 0.0,
      0.0 };

    static const real_T c[8] = { -1.7E-5, 1.7E-5, -1.7E-5, 1.7E-5, 0.0, 0.0, 0.0,
      0.0 };

    static const real_T a[3] = { 0.00625, 0.00625, 0.061311604970797212 };

    static const int8_T d[8] = { 1, -1, -1, 1, 0, 0, 0, 0 };

    static const int8_T e[8] = { 1, 1, -1, -1, 0, 0, 0, 0 };

    static const int8_T x[8] = { -1, 1, -1, 1, 0, 0, 0, 0 };

    real_T rtb_Add2;
    int8_T rtAction;
    int32_T i;
    real_T rtb_VectorConcatenate_i_idx_0;
    real_T rtb_VectorConcatenate_i_idx_1;

    // Integrator: '<S19>/q0 q1 q2 q3'
    if (rtDW.q0q1q2q3_IWORK != 0) {
      rtX.q0q1q2q3_CSTATE[0] = rtConstB.q0;
      rtX.q0q1q2q3_CSTATE[1] = rtConstB.q1;
      rtX.q0q1q2q3_CSTATE[2] = rtConstB.q2;
      rtX.q0q1q2q3_CSTATE[3] = rtConstB.q3;
    }

    // Sqrt: '<S41>/sqrt' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Product: '<S42>/Product'
    //   Product: '<S42>/Product1'
    //   Product: '<S42>/Product2'
    //   Product: '<S42>/Product3'
    //   Sum: '<S42>/Sum'

    rtDW.jxi_a = sqrt(((rtX.q0q1q2q3_CSTATE[0] * rtX.q0q1q2q3_CSTATE[0] +
                        rtX.q0q1q2q3_CSTATE[1] * rtX.q0q1q2q3_CSTATE[1]) +
                       rtX.q0q1q2q3_CSTATE[2] * rtX.q0q1q2q3_CSTATE[2]) +
                      rtX.q0q1q2q3_CSTATE[3] * rtX.q0q1q2q3_CSTATE[3]);

    // Product: '<S40>/Product' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.ixk_b = rtX.q0q1q2q3_CSTATE[0] / rtDW.jxi_a;

    // Product: '<S40>/Product1' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.kxj_m = rtX.q0q1q2q3_CSTATE[1] / rtDW.jxi_a;

    // Product: '<S40>/Product2' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.ixj_i = rtX.q0q1q2q3_CSTATE[2] / rtDW.jxi_a;

    // Product: '<S40>/Product3' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.jxi_a = rtX.q0q1q2q3_CSTATE[3] / rtDW.jxi_a;

    // Sum: '<S30>/Sum' incorporates:
    //   Product: '<S30>/Product'
    //   Product: '<S30>/Product1'
    //   Product: '<S30>/Product2'
    //   Product: '<S30>/Product3'

    rtDW.VectorConcatenate[0] = ((rtDW.ixk_b * rtDW.ixk_b + rtDW.kxj_m *
      rtDW.kxj_m) - rtDW.ixj_i * rtDW.ixj_i) - rtDW.jxi_a * rtDW.jxi_a;

    // Gain: '<S33>/Gain' incorporates:
    //   Product: '<S33>/Product2'
    //   Product: '<S33>/Product3'
    //   Sum: '<S33>/Sum'

    rtDW.VectorConcatenate[1] = (rtDW.kxj_m * rtDW.ixj_i - rtDW.jxi_a *
      rtDW.ixk_b) * 2.0;

    // Gain: '<S36>/Gain' incorporates:
    //   Product: '<S36>/Product1'
    //   Product: '<S36>/Product2'
    //   Sum: '<S36>/Sum'

    rtDW.VectorConcatenate[2] = (rtDW.ixk_b * rtDW.ixj_i + rtDW.kxj_m *
      rtDW.jxi_a) * 2.0;

    // Gain: '<S31>/Gain' incorporates:
    //   Product: '<S31>/Product2'
    //   Product: '<S31>/Product3'
    //   Sum: '<S31>/Sum'

    rtDW.VectorConcatenate[3] = (rtDW.jxi_a * rtDW.ixk_b + rtDW.kxj_m *
      rtDW.ixj_i) * 2.0;

    // Sum: '<S34>/Sum' incorporates:
    //   Product: '<S34>/Product'
    //   Product: '<S34>/Product1'
    //   Product: '<S34>/Product2'
    //   Product: '<S34>/Product3'

    rtDW.VectorConcatenate[4] = ((rtDW.ixk_b * rtDW.ixk_b - rtDW.kxj_m *
      rtDW.kxj_m) + rtDW.ixj_i * rtDW.ixj_i) - rtDW.jxi_a * rtDW.jxi_a;

    // Gain: '<S37>/Gain' incorporates:
    //   Product: '<S37>/Product1'
    //   Product: '<S37>/Product2'
    //   Sum: '<S37>/Sum'

    rtDW.VectorConcatenate[5] = (rtDW.ixj_i * rtDW.jxi_a - rtDW.ixk_b *
      rtDW.kxj_m) * 2.0;

    // Gain: '<S32>/Gain' incorporates:
    //   Product: '<S32>/Product1'
    //   Product: '<S32>/Product2'
    //   Sum: '<S32>/Sum'

    rtDW.VectorConcatenate[6] = (rtDW.kxj_m * rtDW.jxi_a - rtDW.ixk_b *
      rtDW.ixj_i) * 2.0;

    // Gain: '<S35>/Gain' incorporates:
    //   Product: '<S35>/Product1'
    //   Product: '<S35>/Product2'
    //   Sum: '<S35>/Sum'

    rtDW.VectorConcatenate[7] = (rtDW.ixk_b * rtDW.kxj_m + rtDW.ixj_i *
      rtDW.jxi_a) * 2.0;

    // Sum: '<S38>/Sum' incorporates:
    //   Product: '<S38>/Product'
    //   Product: '<S38>/Product1'
    //   Product: '<S38>/Product2'
    //   Product: '<S38>/Product3'

    rtDW.VectorConcatenate[8] = ((rtDW.ixk_b * rtDW.ixk_b - rtDW.kxj_m *
      rtDW.kxj_m) - rtDW.ixj_i * rtDW.ixj_i) + rtDW.jxi_a * rtDW.jxi_a;

    // Saturate: '<S12>/Limit  altitude  to troposhere' incorporates:
    //   Gain: '<Root>/Gain'
    //   Integrator: '<S1>/xe,ye,ze'

    if (-rtX.xeyeze_CSTATE[2] > 11000.0) {
      rtDW.ixk_b = 11000.0;
    } else if (-rtX.xeyeze_CSTATE[2] < -10.0) {
      rtDW.ixk_b = -10.0;
    } else {
      rtDW.ixk_b = -rtX.xeyeze_CSTATE[2];
    }

    // End of Saturate: '<S12>/Limit  altitude  to troposhere'

    // Sum: '<S12>/Sum1' incorporates:
    //   Constant: '<S12>/Sea Level  Temperature'
    //   Gain: '<S12>/Lapse Rate'

    rtDW.ixj_i = 288.15 - 0.0065 * rtDW.ixk_b;

    // Gain: '<S12>/1//T0'
    rtDW.kxj_m = 0.00347041471455839 * rtDW.ixj_i;

    // Saturate: '<S12>/Limit  altitude  to Stratosphere' incorporates:
    //   Constant: '<S12>/Altitude of Troposphere'
    //   Gain: '<Root>/Gain'
    //   Integrator: '<S1>/xe,ye,ze'
    //   Sum: '<S12>/Sum'

    if (11000.0 - (-rtX.xeyeze_CSTATE[2]) > 0.0) {
      rtDW.ixk_b = 0.0;
    } else if (11000.0 - (-rtX.xeyeze_CSTATE[2]) < -9000.0) {
      rtDW.ixk_b = -9000.0;
    } else {
      rtDW.ixk_b = 11000.0 - (-rtX.xeyeze_CSTATE[2]);
    }

    // End of Saturate: '<S12>/Limit  altitude  to Stratosphere'

    // Product: '<S12>/Product3' incorporates:
    //   Constant: '<S12>/Constant'
    //   Gain: '<S12>/g//R'
    //   Gain: '<S12>/rho0'
    //   Math: '<S12>/(T//T0)^(g//LR) '
    //   Math: '<S12>/Stratosphere Model'
    //   Product: '<S12>/Product'
    //   Product: '<S12>/Product1'
    //
    //  About '<S12>/Stratosphere Model':
    //   Operator: exp

    rtDW.ixk_b = rt_powd_snf(rtDW.kxj_m, 5.2558756014667134) / rtDW.kxj_m *
      1.225 * exp(1.0 / rtDW.ixj_i * (0.034163191409533639 * rtDW.ixk_b));
    if (rtmIsMajorTimeStep(rtM)) {
      // DiscreteTransferFcn: '<S18>/Transfer Fcn3'
      rtDW.TransferFcn3 = 30.861623144040156 * rtDW.TransferFcn3_states[0] +
        0.073571384506755 * rtDW.TransferFcn3_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn1'
      rtDW.TransferFcn1 = 30.861623144040156 * rtDW.TransferFcn1_states[0] +
        0.073571384506755 * rtDW.TransferFcn1_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn2'
      rtDW.TransferFcn2 = 30.861623144040156 * rtDW.TransferFcn2_states[0] +
        0.073571384506755 * rtDW.TransferFcn2_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn4'
      rtDW.TransferFcn4 = 30.861623144040156 * rtDW.TransferFcn4_states[0] +
        0.073571384506755 * rtDW.TransferFcn4_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn5'
      rtDW.TransferFcn5 = 30.861623144040156 * rtDW.TransferFcn5_states[0] +
        0.073571384506755 * rtDW.TransferFcn5_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn6'
      rtDW.TransferFcn6 = 30.861623144040156 * rtDW.TransferFcn6_states[0] +
        0.073571384506755 * rtDW.TransferFcn6_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn7'
      rtDW.TransferFcn7 = 30.861623144040156 * rtDW.TransferFcn7_states[0] +
        0.073571384506755 * rtDW.TransferFcn7_states[1];

      // DiscreteTransferFcn: '<S18>/Transfer Fcn8'
      rtDW.TransferFcn8 = 30.861623144040156 * rtDW.TransferFcn8_states[0] +
        0.073571384506755 * rtDW.TransferFcn8_states[1];
    }

    // SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport5' incorporates:
    //   MATLAB Function: '<Root>/multicopter'

    rtDW.TmpSignalConversionAtSFunctionInport5[0] = rtDW.TransferFcn3;
    rtDW.TmpSignalConversionAtSFunctionInport5[1] = rtDW.TransferFcn1;
    rtDW.TmpSignalConversionAtSFunctionInport5[2] = rtDW.TransferFcn2;
    rtDW.TmpSignalConversionAtSFunctionInport5[3] = rtDW.TransferFcn4;
    rtDW.TmpSignalConversionAtSFunctionInport5[4] = rtDW.TransferFcn5;
    rtDW.TmpSignalConversionAtSFunctionInport5[5] = rtDW.TransferFcn6;
    rtDW.TmpSignalConversionAtSFunctionInport5[6] = rtDW.TransferFcn7;
    rtDW.TmpSignalConversionAtSFunctionInport5[7] = rtDW.TransferFcn8;

    // MATLAB Function: '<Root>/multicopter' incorporates:
    //   Integrator: '<S1>/ub,vb,wb'

    // ================================Constants================================= 
    // MATLAB Function 'multicopter': '<S16>:1'
    // '<S16>:1:5' coefficient_drag = 15;
    //  coefficient of drag
    // '<S16>:1:6' rotor_inertia = 0.0000025;
    //  rotor inertia                         (kg m^2)
    // '<S16>:1:7' prop_diameter = 0.1397;
    //  diameter of the propellor             (meters)                                  
    // '<S16>:1:8' aircraft_mass = 0.26;
    //  aircraft mass                         (kg)                                         
    // '<S16>:1:9' aircraft_diameter = 0.25;
    //  motor to motor distance               (meters)                                       
    // ==============================Actuator Mixer============================== 
    //  [x(roll), y(pitch), z(yaw)]
    //  QUAD [X]
    // '<S16>:1:16' MIX = [  1   1  -1   ;      % QUAD [X]
    // '<S16>:1:17'         -1   1   1   ;
    // '<S16>:1:18'         -1  -1  -1   ;
    // '<S16>:1:19'          1  -1   1   ;
    // '<S16>:1:20'          0   0   0   ;
    // '<S16>:1:21'          0   0   0   ;
    // '<S16>:1:22'          0   0   0   ;
    // '<S16>:1:23'          0   0   0   ];
    //  MIX = [  0   1  -1   ;      % QUAD [+]
    //          -1   0   1   ;
    //           0  -1  -1   ;
    //           1   0   1   ;
    //           0   0   0   ;
    //           0   0   0   ];
    //  MIX = [  1   1  -1   ;      % HEX [X]
    //          -1   1   1   ;
    //          -1   0  -1   ;
    //          -1  -1   1   ;
    //           1  -1  -1   ;
    //           1   0   1   ;
    //           0   0   0   ;
    //           0   0   0   ];
    // ==================================Forces==================================  
    //                 % body cross sectional area (X)
    //                 % body cross sectional area (Y)
    // '<S16>:1:45' a = [   aircraft_diameter^2 / 10                        ;...                % body cross sectional area (X) 
    // '<S16>:1:46'         aircraft_diameter^2 / 10                        ;...                % body cross sectional area (Y) 
    // '<S16>:1:47'         sum(abs(MIX(:, 3))) * pi/4 * prop_diameter^2    ];
    //  body cross sectional area (Z)
    // '<S16>:1:49' gravity = aircraft_mass .* (DCM * [0; 0; 9.81]);
    //  gravitational force
    // '<S16>:1:50' drag = -velocity .* coefficient_drag .* density .* a;
    //  drag force
    // --------------------------------Thrust Model------------------------------ 
    // '<S16>:1:53' thrust = abs(MIX(:, 3)) .* (1*1E-3) .* rotors;
    for (i = 0; i < 8; i++) {
      rtDW.thrust[i] = fabs((real_T)x[i]) * 0.001 *
        rtDW.TmpSignalConversionAtSFunctionInport5[i];
    }

    //  rotor thrust <==
    // -------------------------------------------------------------------------- 
    // '<S16>:1:56' forces = gravity + drag;
    for (i = 0; i < 3; i++) {
      rtDW.forces[i] = -rtX.ubvbwb_CSTATE[i] * 15.0 * rtDW.ixk_b * a[i] + 0.26 *
        (rtDW.VectorConcatenate[i + 6] * 9.81 + (rtDW.VectorConcatenate[i + 3] *
          0.0 + rtDW.VectorConcatenate[i] * 0.0));
    }

    // '<S16>:1:57' forces(3) = forces(3) - sum(thrust);
    rtDW.ixk_b = rtDW.thrust[0];
    for (i = 0; i < 7; i++) {
      rtDW.ixk_b += rtDW.thrust[i + 1];
    }

    rtDW.forces[2] -= rtDW.ixk_b;

    // ==================================Moments================================= 
    // '<S16>:1:61' mx = thrust .* MIX(:,1) .* (aircraft_diameter / 2)*sind(45); 
    //  x moment
    // '<S16>:1:62' my = thrust .* MIX(:,2) .* (aircraft_diameter / 2)*sind(45); 
    //  y moment
    // '<S16>:1:64' momentum_x = sum(abs(MIX(:, 3)) .* rotor_inertia .* rotors) * omega(1); 
    for (i = 0; i < 8; i++) {
      rtDW.mx[i] = rtDW.thrust[i] * (real_T)d[i] * 0.125 * 0.70710678118654746;
      rtDW.mz[i] = fabs((real_T)x[i]) * 2.5E-6 *
        rtDW.TmpSignalConversionAtSFunctionInport5[i];
      rtDW.thrust[i] = rtDW.thrust[i] * (real_T)e[i] * 0.125 *
        0.70710678118654746;
    }

    rtDW.ixk_b = rtDW.mz[0];
    for (i = 0; i < 7; i++) {
      rtDW.ixk_b += rtDW.mz[i + 1];
    }

    //  x rotor momentum
    // '<S16>:1:65' momentum_y = sum(abs(MIX(:, 3)) .* rotor_inertia .* rotors) * omega(2); 
    for (i = 0; i < 8; i++) {
      rtDW.mz[i] = fabs((real_T)x[i]) * 2.5E-6 *
        rtDW.TmpSignalConversionAtSFunctionInport5[i];
    }

    rtDW.kxj_m = rtDW.mz[0];
    for (i = 0; i < 7; i++) {
      rtDW.kxj_m += rtDW.mz[i + 1];
    }

    //  y rotor momentum
    // '<S16>:1:66' momentum_z = sum(MIX(:, 3) .* rotor_inertia .* rotors) * omega(3); 
    for (i = 0; i < 8; i++) {
      rtDW.mz[i] = b[i] * rtDW.TmpSignalConversionAtSFunctionInport5[i];
    }

    rtDW.ixj_i = rtDW.mz[0];
    for (i = 0; i < 7; i++) {
      rtDW.ixj_i += rtDW.mz[i + 1];
    }

    //  z rotor momentum
    // --------------------------------Torque Model------------------------------ 
    // '<S16>:1:69' mz = MIX(:,3) .* (1.7E-5) .* rotors;
    for (i = 0; i < 8; i++) {
      rtDW.mz[i] = c[i] * rtDW.TmpSignalConversionAtSFunctionInport5[i];
    }

    //  rotor torque <==
    // -------------------------------------------------------------------------- 
    // '<S16>:1:72' moments = [sum(mx); sum(my); sum(mz)] - [momentum_x; momentum_y; momentum_z]; 
    rtb_Add2 = rtDW.mx[0];
    rtDW.kxi_c = rtDW.thrust[0];
    rtb_VectorConcatenate_i_idx_1 = rtDW.mz[0];
    for (i = 0; i < 7; i++) {
      rtb_Add2 += rtDW.mx[i + 1];
      rtDW.kxi_c += rtDW.thrust[i + 1];
      rtb_VectorConcatenate_i_idx_1 += rtDW.mz[i + 1];
    }

    // Product: '<S1>/Product' incorporates:
    //   Constant: '<S21>/Constant'
    //   Sum: '<Root>/Add6'

    // ========================================================================== 
    rtDW.forces[0] /= 0.26;
    rtDW.forces[1] /= 0.26;
    rtDW.jxi_a = rtDW.forces[2] / 0.26;
    rtDW.forces[2] = rtDW.jxi_a;

    // ZeroOrderHold: '<S79>/Zero-Order Hold1' incorporates:
    //   ZeroOrderHold: '<S79>/Zero-Order Hold2'

    if (rtmIsMajorTimeStep(rtM) && rtM->Timing.RateInteraction.TID0_2) {
      // ZeroOrderHold: '<S79>/Zero-Order Hold' incorporates:
      //   Integrator: '<S1>/p,q,r '
      //   Product: '<Root>/Matrix Multiply1'

      for (i = 0; i < 3; i++) {
        rtDW.ZeroOrderHold1[i] = rtDW.forces[i];
        rtDW.ZeroOrderHold2[i] = 0.0;
        rtDW.ZeroOrderHold2[i] += rtDW.VectorConcatenate[i] * 0.0;
        rtDW.ZeroOrderHold2[i] += rtDW.VectorConcatenate[i + 3] * 0.0;
        rtDW.ZeroOrderHold2[i] += rtDW.VectorConcatenate[i + 6] * 9.81;
        rtDW.ZeroOrderHold[i] = rtX.pqr_CSTATE[i];
      }

      // End of ZeroOrderHold: '<S79>/Zero-Order Hold'
    }

    // End of ZeroOrderHold: '<S79>/Zero-Order Hold1'
    for (i = 0; i < 3; i++) {
      // Product: '<S46>/Product' incorporates:
      //   Integrator: '<S1>/p,q,r '

      rtDW.Sum_p[i] = rtConstB.Selector[i + 6] * rtX.pqr_CSTATE[2] +
        (rtConstB.Selector[i + 3] * rtX.pqr_CSTATE[1] + rtConstB.Selector[i] *
         rtX.pqr_CSTATE[0]);

      // Product: '<S47>/Product' incorporates:
      //   Integrator: '<S1>/p,q,r '

      rtDW.dv1[i] = 0.0 * rtX.pqr_CSTATE[2] + (0.0 * rtX.pqr_CSTATE[1] + 0.0 *
        rtX.pqr_CSTATE[0]);
    }

    // Sum: '<S20>/Sum2' incorporates:
    //   Integrator: '<S1>/p,q,r '
    //   MATLAB Function: '<Root>/multicopter'
    //   Product: '<S47>/Product'
    //   Product: '<S49>/i x j'
    //   Product: '<S49>/j x k'
    //   Product: '<S49>/k x i'
    //   Product: '<S50>/i x k'
    //   Product: '<S50>/j x i'
    //   Product: '<S50>/k x j'
    //   Sum: '<S48>/Sum'

    rtDW.dv0[0] = ((rtb_Add2 - rtDW.ixk_b * rtX.pqr_CSTATE[0]) - rtDW.dv1[0]) -
      (rtX.pqr_CSTATE[1] * rtDW.Sum_p[2] - rtX.pqr_CSTATE[2] * rtDW.Sum_p[1]);
    rtDW.dv0[1] = ((rtDW.kxi_c - rtDW.kxj_m * rtX.pqr_CSTATE[1]) - rtDW.dv1[1])
      - (rtX.pqr_CSTATE[2] * rtDW.Sum_p[0] - rtX.pqr_CSTATE[0] * rtDW.Sum_p[2]);
    rtDW.dv0[2] = ((rtb_VectorConcatenate_i_idx_1 - rtDW.ixj_i * rtX.pqr_CSTATE
                    [2]) - rtDW.dv1[2]) - (rtX.pqr_CSTATE[0] * rtDW.Sum_p[1] -
      rtX.pqr_CSTATE[1] * rtDW.Sum_p[0]);

    // Product: '<S20>/Product2'
    rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf_i(rtDW.dv0, rtConstB.Selector2,
      rtDW.Product2);

    // ZeroOrderHold: '<S79>/Zero-Order Hold3' incorporates:
    //   UnitConversion: '<S78>/Unit Conversion'
    //   ZeroOrderHold: '<S80>/Zero-Order Hold1'

    if (rtmIsMajorTimeStep(rtM) && rtM->Timing.RateInteraction.TID0_2) {
      rtDW.ZeroOrderHold3[0] = rtDW.Product2[0];

      // ZeroOrderHold: '<S80>/Zero-Order Hold' incorporates:
      //   Integrator: '<S1>/p,q,r '

      rtDW.ZeroOrderHold_g[0] = rtX.pqr_CSTATE[0];
      rtDW.ZeroOrderHold3[1] = rtDW.Product2[1];

      // ZeroOrderHold: '<S80>/Zero-Order Hold' incorporates:
      //   Integrator: '<S1>/p,q,r '

      rtDW.ZeroOrderHold_g[1] = rtX.pqr_CSTATE[1];
      rtDW.ZeroOrderHold3[2] = rtDW.Product2[2];

      // ZeroOrderHold: '<S80>/Zero-Order Hold' incorporates:
      //   Integrator: '<S1>/p,q,r '

      rtDW.ZeroOrderHold_g[2] = rtX.pqr_CSTATE[2];
      rtDW.ZeroOrderHold1_o[0] = 0.10197162129779282 * rtDW.forces[0];
      rtDW.ZeroOrderHold1_o[1] = 0.10197162129779282 * rtDW.forces[1];
      rtDW.ZeroOrderHold1_o[2] = 0.10197162129779282 * rtDW.jxi_a;
    }

    // End of ZeroOrderHold: '<S79>/Zero-Order Hold3'

    // Sqrt: '<S44>/sqrt' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Product: '<S45>/Product'
    //   Product: '<S45>/Product1'
    //   Product: '<S45>/Product2'
    //   Product: '<S45>/Product3'
    //   Sum: '<S45>/Sum'

    // Unit Conversion - from: m/s^2 to: gn
    // Expression: output = (0.101972*input) + (0)
    rtb_Add2 = sqrt(((rtX.q0q1q2q3_CSTATE[0] * rtX.q0q1q2q3_CSTATE[0] +
                      rtX.q0q1q2q3_CSTATE[1] * rtX.q0q1q2q3_CSTATE[1]) +
                     rtX.q0q1q2q3_CSTATE[2] * rtX.q0q1q2q3_CSTATE[2]) +
                    rtX.q0q1q2q3_CSTATE[3] * rtX.q0q1q2q3_CSTATE[3]);

    // Product: '<S43>/Product' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.kxi_c = rtX.q0q1q2q3_CSTATE[0] / rtb_Add2;

    // Product: '<S43>/Product1' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.ixj_i = rtX.q0q1q2q3_CSTATE[1] / rtb_Add2;

    // Product: '<S43>/Product2' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.kxj_m = rtX.q0q1q2q3_CSTATE[2] / rtb_Add2;

    // Product: '<S43>/Product3' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtb_Add2 = rtX.q0q1q2q3_CSTATE[3] / rtb_Add2;

    // Trigonometry: '<S27>/Trigonometric Function1' incorporates:
    //   Fcn: '<S27>/fcn1'
    //   Fcn: '<S27>/fcn2'

    rtb_VectorConcatenate_i_idx_0 = rt_atan2d_snf((rtDW.ixj_i * rtDW.kxj_m +
      rtDW.kxi_c * rtb_Add2) * 2.0, ((rtDW.kxi_c * rtDW.kxi_c + rtDW.ixj_i *
      rtDW.ixj_i) - rtDW.kxj_m * rtDW.kxj_m) - rtb_Add2 * rtb_Add2);

    // Fcn: '<S27>/fcn3'
    rtb_VectorConcatenate_i_idx_1 = (rtDW.ixj_i * rtb_Add2 - rtDW.kxi_c *
      rtDW.kxj_m) * -2.0;

    // Trigonometry: '<S27>/trigFcn'
    if (rtb_VectorConcatenate_i_idx_1 > 1.0) {
      rtb_VectorConcatenate_i_idx_1 = 1.0;
    } else {
      if (rtb_VectorConcatenate_i_idx_1 < -1.0) {
        rtb_VectorConcatenate_i_idx_1 = -1.0;
      }
    }

    rtb_VectorConcatenate_i_idx_1 = asin(rtb_VectorConcatenate_i_idx_1);

    // End of Trigonometry: '<S27>/trigFcn'

    // Fcn: '<S27>/fcn4'
    rtDW.ixk_b = (rtDW.kxj_m * rtb_Add2 + rtDW.kxi_c * rtDW.ixj_i) * 2.0;

    // Fcn: '<S27>/fcn5'
    rtDW.kxi_c = ((rtDW.kxi_c * rtDW.kxi_c - rtDW.ixj_i * rtDW.ixj_i) -
                  rtDW.kxj_m * rtDW.kxj_m) + rtb_Add2 * rtb_Add2;

    // Trigonometry: '<S27>/Trigonometric Function3'
    rtDW.kxj_m = rt_atan2d_snf(rtDW.ixk_b, rtDW.kxi_c);

    // RateTransition: '<Root>/TmpRTBAtAdd5Inport2' incorporates:
    //   RateTransition: '<Root>/Rate Transition8'
    //   Sum: '<Root>/Add5'

    if (rtmIsMajorTimeStep(rtM) && rtM->Timing.RateInteraction.TID1_2) {
      rtDW.TmpRTBAtAdd5Inport2 = rtDW.TmpRTBAtAdd5Inport2_Buffer0;
      rtDW.RateTransition8[0] = rtDW.kxj_m + rtDW.TmpRTBAtAdd5Inport2;
      rtDW.RateTransition8[1] = rtb_VectorConcatenate_i_idx_1 +
        rtDW.TmpRTBAtAdd5Inport2;
      rtDW.RateTransition8[2] = rtb_VectorConcatenate_i_idx_0 +
        rtDW.TmpRTBAtAdd5Inport2;
    }

    // End of RateTransition: '<Root>/TmpRTBAtAdd5Inport2'

    // Outport: '<Root>/position_O' incorporates:
    //   Integrator: '<S1>/xe,ye,ze'

    rtY.position_O[0] = rtX.xeyeze_CSTATE[0];
    rtY.position_O[1] = rtX.xeyeze_CSTATE[1];
    rtY.position_O[2] = rtX.xeyeze_CSTATE[2];

    // Sum: '<S55>/Add'
    rtDW.ixj_i = (rtDW.VectorConcatenate[0] + rtDW.VectorConcatenate[4]) +
      rtDW.VectorConcatenate[8];

    // If: '<S11>/If'
    if (rtmIsMajorTimeStep(rtM)) {
      rtAction = (int8_T)!(rtDW.ixj_i > 0.0);
      rtDW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = rtDW.If_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S11>/Positive Trace' incorporates:
      //   ActionPort: '<S54>/Action Port'

      // Sqrt: '<S54>/sqrt' incorporates:
      //   Constant: '<S54>/Constant'
      //   Sum: '<S54>/Sum'

      rtDW.ixj_i = sqrt(rtDW.ixj_i + 1.0);

      // Gain: '<S54>/Gain'
      rtDW.Merge[0] = 0.5 * rtDW.ixj_i;

      // Gain: '<S54>/Gain1'
      rtDW.ixj_i *= 2.0;

      // Product: '<S54>/Product' incorporates:
      //   Sum: '<S75>/Add'
      //   Sum: '<S76>/Add'
      //   Sum: '<S77>/Add'

      rtDW.Merge[1] = (rtDW.VectorConcatenate[7] - rtDW.VectorConcatenate[5]) /
        rtDW.ixj_i;
      rtDW.Merge[2] = (rtDW.VectorConcatenate[2] - rtDW.VectorConcatenate[6]) /
        rtDW.ixj_i;
      rtDW.Merge[3] = (rtDW.VectorConcatenate[3] - rtDW.VectorConcatenate[1]) /
        rtDW.ixj_i;

      // End of Outputs for SubSystem: '<S11>/Positive Trace'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S11>/Negative Trace' incorporates:
      //   ActionPort: '<S53>/Action Port'

      // If: '<S53>/Find Maximum Diagonal Value'
      if (rtmIsMajorTimeStep(rtM)) {
        if ((rtDW.VectorConcatenate[4] > rtDW.VectorConcatenate[0]) &&
            (rtDW.VectorConcatenate[4] > rtDW.VectorConcatenate[8])) {
          rtAction = 0;
        } else if (rtDW.VectorConcatenate[8] > rtDW.VectorConcatenate[0]) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }

        rtDW.FindMaximumDiagonalValue_ActiveSubsystem = rtAction;
      } else {
        rtAction = rtDW.FindMaximumDiagonalValue_ActiveSubsystem;
      }

      switch (rtAction) {
       case 0:
        // Outputs for IfAction SubSystem: '<S53>/Maximum Value at DCM(2,2)' incorporates:
        //   ActionPort: '<S57>/Action Port'

        // Sqrt: '<S57>/sqrt' incorporates:
        //   Constant: '<S69>/Constant'
        //   Sum: '<S69>/Add'

        rtDW.ixj_i = sqrt(((rtDW.VectorConcatenate[4] - rtDW.VectorConcatenate[0])
                           - rtDW.VectorConcatenate[8]) + 1.0);

        // Gain: '<S57>/Gain'
        rtDW.Merge[2] = 0.5 * rtDW.ixj_i;

        // Switch: '<S68>/Switch' incorporates:
        //   Constant: '<S68>/Constant1'

        if (rtDW.ixj_i != 0.0) {
          rtDW.ixk_b = 0.5;
        } else {
          rtDW.ixk_b = 0.0;
          rtDW.ixj_i = 1.0;
        }

        // End of Switch: '<S68>/Switch'

        // Product: '<S68>/Product'
        rtDW.ixj_i = rtDW.ixk_b / rtDW.ixj_i;

        // Gain: '<S57>/Gain1' incorporates:
        //   Product: '<S57>/Product'
        //   Sum: '<S67>/Add'

        rtDW.Merge[1] = (rtDW.VectorConcatenate[1] + rtDW.VectorConcatenate[3]) *
          rtDW.ixj_i;

        // Gain: '<S57>/Gain3' incorporates:
        //   Product: '<S57>/Product'
        //   Sum: '<S66>/Add'

        rtDW.Merge[3] = (rtDW.VectorConcatenate[5] + rtDW.VectorConcatenate[7]) *
          rtDW.ixj_i;

        // Gain: '<S57>/Gain4' incorporates:
        //   Product: '<S57>/Product'
        //   Sum: '<S65>/Add'

        rtDW.Merge[0] = (rtDW.VectorConcatenate[2] - rtDW.VectorConcatenate[6]) *
          rtDW.ixj_i;

        // End of Outputs for SubSystem: '<S53>/Maximum Value at DCM(2,2)'
        break;

       case 1:
        // Outputs for IfAction SubSystem: '<S53>/Maximum Value at DCM(3,3)' incorporates:
        //   ActionPort: '<S58>/Action Port'

        // Sqrt: '<S58>/sqrt' incorporates:
        //   Constant: '<S74>/Constant'
        //   Sum: '<S74>/Add'

        rtDW.ixj_i = sqrt(((rtDW.VectorConcatenate[8] - rtDW.VectorConcatenate[0])
                           - rtDW.VectorConcatenate[4]) + 1.0);

        // Gain: '<S58>/Gain'
        rtDW.Merge[3] = 0.5 * rtDW.ixj_i;

        // Switch: '<S73>/Switch' incorporates:
        //   Constant: '<S73>/Constant1'

        if (rtDW.ixj_i != 0.0) {
          rtDW.ixk_b = 0.5;
        } else {
          rtDW.ixk_b = 0.0;
          rtDW.ixj_i = 1.0;
        }

        // End of Switch: '<S73>/Switch'

        // Product: '<S73>/Product'
        rtDW.ixj_i = rtDW.ixk_b / rtDW.ixj_i;

        // Gain: '<S58>/Gain1' incorporates:
        //   Product: '<S58>/Product'
        //   Sum: '<S70>/Add'

        rtDW.Merge[1] = (rtDW.VectorConcatenate[2] + rtDW.VectorConcatenate[6]) *
          rtDW.ixj_i;

        // Gain: '<S58>/Gain2' incorporates:
        //   Product: '<S58>/Product'
        //   Sum: '<S71>/Add'

        rtDW.Merge[2] = (rtDW.VectorConcatenate[5] + rtDW.VectorConcatenate[7]) *
          rtDW.ixj_i;

        // Gain: '<S58>/Gain3' incorporates:
        //   Product: '<S58>/Product'
        //   Sum: '<S72>/Add'

        rtDW.Merge[0] = (rtDW.VectorConcatenate[3] - rtDW.VectorConcatenate[1]) *
          rtDW.ixj_i;

        // End of Outputs for SubSystem: '<S53>/Maximum Value at DCM(3,3)'
        break;

       case 2:
        // Outputs for IfAction SubSystem: '<S53>/Maximum Value at DCM(1,1)' incorporates:
        //   ActionPort: '<S56>/Action Port'

        // Sqrt: '<S56>/sqrt' incorporates:
        //   Constant: '<S64>/Constant'
        //   Sum: '<S64>/Add'

        rtDW.ixj_i = sqrt(((rtDW.VectorConcatenate[0] - rtDW.VectorConcatenate[4])
                           - rtDW.VectorConcatenate[8]) + 1.0);

        // Gain: '<S56>/Gain'
        rtDW.Merge[1] = 0.5 * rtDW.ixj_i;

        // Switch: '<S63>/Switch' incorporates:
        //   Constant: '<S63>/Constant1'

        if (rtDW.ixj_i != 0.0) {
          rtDW.ixk_b = 0.5;
        } else {
          rtDW.ixk_b = 0.0;
          rtDW.ixj_i = 1.0;
        }

        // End of Switch: '<S63>/Switch'

        // Product: '<S63>/Product'
        rtDW.ixj_i = rtDW.ixk_b / rtDW.ixj_i;

        // Gain: '<S56>/Gain1' incorporates:
        //   Product: '<S56>/Product'
        //   Sum: '<S62>/Add'

        rtDW.Merge[2] = (rtDW.VectorConcatenate[1] + rtDW.VectorConcatenate[3]) *
          rtDW.ixj_i;

        // Gain: '<S56>/Gain2' incorporates:
        //   Product: '<S56>/Product'
        //   Sum: '<S60>/Add'

        rtDW.Merge[3] = (rtDW.VectorConcatenate[2] + rtDW.VectorConcatenate[6]) *
          rtDW.ixj_i;

        // Gain: '<S56>/Gain3' incorporates:
        //   Product: '<S56>/Product'
        //   Sum: '<S61>/Add'

        rtDW.Merge[0] = (rtDW.VectorConcatenate[7] - rtDW.VectorConcatenate[5]) *
          rtDW.ixj_i;

        // End of Outputs for SubSystem: '<S53>/Maximum Value at DCM(1,1)'
        break;
      }

      // End of If: '<S53>/Find Maximum Diagonal Value'
      // End of Outputs for SubSystem: '<S11>/Negative Trace'
      break;
    }

    // End of If: '<S11>/If'

    // Outport: '<Root>/attitude_O'
    rtY.attitude_O[0] = rtDW.Merge[0];
    rtY.attitude_O[1] = rtDW.Merge[1];
    rtY.attitude_O[2] = rtDW.Merge[2];
    rtY.attitude_O[3] = rtDW.Merge[3];

    // DotProduct: '<S29>/Dot Product' incorporates:
    //   Integrator: '<S19>/q0 q1 q2 q3'

    rtDW.ixk_b = ((rtX.q0q1q2q3_CSTATE[0] * rtX.q0q1q2q3_CSTATE[0] +
                   rtX.q0q1q2q3_CSTATE[1] * rtX.q0q1q2q3_CSTATE[1]) +
                  rtX.q0q1q2q3_CSTATE[2] * rtX.q0q1q2q3_CSTATE[2]) +
      rtX.q0q1q2q3_CSTATE[3] * rtX.q0q1q2q3_CSTATE[3];

    // Fcn: '<S29>/q0dot' incorporates:
    //   Constant: '<S29>/Constant'
    //   DotProduct: '<S29>/Dot Product'
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Integrator: '<S1>/p,q,r '
    //   Sum: '<S29>/Sum'

    rtDW.q0dot = ((rtX.q0q1q2q3_CSTATE[1] * rtX.pqr_CSTATE[0] +
                   rtX.q0q1q2q3_CSTATE[2] * rtX.pqr_CSTATE[1]) +
                  rtX.q0q1q2q3_CSTATE[3] * rtX.pqr_CSTATE[2]) * -0.5 + (1.0 -
      rtDW.ixk_b) * rtX.q0q1q2q3_CSTATE[0];

    // Fcn: '<S29>/q1dot' incorporates:
    //   Constant: '<S29>/Constant'
    //   DotProduct: '<S29>/Dot Product'
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Integrator: '<S1>/p,q,r '
    //   Sum: '<S29>/Sum'

    rtDW.q1dot = ((rtX.q0q1q2q3_CSTATE[0] * rtX.pqr_CSTATE[0] +
                   rtX.q0q1q2q3_CSTATE[2] * rtX.pqr_CSTATE[2]) -
                  rtX.q0q1q2q3_CSTATE[3] * rtX.pqr_CSTATE[1]) * 0.5 + (1.0 -
      rtDW.ixk_b) * rtX.q0q1q2q3_CSTATE[1];

    // Fcn: '<S29>/q2dot' incorporates:
    //   Constant: '<S29>/Constant'
    //   DotProduct: '<S29>/Dot Product'
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Integrator: '<S1>/p,q,r '
    //   Sum: '<S29>/Sum'

    rtDW.q2dot = ((rtX.q0q1q2q3_CSTATE[0] * rtX.pqr_CSTATE[1] +
                   rtX.q0q1q2q3_CSTATE[3] * rtX.pqr_CSTATE[0]) -
                  rtX.q0q1q2q3_CSTATE[1] * rtX.pqr_CSTATE[2]) * 0.5 + (1.0 -
      rtDW.ixk_b) * rtX.q0q1q2q3_CSTATE[2];

    // Fcn: '<S29>/q3dot' incorporates:
    //   Constant: '<S29>/Constant'
    //   DotProduct: '<S29>/Dot Product'
    //   Integrator: '<S19>/q0 q1 q2 q3'
    //   Integrator: '<S1>/p,q,r '
    //   Sum: '<S29>/Sum'

    rtDW.q3dot = ((rtX.q0q1q2q3_CSTATE[0] * rtX.pqr_CSTATE[2] +
                   rtX.q0q1q2q3_CSTATE[1] * rtX.pqr_CSTATE[1]) -
                  rtX.q0q1q2q3_CSTATE[2] * rtX.pqr_CSTATE[0]) * 0.5 + (1.0 -
      rtDW.ixk_b) * rtX.q0q1q2q3_CSTATE[3];

    // Sum: '<S1>/Sum' incorporates:
    //   Integrator: '<S1>/p,q,r '
    //   Integrator: '<S1>/ub,vb,wb'
    //   Product: '<S51>/i x j'
    //   Product: '<S51>/j x k'
    //   Product: '<S51>/k x i'
    //   Product: '<S52>/i x k'
    //   Product: '<S52>/j x i'
    //   Product: '<S52>/k x j'
    //   Sum: '<S22>/Sum'

    rtDW.Sum[0] = (rtX.ubvbwb_CSTATE[1] * rtX.pqr_CSTATE[2] - rtX.ubvbwb_CSTATE
                   [2] * rtX.pqr_CSTATE[1]) + rtDW.forces[0];
    rtDW.Sum[1] = (rtX.ubvbwb_CSTATE[2] * rtX.pqr_CSTATE[0] - rtX.ubvbwb_CSTATE
                   [0] * rtX.pqr_CSTATE[2]) + rtDW.forces[1];
    rtDW.Sum[2] = (rtX.ubvbwb_CSTATE[0] * rtX.pqr_CSTATE[1] - rtX.ubvbwb_CSTATE
                   [1] * rtX.pqr_CSTATE[0]) + rtDW.jxi_a;

    // Product: '<S25>/Product' incorporates:
    //   Integrator: '<S1>/ub,vb,wb'
    //   Math: '<S1>/Transpose'

    for (i = 0; i < 3; i++) {
      rtDW.Product_j[i] = 0.0;
      rtDW.Product_j[i] += rtDW.VectorConcatenate[3 * i] * rtX.ubvbwb_CSTATE[0];
      rtDW.Product_j[i] += rtDW.VectorConcatenate[3 * i + 1] *
        rtX.ubvbwb_CSTATE[1];
      rtDW.Product_j[i] += rtDW.VectorConcatenate[3 * i + 2] *
        rtX.ubvbwb_CSTATE[2];
    }

    // End of Product: '<S25>/Product'

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Gain: '<Root>/Gain'
    //   Integrator: '<S1>/xe,ye,ze'

    // MATLAB Function 'MATLAB Function': '<S15>:1'
    // '<S15>:1:2' if altitude > 0
    if (-rtX.xeyeze_CSTATE[2] > 0.0) {
      // '<S15>:1:3' sonar_alt = sqrt(altitude^2 + (sqrt((altitude*tan(roll))^2 + (altitude*tan(pitch))^2))^2); 
      rtDW.ixj_i = -rtX.xeyeze_CSTATE[2] * tan(rtDW.kxj_m);
      rtDW.ixk_b = -rtX.xeyeze_CSTATE[2] * tan(rtb_VectorConcatenate_i_idx_1);
      rtDW.ixj_i = sqrt(rtDW.ixj_i * rtDW.ixj_i + rtDW.ixk_b * rtDW.ixk_b);
      rtDW.jxi_a = sqrt(-rtX.xeyeze_CSTATE[2] * -rtX.xeyeze_CSTATE[2] +
                        rtDW.ixj_i * rtDW.ixj_i);
    } else {
      // '<S15>:1:4' else
      // '<S15>:1:5' sonar_alt = 0;
      rtDW.jxi_a = 0.0;
    }

    // End of MATLAB Function: '<Root>/MATLAB Function'

    // RateTransition: '<Root>/TmpRTBAtAdd2Inport2' incorporates:
    //   Integrator: '<S1>/xe,ye,ze'
    //   RateTransition: '<Root>/Rate Transition11'
    //   RateTransition: '<Root>/Rate Transition2'
    //   RateTransition: '<Root>/TmpRTBAtAdd8Inport2'
    //   Sum: '<Root>/Add8'

    if (rtmIsMajorTimeStep(rtM)) {
      if (rtM->Timing.RateInteraction.TID1_4) {
        rtDW.TmpRTBAtAdd2Inport2 = rtDW.TmpRTBAtAdd2Inport2_Buffer0;
      }

      if (rtM->Timing.RateInteraction.TID1_2) {
        rtDW.TmpRTBAtAdd8Inport2[0] = rtDW.TmpRTBAtAdd8Inport2_Buffer0[0];
        rtDW.TmpRTBAtAdd8Inport2[1] = rtDW.TmpRTBAtAdd8Inport2_Buffer0[1];
        rtDW.TmpRTBAtAdd8Inport2[2] = rtDW.TmpRTBAtAdd8Inport2_Buffer0[2];
      }

      if (rtM->Timing.RateInteraction.TID1_5) {
        rtDW.RateTransition11[0] = rtX.xeyeze_CSTATE[0] +
          rtDW.TmpRTBAtAdd8Inport2[0];
        rtDW.RateTransition11[1] = rtX.xeyeze_CSTATE[1] +
          rtDW.TmpRTBAtAdd8Inport2[1];
        rtDW.RateTransition11[2] = rtX.xeyeze_CSTATE[2] +
          rtDW.TmpRTBAtAdd8Inport2[2];
      }

      if (rtM->Timing.RateInteraction.TID1_4) {
        // Sum: '<Root>/Add2'
        rtb_VectorConcatenate_i_idx_1 = rtDW.jxi_a + rtDW.TmpRTBAtAdd2Inport2;

        // Saturate: '<Root>/Saturation2'
        if (rtb_VectorConcatenate_i_idx_1 > 5.0) {
          rtDW.RateTransition2 = 5.0;
        } else if (rtb_VectorConcatenate_i_idx_1 < 0.3) {
          rtDW.RateTransition2 = 0.3;
        } else {
          rtDW.RateTransition2 = rtb_VectorConcatenate_i_idx_1;
        }

        // End of Saturate: '<Root>/Saturation2'
      }

      // RateTransition: '<S18>/TmpRTBAtProductOutport1' incorporates:
      //   Integrator: '<S1>/xe,ye,ze'
      //   Sum: '<Root>/Add8'

      if (rtM->Timing.RateInteraction.TID1_2) {
        memcpy(&rtDW.TmpRTBAtProductOutport1[0],
               &rtDW.TmpRTBAtProductOutport1_Buffer0[0], sizeof(real_T) << 3U);
      }

      // End of RateTransition: '<S18>/TmpRTBAtProductOutport1'
    }

    // End of RateTransition: '<Root>/TmpRTBAtAdd2Inport2'
  }

  if (rtmIsMajorTimeStep(rtM)) {
    real_T denAccum;

    // Update for Integrator: '<S19>/q0 q1 q2 q3'
    rtDW.q0q1q2q3_IWORK = 0;
    if (rtmIsMajorTimeStep(rtM)) {
      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn3'
      denAccum = (rtDW.TmpRTBAtProductOutport1[0] - -0.904814786066005 *
                  rtDW.TransferFcn3_states[0]) - 0.0 * rtDW.TransferFcn3_states
        [1];
      rtDW.TransferFcn3_states[1] = rtDW.TransferFcn3_states[0];
      rtDW.TransferFcn3_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn1'
      denAccum = (rtDW.TmpRTBAtProductOutport1[1] - -0.904814786066005 *
                  rtDW.TransferFcn1_states[0]) - 0.0 * rtDW.TransferFcn1_states
        [1];
      rtDW.TransferFcn1_states[1] = rtDW.TransferFcn1_states[0];
      rtDW.TransferFcn1_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn2'
      denAccum = (rtDW.TmpRTBAtProductOutport1[2] - -0.904814786066005 *
                  rtDW.TransferFcn2_states[0]) - 0.0 * rtDW.TransferFcn2_states
        [1];
      rtDW.TransferFcn2_states[1] = rtDW.TransferFcn2_states[0];
      rtDW.TransferFcn2_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn4'
      denAccum = (rtDW.TmpRTBAtProductOutport1[3] - -0.904814786066005 *
                  rtDW.TransferFcn4_states[0]) - 0.0 * rtDW.TransferFcn4_states
        [1];
      rtDW.TransferFcn4_states[1] = rtDW.TransferFcn4_states[0];
      rtDW.TransferFcn4_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn5'
      denAccum = (rtDW.TmpRTBAtProductOutport1[4] - -0.904814786066005 *
                  rtDW.TransferFcn5_states[0]) - 0.0 * rtDW.TransferFcn5_states
        [1];
      rtDW.TransferFcn5_states[1] = rtDW.TransferFcn5_states[0];
      rtDW.TransferFcn5_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn6'
      denAccum = (rtDW.TmpRTBAtProductOutport1[5] - -0.904814786066005 *
                  rtDW.TransferFcn6_states[0]) - 0.0 * rtDW.TransferFcn6_states
        [1];
      rtDW.TransferFcn6_states[1] = rtDW.TransferFcn6_states[0];
      rtDW.TransferFcn6_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn7'
      denAccum = (rtDW.TmpRTBAtProductOutport1[6] - -0.904814786066005 *
                  rtDW.TransferFcn7_states[0]) - 0.0 * rtDW.TransferFcn7_states
        [1];
      rtDW.TransferFcn7_states[1] = rtDW.TransferFcn7_states[0];
      rtDW.TransferFcn7_states[0] = denAccum;

      // Update for DiscreteTransferFcn: '<S18>/Transfer Fcn8'
      denAccum = (rtDW.TmpRTBAtProductOutport1[7] - -0.904814786066005 *
                  rtDW.TransferFcn8_states[0]) - 0.0 * rtDW.TransferFcn8_states
        [1];
      rtDW.TransferFcn8_states[1] = rtDW.TransferFcn8_states[0];
      rtDW.TransferFcn8_states[0] = denAccum;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    // Update absolute time
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    // Update absolute time
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.001, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    rtM->Timing.clockTick1++;
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void dynamic_model_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  // Derivatives for Integrator: '<S19>/q0 q1 q2 q3'
  _rtXdot->q0q1q2q3_CSTATE[0] = rtDW.q0dot;
  _rtXdot->q0q1q2q3_CSTATE[1] = rtDW.q1dot;
  _rtXdot->q0q1q2q3_CSTATE[2] = rtDW.q2dot;
  _rtXdot->q0q1q2q3_CSTATE[3] = rtDW.q3dot;

  // Derivatives for Integrator: '<S1>/p,q,r '
  _rtXdot->pqr_CSTATE[0] = rtDW.Product2[0];

  // Derivatives for Integrator: '<S1>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[0] = rtDW.Sum[0];

  // Derivatives for Integrator: '<S1>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[0] = rtDW.Product_j[0];

  // Derivatives for Integrator: '<S1>/p,q,r '
  _rtXdot->pqr_CSTATE[1] = rtDW.Product2[1];

  // Derivatives for Integrator: '<S1>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[1] = rtDW.Sum[1];

  // Derivatives for Integrator: '<S1>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[1] = rtDW.Product_j[1];

  // Derivatives for Integrator: '<S1>/p,q,r '
  _rtXdot->pqr_CSTATE[2] = rtDW.Product2[2];

  // Derivatives for Integrator: '<S1>/ub,vb,wb'
  _rtXdot->ubvbwb_CSTATE[2] = rtDW.Sum[2];

  // Derivatives for Integrator: '<S1>/xe,ye,ze'
  _rtXdot->xeyeze_CSTATE[2] = rtDW.Product_j[2];
}

// Model step function for TID2
void dynamic_model_step2(void)         // Sample time: [0.004s, 0.0s]
{
  // local block i/o variables
  real_T rtb_Output_g;
  int32_T iU;
  real_T rtb_Saturation;
  real_T rtb_Saturation3;
  real_T rtb_Saturation4;
  real_T rtb_Saturation5;

  // Sum: '<S91>/Sum' incorporates:
  //   Product: '<S94>/i x j'
  //   Product: '<S94>/j x k'
  //   Product: '<S94>/k x i'
  //   Product: '<S95>/i x k'
  //   Product: '<S95>/j x i'
  //   Product: '<S95>/k x j'

  rtDW.WhiteNoise_f[0] = rtDW.ZeroOrderHold[1] * 0.0 - rtDW.ZeroOrderHold[2] *
    -0.0;
  rtDW.WhiteNoise_f[1] = rtDW.ZeroOrderHold[2] * 0.0 - rtDW.ZeroOrderHold[0] *
    0.0;
  rtDW.WhiteNoise_f[2] = rtDW.ZeroOrderHold[0] * -0.0 - rtDW.ZeroOrderHold[1] *
    0.0;

  // Sum: '<S90>/Sum' incorporates:
  //   Product: '<S92>/i x j'
  //   Product: '<S92>/j x k'
  //   Product: '<S92>/k x i'
  //   Product: '<S93>/i x k'
  //   Product: '<S93>/j x i'
  //   Product: '<S93>/k x j'
  //   Product: '<S96>/j x k'
  //   Product: '<S96>/k x i'
  //   Product: '<S97>/i x k'
  //   Product: '<S97>/k x j'
  //   Sum: '<S79>/Sum'
  //   Sum: '<S84>/Sum'

  rtb_Saturation = rtDW.ZeroOrderHold[2] * rtDW.WhiteNoise_f[0];
  rtb_Saturation3 = rtDW.ZeroOrderHold[0] * rtDW.WhiteNoise_f[1];
  rtb_Saturation4 = rtDW.ZeroOrderHold[1] * rtDW.WhiteNoise_f[0];
  rtDW.WhiteNoise_f[0] = ((rtDW.ZeroOrderHold[1] * rtDW.WhiteNoise_f[2] -
    rtDW.ZeroOrderHold[2] * rtDW.WhiteNoise_f[1]) + (rtDW.ZeroOrderHold1[0] -
    rtDW.ZeroOrderHold2[0])) + (rtDW.ZeroOrderHold3[1] * 0.0 -
    rtDW.ZeroOrderHold3[2] * -0.0);
  rtDW.WhiteNoise_f[1] = ((rtb_Saturation - rtDW.ZeroOrderHold[0] *
    rtDW.WhiteNoise_f[2]) + (rtDW.ZeroOrderHold1[1] - rtDW.ZeroOrderHold2[1])) +
    (rtDW.ZeroOrderHold3[2] * 0.0 - rtDW.ZeroOrderHold3[0] * 0.0);

  // Sum: '<S79>/Sum' incorporates:
  //   Product: '<S96>/i x j'
  //   Product: '<S97>/j x i'
  //   Sum: '<S84>/Sum'
  //   Sum: '<S90>/Sum'

  rtb_Saturation = ((rtDW.ZeroOrderHold1[2] - rtDW.ZeroOrderHold2[2]) +
                    (rtb_Saturation3 - rtb_Saturation4)) + (rtDW.ZeroOrderHold3
    [0] * -0.0 - rtDW.ZeroOrderHold3[1] * 0.0);

  // Sum: '<S79>/Sum4' incorporates:
  //   Constant: '<S79>/Scale factors & Cross-coupling  errors'
  //   Product: '<S79>/Product'

  for (iU = 0; iU < 3; iU++) {
    rtDW.Saturation_p[iU] = (rtConstP.pooled5[iU + 3] * rtDW.WhiteNoise_f[1] +
      rtConstP.pooled5[iU] * rtDW.WhiteNoise_f[0]) + rtConstP.pooled5[iU + 6] *
      rtb_Saturation;
  }

  // End of Sum: '<S79>/Sum4'
  for (iU = 0; iU < 3; iU++) {
    // Saturate: '<S79>/Saturation' incorporates:
    //   Gain: '<S82>/Output'
    //   RandomNumber: '<S82>/White Noise'
    //   Sum: '<S79>/Sum1'

    rtb_Saturation = 0.011180339887498949 * rtDW.NextOutput[iU] +
      rtDW.Saturation_p[iU];

    // Saturate: '<S80>/Saturation' incorporates:
    //   Constant: '<S80>/Scale factors & Cross-coupling  errors '
    //   Gain: '<S99>/Output'
    //   Product: '<S80>/Product'
    //   Product: '<S80>/Product1'
    //   RandomNumber: '<S99>/White Noise'
    //   Sum: '<S80>/Sum1'
    //   Sum: '<S80>/Sum4'

    rtb_Saturation3 = 0.00070710678118654762 * rtDW.NextOutput_p[iU] +
      (rtDW.ZeroOrderHold1_o[iU] * 0.0 + (rtConstP.pooled5[iU + 6] *
        rtDW.ZeroOrderHold_g[2] + (rtConstP.pooled5[iU + 3] *
         rtDW.ZeroOrderHold_g[1] + rtConstP.pooled5[iU] * rtDW.ZeroOrderHold_g[0])));
    if (rtb_Saturation3 > 4.36) {
      rtb_Saturation3 = 4.36;
    } else {
      if (rtb_Saturation3 < -4.36) {
        rtb_Saturation3 = -4.36;
      }
    }

    // End of Saturate: '<S80>/Saturation'

    // Saturate: '<S79>/Saturation' incorporates:
    //   RandomNumber: '<S82>/White Noise'

    if (rtb_Saturation > 19.62) {
      rtDW.WhiteNoise_f[iU] = 19.62;
    } else if (rtb_Saturation < -19.62) {
      rtDW.WhiteNoise_f[iU] = -19.62;
    } else {
      rtDW.WhiteNoise_f[iU] = rtb_Saturation;
    }

    // Product: '<S80>/Product' incorporates:
    //   Constant: '<S80>/Scale factors & Cross-coupling  errors '

    rtDW.Saturation_p[iU] = rtb_Saturation3;
  }

  // RateTransition: '<Root>/Rate Transition10'
  if (rtM->Timing.RateInteraction.TID2_5) {
    rtDW.RateTransition10[0] = rtDW.RateTransition10_Buffer0[0];
    rtDW.RateTransition10[1] = rtDW.RateTransition10_Buffer0[1];
    rtDW.RateTransition10[2] = rtDW.RateTransition10_Buffer0[2];
  }

  // End of RateTransition: '<Root>/Rate Transition10'

  // RateTransition: '<Root>/Rate Transition7'
  if (rtM->Timing.RateInteraction.TID2_4) {
    rtY.measurements.sonar_z = rtDW.RateTransition7_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition7'

  // Fcn: '<S17>/voltage2' incorporates:
  //   Inport: '<Root>/pwm_cmd'

  rtb_Saturation = (rtU.controls.pwm1 - 1000.0) / 1000.0;

  // Saturate: '<S17>/Saturation'
  if (rtb_Saturation > 1.0) {
    rtb_Saturation = 1.0;
  } else {
    if (rtb_Saturation < 0.0) {
      rtb_Saturation = 0.0;
    }
  }

  // End of Saturate: '<S17>/Saturation'

  // Fcn: '<S17>/voltage3' incorporates:
  //   Inport: '<Root>/pwm_cmd'

  rtb_Saturation3 = (rtU.controls.pwm2 - 1000.0) / 1000.0;

  // Saturate: '<S17>/Saturation3'
  if (rtb_Saturation3 > 1.0) {
    rtb_Saturation3 = 1.0;
  } else {
    if (rtb_Saturation3 < 0.0) {
      rtb_Saturation3 = 0.0;
    }
  }

  // End of Saturate: '<S17>/Saturation3'

  // Fcn: '<S17>/voltage4' incorporates:
  //   Inport: '<Root>/pwm_cmd'

  rtb_Saturation4 = (rtU.controls.pwm3 - 1000.0) / 1000.0;

  // Saturate: '<S17>/Saturation4'
  if (rtb_Saturation4 > 1.0) {
    rtb_Saturation4 = 1.0;
  } else {
    if (rtb_Saturation4 < 0.0) {
      rtb_Saturation4 = 0.0;
    }
  }

  // End of Saturate: '<S17>/Saturation4'

  // Fcn: '<S17>/voltage5' incorporates:
  //   Inport: '<Root>/pwm_cmd'

  rtb_Saturation5 = (rtU.controls.pwm4 - 1000.0) / 1000.0;

  // Saturate: '<S17>/Saturation5'
  if (rtb_Saturation5 > 1.0) {
    rtb_Saturation5 = 1.0;
  } else {
    if (rtb_Saturation5 < 0.0) {
      rtb_Saturation5 = 0.0;
    }
  }

  // End of Saturate: '<S17>/Saturation5'

  // SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   MATLAB Function: '<Root>/LiPo Battery'

  rtDW.TmpSignalConversionAtSFunctionInport1[0] = rtb_Saturation;
  rtDW.TmpSignalConversionAtSFunctionInport1[1] = rtb_Saturation3;
  rtDW.TmpSignalConversionAtSFunctionInport1[2] = rtb_Saturation4;
  rtDW.TmpSignalConversionAtSFunctionInport1[3] = rtb_Saturation5;
  rtDW.TmpSignalConversionAtSFunctionInport1[4] = rtConstB.Saturation6;
  rtDW.TmpSignalConversionAtSFunctionInport1[5] = rtConstB.Saturation7;
  rtDW.TmpSignalConversionAtSFunctionInport1[6] = rtConstB.Saturation8;
  rtDW.TmpSignalConversionAtSFunctionInport1[7] = rtConstB.Saturation9;

  // MATLAB Function: '<Root>/LiPo Battery'
  // ================================Constants=================================
  // MATLAB Function 'LiPo Battery': '<S14>:1'
  // '<S14>:1:5' delta_t = 0.004;
  // '<S14>:1:6' max_current = 5.500;
  //  maximum current per motor             (A)
  // '<S14>:1:7' aux_current = 0.100;
  //  current of auxillary components       (A)
  // '<S14>:1:8' capacity = 1.000;
  //  LiPo current capacity                 (Ah)                                  
  // '<S14>:1:9' cells = 2;
  //  LiPo cell count
  // ==========================================================================
  // '<S14>:1:15' if isempty(discharge)
  // '<S14>:1:19' current = sum(max_current .* load.^2) + aux_current;
  for (iU = 0; iU < 8; iU++) {
    rtDW.y[iU] = rtDW.TmpSignalConversionAtSFunctionInport1[iU] *
      rtDW.TmpSignalConversionAtSFunctionInport1[iU] * 5.5;
  }

  rtDW.b_y = rtDW.y[0];
  for (iU = 0; iU < 7; iU++) {
    rtDW.b_y += rtDW.y[iU + 1];
  }

  // '<S14>:1:20' discharge = current * (delta_t / 3600) + discharge;
  rtDW.discharge += (rtDW.b_y + 0.1) * 1.111111111111111E-6;

  // '<S14>:1:22' discharge_capacity = discharge / capacity;
  // '<S14>:1:24' if (0 < discharge_capacity) && (discharge_capacity <=0.20)
  if ((0.0 < rtDW.discharge) && (rtDW.discharge <= 0.2)) {
    // '<S14>:1:25' cell_voltage = -14.029*discharge_capacity^3 + 16.975*discharge_capacity^2 - 5.3339*discharge_capacity + 4.2; 
    rtDW.b_y = ((rtDW.discharge * rtDW.discharge * 16.975 + -14.029 *
                 rt_powd_snf(rtDW.discharge, 3.0)) - 5.3339 * rtDW.discharge) +
      4.2;
  } else if ((0.2 < rtDW.discharge) && (rtDW.discharge < 0.7)) {
    // '<S14>:1:26' elseif (0.20 < discharge_capacity) && (discharge_capacity < 0.70) 
    // '<S14>:1:27' cell_voltage = -0.2*discharge_capacity + 3.74;
    rtDW.b_y = -0.2 * rtDW.discharge + 3.74;
  } else {
    // '<S14>:1:28' else
    // '<S14>:1:29' cell_voltage = -48*discharge_capacity^3 + 89.6*discharge_capacity^2 - 55.08*discharge_capacity + 14.716; 
    rtDW.b_y = ((rtDW.discharge * rtDW.discharge * 89.6 + -48.0 * rt_powd_snf
                 (rtDW.discharge, 3.0)) - 55.08 * rtDW.discharge) + 14.716;
  }

  // '<S14>:1:32' if cell_voltage < (5 / cells)
  if (rtDW.b_y < 2.5) {
    // '<S14>:1:33' cell_voltage = 0;
    rtDW.b_y = 0.0;
  }

  // '<S14>:1:36' supply_voltage = cells * cell_voltage;
  rtDW.supply_voltage = 2.0 * rtDW.b_y;

  // '<S14>:1:37' voltage = supply_voltage .* load;
  // ==========================================================================
  rtY.measurements.bat_volt = rtDW.b_y;

  // BusCreator: '<Root>/BusConversion_InsertedFor_measurements_at_inport_0'
  rtY.measurements.acc_x = rtDW.WhiteNoise_f[0];
  rtY.measurements.acc_y = rtDW.WhiteNoise_f[1];
  rtY.measurements.acc_z = rtDW.WhiteNoise_f[2];
  rtY.measurements.gyro_x = rtDW.Saturation_p[0];
  rtY.measurements.gyro_y = rtDW.Saturation_p[1];
  rtY.measurements.gyro_z = rtDW.Saturation_p[2];
  rtY.measurements.att_x = rtDW.RateTransition8[0];
  rtY.measurements.att_y = rtDW.RateTransition8[1];
  rtY.measurements.att_z = rtDW.RateTransition8[2];
  rtY.measurements.gps_n = rtDW.RateTransition10[0];
  rtY.measurements.gps_e = rtDW.RateTransition10[1];
  rtY.measurements.gps_d = rtDW.RateTransition10[2];

  // Gain: '<S5>/Output' incorporates:
  //   RandomNumber: '<S5>/White Noise'

  rtb_Output_g = 0.00019364916731037085 * rtDW.NextOutput_l;

  // Gain: '<S6>/Output' incorporates:
  //   RandomNumber: '<S6>/White Noise'

  rtDW.Output_g2[0] = 0.086602540378443879 * rtDW.NextOutput_ls[0];
  rtDW.Output_g2[1] = 0.086602540378443879 * rtDW.NextOutput_ls[1];
  rtDW.Output_g2[2] = 0.1 * rtDW.NextOutput_ls[2];

  // Product: '<S18>/Product' incorporates:
  //   MATLAB Function: '<Root>/LiPo Battery'
  //   SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport1'

  rtDW.Product_o[0] = rtDW.supply_voltage * rtb_Saturation * rtb_Saturation;
  rtDW.Product_o[1] = rtDW.supply_voltage * rtb_Saturation3 * rtb_Saturation3;
  rtDW.Product_o[2] = rtDW.supply_voltage * rtb_Saturation4 * rtb_Saturation4;
  rtDW.Product_o[3] = rtDW.supply_voltage * rtb_Saturation5 * rtb_Saturation5;
  rtDW.Product_o[4] = rtDW.supply_voltage * rtConstB.Saturation6 *
    rtConstB.Saturation6;
  rtDW.Product_o[5] = rtDW.supply_voltage * rtConstB.Saturation7 *
    rtConstB.Saturation7;
  rtDW.Product_o[6] = rtDW.supply_voltage * rtConstB.Saturation8 *
    rtConstB.Saturation8;
  rtDW.Product_o[7] = rtDW.supply_voltage * rtConstB.Saturation9 *
    rtConstB.Saturation9;

  // S-Function (saeroclockpacer): '<Root>/Simulation Pace'
  //
  //  The Clock Pacer generates no code, it is only active in
  //  interpreted simulation.


  // Update for RandomNumber: '<S82>/White Noise'
  rtDW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed[0]);

  // Update for RandomNumber: '<S99>/White Noise'
  rtDW.NextOutput_p[0] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_j[0]);

  // Update for RandomNumber: '<S82>/White Noise'
  rtDW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed[1]);

  // Update for RandomNumber: '<S99>/White Noise'
  rtDW.NextOutput_p[1] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_j[1]);

  // Update for RandomNumber: '<S82>/White Noise'
  rtDW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed[2]);

  // Update for RandomNumber: '<S99>/White Noise'
  rtDW.NextOutput_p[2] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_j[2]);

  // Update for RateTransition: '<Root>/TmpRTBAtAdd5Inport2'
  rtDW.TmpRTBAtAdd5Inport2_Buffer0 = rtb_Output_g;

  // Update for RateTransition: '<Root>/TmpRTBAtAdd8Inport2'
  rtDW.TmpRTBAtAdd8Inport2_Buffer0[0] = rtDW.Output_g2[0];
  rtDW.TmpRTBAtAdd8Inport2_Buffer0[1] = rtDW.Output_g2[1];
  rtDW.TmpRTBAtAdd8Inport2_Buffer0[2] = rtDW.Output_g2[2];

  // Update for RandomNumber: '<S5>/White Noise'
  rtDW.NextOutput_l = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_l);

  // Update for RandomNumber: '<S6>/White Noise'
  rtDW.NextOutput_ls[0] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_li[0]);
  rtDW.NextOutput_ls[1] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_li[1]);
  rtDW.NextOutput_ls[2] = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_li[2]);

  // Update for RateTransition: '<S18>/TmpRTBAtProductOutport1'
  memcpy(&rtDW.TmpRTBAtProductOutport1_Buffer0[0], &rtDW.Product_o[0], sizeof
         (real_T) << 3U);
}

// Model step function for TID3
void dynamic_model_step3(void)         // Sample time: [0.008s, 0.0s]
{
  // (no output/update code required)
}

// Model step function for TID4
void dynamic_model_step4(void)         // Sample time: [0.1s, 0.0s]
{
  // local block i/o variables
  real_T rtb_Output_gq;

  // Gain: '<S7>/Output' incorporates:
  //   RandomNumber: '<S7>/White Noise'

  rtb_Output_gq = 0.0070710678118654753 * rtDW.NextOutput_m;

  // Update for RateTransition: '<Root>/Rate Transition7'
  rtDW.RateTransition7_Buffer0 = rtDW.RateTransition2;

  // Update for RateTransition: '<Root>/TmpRTBAtAdd2Inport2'
  rtDW.TmpRTBAtAdd2Inport2_Buffer0 = rtb_Output_gq;

  // Update for RandomNumber: '<S7>/White Noise'
  rtDW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_o);
}

// Model step function for TID5
void dynamic_model_step5(void)         // Sample time: [0.2s, 0.0s]
{
  // Update for RateTransition: '<Root>/Rate Transition10'
  rtDW.RateTransition10_Buffer0[0] = rtDW.RateTransition11[0];
  rtDW.RateTransition10_Buffer0[1] = rtDW.RateTransition11[1];
  rtDW.RateTransition10_Buffer0[2] = rtDW.RateTransition11[2];
}

// Model step wrapper function for compatibility with a static main program
void dynamic_model_step(int_T tid)
{
  switch (tid) {
   case 0 :
    dynamic_model_step0();
    break;

   case 2 :
    dynamic_model_step2();
    break;

   case 3 :
    dynamic_model_step3();
    break;

   case 4 :
    dynamic_model_step4();
    break;

   case 5 :
    dynamic_model_step5();
    break;

   default :
    break;
  }
}

// Model initialize function
void dynamic_model_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(rtM, 1);

  {
    uint32_T tseed;
    real_T y1;

    // Start for If: '<S11>/If'
    rtDW.If_ActiveSubsystem = -1;

    // Start for IfAction SubSystem: '<S11>/Negative Trace'
    // Start for If: '<S53>/Find Maximum Diagonal Value'
    rtDW.FindMaximumDiagonalValue_ActiveSubsystem = -1;

    // End of Start for SubSystem: '<S11>/Negative Trace'

    // InitializeConditions for Integrator: '<S1>/p,q,r '
    rtX.pqr_CSTATE[0] = 0.0;
    rtX.pqr_CSTATE[1] = 0.0;
    rtX.pqr_CSTATE[2] = 0.0;

    // InitializeConditions for Integrator: '<S19>/q0 q1 q2 q3'
    if (rtmIsFirstInitCond(rtM)) {
      rtX.q0q1q2q3_CSTATE[0] = 0.0;
      rtX.q0q1q2q3_CSTATE[1] = 0.0;
      rtX.q0q1q2q3_CSTATE[2] = 0.0;
      rtX.q0q1q2q3_CSTATE[3] = 0.0;
    }

    rtDW.q0q1q2q3_IWORK = 1;

    // End of InitializeConditions for Integrator: '<S19>/q0 q1 q2 q3'

    // InitializeConditions for Integrator: '<S1>/ub,vb,wb'
    rtX.ubvbwb_CSTATE[0] = 0.0;

    // InitializeConditions for Integrator: '<S1>/xe,ye,ze'
    rtX.xeyeze_CSTATE[0] = 0.0;

    // InitializeConditions for RandomNumber: '<S82>/White Noise'
    tseed = 1373044741U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput[0] = y1;
    rtDW.RandSeed[0] = tseed;

    // InitializeConditions for Integrator: '<S1>/ub,vb,wb'
    rtX.ubvbwb_CSTATE[1] = 0.0;

    // InitializeConditions for Integrator: '<S1>/xe,ye,ze'
    rtX.xeyeze_CSTATE[1] = 0.0;

    // InitializeConditions for RandomNumber: '<S82>/White Noise'
    tseed = 411009029U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput[1] = y1;
    rtDW.RandSeed[1] = tseed;

    // InitializeConditions for Integrator: '<S1>/ub,vb,wb'
    rtX.ubvbwb_CSTATE[2] = 0.0;

    // InitializeConditions for Integrator: '<S1>/xe,ye,ze'
    rtX.xeyeze_CSTATE[2] = -1.0;

    // InitializeConditions for RandomNumber: '<S82>/White Noise'
    tseed = 1845526542U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput[2] = y1;
    rtDW.RandSeed[2] = tseed;

    // InitializeConditions for RandomNumber: '<S99>/White Noise'
    tseed = 1689616386U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_p[0] = y1;
    rtDW.RandSeed_j[0] = tseed;
    tseed = 1998225409U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_p[1] = y1;
    rtDW.RandSeed_j[1] = tseed;
    tseed = 1181220867U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_p[2] = y1;
    rtDW.RandSeed_j[2] = tseed;

    // InitializeConditions for RandomNumber: '<S5>/White Noise'
    rtDW.RandSeed_l = 931168259U;
    rtDW.NextOutput_l = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_l);

    // InitializeConditions for RandomNumber: '<S6>/White Noise'
    tseed = 931168259U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_ls[0] = y1;
    rtDW.RandSeed_li[0] = tseed;
    tseed = 2125594624U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_ls[1] = y1;
    rtDW.RandSeed_li[1] = tseed;
    tseed = 169345024U;
    y1 = rt_nrand_Upu32_Yd_f_pw_snf(&tseed);
    rtDW.NextOutput_ls[2] = y1;
    rtDW.RandSeed_li[2] = tseed;

    // InitializeConditions for RandomNumber: '<S7>/White Noise'
    rtDW.RandSeed_o = 2086731776U;
    rtDW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed_o);

    // SystemInitialize for Merge: '<S11>/Merge'
    // '<S14>:1:16' discharge = 0;
    rtDW.Merge[0] = 1.0;
    rtDW.Merge[1] = 0.0;
    rtDW.Merge[2] = 0.0;
    rtDW.Merge[3] = 0.0;
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(rtM)) {
    rtmSetFirstInitCond(rtM, 0);
  }
}

// Model terminate function
void dynamic_model_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
