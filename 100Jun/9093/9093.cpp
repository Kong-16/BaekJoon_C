#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> s;
	int i, num;

	
	cin >> num;
	cin.ignore();

	for (int j = 0; j < num; j++) {
		string str;
		getline(cin,str);

		i = 0;
		while (i < str.length()) {
			if (str[i] == ' ') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << str[i];
			}
			else s.push(str[i]);
			i++;
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}

}