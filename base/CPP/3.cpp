/*
题目:链表
最后修订时间：2024/3/7
作者:Wanhe
备注:简单的链表
*/
/********************************** */
/**
 * 链表是C/C++中常用的一种数据结构，其基本成员一般包含两个：
 * 1、数据项
 * 2、执向链表下一节点的指针
 * 根据使用需求的不同，可能还包含其他的成员，比如：
 * 1、指向前一节点的指针：由此类节点构成的链表可以双向遍历，称为双链表（区别与普通的单链表）
 * 2、指向某些特定节点的索引。
 * 3、部分链表会设计一个头节点，用于存储链表的信息。
 * 4、有些链表会将链表尾节点的指针指向头节点，使链表能够循环访问，称为循环联保
 * 5、其他根据实际需求的设计
 * 链表可以实现对数据的分布式存储，但缺点是无法对链表进行随机访问（静态链表除外，静态链表的本质是数组）。
 *
 */

// 单链表示例
struct SingleListNode
{
    char data;
    SingleListNode *next;
};

// 双链表示例
struct Doublelistnode
{
    /* data */
    char data;
    Doublelistnode *prior; // 指向上一节点
    Doublelistnode *next;  // 指向下一节点
};

// 循环单链表，为了直观体现循环单链表的特性，用类实现
class CirculateListNode
{
private:
    /* data */
    char data;
    CirculateListNode *next = nullptr;

public:
    // 构造函数
    CirculateListNode(/* args */);
    // 折构函数
    ~CirculateListNode();
    void addNode(char c);               // 在当前节点的下一位添加节点
    void setvalue(char c) { data = c; } // 修改节点数据
    char getdata() { return data; }     // 返回data
    void setnext(CirculateListNode *node) { next = node; }
    CirculateListNode *getnext() { return next; } // 返回next
};

CirculateListNode::CirculateListNode(/* args */)
{
    data = '/n';
}

CirculateListNode::~CirculateListNode()
{

    CirculateListNode *pNode = next;
    if (pNode == nullptr)
    {
        return;
    }
    if (pNode == this)
    {
        return;
    }
    // 查找到上一节点
    while (pNode->next != this)
    {
        pNode = pNode->next;
    }
    // 将上一节点与下一节点相连
    pNode->next = next;
}

void CirculateListNode::addNode(char c)
{
    CirculateListNode newNode;
    newNode.setvalue(c);
    newNode.next = next;
    next = &newNode;
}

// 循环单链表的头节点
class CirculateListNodeHead : public CirculateListNode // 头节点类继承节点类所有功能
{
private:
    /* data */
    int count; // 节点数计数
public:
    CirculateListNodeHead(/* args */);
    ~CirculateListNodeHead();
    void addNode(char c);               // 向循环队列末尾添加一个节点
    bool deleteNode(int n);             // 删除循环队列的第n个节点
    bool setvalue(char c, int n);       // 修改循环队列的第n个节点的值。
    CirculateListNode *getLatestNode(); // 返回尾节点
};

CirculateListNodeHead::CirculateListNodeHead(/* args */)
{
    count = 0; // 初始化计数
}

CirculateListNodeHead::~CirculateListNodeHead()
{
    //删除所有节点
    CirculateListNode* pNode;
}

void CirculateListNodeHead::addNode(char c)
{
    // 访问指针
    CirculateListNode *pNode = getnext();
    if (pNode == nullptr) // 当链表不存在节点时，直接创建一个节点。
    {
        // 分配新的空间存储数据
        CirculateListNode *newNode = new CirculateListNode;
        newNode->setvalue(c);
        setnext(newNode);
        newNode->setnext(newNode); // 将链表设置为循环结构
        count++;
        return;
    }
    CirculateListNode *head = pNode;
    while (pNode->getnext() == head) // 定位到循环链表最后一个节点
    {
        pNode = pNode->getnext();
    }

    pNode->addNode(c); // 在节点末尾添加节点
    count++;
}
bool CirculateListNodeHead::deleteNode(int n)
{
    if (n <= 0)
    {
        return false; // n必须为整数
    }
    if (count < n)
    {
        return false; // n必须小于链表总节点数
    }
    CirculateListNode *pNode = getnext();
    for (int i = 0; i < n; i++) // 寻找目标节点
    {
        pNode = pNode->getnext();
    }
    delete pNode; // 删除目标节点
}
bool CirculateListNodeHead::setvalue(char c, int n)
{
    if (n <= 0)
    {
        return false;
    }
    if (count < n)
    {
        return false;
    }
    CirculateListNode *pNode = getnext();
    for (int i = 0; i < n; i++)
    {
        pNode = pNode->getnext();
    }
    pNode->setvalue(c);
}

CirculateListNode* CirculateListNodeHead::getLatestNode()
{
    CirculateListNode* pNode = getnext();
    if(pNode == nullptr)
    {
        return pNode;
    }
    CirculateListNode* head = pNode;
    while (pNode->getnext() ==head)
    {
        pNode = pNode->getnext();
    }
    return pNode;
}
