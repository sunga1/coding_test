#include<iostream>
#include<set>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int M, N;
		cin >> M >> N;
		multiset<int> mm;
		int temp;
		for (int i = 0; i < M; i++) {
			cin >> temp;
			mm.insert(temp);
		}
		string s1;
		for (int i = 0; i < N; i++) {
			cin >> s1;
			if (s1 == "Delete") {
				string s2;
				cin >> s2;
				if (s2 == "min")
					mm.erase(mm.begin());
				else
					mm.erase(--mm.end());
			}
			else if (s1 == "Add") {
				int s2;
				cin >> s2;
				int n = s2 ;
				mm.insert(n);
				/*for (auto q : mm) {
					cout << q << " ";
				}*/
			}
		}
		cout << (*mm.begin()) << " " << *(--mm.end()) << "\n";
	}
}