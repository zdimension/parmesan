#include "utils.h"

int main()
{
  INIT();
  int i=2;
  int j=2;
  int rep;
  for(;;i++)
  {
    j=2;
    for(; (i-j)>0; j++)
    {
      moduloPos(i, j, rep);
      if(rep==0)
      {
        goto notPrime;
      }
    }
    RES=i;
    notPrime:
    continue;
  }
  while(1);
}

/**
clang -S -target arm-none-eabi -nostdlib -mcpu=cortex-m0 -O0 -mfloat-abi=soft prime.c
python assembleur-tom.py prime.s
https://youtu.be/IhPNx13bxmA
*/
