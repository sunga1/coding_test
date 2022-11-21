#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main() {
	int n, m, u, v;
	int minDepth;//감염된 지역중 depth최소인 지역
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<int>que;
		bool check[100000] = { false };//각 지역별 탐색 유무 저장
		int parent[100000] = { 0 }, infected[100000] = { 0 };//트리의 부모,감염된 지역
		int depth[100000] = { 0 };
		fill_n(depth, 100000, -1);
		cin >> n >> m;
		vector<vector<int>> road(n + 1);//트리의 연결 정보를 저장
		for (int j = 1; j < n; j++) {
			cin >> u >> v;
			road[u].push_back(v);//그래프로 간주하면, adjacency list
			road[v].push_back(u);
		}
		que.push(1);
		depth[1] = 0;
		while (que.empty() == false) {//루트인 1번 노드부터 BFS로
			int now = que.front();//탐색하면서 depth 계산 및 부모 찾기
			que.pop();
			for (int k = 0; k < road[now].size(); k++) {
				if (depth[road[now][k]] == -1) {//unexplored의미
					que.push(road[now][k]);
					depth[road[now][k]] = depth[now] + 1;
					parent[road[now][k]] = now;
				}
			}
		}
		minDepth = n;
		for (int j = 0; j < m; j++) {//감염된 지역 중 depth의 최솟값을 계산
			cin >> infected[j];
			minDepth = min(minDepth, depth[infected[j]]);
		}
		for (int j = 0; j < m; j++) {//감염된 지역들의 depth를 일치시킴
			while (depth[infected[j]] > minDepth) {
				if (check[infected[j]] == true)
					break;
				check[infected[j]] = true;
				infected[j] = parent[infected[j]];
			}
			if (check[infected[j]] == false) {
				que.push(infected[j]);
				check[infected[j]] = true;
			}
		}
		while (que.size() > 1) {//감염된 지역들의 depth를 1씩 감소시키며
			int now = que.front();//공통 조상을 찾음
			que.pop();
			if (check[parent[now]] == false) {
				que.push(parent[now]);
				check[parent[now]] = true;
			}
		}
		int LCA = que.front();
		if (LCA == 1)
			cout << -1 << "\n";
		else
			cout << min(LCA, parent[LCA]) << " " << max(LCA, parent[LCA]) << "\n";
	}
}