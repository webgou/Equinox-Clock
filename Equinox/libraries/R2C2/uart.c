/* Copyright (c) 2011 Jorge Pinto - casainho@gmail.com       */
/* All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include "uart.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_pinsel.h"

//Debug UART can be 0 or 3
#define DBG_UART_NUM  0 
#define DBG_UART      LPC_UART0

void uart_init(void)
{
	// UART Configuration structure variable
	UART_CFG_Type UARTConfigStruct;
	// UART FIFO configuration Struct variable
	UART_FIFO_CFG_Type UARTFIFOConfigStruct;
	// Pin configuration for UART
	PINSEL_CFG_Type PinCfg;

	/*
	* Initialize UART3 pin connect: P4.28 -> TXD3; P4.29 -> RXD3
	* or P0.2 -> TXD0, P0.3 -> RXD0
	*/
	PinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;
	PinCfg.Pinmode = PINSEL_PINMODE_PULLUP;
#if DBG_UART_NUM == 3	
	PinCfg.Funcnum = PINSEL_FUNC_3;
	PinCfg.Portnum = 4;
	PinCfg.Pinnum = 28;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 29;
	PINSEL_ConfigPin(&PinCfg);
#else
	PinCfg.Funcnum = PINSEL_FUNC_1;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 2;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 3;
	PINSEL_ConfigPin(&PinCfg);
#endif	

	/* Initialize UART Configuration parameter structure to default state:
		* Baudrate = as below
		* 8 data bit
		* 1 Stop bit
		* None parity
		*/
	UART_ConfigStructInit(&UARTConfigStruct);
	UARTConfigStruct.Baud_rate = 115200;

	// Initialize UART peripheral with given to corresponding parameter
	UART_Init(DBG_UART, &UARTConfigStruct);

	/* Initialize FIFOConfigStruct to default state:
	*                              - FIFO_DMAMode = DISABLE
	*                              - FIFO_Level = UART_FIFO_TRGLEV0
	*                              - FIFO_ResetRxBuf = ENABLE
	*                              - FIFO_ResetTxBuf = ENABLE
	*                              - FIFO_State = ENABLE
	*/
	UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);

	// Initialize FIFO for UART peripheral
	UART_FIFOConfig(DBG_UART, &UARTFIFOConfigStruct);

	// Enable UART Transmit
	UART_TxCmd(DBG_UART, ENABLE);
}

char uart_data_available(void)
{
	return (DBG_UART->LSR & UART_LSR_RDR);
}

char uart_receive(void)
{
	return (UART_ReceiveByte(DBG_UART));
}

void uart_send(char byte)
{
	while ( (DBG_UART->LSR & UART_LSR_THRE) == 0) ;
	UART_SendByte(DBG_UART, byte);
}

void uart_writestr(char *data)
{
	uint8_t i = 0;
	char r;

 	while ((r = data[i++]))
		uart_send(r);
}

void uart_send_32_Hex(char Data){
	if(Data >= 0x10){
		uart_send_32_Hex(Data/0x10);
		uart_send_32_Hex(Data%0x10);
	}
	else{
		if(Data < 0xA){
		UART_SendByte(DBG_UART, Data+'0');
	    }
	    else{
	    	UART_SendByte(DBG_UART, ((Data-0x0A)+'A'));
	    }
	}
}
/*
void uart_send_float(float number){
  uint8_t n = 0;
  uint8_t digits = 10;
  number = 1.5;

  // Handle negative numbers
  if (number < 0.0)
  {
	  uart_writestr("if (number < 0.0)");
     n++;
     uart_send('-');
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  float rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;uart_writestr("for (uint8_t i=0; i<digits; ++i)");

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  float remainder = number - (float)int_part;
  n ++;
  uart_writestr("uart_send(int_part);");
  uart_writestr(int_part);
  uart_writestr("uart_send(int_part);");

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
	n++;
	uart_send(".");
  }

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = (int)remainder;
    n ++;
    uart_send(toPrint);
    remainder -= toPrint;
  }
}
*/

void uart_uint32(uint32_t v) {
	uint8_t t = 0;
	if (v >= 1000000000) {
		for (t = 0; v >= 1000000000; v -= 1000000000, t++);
		uart_send(t + '0');
	}

	if (v >= 100000000) {
		for (t = 0; v >= 100000000; v -= 100000000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 10000000) {
		for (t = 0; v >= 10000000; v -= 10000000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 1000000) {
		for (t = 0; v >= 1000000; v -= 1000000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 100000) {
		for (t = 0; v >= 100000; v -= 100000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 10000) {
		for (t = 0; v >= 10000; v -= 10000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 1000) {
		for (t = 0; v >= 1000; v -= 1000, t++);
		uart_send(t + '0');
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 100) {
		t = v / 100;
		uart_send(t + '0');
		v -= (t * 100);
	}
	else if (t != 0)
		uart_send('0');

	if (v >= 10) {
	        /* 99 > v > 10 */
		t = v / 10;
		uart_send(t + '0');
		v -= (t * 10);
	}
	else if (t != 0)
		uart_send('0');

	uart_send(v + '0');
}

void uart_send_float(double v){
  if (v < 0)
  {
	  uart_send ('-');
    v = -v;
  }

  /* print first part before '.' */
  uart_uint32((uint32_t) v);

  /* print the '.' */
  uart_send('.');

  /* print last part after '.' */
  v = v - (int32_t)v;

  v = v * 1000.0;
  if (v < 100.0)
	  uart_send('0');
  if (v < 10.0)
	  uart_send('0');
  uart_uint32((uint32_t) v);
}
