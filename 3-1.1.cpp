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
			arr.push_back(temp);//arr�� Į�θ��� ����
		}
		int cnt = 0;
		int count[201] = { 0 };//�� Į�θ����� ��� �ԷµǾ����� ī��Ʈ,�߾Ӱ� sort���� ã������
		for (int j = 0; j < d; j++) {
			count[arr[j]]++;
		}
		for (int i = 0; i < n - d; i++) {
			double mid_val = 0;//Į�θ� �߾Ӱ� ����
			if (d % 2 == 0) {
				int mid1 = d / 2;
				int mid2 = d / 2 +1;
				int cnt = 0;
				for (int k = 0; k < 201; k++) {
					cnt += count[k];
					if (mid_val == 0) {//�ι�° �߾Ӱ� �����ϱ� ���� 
						if (mid1 <= cnt)
							mid_val += k;//ù��° �߾Ӱ� ����
					}
					if (mid2 <= cnt) {
						mid_val += k;//�ι�° �߾Ӱ� ����
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
			count[arr[i]]--;//�� �� Į�θ� ����
			count[arr[i + d]]++;// Į�θ� �ϳ� �߰�
		}
		cout << cnt << "\n";
	}
}