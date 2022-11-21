#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int M, N;
		cin >> M >> N;
		vector<string>s_v(M);
		string s;
		for (int i = 0; i < M; i++) {
			cin >> s;
			s_v[i] = s;
		}
		int L; string t_s;
		cin >> L >>t_s;
		int v_cnt = L / N;
		vector<vector<char>>ans_vec(v_cnt);
		int row = 0, column = 0;
		for (int i = 0; i < t_s.size();i++) {
			if (column == N) {
				row++;
				column = 0;
			}
			ans_vec[row].push_back(t_s[i]);
			column++;
		}
		int dif_cnt;
		
		vector<int>answer(v_cnt);
		for(int i=0;i<v_cnt;i++){
			dif_cnt = 0;
			vector<int>find_cor(M, 0);
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < N; k++) {
					if (ans_vec[i][k] != s_v[j][k]) {
						find_cor[j]++;
					}
				}
			}
			/*for (int j = 0; j < M; j++) {
				cout << find_cor[j] << " ";
			}*/
			int min=128;
			int min_p = 0;
			for (int j = 0; j < M; j++) {
				if (min > find_cor[j]) {
					min = find_cor[j];
					min_p = j;
				}
			}
			answer[i] = min_p;
		}
		for (int i = 0; i < v_cnt; i++) {
			char a = char(answer[i]) + 'A';
			cout << a ;
		}
		cout << "\n";
	}
	
}

