/*******************************************************************************
  MRF24W Driver Medium Access Control (MAC) Layer

  Summary:
    Module for Microchip TCP/IP Stack PIC32 implementation for 
    multiple MAC support
    
  Description:
*******************************************************************************/

/*******************************************************************************
FileName:  MRF24W_Mac_pic32.h 
Copyright � 2012 released Microchip Technology Inc.  All rights
reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

/*
*********************************************************************************************************
*                                           INCLUDES                               
*********************************************************************************************************
*/


#ifndef _MRF24W_MAC_PIC32_H_ 
#define _MRF24W_MAC_PIC32_H_ 

#include "tcpip_private.h"


// Compile only for PIC32MX MRF24W MAC interface
#if defined(TCPIP_IF_MRF24W) 

#include "tcpip/tcpip_mac_object.h"

// MRF24W MAC descriptor
//
typedef struct  
{
    const TCPIP_MAC_OBJECT* pObj;           // safe cast to TCPIP_MAC_DCPT   
    // specific MRF24W MAC data 
    NET_CONFIG*         pNetIf;         // interface we belong to                                     
    bool                isOpen;         // simple open status flag
                                        // just one hardware module supported for now
    // add other MRF24W data here
}MRF24W_MAC_DCPT;

#endif  // defined(TCPIP_IF_MRF24W)

#endif  // _MRF24W_MAC_PIC32_H_ 

