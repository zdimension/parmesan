#include "pins.h"

#define putchar(c) { TTYchr = c; }

void run()
{
	INIT();
	
	RES = 2;
    /*PRINTRES_FIX(3);
    PUTCHAR('\n');*/
	
    for (unsigned int n = 3; ; n += 2)
	{
        for (unsigned int i = 2; i * i <= n; i++)
        {
			int mod;
			MOD(n, i, mod);
			if (mod == 0)
				goto notprime;
				
        }
        
        RES = n;
        /*PRINTRES_FIX(3);
        PUTCHAR('\n');*/
        
	notprime:
		continue;
    }
}