/*
题目：求连续正整数和等于指定数字的所有解
题目来源:leetCode
最后修订日期:2024/2/15
*/
//本题使用vector容器
#include <vector>
using namespace std;

//解1
// 作者：Wanhe
//双循环遍历逐个求和
class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> ret;
        
        for(int i = 1 ; i < target;i++)
        {
            int sum = i;
            for(int j = i+1 ; sum < target;j++)
            {

                sum+=j;
                if(sum == target)
                {         
                    vector<int> ans;
                   for(int t = i;t <= j;t++ )
                   ans.push_back(t);
                    ret.push_back(ans);
                    break;
                }
            }
        }
        return ret;
    }
};


//解2:求解求和连续数的左右边界
/*解析
已知和为target，设整数i为求和连续数字的左边界，j为右边界，则我们可知(i+j)(j-i+1)/2 == target,
则如果已知i和target，就可以解二元一次方程得到j
*/
#include <math.h>
class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        int i = 1;
        double j = 2.0;
        vector<vector<int>> res;
        while(i < j) {
            j = (-1 + sqrt(1 + 4 * (2 * target + (long) i * i - i))) / 2;
            if(i < j && j == (int)j) {//根据题意，解出的j必须为整数
                vector<int> ans;
                for(int k = i; k <= (int)j; k++)
                    ans.push_back(k);
                res.push_back(ans);
            }
            i++;
        }
        return res;
    }
};

// 作者：Krahets
// 链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/lhlvcs/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。