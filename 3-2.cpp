#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string money;
		cin >> money;
		int day = 0;
		for (int i =money.size()-1; i >=0; i--) {
			int temp = money[i] - '0';
			if (temp > 5) {
				day += (10 - temp);
				if (i == 0)
					day++;
				else
					money[i -1]++;
			}
			else if (temp == 5) {
				int t = 0;
				if(i!=0) {
					t = money[i - 1] - '0';
					if (t >= 5) {
						money[i - 1]++;
					}
				}
				day += temp;
			}
			else
				day += temp;
		}
		cout << day<<"\n";
	}
}