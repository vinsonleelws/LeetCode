Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

// LRU是Least Recently Used的简写，就是最近最少使用的意思。那么这个缓存器主要有两个成员函数，get和put，其中get函数是通过输入key来获得value，如果成功获得后，
// 这对(key, value)升至缓存器中最常用的位置（顶部），如果key不存在，则返回-1。而put函数是插入一对新的(key, value)，如果原缓存器中有该key，则需要先删除掉原有的，
// 将新的插入到缓存器的顶部。如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，也就是底部的值。

// 为了以O(1)的时间效率实现get和put操作，我们需要有三个私有变量，cap, l和m，其中cap是缓存器的容量大小，l是保存缓存器内容的列表，m是哈希表，保存关键值key和缓存器各项的迭代器之间映射。
//（1）对于get，我们在m中查找给定的key，如果存在则将此项移到顶部，并返回value，若不存在返回-1。
//（2）对于put，我们也是现在m中查找给定的key，如果存在就删掉原有项，并在顶部插入新来项，然后判断是否溢出，若溢出则删掉底部项(最不常用项)。

// Reference solution:
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) 
            return -1;
        l.splice(l.begin(), l, it->second);  // transfer only the element pointed by it->second from x into the container.
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) 
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) 
        {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
/*
// 用到了list中的splice拼接方法：
entire list (1)	
void splice (iterator position, list& x);  // transfers all the elements of x into the container.

single element (2)	
void splice (iterator position, list& x, iterator i);  // transfers only the element pointed by i from x into the container.

element range (3)	
void splice (iterator position, list& x, iterator first, iterator last); // transfers the range [first,last) from x into the container.

*/