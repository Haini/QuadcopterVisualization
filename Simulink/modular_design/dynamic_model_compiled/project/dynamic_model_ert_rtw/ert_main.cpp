//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_model.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[4];
int taskId[4];
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
pthread_t subRateThread[4];
int subratePriority[4];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 2;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    dynamic_model_step(subRateId);

    // Get model outputs here
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested(rtM);
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    for (i = 1
         ; i <= 4; i++) {
      if (rtmStepTask(rtM, i + 1)
          ) {
        sem_post(&subrateTaskSem[ i - 1
                 ]);
      }
    }

    dynamic_model_step(0);

    // Get model outputs here
    runModel = (rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested(rtM);
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(rtM, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int i;

    // Signal all periodic tasks to complete
    for (i=0; i<4; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    // Wait for all periodic tasks to complete
    for (i=0; i<4; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i],(void *)&threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  // Disable rt_OneStep() here

  // Terminate model
  dynamic_model_terminate();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  subratePriority[0] = 41;
  subratePriority[1] = 42;
  subratePriority[2] = 43;
  subratePriority[3] = 44;
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(rtM, 0);

  // Initialize model
  dynamic_model_initialize();

  // Call RTOS Initialization function
  myRTOSInit(0.001, 4);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
