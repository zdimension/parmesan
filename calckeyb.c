#include "pins.h"

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
		DIV(a, b, &RES);
	else if (choice == '%')
		MOD(a, b, &RES);
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