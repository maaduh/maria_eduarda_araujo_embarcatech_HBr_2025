#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temp_convert.h"


const uint adc_temp = 4;

int main()
{
    stdio_init_all();


    adc_init();


    adc_set_temp_sensor_enabled(true);


    adc_select_input(adc_temp);

    printf("Iniciando...\n");

    while (true)
    {
        uint16_t adcval = adc_read();

        float tempc = adc_to_celsius(adcval);

        printf("Temp: %.2f C\n", tempc);

        sleep_ms(1000);
    }

    return 0;
}