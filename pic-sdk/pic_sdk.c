#include "pic_sdk.h"

/*系统初始化配置*/
void pic_sdk_system_ini_config(void) {
#if defined(_16F1933) || defined(_16F1936) || defined(_16F1938)
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
#endif


#if defined(_16F1947)
    // PORT_A
    PORTA = 0x00;
    TRISA = 0xFF;
    ANSELA = 0x00;

    // PORT_B
    PORTB = 0x00;
    TRISB = 0xFF;
    WPUB = 0x00; // 禁止弱上拉

    // PORT_C
    PORTC = 0x00;
    TRISC = 0xFF;

    // PORT_D
    PORTD = 0x00;
    TRISD = 0xFF;

    // PORT_E
    PORTE = 0x00;
    TRISE = 0xFF;
    ANSELE = 0x00;

    // PORT_F
    PORTF = 0x00;
    TRISF = 0xFF;
    ANSELF = 0x00;

    // PORT_G
    PORTG = 0x00;
    TRISG = 0xFF;
    ANSELG = 0x00;
    WPUG = 0x00; // 禁止弱上拉

    // 中断设置
    INTE = 0; // 禁止外部中断
    IOCIE = 0; // 禁止电平变化中断	
#endif
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
void pic_sdk_osc_config(PIC_SDK_OSC_CONFIG_t p_config) {
    OSCCONbits.SPLLEN = 0;
    if (p_config.fosc == 16000000) {
        OSCCONbits.IRCF0 = 1;
        OSCCONbits.IRCF1 = 1;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    } else if (p_config.fosc == 8000000) {
        OSCCONbits.IRCF0 = 0;
        OSCCONbits.IRCF1 = 1;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    } else if (p_config.fosc == 4000000) {
        OSCCONbits.IRCF0 = 1;
        OSCCONbits.IRCF1 = 0;
        OSCCONbits.IRCF2 = 1;
        OSCCONbits.IRCF3 = 1;
    }
    if (p_config.inner_osc_used) {
        // 系统时钟选择位
        OSCCONbits.SCS0 = 0;
        OSCCONbits.SCS1 = 1;
    } else {
        OSCCONbits.SCS0 = 0;
        OSCCONbits.SCS1 = 0;
    }
}

/* Timer 配置 */
void pic_sdk_timer6_config(PIC_SDK_TIMER6_CONFIG_t p_config) {
    GIE = 1;
    PEIE = 1;
    TMR6IF = 0;
    TMR6IE = 1;
    T6CON = p_config.period;
}

/* ADC */
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

/* IIC */
void pic_sdk_i2c_config(uint8_t p_index, PIC_SDK_I2C_CONFIG_t p_config) {
#if defined(_16F1933) || defined(_16F1936) || defined(_16F1938)
    TRISC3 = 1;
    TRISC4 = 1;
    if (p_config.master_slave_mode == PIC_SDK_I2C_MODE_MASTER) {
        SSPSTATbits.SMP = 1;
        SSPCONbits.SSPM0 = 1;
        SSPCONbits.SSPM1 = 0;
        SSPCONbits.SSPM2 = 0;
        SSPCONbits.SSPM3 = 0; // FOSC / (4 * (SSPADD+1)) 
        SSPADD = 0x39; // 设置时钟频率 100KH
        SSPIF = 0;
        SSPCONbits.SSPEN = 1;
    }
#elif defined(_16F1947)
    switch (p_index) {
        case 2:
            // 设置IO输入状态
            TRISD5 = 1;
            TRISD6 = 1;
            if (p_config.master_slave_mode == PIC_SDK_I2C_MODE_MASTER) {
                SSP2STATbits.SMP = 1;
                SSP2CON1bits.SSPM0 = 1;
                SSP2CON1bits.SSPM1 = 0;
                SSP2CON1bits.SSPM2 = 0;
                SSP2CON1bits.SSPM3 = 0; // FOSC / (4 * (SSPADD+1)) 
                SSP2ADD = 0x39; // 设置时钟频率 100KH
                SSP2IF = 0;
            }
            SSP2CON1bits.SSPEN = 1; // 使能i2c
            break;
        default:
            break;
    }
#endif


}

void pic_sdk_i2c_write(uint8_t p_index, uint8_t p_write_address, uint8_t* p_data, uint8_t p_data_size) {
#if defined(_16F1933) || defined(_16F1936) || defined(_16F1938)

    SEN = 1; //产生IIC启动信号
    while (!SSPIF); //等待启动结束
    SSPIF = 0; //SSPIF标志清0

    SSPBUF = p_write_address; //发送地址字节
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

#elif defined(_16F1947)
    switch (p_index) {
        case 2:
            SSP2CON2bits.SEN = 1; //产生IIC启动信号
            while (!SSP2IF); //等待启动结束
            SSP2IF = 0; //SSPIF标志清0

            SSP2BUF = p_write_address; //发送地址字节
            while (!SSP2IF); //等待发送结束
            SSP2IF = 0; //SSPIF标志清0     
            while (SSP2CON2bits.ACKSTAT);

            for (uint8_t i = 0; i < p_data_size; i++) {
                SSP2BUF = *p_data; //发送数据字节
                while (!SSP2IF); //等待发送结束
                SSP2IF = 0; //SSPIF标志清0
                while (SSP2CON2bits.ACKSTAT);
                p_data++;
            }

            SSP2CON2bits.PEN = 1; //产生IIC停止信号
            while (!SSP2IF);
            SSP2IF = 0; //SSPIF标志清0 
            break;
        default:
            break;
    }

#endif
}

uint8_t pic_sdk_i2c_read(uint8_t p_index, uint8_t p_read_address) {
    uint8_t content;
#if defined(_16F1947)
    switch (p_index) {
        case 2:
            SSP2CON2bits.SEN = 1; //产生IIC启动信号
            while (!SSPIF); //等待启动结束
            SSPIF = 0; //SSPIF标志清0

            SSP2BUF = p_read_address; //发送数据字节
            while (!SSP2IF); //等待发送结束
            SSP2IF = 0; //SSPIF标志清0
            while (SSP2CON2bits.ACKSTAT);

            SSP2CON2bits.RCEN = 1;
            while (!SSP2IF); //等待发送结束
            SSP2IF = 0; //SSPIF标志清0
            content = SSP2BUF;

            SSP2CON2bits.PEN = 1; //产生IIC停止信号
            while (!SSP2IF);
            SSP2IF = 0; //SSPIF标志清0 

            break;
        default:
            break;
    }
#endif
    return content;
}

/* SPI */
void pic_sdk_spi_config(uint8_t p_index, PIC_SDK_SPI_CONFIG_t p_config) {
#if defined(_16F1947)
    switch (p_index) {
        case 1:
            TRISC5 = 0; // SDO
            TRISC4 = 1; // SDI
            if (p_config.master_slave_mode == PIC_SDK_SPI_MODE_MASTER) {
                TRISC3 = 0; // SCK

                SSP1STATbits.SMP = 1;
                SSP1CON1bits.SSPM0 = 0;
                SSP1CON1bits.SSPM1 = 0;
                SSP1CON1bits.SSPM2 = 0;
                SSP1CON1bits.SSPM3 = 0;
            }

            SSP1STATbits.CKE = 1;
            SSP1CON1bits.CKP = 1;

            SSP1IF = 0;

            if (p_config.interrupt_open) {
                GIE = 1;
                PEIE = 1;
                PIE1bits.SSP1IE = 1;
            }


            SSP1CON1bits.SSPEN = 1;
            break;
        default:
            break;
    }
#endif
}

void pic_sdk_spi_write(uint8_t p_index, uint8_t p_data) {

#if defined(_16F1947)
    switch (p_index) {
        case 1:
            SSP1BUF = p_data;
            while (!SSP1IF);
            SSP1IF = 0;
            break;
        default:
            break;
    }
#endif

}

uint8_t pic_sdk_spi_read(uint8_t p_index) {
    uint8_t content;
#if defined(_16F1947)
    switch (p_index) {
        case 1:
            content = SSP1BUF;
            break;
        default:
            break;
    }
#endif
    return content;
}

/* UART */
void pic_sdk_uart_config(uint32_t p_fosc, uint32_t p_baudrate, uint8_t p_option) {
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


