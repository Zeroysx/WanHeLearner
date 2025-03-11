/*

题目：求两个链表的首个重合节点
有两个链表，如果两个链表存在重合部分，则从第一个重合部分开始，后面的节点都重合，本题求相同的首个节点               
题目来源：Leetcode
最后修订日期:2024/2/15
*/
 struct ListNode
    {
        int val;
        ListNode * next;
    };
class LearingTest
{
private:

public:
    LearingTest(/* args */);
    ~LearingTest();
    /*
    说明：指针A先遍历A，再遍历B，指针B先遍历B再遍历A，循环遍历。
    当A==B时，存在两种情况：在第一个相同节点相交，和两个都为空，当两者无相交时，两者为空
    
    */
    ListNode* getIntersectionNode(ListNode *headA,ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != B)
        {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
//     作者：Krahets
// 链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/lhd3hj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*思路2：双循环遍历链表找到第一个相同节点,此处略*/
};



