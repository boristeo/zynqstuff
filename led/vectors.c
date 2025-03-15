/******************************************************************************
* Copyright (c) 2009 - 2021 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
* @file vectors.c
*
* This file contains the C level vectors for the ARM Cortex A9 core.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- ---------------------------------------------------
* 1.00a ecm  10/20/09 Initial version, moved over from bsp area
* 6.0   mus  27/07/16 Consolidated vectors for a53,a9 and r5 processor
*                     and added UndefinedException for a53 32 bit and r5
*                     processor
* 8.0	sk   03/02/22 Move XExc_VectorTableEntry structure to xil_exception.h
* 		      header file to fix misra_c_2012_rule_5_6 violation.
* 8.0	sk   03/02/22 Move XExc_VectorTableEntry declaration to xil_exception.h
* 		      header file to fix misra_c_2012_rule_8_4 violation.
* </pre>
*
******************************************************************************/
/***************************** Include Files *********************************/

#include <stdint.h>
#define NULL 0

//#include "xil_exception.h"
#include "vectors.h"

#define XIL_EXCEPTION_ID_RESET					0U
#define XIL_EXCEPTION_ID_UNDEFINED_INT			1U
#define XIL_EXCEPTION_ID_SWI_INT				2U
#define XIL_EXCEPTION_ID_PREFETCH_ABORT_INT		3U
#define XIL_EXCEPTION_ID_DATA_ABORT_INT			4U
#define XIL_EXCEPTION_ID_IRQ_INT				5U
#define XIL_EXCEPTION_ID_FIQ_INT				6U
#define XIL_EXCEPTION_ID_LAST					6U
typedef void (*Xil_ExceptionHandler)(void *data);
typedef void (*Xil_InterruptHandler)(void *data);

static void Xil_ExceptionNullHandler(void *Data)
{
  (void) Data;
DieLoop: goto DieLoop;
}
// These are fake
void Xil_UndefinedExceptionHandler(void*p) {Xil_ExceptionNullHandler(p);}
void Xil_PrefetchAbortHandler(void*p) {Xil_ExceptionNullHandler(p);}
void Xil_DataAbortHandler(void*p) {Xil_ExceptionNullHandler(p);}

typedef struct {
        Xil_ExceptionHandler Handler;
        void *Data;
} XExc_VectorTableEntry;

XExc_VectorTableEntry XExc_VectorTable[XIL_EXCEPTION_ID_LAST + 1] =
{
  {Xil_ExceptionNullHandler, NULL},
  {Xil_UndefinedExceptionHandler, NULL},
  {Xil_ExceptionNullHandler, NULL},
  {Xil_PrefetchAbortHandler, NULL},
  {Xil_DataAbortHandler, NULL},
  {Xil_ExceptionNullHandler, NULL},
  {Xil_ExceptionNullHandler, NULL},
};


uint32_t DataAbortAddr;       /* Address of instruction causing data abort */
uint32_t PrefetchAbortAddr;   /* Address of instruction causing prefetch abort */
uint32_t UndefinedExceptionAddr;   /* Address of instruction causing Undefined
                   exception */


/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Variable Definitions *****************************/

/************************** Function Prototypes ******************************/


/*****************************************************************************/
/**
*
* This is the C level wrapper for the FIQ interrupt called from the vectors.s
* file.
*
* @return	None.
*
******************************************************************************/
void FIQInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_FIQ_INT].Handler(XExc_VectorTable[
					XIL_EXCEPTION_ID_FIQ_INT].Data);
}

/*****************************************************************************/
/**
*
* This is the C level wrapper for the IRQ interrupt called from the vectors.s
* file.
*
* @return	None.
*
******************************************************************************/
void IRQInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_IRQ_INT].Handler(XExc_VectorTable[
					XIL_EXCEPTION_ID_IRQ_INT].Data);
}

#if !defined (__aarch64__)
/*****************************************************************************/
/**
*
* This is the C level wrapper for the Undefined exception called from the
* vectors.s file.
*
* @return	None.
*
******************************************************************************/
void UndefinedException(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_UNDEFINED_INT].Handler(XExc_VectorTable[
					XIL_EXCEPTION_ID_UNDEFINED_INT].Data);
}

/*****************************************************************************/
/**
*
* This is the C level wrapper for the SW Interrupt called from the vectors.s
* file.
*
* @return	None.
*
******************************************************************************/
void SWInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_SWI_INT].Handler(XExc_VectorTable[
					XIL_EXCEPTION_ID_SWI_INT].Data);
}

/*****************************************************************************/
/**
*
* This is the C level wrapper for the DataAbort Interrupt called from the
* vectors.s file.
*
* @return	None.
*
******************************************************************************/
void DataAbortInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_DATA_ABORT_INT].Handler(
		XExc_VectorTable[XIL_EXCEPTION_ID_DATA_ABORT_INT].Data);
}

/*****************************************************************************/
/**
*
* This is the C level wrapper for the PrefetchAbort Interrupt called from the
* vectors.s file.
*
* @return	None.
*
******************************************************************************/
void PrefetchAbortInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_PREFETCH_ABORT_INT].Handler(
		XExc_VectorTable[XIL_EXCEPTION_ID_PREFETCH_ABORT_INT].Data);
}
#else

/*****************************************************************************/
/**
*
* This is the C level wrapper for the Synchronous Interrupt called from the vectors.s
* file.
*
* @return	None.
*
******************************************************************************/
void SynchronousInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_SYNC_INT].Handler(XExc_VectorTable[
					XIL_EXCEPTION_ID_SYNC_INT].Data);
}

/*****************************************************************************/
/**
*
* This is the C level wrapper for the SError Interrupt called from the
* vectors.s file.
*
* @return	None.
*
******************************************************************************/
void SErrorInterrupt(void)
{
	XExc_VectorTable[XIL_EXCEPTION_ID_SERROR_ABORT_INT].Handler(
		XExc_VectorTable[XIL_EXCEPTION_ID_SERROR_ABORT_INT].Data);
}

#endif
