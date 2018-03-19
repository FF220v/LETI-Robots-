
#include "RobotLib.h"
#include <xc.h>
void init(){
    for(char i = 0; i<=7; i++)
        pinMode(i, INPUT);
    for(char i = 19; i<=22; i++)
        pinMode(i, OUTPUT);
}

void pinMode(char pin,char mode)
{
    switch(pin)
    {
        case 0:
            if(mode) 
                TRISA0 = 1;
            else 
                TRISA0 = 0;
        break;
            
        case 1:
            if(mode) 
                TRISA1 = 1;
            else 
                TRISA1 = 0;
        break;
            
        case 2:
            if(mode) 
                TRISA2 = 1;
            else 
                TRISA2 = 0;
        break;
    
        case 3:
            if(mode) 
                TRISA3 = 1;
            else 
                TRISA3 = 0;
        break;
    
        case 4:
            if(mode) 
                TRISA5 = 1;
            else 
                TRISA5 = 0;
        break;
    
        case 5:
            if(mode) 
                TRISE0 = 1;
            else 
                TRISE0 = 0;
        break;
    
        case 6:
            if(mode) 
                TRISE1 = 1;
            else 
                TRISE1 = 0;
        break;
    
        case 7:
            if(mode) 
                TRISE2 = 1;
            else 
                TRISE2 = 0;
        break;
    
        case 8:
            if(mode) 
                TRISC5 = 1;
            else 
                TRISC5 = 0;
        break;
    
        case 9:
            if(mode) 
                TRISB4 = 1;
            else 
                TRISB4 = 0;
        break;
    
        case 10:
            if(mode) 
                TRISB5 = 1;
            else 
                TRISB5 = 0;
        break;
    
        case 11:
            if(mode) 
                TRISB0 = 1;
            else 
                TRISB0 = 0;
        break;
    
        case 12:
            if(mode) 
                TRISC7 = 1;
            else 
                TRISC7 = 0;
        break;
    
        case 13:
            if(mode) 
                TRISC6 = 1;
            else 
                TRISC6 = 0;
        break;
    
        case 14:
            if(mode) 
                TRISC4 = 1;
            else 
                TRISC4 = 0;
        break;
    
        case 15:
            if(mode) 
                TRISC3 = 1;
            else 
                TRISC3 = 0;
        break;
    
        case 16:
            if(mode) 
                TRISA4 = 1;
            else 
                TRISA4 = 0;
        break;
    
        case 17:
            if(mode) 
                TRISC0 = 1;
            else 
                TRISC0 = 0;
        break;
    
        case 18:
            if(mode) 
                TRISB3 = 1;
            else 
                TRISB3 = 0;
        break;
        
        case 19:
            if(mode) 
                TRISD0 = 1;
            else 
                TRISD0 = 0;
        break;
        
         case 20:
            if(mode) 
                TRISD1 = 1;
            else 
                TRISD1 = 0;
        break;
        
        
         case 21:
            if(mode) 
                TRISB1 = 1;
            else 
                TRISB1 = 0;
        break;
        
         case 22:
            if(mode) 
                TRISB2 = 1;
            else 
                TRISB2 = 0;
        break;
    
    }
}

void digitalWrite(char pin, char mode)
{
switch(pin)
    {
        case 0:
            if(mode) 
                LATAbits.LATA0 = 1;
            else 
                LATAbits.LATA0 = 0;
        break;
            
        case 1:
            if(mode) 
                LATAbits.LATA1 = 1;
            else 
                LATAbits.LATA1 = 0;
        break;
            
        case 2:
            if(mode) 
                LATAbits.LATA2 = 1;
            else 
                LATAbits.LATA2 = 0;
        break;
    
        case 3:
            if(mode) 
                LATAbits.LATA3 = 1;
            else 
                LATAbits.LATA3 = 0;
        break;
    
        case 4:
            if(mode) 
                LATAbits.LATA5 = 1;
            else 
                LATAbits.LATA5 = 0;
        break;
    
        case 5:
            if(mode) 
                LATEbits.LATE0 = 1;
            else 
                LATEbits.LATE0 = 0;
        break;
    
        case 6:
            if(mode) 
                LATEbits.LATE1 = 1;
            else 
                LATEbits.LATE1 = 0;
        break;
    
        case 7:
            if(mode) 
                LATEbits.LATE2 = 1;
            else 
                LATEbits.LATE2 = 0;
        break;
    
        case 8:
            if(mode) 
                LATCbits.LATC5 = 1;
            else 
                LATCbits.LATC5 = 0;
        break;
    
        case 9:
            if(mode) 
                LATBbits.LATB4 = 1;
            else 
                LATBbits.LATB4 = 0;
        break;
    
        case 10:
            if(mode) 
                LATBbits.LATB5 = 1;
            else 
                LATBbits.LATB5 = 0;
        break;
    
        case 11:
            if(mode) 
                LATBbits.LATB0 = 1;
            else 
                LATBbits.LATB0 = 0;
        break;
    
        case 12:
            if(mode) 
                LATCbits.LATC7 = 1;
            else 
                LATCbits.LATC7 = 0;
        break;
    
        case 13:
            if(mode) 
                LATCbits.LATC6 = 1;
            else 
                LATCbits.LATC6 = 0;
        break;
    
        case 14:
            if(mode) 
                LATCbits.LATC4 = 1;
            else 
                LATCbits.LATC4 = 0;
        break;
    
        case 15:
            if(mode) 
                LATCbits.LATC3 = 1;
            else 
                LATCbits.LATC3 = 0;
        break;
    
        case 16:
            if(mode) 
                LATAbits.LATA4 = 1;
            else 
                LATAbits.LATA4 = 0;
        break;
    
        case 17:
            if(mode) 
                LATCbits.LATC0 = 1;
            else 
                LATCbits.LATC0 = 0;
        break;
    
        case 18:
            if(mode) 
                LATBbits.LATB3 = 1;
            else 
                LATBbits.LATB3 = 0;
        break;
        
        case 19:
            if(mode) 
                LATDbits.LATD0 = 1;
            else 
                LATDbits.LATD0 = 0;
        break;
        
         case 20:
            if(mode) 
                LATDbits.LATD1 = 1;
            else 
                LATDbits.LATD1 = 0;
        break;
        
        
         case 21:
            if(mode) 
                LATBbits.LATB1 = 1;
            else 
                LATBbits.LATB1 = 0;
        break;
        
         case 22:
            if(mode) 
                LATBbits.LATB2 = 1;
            else 
                LATBbits.LATB2 = 0;
        break;
    
    }
} 

char digitalRead(char pin){
switch(pin)
    {
    case 0: return PORTAbits.RA0;
    case 1: return PORTAbits.RA1;
    case 2: return PORTAbits.RA2;
    case 3: return PORTAbits.RA3;
    case 4: return PORTAbits.RA5;
    case 5: return PORTEbits.RE0;
    case 6: return PORTEbits.RE1;
    case 7: return PORTEbits.RE2;
    case 8: return PORTCbits.RC5;
    case 9: return PORTBbits.RB4;
    case 10: return PORTBbits.RB5;
    case 11: return PORTBbits.RB0;
    case 12: return PORTCbits.RC7;
    case 13: return PORTCbits.RC6;
    case 14: return PORTCbits.RC4;
    case 15: return PORTCbits.RC3;
    case 16: return PORTAbits.RA4;
    case 17: return PORTCbits.RC0;
    case 18: return PORTBbits.RB3;
    case 19: return PORTDbits.RD0;
    case 20: return PORTDbits.RD1;
    case 21: return PORTBbits.RB1;
    case 22: return PORTBbits.RB2;
    }
}

int analogRead(char pin)
{

}

