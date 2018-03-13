#ifndef PIC_SDK_H
#define	PIC_SDK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <pic.h>
#include <stdint.h>

#if defined (_16F1933) || defined(_16F1936) || defined(_16F1938)
    void uart_0_initialise(uint32_t fosc, uint32_t baudrate, uint8_t option);
#endif

#ifdef	__cplusplus
}
#endif

#endif	


