# lab_1_task_3


```
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
```
---------------------

# lab_1_task_4

```
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string getBySelectionSort(vector<double> array_vils, vector<double> array_ids);

int main()
{
	double n_count, max_vil, min_vil, medium_vil, i, j;

	freopen("sortland.in", "r", stdin);
	freopen("sortland.out", "w", stdout);

	cin >> n_count;
	vector<double> array_vils (n_count);
	vector<double> array_ids (n_count);

	for (i = 0; i < n_count; i++)
		cin >> array_vils[i];
	for (i = 0; i < n_count; i++)
		array_ids[i] = i + 1; 
		
	getBySelectionSort(array_vils, array_ids);
	return 0;
}

string getBySelectionSort(vector<double> array_vils, vector<double> array_ids){

	int j, i, k, tmp_int = 0;
	double tmp = 0;

	for (i = 0; i < array_vils.size(); i++){
		j = i;
		for (k = i; k < array_vils.size(); k++){
			if (array_vils[j] > array_vils[k])
				j = k;
		}
		
		tmp = array_vils[i];
		array_vils[i] = array_vils[j];
		array_vils[j] = tmp;	

		tmp_int = array_ids[i];
		array_ids[i] = array_ids[j];
		array_ids[j] = tmp_int;
	}

	cout << array_ids[0] << ' ' << array_ids[array_ids.size()/2] << ' ' << array_ids[array_ids.size() - 1];

	return "";
}
```
--------------------
# lab_2_task_1


