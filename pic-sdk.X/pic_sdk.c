#include "pic_sdk.h"
#if defined (_16F1933) || defined(_16F1936) || defined(_16F1938)

void uart_0_initialise(uint32_t fosc, uint32_t baudrate, uint8_t option) {
    // RX设置为输入状态, TX设置为输出状态
    TRISC7 = 1;
    TRISC6 = 0;

    SPBRGL = (uint8_t) (fosc / baudrate / 4 - 1 + 0.5f);
    SPBRGH = 0;

    // 16位波特率发生器
    BAUDCONbits.BRG16 = 1;
    //    BAUDCONbits.SCKP = 0; // 电平不翻转

    // 发送配置
    TXSTAbits.BRGH = 1; // 高速波特率
    // TXSTAbits.TX9 = 0; // 8位数据
    // SYNC = 0; //
    TXIE = option & 0x01; // TX中断配置
    TXIF = 0;
    TXSTAbits.TXEN = 1; //使能发送

    // RX
    //    RX9 = 0; // 8位数据
    RCIE = option & 0x02; // RX中断配置
    RCIF = 0;
    RCSTAbits.CREN = 1; //使能接收	

    //
    RCSTAbits.SPEN = 1; //使能串口
}
#endif
