#include "pins.h"

void run()
{
	INIT();
	
	for (int i = 0; ; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int jj = j;
			if (jj > i - jj)
				jj = i - jj;
			
			int result = 1;
			for (int k = 0; k < jj; k++)
			{
				result = (result * (i - k));
				DIV(result, k + 1, &result);
			}
			
			RES = result;
			PRINTRES_FIX(2);
			PUTCHAR(' ');
		}
		
		PUTCHAR('\n');
	}
	
	while(1);
}