/*
 * 1 Wire Protocol for XC8 Compiler 
 * 
 * Author:  Ahmed Said
 * Email:   Ahm3d.said@gmail.com 
 * Website: http://brillianttechie.com
 * 
 * Date:    15 March. 2016
 *
 * Version 1.0
 * 
 * Revision history: 
 * 
 */
#include "1-wire.h"

unsigned char OW_Reset() {
    unsigned char presence = 0, i = 0;

    DQ_TRIS = 1; // Release the DQ Bus
    Delay18us();

    // Pull the DQ Bus Low for a minimum of 480 us
    DQ_PIN = 0;
    DQ_TRIS = 0;

    for (i = 0; i < 48; i++)
        Delay10us();

    DQ_TRIS = 1; // Release the DQ Bus

    for (i = 0; i < 6; i++)
        Delay10us();

    presence = DQ_PIN;

    for (i = 0; i < 41; i++)
        Delay10us(); //Wait until the end of cycle (480-60)

    return !presence;
}

void OW_WriteByte(unsigned char data) {
    unsigned char i = 8, lsb;

    for (; i > 0; i--) {
        lsb = data & 0x01; // Get the LSB

        // Write the bit to the bus
        DQ_PIN = 0;
        DQ_TRIS = 0;
        Delay5us();

        //DQ_TRIS = lsb;
        DQ_PIN = lsb;

        Delay25us();
        Delay25us();
        Delay5us();

        DQ_TRIS = 1;

        Delay5us();

        data = data >> 1; // Prepare next bit
    }
}

unsigned char OW_ReadByte() {
    unsigned char i = 8, data = 0, state;

    for (; i > 0; i--) {
        DQ_PIN = 0;
        DQ_TRIS = 0;
        Delay5us();

        DQ_TRIS = 1;
        Delay5us();
        state = DQ_PIN;

        Delay25us();
        Delay25us();

        data = data >> 1;

        if (state == 1) {
            data |= 0x80;
        }
        Delay5us();
    }
    Delay5us();
    return data;
}
