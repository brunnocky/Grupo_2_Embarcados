/*
 * main.c
 *
 *  Created on: 20 de nov de 2019
 *      Author: Milena & Brunno
 */

#include <msp430f5529.h>
#include <msp430.h>
#include <stdint.h>
#include "motorDrivers.h"

extern void LedFrenteAcende(void);
extern void LedFrenteApaga(void);
extern void LedTraseiraAcende(void);
extern void LedTraseiraApaga(void);

/**
 * main.c
 */
int main(void)
{

       WDTCTL = WDTPW | WDTHOLD;                 //stop watchdog timer

       //LEDS
       P6DIR |= BIT1+BIT2;                       //LED's Frente
       P2DIR |= BIT4+BIT5;                       //LED's Traseira
       P8DIR |= BIT2;

       //CONTROLE BLUETOOTH
       P3SEL |= BIT3+BIT4;                       // P3.3,3.4 = USCI_A1 TXD/RXD
       UCA0CTL1 |= UCSWRST;                      // **Estado da máquina em reset**
       UCA0CTL1 |= UCSSEL_2;                     // SMCLK
       UCA0BR0 = 109;                              // 1MHz 115200 
       UCA0BR1 = 0;                              // 1MHz 115200
       UCA0MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
       UCA0CTL1 &= ~UCSWRST;                     // **Inicializa estado USCI da máquina**


    //CONTROLE UTILIZANDO INTERRUPÇÃO
    UCA0IE |= UCRXIE;                         // Habilita interrupção USCI_A1 RX

   __bis_SR_register(LPM0_bits + GIE);       // Entre LPM0, interrupção habilitada
   __no_operation();                        // Para debugger

}

 // Segura o caractere RX, confirma se o TX buffer está pronto primeiro

  #pragma vector=USCI_A0_VECTOR
 __interrupt void USCI_A0_ISR(void)
 {
     UCA0IFG &= ~UCRXIFG;
     if(UCA0RXBUF == 'F'){ //Frente
         motor_init();
         motorFrente();

     }else if(UCA0RXBUF == 'B'){ // Ré
         motor_init();
         motorRe();

     }else if(UCA0RXBUF == 'I'){//FrenteDireita
         motor_init();
         DirecaoFrenteDireita();

     }else if(UCA0RXBUF == 'S'){ //Parar
         motor_init();
         motorParar();

     }else if(UCA0RXBUF == 'G'){ //FrenteEsquerda
         motor_init();
         DirecaoFrenteEsquerda();

     }else if(UCA0RXBUF == 'L'){ //Esquerda
         motor_init();
         motorEsquerda();

     }else if(UCA0RXBUF == 'R'){ //Direita
         motor_init();
         motorDireita();

     }else if(UCA0RXBUF == 'H'){//ReEsquerda
         motor_init();
         DirecaoReEsquerda();

     }else if(UCA0RXBUF == 'J'){//ReDireita
         motor_init();
         DirecaoReDireita();

     }else if(UCA0RXBUF == 'W'){
         LedFrenteAcende();

     }else if(UCA0RXBUF == 'w'){
         LedFrenteApaga();

     }else if(UCA0RXBUF == 'U'){
         LedTraseiraAcende();

     }else if(UCA0RXBUF == 'u'){
         LedTraseiraApaga();

     }else if(UCA0RXBUF == 'V'){

             play();
     }/*else if(UCA0RXBUF == 'X'){
         motor_init();
         velocidadeMotor(0.10);

 }*/

 }

