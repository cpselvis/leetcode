/**
 * System design: LRU cache (least recently used).
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 8th, 2016
 */
#include<iostream>
#include<map>

using namespace std;

/**
 * Definition of cachelist node, it's double linked list node.
 */
struct CacheNode {
  int key;
  int value;
  CacheNode *pre, *next;
  CacheNode(int k, int v) : key(k), value(v), pre(NULL), next(NULL) {}
};

class LRUCache{
private:
  int size;                     // Maximum of cachelist size.
  CacheNode *head, *tail;
  map<int, CacheNode *> mp;          // Use hashmap to store
public:
  LRUCache(int capacity)
  {
    size = capacity;
    head = NULL;
    tail = NULL;
  }

  int get(int key)
  {
    map<int, CacheNode *>::iterator it = mp.find(key);
    if (it != mp.end())
    {
      CacheNode *node = it -> second;
      remove(node);
      setHead(node);
      return node -> value;
    }
    else
    {
      return -1;
    }
  }

  void set(int key, int value)
  {
    map<int, CacheNode *>::iterator it = mp.find(key);
    if (it != mp.end())
    {
      CacheNode *node = it -> second;
      node -> value = value;
      remove(node);
      setHead(node);
    }
    else
    {
      CacheNode *newNode = new CacheNode(key, value);
      if (mp.size() >= size)
      {
	map<int, CacheNode *>::iterator iter = mp.find(tail -> key);
      	remove(tail);
	mp.erase(iter);
      }
      setHead(newNode);
      mp[key] = newNode;
    }
  }

  void remove(CacheNode *node)
  {
    if (node -> pre != NULL)
    {
      node -> pre -> next = node -> next;
    }
    else
    {
      head = node -> next;
    }
    if (node -> next != NULL)
    {
      node -> next -> pre = node -> pre;
    }
    else
    {
      tail = node -> pre;
    }
  }

  void setHead(CacheNode *node)
  {
    node -> next = head;
    node -> pre = NULL;

    if (head != NULL)
    {
      head -> pre = node;
    }
    head = node;
    if (tail == NULL)
    {
      tail = head;
    }
  }
};


int main(int argc, char **argv)
{
  LRUCache *lruCache = new LRUCache(2);
  lruCache -> set(2, 1);
  lruCache -> set(1, 1);
  cout << lruCache -> get(2) << endl;
  lruCache -> set(4, 1);
  cout << lruCache -> get(1) << endl;
  cout << lruCache -> get(2) << endl;
}
