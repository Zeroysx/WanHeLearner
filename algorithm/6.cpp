/*
寻找数组内存在相同相同值的任意值
*/
#include <vector>
using namespace std;


//解法1，双循环遍历
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        for(int i = 0; i <documents.size();i++)
        {
            for(int j = i ; j <documents.size();j++)
            {
                if(documents[i] == documents[j] && i != j)
                return documents[i];
            }
        }
        return NULL;
    }
};
