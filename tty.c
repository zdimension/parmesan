#include "pins.h"

#define putchar(c) { TTYchr = c; }

int main()
{
	INIT();
	putchar('P');
	putchar('A');
	putchar('R');
	putchar('M');
	putchar('E');
	putchar('S');
	putchar('A');
	putchar('N');
	putchar('!');
	while (1);
}