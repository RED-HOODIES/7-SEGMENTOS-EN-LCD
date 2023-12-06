#include "Setup.h"


void SetupOscilador(void)
{
    
return;}

void Setupports(void)
{
    TRISB = 0x00; //SALIDA puerto B
    TRISD = 0x00; //SALIDA puerto D
return;}

void Setupint(void)
{
    
    return;}

void SetupADC (void)
{
    // Configuraci�n del m�dulo ADC
    ADCON0 = 0b00000001; // Habilita el ADC y selecciona AN1 como entrada
    ADCON1 = 0b00000000; // Configura referencias de voltaje y activa todos los pines como analogicos
    ADCON2 = 0b10001000; // Configura FADCK y velocidad de conversi�n
    
    return;}


void Setup(void)
{   
    SetupOscilador();
    Setupports();
    Setupint();
    SetupADC();
    
return;}


