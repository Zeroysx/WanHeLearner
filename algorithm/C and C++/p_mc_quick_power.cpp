#include <bits/stdc++.h>
using namespace std;
long long int quick_mi(long long int m, int power)
{
    long long int result = 1;
    while(power > 0)
    {
        if(power & 1)
        {
            result = result * m;
        }
        m = m * m;
        power >>= 1;
    }
    return result;
}
long long int quik_power(long long int base, int power)
{
    long long int result = 1;   //用于存储项累乘与返回最终结果，由于要存储累乘所以要初始化为1
    while (power > 0)           //指数大于0说明指数的二进制位并没有被左移舍弃完毕
    {
        if (power & 1)          //指数的当前计算二进制位也就是最末尾的位是非零位也就是1的时候
                                //例如1001的当前计算位就是1， 100*1* 星号中的1就是当前计算使用的位
        result *= base;     //累乘当前项并存储
        base *= base;           //计算下一个项，例如当前是n^2的话计算下一项n^2的值
                                //n^4 = n^2 * n^2;
        power >>= 1;            //指数位右移，为下一次运算做准备
                                //一次的右移将舍弃一个位例如1011(2)一次左移后变成101(2)
    }
    return result;              //返回最终结果
}
long long int mi(long long int base, int power)
{
    long long int result = 1;
    while(power > 0)
    {
        result = base * result;
        power -= 1;
    }
    return result;
}
int main()
{
    long long int result = quick_mi(3, 45);
    cout << result << endl;
    cout << quik_power(3 , 45) << endl;
    cout << mi(3, 45) << endl;
    return 0
}