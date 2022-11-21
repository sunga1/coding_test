#include<iostream>
#include<cmath>

using namespace std;


int main() {
	int N, i = 2;
	long long answer[2];
	
	cin >> N;
	while (pow(2, i - 1) < N) {
		answer[0] += (i - 1) * pow(2, i - 2);
		answer[1] += (i - 1) * pow(2, i - 2) + pow(2, i - 1);
		i += 1;
	}
	answer[0] += i - 1;
	answer[1] += 2;
	cout << answer[0] << " " << answer[1];
}

