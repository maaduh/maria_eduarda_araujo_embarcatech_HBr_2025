#include "temp_convert.h"

const float vref = 3.3f;
const float range = (1 << 12); 
const float conv = vref / (range - 1); 

const float temp27 = 0.706f;
const float tempsens = 0.001721f;

float adc_to_celsius(uint16_t adc_val) {

    if (adc_val > 4095) {
        adc_val = 4095;
    }
    float adcv = (float)adc_val * conv;

    float tempc = 27.0f - (adcv - temp27) / tempsens;

    return tempc;
}