#include <iostream>

using namespace std;

void DoUKnowDaWay(int N, int S, bool** map, bool* IsConected) 
{
	for (int i = 0; i < N; i++) 
	{
		if (map[S][i] && !IsConected[i]) 
		{
			IsConected[i] = 1;
			DoUKnowDaWay(N, i, map, IsConected);
		}
	}
}

int main() 
{
	int N, S;
	cin >> N >> S;
	S--;

	bool* IsConected = new bool[N];
	bool** map = new bool* [N];

	for (int i = 0; i < N; i++) 
	{
		map[i] = new bool[N];
		IsConected[i] = 0;

		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	IsConected[S] = 1;

	DoUKnowDaWay(N, S, map, IsConected);

	int res = 0;

	for (int i = 0; i < N; i++)
	{
		res += IsConected[i];
	}

	cout << res;
}