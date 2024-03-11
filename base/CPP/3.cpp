/*
题目:链表
最后修订时间：2024/3/7
作者:Wanhe
备注:简单的链表
*/
//结构体简单实现
typedef struct 
{
    //存储的值
    int val;
    //下个个链表的地址
    ListNode* next;
}ListNode;
//创建一个长度为n的链表
ListNode* CreateListNde(int n)
{
    ListNode* head;
    if(n !=1)
    {
        head->next = CreateListNde(n-1);
    }
}

//模板类实现,此实现做出了更多智能化的设计
template <typename T>
class ClassListNode
{
private:
    T val;
    ClassListNode *next;
public:
    ClassListNode(/* args */);
    ~ClassListNode();
};

ClassListNode::ClassListNode(/* args */)
{
}

ClassListNode::~ClassListNode()
{
}

int main()
{

}

