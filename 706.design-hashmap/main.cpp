#include <iostream>
#include <utility>
#include <vector>
#include <list>

class MyHashMap {
  private:
    std::list<std::pair<int, int>> map[16];
    int factor = 16;
  public:
    int hash(int key) {
      return key%factor;
    }
    /** Initialize your data structure here. */
    MyHashMap() {

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
      int h = hash(key);
      for(auto &p : map[h]){
        if(p.first == key) {
          p.second = value;
          return;
        }
      }
      map[h].push_front(std::pair<int, int>(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int h = hash(key);
      for(auto p : map[h]){
        if(p.first == key) {
          return p.second;
        }
      }
      return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      int h = hash(key);
      for(auto i = map[h].begin(); i != map[h].end(); i ++) {
        if(key == i->first) {
          map[h].erase(i);
          return;
        }
      }
    }
};

int main()
{
  MyHashMap myHashMap;
  myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
  myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
  // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
  /* std::cout << myHashMap.get(1) << std::endl; */
  /* myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]] */
  myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
  std::cout << myHashMap.get(2) << std::endl;
  /* myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]] */
  /* myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]] */
  /* myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]] */
  std::cout << "ok" << std::endl;
}
