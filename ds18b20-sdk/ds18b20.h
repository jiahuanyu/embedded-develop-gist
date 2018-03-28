#ifndef DS18B20_H
#define	DS18B20_H

#ifdef	__cplusplus
extern "C" {
#endif

    void ds18b20_reset(uint8_t p_index);
    void ds18b20_write_bit(uint8_t p_index, uint8_t p_data);
    void ds18b20_write_byte(uint8_t p_index, uint8_t p_data);
    uint8_t ds18b20_read_bit(uint8_t p_index);
    uint8_t ds18b20_read_byte(uint8_t p_index);

    void ds18b20_convert(uint8_t p_index);
    void ds18b20_read_info(uint8_t p_index);
	


#ifdef	__cplusplus
}
#endif

#endif	
