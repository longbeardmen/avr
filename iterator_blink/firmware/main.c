
// roman
/*
     3
    ###
8 #  6  # 7
    ###
4 #  5  #  1
    ###  # 2

*/

#include <avr/io.h>
#include <util/delay.h>

int  i, j,
  digits[4] = { 1, 2, 3, 4},
  arr[10] = {
    0b11011101,
    0b01000001,
    0b01111100,
    0b01110101,
    0b11100001,
    0b10110101,
    0b10111101,
    0b01000101,
    0b11111101,
    0b11110101,
  };

int power(int base, int pow){
  if(pow == 1)
    return base;
  else if(pow == 0)
    return 1;
  else
    return base*power(base, pow - 1);
}

int main(void){

  DDRD = 0b11111100;
  DDRB = 0b00111111;
  PORTB = 0b00000000;

  for(;;){
    /*
    for(i = 2; i < 8; i++){
      //PORTD &= 1 << (8 - i);    // reset previous pin
      PORTD ^= 1 << i;    // toggle the LED
      _delay_ms(1000);
      PORTD ^= 1 << i;
    }
    for(i = 0; i < 2; i++){
      //PORTB &= 1 << (8 - i);    // reset previous pin
      PORTB ^= 1 << i;    // toggle the LED
      _delay_ms(1000);
      PORTB ^= 1 << i;
    }
    */

    /*
    for(i = 0; i < 10; i++){
      PORTD = arr[i] << 2;
      PORTB = arr[i] >> 6;
      _delay_ms(10);
      PORTB = 0;
    }
    */

    for(i = 0; i < 1000; i++){
      int k;
      for(k = 0; k < 50; k++){
        for(j = 0; j < 4; j++){
          digits[j] = (i % power(10, j + 1))/power(10, j);
          PORTD = arr[digits[j]] << 2;
          PORTB = arr[digits[j]] >> 6 | (0b00111100 ^ (1 << (2 + j)));
          _delay_ms(5);
        }
      }
    }

    /*
    for(j = 0; j < 4; j++){
      //digits[j] = (i % power(10, j + 1))/power(10, j);
      PORTD = arr[digits[j]] << 2;
      PORTB = arr[digits[j]] >> 6 | (0b00111100 ^ (1 << (2 + j)));
      _delay_ms(4);
    }
    */
  }
  return 0;
}

