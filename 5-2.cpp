#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		map<string, int>local_num;
		multimap<int, int>year_lnum;
		map<int, int>lnum_year;
		map<int, set<int, int>>node;
		set<int, int>::iterator iter;
		int N, M;
		cin >> N >> M;
		string s;
		int y;
		for (int i = 0; i < N; i++) {
			cin >> s >> y;
			local_num[s] = i;
			lnum_year[i] = y;
			year_lnum.insert(pair<int,int>(y,i));
		}
		string l1, l2; int weight;
		for (int i = 0; i < M; i++) {
			cin >> l1 >> l2 >> weight;
			int l1_num = local_num[l1];
			int l2_num = local_num[l2];
			int l1_year = lnum_year[l1_num];
			int l2_year = lnum_year[l2_num];

			if (l1_year==l2_year)
				continue;
			if (l1_year < l2_year) {
				node[l1_num].insert(l2_num,weight);
			}
			else {
				node[l2_num].insert(l1_num, weight);
			}
		}
		int max = 0;
		stack<int>stack;
		for (auto m:year_lnum) {
			for (iter = node[m.second].begin(); iter != node[m.second].end(); iter++) {
				stack.push(node[m.second][1])
			}
			
		}
	}
}