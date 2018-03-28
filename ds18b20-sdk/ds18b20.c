#include "ds18b20.h"

void ds18b20_reset(uint8_t p_index) {
    if (p_index == 0) {
        if (!IO_MOXA_0_DATA) {
            moxa_info_array_[0].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_0_DATA_LOW();
        __delay_us(500);
        IO_MOXA_0_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_0_DATA) {
            if (moxa_info_array_[0].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[0].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[0].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 1) {
        if (!IO_MOXA_1_DATA) {
            moxa_info_array_[1].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_1_DATA_LOW();
        __delay_us(500);
        IO_MOXA_1_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_1_DATA) {
            if (moxa_info_array_[1].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[1].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[1].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 2) {
        if (!IO_MOXA_2_DATA) {
            moxa_info_array_[2].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_2_DATA_LOW();
        __delay_us(500);
        IO_MOXA_2_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_2_DATA) {
            if (moxa_info_array_[2].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[2].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[2].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 3) {
        if (!IO_MOXA_3_DATA) {
            moxa_info_array_[3].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_3_DATA_LOW();
        __delay_us(500);
        IO_MOXA_3_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_3_DATA) {
            if (moxa_info_array_[3].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[3].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[3].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 4) {
        if (!IO_MOXA_4_DATA) {
            moxa_info_array_[4].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_4_DATA_LOW();
        __delay_us(500);
        IO_MOXA_4_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_4_DATA) {
            if (moxa_info_array_[4].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[4].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[4].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 5) {
        if (!IO_MOXA_5_DATA) {
            moxa_info_array_[5].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_5_DATA_LOW();
        __delay_us(500);
        IO_MOXA_5_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_5_DATA) {
            if (moxa_info_array_[5].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[5].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[5].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 6) {
        if (!IO_MOXA_6_DATA) {
            moxa_info_array_[6].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_6_DATA_LOW();
        __delay_us(500);
        IO_MOXA_6_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_6_DATA) {
            if (moxa_info_array_[6].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[6].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[6].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 7) {
        if (!IO_MOXA_7_DATA) {
            moxa_info_array_[7].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_7_DATA_LOW();
        __delay_us(500);
        IO_MOXA_7_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_7_DATA) {
            if (moxa_info_array_[7].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[7].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[7].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 8) {
        if (!IO_MOXA_8_DATA) {
            moxa_info_array_[8].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_8_DATA_LOW();
        __delay_us(500);
        IO_MOXA_8_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_8_DATA) {
            if (moxa_info_array_[8].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[8].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[8].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    } else if (p_index == 9) {
        if (!IO_MOXA_9_DATA) {
            moxa_info_array_[9].status = MOXA_STATUS_ERROR_PULL_DOWN;
            return;
        }
        IO_MOXA_9_DATA_LOW();
        __delay_us(500);
        IO_MOXA_9_DATA_HIGH();
        __delay_us(70);
        if (!IO_MOXA_9_DATA) {
            if (moxa_info_array_[9].status == MOXA_STATUS_DISCONNECTED) {
                moxa_info_array_[9].status = MOXA_STATUS_CONNECTED;
            }
        } else {
            moxa_info_array_[9].status = MOXA_STATUS_DISCONNECTED;
        }
        __delay_us(500);
    }
}

void ds18b20_write_bit(uint8_t p_index, uint8_t p_data) {
    if (p_index == 0) {
        IO_MOXA_0_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_0_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_0_DATA_HIGH();
    } else if (p_index == 1) {
        IO_MOXA_1_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_1_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_1_DATA_HIGH();
    } else if (p_index == 2) {
        IO_MOXA_2_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_2_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_2_DATA_HIGH();
    } else if (p_index == 3) {
        IO_MOXA_3_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_3_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_3_DATA_HIGH();
    } else if (p_index == 4) {
        IO_MOXA_4_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_4_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_4_DATA_HIGH();
    } else if (p_index == 5) {
        IO_MOXA_5_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_5_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_5_DATA_HIGH();
    } else if (p_index == 6) {
        IO_MOXA_6_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_6_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_6_DATA_HIGH();
    } else if (p_index == 7) {
        IO_MOXA_7_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_7_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_7_DATA_HIGH();
    } else if (p_index == 8) {
        IO_MOXA_8_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_8_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_8_DATA_HIGH();
    } else if (p_index == 9) {
        IO_MOXA_9_DATA_LOW();
        __delay_us(2);
        if (p_data) {
            IO_MOXA_9_DATA_HIGH();
        }
        __delay_us(60);
        IO_MOXA_9_DATA_HIGH();
    }
}

void ds18b20_write_byte(uint8_t p_index, uint8_t p_data) {
    uint8_t command_bit;
    for (uint8_t i = 0; i < 8; i++) {
        command_bit = p_data & 0x01;
        moxa_write_bit(p_index, command_bit);
        p_data = p_data >> 1;
    }
}

uint8_t ds18b20_read_bit(uint8_t p_index) {
    uint8_t bit_data;
    if (p_index == 0) {
        IO_MOXA_0_DATA_LOW();
        __delay_us(6);
        IO_MOXA_0_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_0_DATA;
        __delay_us(70);
    } else if (p_index == 1) {
        IO_MOXA_1_DATA_LOW();
        __delay_us(6);
        IO_MOXA_1_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_1_DATA;
        __delay_us(70);
    } else if (p_index == 2) {
        IO_MOXA_2_DATA_LOW();
        __delay_us(6);
        IO_MOXA_2_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_2_DATA;
        __delay_us(70);
    } else if (p_index == 3) {
        IO_MOXA_3_DATA_LOW();
        __delay_us(6);
        IO_MOXA_3_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_3_DATA;
        __delay_us(70);
    } else if (p_index == 4) {
        IO_MOXA_4_DATA_LOW();
        __delay_us(6);
        IO_MOXA_4_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_4_DATA;
        __delay_us(70);
    } else if (p_index == 5) {
        IO_MOXA_5_DATA_LOW();
        __delay_us(6);
        IO_MOXA_5_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_5_DATA;
        __delay_us(70);
    } else if (p_index == 6) {
        IO_MOXA_6_DATA_LOW();
        __delay_us(6);
        IO_MOXA_6_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_6_DATA;
        __delay_us(70);
    } else if (p_index == 7) {
        IO_MOXA_7_DATA_LOW();
        __delay_us(6);
        IO_MOXA_7_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_7_DATA;
        __delay_us(70);
    } else if (p_index == 8) {
        IO_MOXA_8_DATA_LOW();
        __delay_us(6);
        IO_MOXA_8_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_8_DATA;
        __delay_us(70);
    } else if (p_index == 9) {
        IO_MOXA_9_DATA_LOW();
        __delay_us(6);
        IO_MOXA_9_DATA_HIGH();
        __delay_us(4);
        bit_data = IO_MOXA_9_DATA;
        __delay_us(70);
    }
    return bit_data;
}

uint8_t ds18b20_read_byte(uint8_t p_index) {
    uint8_t data = moxa_read_bit(p_index);
    for (int i = 1; i < 8; i++) {
        data |= (moxa_read_bit(p_index) << i);
    }
    return data;
}

void ds18b20_convert(uint8_t p_index) {
    moxa_reset(p_index);
    if (moxa_info_array_[p_index].status == MOXA_STATUS_CONNECTED) {
        moxa_write_byte(p_index, 0xCC);
        moxa_write_byte(p_index, 0x44);
    }
}


