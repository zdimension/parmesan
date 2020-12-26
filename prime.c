#include "pins.h"

#define putchar(c) { TTYchr = c; }

int main()
{
	INIT();
	
	RES = 2;
    PRINTRES_FIX(3);
    PUTCHAR('\n');
	
    for (unsigned int n=3; ; n += 2)
	{
        for(unsigned int i = 2; i < n; i++)
        {
            for(unsigned int j = i; j < n; j++)
            {
				register unsigned int prod = i * j;
				
                if (prod > n)
					break;
					
				if (prod == n)
					goto notprime;
            }
        }
        
        RES = n;
        PRINTRES_FIX(3);
        PUTCHAR('\n');
        
	notprime:
		continue;
    }
}