# Controle Modular de LED para Raspberry Pi Pico W

Este projeto controla o LED embutido da Raspberry Pi Pico W de forma modular, dividindo o código em três camadas: drivers, HAL e aplicação principal.

## Estrutura do Projeto

- **drivers/**: Controla diretamente o LED.
- **hal/**: Fornece uma função simples para alternar o LED.
- **app/**: Usa a função da HAL para piscar o LED.
