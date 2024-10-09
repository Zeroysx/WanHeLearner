# 判断回文数

# 输入字符串
c  = input("Input your string:")
# 将字符串拆分为序列
c_list = list(c);
# 获取序列长度
s =len(c_list);
for i in range(s):
    if i == s - i - 1 or i == s - i:
        print("字符串：‘%s’是回文"%c);
        break;
    if(c_list[i] != c_list[s - i - 1]):
        print("字符串：‘%s’不是回文"%c);
        break;

