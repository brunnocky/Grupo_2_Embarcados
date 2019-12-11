#define Direita_Sensor    P6_1    //define a porta de entrada para o sensor IR da direita
#define Esquerda_Sensor   P6_2    //define a porta de entrada para o sensor IR da esquerda

int pinos[4] = {P1_2,P1_3,P1_4,P1_5};    //define um vetor de saida para o Driver do motor

#define frente    0x05  
#define esquerda  0x06  
#define direita   0x09
#define parar     0x00

//#define activeLowMode            //Presumindo que os sensores são ativos em HighMode

#ifdef  activeLowMode
  int resultado[4] = {frente,esquerda,direita,parar};
#else
  int resultado[4] = {parar,direita,esquerda,frente};
#endif


//Abaixo será direcionado os sensores e os pinos do motor

void setup() {
  for(int i = 0; i < 4; i++)
    pinMode(pinos[i], OUTPUT);
    pinMode(Direta_Sensor, INPUT);
    pinMode(Esquerda_Sensor, INPUT);
}

//Abaixo faz a verificação das entrada e envia a saida para o driver do motor

void loop() {
  int sentido = (digitalRead(Esquerda_sensor) << 1) | digitalRead(Direita_sensor); //desloca Esqueda_Sensor uma casa a esquerda
  for(int i = 0; i < 4; i++)
    digitalWrite(pinos[i], (resultado[sentido] >> i) & 0x01); 
}
//Branco - 1; Preto - 0
// Entradas             Resultado         Movimento
//EsqS    DirS        MEsq     MDir           -
//0         0          00       00          Parar        
//0         1          10       00          Direita
//1         0          00       10          Esquerda
//1         1          10       10          Frente
