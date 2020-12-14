#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "pins.h"

#define abs(x) (x<0 ? (-x) : x)
#define div(a, b, c) for(int iDD=-120; iDD<=abs(a); iDD++){if(iDD*abs(b)>=abs(a)){c=(a*b<0) ? -iDD : iDD;break;}} // c=a/b
#define divPos(a, b, c) for(int iGG=0; a-iGG>=0; iGG++){int tmp=iGG*b;int zero=0;int tmp2=a-tmp;if(tmp2-zero<=0){c=iGG;break;}}
#define moduloPos(a, b, c) {int xJJ;divPos(a, b, xJJ);c=abs((xJJ*b)-a);}

#endif // UTILS_H_INCLUDED

/**
Works for prime, but contains some errors
*/
