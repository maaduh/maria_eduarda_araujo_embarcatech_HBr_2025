#include "pico/stdlib.h"
#include "hal_led.h"

int main() {
    stdio_init_all();
    hal_led_init();

    while (true) {
        hal_led_toggle();
        sleep_ms(500);
    }
}
