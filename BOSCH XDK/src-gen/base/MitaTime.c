/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2021-06-29 11:06:59
 */


#include <FreeRTOS.h>
#include <BCDS_Basics.h>
#include <BCDS_CmdProcessor.h>
#include <timers.h>
#include <BCDS_Retcode.h>
#include "MitaTime.h"
#include "MitaExceptions.h"
#include "MitaEvents.h"

static TimerHandle_t timerHandleEvery3Second1;

static void InternalHandleEvery3Second1(TimerHandle_t xTimer)
{
	BCDS_UNUSED(xTimer);
	CmdProcessor_Enqueue(&Mita_EventQueue, HandleEvery3Second1, NULL, 0);
}


Retcode_T SetupTime(void)
{
	
	timerHandleEvery3Second1 = xTimerCreate("timerHandleEvery3Second1", UINT32_C(3000), pdTRUE, NULL, InternalHandleEvery3Second1);
	
	if(timerHandleEvery3Second1 == NULL)
	{
		return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_OUT_OF_RESOURCES);
	}
	
	return NO_EXCEPTION;
}

Retcode_T EnableTime(void)
{
	Retcode_T result = NO_EXCEPTION;

	
	result = EveryHandleEvery3Second1_Enable();
	if(result != NO_EXCEPTION)
	{
		return result;
	}
	
	return NO_EXCEPTION;
}

Retcode_T EveryHandleEvery3Second1_Enable(void)
{
	xTimerStart(timerHandleEvery3Second1, 0);
	
	return NO_EXCEPTION;
}

