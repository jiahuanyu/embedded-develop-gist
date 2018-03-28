#ifndef PIC_SDK_H
#define	PIC_SDK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pic_sdk_config.h"
#include <pic.h>
#include <stdint.h>

    typedef uint8_t boolean;

    // 断言设置
#define configASSERT(x) if((x) ==0){printf("错误代码位置：%s\n行数：%d\n",__FILE__,__LINE__),exit(1);}  

#if defined(_16F1933) || defined(_16F1936) || defined(_16F1938)

    // 器件配置1
#define CONFIGURATION_WORD_1 (0bPIC_CONFIG_FCMEN << 13) | (0bPIC_CONFIG_IESO << 12) | (0bPIC_CONFIG_CLKOUTEN << 11) | \
                             (0bPIC_CONFIG_BOREN << 9)  | (0bPIC_CONFIG_CPD << 8)   | (0bPIC_CONFIG_CP << 7) | \
                             (0bPIC_CONFIG_MCLRE << 6)  | (0bPIC_CONFIG_PWRTE << 5)   | (0bPIC_CONFIG_WDTE << 3) | \
                             (0bPIC_CONFIG_FOSC)

    // 器件配置2
#define CONFIGURATION_WORD_2 (0bPIC_CONFIG_LVP << 13) | (0bPIC_CONFIG_DEBUG << 12) | (0b1 << 11) | (0bPIC_CONFIG_BORV << 10) | \
                             (0bPIC_CONFIG_STVREN << 9) | (0bPIC_CONFIG_PLLEN << 8) | (0b11 << 6) | (0bPIC_CONFIG_VCAPEN << 4) | \
                             (0b11 << 2) | (0bPIC_CONFIG_WRT)

#elif defined(_16F1947)
    // 器件配置1
#define CONFIGURATION_WORD_1 (0bPIC_CONFIG_FCMEN << 13) | (0bPIC_CONFIG_IESO << 12) | (0bPIC_CONFIG_CLKOUTEN << 11) | \
                             (0bPIC_CONFIG_BOREN << 9)  | (0bPIC_CONFIG_CPD << 8)   | (0bPIC_CONFIG_CP << 7) | \
                             (0bPIC_CONFIG_MCLRE << 6)  | (0bPIC_CONFIG_PWRTE << 5)   | (0bPIC_CONFIG_WDTE << 3) | \
                             (0bPIC_CONFIG_FOSC)

    // 器件配置2
#define CONFIGURATION_WORD_2 (0bPIC_CONFIG_LVP << 13) | (0bPIC_CONFIG_DEBUG << 12) | (0b1 << 11) | (0bPIC_CONFIG_BORV << 10) | \
                             (0bPIC_CONFIG_STVREN << 9) | (0bPIC_CONFIG_PLLEN << 8) | (0b111 << 5) | (0bPIC_CONFIG_VCAPEN << 4) | \
                             (0b11 << 2) | (0bPIC_CONFIG_WRT)
#endif

    __PROG_CONFIG(1, CONFIGURATION_WORD_1);
    __PROG_CONFIG(2, CONFIGURATION_WORD_2);

    /* 系统初始化配置 */
    void pic_sdk_system_ini_config(void);

    /* 内部晶振设置 */
    struct PIC_SDK_OSC_CONFIG {
        boolean inner_osc_used;
        uint32_t fosc;
    };
    typedef struct PIC_SDK_OSC_CONFIG PIC_SDK_OSC_CONFIG_t;
    void pic_sdk_osc_config(PIC_SDK_OSC_CONFIG_t p_config);

    /* 系统内部看门狗配置 */
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

    /* Timer */
    enum PIC_SDK_TIMER6_PERIOD {
        PIC_SDK_TIMER6_PERIOD_ms_65_536 = 0b01111111,
        PIC_SDK_TIMER6_PERIOD_ms_32_768 = 0b00111011
    };
    typedef enum PIC_SDK_TIMER6_PERIOD PIC_SDK_TIMER6_PERIOD_e;

    struct PIC_SDK_TIMER6_CONFIG {
        PIC_SDK_TIMER6_PERIOD_e period;
    };
    typedef struct PIC_SDK_TIMER6_CONFIG PIC_SDK_TIMER6_CONFIG_t;

    void pic_sdk_timer6_config(PIC_SDK_TIMER6_CONFIG_t p_config);

    /* ADC */
    void pic_sdk_adc_config(uint8_t p_index);

    /* IIC */
    enum PIC_SDK_I2C_MODE {
        PIC_SDK_I2C_MODE_MASTER = 0,
        PIC_SDK_I2C_MODE_SLAVE = 1
    };
    typedef enum PIC_SDK_I2C_MODE PIC_SDK_I2C_Mode_e;

    struct PIC_SDK_I2C_CONFIG {
        PIC_SDK_I2C_Mode_e master_slave_mode;
        boolean interrupt_open;
    };
    typedef struct PIC_SDK_I2C_CONFIG PIC_SDK_I2C_CONFIG_t;

    void pic_sdk_i2c_config(uint8_t p_index, PIC_SDK_I2C_CONFIG_t p_config);
    void pic_sdk_i2c_write(uint8_t p_index, uint8_t p_write_address, uint8_t* p_data, uint8_t p_data_size);
    uint8_t pic_sdk_i2c_read(uint8_t p_index, uint8_t p_read_address);

    /* SPI */
    enum PIC_SDK_SPI_MODE {
        PIC_SDK_SPI_MODE_MASTER = 0,
        PIC_SDK_SPI_MODE_SLAVE = 1
    };
    typedef enum PIC_SDK_SPI_MODE PIC_SDK_SPI_MODE_e;

    struct PIC_SDK_SPI_CONFIG {
        PIC_SDK_SPI_MODE_e master_slave_mode; // 主从模式
        boolean interrupt_open; // 是否开启中断
    };
    typedef struct PIC_SDK_SPI_CONFIG PIC_SDK_SPI_CONFIG_t;

    void pic_sdk_spi_config(uint8_t p_index, PIC_SDK_SPI_CONFIG_t p_config);
    void pic_sdk_spi_write(uint8_t p_index, uint8_t p_data);
    uint8_t pic_sdk_spi_read(uint8_t p_index);

    /* UART */
    void pic_sdk_uart_config(uint32_t p_fosc, uint32_t p_baudrate, uint8_t p_option);

#ifdef	__cplusplus
}
#endif

#endif	


