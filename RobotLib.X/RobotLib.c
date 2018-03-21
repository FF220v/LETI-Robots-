
#include "RobotLib.h"
#include <xc.h>

void init(){
    initOutputs();
    initADC();
    initLCD();
}

void lcdPulse(){
    LCD_E=1;
    __delay_us(LCD_PULSE);
    LCD_E=0;
    __delay_us(LCD_PULSE);
}

void lcdCmd(char cmd){
    LCD_RS = 0;
    LCD_DATA = (LCD_DATA&0x0f)|(cmd&0xf0);
    lcdPulse();
    LCD_DATA = (LCD_DATA&0x0f)|((cmd<<4)&0xf0);
    lcdPulse();
    __delay_ms(1);
}

void initLCD(){
//Configuring LCD
    TRISD &= 0x03;
    LCD_DATA &= 0b00001111;
    LCD_E = 0;
    LCD_RS = 0;
    for(char i = 0; i<3; i++){
    __delay_ms(1);
    LCD_DATA = (LCD_DATA&0x0f)|0x30;
    lcdPulse();
    }
    LCD_DATA = (LCD_DATA&0x0f)|0x20;
    lcdPulse();
    __delay_ms(1);
    lcdCmd(0x28);
    lcdCmd(0x01);
    lcdCmd(0x06);
    lcdCmd(0x0C);
    lcdCmd(0x02);
    lcdCmd(0x01);
}

void lcd_setCursor(unsigned char x,unsigned char y){
    lcdCmd(0x02);
    lcdCmd((unsigned char)0x80+x+(unsigned char)0x40*y);   
}

void lcd_clear(){
    lcdCmd(0x01);
}

void lcd_print_char(char entity){
    LCD_RS = 1;
    LCD_DATA = (LCD_DATA&0x0f)|(entity & 0xf0);
    lcdPulse();
    LCD_DATA = (LCD_DATA&0x0f)|((entity<<4)&0xf0);
    lcdPulse();
}

void lcd_print_string(char *entity){
 while(*entity) // ?????????, ????? ?? ????????? 0
 {
 lcd_print_char(*entity); // ????????? ?????? ?? LCD
 entity++; // ????????? ????? ?? 1
 }
} 

void intToStr(char* buff, long int value){
    char workBuff[16];
    long int valueBuff = value;
    if(value == 0){
        buff [0] = 0;
        return;
    }
    char i = 15;
    while(valueBuff!=0){
        char num = valueBuff%10; 
        workBuff[i] =  num+0x30;
        valueBuff = (valueBuff - num)/10;
        i--;
    }
    if(value<0)
        workBuff[i] = '-';
    else i++;
    
    char j=0;
    for(;i<=15;i++){
        buff[j]=workBuff[i];
        j++;
    } 
}

void lcd_print_int(int entity){
   char buff[16];
   intToStr(buff, entity);
   lcd_print_string(buff);
}

void lcd_print_long(long int entity){
   char buff[16];
   intToStr(buff, entity);
   lcd_print_string(buff);
}

void lcd_print_float(float entity);

void initOutputs(){
    //Configuring motor outputs and inputs 0-7
    for(char i = 0; i<=7; i++)
        pinMode(i, INPUT);
    for(char i = 19; i<=22; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }}

void pinMode(char pin,char mode){
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

void digitalWrite(char pin, char mode){
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
return '0';
}
       
void initADC(){
//Configuring ADC
    ADCON1bits.PCFG=0b1111; //Disabling analog inputs
    ADCON1bits.VCFG=0b00; // selecting supply vss 
    ADCON2bits.ACQT=0b111; 
    ADCON2bits.ADCS=0b110;// frequency = Fosc/64 
    ADCON2bits.ADFM=0;//left shift
}

int analogRead(char pin){
    ADCON1bits.PCFG=0b0000; //Enabling analog inputs
    ADCON0bits.ADON=1; //turn ADS on
    
    //Choosing chanel (pin)
    switch(pin){
        case 0:
            ADCON0bits.CHS=0; 
        break;
            
        case 1:
            ADCON0bits.CHS=1;
        break;
        
        case 2:
            ADCON0bits.CHS=2;
        break;
        
        case 3:
            ADCON0bits.CHS=3;
        break;
        
        case 4:
            ADCON0bits.CHS=4;
        break;
        
        case 5:
            ADCON0bits.CHS=5;
        break;
        
        case 6:
            ADCON0bits.CHS=6;
        break;
        
        case 7:
            ADCON0bits.CHS=7;
        break;
        
        case 9: //AN11
            ADCON0bits.CHS=11;
        break;
        
        case 11: //AN12 
            ADCON0bits.CHS=12;
        break;
    }
    
    ADCON0bits.GO_DONE=1; // start reading
    while(ADCON0bits.GO_DONE); //waiting until reading done  
    ADCON1bits.PCFG=0b1111; //Disabling analog inputs
    ADCON0bits.ADON=0; //turn ADC off 
    return (ADRESH<<2)+(ADRESL>>6); //returning result
}

