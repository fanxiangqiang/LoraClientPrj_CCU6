#include "usart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "DebugLog.h"
#include <stdarg.h>
#include <string.h>

static int inHandlerMode (void) //若在中断中__get_IPSR()返回1，否则返回0
{
   return __get_IPSR();
}
void print_usartLp(char *format, ...)
{
    char buf[64];
    if(inHandlerMode() != 0)
	{
        taskDISABLE_INTERRUPTS();
	}
    else
    {
		while(HAL_UART_GetState(&hlpuart1) == HAL_UART_STATE_BUSY_TX)//若串口忙则挂起此任务
		taskYIELD();
	}
	va_list ap;
	va_start(ap, format);
	vsprintf(buf, format, ap);
	HAL_UART_Transmit(&hlpuart1, (uint8_t *)buf, strlen(buf), 100);
	va_end(ap);
	if(inHandlerMode() != 0)
	taskENABLE_INTERRUPTS();

}
