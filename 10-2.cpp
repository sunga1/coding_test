#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>>shark(N);
		vector<int>aquarium(M);
		priority_queue<pair<int, int>> pq;
		int answer = 0;
		for (int i = 0; i < N; i++) {
			cin >> shark[i].first >> shark[i].second;
		}
		for (int i = 0; i < M; i++) {
			cin >> aquarium[i];
		}
		sort(aquarium.begin(), aquarium.end());
		sort(shark.begin(), shark.end());
		int j = 0;
		for (int i = 0; i < M; i++) {
			while (j < N && shark[j].first <= aquarium[i]) {
				pq.push({ shark[j].second, shark[j].first });
				j = j + 1;
			}
			while (pq.empty() == false && pq.top().first < aquarium[j])
				pq.pop();
			if (pq.empty() == false) {
				pq.pop();
				answer++;
			}
		}
		cout << answer<<"\n";
	}
}