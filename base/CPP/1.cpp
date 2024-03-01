/*
动态内存分配
最后修订时间L:2024/2/29
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
    if((choice[0] =='C' && choice[1] == 'P' &&choice[2] == 'P')||(choice[0] == 'c'&&choice[1] == 'p' && choice[2] == 'p'))
    {
    str = new char[3];//C++风格动态内存分配
     cin>>str;
     cout<<str<<endl;
     delete [] str;
    }
    else if (choice == "C" ||choice == "c")
    {
         str = (char *)malloc(10 * sizeof(char));//C风格动态内存分配
         cin>>str;
         cout<<str<<endl;
         free(str);
    }
    else if(choice == "No" || choice == "no" || choice == "no")
    {
        cout<<"You will exit with no space create."<<endl;//此类情况将不分配内存
    }
    else cout<<"error.";
    
   
}