#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string s;
		int cnt = 0;
		int tot_n = 0;
		int max = 0;
		cin >> s;
		int pointer = 0;
		int c_cnt=0, t_cnt = 0;
		int max_pos;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'C')
				c_cnt++;
			else
				t_cnt++;
		}
		if (c_cnt > t_cnt) {
			max_pos = t_cnt;
		}
		else
			max_pos = c_cnt;
		while(pointer< s.size()) {
			tot_n = 0; cnt = 0;
			for (int j = pointer; j < s.size(); j++) {
				if (s[j] == 'C')
					cnt++;
				else 
					cnt--;
				tot_n++;
				if (cnt == 0) {
					if (max < tot_n)
						max = tot_n;
					
				}
				if (cnt < 0) {
					if (pointer == 0)
						pointer += tot_n;
					else
						pointer += (++tot_n);
					break;
				}
				if (j == s.size() - 1)
					pointer++;
				
			}
			if (max == (s.size() - pointer + 1))
				break;
				
			if (max == max_pos)
				break;
		}
		cout << max << "\n";
	}
}