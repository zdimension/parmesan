#include "pins.h"

#define READINT(x) {\
	*x = 0;\
	int cur;\
	while(1)\
	{\
		READKEY(&cur);\
		if (cur == '\n')\
			break;\
		if (cur < '0' || cur > '9')\
			continue;\
		TTYchr = cur;\
		*x *= 10;\
		*x += cur - '0' + 1;\
	}\
}

void run() 
{
	INIT();
	
	int a, b;
	
	PUTCHAR('A');
	PUTCHAR('=');
	READINT(&a);
	PUTCHAR('\n');
	
	PUTCHAR('B');
	PUTCHAR('=');
	READINT(&b);
	PUTCHAR('\n');
	
	PUTCHAR('+');
	PUTCHAR('-');
	PUTCHAR('*');
	PUTCHAR('/');
	PUTCHAR('%');
	PUTCHAR('&');
	PUTCHAR('|');
	PUTCHAR('^');

	int choice;
read:
	READKEY(&choice);
	
	if (choice == '+')
		RES = a + b;
	else if (choice == '-')
		RES = a - b;
	else if (choice == '*')
		RES = a * b;
	else if (choice == '/')
		DIV(a, b, RES);
	else if (choice == '%')
		MOD(a, b, RES);
	else if (choice == '&')
		RES = a & b;
	else if (choice == '|')
		RES = a | b;
	else if (choice == '^')
		RES = a ^ b;
	else
		goto read;
		
	PUTCHAR('\n');
	PUTCHAR('R');
	PUTCHAR('=');
	PRINTRES_SIGN();
		
	while (!KEYBeof);

	RESET();
}