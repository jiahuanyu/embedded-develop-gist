#include <pic16f1933.h>

#include "pic_sdk.h"

/*系统初始化配置*/
void pic_sdk_system_ini_config(void) {
    // PORT_A
    PORTA = 0x00;
    TRISA = 0xFF;
    ANSELA = 0x00;

    // PORT_B
    PORTB = 0x00;
    TRISB = 0xFF;
    ANSELB = 0x00;
    WPUB = 0x00; // 禁止弱上拉

    // PORT_C
    PORTC = 0x00;
    TRISC = 0xFF;

    // 中断设置
    INTE = 0; // 禁止外部中断
    IOCIE = 0; // 禁止电平变化中断	
}

/*系统内部看门狗配置*/
void pic_sdk_watch_dog_config(PIC_SDK_WEATCH_DOG_PERIOD_e p_period) {
    WDTCONbits.WDTPS = p_period;
}

void pic_sdk_watch_dog_on(void) {
    WDTCONbits.SWDTEN = 1;
}

void pic_sdk_watch_dog_off(void) {
    WDTCONbits.SWDTEN = 0;
}

/*内部晶振设置*/
void pic_sdk_inner_osc_config(void) {
    OSCCONbits.SPLLEN = 0;
    // 系统时钟选择位
    OSCCONbits.SCS0 = 0;
    OSCCONbits.SCS1 = 1;
    if (_XTAL_FREQ == 16000000) {
        OSCCONbits.IRCF0 = 1;
        OSCCONbits.IRCF1 = 1;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    } else if (_XTAL_FREQ == 8000000) {
        OSCCONbits.IRCF0 = 0;
        OSCCONbits.IRCF1 = 1;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    } else if (_XTAL_FREQ == 4000000) {
        OSCCONbits.IRCF0 = 1;
        OSCCONbits.IRCF1 = 0;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    }
}

void pic_sdk_uart_0_config(uint32_t p_fosc, uint32_t p_baudrate, uint8_t p_option) {
    // RX设置为输入状态, TX设置为输出状态
    TRISC7 = 1;
    TRISC6 = 0;

    SPBRGL = (uint8_t) (p_fosc / p_baudrate / 4 - 1 + 0.5f);
    SPBRGH = 0;

    // 16位波特率发生器
    BAUDCONbits.BRG16 = 1;
    //    BAUDCONbits.SCKP = 0; // 电平不翻转

    // 发送配置
    TXSTAbits.BRGH = 1; // 高速波特率
    // TXSTAbits.TX9 = 0; // 8位数据
    // SYNC = 0; //
    TXIE = p_option & 0x01; // TX中断配置
    TXIF = 0;
    TXSTAbits.TXEN = 1; //使能发送

    // RX
    //    RX9 = 0; // 8位数据
    RCIE = p_option & 0x02; // RX中断配置
    RCIF = 0;
    RCSTAbits.CREN = 1; //使能接收	

    //
    RCSTAbits.SPEN = 1; //使能串口
}
