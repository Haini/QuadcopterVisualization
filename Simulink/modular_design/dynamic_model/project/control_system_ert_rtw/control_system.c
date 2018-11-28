/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_system.c
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

#include "control_system.h"
#define NumBitsPerChar                 8U

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void invNxN(const real_T x[16], real_T y[16]);
static void rate_scheduler(void);
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

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
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

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
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

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 249) {/* Sample time: [1.0s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/PoseEstimator ' */
static void invNxN(const real_T x[16], real_T y[16])
{
  int8_T p[4];
  real_T A[16];
  int8_T ipiv[4];
  int32_T b_j;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kAcol;
  int32_T c_i;
  for (b_j = 0; b_j < 16; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (b_j = 0; b_j < 3; b_j++) {
    jBcol = b_j * 5;
    iy = 0;
    kAcol = jBcol;
    smax = fabs(A[jBcol]);
    for (c_i = 2; c_i <= 4 - b_j; c_i++) {
      kAcol++;
      s = fabs(A[kAcol]);
      if (s > smax) {
        iy = c_i - 1;
        smax = s;
      }
    }

    if (A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[b_j] = (int8_T)((b_j + iy) + 1);
        iy += b_j;
        smax = A[b_j];
        A[b_j] = A[iy];
        A[iy] = smax;
        kAcol = b_j + 4;
        iy += 4;
        smax = A[kAcol];
        A[kAcol] = A[iy];
        A[iy] = smax;
        kAcol += 4;
        iy += 4;
        smax = A[kAcol];
        A[kAcol] = A[iy];
        A[iy] = smax;
        kAcol += 4;
        iy += 4;
        smax = A[kAcol];
        A[kAcol] = A[iy];
        A[iy] = smax;
      }

      iy = (jBcol - b_j) + 4;
      for (kAcol = jBcol + 1; kAcol + 1 <= iy; kAcol++) {
        A[kAcol] /= A[jBcol];
      }
    }

    iy = jBcol;
    kAcol = jBcol + 4;
    for (c_i = 1; c_i <= 3 - b_j; c_i++) {
      smax = A[kAcol];
      if (A[kAcol] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - b_j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= d; ijA++) {
          A[ijA] += A[c_ix] * -smax;
          c_ix++;
        }
      }

      kAcol += 4;
      iy += 4;
    }
  }

  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  if (ipiv[0] > 1) {
    jBcol = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = 1;
    p[0] = (int8_T)jBcol;
  }

  if (ipiv[1] > 2) {
    jBcol = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = (int8_T)jBcol;
  }

  if (ipiv[2] > 3) {
    jBcol = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = (int8_T)jBcol;
  }

  jBcol = p[0] - 1;
  y[(p[0] - 1) << 2] = 1.0;
  for (iy = 0; iy + 1 < 5; iy++) {
    if (y[(jBcol << 2) + iy] != 0.0) {
      for (kAcol = iy + 1; kAcol + 1 < 5; kAcol++) {
        y[kAcol + (jBcol << 2)] -= y[(jBcol << 2) + iy] * A[(iy << 2) + kAcol];
      }
    }
  }

  jBcol = p[1] - 1;
  y[1 + ((p[1] - 1) << 2)] = 1.0;
  for (iy = 1; iy + 1 < 5; iy++) {
    if (y[(jBcol << 2) + iy] != 0.0) {
      for (kAcol = iy + 1; kAcol + 1 < 5; kAcol++) {
        y[kAcol + (jBcol << 2)] -= y[(jBcol << 2) + iy] * A[(iy << 2) + kAcol];
      }
    }
  }

  jBcol = p[2] - 1;
  y[2 + ((p[2] - 1) << 2)] = 1.0;
  for (iy = 2; iy + 1 < 5; iy++) {
    if (y[(jBcol << 2) + iy] != 0.0) {
      for (kAcol = iy + 1; kAcol + 1 < 5; kAcol++) {
        y[kAcol + (jBcol << 2)] -= y[(jBcol << 2) + iy] * A[(iy << 2) + kAcol];
      }
    }
  }

  jBcol = p[3] - 1;
  y[3 + ((p[3] - 1) << 2)] = 1.0;
  for (iy = 3; iy + 1 < 5; iy++) {
    if (y[(jBcol << 2) + iy] != 0.0) {
      for (kAcol = iy + 1; kAcol + 1 < 5; kAcol++) {
        y[kAcol + (jBcol << 2)] -= y[(jBcol << 2) + iy] * A[(iy << 2) + kAcol];
      }
    }
  }

  for (b_j = 0; b_j < 4; b_j++) {
    jBcol = b_j << 2;
    if (y[3 + jBcol] != 0.0) {
      y[3 + jBcol] /= A[15];
      for (c_i = 0; c_i + 1 < 4; c_i++) {
        y[c_i + jBcol] -= y[3 + jBcol] * A[c_i + 12];
      }
    }

    if (y[2 + jBcol] != 0.0) {
      y[2 + jBcol] /= A[10];
      for (c_i = 0; c_i + 1 < 3; c_i++) {
        y[c_i + jBcol] -= y[2 + jBcol] * A[c_i + 8];
      }
    }

    if (y[1 + jBcol] != 0.0) {
      y[1 + jBcol] /= A[5];
      for (c_i = 0; c_i + 1 < 2; c_i++) {
        y[c_i + jBcol] -= y[1 + jBcol] * A[c_i + 4];
      }
    }

    if (y[jBcol] != 0.0) {
      y[jBcol] /= A[0];
    }
  }
}

/* Model step function */
void control_system_step(void)
{
  real_T V[24];
  real_T x_p[6];
  real_T sigma_p[36];
  int8_T I[36];
  static const real_T R[16] = { 3.0E-5, 0.0, 0.0, 0.0, 0.0, 3.0E-5, 0.0, 0.0,
    0.0, 0.0, 4.0E-5, 0.0, 0.0, 0.0, 0.0, 5.0E-6 };

  static const real_T b[36] = { 1.0, 0.0, 0.0, 0.004, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.004, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.004, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_b[24] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 1, 0, 0, 0 };

  static const real_T b_a[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.004, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.004, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.004, 0.0, 0.0, 1.0 };

  static const real_T c_b[16] = { 1.0E-9, 0.0, 0.0, 0.0, 0.0, 1.0E-9, 0.0, 0.0,
    0.0, 0.0, 1.0E-9, 0.0, 0.0, 0.0, 0.0, 3.0000000000000004E-9 };

  static const int8_T c_a[24] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  real_T rtb_Product;
  real_T rtb_VectorConcatenate1[2];
  real_T rtb_Sum_o[2];
  real_T rtb_TSamp;
  real_T rtb_Sum21;
  real_T rtb_Sum18;
  real_T rtb_Sum19;
  real_T rtb_Saturate_ng;
  real_T rtb_Sum22;
  real_T rtb_Sum17;
  real_T rtb_Saturate_b;
  real_T rtb_Saturate_j;
  real_T rtb_Saturation10;
  int32_T i;
  real_T c_a_0[16];
  real_T tmp[16];
  real_T V_0[24];
  real_T b_a_0[36];
  real_T V_1[36];
  int32_T i_0;
  int32_T i_1;
  real_T z_t_idx_0;
  real_T z_t_idx_1;
  real_T u0;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<Root>/Product'
   */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  /* '<S3>:1:6' if isempty(current) */
  /* '<S3>:1:10' xwant = nodes(current,1); */
  /* '<S3>:1:11' ywant = - nodes(current,2); */
  /* '<S3>:1:12' zwant = - nodes(current,3); */
  /* '<S3>:1:14' dist = sqrt((xis-xwant)^2 + (yis-ywant)^2 + (zis-zwant)^2); */
  rtb_TSamp = rtDW.Delay_DSTATE[1] - rtConstP.MATLABFunction_nodes[(int32_T)
    rtDW.current - 1];
  rtb_Sum18 = rtDW.Delay_DSTATE[0] - (-rtConstP.MATLABFunction_nodes[(int32_T)
    rtDW.current + 10]);
  rtb_Sum21 = -rtDW.Delay_DSTATE[2] - (-rtConstP.MATLABFunction_nodes[(int32_T)
    rtDW.current + 21]);

  /* '<S3>:1:15' if dist < 0.6 */
  if (sqrt((rtb_TSamp * rtb_TSamp + rtb_Sum18 * rtb_Sum18) + rtb_Sum21 *
           rtb_Sum21) < 0.6) {
    /* '<S3>:1:16' current = current + 1; */
    rtDW.current++;
  }

  /*  go back */
  /* '<S3>:1:20' if current > size(nodes,1) */
  if (rtDW.current > 11.0) {
    /* '<S3>:1:21' current =  size(nodes,1)-1; */
    rtDW.current = 10.0;
  }

  /* '<S3>:1:24' x = nodes(current,1); */
  rtb_VectorConcatenate1[0] = rtConstP.MATLABFunction_nodes[(int32_T)
    rtDW.current - 1];

  /* '<S3>:1:25' y = - nodes(current,2); */
  rtb_VectorConcatenate1[1] = -rtConstP.MATLABFunction_nodes[(int32_T)
    rtDW.current + 10];

  /* SignalConversion: '<S7>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  /* '<S3>:1:26' z = - nodes(current,3); */
  rtb_Sum_o[0] = rtDW.Delay_DSTATE[1];

  /* SignalConversion: '<S7>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Sum_o[1] = rtDW.Delay_DSTATE[0];

  /* RateTransition: '<S7>/Rate Transition3' incorporates:
   *  RateTransition: '<S7>/Rate Transition1'
   */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition3[0] = rtb_VectorConcatenate1[0];
    rtDW.RateTransition3[1] = rtb_VectorConcatenate1[1];
    rtDW.RateTransition1[0] = rtb_Sum_o[0];

    /* Sum: '<S21>/Diff' incorporates:
     *  UnitDelay: '<S21>/UD'
     *
     * Block description for '<S21>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S21>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.Diff[0] = rtDW.RateTransition1[0] - rtDW.UD_DSTATE[0];
    rtDW.RateTransition1[1] = rtb_Sum_o[1];

    /* Sum: '<S21>/Diff' incorporates:
     *  UnitDelay: '<S21>/UD'
     *
     * Block description for '<S21>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S21>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.Diff[1] = rtDW.RateTransition1[1] - rtDW.UD_DSTATE[1];
  }

  /* End of RateTransition: '<S7>/Rate Transition3' */

  /* Sum: '<S7>/Sum' */
  z_t_idx_0 = rtDW.RateTransition3[0] - rtb_Sum_o[0];

  /* Saturate: '<S7>/Saturation1' */
  if (z_t_idx_0 > 10.0) {
    z_t_idx_0 = 10.0;
  } else {
    if (z_t_idx_0 < -10.0) {
      z_t_idx_0 = -10.0;
    }
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  Gain: '<S7>/Gain1'
   */
  rtb_TSamp = 0.1 * z_t_idx_0 - rtDW.Diff[0];

  /* Sum: '<S22>/Sum' incorporates:
   *  DiscreteIntegrator: '<S22>/Integrator'
   *  Gain: '<S22>/Proportional Gain'
   */
  rtb_Product = 0.54 * rtb_TSamp + rtDW.Integrator_DSTATE[0];

  /* Sum: '<S7>/Sum3' */
  if (rtb_Product > 1.0) {
    rtb_Product = 1.0;
  } else {
    if (rtb_Product < -1.0) {
      rtb_Product = -1.0;
    }
  }

  /* DiscreteIntegrator: '<S22>/Integrator' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Sum_o[0] = acos(rtb_Product) + -1.57;

  /* Sum: '<S7>/Sum2' */
  rtb_VectorConcatenate1[0] = rtb_TSamp;

  /* Sum: '<S7>/Sum' */
  z_t_idx_0 = rtDW.RateTransition3[1] - rtb_Sum_o[1];

  /* Saturate: '<S7>/Saturation1' */
  if (z_t_idx_0 > 10.0) {
    z_t_idx_0 = 10.0;
  } else {
    if (z_t_idx_0 < -10.0) {
      z_t_idx_0 = -10.0;
    }
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  Gain: '<S7>/Gain1'
   */
  rtb_TSamp = 0.1 * z_t_idx_0 - rtDW.Diff[1];

  /* Sum: '<S22>/Sum' incorporates:
   *  DiscreteIntegrator: '<S22>/Integrator'
   *  Gain: '<S22>/Proportional Gain'
   */
  rtb_Product = 0.54 * rtb_TSamp + rtDW.Integrator_DSTATE[1];

  /* Sum: '<S7>/Sum3' */
  if (rtb_Product > 1.0) {
    rtb_Product = 1.0;
  } else {
    if (rtb_Product < -1.0) {
      rtb_Product = -1.0;
    }
  }

  /* DiscreteIntegrator: '<S22>/Integrator' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Sum_o[1] = acos(rtb_Product) + -1.57;

  /* Sum: '<S7>/Sum2' */
  rtb_VectorConcatenate1[1] = rtb_TSamp;

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Inport: '<Root>/measurements'
   */
  /* MATLAB Function 'simple_path_tracker /MATLAB Function': '<S23>:1' */
  /* '<S23>:1:3' y = zeros(2,1); */
  /* '<S23>:1:4' y(1)=world(1)*cos(yaw)-world(2)*sin(yaw); */
  /* '<S23>:1:5' y(2)=world(1)*sin(yaw)+world(2)*cos(yaw); */
  rtb_Sum18 = rtb_Sum_o[0] * sin(rtU.measurements.att_z) + rtb_Sum_o[1] * cos
    (rtU.measurements.att_z);

  /* Sum: '<S7>/Sum1' incorporates:
   *  Constant: '<S7>/Constant4'
   *  Gain: '<S7>/Gain'
   *  Inport: '<Root>/measurements'
   *  MATLAB Function: '<S7>/MATLAB Function'
   */
  rtb_Sum21 = (rtb_Sum_o[0] * cos(rtU.measurements.att_z) - rtb_Sum_o[1] * sin
               (rtU.measurements.att_z)) * -500.0 + 1500.0;

  /* Sum: '<S8>/Add1' incorporates:
   *  Delay: '<Root>/Delay'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  Product: '<Root>/Product'
   */
  rtb_Product = -rtConstP.MATLABFunction_nodes[(int32_T)rtDW.current + 21] -
    (-rtDW.Delay_DSTATE[2]);

  /* SampleTimeMath: '<S24>/TSamp'
   *
   * About '<S24>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = rtb_Product * 250.0;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S8>/D' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    rtDW.D = 10.0 * rtDW.DiscreteTimeIntegrator_DSTATE;
  }

  /* Outputs for Atomic SubSystem: '<Root>/reactive controller' */
  /* Gain: '<S6>/1 // rad_max' incorporates:
   *  Inport: '<Root>/measurements'
   */
  rtb_Sum_o[0] = 1.2732395447351628 * rtU.measurements.att_x;
  rtb_Sum_o[1] = 1.2732395447351628 * rtU.measurements.att_y;

  /* Fcn: '<S6>/Fcn2' */
  z_t_idx_0 = (rtb_Sum21 - 1500.0) / 500.0;

  /* Fcn: '<S6>/Fcn5' incorporates:
   *  Constant: '<S7>/Constant4'
   *  Gain: '<S7>/Gain'
   *  Sum: '<S7>/Sum1'
   */
  z_t_idx_1 = ((-500.0 * rtb_Sum18 + 1500.0) - 1500.0) / 500.0;

  /* Saturate: '<S6>/Saturation9' */
  if (z_t_idx_0 > 1.0) {
    z_t_idx_0 = 1.0;
  } else {
    if (z_t_idx_0 < -1.0) {
      z_t_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S6>/Saturation9' */

  /* Sum: '<S6>/Sum18' */
  rtb_Sum18 = z_t_idx_0 - rtb_Sum_o[0];

  /* Sum: '<S18>/Sum' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator'
   *  Gain: '<S18>/Proportional Gain'
   */
  z_t_idx_0 = 0.5 * rtb_Sum18 + rtDW.Integrator_DSTATE_c;

  /* Saturate: '<S18>/Saturate' */
  if (z_t_idx_0 > 1.0) {
    z_t_idx_0 = 1.0;
  } else {
    if (z_t_idx_0 < -1.0) {
      z_t_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S18>/Saturate' */

  /* Sum: '<S6>/Sum21' incorporates:
   *  Gain: '<S6>/1 // rads_max'
   *  Inport: '<Root>/measurements'
   */
  rtb_Sum21 = z_t_idx_0 - 0.23873241463784303 * rtU.measurements.gyro_x;

  /* Sum: '<S19>/Sum' incorporates:
   *  DiscreteIntegrator: '<S19>/Integrator'
   *  Gain: '<S19>/Proportional Gain'
   */
  rtb_Saturate_ng = 0.3 * rtb_Sum21 + rtDW.Integrator_DSTATE_l;

  /* Saturate: '<S19>/Saturate' */
  if (rtb_Saturate_ng > 1.0) {
    rtb_Saturate_ng = 1.0;
  } else {
    if (rtb_Saturate_ng < -1.0) {
      rtb_Saturate_ng = -1.0;
    }
  }

  /* End of Saturate: '<S19>/Saturate' */

  /* Saturate: '<S6>/Saturation8' */
  if (z_t_idx_1 > 1.0) {
    z_t_idx_1 = 1.0;
  } else {
    if (z_t_idx_1 < -1.0) {
      z_t_idx_1 = -1.0;
    }
  }

  /* End of Saturate: '<S6>/Saturation8' */

  /* Sum: '<S6>/Sum19' incorporates:
   *  Gain: '<S6>/Gain2'
   */
  rtb_Sum19 = -z_t_idx_1 - rtb_Sum_o[1];

  /* Sum: '<S15>/Sum' incorporates:
   *  DiscreteIntegrator: '<S15>/Integrator'
   *  Gain: '<S15>/Proportional Gain'
   */
  z_t_idx_0 = 0.5 * rtb_Sum19 + rtDW.Integrator_DSTATE_k;

  /* Saturate: '<S15>/Saturate' */
  if (z_t_idx_0 > 1.0) {
    z_t_idx_0 = 1.0;
  } else {
    if (z_t_idx_0 < -1.0) {
      z_t_idx_0 = -1.0;
    }
  }

  /* End of Saturate: '<S15>/Saturate' */

  /* Sum: '<S6>/Sum22' incorporates:
   *  Gain: '<S6>/1 // rads_max'
   *  Inport: '<Root>/measurements'
   */
  rtb_Sum22 = z_t_idx_0 - 0.23873241463784303 * rtU.measurements.gyro_y;

  /* Sum: '<S16>/Sum' incorporates:
   *  DiscreteIntegrator: '<S16>/Integrator'
   *  Gain: '<S16>/Proportional Gain'
   */
  rtb_Saturate_b = 0.3 * rtb_Sum22 + rtDW.Integrator_DSTATE_k4;

  /* Saturate: '<S16>/Saturate' */
  if (rtb_Saturate_b > 1.0) {
    rtb_Saturate_b = 1.0;
  } else {
    if (rtb_Saturate_b < -1.0) {
      rtb_Saturate_b = -1.0;
    }
  }

  /* End of Saturate: '<S16>/Saturate' */

  /* Sum: '<S6>/Sum17' incorporates:
   *  Gain: '<S6>/1 // rads_max_yaw'
   *  Inport: '<Root>/measurements'
   */
  rtb_Sum17 = 0.0 - 0.15915494309189535 * rtU.measurements.gyro_z;

  /* Sum: '<S20>/Sum' incorporates:
   *  DiscreteIntegrator: '<S20>/Integrator'
   *  Gain: '<S20>/Proportional Gain'
   */
  rtb_Saturate_j = 0.5 * rtb_Sum17 + rtDW.Integrator_DSTATE_d;

  /* Saturate: '<S20>/Saturate' */
  if (rtb_Saturate_j > 1.0) {
    rtb_Saturate_j = 1.0;
  } else {
    if (rtb_Saturate_j < -1.0) {
      rtb_Saturate_j = -1.0;
    }
  }

  /* End of Saturate: '<S20>/Saturate' */

  /* Fcn: '<S6>/Fcn6' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Gain: '<S8>/I'
   *  Gain: '<S8>/Invert'
   *  Gain: '<S8>/P'
   *  Sum: '<S24>/Diff'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add2'
   *  UnitDelay: '<S24>/UD'
   *
   * Block description for '<S24>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S24>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Saturation10 = ((-(((rtb_TSamp - rtDW.UD_DSTATE_f) * 200.0 + 200.0 *
    rtb_Product) + rtDW.D) + 1500.0) - 1000.0) / 1000.0;

  /* Saturate: '<S6>/Saturation10' */
  if (rtb_Saturation10 > 1.0) {
    rtb_Saturation10 = 1.0;
  } else {
    if (rtb_Saturation10 < 0.0) {
      rtb_Saturation10 = 0.0;
    }
  }

  /* End of Saturate: '<S6>/Saturation10' */

  /* MATLAB Function: '<S6>/pwm_out1' */
  /* MATLAB Function 'reactive controller/pwm_out1': '<S17>:1' */
  /* '<S17>:1:3' idle_PWM = 1000; */
  /*  Quad X */
  /* '<S17>:1:6' M1 = ((Roll + Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /* '<S17>:1:7' M2 = ((-Roll + Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /* '<S17>:1:8' M3 = ((-Roll - Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /* '<S17>:1:9' M4 = ((Roll - Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /* '<S17>:1:10' M5 = 1000; */
  /* '<S17>:1:11' M6 = 1000; */
  /* '<S17>:1:12' M7 = 1000; */
  /* '<S17>:1:13' M8 = 1000; */
  /*  Quad + */
  /*  M1 = ((Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((-Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = 1000; */
  /*  M6 = 1000; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Hex X */
  /*  M1 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M6 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  z_t_idx_0 = (((rtb_Saturate_ng + rtb_Saturate_b) - rtb_Saturate_j) / 2.0 *
               rtb_Saturation10 + rtb_Saturation10) * 1000.0 + 1000.0;
  z_t_idx_1 = (((-rtb_Saturate_ng + rtb_Saturate_b) + rtb_Saturate_j) / 2.0 *
               rtb_Saturation10 + rtb_Saturation10) * 1000.0 + 1000.0;
  u0 = (((-rtb_Saturate_ng - rtb_Saturate_b) - rtb_Saturate_j) / 2.0 *
        rtb_Saturation10 + rtb_Saturation10) * 1000.0 + 1000.0;
  rtb_Saturate_ng = (((rtb_Saturate_ng - rtb_Saturate_b) + rtb_Saturate_j) / 2.0
                     * rtb_Saturation10 + rtb_Saturation10) * 1000.0 + 1000.0;

  /* Update for DiscreteIntegrator: '<S18>/Integrator' incorporates:
   *  Gain: '<S18>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_c += 0.05 * rtb_Sum18 * 0.004;

  /* Update for DiscreteIntegrator: '<S19>/Integrator' incorporates:
   *  Gain: '<S19>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_l += 0.03 * rtb_Sum21 * 0.004;

  /* Update for DiscreteIntegrator: '<S15>/Integrator' incorporates:
   *  Gain: '<S15>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_k += 0.05 * rtb_Sum19 * 0.004;

  /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
   *  Gain: '<S16>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_k4 += 0.03 * rtb_Sum22 * 0.004;

  /* Update for DiscreteIntegrator: '<S20>/Integrator' incorporates:
   *  Gain: '<S20>/Integral Gain'
   */
  rtDW.Integrator_DSTATE_d += 0.05 * rtb_Sum17 * 0.004;

  /* Saturate: '<S6>/Output_Limits1' */
  if (z_t_idx_0 > 2000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm1 = 2000.0;
  } else if (z_t_idx_0 < 1000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm1 = 1000.0;
  } else {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm1 = z_t_idx_0;
  }

  if (z_t_idx_1 > 2000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm2 = 2000.0;
  } else if (z_t_idx_1 < 1000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm2 = 1000.0;
  } else {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm2 = z_t_idx_1;
  }

  if (u0 > 2000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm3 = 2000.0;
  } else if (u0 < 1000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm3 = 1000.0;
  } else {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm3 = u0;
  }

  if (rtb_Saturate_ng > 2000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm4 = 2000.0;
  } else if (rtb_Saturate_ng < 1000.0) {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm4 = 1000.0;
  } else {
    /* Outport: '<Root>/pwm_cmd' */
    rtY.pwm_cmd.pwm4 = rtb_Saturate_ng;
  }

  /* End of Saturate: '<S6>/Output_Limits1' */
  /* End of Outputs for SubSystem: '<Root>/reactive controller' */

  /* MATLAB Function: '<Root>/CalcThrust ' */
  /* MATLAB Function 'CalcThrust ': '<S1>:1' */
  /* '<S1>:1:5' maxAirVelocity = 70; */
  /* TODO FIND MAX V through 1 rotor */
  /* '<S1>:1:6' air_density = 1.225; */
  /* kg/m^3 */
  /* '<S1>:1:7' rotor_diameter = 0.1397; */
  /*  diameter of the propellor              (meters)    */
  /* rotor_inertia = 0.0000025;          % rotor inertia (torque for angular acc) (kg m^2)                                   */
  /* aircraft_diameter = 0.25;           % motor to motor distance               (meters)                                  */
  /* aircraft_mass = 0.26;               % aircraft mass                         (kg)   */
  /* thrust kg m /s^2 */
  /* '<S1>:1:15' air_velocity = maxAirVelocity * thrust_normalized; */
  /* '<S1>:1:16' thrust = (pi/4 * rotor_diameter^2 * 4) * air_density * air_velocity; */
  rtb_Sum18 = 70.0 * rtb_Saturation10 * 0.075106716089226588;

  /* MATLAB Function: '<Root>/PoseEstimator ' incorporates:
   *  Inport: '<Root>/measurements'
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport2'
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* need to get t (simulation timestep) */
  /* MATLAB Function 'PoseEstimator ': '<S4>:1' */
  /* '<S4>:1:4' t = 0.004; */
  /* '<S4>:1:5' t_sonar = 0.1; */
  /* '<S4>:1:6' t_gps = 0.2; */
  /* '<S4>:1:7' m = 0.26; */
  /* '<S4>:1:8' g = 9.81; */
  /* '<S4>:1:16' if isempty(t_act_gps) */
  /* '<S4>:1:19' if isempty(t_act_sonar) */
  /* '<S4>:1:23' t_act_sonar = t_act_sonar + t; */
  rtDW.t_act_sonar += 0.004;

  /* '<S4>:1:24' t_act_gps = t_act_gps + t; */
  rtDW.t_act_gps += 0.004;

  /* DETECT MEASUREMENT CHANGED */
  /* '<S4>:1:29' if isempty(last_measurement) */
  if (!rtDW.last_measurement_not_empty) {
    /* '<S4>:1:30' last_measurement = measurement; */
    rtDW.last_measurement[0] = rtU.measurements.gps_n;
    rtDW.last_measurement[1] = rtU.measurements.gps_e;
    rtDW.last_measurement[2] = rtU.measurements.gps_d;
    rtDW.last_measurement[3] = rtU.measurements.sonar_z;
    rtDW.last_measurement_not_empty = true;
  }

  /* '<S4>:1:32' if last_measurement(4) ~= measurement(4) */
  if (rtDW.last_measurement[3] != rtU.measurements.sonar_z) {
    /* '<S4>:1:33' t_act_sonar = t_act_sonar + t_sonar; */
    rtDW.t_act_sonar += 0.1;
  }

  /* '<S4>:1:35' if (last_measurement(1) ~= measurement(1)) || (last_measurement(2) ~= measurement(2)) || (last_measurement(3) ~= measurement(3)) */
  if ((rtDW.last_measurement[0] != rtU.measurements.gps_n) ||
      (rtDW.last_measurement[1] != rtU.measurements.gps_e) ||
      (rtDW.last_measurement[2] != rtU.measurements.gps_d)) {
    /* '<S4>:1:36' t_act_gps = t_act_gps + t_gps; */
    rtDW.t_act_gps += 0.2;
  }

  /* '<S4>:1:42' if isempty(x) */
  /* '<S4>:1:50' if isempty(sigma) */
  /* '<S4>:1:60' phi = -attitude(1); */
  /* '<S4>:1:61' theta = -attitude(2); */
  /* '<S4>:1:62' psi = attitude(3); */
  /* '<S4>:1:64' Kp = 0.282; */
  /* todo tEST  */
  /* TODO: some signs may be wrong here (different papers show them */
  /* differently) - check in simulation */
  /* '<S4>:1:68' f_x = [x(4);  */
  /* '<S4>:1:69'        x(5);  */
  /* '<S4>:1:70'        x(6);  */
  /* '<S4>:1:71'        (cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi)) * (thrust - Kp * x(4))/m;  */
  /* '<S4>:1:72'        (cos(phi)*sin(theta)*sin(psi) - sin(phi)*cos(psi)) * (thrust - Kp * x(5))/m;  */
  /* '<S4>:1:73'        -g + cos(phi)*cos(theta)*(thrust - Kp * x(6))/m]; */
  /* note: z pointing upwards */
  /* '<S4>:1:75' G = [ 1 0 0 t 0 0; */
  /* '<S4>:1:76'       0 1 0 0 t 0; */
  /* '<S4>:1:77'       0 0 1 0 0 t; */
  /* '<S4>:1:78'       0 0 0 1 0 0; */
  /* '<S4>:1:79'       0 0 0 0 1 0; */
  /* '<S4>:1:80'       0 0 0 0 0 1]; */
  /* u is [phi theta psi thrust]' */
  /* '<S4>:1:83' v_4_1 = (sin(psi)*cos(phi)-sin(theta)*cos(psi)*sin(phi))*thrust/m; */
  /* '<S4>:1:84' v_4_2 = (cos(phi)*cos(theta)*cos(psi))*thrust/m; */
  /* '<S4>:1:85' v_4_3 = (cos(psi)*sin(phi)-sin(theta)*sin(psi)*cos(phi))*thrust/m; */
  /* '<S4>:1:86' v_4_4 = (cos(phi)*sin(theta)*cos(psi) + sin(phi)*sin(psi))/m; */
  /* '<S4>:1:88' v_5_1 = (cos(psi)*(-cos(phi))-sin(theta)*sin(psi)*sin(phi))*thrust/m; */
  /* '<S4>:1:89' v_5_2 = (cos(theta)*sin(psi)*cos(phi))*thrust/m; */
  /* '<S4>:1:90' v_5_3 = (sin(theta)*cos(psi)*cos(phi)+sin(psi)*sin(phi))*thrust/m; */
  /* '<S4>:1:91' v_5_4 = (cos(phi)*sin(theta)*sin(psi) - sin(phi)*cos(psi))/m; */
  /* '<S4>:1:93' v_6_1 = -sin(phi)*cos(theta)*thrust/m; */
  /* '<S4>:1:94' v_6_2 = -cos(phi)*sin(theta)*thrust/m; */
  /* '<S4>:1:95' v_6_3 = 0; */
  /* '<S4>:1:96' v_6_4 = cos(phi)*cos(theta)/m; */
  /* '<S4>:1:98' V = [0 0 0 0; */
  /* '<S4>:1:99'      0 0 0 0; */
  /* '<S4>:1:100'      0 0 0 0; */
  /* '<S4>:1:101'     v_4_1 v_4_2 v_4_3 v_4_4; */
  /* '<S4>:1:102'     v_5_1 v_5_2 v_5_3 v_5_4; */
  /* '<S4>:1:103'     v_6_1 v_6_2 v_6_3 v_6_4]; */
  V[0] = 0.0;
  V[1] = 0.0;
  V[2] = 0.0;
  V[6] = 0.0;
  V[7] = 0.0;
  V[8] = 0.0;
  V[12] = 0.0;
  V[13] = 0.0;
  V[14] = 0.0;
  V[18] = 0.0;
  V[19] = 0.0;
  V[20] = 0.0;
  V[3] = (sin(rtU.measurements.att_z) * cos(-rtU.measurements.att_x) - sin
          (-rtU.measurements.att_y) * cos(rtU.measurements.att_z) * sin
          (-rtU.measurements.att_x)) * rtb_Sum18 / 0.26;
  V[9] = cos(-rtU.measurements.att_x) * cos(-rtU.measurements.att_y) * cos
    (rtU.measurements.att_z) * rtb_Sum18 / 0.26;
  V[15] = (cos(rtU.measurements.att_z) * sin(-rtU.measurements.att_x) - sin
           (-rtU.measurements.att_y) * sin(rtU.measurements.att_z) * cos
           (-rtU.measurements.att_x)) * rtb_Sum18 / 0.26;
  V[21] = (cos(-rtU.measurements.att_x) * sin(-rtU.measurements.att_y) * cos
           (rtU.measurements.att_z) + sin(-rtU.measurements.att_x) * sin
           (rtU.measurements.att_z)) / 0.26;
  V[4] = (cos(rtU.measurements.att_z) * -cos(-rtU.measurements.att_x) - sin
          (-rtU.measurements.att_y) * sin(rtU.measurements.att_z) * sin
          (-rtU.measurements.att_x)) * rtb_Sum18 / 0.26;
  V[10] = cos(-rtU.measurements.att_y) * sin(rtU.measurements.att_z) * cos
    (-rtU.measurements.att_x) * rtb_Sum18 / 0.26;
  V[16] = (sin(-rtU.measurements.att_y) * cos(rtU.measurements.att_z) * cos
           (-rtU.measurements.att_x) + sin(rtU.measurements.att_z) * sin
           (-rtU.measurements.att_x)) * rtb_Sum18 / 0.26;
  V[22] = (cos(-rtU.measurements.att_x) * sin(-rtU.measurements.att_y) * sin
           (rtU.measurements.att_z) - sin(-rtU.measurements.att_x) * cos
           (rtU.measurements.att_z)) / 0.26;
  V[5] = -sin(-rtU.measurements.att_x) * cos(-rtU.measurements.att_y) *
    rtb_Sum18 / 0.26;
  V[11] = -cos(-rtU.measurements.att_x) * sin(-rtU.measurements.att_y) *
    rtb_Sum18 / 0.26;
  V[17] = 0.0;
  V[23] = cos(-rtU.measurements.att_x) * cos(-rtU.measurements.att_y) / 0.26;

  /*  Uncertainties of [phi theta psi thrust] (TODO: use attitude estimator */
  /*  covariance for phi, theta, psi uncertainty) */
  /* '<S4>:1:108' q = [1*10^(-9) 1*10^(-9) 1*10^(-9) 3*10^(-9)]; */
  /* '<S4>:1:109' Q = [q(1) 0 0 0; */
  /* '<S4>:1:110'     0 q(2) 0 0; */
  /* '<S4>:1:111'     0 0 q(3) 0; */
  /* '<S4>:1:112'     0 0 0 q(4)]; */
  /* '<S4>:1:115' noise = [0.00003 0.00003 0.00004 0.000005]; */
  /* noise values taken from dynamic model */
  /* '<S4>:1:116' R = [noise(1) 0 0 0; */
  /* '<S4>:1:117'     0 noise(2) 0 0; */
  /* '<S4>:1:118'     0 0 noise(3) 0; */
  /* '<S4>:1:119'     0 0 0 noise(4)]; */
  /*  Prediction */
  /* '<S4>:1:123' x_p = x + f_x * t; */
  x_p[0] = rtDW.x[3] * 0.004 + rtDW.x[0];
  x_p[1] = rtDW.x[4] * 0.004 + rtDW.x[1];
  x_p[2] = rtDW.x[5] * 0.004 + rtDW.x[2];
  x_p[3] = (cos(-rtU.measurements.att_x) * sin(-rtU.measurements.att_y) * cos
            (rtU.measurements.att_z) + sin(-rtU.measurements.att_x) * sin
            (rtU.measurements.att_z)) * (rtb_Sum18 - 0.282 * rtDW.x[3]) / 0.26 *
    0.004 + rtDW.x[3];
  x_p[4] = (cos(-rtU.measurements.att_x) * sin(-rtU.measurements.att_y) * sin
            (rtU.measurements.att_z) - sin(-rtU.measurements.att_x) * cos
            (rtU.measurements.att_z)) * (rtb_Sum18 - 0.282 * rtDW.x[4]) / 0.26 *
    0.004 + rtDW.x[4];
  x_p[5] = ((rtb_Sum18 - 0.282 * rtDW.x[5]) * (cos(-rtU.measurements.att_x) *
             cos(-rtU.measurements.att_y)) / 0.26 + -9.81) * 0.004 + rtDW.x[5];

  /* '<S4>:1:124' sigma_p = G * sigma * G' + V*Q*V'; */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      sigma_p[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        sigma_p[i + 6 * i_0] += b_a[6 * i_1 + i] * rtDW.sigma[6 * i_0 + i_1];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      V_0[i + 6 * i_0] = 0.0;
      V_0[i + 6 * i_0] += c_b[i_0 << 2] * V[i];
      V_0[i + 6 * i_0] += c_b[(i_0 << 2) + 1] * V[i + 6];
      V_0[i + 6 * i_0] += c_b[(i_0 << 2) + 2] * V[i + 12];
      V_0[i + 6 * i_0] += c_b[(i_0 << 2) + 3] * V[i + 18];
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      b_a_0[i + 6 * i_0] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        b_a_0[i + 6 * i_0] += sigma_p[6 * i_1 + i] * b[6 * i_0 + i_1];
      }

      V_1[i + 6 * i_0] = 0.0;
      V_1[i + 6 * i_0] += V_0[i] * V[i_0];
      V_1[i + 6 * i_0] += V_0[i + 6] * V[i_0 + 6];
      V_1[i + 6 * i_0] += V_0[i + 12] * V[i_0 + 12];
      V_1[i + 6 * i_0] += V_0[i + 18] * V[i_0 + 18];
    }
  }

  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      sigma_p[i_0 + 6 * i] = b_a_0[6 * i + i_0] + V_1[6 * i + i_0];
    }
  }

  /* TODO */
  /* '<S4>:1:126' if t_act_sonar >= t_sonar */
  if (rtDW.t_act_sonar >= 0.1) {
    /* '<S4>:1:127' t_act_sonar = 0; */
    rtDW.t_act_sonar = 0.0;

    /*  Correction (preparation) */
    /* '<S4>:1:130' if t_act_gps >= t_gps */
    if (rtDW.t_act_gps >= 0.2) {
      /* '<S4>:1:131' t_act_gps = 0; */
      rtDW.t_act_gps = 0.0;

      /* '<S4>:1:132' z_t = [ measurement(1);  */
      /* '<S4>:1:133'                 measurement(2);  */
      /* '<S4>:1:134'                 -measurement(3);  */
      /* '<S4>:1:135'                 measurement(4) / sqrt(1+tan(phi)^2 + tan(theta)^2)]; */
      rtb_Sum18 = tan(-rtU.measurements.att_x);
      rtb_Sum21 = tan(-rtU.measurements.att_y);
      z_t_idx_0 = rtU.measurements.gps_n;
      z_t_idx_1 = rtU.measurements.gps_e;
      rtb_Sum19 = -rtU.measurements.gps_d;
      rtb_Sum18 = rtU.measurements.sonar_z / sqrt((rtb_Sum18 * rtb_Sum18 + 1.0)
        + rtb_Sum21 * rtb_Sum21);
    } else {
      /* '<S4>:1:136' else */
      /* '<S4>:1:137' z_t = [ x_p(1); */
      /* '<S4>:1:138'                 x_p(2); */
      /* '<S4>:1:139'                 x_p(3); */
      /* '<S4>:1:140'                 measurement(4) / sqrt(1+tan(phi)^2 + tan(theta)^2)]; */
      rtb_Sum18 = tan(-rtU.measurements.att_x);
      rtb_Sum21 = tan(-rtU.measurements.att_y);
      z_t_idx_0 = x_p[0];
      z_t_idx_1 = x_p[1];
      rtb_Sum19 = x_p[2];
      rtb_Sum18 = rtU.measurements.sonar_z / sqrt((rtb_Sum18 * rtb_Sum18 + 1.0)
        + rtb_Sum21 * rtb_Sum21);
    }

    /* '<S4>:1:144' if measurement(4) >= 4.99 || measurement(4) <= 0 */
    if ((rtU.measurements.sonar_z >= 4.99) || (rtU.measurements.sonar_z <= 0.0))
    {
      /* '<S4>:1:145' z_t(4) = x_p(3); */
      rtb_Sum18 = x_p[2];
    }

    /* Predicted Measurement mean */
    /* '<S4>:1:149' h_x = [x_p(1);    %Predicted Measurement mean */
    /* '<S4>:1:150'            x_p(2); */
    /* '<S4>:1:151'            x_p(3); */
    /* '<S4>:1:152'            x_p(3)]; */
    /* '<S4>:1:154' s4_3 = sqrt(1+tan(phi)^2+tan(theta)^2); */
    /* '<S4>:1:155' s4_4 = x_p(3) * 4*tan(phi)/((1+cos(2*phi)) * s4_3); */
    /* '<S4>:1:156' s4_5 = x_p(3) * 4*tan(theta)/((1+cos(2*theta)) * s4_3); */
    /* '<S4>:1:158' H = [ 1 0 0 0 0 0; */
    /* '<S4>:1:159'           0 1 0 0 0 0; */
    /* '<S4>:1:160'           0 0 1 0 0 0; */
    /* '<S4>:1:161'           0 0 1 0 0 0]; */
    /*  Correction */
    /* '<S4>:1:164' K = sigma_p * H' * ( H * sigma_p * H' + R)^(-1); */
    for (i = 0; i < 4; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        V_0[i + (i_0 << 2)] = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          V_0[i + (i_0 << 2)] += (real_T)c_a[(i_1 << 2) + i] * sigma_p[6 * i_0 +
            i_1];
        }
      }

      for (i_0 = 0; i_0 < 4; i_0++) {
        rtb_Sum21 = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          rtb_Sum21 += V_0[(i_1 << 2) + i] * (real_T)b_b[6 * i_0 + i_1];
        }

        c_a_0[i + (i_0 << 2)] = R[(i_0 << 2) + i] + rtb_Sum21;
      }
    }

    invNxN(c_a_0, tmp);
    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 4; i_0++) {
        V_0[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          V_0[i + 6 * i_0] += sigma_p[6 * i_1 + i] * (real_T)b_b[6 * i_0 + i_1];
        }
      }

      for (i_0 = 0; i_0 < 4; i_0++) {
        V[i + 6 * i_0] = 0.0;
        V[i + 6 * i_0] += tmp[i_0 << 2] * V_0[i];
        V[i + 6 * i_0] += tmp[(i_0 << 2) + 1] * V_0[i + 6];
        V[i + 6 * i_0] += tmp[(i_0 << 2) + 2] * V_0[i + 12];
        V[i + 6 * i_0] += tmp[(i_0 << 2) + 3] * V_0[i + 18];
      }
    }

    /* '<S4>:1:165' x = x_p + K * (z_t - h_x); */
    z_t_idx_0 -= x_p[0];
    z_t_idx_1 -= x_p[1];
    rtb_Sum19 -= x_p[2];
    rtb_Sum18 -= x_p[2];
    for (i = 0; i < 6; i++) {
      rtDW.x[i] = (((V[i + 6] * z_t_idx_1 + V[i] * z_t_idx_0) + V[i + 12] *
                    rtb_Sum19) + V[i + 18] * rtb_Sum18) + x_p[i];
    }

    /* '<S4>:1:166' sigma = (eye(6) - K * H) * sigma_p; */
    for (i = 0; i < 36; i++) {
      I[i] = 0;
    }

    for (i = 0; i < 6; i++) {
      I[i + 6 * i] = 1;
    }

    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        b_a_0[i + 6 * i_0] = (real_T)I[6 * i_0 + i] - ((((real_T)c_a[(i_0 << 2)
          + 1] * V[i + 6] + (real_T)c_a[i_0 << 2] * V[i]) + (real_T)c_a[(i_0 <<
          2) + 2] * V[i + 12]) + (real_T)c_a[(i_0 << 2) + 3] * V[i + 18]);
      }

      for (i_0 = 0; i_0 < 6; i_0++) {
        rtDW.sigma[i + 6 * i_0] = 0.0;
        for (i_1 = 0; i_1 < 6; i_1++) {
          rtDW.sigma[i + 6 * i_0] += b_a_0[6 * i_1 + i] * sigma_p[6 * i_0 + i_1];
        }
      }
    }
  } else {
    /* '<S4>:1:168' else */
    /* '<S4>:1:169' x = x_p; */
    for (i = 0; i < 6; i++) {
      rtDW.x[i] = x_p[i];
    }

    /* '<S4>:1:170' sigma = sigma_p; */
    memcpy(&rtDW.sigma[0], &sigma_p[0], 36U * sizeof(real_T));
  }

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  MATLAB Function: '<Root>/PoseEstimator '
   */
  /* '<S4>:1:173' mu = x; */
  /* '<S4>:1:174' sigma_t = sigma; */
  for (i = 0; i < 6; i++) {
    rtDW.Delay_DSTATE[i] = rtDW.x[i];
  }

  /* End of Update for Delay: '<Root>/Delay' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S21>/UD'
     *
     * Block description for '<S21>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.UD_DSTATE[0] = rtDW.RateTransition1[0];
    rtDW.UD_DSTATE[1] = rtDW.RateTransition1[1];
  }

  /* Update for DiscreteIntegrator: '<S22>/Integrator' incorporates:
   *  Gain: '<S22>/Integral Gain'
   */
  rtDW.Integrator_DSTATE[0] += 0.17419354838709677 * rtb_VectorConcatenate1[0] *
    0.004;
  rtDW.Integrator_DSTATE[1] += 0.17419354838709677 * rtb_VectorConcatenate1[1] *
    0.004;

  /* Update for UnitDelay: '<S24>/UD'
   *
   * Block description for '<S24>/UD':
   *
   *  Store in Global RAM
   */
  rtDW.UD_DSTATE_f = rtb_TSamp;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE += rtb_Product;
  }

  rate_scheduler();
}

/* Model initialize function */
void control_system_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    static const real_T tmp[36] = { 1.0E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-8,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-8,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-8
    };

    static const int8_T tmp_0[6] = { 0, 0, 1, 0, 0, 0 };

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    /* '<S3>:1:7' current = 1; */
    rtDW.current = 1.0;

    /* SystemInitialize for MATLAB Function: '<Root>/PoseEstimator ' */
    for (i = 0; i < 6; i++) {
      rtDW.x[i] = tmp_0[i];
    }

    memcpy(&rtDW.sigma[0], &tmp[0], 36U * sizeof(real_T));

    /* '<S4>:1:17' t_act_gps = t_gps; */
    rtDW.t_act_gps = 0.2;

    /* '<S4>:1:20' t_act_sonar = t_sonar; */
    rtDW.t_act_sonar = 0.1;

    /* End of SystemInitialize for MATLAB Function: '<Root>/PoseEstimator ' */
    /* TODO: set start position */
    /* '<S4>:1:43' x = [0; */
    /* '<S4>:1:44'          0; */
    /* '<S4>:1:45'          1; %TODO: set start position */
    /* '<S4>:1:46'          0; */
    /* '<S4>:1:47'          0; */
    /* '<S4>:1:48'          0]; */
    /* '<S4>:1:51' sigma = [1e-8 0    0    0    0    0; */
    /* '<S4>:1:52'              0   1e-8  0    0    0    0; */
    /* '<S4>:1:53'              0    0   1e-8  0    0    0; */
    /* '<S4>:1:54'              0    0    0   1e-8  0    0; */
    /* '<S4>:1:55'              0    0    0    0   1e-8  0; */
    /* '<S4>:1:56'              0    0    0    0    0   1e-8]; */
  }
}

/* Model terminate function */
void control_system_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
