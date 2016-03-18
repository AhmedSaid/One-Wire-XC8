/*
 * XC8 Delay functions 
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

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "system.h"

#define Delay5us() __delay_us(5)
#define Delay10us() __delay_us(10)
#define Delay18us() __delay_us(18)
#define Delay25us() __delay_us(25)

#define Delay5ms()  __delay_ms(5)
#define Delay10ms()  __delay_ms(10)
#define Delay15ms() __delay_ms(15)
#define Delay25ms() __delay_ms(25)

