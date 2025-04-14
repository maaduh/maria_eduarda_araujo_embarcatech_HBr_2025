#include <stdio.h>
#include "pico/stdlib.h"       
#include "hardware/adc.h"    

#define ADC_TEMPERATURE_CHANNEL 4

float adc_to_temperature(uint16_t adc_value) {
    const float conversion_factor = 3.3f / (1 << 12); 
    float voltage = adc_value * conversion_factor;    
    float temperature_celsius = 27.0f - (voltage - 0.706f) / 0.001721f;  
    return temperature_celsius;
}

int main() {
    stdio_init_all();

    adc_init();

    adc_set_temp_sensor_enabled(true);  
    adc_select_input(ADC_TEMPERATURE_CHANNEL); 

    while (true) {
        uint16_t adc_value = adc_read();

        float temperature_celsius = adc_to_temperature(adc_value);

        printf("Temperatura: %.2f °F\n", temperature_celsius);

        sleep_ms(1000);
    }

    return 0;
}

