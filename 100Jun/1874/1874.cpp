#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool seq(stack<int>& stack, queue<char>& queue) {
	int sequenceNum, inputNum, stackNum;
	bool result = true;

	cin >> sequenceNum;

	stackNum = 1;
	stack.push(0);

	for (int i = 0; i < sequenceNum; i++) {
		cin >> inputNum;
		if (result == true) {
			if (inputNum >= stackNum) { //push
				while (inputNum > stackNum) {
					stack.push(stackNum);
					queue.push('+');
					stackNum++;
				}
				stackNum++;
				queue.push('+');
				queue.push('-');
			}
			else { //pop
				if (stack.top() == inputNum) {
					stack.pop();
					queue.push('-');
				}
				else {
					result = false;
				}
			}
		}
	}
	return result;
}



int main() {
	stack<int> stack;
	queue<char> queue;
	
	if (seq(stack, queue)) {
		while (!queue.empty()) {
			cout << queue.front() << endl;
			queue.pop();
		}
	}
	else {
		cout << "NO";
	}
}