  //Title: LCD interfacing with PIC16f877a

  //LCD module connections

  sbit LCD_RS at RC4_bit; //LCD reset
  sbit LCD_EN at RC5_bit; //LCD enable

  sbit LCD_D4 at RE1_bit; //Data
  sbit LCD_D5 at RB1_bit; //Data
  sbit LCD_D6 at RB2_bit; //Data
  sbit LCD_D7 at RB3_bit; //Data


  //LCD Pin Direction

  sbit LCD_RS_Direction at TRISC4_bit;
  sbit LCD_EN_Direction at TRISC5_bit;
  sbit LCD_D4_Direction at TRISE1_bit;
  sbit LCD_D5_Direction at TRISB1_bit;
  sbit LCD_D6_Direction at TRISB2_bit;
  sbit LCD_D7_Direction at TRISB3_bit;

  char i;

void main() {
  Lcd_Init();
  Lcd_cmd(_LCD_CLEAR);

  Lcd_out(1,1,"Subscribe Electroniks Day");
  Delay_ms(500);

  for(i=0; i<10; i++){
  lcd_cmd(_lcd_shift_left);
  delay_ms(250);

  }

}