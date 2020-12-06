#include "pins.h"

int main()
{
	INIT();
	
	int x = 1;
	int y = 1;
	int tx, ty;
	int key = 'd';
	goto targetInit;
		
loopStart:
	PIXSET(tx, ty);

	PIXSET(x, y);
	
	SCRUPD();
	
	if (KEYBeof)
	{
		key = KEYBchr;
	}
	
	PIXCLR(x, y);
	
	if (0)
	{
		restart:
			goto loopStart;
	}
	
	if (key == 'q')
		x--;
	else if (key == 'd')
		x++;
	else if (key == 'z')
		y--;
	else if (key == 's')
		y++;
		
	x &= 7;
	y &= 3;
	
	if (x == tx && y == ty)
	{
		RES++;
targetInit:
		do
		{
			tx = RNG32 & 7;
			ty = RNG32 & 3;
		} while (x == tx && y == ty);
	}
	
	goto restart;
}