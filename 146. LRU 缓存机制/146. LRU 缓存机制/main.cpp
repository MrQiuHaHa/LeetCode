//
//  main.cpp
//  146. LRU 缓存机制
//
//  Created by 邱俊荣 on 2021/3/21.
//
/*
 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 
 实现 LRUCache 类：
 LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
  
 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/lru-cache
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
    
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int key, int value): key(key), value(value) {}
        Node() {}
    };
    int capacity;
    Node *first;//虚拟头结点
    Node *last;//虚拟尾结点
    unordered_map<int, Node *> map;
    //将节点插入到链表最前面,first的后面
    void addAfterFirst(Node *node) {
        node->next = first->next;
        first->next->prev = node;
        
        first->next = node;
        node->prev = first;
    }
    //从链表移除节点
    void removeNode(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        first = new Node();//虚拟节点的作用是辅助不需要判断next和prve是空指针的情况
        last = new Node();
        first->next = last;
        last->prev = first;
    }
    
    int get(int key) {
        
        Node *node = map[key];
        if (node == nullptr) return -1;
        removeNode(node);
        addAfterFirst(node);
        return node->value;
    }
    
    void put(int key, int value) {
        Node *node = map[key];
        if (node != nullptr) { //已经存在的key，则覆盖
            node->value = value;//
            removeNode(node);
        } else {
            if (map.size()-1 >= capacity) {
                //容量不够取出链表最后节点,last的前一个节点，移除
                Node *lastNode = last->prev;
                map.erase(lastNode->key);
                removeNode(lastNode);
            }
            // 直接添加新节点
            node = new Node(key, value);
            map[key] = node;
        }
        addAfterFirst(node);
    }
};

int main(int argc, const char * argv[]) {
    
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 10);
    cache->get(1);
    
    return 0;
}
