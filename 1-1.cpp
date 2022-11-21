#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		vector<int>n1(n,0);
		vector<int>n2(m, 0);
		vector<int>answer(2, 0);
		int min_gcd = 0;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			n1[i]=temp;
		}
		
		if (n < 2) {
			min_gcd = n1[0];
		}
		else
		min_gcd = gcd(n1[0], n1[1]);

		for (int i = 2; i < n ; i++) {
			min_gcd = gcd(min_gcd, n1[i]);
		
		}
		answer[1] = min_gcd;
		
		
		for (int i = 0; i < m; i++) {
			cin >> temp;
			n2[i]=temp;
		}
		if (m < 2) {
			min_gcd = n2[0];
		}
		else
		min_gcd = gcd(n2[0], n2[1]);
		for (int i = 2; i < m; i++) {
			min_gcd = gcd(min_gcd, n2[i]);
		}
		answer[0] = min_gcd;
		for (int i = 0; i < n; i++) {
			if (n1[i] % answer[0] == 0) {
				answer[0] = -1;
				break;
			}
		}
		
		for (int i = 0; i < m; i++) {
			if (n2[i] % answer[1] == 0) {
				answer[1] = -1;
				break;
			}
		}
		cout << answer[0] << " " << answer[1] << "\n";
	}
}

int gcd(int a,int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}