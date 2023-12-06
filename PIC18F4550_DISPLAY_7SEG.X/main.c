//AÑADIR POTENCIOMETRO Y ENTRADA ANALOGICA QUE MUESTRE VALORES EN EL LCD
#include <stdio.h>
#include "fuses.h"
#include "Setup.h"

#define _XTAL_FREQ 8000000

int D1=0,D2=0,D3=0,D4=0;
int prueba=0;


unsigned int ReadADC(unsigned char channel) {
    // Configura el canal de entrada
    ADCON0 = (channel << 2) | 0x01; // Configura el canal y habilita el ADC
    GO_nDONE = 1; // Inicia la conversión
    while (GO_nDONE); // Espera a que termine la conversión 
    return ((ADRESH << 8) | ADRESL); // Retorna el resultado de la conversión
}

void DISPLAY_7SEG(int x){
    switch (x) {
        case 0:
            LATD =0b11000000;
            break;
        case 1:
            LATD =0b11111001;
            break;
        case 2:
            LATD =0b10100100;
            break;
        case 3:
            LATD =0b10110000;
            break;
        case 4:
            LATD =0b10011001;
            break;
        case 5:
            LATD =0b10010010;
            break;
        case 6:
            LATD =0b10000010;
            break;
        case 7:
            LATD =0b11111000;
            break;
        case 8:
            LATD =0b10000000;
            break;
        case 9:
            LATD =0b10010000;
            break;
        default:
            break;
    }
}

void MOSTRAR_DISPLAY(){
    
    prueba=ReadADC(0);           // El valor del 0 denota el puerto adc del micro 
    D1 = prueba / 1000;          // Digito 1 
    D2 = (prueba / 100) % 10;    // Digito 2 
    D3 = (prueba / 10) % 10;     // Digito 3 
    D4 = prueba % 10;            // Digito 4 
    __delay_ms(5);
    DISPLAY_7SEG(D1);
    LATB =0b00001110;           // PRENDE CON TIERRA
    __delay_ms(5);
    DISPLAY_7SEG(D2);
    LATB =0b00001101;
    __delay_ms(5);
    DISPLAY_7SEG(D3);
    LATB =0b00001011;
    __delay_ms(5);
    DISPLAY_7SEG(D4);
    LATB =0b00000111;
    __delay_ms(5);
}

void main(void){
    Setup();
    while(1){
        MOSTRAR_DISPLAY();
    }
    return;
}