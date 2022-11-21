#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, d;
		cin >> n >> d;
		int temp;
		vector<int>arr;
		
		for (int i = 0; i < n; i++) {
			cin >> temp;
			arr.push_back(temp);
		}
		int cnt = 0;
		for (int i = 0; i < n-d; i++) {
			vector<int>sorted_arr;
			for (int j = 0; j < d; j++) {
				sorted_arr.push_back(arr[i+j]);
			}
			sort(sorted_arr.begin(), sorted_arr.end());
			double mid=0;
			if (d % 2 == 0) {
				int mid1 = d / 2;
				int mid2 = d / 2 - 1;
				mid = double(sorted_arr[mid1] + sorted_arr[mid2]) / 2;
			}
			else if (d % 2 == 1) {
				mid = sorted_arr[d / 2];
			}
			if (2 * mid <= arr[d + i])
				cnt++;
		}
		cout << cnt << "\n";
	}
}