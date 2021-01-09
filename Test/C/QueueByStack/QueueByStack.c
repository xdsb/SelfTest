#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1024
struct Stack{
   int data[MaxSize];
   int top;
};
typedef struct Stack Mystack;
//队列定义为双栈
typedef struct
{
    Mystack s1;//S1为主栈
    Mystack s2;//S2为用来反转的栈
}MyQueue;

MyQueue *myQueueInit()
{
    MyQueue *tempQueue=(MyQueue *)malloc(sizeof(MyQueue));
    tempQueue->s1.top=-1;
    tempQueue->s2.top=-1;
    return tempQueue;
}

void myQueuePush(MyQueue *obj,int x)
{
     if(obj->s1.top<MaxSize)
     {
         while(obj->s1.top != -1)
         {
             obj->s2.data[++(obj->s2.top)]=obj->s1.data[(obj->s1.top)--];//把S1栈中元素压入S2实现反转
         }
         obj->s1.data[++(obj->s1.top)]=x;
         while(obj->s2.top != -1)
         {
             obj->s1.data[++(obj->s1.top)]=obj->s2.data[(obj->s2.top)--];//再把S2栈中的元素全部反转压入S1
         }
     }
}

void show_myQueue(MyQueue *obj)
{
    int temp=obj->s1.top;
    while(temp != -1)
    {
        printf("%d",obj->s1.data[temp--]);
    }
}

int myQueuePop(MyQueue* obj)
{
    if(obj->s1.top != -1)
    {
        return obj->s1.data[obj->s1.top--];
    }
    return NULL;
}

int myQueuePeek(MyQueue *obj)
{
    if(obj ->s1.top !=-1)
    {
        return obj->s1.data[obj->s1.top];
    }
    return NULL;
}

int myQueueEmpty(MyQueue *obj)
{
    if(obj ->s1.top ==-1)
    {
        return 0;
    }
    return -1;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

int main()
{
    int i;
    MyQueue *myQueue =NULL;
    myQueue=myQueueInit;
    for(i=0;i<3;i++)
    {
       myQueuePush(myQueue,i);
    }
    show_myQueue(myQueue);
    printf("出队的元素是：%d\n",myQueuePop(myQueue));
    printf("此时队列内的首个元素是：%d\n",myQueuePeek(myQueue));
}