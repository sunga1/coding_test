#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<long long>v(N);
		long long temp;
		for (int i = 0; i <N; i++) {
			cin >> temp;
			v[i] = temp;
		}
		sort(v.begin(), v.end());
		long long p, q, X;
		cin >> p >> q >> X;
		int count = 0;
		do {
			temp=0;
			for (int i = 0; i < N; i++) {
				//cout << v[i] << " ";
				temp += v[i] * pow(X, i);
				
			}
			//cout << temp << "\n";
			if (p <= (temp%1013) && (temp % 1013) <= q)
				count++;
		} while (next_permutation(v.begin(), v.end()));
		cout << count << "\n";
	}
}