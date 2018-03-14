#include "stdio.h"

int power(int base, int pow){
  if(pow == 1)
    return base;
  else if(pow == 0)
    return 1;
  else
    return base*power(base, pow - 1);
}

int main(void){
  int i, j;
  for(i = 970; i < 1000; i++){
    for(j = 0; j < 4; j++){
      printf("%i\n",(i % power(10, j + 1))/power(10, j));

  //    PORTD = arr[digits[j]] << 2;
  //    PORTB = arr[digits[j]] >> 6 | (0b00111100 ^ (1 << (2 + j)));
    }
    printf("-----------\n");
  }
  return 0;
}


