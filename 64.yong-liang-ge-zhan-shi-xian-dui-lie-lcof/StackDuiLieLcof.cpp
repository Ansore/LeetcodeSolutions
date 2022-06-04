#include <iostream>
#include <stack>

using namespace std;

class CQueue {
	private:
		stack<int> stack1;
		stack<int> stack2;
	public:
		CQueue() {
		}

		void appendTail(int value) {
			this->stack1.push(value);
		}

		int deleteHead() {
			if(stack2.empty()) {
				if(stack1.empty()) {
					return -1;
				} else {
					while(stack1.size() > 0) {
						stack2.push(stack1.top());
						stack1.pop();
					}
					int r = stack2.top();
					stack2.pop();
					return r;
				}
			} else {
				int r = stack2.top();
				stack2.pop();
				return r;
			}
		}
};

int main(int argc, char *argv[])
{
	CQueue* obj = new CQueue();
	//obj->appendTail(3);
	//cout << obj->deleteHead() << endl;
	//cout << obj->deleteHead() << endl;
	cout << obj->deleteHead() << endl;
	obj->appendTail(5);
	obj->appendTail(2);
	cout << obj->deleteHead() << endl;
	cout << obj->deleteHead() << endl;
	return 0;
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
