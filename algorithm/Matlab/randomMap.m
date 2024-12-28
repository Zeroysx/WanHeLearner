function [ret] = randomMap(size,maxWeight,CP)
    %RANDOMMAP 生成随机无向图
    
    %{
    输入：
    size:图的节点数
    maxWeight：图的最大边权。
    CP:每个节点间连接的概率
    输出：邻接矩阵
    %}
    %预分配矩阵空间
    ret = zeros(size,size);
    
    %首先生成一个上三角矩阵
    martix = zeros(1,(1 + size) * size /2);
    
    %遍历上三角矩阵，确认节点间的连接以及边权.
    for i = 1 : (1 + size) * size /2
        %生成一个服从0-1分配的随机数，当数在CP的范围内时为节点分配连接
        if( rand < CP)
            %生成一个在最大权值范围内的边权
           martix(i) = maxWeight * rand;
        end
    end
    
    %将上三角矩阵转化为邻接矩阵
    i = 1;
    j = 1;
    k = 0;
    while ( k + j < (1 + size) * size /2)
        if(i ~= j+ i - 1)
    
        ret(i,j+ i - 1) = martix(k + j);
        ret(j+i - 1,i) = martix(k + j);
        end
        if(j + i - 1 == size)
            j = 1;
            k = k + i;
            i = i + 1;
        else
            j = j+1;
        end
    end