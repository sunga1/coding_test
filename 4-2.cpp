#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>loc(n + 1);
		vector<vector<int>>parent(n + 1);
		vector<int>depth(n + 1, 0);
		vector<bool>check(n + 1, false);
		int loc1, loc2;
		parent[1].push_back(0);
		for (int i = 1; i < n; i++) {
			cin >> loc1 >> loc2;
			loc[loc1].push_back(loc2);
			loc[loc2].push_back(loc1);
		}
		depth[1] = 1;
		int high = 1;
		vector<int>q;
		q.push_back(1);
		while (!q.empty()) {
			high = q.back();
			q.pop_back();
			for (int j = 0; j < loc[high].size(); j++) {
				if (depth[loc[high][j]] == 0) {
					depth[loc[high][j]] = depth[high]+1;
					parent[loc[high][j]].push_back(high);
					q.push_back(loc[high][j]);
				}
			}
		}
		/*for (int i = 1; i <= n; i++) {
			cout << parent[i][0] << " ";
		}*/

		vector<int>dirty_loc;
		int temp;
		int min = 100000;
		for (int i = 0; i < m; i++) {
			cin >> temp;
			dirty_loc.push_back(temp);
			if (min > depth[temp])
				min = depth[temp];
		}
		queue<int>qq;
		for (int i = 0; i < m; i++) {
			while (depth[dirty_loc[i]] > min) {
				if (check[dirty_loc[i]] == true)
					break;
				check[dirty_loc[i]] = true;
				dirty_loc[i] = parent[dirty_loc[i]][0];
			}
			if (check[dirty_loc[i]] == false) {
				check[dirty_loc[i]] = true;
				qq.push(dirty_loc[i]);
			}
		}
		
		while (qq.size()>1) {
			int t = qq.front();
			qq.pop();
			t = parent[t][0];
			if (check[t] == false) {
				check[t] = true;
				qq.push(t);
			}

		}
		int root = qq.front();
		if (root == 1)
			cout << -1<<"\n";
		else {
			int p = parent[root][0];
			int c = root;
			if (p < c) {
				cout << p << " " << c << "\n";
			}
			else
				cout << c << " " << p << "\n";
			
		}
	}
}