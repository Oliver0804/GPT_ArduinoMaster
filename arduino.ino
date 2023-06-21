#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(reg, pin)		    (reg) |= (1 << (pin))
#define CLEAR_BIT(reg, pin)		  (reg) &= ~(1 << (pin))

//Functions declaration
void setup(void);
void process(void);

void setup(void) {

	// Timer 1 in normal mode, with pre-scaler 8 ==> ~60Hz overflow.
	// Timer overflow on.
	TCCR1A = 0;
  CLEAR_BIT(TCCR1B,WGM12);
  CLEAR_BIT(TCCR1B,WGM13);
  		SET_BIT(TCCR1B,CS12);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS10);
  SET_BIT(TIMSK1, TOIE1);

    // Enable B5 as output, led on B5
	SET_BIT(DDRB, 5);

	// Enable timer overflow, and turn on interrupts.
	sei();
}

volatile int overflow_counter = 0;

ISR(TIMER0_OVF_vect) {
	overflow_counter ++;
}

void process(void) {

  SET_BIT(PORTB, 5);
}

int main(void) {
	setup();
	for ( ;; ) {
		process();
      _delay_ms(1000);
	}
}