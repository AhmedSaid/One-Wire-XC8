/*
 * 1 Wire Protocol for XC8 Compiler 
 * 
 * Author:  Ahmed Said
 * Email:   Ahm3d.said@gmail.com 
 * Website: http://brillianttechie.com
 * 
 * Date:    15 March. 2016
 *
 * Revision history: 
 * 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ONE_WIRE_H
#define	__ONE_WIRE_H

#include <xc.h>

#include "delay.h" // include processor files - each processor file is guarded. 


#ifdef	__cplusplus
extern "C"
{
#endif /* __cplusplus */

#define DQ_PIN PORTAbits.RA2
#define DQ_TRIS TRISAbits.TRISA2

    // 1wire command set
#define ONEWIRE_CMD_SEARCHROM        0xF0
#define ONEWIRE_CMD_READROM          0x33
#define ONEWIRE_CMD_MATCHROM         0x55
#define ONEWIRE_CMD_SKIPROM          0xCC
#define ONEWIRE_CMD_ALARMSEARCH      0xEC

    unsigned char OW_Reset();
    void OW_WriteByte(unsigned char data);
    unsigned char OW_ReadByte();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif

