#include <xc.h>
#include <pic18f4525.h>
#include "../RobotLib.X/RobotLib.h"

void func(){}
void main(void) 

{
    init();
    attachInterrupt(0,RISING,func);

    lcd_setCursor(0,1);
    lcd_print_int(analogRead(7));
    pinMode(18,OUTPUT);
    //lcd_print_int(123);

    while(1){
    lcd_setCursor(0,1);
    lcd_print_int(analogRead(7));
    lcd_print_string("    ");
    } 
}