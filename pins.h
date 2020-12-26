// use placeholder as RAM reference
// since we don't have absolute addressing
#define PIN(n) (((unsigned int volatile*)(&placeholder))[n])
// for inputs, make the expression an rvalue to prevent writes
#define INP(n) (PIN(n)+0)
#define OUT(n) (PIN(n))

#define TTYchr	 	PIN(0)
#define RES 		PIN(1)
#define SCRbuf		PIN(2)
#define SCRupd		OUT(3)
#define RESETpin	OUT(4)
#define BREAKpin	OUT(5)
#define BUZZER		OUT(6)

#define DIP1 		INP(3)
#define DIP2 		INP(4)
#define DIP3 		INP(5)
#define KEYBeof		INP(6)
#define KEYBchr		INP(7)
#define JOYx		INP(8)
#define JOYy		INP(9)
#define RNG32		INP(10)
#define RESbcd		INP(11)

#define INIT() \
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #120");\
asm("sub sp, #56");\
volatile int placeholder;

#include "utils.h"
