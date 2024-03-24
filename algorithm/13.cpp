/*
题目:队列求杨辉三角
最后修订时间：2024/3/24
作者:Wanhe
备注:队列的具体实现可使用多种方法，具体可以参考base\CPP目录下的关于队列的实现方法
*/

/*数组队列法*/

const int MAX_SIZE_OF_QUEUE = 30;
//类型声明
typedef struct queue
{
    int length = -1;//队列的长度，当为空时置-1
    int front = 0;//指向队列头结点
    int array[MAX_SIZE_OF_QUEUE];//队列所占用的空间
};
//检测是否队空
bool isempty(queue q)
{
    if(q.length == -1)
        return true;
    else return false;
}
//检测是否队满
bool isfull(queue q)
{
    if(q.length < MAX_SIZE_OF_QUEUE - 1)
        return false;
    else return true;
}
//入队
bool queueIn(queue& q,int val)
{
    if(!isfull(q))
    {
        q.length++;
        q.array[(q.front + q.length)%MAX_SIZE_OF_QUEUE] = val;
        return true;
    }
    else return false;
}
//出队
bool queueOut(queue& q,int &ret)
{
    if(isempty(q))
    {
        return false;
    }
    else
    {
        ret = q.array[q.front];
        q.front = (q.front+1)%MAX_SIZE_OF_QUEUE;
        q.length--;
        return true;
    }
}

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    queue Q;
    //输入要创建的杨辉三角的阶数
    int i;
    cin>>i;
    //将第一层的1入队
    queueIn(Q,1);
    //逐层计算并输出
    for(int j = 2,x = 0,t = 0 ; j <= i; j++)
    {
        //每一层开头1入队
        queueIn(Q,1);
        //计算下一层的中间量及输出本层的中间量
        for(int c = 1; c <= j - 2 ; c++)
        {

            queueOut(Q,t);
            cout<<t<<" ";
            x = Q.array[Q.front];
            t +=x;
            queueIn(Q,t);
        }
        //每层末尾1入队
    queueIn(Q,1);
    //结尾输出
    cout<<Q.array[Q.front];
    int a;
    queueOut(Q,a);
    cout<<endl;
    }
    while (!isempty(Q))
    {
        queueOut(Q,i);
        cout<<i<<" ";
    }
    
}
