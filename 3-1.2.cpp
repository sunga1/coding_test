#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	int n, d;
	while (T--) {
		cin >> n >> d;
		int arr[201] = { 0 };
		vector<int>t;
		int temp;
		int cnt = 0;
		while (n--) {
			cin >> temp;
			t.push_back(temp);
		}
		int i;
		for (int j = 0; j < n - d; j++) {
			for (i = j; i < d+j-1; i++) {
				arr[t[i]]++;
			}
			int count = 0;
			double mid;
			if (d % 2 == 0) {
				int mid1 = 0; int mid2 = 0;
				int m1 = d / 2;
				int m2 = d / 2 + 1;
				for (i = 1; i < n; i++) {
					count += t[i];
					if (mid1 == 0 && count >= m1) {
						mid1 = i;
					}
					if (count >= m2) {
						mid2 = i;
						break;
					}
				}
				mid = double(mid1 + mid2) / 2;
			}
			else {
				int m = d / 2 + 1;
				for (i = 0; i < n; i++) {
					count += t[i];
					if (count >= m) {
						mid = i;
						break;
					}
				}
			}
			if (mid * 2 <= t[j + d]) {
				cnt++;
			}
			arr[t[j]]--;
		}
	}
}