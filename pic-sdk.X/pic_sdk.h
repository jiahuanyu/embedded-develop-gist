#ifndef PIC_SDK_H
#define	PIC_SDK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pic_config.h"
#include <pic.h>
#include <stdint.h>

    // 断言设置
#define configASSERT(x) if((x) ==0){printf("错误代码位置：%s\n行数：%d\n",__FILE__,__LINE__),exit(1);}  

    // 器件配置1
#define CONFIGURATION_WORD_1 (0bPIC_CONFIG_FCMEN << 13) | (0bPIC_CONFIG_IESO << 12) | (0bPIC_CONFIG_CLKOUTEN << 11) | \
                             (0bPIC_CONFIG_BOREN << 9)  | (0bPIC_CONFIG_CPD << 8)   | (0bPIC_CONFIG_CP << 7) | \
                             (0bPIC_CONFIG_MCLRE << 6)  | (0bPIC_CONFIG_PWRTE << 5)   | (0bPIC_CONFIG_WDTE << 3) | \
                             (0bPIC_CONFIG_FOSC)

    // 器件配置2
#define CONFIGURATION_WORD_2 (0bPIC_CONFIG_LVP << 13) | (0bPIC_CONFIG_DEBUG << 12) | (1 << 11) | (0bPIC_CONFIG_BORV << 10) | \
                             (0bPIC_CONFIG_STVREN << 9) | (0bPIC_CONFIG_PLLEN << 8) | (0b11 << 6) | (0bPIC_CONFIG_VCAPEN << 4) | \
                             (0b11 << 2) | (0bPIC_CONFIG_WRT)

    __PROG_CONFIG(1, CONFIGURATION_WORD_1);
    __PROG_CONFIG(2, CONFIGURATION_WORD_2);

    /*系统初始化配置*/
    void pic_sdk_system_ini_config(void);

    /*内部晶振设置*/
    void pic_sdk_inner_osc_config(void);

    /*系统内部看门狗配置*/
    enum PIC_SDK_WEATCH_DOG_PERIOD {
        ms_1 = 0b00000,
        ms_2 = 0b00001,
        ms_4 = 0b00010,
        ms_512 = 0b01001,
        s_1 = 0x01010
    };
    typedef enum PIC_SDK_WEATCH_DOG_PERIOD PIC_SDK_WEATCH_DOG_PERIOD_e;
    void pic_sdk_watch_dog_config(PIC_SDK_WEATCH_DOG_PERIOD_e p_period);
    void pic_sdk_watch_dog_on(void);
    void pic_sdk_watch_dog_off(void);

    /*串口配置*/
    void pic_sdk_uart_0_config(uint32_t p_fosc, uint32_t p_baudrate, uint8_t p_option);

#ifdef	__cplusplus
}
#endif

#endif	


