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
			arr.push_back(temp);//arr에 칼로리값 저장
		}
		int cnt = 0;
		int count[201] = { 0 };//각 칼로리마다 몇번 입력되었는지 카운트,중앙값 sort없이 찾기위해
		for (int j = 0; j < d; j++) {
			count[arr[j]]++;
		}
		for (int i = 0; i < n - d; i++) {
			double mid_val = 0;//칼로리 중앙값 저장
			if (d % 2 == 0) {
				int mid1 = d / 2;
				int mid2 = d / 2 +1;
				int cnt = 0;
				for (int k = 0; k < 201; k++) {
					cnt += count[k];
					if (mid_val == 0) {//두번째 중앙값 저장하기 위해 
						if (mid1 <= cnt)
							mid_val += k;//첫번째 중앙값 저장
					}
					if (mid2 <= cnt) {
						mid_val += k;//두번째 중앙값 저장
						break;
					}
				}
				mid_val /= 2;
			}
			else if (d % 2 == 1) {
				int mid = d / 2+1;
				int cnt = 0;
				for (int k = 0; k < 201; k++) {
					cnt += count[k];
					if (mid <= cnt) {
						mid_val += k;
						break;
					}
				}
			}
			if (2 * mid_val <= arr[d + i])
				cnt++;
			count[arr[i]]--;//맨 앞 칼로리 제거
			count[arr[i + d]]++;// 칼로리 하나 추가
		}
		cout << cnt << "\n";
	}
}