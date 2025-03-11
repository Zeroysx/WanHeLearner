# WanheLearner

## 目录

+ [概述](#abstract)
+ [文件命名规范](#filenameRule)
+ [文件头规范](#fileheadRule)

<a id="abstract"></a>

## 概述

WanHeLearner，是作者在学习过程中整理的一些自认为有利于诸君学习计算机技术的一些源代码，特此整理，分享与大家，部分代码摘自他处，已标注出，本人学艺不精，还请各位勿要苛责，希望对诸位能有所帮助。

<a id = "filenameRule"></a>

## 文件命名规范

文件名整体采用`代码难度_代码类型_程序名+尾缀`的格式。比如一个简单的C++归并算法程序应该命名为`e_so_mergesort.cpp`。也可以为它追加尾缀标注,比如这个文件是一个测试文件，可以将它命名为：`e_so_mergesortt.cpp`。具体如何根据具体情况使用词缀，请参见以下内容

### 代码难度

代码难度分为五个等级，除了独特的（`u`）以外，难度逐级递增。

unique等级的程序的难度并没有一个确切的范围， 其主要评判标准是这个程序是否采用了某种反理论的思路，以达到在特殊场景下能够高效的解决问题的算法，因此unique等级难度的程序不见得会比hard难度更难。

对于未来得及分类的程序，则会以`uc`标记注明。

|词缀|释义|
|:----:|----|
|e|简单(Easy)：适用于程序入门者的内容|
|c|普通（common）：适用于有一定程序基础的学习者的内容|
|p|进阶（progressive）：适用于良好计算机和算法基础的学习者的内容|
|h|困难（hard）：适用于扎实基础，算法研究者的内容|
|u|独特的（unique）：非常规场景或非常规思路的特殊程序|
|uc|未分类的（unclassified）|

### 代码类型

|词缀|释义|
|:----:|----|
|ba|程序基础|
|cn|计算机网络|
|ds|数据结构|
|dp|动态规划|
|ga|贪心算法|
|ma|图论|
|mc|数学|
|mt|多线程|
|so|排序算法|
|un|未分类|

<a id="fileheadRule"> </a>

### 关于尾缀

在命名中，可以增加尾缀，一般来说，可以采用数字代表程序的版本迭代，或者加入`t`尾缀表达这是一个测试程序。

## 文件头规范

每一个源代码文件都应该在文件头部依照规范注明程序的信息。

每个文件头都应该包括以下要素：题目、程序最后修订时间、程序作者、问题描述/备注。等部分，对每个程序的基本信息进行描述。

下面是一个C++程序文件头的样例：

```C++
/*
题目：归并排序算法
最后修订时间:2024/2/22
作者:Wanhe
备注:分治思想典型案例
此算法需要用到10.cpp中的算法
*/
```
