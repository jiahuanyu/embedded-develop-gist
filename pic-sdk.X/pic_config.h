#ifndef PIC_CONFIG_H
#define	PIC_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

    // 振荡器
#define _XTAL_FREQ 16000000

    // FCMEN = 故障保护时钟监视器使能位
    // 1 = 使能故障保护时钟监视器
    // 0 = 禁止故障保护时钟监视器
#define PIC_CONFIG_FCMEN 1

    // IESO 内部/外部时钟切换位
    // 1 = 使能内部/外部时钟切换模式
    // 0 = 禁止内部/外部时钟切换模式
#define PIC_CONFIG_IESO 0

    // CLKOUTEN 时钟输出使能位
    // 1 = 禁止 CLKOUT 功能，即禁止 I/O 或 RA6/CLKOUT 引脚上的振荡器功能
    // 0 = 使能 RA6/CLKOUT 引脚上的 CLKOUT 功能
#define PIC_CONFIG_CLKOUTEN 1


    // BOREN<1:0> 欠压复位使能位
    // 11 = 使能 BOR
    // 10 = BOR 在工作时使能，在休眠时禁止
    // 01 = BOR 由 PCON 寄存器的 SBOREN 位控制
    // 00 = 禁止 BOR
#define PIC_CONFIG_BOREN 00

    // CPD 数据代码保护位
    // 1 = 禁止数据存储器代码保护 
    // 0 = 使能数据存储器代码保护
#define PIC_CONFIG_CPD 0


    // CP 代码保护位
    // 1 = 禁止程序存储器代码保护
    // 0 = 使能程序存储器代码保护
#define PIC_CONFIG_CP 0

    // MCLRE RE3/MCLR/VPP 引脚功能选择位
    // 如果 LVP 位 = 1 忽略此位。 
    // 如果 LVP 位 = 0:
    // 1 = RE3/MCLR/VPP 引脚功能为 MCLR ;使能弱上拉功能。
    // 0 = RE3/MCLR/VPP 引脚功能为数字输入;内部禁止 MCLR ;弱上拉功能由 WPUE3 位控制。
#define PIC_CONFIG_MCLRE 1

    // PWRTE 上电延时定时器使能位 
    // 1 = 禁止PWRT
    // 0 = 使能PWRT
#define PIC_CONFIG_PWRTE 0

    // WDTE<1:0> 看门狗定时器使能位
    // 11 = 使能WDT
    // 10 = WDT 在运行时使能，休眠时禁止
    // 01 = WDT 由 WDTCON 寄存器中的 SWDTEN 位控制
    // 00 = 禁止WDT
#define PIC_CONFIG_WDTE 01

    // FOSC<2:0> 振荡器选择位
#define PIC_CONFIG_FOSC 100

    // LVP 低压使能变成位
    // 1 = 使能低压编程   
    // 0 = 必须使用 MCLR/VPP 引脚上的高压进行编程
#define PIC_CONFIG_LVP 0

    // DEBUG 在线调试器模式位
    // 1 = 禁止在线调试器， RB6/ICSPCLK 和 RB7/ICSPDAT 是通用 I/O 引脚
    // 0 = 使能在线调试器， RB6/ICSPCLK 和 RB7/ICSPDAT 专用于调试器
#define PIC_CONFIG_DEBUG 1


    // BORV 欠压复位电压选择位
    // 1 = 欠压复位电压设置为 1.9V
    // 0 = 欠压复位电压设置为 2.7V
#define PIC_CONFIG_BORV 1

    // STVREN 堆栈满/下溢复位使能位 
    // 1 = 堆栈满或下溢将导致复位
    // 0 = 堆栈满或下溢不会导致复位
#define PIC_CONFIG_STVREN 1

    // PLLEN PLL使能位 
    // 1 = 使能 4xPLL
    // 0 = 禁止 4xPLL
#define PIC_CONFIG_PLLEN 0

    // VCAPEN<1:0> 稳压器电容使能位
    // 00 = 在 RA0 引脚上使能 VCAP 功能
    // 01 = 在 RA5 引脚上使能 VCAP 功能
    // 10 = 在 RA6 引脚上使能 VCAP 功能
    // 11 = VCAP 引脚上无电容
#define PIC_CONFIG_VCAPEN 11

    // WRT<1:0> 闪存自写保护位
#define PIC_CONFIG_WRT 00



#ifdef	cplusplus
}
#endif

#endif	

