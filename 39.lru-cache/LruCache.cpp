#include <iostream>
#include <unordered_map>

using namespace std;

struct CacheNode {
	int key;
	int value;
	CacheNode* pre;
	CacheNode* next;
	CacheNode(int x, int y) : key(x), value(y), pre(nullptr), next(nullptr){}
};

class LRUCache {
	private:
		int size;
		int capacity;
		CacheNode* head;
		CacheNode* tail;
	public:
		LRUCache(int capacity) {
			//cout << "11111111";
			this->capacity = capacity;
			this->size = 0;
			this->head = nullptr;
			this->tail = nullptr;
		}

		void moveToHead(CacheNode* p) {

			if(p->next != nullptr) {
				if(p->pre != nullptr) {
					p->pre->next = p->next;
					p->next->pre = p->pre;
					p->next = this->head;
					this->head->pre = p;
					this->head = p;
					p->pre = nullptr;
				}
			} else {
				if(p->pre != nullptr) {
					this->tail = p->pre;
					this->tail->next = nullptr;
					p->next = this->head;
					this->head->pre = p;
					p->pre = nullptr;
					this->head = p;
				}
			}
		}

		int get(int key) {
			CacheNode* p = head;
			while(p != nullptr) {
				if(p->key == key) {
					// 移动到头部
					moveToHead(p);
					return p->value;
				}
				p = p->next;
			}

			return -1;
		}

		void put(int key, int value) {
			//cout << key;
			// 头节点
			if(head == nullptr) {
				head = new CacheNode(key, value);
				this->tail = head;
				this->size += 1;
				return;
			}

			CacheNode* p = head;
			while(p != nullptr) {
				if(p->key == key) {
					p->value = value;
					// 移到头部
					moveToHead(p);
					return;
				}
				p = p->next;
			}
			//cout << "size: "<<this->size << endl;
			// 没有找到则插入新数据
			if(this->size == this->capacity) {
				if(this->size == 1) {
					this->head->value = value;
					this->head->key = key;
					return;
				}
				//cout << "满了";
				// 存储满了，则删除最后一个，把数据插入到头部,改变最后一个元素,存储再利用
				CacheNode* temp = this->tail;
				this->tail = this->tail->pre;
				this->tail->next = nullptr;
				temp->key = key;
				temp->value = value;
				temp->next = this->head;
				this->head->pre = temp;
				this->head = temp;
				temp->pre = nullptr;
				return;
			}
			// 没满就插入到第一个
			CacheNode* node = new CacheNode(key, value);
			node->next = this->head;
			this->head->pre = node;
			this->head = node;
			this->size += 1;
			return;
		}
		CacheNode* getHead() {
			return this->head;
		}
};

int main(int argc, char *argv[])
{
	//LRUCache* cache = new LRUCache(2);
	//LRUCache cache(2);
	//cache->put(1, 1);
	//cache->put(2, 2);
	//CacheNode* node = cache->getHead();
	//while(node != nullptr) {
	//cout << node->value << " ";
	//node = node->next;
	//}
	//cout << cache->get(1) << endl;
	//cache->put(3, 3);
	//while(node != nullptr) {
	//cout << node->value << " ";
	//node = node->next;
	//}
	//cout << "-----------" << endl;
	//node = cache->getHead();
	//while(node != nullptr) {
	//cout << node->value << " ";
	//node = node->next;
	//}
	//cout << endl;
	//cout << "-----------" << endl;
	//cout << cache->get(2) << endl;
	//cache->put(4, 4);
	//cout << "-----------" << endl;
	//node = cache->getHead();
	//while(node != nullptr) {
	//cout << node->value << " ";
	//node = node->next;
	//}
	//cout << endl;
	//cout << "-----------" << endl;
	//cout << cache->get(1) << endl;
	//cout << cache->get(3) << endl;
	//cout << "-----------" << endl;
	//node = cache->getHead();
	//while(node != nullptr) {
	//cout << node->value << " ";
	//node = node->next;
	//}
	//cout << endl;
	//cout << "-----------" << endl;
	//cout << cache->get(4) << endl;


	LRUCache* cache = new LRUCache(2);
	cache->put(2, 1);
	cache->put(1, 1);
	cache->put(2, 3);
	cache->put(4, 1);
	CacheNode* node = cache->getHead();
	while(node != nullptr) {
		cout << node->key << "-" << node->value << " ";

		node = node->next;
	}
	cout << endl;
	cout << "-----------" << endl;
	cout << cache->get(1) << endl;
	cout << cache->get(2) << endl;
	//cout << cache->get(3) << endl;
	return 0;
}
