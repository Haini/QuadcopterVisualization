//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: quadcopter_dynamic_model.cpp
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
#include "quadcopter_dynamic_model.h"
#define quadcopter_dynamic_model_MessageQueueLen (1)

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

rtTimingBridge quadcopter_dynamic_model_TimingBrdg;
const SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray
  quadcopter_dynamic_model_rtZSL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray
  = {
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    // Data

  {
    0U,                                // CurrentLength
    0U                                 // ReceivedLength
  },                                   // Data_SL_Info

  {
    0U,                                // DataOffset

    {
      {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      }, {
        {
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }
        ,                              // Label

        {
          0U,                          // CurrentLength
          0U                           // ReceivedLength
        },                             // Label_SL_Info
        0U,                            // Size
        0U                             // Stride
      } }
    ,                                  // Dim

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Dim_SL_Info
  }                                    // Layout
} ;                                    // SL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray ground 

// Continuous states
X_quadcopter_dynamic_model_T quadcopter_dynamic_model_X;

// Block signals and states (auto storage)
DW_quadcopter_dynamic_model_T quadcopter_dynamic_model_DW;

// Real-time model
RT_MODEL_quadcopter_dynamic_model_T quadcopter_dynamic_model_M_;
RT_MODEL_quadcopter_dynamic_model_T *const quadcopter_dynamic_model_M =
  &quadcopter_dynamic_model_M_;
extern const real_T rtCP_pooled_XHMGDNPS0ktC[9];

#define rtCP_GainKu_Gain               rtCP_pooled_XHMGDNPS0ktC  // Expression: [0 1 0; 0 0 -1; -1 0 0]
                                                                 //  Referenced by: '<S6>/Gain K*u'

#define rtCP_GainKu_Gain_h             rtCP_pooled_XHMGDNPS0ktC  // Expression: [0 1 0; 0 0 -1; -1 0 0]
                                                                 //  Referenced by: '<S12>/Gain K*u'


extern void quadcopter_dynamic_model_step0(void);
extern void quadcopter_dynamic_model_step2(void);
extern void quadcopter_dynamic_model_step3(void);
extern void quadcopter_dynamic_model_step4(void);
extern void quadcopter_dynamic_model_step5(void);
extern void quadcopter_dynamic_model_step6(void);// private model entry point functions 
extern void quadcopter_dynamic_model_derivatives(void);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void quadcopter_dynamic_model_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[2] = ((boolean_T)rtmStepTask(quadcopter_dynamic_model_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(quadcopter_dynamic_model_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(quadcopter_dynamic_model_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(quadcopter_dynamic_model_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(quadcopter_dynamic_model_M, 6));
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
  quadcopter_dynamic_model_M->Timing.RateInteraction.TID0_2 =
    (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2] == 0);

  // tid 1 shares data with slower tid rates: 2, 5, 6
  if (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[1] == 0) {
    quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_2 =
      (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2] == 0);
    quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_5 =
      (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[5] == 0);
    quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_6 =
      (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[6] == 0);
  }

  // tid 2 shares data with slower tid rates: 5, 6
  if (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2] == 0) {
    quadcopter_dynamic_model_M->Timing.RateInteraction.TID2_5 =
      (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[5] == 0);
    quadcopter_dynamic_model_M->Timing.RateInteraction.TID2_6 =
      (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[6] == 0);
  }

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2])++;
  if ((quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2]) > 3) {// Sample time: [0.004s, 0.0s] 
    quadcopter_dynamic_model_M->Timing.TaskCounters.TID[2] = 0;
  }

  (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[3])++;
  if ((quadcopter_dynamic_model_M->Timing.TaskCounters.TID[3]) > 7) {// Sample time: [0.008s, 0.0s] 
    quadcopter_dynamic_model_M->Timing.TaskCounters.TID[3] = 0;
  }

  (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[4])++;
  if ((quadcopter_dynamic_model_M->Timing.TaskCounters.TID[4]) > 29) {// Sample time: [0.03s, 0.0s] 
    quadcopter_dynamic_model_M->Timing.TaskCounters.TID[4] = 0;
  }

  (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[5])++;
  if ((quadcopter_dynamic_model_M->Timing.TaskCounters.TID[5]) > 99) {// Sample time: [0.1s, 0.0s] 
    quadcopter_dynamic_model_M->Timing.TaskCounters.TID[5] = 0;
  }

  (quadcopter_dynamic_model_M->Timing.TaskCounters.TID[6])++;
  if ((quadcopter_dynamic_model_M->Timing.TaskCounters.TID[6]) > 199) {// Sample time: [0.2s, 0.0s] 
    quadcopter_dynamic_model_M->Timing.TaskCounters.TID[6] = 0;
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
  quadcopter_dynamic_model_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  quadcopter_dynamic_model_step0();
  quadcopter_dynamic_model_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  quadcopter_dynamic_model_step0();
  quadcopter_dynamic_model_derivatives();

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

// Model step function for TID0
void quadcopter_dynamic_model_step0(void) // Sample time: [0.0s, 0.0s]
{
  if (rtmIsMajorTimeStep(quadcopter_dynamic_model_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&quadcopter_dynamic_model_M->solverInfo,
                          ((quadcopter_dynamic_model_M->Timing.clockTick0+1)*
      quadcopter_dynamic_model_M->Timing.stepSize0));

    {                                  // Sample time: [0.0s, 0.0s]
      rate_monotonic_scheduler();
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(quadcopter_dynamic_model_M)) {
    quadcopter_dynamic_model_M->Timing.t[0] = rtsiGetT
      (&quadcopter_dynamic_model_M->solverInfo);
  }

  // ModelReference: '<Root>/dynamic_model'
  dynamic_modelTID0(&quadcopter_dynamic_model_DW.dynamic_model_o15[0],
                    &quadcopter_dynamic_model_DW.dynamic_model_o16[0],
                    &(quadcopter_dynamic_model_X.dynamic_model_CSTATE[0]));
  if (rtmIsMajorTimeStep(quadcopter_dynamic_model_M)) {
    // ModelReference: '<Root>/dynamic_model'
    dynamic_modelTID1();
  }

  if (rtmIsMajorTimeStep(quadcopter_dynamic_model_M)) {
    dynamic_model_UpdateTID0();
    if (rtmIsMajorTimeStep(quadcopter_dynamic_model_M)) {
      dynamic_model_UpdateTID1();
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(quadcopter_dynamic_model_M)) {
    rt_ertODEUpdateContinuousStates(&quadcopter_dynamic_model_M->solverInfo);

    // Update absolute time
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++quadcopter_dynamic_model_M->Timing.clockTick0;
    quadcopter_dynamic_model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&quadcopter_dynamic_model_M->solverInfo);

    // Update absolute time
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.001, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    quadcopter_dynamic_model_M->Timing.clockTick1++;
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void quadcopter_dynamic_model_derivatives(void)
{
  // Derivatives for ModelReference: '<Root>/dynamic_model'
  dynamic_model_Deriv(&(((XDot_quadcopter_dynamic_model_T *)
    quadcopter_dynamic_model_M->derivs)->dynamic_model_CSTATE[0]));
}

// Model step function for TID2
void quadcopter_dynamic_model_step2(void) // Sample time: [0.004s, 0.0s]
{
  boolean_T varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S20>/In1'
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_quadcopter_dynamic_model_7067.getLatestMessage
    (&quadcopter_dynamic_model_DW.BusAssignment);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (varargout_1) {
    quadcopter_dynamic_model_DW.In1 = quadcopter_dynamic_model_DW.BusAssignment;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  quadcopter_dynamic_model_DW.DataTypeConversion1[0] =
    quadcopter_dynamic_model_DW.In1.Data[0];
  quadcopter_dynamic_model_DW.DataTypeConversion1[1] =
    quadcopter_dynamic_model_DW.In1.Data[1];
  quadcopter_dynamic_model_DW.DataTypeConversion1[2] =
    quadcopter_dynamic_model_DW.In1.Data[2];
  quadcopter_dynamic_model_DW.DataTypeConversion1[3] =
    quadcopter_dynamic_model_DW.In1.Data[3];

  // ModelReference: '<Root>/dynamic_model'
  dynamic_modelTID2(&quadcopter_dynamic_model_DW.DataTypeConversion1[0],
                    &quadcopter_dynamic_model_DW.DataTypeConversion1[1],
                    &quadcopter_dynamic_model_DW.DataTypeConversion1[2],
                    &quadcopter_dynamic_model_DW.DataTypeConversion1[3],
                    &quadcopter_dynamic_model_DW.acc_x,
                    &quadcopter_dynamic_model_DW.acc_y,
                    &quadcopter_dynamic_model_DW.acc_z,
                    &quadcopter_dynamic_model_DW.gyro_x,
                    &quadcopter_dynamic_model_DW.gyro_y,
                    &quadcopter_dynamic_model_DW.gyro_z,
                    &quadcopter_dynamic_model_DW.att_x,
                    &quadcopter_dynamic_model_DW.att_y,
                    &quadcopter_dynamic_model_DW.att_z,
                    &quadcopter_dynamic_model_DW.gps_n,
                    &quadcopter_dynamic_model_DW.gps_e,
                    &quadcopter_dynamic_model_DW.gps_d,
                    &quadcopter_dynamic_model_DW.sonar_z,
                    &quadcopter_dynamic_model_DW.bat_volt);

  // SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[0] =
    quadcopter_dynamic_model_DW.acc_x;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[1] =
    quadcopter_dynamic_model_DW.acc_y;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[2] =
    quadcopter_dynamic_model_DW.acc_z;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[3] =
    quadcopter_dynamic_model_DW.gyro_x;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[4] =
    quadcopter_dynamic_model_DW.gyro_y;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[5] =
    quadcopter_dynamic_model_DW.gyro_z;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[6] =
    quadcopter_dynamic_model_DW.att_x;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[7] =
    quadcopter_dynamic_model_DW.att_y;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[8] =
    quadcopter_dynamic_model_DW.att_z;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[9] =
    quadcopter_dynamic_model_DW.gps_n;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[10] =
    quadcopter_dynamic_model_DW.gps_e;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[11] =
    quadcopter_dynamic_model_DW.gps_d;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[12] =
    quadcopter_dynamic_model_DW.sonar_z;
  quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[13] =
    quadcopter_dynamic_model_DW.bat_volt;

  // MATLAB Function: '<Root>/MATLAB Function'
  // MATLAB Function 'MATLAB Function': '<S2>:1'
  // '<S2>:1:4' y = zeros(1,128);
  memset(&quadcopter_dynamic_model_DW.y[0], 0, sizeof(real_T) << 7U);

  // '<S2>:1:5' for i = 1:14
  // '<S2>:1:6' y(i) = u(i);
  memcpy(&quadcopter_dynamic_model_DW.y[0],
         &quadcopter_dynamic_model_DW.TmpSignalConversionAtSFunctionInport1[0],
         14U * sizeof(real_T));

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S1>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  quadcopter_dynamic_model_DW.BusAssignment =
    quadcopter_dynamic_model_rtZSL_Bus_quadcopter_dynamic_model_std_msgs_Float32MultiArray;
  quadcopter_dynamic_model_DW.BusAssignment.Data_SL_Info.CurrentLength = 14U;
  for (quadcopter_dynamic_model_DW.i = 0; quadcopter_dynamic_model_DW.i < 128;
       quadcopter_dynamic_model_DW.i++) {
    quadcopter_dynamic_model_DW.BusAssignment.Data[quadcopter_dynamic_model_DW.i]
      = (real32_T)quadcopter_dynamic_model_DW.y[quadcopter_dynamic_model_DW.i];
  }

  // End of BusAssignment: '<Root>/Bus Assignment'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   MATLABSystem: '<S3>/SinkBlock'

  Pub_quadcopter_dynamic_model_7058.publish
    (&quadcopter_dynamic_model_DW.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  dynamic_model_UpdateTID2();

  // Update absolute time
  // The "clockTick2" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.004, which is the step size
  //  of the task. Size of "clockTick2" ensures timer will not overflow during the
  //  application lifespan selected.

  quadcopter_dynamic_model_M->Timing.clockTick2++;
}

// Model step function for TID3
void quadcopter_dynamic_model_step3(void) // Sample time: [0.008s, 0.0s]
{
  // ModelReference: '<Root>/dynamic_model'
  dynamic_modelTID3();
  dynamic_model_UpdateTID3();

  // Update absolute time
  // The "clockTick3" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.008, which is the step size
  //  of the task. Size of "clockTick3" ensures timer will not overflow during the
  //  application lifespan selected.

  quadcopter_dynamic_model_M->Timing.clockTick3++;
}

// Model step function for TID4
void quadcopter_dynamic_model_step4(void) // Sample time: [0.03s, 0.0s]
{
  real_T rtb_TrigonometricFunction1;
  real_T rtb_Switch1;
  int32_T i;
  real_T rtb_MathFunction_idx_0;
  real_T rtb_MathFunction_idx_1;
  real_T rtb_MathFunction_idx_2;
  real_T rtb_MathFunction_idx_3;

  // Gain: '<S6>/Gain K*u'
  for (i = 0; i < 3; i++) {
    quadcopter_dynamic_model_DW.Switch3[i] = rtCP_GainKu_Gain[i + 6] *
      quadcopter_dynamic_model_DW.dynamic_model_o15[2] + (rtCP_GainKu_Gain[i + 3]
      * quadcopter_dynamic_model_DW.dynamic_model_o15[1] + rtCP_GainKu_Gain[i] *
      quadcopter_dynamic_model_DW.dynamic_model_o15[0]);
  }

  // End of Gain: '<S6>/Gain K*u'

  // BusAssignment: '<S4>/Bus Assignment'
  quadcopter_dynamic_model_DW.BusAssignment_a.X =
    quadcopter_dynamic_model_DW.Switch3[0];
  quadcopter_dynamic_model_DW.BusAssignment_a.Y =
    quadcopter_dynamic_model_DW.Switch3[2];
  quadcopter_dynamic_model_DW.BusAssignment_a.Z =
    quadcopter_dynamic_model_DW.Switch3[1];

  // Outputs for Atomic SubSystem: '<S4>/position'
  // Start for MATLABSystem: '<S11>/SinkBlock' incorporates:
  //   MATLABSystem: '<S11>/SinkBlock'

  Pub_quadcopter_dynamic_model_6994.publish
    (&quadcopter_dynamic_model_DW.BusAssignment_a);

  // End of Outputs for SubSystem: '<S4>/position'

  // Switch: '<S13>/Switch' incorporates:
  //   Constant: '<S14>/Constant'
  //   Math: '<S17>/Math Function'
  //   RelationalOperator: '<S14>/Compare'
  //   Sqrt: '<S17>/Sqrt'
  //   Sum: '<S17>/Sum of Elements'

  if (sqrt(((quadcopter_dynamic_model_DW.dynamic_model_o16[0] *
             quadcopter_dynamic_model_DW.dynamic_model_o16[0] +
             quadcopter_dynamic_model_DW.dynamic_model_o16[1] *
             quadcopter_dynamic_model_DW.dynamic_model_o16[1]) +
            quadcopter_dynamic_model_DW.dynamic_model_o16[2] *
            quadcopter_dynamic_model_DW.dynamic_model_o16[2]) +
           quadcopter_dynamic_model_DW.dynamic_model_o16[3] *
           quadcopter_dynamic_model_DW.dynamic_model_o16[3]) != 1.0) {
    // Sqrt: '<S19>/Sqrt' incorporates:
    //   Math: '<S19>/Math Function'
    //   Sum: '<S19>/Sum of Elements'

    rtb_Switch1 = sqrt(((quadcopter_dynamic_model_DW.dynamic_model_o16[0] *
                         quadcopter_dynamic_model_DW.dynamic_model_o16[0] +
                         quadcopter_dynamic_model_DW.dynamic_model_o16[1] *
                         quadcopter_dynamic_model_DW.dynamic_model_o16[1]) +
                        quadcopter_dynamic_model_DW.dynamic_model_o16[2] *
                        quadcopter_dynamic_model_DW.dynamic_model_o16[2]) +
                       quadcopter_dynamic_model_DW.dynamic_model_o16[3] *
                       quadcopter_dynamic_model_DW.dynamic_model_o16[3]);

    // Switch: '<S16>/Switch' incorporates:
    //   Product: '<S16>/Divide'

    if (rtb_Switch1 != 0.0) {
      rtb_MathFunction_idx_0 = quadcopter_dynamic_model_DW.dynamic_model_o16[0] /
        rtb_Switch1;
      rtb_MathFunction_idx_1 = quadcopter_dynamic_model_DW.dynamic_model_o16[1] /
        rtb_Switch1;
      rtb_MathFunction_idx_2 = quadcopter_dynamic_model_DW.dynamic_model_o16[2] /
        rtb_Switch1;
      rtb_MathFunction_idx_3 = quadcopter_dynamic_model_DW.dynamic_model_o16[3] /
        rtb_Switch1;
    } else {
      rtb_MathFunction_idx_0 = 1.0;
      rtb_MathFunction_idx_1 = 0.0;
      rtb_MathFunction_idx_2 = 0.0;
      rtb_MathFunction_idx_3 = 0.0;
    }

    // End of Switch: '<S16>/Switch'
  } else {
    rtb_MathFunction_idx_0 = quadcopter_dynamic_model_DW.dynamic_model_o16[0];
    rtb_MathFunction_idx_1 = quadcopter_dynamic_model_DW.dynamic_model_o16[1];
    rtb_MathFunction_idx_2 = quadcopter_dynamic_model_DW.dynamic_model_o16[2];
    rtb_MathFunction_idx_3 = quadcopter_dynamic_model_DW.dynamic_model_o16[3];
  }

  // End of Switch: '<S13>/Switch'

  // Trigonometry: '<S13>/Trigonometric Function'
  if (rtb_MathFunction_idx_0 > 1.0) {
    rtb_MathFunction_idx_0 = 1.0;
  } else {
    if (rtb_MathFunction_idx_0 < -1.0) {
      rtb_MathFunction_idx_0 = -1.0;
    }
  }

  rtb_MathFunction_idx_0 = acos(rtb_MathFunction_idx_0);

  // End of Trigonometry: '<S13>/Trigonometric Function'

  // Math: '<S13>/Remainder' incorporates:
  //   Constant: '<S13>/Constant'

  rtb_Switch1 = rt_modd_snf(rtb_MathFunction_idx_0, 3.1415926535897931);

  // Switch: '<S13>/Switch2'
  if (rtb_Switch1 != 0.0) {
    // Trigonometry: '<S13>/Trigonometric Function1'
    rtb_TrigonometricFunction1 = sin(rtb_MathFunction_idx_0);

    // Switch: '<S13>/Switch3' incorporates:
    //   Product: '<S13>/Divide'

    if (rtb_TrigonometricFunction1 != 0.0) {
      quadcopter_dynamic_model_DW.Switch3[0] = rtb_MathFunction_idx_1 /
        rtb_TrigonometricFunction1;
      quadcopter_dynamic_model_DW.Switch3[1] = rtb_MathFunction_idx_2 /
        rtb_TrigonometricFunction1;
      quadcopter_dynamic_model_DW.Switch3[2] = rtb_MathFunction_idx_3 /
        rtb_TrigonometricFunction1;
    } else {
      quadcopter_dynamic_model_DW.Switch3[0] = rtb_MathFunction_idx_1;
      quadcopter_dynamic_model_DW.Switch3[1] = rtb_MathFunction_idx_2;
      quadcopter_dynamic_model_DW.Switch3[2] = rtb_MathFunction_idx_3;
    }

    // End of Switch: '<S13>/Switch3'
  } else {
    quadcopter_dynamic_model_DW.Switch3[0] = 1.0;
    quadcopter_dynamic_model_DW.Switch3[1] = 0.0;
    quadcopter_dynamic_model_DW.Switch3[2] = 0.0;
  }

  // End of Switch: '<S13>/Switch2'

  // Gain: '<S12>/Gain K*u'
  for (i = 0; i < 3; i++) {
    quadcopter_dynamic_model_DW.GainKu[i] = rtCP_GainKu_Gain_h[i + 6] *
      quadcopter_dynamic_model_DW.Switch3[2] + (rtCP_GainKu_Gain_h[i + 3] *
      quadcopter_dynamic_model_DW.Switch3[1] + rtCP_GainKu_Gain_h[i] *
      quadcopter_dynamic_model_DW.Switch3[0]);
  }

  // End of Gain: '<S12>/Gain K*u'

  // Switch: '<S13>/Switch1' incorporates:
  //   Constant: '<S13>/Constant1'
  //   Gain: '<S13>/Gain'

  if (rtb_Switch1 != 0.0) {
    rtb_Switch1 = 2.0 * rtb_MathFunction_idx_0;
  } else {
    rtb_Switch1 = 0.0;
  }

  // End of Switch: '<S13>/Switch1'

  // BusAssignment: '<S4>/Bus Assignment1'
  quadcopter_dynamic_model_DW.BusAssignment1.X =
    quadcopter_dynamic_model_DW.GainKu[0];
  quadcopter_dynamic_model_DW.BusAssignment1.Y =
    quadcopter_dynamic_model_DW.GainKu[1];
  quadcopter_dynamic_model_DW.BusAssignment1.Z =
    quadcopter_dynamic_model_DW.GainKu[2];
  quadcopter_dynamic_model_DW.BusAssignment1.W = rtb_Switch1;

  // Outputs for Atomic SubSystem: '<S4>/attitude'
  // Start for MATLABSystem: '<S10>/SinkBlock' incorporates:
  //   MATLABSystem: '<S10>/SinkBlock'

  Pub_quadcopter_dynamic_model_6939.publish
    (&quadcopter_dynamic_model_DW.BusAssignment1);

  // End of Outputs for SubSystem: '<S4>/attitude'
}

// Model step function for TID5
void quadcopter_dynamic_model_step5(void) // Sample time: [0.1s, 0.0s]
{
  // ModelReference: '<Root>/dynamic_model'
  dynamic_modelTID4();
  dynamic_model_UpdateTID4();

  // Update absolute time
  // The "clockTick5" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.1, which is the step size
  //  of the task. Size of "clockTick5" ensures timer will not overflow during the
  //  application lifespan selected.

  quadcopter_dynamic_model_M->Timing.clockTick5++;
}

// Model step function for TID6
void quadcopter_dynamic_model_step6(void) // Sample time: [0.2s, 0.0s]
{
  // ModelReference: '<Root>/dynamic_model'
  dynamic_modelTID5();
  dynamic_model_UpdateTID5();

  // Update absolute time
  // The "clockTick6" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.2, which is the step size
  //  of the task. Size of "clockTick6" ensures timer will not overflow during the
  //  application lifespan selected.

  quadcopter_dynamic_model_M->Timing.clockTick6++;
}

// Model step wrapper function for compatibility with a static main program
void quadcopter_dynamic_model_step(int_T tid)
{
  switch (tid) {
   case 0 :
    quadcopter_dynamic_model_step0();
    break;

   case 2 :
    quadcopter_dynamic_model_step2();
    break;

   case 3 :
    quadcopter_dynamic_model_step3();
    break;

   case 4 :
    quadcopter_dynamic_model_step4();
    break;

   case 5 :
    quadcopter_dynamic_model_step5();
    break;

   case 6 :
    quadcopter_dynamic_model_step6();
    break;

   default :
    break;
  }
}

// Model initialize function
void quadcopter_dynamic_model_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&quadcopter_dynamic_model_M->solverInfo,
                          &quadcopter_dynamic_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&quadcopter_dynamic_model_M->solverInfo, &rtmGetTPtr
                (quadcopter_dynamic_model_M));
    rtsiSetStepSizePtr(&quadcopter_dynamic_model_M->solverInfo,
                       &quadcopter_dynamic_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&quadcopter_dynamic_model_M->solverInfo,
                 &quadcopter_dynamic_model_M->derivs);
    rtsiSetContStatesPtr(&quadcopter_dynamic_model_M->solverInfo, (real_T **)
                         &quadcopter_dynamic_model_M->contStates);
    rtsiSetNumContStatesPtr(&quadcopter_dynamic_model_M->solverInfo,
      &quadcopter_dynamic_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&quadcopter_dynamic_model_M->solverInfo,
      &quadcopter_dynamic_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&quadcopter_dynamic_model_M->solverInfo,
      &quadcopter_dynamic_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&quadcopter_dynamic_model_M->solverInfo,
      &quadcopter_dynamic_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&quadcopter_dynamic_model_M->solverInfo,
                          (&rtmGetErrorStatus(quadcopter_dynamic_model_M)));
    rtsiSetRTModelPtr(&quadcopter_dynamic_model_M->solverInfo,
                      quadcopter_dynamic_model_M);
  }

  rtsiSetSimTimeStep(&quadcopter_dynamic_model_M->solverInfo, MAJOR_TIME_STEP);
  quadcopter_dynamic_model_M->intgData.y = quadcopter_dynamic_model_M->odeY;
  quadcopter_dynamic_model_M->intgData.f[0] = quadcopter_dynamic_model_M->odeF[0];
  quadcopter_dynamic_model_M->intgData.f[1] = quadcopter_dynamic_model_M->odeF[1];
  quadcopter_dynamic_model_M->intgData.f[2] = quadcopter_dynamic_model_M->odeF[2];
  quadcopter_dynamic_model_M->contStates = ((X_quadcopter_dynamic_model_T *)
    &quadcopter_dynamic_model_X);
  rtsiSetSolverData(&quadcopter_dynamic_model_M->solverInfo, (void *)
                    &quadcopter_dynamic_model_M->intgData);
  rtsiSetSolverName(&quadcopter_dynamic_model_M->solverInfo,"ode3");
  rtmSetTPtr(quadcopter_dynamic_model_M,
             &quadcopter_dynamic_model_M->Timing.tArray[0]);
  quadcopter_dynamic_model_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(quadcopter_dynamic_model_M, 1);

  {
    static uint32_T *clockTickPtrs[7];
    static real_T *taskTimePtrs[7];
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(7 * 7)];
    quadcopter_dynamic_model_TimingBrdg.nTasks = 7;
    clockTickPtrs[0] = &(quadcopter_dynamic_model_M->Timing.clockTick0);
    clockTickPtrs[1] = &(quadcopter_dynamic_model_M->Timing.clockTick1);
    clockTickPtrs[2] = &(quadcopter_dynamic_model_M->Timing.clockTick2);
    clockTickPtrs[3] = &(quadcopter_dynamic_model_M->Timing.clockTick3);
    clockTickPtrs[4] = (NULL);
    clockTickPtrs[5] = &(quadcopter_dynamic_model_M->Timing.clockTick5);
    clockTickPtrs[6] = &(quadcopter_dynamic_model_M->Timing.clockTick6);
    quadcopter_dynamic_model_TimingBrdg.clockTick = clockTickPtrs;
    quadcopter_dynamic_model_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(quadcopter_dynamic_model_M->Timing.TaskCounters.TID[0]);
    quadcopter_dynamic_model_TimingBrdg.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*7 + 2] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID0_2);
    rateTransitionPtrs[1*7 + 2] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_2);
    rateTransitionPtrs[1*7 + 5] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_5);
    rateTransitionPtrs[1*7 + 6] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID1_6);
    rateTransitionPtrs[2*7 + 5] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID2_5);
    rateTransitionPtrs[2*7 + 6] =
      &(quadcopter_dynamic_model_M->Timing.RateInteraction.TID2_6);
    quadcopter_dynamic_model_TimingBrdg.rateTransition = rateTransitionPtrs;
    taskTimePtrs[0] = &(quadcopter_dynamic_model_M->Timing.t[0]);
    taskTimePtrs[1] = (NULL);
    taskTimePtrs[2] = (NULL);
    taskTimePtrs[3] = (NULL);
    taskTimePtrs[4] = (NULL);
    taskTimePtrs[5] = (NULL);
    taskTimePtrs[6] = (NULL);
    quadcopter_dynamic_model_TimingBrdg.taskTime = taskTimePtrs;
    quadcopter_dynamic_model_TimingBrdg.firstInitCond = &rtmIsFirstInitCond
      (quadcopter_dynamic_model_M);
  }

  // Model Initialize fcn for ModelReference Block: '<Root>/dynamic_model'
  dynamic_model_initialize(rtmGetErrorStatusPointer(quadcopter_dynamic_model_M),
    rtmGetStopRequestedPtr(quadcopter_dynamic_model_M),
    &(quadcopter_dynamic_model_M->solverInfo),
    &quadcopter_dynamic_model_TimingBrdg, 0, 1, 2, 3, 5, 6);

  {
    static const char_T tmp[11] = { '/', 'a', 't', 't', 'i', 't', 'u', 'd', 'e',
      '_', 'O' };

    static const char_T tmp_0[11] = { '/', 'p', 'o', 's', 'i', 't', 'i', 'o',
      'n', '_', 'O' };

    static const char_T tmp_1[22] = { '/', 'd', 'y', 'n', '_', 'm', 'o', 'd',
      'e', 'l', '_', 'm', 'e', 'a', 's', 'u', 'r', 'm', 'e', 'n', 't', 's' };

    static const char_T tmp_2[19] = { '/', 'c', 'o', 'n', 't', 'r', 'o', 'l',
      '_', 's', 'y', 's', 't', 'e', 'm', '_', 'p', 'w', 'm' };

    char_T tmp_3[12];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    quadcopter_dynamic_model_DW.obj_g.isInitialized = 0;
    quadcopter_dynamic_model_DW.objisempty = true;
    quadcopter_dynamic_model_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 19; i++) {
      quadcopter_dynamic_model_DW.cv1[i] = tmp_2[i];
    }

    quadcopter_dynamic_model_DW.cv1[19] = '\x00';
    Sub_quadcopter_dynamic_model_7067.createSubscriber
      (quadcopter_dynamic_model_DW.cv1, quadcopter_dynamic_model_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'
    // Start for ModelReference: '<Root>/dynamic_model'
    dynamic_model_Start();

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    quadcopter_dynamic_model_DW.obj_n.isInitialized = 0;
    quadcopter_dynamic_model_DW.objisempty_a = true;
    quadcopter_dynamic_model_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 22; i++) {
      quadcopter_dynamic_model_DW.cv0[i] = tmp_1[i];
    }

    quadcopter_dynamic_model_DW.cv0[22] = '\x00';
    Pub_quadcopter_dynamic_model_7058.createPublisher
      (quadcopter_dynamic_model_DW.cv0, quadcopter_dynamic_model_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<S4>/position'
    // Start for MATLABSystem: '<S11>/SinkBlock'
    quadcopter_dynamic_model_DW.obj.isInitialized = 0;
    quadcopter_dynamic_model_DW.objisempty_m = true;
    quadcopter_dynamic_model_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[11] = '\x00';
    Pub_quadcopter_dynamic_model_6994.createPublisher(tmp_3,
      quadcopter_dynamic_model_MessageQueueLen);

    // End of Start for MATLABSystem: '<S11>/SinkBlock'
    // End of Start for SubSystem: '<S4>/position'

    // Start for Atomic SubSystem: '<S4>/attitude'
    // Start for MATLABSystem: '<S10>/SinkBlock'
    quadcopter_dynamic_model_DW.obj_h.isInitialized = 0;
    quadcopter_dynamic_model_DW.objisempty_g = true;
    quadcopter_dynamic_model_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp[i];
    }

    tmp_3[11] = '\x00';
    Pub_quadcopter_dynamic_model_6939.createPublisher(tmp_3,
      quadcopter_dynamic_model_MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SinkBlock'
    // End of Start for SubSystem: '<S4>/attitude'

    // SystemInitialize for ModelReference: '<Root>/dynamic_model'
    dynamic_model_Init(&quadcopter_dynamic_model_DW.dynamic_model_o16[0],
                       &(quadcopter_dynamic_model_X.dynamic_model_CSTATE[0]));
  }

  // set "at time zero" to false
  if (rtmIsFirstInitCond(quadcopter_dynamic_model_M)) {
    rtmSetFirstInitCond(quadcopter_dynamic_model_M, 0);
  }
}

// Model terminate function
void quadcopter_dynamic_model_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (quadcopter_dynamic_model_DW.obj_g.isInitialized == 1) {
    quadcopter_dynamic_model_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (quadcopter_dynamic_model_DW.obj_n.isInitialized == 1) {
    quadcopter_dynamic_model_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<S4>/position'
  // Start for MATLABSystem: '<S11>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S11>/SinkBlock'

  if (quadcopter_dynamic_model_DW.obj.isInitialized == 1) {
    quadcopter_dynamic_model_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S11>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/position'

  // Terminate for Atomic SubSystem: '<S4>/attitude'
  // Start for MATLABSystem: '<S10>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SinkBlock'

  if (quadcopter_dynamic_model_DW.obj_h.isInitialized == 1) {
    quadcopter_dynamic_model_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<S4>/attitude'
}

//
// File trailer for generated code.
//
// [EOF]
//
