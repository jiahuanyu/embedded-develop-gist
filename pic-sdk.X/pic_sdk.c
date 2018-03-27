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

/* Timer 配置 */
void pic_sdk_timer6_config(PIC_SDK_TIMER6_PERIOD_e p_period) {
    GIE = 1;
    PEIE = 1;
    TMR6IF = 0;
    TMR6IE = 1;
    T6CON = p_period;
}

/*ADC*/
void pic_sdk_adc_config(uint8_t p_index) {
    switch (p_index) {
        case 1:
            ANSELAbits.ANSA1 = 1;
            ADCON0bits.CHS = 0b00001;
            break;
        default:
            break;
    }
    ADCON0bits.GO = 0;
    ADCON0bits.ADON = 1;

    ADCON1bits.ADFM = 1;
    ADCON1bits.ADCS = 0b010;
    ADCON1bits.ADNREF = 0;
    ADCON1bits.ADPREF = 0b00;
}

/*IIC*/
void pic_sdk_i2c_config(void) {
    TRISC3 = 1;
    TRISC4 = 1;
    SSPSTATbits.SMP = 1;
    SSPADD = 0x09; // 设置时钟频率
    SSPIF = 0;
    SSPCON1 = 0x38; // 初始化寄存器 主模式
}

void pic_sdk_i2c_write_1(uint8_t p_address, uint8_t p_data) {
    SEN = 1; //产生IIC启动信号
    while (!SSPIF); //等待启动结束
    SSPIF = 0; //SSPIF标志清0

    SSPBUF = p_address; //发送地址字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0     
    while (ACKSTAT);

    SSPBUF = p_data; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    PEN = 1; //产生IIC停止信号
    while (!SSPIF);
    SSPIF = 0; //SSPIF标志清0 
}

void pic_sdk_i2c_write_2(uint8_t p_address, uint8_t p_data, uint8_t p_data_2) {
    SEN = 1; //产生IIC启动信号
    while (!SSPIF); //等待启动结束
    SSPIF = 0; //SSPIF标志清0

    SSPBUF = p_address; //发送地址字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0     
    while (ACKSTAT);

    SSPBUF = p_data; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    SSPBUF = p_data_2; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    PEN = 1; //产生IIC停止信号
    while (!SSPIF);
    SSPIF = 0; //SSPIF标志清0 
}

void pic_sdk_i2c_write_3(uint8_t p_address, uint8_t p_data, uint8_t p_data_2, uint8_t p_data_3) {
    SEN = 1; //产生IIC启动信号
    while (!SSPIF); //等待启动结束
    SSPIF = 0; //SSPIF标志清0

    SSPBUF = p_address; //发送地址字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0     
    while (ACKSTAT);

    SSPBUF = p_data; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    SSPBUF = p_data_2; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    SSPBUF = p_data_3; //发送数据字节
    while (!SSPIF); //等待发送结束
    SSPIF = 0; //SSPIF标志清0
    while (ACKSTAT);

    PEN = 1; //产生IIC停止信号
    while (!SSPIF);
    SSPIF = 0; //SSPIF标志清0     
}

/**/
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
