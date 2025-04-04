#include <iostream>
#include <unordered_map>
#include <climits>
/*
题目：LFU (Least Frequently Used) 缓存算法的实现
最后修订时间: 2025/04/04
作者: whsialcx
备注: 本程序实现了一个基于双向链表和哈希表的LFU缓存算法。
      本算法用于模拟一个具有固定容量的缓存，其中最少使用的数据会被移除。
      LFU算法用于高效地管理缓存数据，并确保频繁访问的缓存数据优先保留。

此算法使用了多重链表（频率链表）以高效管理不同频率的数据，并使用哈希表进行快速查找和更新。
*/
template <typename K, typename V>
class MultiLinkedListLFU {
private:
    struct Entry 
    {
        K key;
        V val;
        Entry* prev = nullptr;
        Entry* next = nullptr;
        Entry(K k, V v) : key(k), val(v) {}
    };

    struct FreqList //相当于一个大桶，存储着一个二维链表，桶本身也是一个二维链表
    {
        int freq;
        Entry* head = nullptr;
        Entry* tail = nullptr;
        int size = 0;

        FreqList(int f) : freq(f) {}

        void addToHead(Entry* entry) 
        {
            entry->prev = nullptr;
            entry->next = head;
            if(head != nullptr)
            {
                head->prev = entry;
            }
            else//head == nullptr
            {
                tail = entry;
            }
            head = entry;
            size++;
        }

        Entry* remove(Entry* entry) 
        {
            if(entry->prev != nullptr)
            {
                entry->prev->next = entry->next;
            }
            else
            {
                head = entry->next;
            }
            if(entry->next != nullptr)
            {
                entry->next->prev = entry->prev;
            }
            else
            {
                tail = entry->prev;
            }
            size--;
            return entry;
        }

        Entry* removeTail() 
        {
            if(tail == nullptr)
            {
                return nullptr;
            }
            return remove(tail);
        }
    };

    int capacity;
    int minFreq = 0;
    std::unordered_map<K, Entry*> keyEntryMap;// 缓存项的映射：key -> Entry（缓存项）
    std::unordered_map<K, int> keyFreqMap;         
    std::unordered_map<int, FreqList*> freqListMap; 

    void updateMinFreq() 
    {
        while(!freqListMap.count(minFreq) && minFreq < INT_MAX)
        {
            minFreq++;
        }
    }
    // 增加指定缓存项的访问频率
    void increaseFreq(K key) 
    {
        int oldkey = keyFreqMap[key];//直接找到缓存项的原有频率
        FreqList* oldlist = freqListMap[oldkey];//根据原有的频率找到所在的桶
        Entry *oldnode = oldlist->remove(keyEntryMap[key]);//删除桶中的缓存项
        if(oldlist->size == 0)//如果原桶的大小为0
        {
            freqListMap.erase(oldkey);//删除频率映射
            delete oldlist;
            if(minFreq == oldkey)
            {
                updateMinFreq();
            }
        }
        int newkey = oldkey + 1;
        keyFreqMap[key] = newkey;
        if(!freqListMap.count(newkey))//之前，这个频率的桶没有出现过
        {
            freqListMap[newkey] = new FreqList(newkey);//新建一个桶
        }
        freqListMap[newkey]->addToHead(oldnode);
    }

public:
    MultiLinkedListLFU(int cap) : capacity(cap) {}
    //析构函数，用来删除缓存项和桶
    ~MultiLinkedListLFU() 
    {
        for (auto& pair : keyEntryMap) delete pair.second;
        for (auto& pair : freqListMap) delete pair.second;
    }

    V get(K key) 
    {
        if(!keyEntryMap.count(key))//缓存中没有key值
        {
            return V();//返回默认值
        }
        increaseFreq(key);
        return keyEntryMap[key]->val;
    }

    void put(K key, V val) 
    {
        if(capacity <= 0)
        {
            return ;
        }
        if(keyEntryMap.count(key))//存在key值
        {
            keyEntryMap[key]->val = val;//更新val
            increaseFreq(key);
            return ;
        }
        //加入的缓存超过预定值
        if(keyEntryMap.size() >= capacity)
        {
            FreqList* minlist = freqListMap[minFreq];//最小频率的桶
            Entry* minnode = minlist->removeTail();//删除这个桶的尾节点
            keyEntryMap.erase(minnode->key);
            keyFreqMap.erase(minnode->key);
            delete minnode;
            if(minlist->size == 0)
            {
                freqListMap.erase(minFreq);
                updateMinFreq();
            }
        }
        //上面的if判断保证了缓存区未满，并且节点之前不存在
        //将加入的节点放到频率未为1的桶中
        Entry* entry = new Entry(key, val);
        keyEntryMap[key] = entry;
        keyFreqMap[key] = 1;
        if (!freqListMap.count(1)) 
        {
            freqListMap[1] = new FreqList(1);
        }
        freqListMap[1]->addToHead(entry);
        minFreq = 1; 
    }

    void printDebug() 
    {
        std::cout << "===== Cache State (minFreq=" << minFreq << ") =====" << std::endl;
        for (auto& pair : freqListMap) 
        {
            std::cout << "Freq " << pair.first << ": ";
            Entry* cur = pair.second->head;
            while (cur) 
            {
                std::cout << "(" << cur->key << "," << cur->val << ") ";
                cur = cur->next;
            }
            std::cout << std::endl;
        }
        std::cout << "===============================" << std::endl;
    }
};