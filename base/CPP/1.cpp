/*
动态内存分配
最后修订时间L:2024/2/27
作者:Wanhe
未完成
*/
//C风格分配内存引用库
#include <malloc.h>
//用于字符串复制
#include <string.h>
//输入/输出
#include <iostream>

//
using std::cin;
using std::cout;
using std::endl;

int main()
{
    char choice[3];//静态内存分配
    char *str;
    cout<<"How you want to create space for string,C or CPP type.(input C or CPP.)"<<endl;
    cin>>choice;
    if(choice =="CPP" || choice == "cpp" )
    str = new char[3];//C++风格动态内存分配
    else if (choice == "C" ||choice == "c")
    {
         str = (char *)malloc(10 * sizeof(char));//C风格动态内存分配
         
    }
    else if(choice == "No" || choice == "no" || choice == "no")
    {
        cout<<"You will exit with no space create."<<endl;//此类情况将不分配内存
    }
    
   
}