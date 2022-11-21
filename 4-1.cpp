#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		cin >> N >> K;

		multimap<int, int,greater<int>>m;
		multimap<int,int>::iterator iter;
		multiset<int,greater<int>>s;
		vector<int>weight;
		vector<int>per_price;
		int temp;
		int total = 0;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			weight.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			cin >> temp;
			per_price.push_back(temp/weight[i]);
		}
		for (int i = 0; i < N; i++) {
			m.insert(pair<int, int>(per_price[i], weight[i]));
			
		}
		iter = m.begin();
		int max_cnt = 0;
		int h = 0;
		for (iter; iter != m.end();iter++) {
			h = max_cnt + iter->second;
			if (h > K)
				break;
			total += (iter->second*iter->first );
			
			max_cnt += iter->second;
			
		
			
		}
		if (max_cnt != K) {
			if(iter!=m.end())
			total += (K-max_cnt) * iter->first;
			
		}
		cout << total << "\n";
	}
}