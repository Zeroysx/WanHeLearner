/*
求数组A排除第i个数的乘积，得到数组B
*/
//
#include <vector>
using namespace std;
//解1,部分测试样例未通过
class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        vector<int> arrayB;
        if(arrayA.size() == 0)
        return {};
        for(int i = 0; i < arrayA.size();i++)
        {
            int ans = 1;
            for(int j = 0; j < arrayA.size();j++)
            {
                if(i != j)
                ans *= arrayA[j];
                else ans *=1;
            }
            arrayB.push_back(ans);
        }
         
        return arrayB;
    }
};
//  作者:Wanhe