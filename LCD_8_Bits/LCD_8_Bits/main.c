#define F_CPU 1e6
#include <avr/io.h>
#include <util/delay.h>

#define PORTC_MODE(MASK)	DDRC |= MASK
#define PORTB_MODE(MASK)	DDRB |= MASK
#define LCD_CTRL_PORT		PORTC
#define LCD_DATA_PORT		PORTB
#define RS					PORTC0
#define RW					PORTC1
#define E					PORTC2
#define ALL_BITS_OUT		0xFF

void lcdWriteRegister(uint8_t data)
{
	LCD_CTRL_PORT |= 1<<E;
	LCD_DATA_PORT = data;
	LCD_CTRL_PORT &= ~(1<<E);
}

void lcd_init()
{
	lcdWriteRegister(0x30);
	_delay_us(4500);
	lcdWriteRegister(0x30);
	_delay_us(100);
	lcdWriteRegister(0x30);
	_delay_ms(1);
	lcdWriteRegister(0x38);
	_delay_ms(1);
	lcdWriteRegister(0x8);
	_delay_ms(1);
	lcdWriteRegister(0x1);
	_delay_ms(1);
	lcdWriteRegister(0x6);
	_delay_ms(1);
	lcdWriteRegister(0xf);
	_delay_ms(1);
}

void lcdWriteChar(char c)
{
	LCD_CTRL_PORT |= 1<<RS | 1<<E;
	LCD_DATA_PORT = c;
	LCD_CTRL_PORT &= ~(1<<E);
	_delay_ms(1);
}

int main(void)
{
    PORTB_MODE(ALL_BITS_OUT);
	PORTC_MODE(_BV(RS)|_BV(RW)|_BV(E));//1<<DDC0
	
	lcd_init();
	lcdWriteChar('H');
	lcdWriteChar('o');
	lcdWriteChar('l');
	lcdWriteChar('a');
	LCD_CTRL_PORT = 0<<RS | 1<<E;
	LCD_DATA_PORT = 0xc0;
	LCD_CTRL_PORT &= ~(1<<E);
	_delay_ms(1);
	lcdWriteChar('M');
	lcdWriteChar('u');
	lcdWriteChar('n');
	lcdWriteChar('d');
	lcdWriteChar('o');
    while (1) 
    {
    }
}

