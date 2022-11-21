#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		stack<int>stack;
		string S;
		int len, maxlen = 0;
		cin >> S;
		stack.push(0);
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == 'C') {
				stack.push(i + 1);
			}
			else if (S[i] == 'T') {
				if (stack.size() != 1) {
					stack.pop();
					len = (i + 1) - stack.top();
					if (maxlen < len) {
						maxlen = len;
					}
				}
				else {
					stack.pop();
					stack.push(i+1);
				}
			}
			
		}
		cout << maxlen << endl;

	}
}