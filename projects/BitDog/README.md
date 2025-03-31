🎯 **Objetivo do Projeto**  
O projeto tem como objetivo desenvolver um sistema interativo para a placa BitDogLab, implementando funcionalidades que permitem ao usuário interagir com o dispositivo por meio de botões e joystick. As principais funções incluem animações no display OLED, reprodução de sons no buzzer e controle de uma matriz de LEDs, simulando ações como "comer", "dormir" e "dançar".  

🔧 **Componentes Usados**  
- Placa **BitDogLab (Raspberry Pi Pico W)**  
- **Display OLED** SSD1306  
- **Matriz de LEDs** WS2812B  
- **LED RGB**  
- **Buzzer** passivo  
- **Joystick** analógico  
- **Dois botões** físicos  

💾 **Como Compilar e Executar o Código**  
1. Instalar as dependências: **SDK do Raspberry Pi Pico**, **CMake**, **Compilador GCC para ARM**, entre outros.  
2. Configurar o **VS Code** com as extensões **C/C++** e **Raspberry Pi Pico Project**.  
3. Incluir as bibliotecas necessárias, como `hardware/dma.h` e `hardware/pio.h`.  
4. Compilar o código usando CMake e gerar o arquivo `.uf2`.  
5. Conectar a placa ao PC via USB, entrar no modo **BOOTSEL**, e copiar o arquivo `.uf2` para a unidade montada.  

⚡ **Pinagem dos Dispositivos Utilizados**  
- **Display OLED SSD1306** → Comunicação via **I2C1 (pinos GP26 e GP27)**  
- **Matriz de LEDs WS2812B** → **Pino GP0**  
- **LED RGB** → Pinos **GP13, GP14 e GP15**  
- **Buzzer** → **Pino GP16 (PWM)**  
- **Joystick** → **Eixo X (GP26), Eixo Y (GP27), Botão (GP22)**  
- **Botões físicos** → **GP18 e GP19**  

📈 **Resultados Esperados ou Obtidos**  
O projeto foi implementado com sucesso, permitindo que todas as funcionalidades fossem aplicadas. No entanto, algumas limitações da placa BitDogLab impactaram o desempenho, como a resposta mais lenta dos botões e a demora na atualização do display. Também foram observados travamentos e imagens distorcidas no display ao desconectar o cabo USB. Apesar dessas limitações, a integração entre os componentes ocorreu conforme esperado, tornando o projeto confiável e replicável. Além disso, há possibilidade de expansão, permitindo novas funcionalidades e otimizações no futuro.