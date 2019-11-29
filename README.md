# Grupo_2_Embarcados
# **Carrinho controlado por microcontrolador via bluetooth**

### 
Este projeto tem como objetivo desenvolver um carrinho controlador por bluetooth. O carrinho possui dois motores DC, sendo um responsável
pelos movimentos (FRENTE & RÉ) e o outro pelos movimentos (ESQUERDA & DIREITA). Também serão utilizados um microcontrolador (MSP430F5529),
driver para motor DC (L298n) e um módulo bluetooth (HC - 05). 

O microcontrolador será responsável por interpretar os comandos recebidos pelo módulo bluetooth e logo após, o microcontrolador enviará a
lógica correspondente ao comando recebido para o driver, que interpretará essa lógica e rotacionará um dos motores.

O aplicativo usado para enviar os comandos ao módulo bluetooth será o BLUETOOTH RC CONTROLLER, que possui os camandos de direções, ascender
LED's e direções com acelerômetro do celular.

