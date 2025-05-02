#include "led_embutido.h"
#include "pico/cyw43_arch.h"

void led_driver_init() {
    cyw43_arch_init();
}

void led_driver_set(bool on) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
}
