#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a, b;
    vector<vector<int>> arr_num;
	freopen("aplusb.in", "r", stdin);
	freopen("aplusb.out", "w", stdout);
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}