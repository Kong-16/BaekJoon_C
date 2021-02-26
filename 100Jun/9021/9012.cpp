#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str){
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (s.empty()) return false;
			else s.pop();
		}
	}
	return s.empty();
}

int main() {
	string str;
	int num;

	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cin >> str;
		if (check(str)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}