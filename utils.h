#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "pins.h"

#define abs(x) (x<0 ? (-x) : x)
#define div(a, b, c) for(int i=-120; i<=abs(a); i++){if(i*abs(b)>=abs(a)){c=(a*b<0) ? -i : i;break;}} // c=a/b
#define divPos(a, b, c) for(int i=0; i<=a; i++){if(i*b>=a){c=i;break;}}
#define moduloPos(a, b, c) int x;divPos(a, b, x);c=abs((x*b)-a);

#endif // UTILS_H_INCLUDED
