#include "pins.h"

int main() 
{
	INIT();
	
	int val;
	int swap = 0;
	while (1)
	{
		if (KEYBeof == 0) continue;
		val = KEYBchr;
		swap = 32 - swap;
		val &= ~(swap);
		TTYchr = val;
	}
}