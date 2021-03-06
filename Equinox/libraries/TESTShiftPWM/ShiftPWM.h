/*

*/

#ifndef CShiftPWM_h
#define CShiftPWM_h

#include "lpc_types.h"

void TIMER0_IRQHandler(void);
void LatchIn(void);
void WaitForSend(void);
void DMA_IRQHandler (void);
void LED_init();
void LED_test();
void SetRGB(int32_t group, uint8_t v0, uint8_t v1, uint8_t v2);
void SetLED(int32_t led, uint8_t v0);
void resetLeds(void);
void calulateLEDMIBAMBits();


#endif
