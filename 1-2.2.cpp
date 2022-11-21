#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		stack<int>stack;
		stack.push(0);
		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'C') {
				stack.push(i+1);
			}
			else {
				if (stack.size() != 1) {
					stack.pop();
					int temp = i+1-stack.top();

					if (temp > max)
						max=temp;
				}
				else {
					stack.pop();
					stack.push(i + 1);
				}
			}
		}
		cout << max << "\n";
	}
}