#include <stdint.h> //C語言標頭檔
#include <stdio.h> //C語言標頭檔
#include <stdlib.h> //C語言標頭檔
#include <avr/io.h> //AVR C語言函式庫
#include <avr/interrupt.h> //AVR中斷函式庫
#include <util/delay.h> //延遲函數庫

#define SET_BIT(reg, pin)		    (reg) |= (1 << (pin)) //設定位元（reg, pin）
#define CLEAR_BIT(reg, pin)		  (reg) &= ~(1 << (pin)) //

//Functions declaration
void setup(void); //設定函數
void process(void); //函數定義

void setup(void) {

// Timer 1 in normal mode, with pre-scaler 8 ==> ~60Hz overflow.
// Timer overflow on.
TCCR1A = 0; //TCCR1A：定時器/計數器控制寄存器1A，值為0。
CLEAR_BIT(TCCR1B,WGM12); //設定TCCR1B的WGM12位為0
CLEAR_BIT(TCCR1B,WGM13); //設定TCCR1B的WGM13位為0
SET_BIT(TCCR1B,CS12); //設定TCCR1B的CS12位為1
CLEAR_BIT(TCCR1B,CS11); //清除TCCR1B的CS11位
SET_BIT(TCCR1B,CS10); //設定TCCR1B的CS10位為1
SET_BIT(TIMSK1, TOIE1); //定義TIMSK1中TOIE1位為1

// Enable B5 as output, led on B5
SET_BIT(DDRB, 5); //設定PB5為輸出

// Enable timer overflow, and turn on interrupts.
sei(); //未知物。
}

volatile int overflow_counter = 0; //變數: overflow_counter, 數值: 0, 資料型態: volatile int

ISR(TIMER0_OVF_vect) {
overflow_counter ++; //計數器增加1。
}

void process(void) {

SET_BIT(PORTB, 5); //設定PORTB的第5位為1
}

int main(void) {
setup(); //設定程序。
for ( ;; ) {
process(); //函數
_delay_ms(1000); //時間延遲。
}
}
