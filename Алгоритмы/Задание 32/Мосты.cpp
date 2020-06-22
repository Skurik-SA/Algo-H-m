#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector <bool>> map;

	string* towns = new string[N];

	for (int i = 0; i < N; i++)
	{
		vector<bool> temp;

		for (int j = 0; j < N; j++)
		{
			int temp2;
			cin >> temp2;
			temp.push_back(temp2);
		}

		map.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> towns[i];
	}

	int B = 0,
		M = 0;

	for (int i = 0; i < N - 1; i++) 
	{
		for (int j = 1 + i; j < N; j++)
		{
			if (map[i][j])
			{
				if (towns[i] == towns[j])
				{
					B++;
				}
				else
				{
					M++;
				}
			}
		}
	}

	cout << B << ' ' << M;

	return 0;
}