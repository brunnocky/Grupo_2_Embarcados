/*
 * motorDrivers.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: Milena & Brunno
 */

//#ifndef MOTORDRIVERS_H_
//#define MOTORDRIVERS_H_
#define IN1 BIT2
#define IN2 BIT3
#define IN3 BIT4
#define IN4 BIT5

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
//#endif /* MOTORDRIVERS_H_ */
