/*
题目:简单的队列
最后修订时间：2024/3/23
作者:Wanhe
备注:
*/
const int MAX_SIZE_OF_QUEUE = 30;
//法1，通过数组实现固定长度的队列
typedef struct queue
{
    int length;
    int* front;
    int array[MAX_SIZE_OF_QUEUE];
};

//法二：通过链表实现队列
template <typename T>
class Queue
{
private:
    typedef struct Node
    {
        T val;
        Node * next;
    };
    Node* head;
public:

    Queue(/* args */);
    ~Queue();
};
template <typename T>
Queue<T>::Queue(/* args */)
{
}
template <typename T>
Queue<T>::~Queue()
{
}

