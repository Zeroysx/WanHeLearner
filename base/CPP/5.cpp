/*
题目:简单的队列
最后修订时间：2024/3/23
作者:Wanhe
备注:
*/
/********************************** */
/**
 * 队列是一种人为规定行为模式的数据结构，就像现实中排队的队伍中有许多独
 * 立的人一样，队列中存储着一系列分立的数据，并且无法对队列进行随机访问。
 * 而是只能从队列的头部进行读取数据，从队列的尾部加入数据。
 */
const int MAX_SIZE_OF_QUEUE = 30;
// 法1，通过数组实现固定长度的队列
typedef struct queue
{
    int length;
    int *front;
    int array[MAX_SIZE_OF_QUEUE];
};

// 法二：通过链表实现队列
template <typename T>
class Queue
{
private:
    int numofNode = 0;
    typedef struct Node
    {
        T val;
        Node *next;
    };
    Node *head;
    Node *last;

public:
    Queue(/* args */);
    ~Queue();
    bool queueIn(T value); // 入队
    T *queueOut();         // 出队
};
// 默认构造函数
template <typename T>
Queue<T>::Queue(/* args */)
{
    // 创建初始节点
    head = new Node;
    head->next = nullptr;
    // 定位队尾
    last = head;
    // 更新队列计数
    numofNode++;
}
// 折构函数
template <typename T>
Queue<T>::~Queue()
{
    // 删除队列中的所有节点
    if(head == nullptr)
    {
        break;
    }
    if (head->next != nullptr)
    {
        Node *pNode = head->next;
        Node *prior = head;
        while (pNode != last)
        {
            delete prior;
            prior = pNode;
            pNode = pNode->next;
        }
        delete prior;
        delete pNode;
    }
    else 
    {
        delete head;
    }
}

template <typename T> 
bool Queue<T>::queueIn(T value)
{
    Node* pNode = new Node;
    pNode->val = value;
    last->next = pNode;
    numofNode++;
}

template <typename T>
T* Queue<T>::queueOut()
{
    Node* ret = head;
    head = head->next;
    return ret;
}