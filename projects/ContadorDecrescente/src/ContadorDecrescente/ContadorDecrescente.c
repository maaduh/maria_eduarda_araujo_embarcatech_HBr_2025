#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "inc/ssd1306.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define BTNA_PIN 5
#define BTNB_PIN 6
const uint I2C_SDA = 14;
const uint I2C_SCL = 15;

int main()
{
    int countB = 0;
    int reg = 9;
    int g = 0;
    bool anteriorA = gpio_get(BTNA_PIN);
    bool anteriorB = gpio_get(BTNB_PIN);

    stdio_init_all();

    gpio_init(BTNA_PIN);
    gpio_set_dir(BTNA_PIN, GPIO_IN);
    gpio_pull_up(BTNA_PIN);

    gpio_init(BTNB_PIN);
    gpio_set_dir(BTNB_PIN, GPIO_IN);
    gpio_pull_up(BTNB_PIN); 

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    struct render_area frame_area = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    uint8_t ssd[ssd1306_buffer_length];
    char buffer[32];

    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

    while (gpio_get(BTNA_PIN)) {
        sleep_ms(10);
    }
    while (1) {
        bool A = gpio_get(BTNA_PIN);

        if (A && !anteriorA) {
            countB = 0;
            reg = 9;

            while (reg >= 0) {
                memset(ssd, 0, ssd1306_buffer_length);
                sprintf(buffer, "Contador: %d", reg);
                ssd1306_draw_string(ssd, 0, 0, buffer);
                render_on_display(ssd, &frame_area);
                uint32_t tempo_inicio = to_ms_since_boot(get_absolute_time());
                while (to_ms_since_boot(get_absolute_time()) - tempo_inicio < 1000) {
                    bool B = gpio_get(BTNB_PIN);
                    if (B && !anteriorB) {
                        countB++;
                    }
                    anteriorB = B;
                    sleep_ms(10);
                }

                reg--;
            }
            if(g == 0){
                countB--;
                g = 1;
            }
            memset(ssd, 0, ssd1306_buffer_length);
            ssd1306_draw_string(ssd, 0, 0, "Contador: 0");
            sprintf(buffer, "Cliques: %d ", countB);
            ssd1306_draw_string(ssd, 0, 2, buffer);
            render_on_display(ssd, &frame_area); 
        }

        anteriorA = A;
        sleep_ms(10);
    }
}