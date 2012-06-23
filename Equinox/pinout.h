/* Copyright (C) 2009-2010 Michael Moon aka Triffid_Hunter   */
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

#ifndef _PINOUT_H
#define _PINOUT_H

//#include "ios.h"

/*
        LED Pins
*/
/*
//For Equinox clock board
#define LED_LE_PORT			0
#define LED_LE_PIN			16
#define LED_LE_BIT			(1 << LED_CS_PIN)
#define LED_OE_PORT			0
#define LED_OE_PIN			19
#define LED_OE_BIT			(1 << LED_LE_PIN)
#define LED_SCK_PORT     	0
#define LED_SCK_PIN			15
#define LED_SCK_BIT			(1 << LED_SCK_PIN)
#define LED_MISO_PORT		0
#define LED_MISO_PIN		17
#define LED_MISO_BIT		(1 << LED_MISO_PIN)
#define LED_MOSI_PORT		0
#define LED_MOSI_PIN		18
#define LED_MOSI_BIT		(1 << LED_MOSI_PIN)

#define LED_SPI_CHN			0
*/
//For DEV board
#define LED_LE_PORT			0
#define LED_LE_PIN			6
#define LED_LE_BIT			(1 << LED_CS_PIN)
#define LED_OE_PORT			0//not connected but can use
#define LED_OE_PIN			10
#define LED_OE_BIT			(1 << LED_LE_PIN)
#define LED_SCK_PORT     	0
#define LED_SCK_PIN			7
#define LED_SCK_BIT			(1 << LED_SCK_PIN)
#define LED_MISO_PORT		0
#define LED_MISO_PIN		8
#define LED_MISO_BIT		(1 << LED_MISO_PIN)
#define LED_MOSI_PORT		0
#define LED_MOSI_PIN		9
#define LED_MOSI_BIT		(1 << LED_MOSI_PIN)

#define LED_SPI_CHN			0

/*
        Wifi Pins
*/

/*
//For Equinox clock board
#define WF_CS_PORT			0
#define WF_CS_PIN			6
#define WF_CS_BIT			(1 <<  WF_CS_PIN)
#define WF_RESET_PORT		0
#define WF_RESET_PIN		11
#define WF_RESET_BIT		(1 << WF_RESET_PIN)
#define WF_HIBERNATE_PORT	0
#define WF_HIBERNATE_PIN	10
#define WF_HIBERNATE_BIT	(1 << WF_HIBERNATE_PIN)
#define WF_SCK_PORT     	0
#define WF_SCK_PIN			7
#define WF_SCK_BIT			(1 <<  WF_SCK_PIN)
#define WF_MISO_PORT		0
#define WF_MISO_PIN			8
#define WF_MISO_BIT			(1 <<  WF_MISO_PIN)
#define WF_MOSI_PORT		0
#define WF_MOSI_PIN			9
#define WF_MOSI_BIT			(1 <<  WF_MOSI_PIN)
#define WF_EINT0_PORT		2
#define WF_EINT0_PIN		10
#define WF_EINT0_BIT		(1 <<  WF_EINT0_PIN)
#define WF_EINT2_PORT		2
#define WF_EINT2_PIN		12
#define WF_EINT2_BIT		(1 <<  WF_EINT2_PIN)
*/

//For DEV board
#define WF_CS_PORT			0
#define WF_CS_PIN			16
#define WF_CS_BIT			(1 << WF_CS_PIN)
//Reset connected to LPC reset in
#define WF_RESET_PORT		0
#define WF_RESET_PIN		11
#define WF_RESET_BIT		(1 << WF_RESET_PIN)
#define WF_HIBERNATE_PORT	0
#define WF_HIBERNATE_PIN	23
#define WF_HIBERNATE_BIT	(1 << WF_HIBERNATE_PIN)
#define WF_SCK_PORT     	0
#define WF_SCK_PIN			15
#define WF_SCK_BIT			(1 <<  WF_SCK_PIN)
#define WF_MISO_PORT		0
#define WF_MISO_PIN			17
#define WF_MISO_BIT			(1 <<  WF_MISO_PIN)
#define WF_MOSI_PORT		0
#define WF_MOSI_PIN			18
#define WF_MOSI_BIT			(1 <<  WF_MOSI_PIN)
#define WF_EINT0_PORT		2
#define WF_EINT0_PIN		10
#define WF_EINT0_BIT		(1 <<  WF_EINT0_PIN)
#define WF_EINT2_PORT		2
#define WF_EINT2_PIN		12
#define WF_EINT2_BIT		(1 <<  WF_EINT2_PIN)
#define WF_EINT3_PORT		2//Using this one
#define WF_EINT3_PIN		13 //Using this one
#define WF_EINT3_BIT		(1 <<  WF_EINT3_PIN) //Using this one


#define WF_SPI_CHN			1
#define WF_INT				1



#endif  /* _PINOUT_H */
