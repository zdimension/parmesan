#define abs(x) (x<0 ? (-x) : x)
#define div(a, b, c) for(int iDD=-120; iDD<=abs(a); iDD++){if(iDD*abs(b)>=abs(a)){c=(a*b<0) ? -iDD : iDD;break;}} // c=a/b
#define divPos(a, b, c) for(int iGG=0; a-iGG>=0; iGG++){int tmp=iGG*b;int zero=0;int tmp2=a-tmp;if(tmp2-zero<=0){c=iGG;break;}}
#define moduloPos(a, b, c) do{int xJJ;divPos(a, b, xJJ);c=abs((xJJ*b)-a);}while(0)

#define BITVAL(x,y) (1 << ((7-x) | ((y & 3) << 3)))
#define PIXSET(x,y)	do{SCRbuf |= BITVAL(x, y);}while(0)
#define PIXCLR(x,y)	do{SCRbuf &= ~BITVAL(x, y);}while(0)
#define SCRUPD() do{SCRupd = 1;}while(0)

#define CLEAR() do{PUTCHAR('\f');}while(0)

#define RESET() do{RESETpin = 1; while(1);}while(0)

#define WAITKEY() do{while(!KEYBeof);}while(0)

#define READKEY(x) do{WAITKEY(); *x=KEYBchr;}while(0)

#define PUTCHAR(x) do{TTYchr=x;}while(0)

#define BREAK() do{BREAKpin=1;}while(0)

// print RES to the TTY
// unsigned, with fixed width (8 digits max)
#define PRINTRES_FIX(width) __PRINTRES(0, width)

// unsigned, automatic width
#define PRINTRES() __PRINTRES(0, 0)

// signed, automatic width
#define PRINTRES_SIGN() __PRINTRES(1, 0)


#define __PRINTRES(sign, width) do {\
	int x = RESbcd;\
	if (width == 0)\
	{\
		if (!x)\
		{\
			PUTCHAR('0');\
			break;\
		}\
		if (sign && RES < 0)\
		{\
			PUTCHAR('-');\
			RES = -RES;\
			x = RESbcd;\
		}\
	}\
	else\
	{\
		x >>= 32 - (width * 4);\
	}\
	int flag = 0;\
	for (int pos = 0; pos < (width == 0 ? 8 : width); pos++)\
	{\
		int digit = x & 0xf;\
		x >>= 4;\
		if (width == 0 && !flag)\
		{\
			if (digit) flag = 1;\
			else continue;\
		}\
		PUTCHAR('0' + digit);\
	}\
} while(0)