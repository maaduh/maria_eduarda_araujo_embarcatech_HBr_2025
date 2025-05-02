<H1>Contador Decrescente com Interrupção </H1>
Este projeto em C implementa um contador decrescente controlado por interrupção. Ao pressionar o Botão A (GPIO5), o contador reinicia em 9 e começa a diminuir de 1 em 1 a cada segundo, exibindo os valores no display OLED. Durante a contagem, o sistema registra quantas vezes o Botão B (GPIO6) é pressionado. Quando o contador chega a 0, ele congela e mostra o total de cliques no Botão B. O sistema só reinicia após nova pressão no Botão A, reiniciando a contagem e zerando o número de cliques.







