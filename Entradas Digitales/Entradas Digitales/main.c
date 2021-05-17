#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

#define DIRECCION_PB DDRB
#define TODOS_BITS_SALIDAS 0xFF
#define ESCRIBIR_DISPLAY(VALOR) PORTB = VALOR
#define CERO 0x3F
#define UNO 0x06
#define TWO 0X5B
#define BIT_INICIO PINC3
#define LECTURA_BIT(BIT) (PINC & (1<<BIT))
unsigned char numero[]={CERO,UNO,TWO};

int main(void)
{
	DIRECCION_PB |= TODOS_BITS_SALIDAS;
	while(!LECTURA_BIT(BIT_INICIO));
	while (1)
	{
		for (int i = 0; i<=2; i++)
		{
			ESCRIBIR_DISPLAY(numero[i]);
			_delay_ms(500);
		}
	}
}
