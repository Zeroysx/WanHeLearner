/*
题目:共享栈
最后修订时间：2024/3/23
作者:Wanhe
备注:本案例为直观，输出函数的设计在实际中不完全可取。
*/
const int LEFT = 1;
const int RIGHT = 2;
template <typename T>
class ShareStack
{
private:
    int size;
    T* space;
    typedef struct Stack
    {
        T *head;
        T *top;
    };
    Stack stack1;
    Stack stack2;
    
    //栈顶指针
public:
    //入栈
    bool push(T val,int target) ;
    //出栈
    bool pop(int target);
    //检查栈是否为空；
    bool isempty(int target);
    //输出栈顶元素
    T gettop(int target);
    //判断整个共享栈是否满
    bool isfull(){if(stack1.top + 1 == stack2.top) return true;else return false;}
    ShareStack(int length);
    ~ShareStack();
};
//构造函数
template <typename T>
ShareStack<T>::ShareStack(int length)
{
    size =length;
    space = new T[length];

    stack1.head = space;
    stack1.top = stack1.head - 1;

    stack2.head = space + length - 1;
    stack2.top = stack2.head + 1;
}

//折构函数
template <typename T>
ShareStack<T>::~ShareStack()
{
    delete [] space;
}

template <typename T>
bool ShareStack<T>::pop(int target)
{
    if(target == LEFT)
    {
        if(isempty(LEFT))
        {
            return false;
        }
        else
        {
            stack1.top--;
        }
        
    }
    else if (target == RIGHT)
    {
        if(isempty(RIGHT))
        {
            return false;
        }
        else
        {
            stack2.top++;
        }
    }
    else
        return false;
    return true;
}

template <typename T>
bool ShareStack<T>::push(T val,int target)
{
    if(isfull())
    {
        return false;
    }
    else
    {
        if(target == LEFT)
        {
            stack1.top++;
            *stack1.top = val; 
        }
        else if(target == RIGHT)
        {
            stack2.top--;
            *stack2.top = val;
        }
        else return false;
    }
    return true;
}

template <typename T>
bool ShareStack<T>::isempty(int target)
{
    if(target == LEFT)
    {
        if (stack1.top == stack1.head - 1)
        {
            return true;
        }
    }
    else if(target == RIGHT)
    {
        if (stack2.top == stack2.head + 1)
        {
            return true;
        }
        
    }
    return false;
}

template <typename T>
T ShareStack<T>::gettop(int target)
{
    if (target == LEFT)
    {
        return *stack1.top;
    }
    if(target == RIGHT)
    {
        return *stack2.top;
    }   
}

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//格式化输出栈顶
template <typename T>
void printStack(ShareStack<T>& ss,int target)
{
    if(target == LEFT)
    {
        if(ss.isempty(LEFT))
        {
            cout<<"empty";
        }
        else
        {
            cout<<ss.gettop(LEFT);
        }
    }
    if(target == RIGHT)
    {
        if(ss.isempty(RIGHT))
        {
            cout<<"empty";
        }
        else
        {
            cout<<ss.gettop(RIGHT);
        }
    }
}
int main()
{
    ShareStack<int> Sstack(12);
    //输出1
   cout<<"stack1: ";
   printStack(Sstack,LEFT);
   cout<<endl;
   cout<<"stack2: ";
   printStack(Sstack,RIGHT);
   cout<<endl;
   //输入
   int i ;
   cin>>i;
   for(int j = 1; j < i; j++)
   {

        if(Sstack.isfull())
            break;
        if(j % 2 == 0)
        {
            Sstack.push(j,RIGHT);
        }
        else Sstack.push(j,LEFT);
   }
   //输出2
   printStack(Sstack,LEFT);
   Sstack.pop(LEFT);
   cout<<endl;
   printStack(Sstack,RIGHT);
   Sstack.pop(RIGHT);
    cout<<endl;

   //输出3
   cout<<"stack1:";
   while (!Sstack.isempty(LEFT))
   {
        printStack(Sstack,LEFT);
        Sstack.pop(LEFT);
        if(!Sstack.isempty(LEFT))
        {
            cout<<" ";
        }
   }
   cout<<endl;
   cout<<"stack2:";
   while (!Sstack.isempty(RIGHT))
   {
        printStack(Sstack,RIGHT);
        Sstack.pop(RIGHT);
        if(!Sstack.isempty(RIGHT))
        {
            cout<<" ";
        }
   }
   cout<<endl;
   
}