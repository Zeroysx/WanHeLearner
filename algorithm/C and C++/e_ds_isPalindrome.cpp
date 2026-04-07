/*
题目:判读一个链表是否时回文链表
最后修订时间：2026/3/07
作者:Wanhe
备注:给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
*/
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *fast = head;
        ListNode *slow = head;
        bool flag = false;
        if (fast->next == nullptr)
            return true;
        while (fast != nullptr) // 反转前半段
        {
            st.push(slow->val); // 前半段入栈
            if (slow->next != nullptr)
                slow = slow->next;
            else
                slow = nullptr;
            for (int i = 0; i < 2; i++)
                if (fast->next != nullptr)
                {
                    flag = !flag;
                    fast = fast->next;
                }
                else
                {
                    fast = nullptr;
                    break;
                }
        }
        // 开始比较
        if (flag == false)
            st.pop();
        while (slow != nullptr)
        {
            if (slow->val != st.top())
                return false;
            slow = slow->next;
            st.pop();
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};