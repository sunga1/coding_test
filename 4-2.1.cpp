#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main() {
	int n, m, u, v;
	int minDepth;//������ ������ depth�ּ��� ����
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		queue<int>que;
		bool check[100000] = { false };//�� ������ Ž�� ���� ����
		int parent[100000] = { 0 }, infected[100000] = { 0 };//Ʈ���� �θ�,������ ����
		int depth[100000] = { 0 };
		fill_n(depth, 100000, -1);
		cin >> n >> m;
		vector<vector<int>> road(n + 1);//Ʈ���� ���� ������ ����
		for (int j = 1; j < n; j++) {
			cin >> u >> v;
			road[u].push_back(v);//�׷����� �����ϸ�, adjacency list
			road[v].push_back(u);
		}
		que.push(1);
		depth[1] = 0;
		while (que.empty() == false) {//��Ʈ�� 1�� ������ BFS��
			int now = que.front();//Ž���ϸ鼭 depth ��� �� �θ� ã��
			que.pop();
			for (int k = 0; k < road[now].size(); k++) {
				if (depth[road[now][k]] == -1) {//unexplored�ǹ�
					que.push(road[now][k]);
					depth[road[now][k]] = depth[now] + 1;
					parent[road[now][k]] = now;
				}
			}
		}
		minDepth = n;
		for (int j = 0; j < m; j++) {//������ ���� �� depth�� �ּڰ��� ���
			cin >> infected[j];
			minDepth = min(minDepth, depth[infected[j]]);
		}
		for (int j = 0; j < m; j++) {//������ �������� depth�� ��ġ��Ŵ
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
		while (que.size() > 1) {//������ �������� depth�� 1�� ���ҽ�Ű��
			int now = que.front();//���� ������ ã��
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