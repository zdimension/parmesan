// use placeholder as RAM reference
// since we don't have absolute addressing
#define PIN(n) ((&placeholder)[n])
// for inputs, make the expression an rvalue to prevent writes
#define INP(n) (PIN(n)+0)
#define OUT(n) (PIN(n))

#define TTYchr	 	PIN(0)
#define RES 		PIN(1)
#define SCRbuf		PIN(2)
#define SCRupd		OUT(3)
#define RESETpin	OUT(4)
#define BREAKpin	OUT(5)

#define DIP1 		INP(3)
#define DIP2 		INP(4)
#define DIP3 		INP(5)
#define KEYBeof		INP(6)
#define KEYBchr		INP(7)
#define JOYx		INP(8)
#define JOYy		INP(9)
#define RNG32		INP(10)

#define BITVAL(x,y) (1 << ((7-x) | ((y & 3) << 3)))
#define PIXSET(x,y)	do{SCRbuf |= BITVAL(x, y);}while(0)
#define PIXCLR(x,y)	do{SCRbuf &= ~BITVAL(x, y);}while(0)
#define SCRUPD() do{SCRupd = 1;}while(0)

#define CLEAR() do{PUTCHAR('\f');}while(0)

#define RESET() do{RESETpin = 1; while(1);}while(0)

#define WAITKEY() do{while(!KEYBeof);}while(0)

#define READKEY(x) do{WAITKEY(); *x=KEYBchr;}while(0)

#define PUTCHAR(x) do{TTYchr=x;}while(0)

#define BREAK() do{BREAKpin=1;}while(0)

#define INIT() \
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #120");\
__asm__("sub sp, #56");\
volatile int placeholder;

#include "utils.h"
