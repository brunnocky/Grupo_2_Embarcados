; File:     LedFrente.asm
; *****************************************************************************

      .cdecls C,NOLIST,"msp430.h"       ; Processor specific definitions

       
;========================================================================
; Acende os dois led's da frente que correspode aos farois
;========================================================================
      .global    LedFrenteAcende              ; Declare symbol to be exported
      .sect ".text"                           	       ; Code is relocatable
LedFrenteAcende:    .asmfunc
        mov.b #00000110b, &P6OUT        ;Acende os faróis

   .if ($defined(__MSP430_HAS_MSP430XV2_CPU__) | $defined(__MSP430_HAS_MSP430X_CPU__))
        reta
   .else
        ret
   .endif
         .endasmfunc
;========================================================================
; Apaga os dois led's da frente que correspode aos farois
;========================================================================
        .global  LedFrenteApaga               ; Declare symbol to be exported
        .sect ".text"                                    ; Code is relocatable
LedFrenteApaga:   .asmfunc
        mov.b #00000000b, &P6OUT  

   .if ($defined(__MSP430_HAS_MSP430XV2_CPU__) | $defined(__MSP430_HAS_MSP430X_CPU__))
        reta
   .else
        ret
   .endif
        .endasmfunc

;========================================================================
; Acende os dois led's da traseira que correspode as lanternas
;========================================================================
        .global  LedTraseiraAcende              ; Declare symbol to be exported
        .sect ".text"                                       ; Code is relocatable
LedTraseiraAcende:   .asmfunc
        mov.b #00110000b, &P2OUT  

   .if ($defined(__MSP430_HAS_MSP430XV2_CPU__) | $defined(__MSP430_HAS_MSP430X_CPU__))
        reta
   .else
        ret
   .endif
        .endasmfunc

;========================================================================
; Apaga os dois led's da traseira que correspode as lanternas
;========================================================================
        .global  LedTraseiraApaga              ; Declare symbol to be exported
        .sect ".text"                                       ; Code is relocatable
LedTraseiraApaga:   .asmfunc
        mov.b #00000000b, &P2OUT  

   .if ($defined(__MSP430_HAS_MSP430XV2_CPU__) | $defined(__MSP430_HAS_MSP430X_CPU__))
        reta
   .else
        ret
   .endif
        .endasmfunc

        .end