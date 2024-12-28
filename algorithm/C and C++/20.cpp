/*
题目:给你两个整数数组 nums1 和 nums2，长度分别为 n 和 m。同时给你一个正整数 k。

如果 nums1[i] 可以被 nums2[j] * k 整除，则称数对 (i, j) 为 优质数对（0 <= i <= n - 1, 0 <= j <= m - 1）。

返回 优质数对 的总数。
最后修订时间：2024/10/11
作者:LeetCode
备注:力扣题目,待完成
*/
#include <vector>
using namespace std;


/**
 * @brief 方法1：双循环暴力破解
 * 
 * @param nums1 
 * @param nums2 
 * @param k 
 * @return long long 
 * @author WanHe 
 */
long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ret = 0;
        int n = nums1.size();
        int m = nums2.size();
        for( int i = 0; i < n;i++)
        {
            for(int j = 0; j < m;j++)
            {
                if(nums1[i] % (nums2[j] * k) == 0)
                    ret++;
            }
        }
        return ret;
    }
