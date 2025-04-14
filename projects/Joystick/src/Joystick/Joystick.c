#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"


int main()
{
    stdio_init_all();

    adc_init;

    adc_gpio_init(26);
    adc_gpio_init(27); 

    while(1){
        adc_select_input(1);
        uint x1 = adc_read();

        adc_select_input(0);
        uint y1 = adc_read();

        const uint barra_largura = 40;
        const uint max_adc = (1 << 12) - 1;

        uint x2 = x1 * barra_largura / max_adc;
        uint y2 = y1 * barra_largura / max_adc;

        printf("\rX: [");
        for (uint i = 0; i < barra_largura; ++i)
            putchar(i == x2 ? 'o' : ' ');
        printf("]  Y: [");
       
        for (uint i = 0; i < barra_largura; ++i)
            putchar(i == y2 ? 'o' : ' ');
        printf("]");

        sleep_ms(50);

    }

}
