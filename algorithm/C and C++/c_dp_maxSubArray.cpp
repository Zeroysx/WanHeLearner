/*
题目:最大子数组问题
最后修订时间：2024/5/15
作者:Wanhe
备注:分治策略
问题描述：一个含有含符号数的数组，求其中拥有最大和的最大子数组
*/
#include <vector>
// 获取一个范围内跨越中点的最大子数组。
std::vector<int> find_max_crossing_subarray(std::vector<int> A,int low,int mid,int high)
{
    //获取中点左边包含中点的最大子数组。
    int left_sum = -10000000;
    int sum = 0;
    int max_left_tag;//最大
    for(int i=mid;i >= low;i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left_tag = i;
        }
    }
    int right_sum = -1000000;
    sum = 0;
    int max_right_tag;
    for(int i=mid;i <= high;i++ )
    {
        sum = sum + A[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right_tag = i;
        }
    }
    std::vector<int> ret ={0,0,0};
    ret[0] = max_left_tag;ret[1] = max_right_tag;ret[2] = left_sum+right_sum;
    return ret;
}

//求最大子数组
std::vector<int> find_max_subarray(std::vector<int> A,int low,int high)
{
    if (low == high)
    {
        std::vector<int> ret={0,0,0};
        ret[0] = ret [1] = low;
        ret[2] = A[low];
        return ret;
    }
    else if (low > high)
    {
        // 非法的输入
        std::vector<int> ret={0,0,0};
        ret[0] = -1;
        return ret;
    }
    else
    {
        int mid = (low+high) / 2;
        std::vector<int> max_left_array = find_max_subarray(A,low,mid);
        std::vector<int> max_right_array = find_max_subarray(A,mid+1,high);
        std::vector<int> max_mid_array = find_max_crossing_subarray(A,low,mid,high);
        if( max_left_array >= max_right_array && max_left_array >= max_mid_array)
        {
            return max_left_array;
        }
        else if (max_right_array >= max_left_array && max_right_array >= max_mid_array)
        {
            return max_right_array;
        }
        else
        {
            return max_mid_array;
        }   
    }
}