#include "pins.h"

#define putchar(c) { TTYchr = c; }

int main()
{
	INIT();

    for(unsigned int n=2;;n++)
    {
        for(unsigned int i=2;;i++)
        {
            for(unsigned int j=2;;j++)
            {
                if(i*j==n)
                {
                    goto notprime;
                }
                if(i*j>n)
                {
                    break;
                }
            }
            if(i>n)
            {
                break;
            }
        }
        RES = n;
        PRINTRES_FIX(3);
        PUTCHAR('\n');
	notprime:
		continue;
    }
    while (1);
}