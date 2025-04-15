/*
题目:统计单词数
最后修订时间：2025/4/16
作者:Wanhe
备注:BM匹配算法
    洛谷题目P1308
    匹配指定单词，忽视大小写，如果给定单词仅是文章中某一单词的一部分则不算匹配。
*/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
int main()
{
    string tar;
    string str;
    int count=0,first=1000000;
    // input
    cin>>tar;
    cin.get();
    std::getline(cin,str);

    int size = tar.length();
    for(int i =0;i < str.length();i++)
    {
        for(int j = 1; j <= size;j++)
        {
            if(i+size > str.length() && count == 0)
            {
                cout<<"-1";
                return 0;
            }
            if(str[i+ size - j ] != tar[size-j])
            {
                //大小写匹配
                if(str[i+size - j] < 123 && str[i+size - j] >96)
                {    
                    if(str[i+size - j] -32 != tar[size -j])
                        break;
                }
                else if(str[i+size-j] <90 && str[i+size - j] > 64)
                {
                    if(str[i+size - j] +32 != tar[size - j])
                        break;
                }
                else break;    
            }
            if(j == size  && (str[i] == tar[0] 
            || str[i] == tar[0] + 32 || str[i] == tar[0] - 32))
            {
                if(i == 0 ||(str[i - 1] == ' ' && (str[i + size] == ' ' || i+size > str.length())))
                {
                    count++;
                    if( i < first)
                        first = i;
                }
                
            }
                
        }
    }
    cout<<count<<" "<<first;
    return 0;
}