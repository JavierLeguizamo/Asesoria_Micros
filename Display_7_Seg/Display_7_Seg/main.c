
#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

#define DIRECCION_PB DDRB
#define TODOS_BITS_SALIDAS 0xFF
#define ESCRIBIR_DISPLAY(VALOR) PORTB = VALOR
#define LEER_PIN_PC(PIN) (PINC & 1<<PIN)
#define CERO 0x3F
#define UNO 0x06
#define TWO 0X5B
#define Three 0X60
#define four 0XFF
unsigned char numero[]={CERO,UNO,TWO,Three,four};

int main(void)
{
    DIRECCION_PB |= TODOS_BITS_SALIDAS;
	DDRC &= ~(1<<DDC0);
	while (!LEER_PIN_PC(PINC0));//Boton de start
	uint8_t state = 1;
    while (1) 
    {
		if(LEER_PIN_PC(PINC0)){
			state = 1;
		}
		
		while(state == 1){
			for (int i = 0; i<=4; i++)
			{
				ESCRIBIR_DISPLAY(numero[i]);
				if (LEER_PIN_PC(PINC2))
				{
					state = 0;
					continue;
				}
				_delay_ms(500);
			}
			
		}
		ESCRIBIR_DISPLAY(0);
    }
}


