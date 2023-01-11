/*
 * main.c
 *
 *      Author: Ewa Krzaczkowska
 *
 * Project name: "projekt inzynierski"
 *
 *
 *          MCU: ATmega8A
 *        F_CPU: 8 000 000 Hz
 *
 */

//biblioteki
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "nRF24L01.h"
#include "uart.h"

//stale
uint16_t odleglosc_cm=0;
uint16_t ile=0;
uint16_t ileus=0;
uint16_t duration=0;
unsigned char data;
//funkcje
void timer_init(void);
int pomiar_ultra(void);
static int pomiar_czas();

int main (void)
{

	//inicjalizacja USART tylko do testow
	//USART_Init();
	//USART_TransmitString("inicjalizacja\r\n");

	//inicjalizacja timera
	timer_init();

	//inicjalizacja modulu radiowego
  	nRF_init();
    	
   	//zezwolenie na przerwania
	sei();

	//wlaczenie NRF
    	nRF_TX_Power_Up();
	
	while(1)
	{
				
				odleglosc_cm = pomiar_ultra();
			
				if(odleglosc_cm>60) nRF_SendDataToAir("K");
				if(odleglosc_cm>50 && odleglosc_cm<60)nRF_SendDataToAir("trzy");		
				if(odleglosc_cm>40 && odleglosc_cm<50)nRF_SendDataToAir("szesc");		
				if(odleglosc_cm>30 && odleglosc_cm<40)nRF_SendDataToAir("dwana");		
				if(odleglosc_cm>20 && odleglosc_cm<30)nRF_SendDataToAir("szesn");		
				if(odleglosc_cm>10 && odleglosc_cm<20)nRF_SendDataToAir("dwadz");		
				if(odleglosc_cm>0 && odleglosc_cm<10)nRF_SendDataToAir("dwatr");		
						
				odleglosc_cm = 0;
				_delay_ms(10);
				
			
	}
}

//------------------------------czujnik ultradźwiękowy-------------------------------------------

//timer na 16bitowym
void timer_init(void){
	OCR1A=1250;
	TIMSK=(1<<OCIE1A); // zezwolenie na comp. od A
}

void timer_start(void){
	TCCR1B |=(1<<WGM12); //tryb CTC
	TCCR1B |=(1<<CS12); //prescaler
	TCNT1=0;
}

uint16_t timer_stop(void){
	TCCR1B=0;
	ile=TCNT1;	
	return ile*31.25; //skalowanie zeby us
}

ISR(TIMER1_COMPA_vect){
	//USART_TransmitString("przerwanie\r\n");
}

//--------------definiowanie ultradzwiekowego czujnika-----------------------

static int pomiar_czas(){
	
	while (!(PINB & (1<<PB1)));

	timer_start();
	while((PINB & (1<<PB1)));

	ileus=timer_stop();
	return ileus;
}


int pomiar_ultra(void){
	duration=0;
	ileus=0;
	ile=0;
	
	DDRB |= (1<<PB1); // D na wyjscie
	PORTB &= ~(1<<PB1);
	PORTB |= (1<<PB1); //stan wysoki na wyjscie pobudzenie czujnika
	_delay_us(8);
	PORTB &= ~(1<<PB1);
	DDRB &= ~(1<<PB1);  //D na wejscie odbieranie fali ECHO
	duration = pomiar_czas();
	odleglosc_cm =(duration)/29/2;
	return odleglosc_cm;
}
