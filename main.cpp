#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int h, w, i, j;

	freopen("turtle.in", "r", stdin);
	freopen("turtle.out", "w", stdout);

	cin >> h >> w;
	vector<vector<int>> map (h, vector<int>(w));
	vector<vector<int>> dp_map (h, vector<int>(w));

	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			cin >> map[i][j]; 

	dp_map[0][w - 1] = map[0][w - 1];
	for (i = 1; i < h; i++)
		dp_map[i][w - 1] = dp_map[i - 1][w - 1] + map[i][w - 1];
	for (i = w - 2; i >= 0; i--)
		dp_map[0][i] = dp_map[0][i + 1] + map[0][i];

	for (i = 1; i < h; i++)
		for (j = w - 2; j >= 0; j--)
			dp_map[i][j] = max(dp_map[i - 1][j], dp_map[i][j + 1]) + map[i][j];   

	cout << dp_map[h - 1][0];

	return 0;
}