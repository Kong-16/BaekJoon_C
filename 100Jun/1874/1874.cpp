#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool seq(stack<int>& stack, queue<char>& queue) {
	int sequenceNum, inputNum, stackNum;

	cin >> sequenceNum;

	stackNum = 1;
	stack.push(0);

	for (int i = 0; i < sequenceNum; i++) {
		cin >> inputNum;
		if (inputNum > stackNum) { //push
			while (inputNum == stackNum + 1) {
				stack.push(stackNum);
				queue.push('+');
				stackNum++;
			}
		}
		else { //pop
			if (stack.top() == inputNum) {
				stack.pop();
				queue.push('-');
			}
			else {
				return false;
			}
		}
	}
	return true;
}



int main() {
	stack<int> stack;
	queue<char> queue;
	
	if (seq(stack, queue)) {

	}
	else {
		cout << ""
	}
}