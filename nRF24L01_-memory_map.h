/*                  e-gadget.header
 * nRF24L01_memory_map.h
 *
 *  Created on: 2015-03-07
 *    Modyfied: 2015-04-13 21:18:47
 *      Author: Nefarious19
 *
 * Project name: "NRF24"
 *
 *	This is AVR GCC library for nRF24L01 module, ver. 1.0
 *	It can be only used by REGISTERED USERS of www.forum.atnel.pl, 
 *	they must only leave this header in they C code.
 *	
 *	Library code was based on the libraries from the books:
 *	
 *	https://www.sklep.atnel.pl/pl/p/AVR-Microcontrollers-C-Programming-Basics-EN-BOOK-DVD/103
 *	https://www.sklep.atnel.pl/pl/p/Jezyk-C-Pasja-programowania-mikrokontrolerow-8-bitowych-Wydanie-II-Ksiazka-DVD/104
 *	
 *	"
 *	
 *	This library uses also some ideas from:
 *	
 *	http://gizmosnack.blogspot.com/2013/04/tutorial-nrf24l01-and-avr.html
 *	http://www.tinkerer.eu/AVRLib/nRF24L01/
 *
 *
 */

#ifndef NRF24L01_MEMORY_MAP_H_
#define NRF24L01_MEMORY_MAP_H_


/////////////////////////////////////////////
//  SWITCHES definitions
/////////////////////////////////////////////
///////////////////
#define ON   1
#define OFF  2
///////////////////
#define TWO_BYTES 2
#define ONE_BYTE  1
///////////////////
#define ACK_ON    1
#define ACK_OFF   2
///////////////////



//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''//
//REGISTERS LIST OF nRF24L01 - SPIS REJESTRÓW MODU£U nRF24L01//
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,//
#define CONFIG      0x00     //CONFIGURATION REGISTER  -  REJESTR CONFIGURACYJNY
#define EN__AA      0x01     //ENABLE AUTO ACKNOWLEDGEMENT - W£¥CZ AUTOMATYCZNE POTWIERDZENIE DOTARCIA PAKIETU
#define EN_RXADDR   0x02     //ENABLE RX ADRESSES - W£¥CZONE ADRESY ODBIORCZE DLA STRUMIENI DANYCH (0 - 5 DATA PIPES)
#define SETUP_AW    0x03	 //SETUP ADRESSE WIDTH - USTAL D£UGOC ADRESU (3-5 BAJTÓW) WSPÓLNE DLA KA¯DEGO Z 6 STRUMIENI DANYCH (DATA PIPES)
#define SETUP_RETR  0x04	 //SETUP RETRANSMISON - USTAW CZAS PONOWNEJ RETRANSMISJI PAKIETU
#define RF_CH       0x05     //CHANNEL - KANA£ NA JAKIM JEST NADAWANIE
#define RF_SETUP    0x06     //TRANSMISSION SETTINGS - USTAWIENIA TRANSMISJI
#define STATUS      0x07     //STATUS REGISTER - REJESTR STATUSU
#define OBSERVE_TX  0x08     //TRANSMIT OBSERVE REGISTER - OBSERWACJA STANU NADAWANIA
#define RPD         0x09     //RECIVED POWER DETECTOR - WYKRYWANIE MOCY NADAWANEGO SYGNA£U
#define RX_ADDR_P0  0x0A     //RECEIVER ADDRES FOR DATA PIPE 0 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 0
#define RX_ADDR_P1  0x0B	 //RECEIVER ADDRES FOR DATA PIPE 1 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 1
#define RX_ADDR_P2  0x0C	 //RECEIVER ADDRES FOR DATA PIPE 2 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 2
#define RX_ADDR_P3  0x0D	 //RECEIVER ADDRES FOR DATA PIPE 3 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 3
#define RX_ADDR_P4  0x0E	 //RECEIVER ADDRES FOR DATA PIPE 4 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 4
#define RX_ADDR_P5  0x0F     //RECEIVER ADDRES FOR DATA PIPE 5 - ADRES ODBIORCZY DLA STRUMIENIA DANYCH NR 5
#define TX_ADDR     0x10     //TRANSMITER ADDRES - ADRES NADAWCZY MODU£U
#define RX_PW_P0	0x11     //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 0 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 0
#define RX_PW_P1	0x12	 //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 1 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 1
#define RX_PW_P2	0x13	 //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 2 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 2
#define RX_PW_P3	0x14	 //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 3 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 3
#define RX_PW_P4	0x15	 //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 4 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 4
#define RX_PW_P5	0x16	 //RECEIVER PAYLOAD WIDTH FOR DATA PIPE 5 - D£UGOC ODEBRANEGO PAKIETU ZE STRUMIENIA DANYCH 5
#define FIFO_STATUS 0x17     //FIFO STATUS - STATUS STOSÓW NADAWCZYCH I ODBIORCZYCH
#define DYNPD       0x1C     //DYNAMIC PAYLOAD WIDTH - DYNAMICZNA SZEROKOC RAMKI DANYCH
#define FEATURE     0x1D     //FEATURE REGISTER - REJESTR Z FICZERAMI


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""//
//LIST OF CONFIGURATION BITS IN EACH REGISTER - LISTA BITÓW KONFIGURACYJNYCH W KA¯DYM REJESTRZE//
//.............................................................................................//

// |CONFIG|
#define MASK_RX_DR       6  //1-OFF, 0-ON INTERRUPT ON IRQ IF RECIVED DATA READY  -  1-WY£¥CZ, 0-W£¥CZ PRZERWANIE NA PINIE IRQ GDY ODEBRANE DANE GOTOWE
#define MASK_TX_DS       5  //1-OFF, 0-ON INTERRUPT ON IRQ IF DATA TRANSMITED SUCCESFULLY   -  1-WY£¥CZ, 0-W£¥CZ PRZERWANIE NA PINIE IRQ GDY DANE WYS£ANO POMYLNIE
#define MASK_MAX_RT      4  //1-OFF, 0-ON INTERRUPT ON IRQ IF MAXIMUM ACCOUNT OF RETRANSMISIONS IS ACHIVED  -  1-WY£¥CZ, 0-W£¥CZ PRZERWANIE NA PINIE IRQ GDY PRZEKROCZONO MAKSYMALN¥ LICZBE RETRANSMISJI PAKIETU
#define EN_CRC           3  //ENABLE CRC - W£¥CZ SUME KONTROLN¥ CRC
#define CRCO             2  //CRC ENCHODING SCHEME - IF 0 -> crc == 1 BYTE; IF 1 CRC == 2 BYTES; LICZBA BAJTÓW UMY KONTROLNEJ CRC: JE¯ELI 0 -> CRC TO 1 BAJT, JE¯ELI 1 -> CRC TO 2 BAJTY
#define PWR_UP           1  //1 - POWER UP, 0 - POWER DOW; 1 - W£¥CZ MODU£, 0 - WY£¥CZ MODU£
#define PRIM_RX          0  //RX/TX CONTROL: 1 - RECEIVING, 0 - TRANSMITING; KONTROLA ODBIÓR/NADAWANIE: 1 - OBIÓR, 0 - NADAWANIE

// |EN_AA|
#define ENAA_P5     	 (1<<5)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 5 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 5
#define ENAA_P4     	 (1<<4)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 4 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 4
#define ENAA_P3     	 (1<<3)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 3 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 3
#define ENAA_P2     	 (1<<2)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 2 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 2
#define ENAA_P1     	 (1<<1)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 1 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 1
#define ENAA_P0     	 (1<<0)  //ENABLE AUTO ACKNOWLEDGEMENT DATA PIPE 0 - W£¥CZ AUTOMATYCZNE POTWIERDZENIA POPRAWNEGO NDANIA/ODBIORU PAKIETU DLA STRUMIENIA DANYCH NR 0

// |EN_RXADDR|
#define ERX_P5           (1<<5)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5
#define ERX_P4           (1<<4)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5
#define ERX_P3           (1<<3)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5
#define ERX_P2           (1<<2)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5
#define ERX_P1           (1<<1)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5
#define ERX_P0           (1<<0)  //ENABLE DATA PIPE 5 - W£¥CZ STRUMIEÑ DANYCH NR 5

// |SETUP_AW|
#define AW_3BYTE         1  //ADDRES WIDTH = 3 BYTES; SZEROKOC ADRESU = 3 BAJTY
#define AW_4BYTE         2  //ADDRES WIDTH = 4 BYTES; SZEROKOC ADRESU = 4 BAJTY
#define AW_5BYTE         3  //ADDRES WIDTH = 5 BYTES; SZEROKOC ADRESU = 5 BAJTÓW

// |SETUP_RETR|

//IN THE FIRST HALF OH THIS REGISTER (ARD) WE'RE SETTING TIME BEETWEN RETRANSMISSIONS
#define WAIT_4000uS   0xF0  //4000 microseconds - 4000 mikrosekund
#define WAIT_3750uS   0xE0  //3750 microseconds - 3750 mikrosekund
#define WAIT_3500uS   0XD0  //3500 microseconds - 3500 mikrosekund
#define WAIT_3250uS   0xC0  //3250 microseconds - 3250 mikrosekund
#define WAIT_3000uS   0xB0  //3000 microseconds - 3000 mikrosekund
#define WAIT_2750uS   0xA0  //2750 microseconds - 2750 mikrosekund
#define WAIT_2500uS   0x90  //2500 microseconds - 2500 mikrosekund
#define WAIT_2225uS   0x80  //2250 microseconds - 2250 mikrosekund
#define WAIT_2000uS   0x70  //2000 microseconds - 2000 mikrosekund
#define WAIT_1750uS   0x60  //1750 microseconds - 1750 mikrosekund
#define WAIT_1500uS   0x50  //1500 microseconds - 1500 mikrosekund
#define WAIT_1250uS   0x40  //1250 microseconds - 1250 mikrosekund
#define WAIT_1000uS   0x30  //1000 microseconds - 1000 mikrosekund
#define WAIT_750uS    0x20  //750 microseconds -  750 mikrosekund
#define WAIT_500uS    0x10  //500 microseconds -  500 mikrosekund
#define WAIT_250uS    0x00  //250 microseconds -  250 mikrosekund

//IN THE SECOND HALF OF THIS REGISTER (ARC) WE'RE SETTING NUMBER OF RETRANSMISSIONS
#define RETR_15_TIMES 0x0F  //15 RETRANSMISSIONS - 15 RETRANSMISJI
#define RETR_14_TIMES 0x0E	//14 RETRANSMISSIONS - 14 RETRANSMISJI
#define RETR_13_TIMES 0x0D  //13 RETRANSMISSIONS - 13 RETRANSMISJI
#define RETR_12_TIMES 0x0C	//12 RETRANSMISSIONS - 12 RETRANSMISJI
#define RETR_11_TIMES 0x0B	//11 RETRANSMISSIONS - 11 RETRANSMISJI
#define RETR_10_TIMES 0x0A	//10 RETRANSMISSIONS - 10 RETRANSMISJI
#define RETR_9_TIMES  0x09	//9  RETRANSMISSIONS - 9  RETRANSMISJI
#define RETR_8_TIMES  0x08  //8  RETRANSMISSIONS - 8  RETRANSMISJI
#define RETR_7_TIMES  0x07  //7  RETRANSMISSIONS - 7  RETRANSMISJI
#define RETR_6_TIMES  0x06  //6  RETRANSMISSIONS - 6  RETRANSMISJI
#define RETR_5_TIMES  0x05  //5  RETRANSMISSIONS - 5  RETRANSMISJI
#define RETR_4_TIMES  0x04  //4  RETRANSMISSIONS - 4  RETRANSMISJI
#define RETR_3_TIMES  0x03  //3  RETRANSMISSIONS - 3  RETRANSMISJI
#define RETR_2_TIMES  0x02  //2  RETRANSMISSIONS - 2  RETRANSMISJI
#define RETR_1_TIME   0x01  //1  RETRANSMISSIONS - 1  RETRANSMISJI
#define RETR_0_TIMES  0X00  //0  RETRANSMISSIONS - 0  RETRANSMISJI
#define RETR_DISABLED 0X00  //0  RETRANSMISSIONS - 0  RETRANSMISJI

// |RF_SETUP|
#define CONT_WAVE        7  //CONTINOUS CARRIER TRANSMIT - CI¥G£E NADAWANIE NONEJ
#define RF_DR_LOW        5  //RF DATA RATE LOW  - M£ODSZY BIT W DWUBITOWYM "S£OWIE" DO USTAWIANIA PRÊDKOCI TRANSMISJI
#define RF_DR_HIGH       3  //RF DATA RATE HIGH - STARSZY BIT W DWUBITOWYM "S£OWIE" DO USTAWIANIA PRÊDKOCI TRANSMISJI
#define PLL_LOCK         4  //FORCE PLL LOCK SIGNAL. ONLY USED IN TEST

#define RF_PWR_18dB        ( (0<<1) | (0<<2) )    //SIGNAL POWER - -18dB
#define RF_PWR_12dB        ( (0<<1) | (1<<2) )    //SIGNAL POWER - -12dB
#define RF_PWR_6dB         ( (1<<1) | (0<<2) )	  //SIGNAL POWER - -6dB
#define RF_PWR_0dB         ( (1<<1) | (1<<2) )    //SIGNAL POWER -  08dB

#define TRANS_SPEED_2MB    ( (0<<RF_DR_LOW) | (1<<RF_DR_HIGH) )  //TRANSMISION SPEED 2MBITS/SECOND
#define TRANS_SPEED_1MB    ( (0<<RF_DR_LOW) | (0<<RF_DR_HIGH) )  //TRANSMISION SPEED 1 MBIT/SECOND
#define TRANS_SPEED_250kB    (1<<RF_DR_LOW)  					 //TRANSMISION SPEED 250 KBIT/SECOND

// |STATUS|
#define RX_DR       6     //RECIVED DATA READY - ODEBRANE DANE S¥ GOTOWE
#define TX_DS       5     //TRASMITED DATA SENT - WYS£ANO POPRAWNIE DANE
#define MAX_RT      4     //MAXIMUM ACCOUNT OF RETRANSMISION ACHIVED - OSIAGNIÊTO MAKSYMALN¥ ILOSC RETRANSMISJI
#define TX_FULL     0     //TX FIFO IS FULL - BUFOR NADAWCZY JEST PE£NY

#define RX_PIPE_0   ( (0<<3) | (0<<2) | (0<<1) )
#define RX_PIPE_1   ( (0<<3) | (0<<2) | (1<<1) )
#define RX_PIPE_3   ( (0<<3) | (1<<2) | (1<<1) )
#define RX_PIPE_4   ( (1<<3) | (0<<2) | (0<<1) )
#define RX_PIPE_5   ( (1<<3) | (0<<2) | (1<<1) )

// |OBSERVE_TX|
#define PLOS_CNT    4	//FIRST BIT OF LOST PACKET COUNTER
#define ARC_CNT     0	//FIRST BIT OF RETRANSMITTED PACKET COUNTER

// |FIFO_STATUS|
#define TX_REUSE    6    //REUSE TX FIFO PAYLOAD  -  TO SET THIS BIT USE " REUSE_TX_PAYLOAD "; DATA AVALIABLE IN TX FIFO WILL BE SENT
#define FULL_TX     5    //TX FIFO IS FULL FLAG   - FLAGA OZNACZAJ¥CA ¯E BUFOR NADAWCZY JEST PE£NY
#define TX_EMPTY    4    //TX IS EMPTY FLAG - FLAGA OZNACZAJ¥CA PUSTY BUFOR NADAWCZY
#define RX_FULL     1    //RX IS FULL FLAG - FLAGA OZNACZAJ¥CA ¯E BUFOR ODBIORCZY JEST PE£NY
#define RX_EMPTY    0    //RX IS EMPTY FLAG - FLAGA OZNACZAJ¥CA PUSTY BUFOR ODBIORCZY

// |DYNPD|

#define DPL_P5		(1<<5)	//DYNAMIC PAYLOAD ON DATAPIPE 5
#define DPL_P4		(1<<4)	//DYNAMIC PAYLOAD ON DATAPIPE 4
#define DPL_P3		(1<<3)	//DYNAMIC PAYLOAD ON DATAPIPE 3
#define DPL_P2		(1<<2)	//DYNAMIC PAYLOAD ON DATAPIPE 2
#define DPL_P1		(1<<1)	//DYNAMIC PAYLOAD ON DATAPIPE 1
#define DPL_P0		(1<<0)	//DYNAMIC PAYLOAD ON DATAPIPE 0


// |FEATURE|

#define EN_DPL      2		//ENABLE DYNAMIC PAYLOAD
#define EN_ACK_PAY  1		//ENABLE PAYLOADS WHICH CAN BE SEND WITH ACK PACKET
#define EN_DYN_ACK  0		//ENABLE POSSIBILITY OF USING W_TX_PAYLOAD_NO_ACK COMMAND


//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''//
//nRF24L01 COMMAND LIST  -  LISTA KOMEND MODU£U nRF24L01                    //
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,//
#define W_ACK_PAYLOAD        0xA8	//WRITE PAYLOAD WITH ACK PACKET (USED IN RECEIVER WHEN YOU WANT RETURN ACK WITH SOME SPECIAL PACKET)
#define R_REGISTER           0x00   //READ REGISTER -- ODCZYTAJ REJESTR
#define W_REGISTER           0x20   //WRITE REGISTER -- ZAPISZ DO REJESTRU
#define REGISTER_MASK        0x1F	//CONSTANT USED TO MASKING REGISTERS
#define R_RX_PAYLOAD         0x61   //READ RX PAYLOAD -- ODCZYTAJ DANE Z BUFORA ODBIORCZEGO
#define W_TX_PAYLOAD  		 0xA0   //WRITE TX PAYLOAD -- ZAPISZ DANE DO BUFORA NADAWCZEGO
#define FLUSH_TX     		 0xE1   //FLUSH TX - WYCZYC BUFOR TX
#define FLUSH_RX     		 0xE2   //FLUSH RX - WYCZYC BUFOR RX
#define REUSE_TX_PL  		 0xE3   //REUSE TX PAYLOAD - WYSLIJ PONOWNIE DANE Z BUFORA TX
#define W_TX_PAYLOAD_NO_ACK	 0xB0	//SEND PACKET TO ANOTHER NRF WITHOUT ACK
#define NOP                  0xFF   //NOP - NIC NIE RÓB - PO WYS£ANIEU TEGO BAJTU NRF ZWRACA REJESTR STATUS
#define R_RX_PL_WID          0x60	//READ RX PAYLOAD WIDTH

#endif /* NRF24L01_MEMORY_MAP_H_ */











