#include<stdio.h>
#include<Windows.h>
int main()
{
    system(" color 0c");//设计程序颜色 
    printf("遇见你是一件很开心的事情,爱你哟！！！\n");//打印文字 
    
    float x,y,a;//定义变量x,y,a 
    
    for(y=1.5f;y>-1;y-=0.1f)
    {
        for(x=-1.5f;x<1.5f;x+=.05f){
            a=x*x+y*y-1;
            putchar(a*a*a-x*x*y*y*y<0.0f?'x':' '); 
        }
        
        Sleep(150);//停顿函数（1.5秒钟） 
        putchar('\n'); //换行 
    }
    while(1)
    {
    }
    
    return 0;
}