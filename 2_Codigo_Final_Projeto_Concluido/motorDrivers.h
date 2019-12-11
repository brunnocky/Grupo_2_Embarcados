/*
 * motorDrivers.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: Milena
 */

//#ifndef MOTORDRIVERS_H_
//#define MOTORDRIVERS_H_
#define IN1 BIT2
#define IN2 BIT3
#define IN3 BIT4
#define IN4 BIT5
//#define ENABLE BIT2

//Notas musicais
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

void motor_init();
void motorFrente();
void motorRe();
void motorParar();
void motorDireita();
void motorEsquerda();
void DirecaoFrenteDireita();
void DirecaoFrenteEsquerda();
void DirecaoReDireita();
void DirecaoReEsquerda();
void velocidadeMotor();
void play();

//#endif /* MOTORDRIVERS_H_ */
