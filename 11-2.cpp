#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m; //���� �� ,�� ��
	vector<int>team; //���μ����� ����ȣ
	vector<pair<int, int>>score(n); //<��������,����ȣ>
	vector<int>chance(m); //chance[i]=j; �������� ������ i���� ���� ������ jȸ ���
	int rest; //������ �ø��� �ִ� �������� ��
	int answer; //����

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> team[i];
		score[team[i]].first += n - i + 1; //�� ���� ���� 
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