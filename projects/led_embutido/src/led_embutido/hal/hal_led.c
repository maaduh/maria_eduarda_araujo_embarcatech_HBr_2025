#include "hal_led.h"
#include "led_embutido.h"

static bool estado_led = false;

void hal_led_init() {
    led_driver_init();
}

void hal_led_toggle() {
    estado_led = !estado_led;
    led_driver_set(estado_led);
}
