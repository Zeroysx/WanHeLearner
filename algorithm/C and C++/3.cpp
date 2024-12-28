/*
使有一个数组的所有奇数在所有偶数前面
题目来源：LeetCode
最后修订日期:2024/2/15
*/
//本题使用vector容器
#include <vector>
using namespace std;
//解1：双指针同端同向遍历

class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int j = actions.size();
        for(int i = 0 ;i < j ; i++ )
        {
            if(actions[i] % 2 == 0 )
            {
                for(int z=i; z < j;z++)
                {
                    if(actions[z] % 2  == 1)
                    {
                    swap(actions[i],actions[z]);
                    break;
                    }
                }
            }
        }
        return actions;
    }
};
//作者：Wanhe 
//解2：双指针，两端反向遍历，LeetCode题解
class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions)
    {
        int i = 0, j = actions.size() - 1;
        while (i < j)
        {
            while(i < j && (actions[i] & 1) == 1) i++;
            while(i < j && (actions[j] & 1) == 0) j--;
            swap(actions[i], actions[j]);
        }
        return actions;
    }
};

// 作者：Krahets
// 链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/lh70jr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
