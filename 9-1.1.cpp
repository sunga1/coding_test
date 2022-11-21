#include<iostream>
using namespace std;

int dist[1001][1001];
int edit_distance(string& input1, string& input2) {
	
	for (int j = 0; j <= input1.length(); j++)
		dist[0][j]=j;
	for (int i = 0; i <= input2.length(); i++) 
		dist[i][0]=i;
	for (int i = 1; i <= input2.length(); i++) {
		for (int j = 1; j <= input1.length(); j++) {
			if (input2[i - 1] == input1[j - 1])
				dist[i][j] = dist[i - 1][j - 1];
			else
				dist[i][j] = min(dist[i - 1][j - 1] + 1, min(dist[i - 1][j] + 1, dist[i][j - 1] + 1));
		}
	}
	return dist[input2.length()][input1.length()];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string X, Y;
		cin >> X >> Y;
		cout<<edit_distance(X, Y)<<"\n";
		
	}
}