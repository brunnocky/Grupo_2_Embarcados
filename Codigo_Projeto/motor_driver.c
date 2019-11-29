#include <msp430.h> 
#include <msp430f5529.h>
#include "motorDrivers.h"

/**
 * main.c
 */

void motor_init(){
    P1DIR |= IN1 + IN2 + IN3 + IN4;         //(IN1 E IN2) MOTOR TRASEIRO //(IN3 E IN4) MOTOR DIANTEIRO
    TA0CCR0 |= 255;
    TA0CCTL1 |= OUTMOD_7;
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

void velocidadeMotor(int speed){
    TA0CCR1 |= speed % 50;
    P1SEL |= BIT2;
    //P1SEL |= BIT3;
}

