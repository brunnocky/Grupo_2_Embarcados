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

//Velocidade do motor ainda precisa de otimiza��o

int main(void)
{

       WDTCTL = WDTPW | WDTHOLD;                 //stop watchdog timer

       //LEDS
       P6DIR |= BIT1+BIT2;                       //LED's Frente
       P2DIR |= BIT4+BIT5;                       //LED's Traseira

       //CONTROLE BLUETOOTH
       P3SEL |= BIT3+BIT4;                       // P3.4,3.3 = USCI_A1 TXD/RXD
       UCA0CTL1 |= UCSWRST;                      // **Estado da m�quina em reset**
       UCA0CTL1 |= UCSSEL_2;                     // SMCLK
       UCA0BR0 = 109;                              // 1MHz 115200 
       UCA0BR1 = 0;                              // 1MHz 115200
       UCA0MCTL |= UCBRS_1 + UCBRF_0;            // Modula��o UCBRSx=1, UCBRFx=0
       UCA0CTL1 &= ~UCSWRST;                     // **Inicializa USCI no estado da m�quina**
  /* while(1)
   {
       if(UCA0RXBUF == 'F') //Frente
                {


                       P1OUT |= BIT0;
                       P4OUT &=~ BIT7;
                       motor_init();
                       motorFrente();

                }
        else if(UCA0RXBUF == 'B') // R�
              {

                    P1OUT &=~ BIT0;
                    P4OUT |= BIT7;
                    motor_init();
                    motorRe();

              }
        else if(UCA0RXBUF == 'I'){//FrenteDireita
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
        }

   }*/

    //CONTROLE UTILIZANDO INTERRUP��O
    UCA0IE |= UCRXIE;                         // Habilita interrup��o USCI_A1 RX

   __bis_SR_register(LPM0_bits + GIE);       // Entra com LPM0, Interrup��o habilitada
   __no_operation();                        // Para debugger
}

 // Guarda o caractee RXed, confirma se TX buffer est� pronto primeiro

  #pragma vector=USCI_A0_VECTOR
 __interrupt void USCI_A0_ISR(void)
 {
     UCA0IFG &= ~UCRXIFG;
     if(UCA0RXBUF == 'F'){ //Frente
         motor_init();
         motorFrente();

     }else if(UCA0RXBUF == 'B'){ // R�
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

     }else if(UCA0RXBUF == '2'){
         motor_init();
         motorFrente();
         velocidadeMotor();
         __delay_cycles(2500);


     }
 }



