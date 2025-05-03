#include "unity.h"
#include "temp_convert.h"
#include "pico/stdlib.h"

const float test_vref = 3.3f;
const float range_minus1 = 4095.0f; // (1 << 12) - 1
const float conv_factor= test_vref / range_minus1;
const float test_27c = 0.706f;
const float test_slope = 0.001721f;

void setUp(void) {}
void tearDown(void) {}

/**
 * @brief Testa a conversão ADC para Celsius usando um valor ADC próximo ao
 *        ponto de referência de 27°C e calculando a Temp exata esperada
 *        para ESSE valor ADC.
 */
void test_adc_to_celsius_near_reference_point(void)
{
    // Valor ADC próximo ao esperado para 0.706V
    uint16_t test_adc_input = 876;

    // Calcular a Temp ESPERADA para este valor ADC
    float exp_voltage = (float)test_adc_input * conv_factor;
    float exp_temp_c = 27.0f - (exp_voltage - test_27c) / test_slope;

    // Tolerância
    float delta = 0.001f; // Margem pequena para erros de ponto flutuante

    // Função sob teste com o valor ADC escolhido
    float act_temp_c = adc_to_celsius(test_adc_input);

    // Verifica se o resultado real corresponde ao resultado esperado calculado
    TEST_ASSERT_FLOAT_WITHIN(delta, exp_temp_c, act_temp_c);
}

// Teste para 20C
void test_adc_to_celsius_at_20C(void)
{
    uint16_t test_adc_input = 891; // Valor ADC aproximado para 20C

    // Calcular o esperado para 891
    float exp_voltage = (float)test_adc_input * conv_factor;
    float exp_temp_c = 27.0f - (exp_voltage - test_27c) / test_slope;

    float delta = 0.01f; 
    float act_temp_c = adc_to_celsius(test_adc_input);
    TEST_ASSERT_FLOAT_WITHIN(delta, exp_temp_c, act_temp_c);
}

// Temp alta
void test_adc_to_celsius_higher_temp(void)
{
    uint16_t test_adc_input = 850;
    float exp_voltage = (float)test_adc_input * conv_factor;
    float exp_temp_c = 27.0f - (exp_voltage - test_27c) / test_slope; // ~38.48 C
    float delta = 0.01f;                                                                                          

    float act_temp_c = adc_to_celsius(test_adc_input);
    TEST_ASSERT_FLOAT_WITHIN(delta, exp_temp_c, act_temp_c);
}

// Temp baixa
void test_adc_to_celsius_lower_temp(void)
{
    uint16_t test_adc_input = 950;
    float exp_voltage = (float)test_adc_input * conv_factor;
    float exp_temp_c = 27.0f - (exp_voltage - test_27c) / test_slope; // ~ -8.13 C
    float delta = 0.01f;                                                                                          

    float act_temp_c = adc_to_celsius(test_adc_input);
    TEST_ASSERT_FLOAT_WITHIN(delta, exp_temp_c, act_temp_c);
}

int main(void)
{
    stdio_init_all();
    sleep_ms(5000); 

    UNITY_BEGIN();
    printf("Iniciando...\n");
    sleep_ms(2000);

    printf("Testando...\n");
    sleep_ms(2000);
    RUN_TEST(test_adc_to_celsius_near_reference_point);
    sleep_ms(2000);

    printf("20C...\n");
    sleep_ms(2000);
    RUN_TEST(test_adc_to_celsius_at_20C);
    sleep_ms(2000);

    printf("Temp mais alta...\n");
    sleep_ms(2000);
    RUN_TEST(test_adc_to_celsius_higher_temp);
    sleep_ms(2000);

    printf("Temp mais baixa...\n");
    sleep_ms(2000);
    RUN_TEST(test_adc_to_celsius_lower_temp);
    sleep_ms(2000);

    printf("Resultado:\n");
    return UNITY_END();
}