
#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 1<<4 | 1<<5;//pinMode(4,OUTPUT);pinMode(5,OUTPUT);
	_delay_ms(500);
	PORTB = 1<<4 | 1<<5;//digitalWrite(4,HIGH);digitalWrite(5,HIGH);
	_delay_ms(500);
	PORTB &= ~(1<<4);//digitalWrite(4,LOW);
	_delay_ms(500);
	PORTB |= 1<<4 | 1<<5;//digitalWrite(4,HIGH);
    while (1) 
    {
    }
}

