#ifndef ROBOTLIB
#define	ROBOTLIB

//Setting coniguration bits 

#pragma config OSC = HSPLL      // Oscillator Selection bits (HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bits (Brown-out Reset enabled and controlled by software (SBOREN is enabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (008000-00BFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

//Setting default frequency if not defined yet
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 40000000 
#endif

//Defining constants
#define HIGH 1
#define LOW 0
#define OUTPUT 0
#define INPUT 1
#define RISING 0
#define FALLING 1
#define CHANGE 2

//Defining numbers of pins
#define _RC5 8
#define _RB4 9
#define _RB5 10
#define _RB0 11
#define _RA0 0
#define _RA1 1
#define _RA2 2
#define _RA3 3
#define _RA5 4
#define _RE0 5
#define _RE1 6
#define _RE2 7
#define _RC7 12
#define _RC6 13
#define _RC4 14
#define _RC3 15
#define _RA4 16
#define _RC0 17
#define _RB3 18
#define _RD0 19
#define _RD1 20
#define _RB1 21
#define _RB2 22


#define _AN0 0
#define _AN1 1
#define _AN2 2
#define _AN3 3
#define _AN4 4
#define _AN5 5
#define _AN6 6
#define _AN7 7
#define _AN11 9
#define _AN12 11

//defining LCD constants
#define LCD_E PORTDbits.RD3
#define LCD_RS PORTDbits.RD2
#define LCD_PULSE 50
#define LCD_DATA LATD

#include <xc.h>
#include <pic18f4525.h>

//interrupt functions
#pragma interrupt high_isr
void  high_isr(void);
#pragma interruptlow low_isr
void low_isr(void);

//intialization of RobotLib
void init();

//Digital pins controls
void initOutputs();
void pinMode(char pin,char mode);
void digitalWrite(char pin, char state);
char digitalRead(char pin);

//Function for reading analog values 
int analogRead(char pin); 
void initADC();

//Handling interrupts
void (*int0func)();
void (*timerFunc)();
void initInterrupts();
void attachInterrupt(char num, char mode, void (*func)());
void detachInterrupt(char num);

//LCD Functions
void initLCD();
void lcd_clear();
void lcd_setCursor(char x,char y);
void lcd_print_int(int entity);
void lcd_print_char(char entity);
void lcd_print_float(float entity);
void lcd_print_string(char *entity);

//Overloading-like construction
//#define lcd_print(X)      \
    _Generic((X),           \
    int: lcd_print_int,     \
    char: lcd_print_char,   \
    float: lcd_print_float, \
    char*: lcd_print_string \
    )(X)

//Timer functions for counting time since start 
unsigned long long microSeconds = 0;
unsigned long long milliSeconds = 0;
void init_timer();
unsigned long long micros();
unsigned long long millis();

void delay_ms();
void delayMicroseconds();


#endif	/* ROBOTLIB */
