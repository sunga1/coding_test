#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m; //선수 수 ,팀 수
	vector<int>team; //개인순위별 팀번호
	vector<pair<int, int>>score(n); //<팀의점수,팀번호>
	vector<int>chance(m); //chance[i]=j; 인하팀의 선수가 i번의 팀의 선수와 j회 대결
	int rest; //순위를 올릴수 있는 인하팀의 수
	int answer; //정답

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> team[i];
		score[team[i]].first += n - i + 1; //각 팀의 점수 
		score[team[i]].second = team[i];
		if ((i != 1 && team[i] == 1) && team[i - 1] != team[i]) {
			rest += 1;
			chance[team[i - 1]] += 1;
		}
	}
	sort(score.begin(), score.end());
	while (rest > 0) {
		if (score[m].second == 1&&score[m].first>score[m-1].first) {
			break;
		}
		bool flag = true;
		for (int i = m; i > 0; i--) {
			if (score[i].second == 1)
				score[i].first += 1;
			if(score[])
		}
	}
}