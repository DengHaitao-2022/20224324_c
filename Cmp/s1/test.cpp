#include "math.h"
main()
{
    float a,b,y1,y2;
    int c,d,e;
    a=3.1415926;b=25.0;
    scanf("%d,%d",&c,&d);
    y1=cos(a/3);
    y2=sqrt(b);
    e=d+(-1);
    if(c>=d&&c>0)  e=c;
    printf("y1=%f,y2=%f,e=%d,c=%x\n",y1,y2,e,c);  
}
