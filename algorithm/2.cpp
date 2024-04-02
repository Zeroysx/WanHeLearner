/*
复制含有指向链表随机位置的指针
题目来源：Leetcode
最后修订日期:2024/2/15
*/
#define NULL nullptr
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*更优解决方案是使用哈希表构建映射，本方法未使用哈希表但是原理类似*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        return nullptr;
        //创建返回的链表
        Node *ret = new Node(head->val);
        //遍历head的节点
        Node *pNode = head->next;
        Node *pNode2 = ret;
       int i = 1;//链表长度 
        while(pNode != nullptr)
        {
            pNode2->next = new Node(pNode->val);
            pNode2 = pNode2->next;
            pNode = pNode->next;
            i++;
        }
        //构建映射
        Node *Map[2][i];
        pNode =head;
        pNode2 = ret;
        //
        for(int i = 0;pNode != nullptr && pNode2 != nullptr;i++)
        {
            Map[0][i] = pNode;
            Map[1][i] = pNode2;
            pNode = pNode->next;
            pNode2 = pNode2->next;
        }
        for(int j = 0 ; j < i;j++)
        {
            pNode = head;
            for(int z = 0;z < i;z++)
            {
                if(pNode == Map[0][j]->random)
                {
                Map[1][j]->random = Map[1][z];
                break;
                }
                pNode = pNode->next;
            }
        }
        return ret;
    }
};
//作者:Wanhe