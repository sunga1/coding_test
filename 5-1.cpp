#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a[28] = { 0 };
		int b[28] = { 0 };
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.size(); i++) {
			int temp = s1[i] - 'A';
			a[temp]=1;
		}
		for (int i = 0; i < s2.size(); i++) {
			int temp = s2[i] - 'A';
			b[temp] = 1;
		}
		int i = 0;
		for (i; i < 28; i++) {
			if (a[i] != b[i]) {
				cout << "NO\n";
				break;
			}
		}
		if (i == 28)
			cout << "YES\n";
	}
}