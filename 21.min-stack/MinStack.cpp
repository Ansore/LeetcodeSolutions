#include <iostream>

using namespace std;

struct Node {
	int val;
	int min;
	Node* next;

	Node(int v, int m, Node* n):
		val(v), min(m), next(n){}
};

class MinStack {
	private:
		Node* head = nullptr;
	public:
		/** initialize your data structure here. */
		MinStack() {
		}

		void push(int x) {
			if(this->head == nullptr) {
				this->head = new Node(x, x, nullptr);
			} else {
				int minNum = this->head->min > x? x : this->head->min;
				this->head = new Node(x, min(this->head->min, x), this->head);
			}
		}

		void pop() {
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}

		int top() {
			return this->head->val;
		}

		int getMin() {
			return this->head->min;
		}
};

int main(int argc, char *argv[])
{
	MinStack* min = new MinStack();
	min->push(-2);
	min->push(0);
	min->push(-3);
	cout << min->getMin() << endl;
	min->pop();
	cout << min->top() << endl;
	cout << min->getMin() << endl;
	return 0;
}
