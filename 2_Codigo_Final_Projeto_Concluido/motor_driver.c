#include <msp430.h> 
#include <msp430f5529.h>
#include "motorDrivers.h"

/**
 * main.c
 */

void motor_init(){
    P1DIR |= IN1 + IN2 + IN3 + IN4;         //(IN1 E IN2) MOTOR TRASEIRO //(IN3 E IN4) MOTOR DIANTEIRO
    //P2DIR |= ENABLE;
   // P2OUT |= BIT0;
    TA0CCR0 |= 255;
    TA0CCTL1 |= OUTMOD_6;
    TA0CTL |= TASSEL_2 + MC_1;
}

void motorRe(){
    P1OUT |= IN1;
    P1OUT &= ~IN2;
    P1OUT &= ~IN3;
    P1OUT &= ~IN4;
}

void motorFrente(){
    P1OUT |= IN2;
    P1OUT &= ~IN1;
    P1OUT &= ~IN3;
    P1OUT &= ~IN4;
}

void motorParar(){
    P1OUT &= ~IN1;
    P1OUT &= ~IN2;
    P1OUT &= ~IN3;
    P1OUT &= ~IN4;
}

void motorDireita(){
    P1OUT &= ~IN2;
    P1OUT &= ~IN1;
    P1OUT |= IN3;
    P1OUT &= ~IN4;
}

void motorEsquerda(){
    P1OUT &= ~IN2;
    P1OUT &= ~IN1;
    P1OUT |= IN4;
    P1OUT &= ~IN3;
}

void DirecaoFrenteDireita(){
    P1OUT |= IN2;
    P1OUT &= ~IN1;
    P1OUT |= IN3;
    P1OUT &= ~IN4;
}

void DirecaoFrenteEsquerda(){
    P1OUT |= IN2;
    P1OUT &= ~IN1;
    P1OUT |= IN4;
    P1OUT &= ~IN3;
}

void DirecaoReDireita(){
    P1OUT |= IN1;
    P1OUT &= ~IN2;
    P1OUT |= IN3;
    P1OUT &= ~IN4;
}

void DirecaoReEsquerda(){
    P1OUT |= IN1;
    P1OUT &= ~IN2;
    P1OUT |= IN4;
    P1OUT &= ~IN3;
}

/*void velocidadeMotor(int speed){

    TA0CCR1 |= speed * 255;
    P1SEL |= BIT0;


}*/
void delay_ms(unsigned int ms )
{
    unsigned int i;
    for (i = 0; i<= ms; i++)
       __delay_cycles(500); //SUSPENDE A EXECUCAO POR 500MS
}

void delay_us(unsigned int us )
{
    unsigned int i;
    for (i = 0; i<= us/2; i++)
       __delay_cycles(1);
}
void beep(unsigned int note, unsigned int duration)
{
    int i;
    long delay = (long)(10000/note);  //SEMIPERIODO DE CADA NOTA.
    long time = (long)((duration*100)/(delay*2));  //TEMPO TOTAL DE EXECUCAO DA NOTA
    for (i=0;i<time;i++)
    {
        P8OUT |= BIT2;     //PINO P1.2 SETADO
        delay_us(delay);   //DELAY DO SEMIPERIODO
        P8OUT &= ~BIT2;    //RESETA O ESTADO DO PINO
        delay_us(delay);   //DELAY DO SEMIPERIODO
    }
    delay_ms(20); //DELAY MINIMO PARA SEPARAR UMA NOTA DA OUTRA
}
void play(){

    beep(a, 500);
        delay_ms(100);
        beep(a, 500);
        delay_ms(100);
        beep(a, 500);
        delay_ms(100);
        beep(f, 350);
        delay_ms(100);
        beep(cH, 150);
        delay_ms(100);
        beep(a, 500);
        delay_ms(100);
        beep(f, 350);
        delay_ms(100);
        beep(cH, 150);
        delay_ms(100);
        beep(a, 650);
        delay_ms(100);

        delay_ms(350);
        //INVERTALO ENTRE PRIMEIRA E SEGUNDA PARTE

        beep(eH, 500);
        delay_ms(100);
        beep(eH, 500);
        delay_ms(100);
        beep(eH, 500);
        delay_ms(100);
        beep(fH, 350);
        delay_ms(100);
        beep(cH, 150);
        delay_ms(100);
        beep(gS, 500);
        delay_ms(100);
        beep(f, 350);
        delay_ms(100);
        beep(cH, 150);
        delay_ms(100);
        beep(a, 650);

        delay_ms(350);

        beep(aH, 500);
        delay_ms(100);
        beep(a, 300);
        delay_ms(100);
        beep(a, 150);
        delay_ms(100);
        beep(aH, 400);
        delay_ms(100);
        beep(gSH, 200);
        delay_ms(100);
        beep(gH, 200);
        delay_ms(100);
        beep(fSH, 125);
        delay_ms(100);
        beep(fH, 125);
        delay_ms(100);
        beep(fSH, 250);

        delay_ms(250);

        beep(aS, 250);
        delay_ms(100);
        beep(dSH, 400);
        delay_ms(100);
        beep(dH, 200);
        delay_ms(100);
        beep(cSH, 200);
        delay_ms(100);
        beep(cH, 125);
        delay_ms(100);
        beep(b, 125);
        delay_ms(100);
        beep(cH, 250);

        delay_ms(250);

        beep(f, 125);
        delay_ms(100);
        beep(gS, 500);
        delay_ms(100);
        beep(f, 375);
        delay_ms(100);
        beep(a, 125);
        delay_ms(100);
        beep(cH, 500);
        delay_ms(100);
        beep(a, 375);
        delay_ms(100);
        beep(cH, 125);
        delay_ms(100);
        beep(eH, 650);

        beep(aH, 500);
        delay_ms(100);
        beep(a, 300);
        delay_ms(100);
        beep(a, 150);
        delay_ms(100);
        beep(aH, 400);
        delay_ms(100);
        beep(gSH, 200);
        delay_ms(100);
        beep(gH, 200);
        delay_ms(100);
        beep(fSH, 125);
        delay_ms(100);
        beep(fH, 125);
        delay_ms(100);
        beep(fSH, 250);

        delay_ms(250);

        beep(aS, 250);
        delay_ms(100);
        beep(dSH, 400);
        delay_ms(100);
        beep(dH, 200);
        delay_ms(100);
        beep(cSH, 200);
        delay_ms(100);
        beep(cH, 125);
        delay_ms(100);
        beep(b, 125);
        delay_ms(100);
        beep(cH, 250);

        delay_ms(250);

        beep(f, 250);
        delay_ms(100);
        beep(gS, 500);
        delay_ms(100);
        beep(f, 375);
        delay_ms(50);
        beep(cH, 125);
        delay_ms(100);
        beep(a, 500);
        delay_ms(100);
        beep(f, 375);
        delay_ms(100);
        beep(cH, 125);
        delay_ms(100);
        beep(a, 650);


}



