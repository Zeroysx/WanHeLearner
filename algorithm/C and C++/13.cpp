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

/*链表实现队列*/
template <typename T>
 class Queue
 {
 private:
    typedef struct ListNode
    {
        T val;
        ListNode* next;
    };

    //队首
    ListNode* head;
    //队尾
    ListNode* last;
 public:
    // Queue()
    //构造函数
    Queue();
    //折构函数
    ~Queue();
    //入队函数
    bool queueIn(T value);
    //出队
    bool queueOut(T& value);
    //队列是否为空
    bool isempty();
    
 };

 template <typename T>
 Queue<T>::Queue(/* args */)
 {

    head = new ListNode;
    last = head;
    head->val = 0;
    head->next = nullptr;
    
 }

 template <typename T>
 Queue<T>::~Queue()
 {
 }
 