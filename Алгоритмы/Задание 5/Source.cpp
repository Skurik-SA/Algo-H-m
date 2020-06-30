#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Arr;
string F_L, S_L;

int func(int len1, int len2) 
{
	if (len1 < 0)
	{
		return len2 + 1;
	}

	if (len2 < 0)
	{
		return len1 + 1;
	}

	if (Arr[len1][len2] == -1) 
	{
		Arr[len1][len2] = 1 + func(len1 - 1, len2);
		Arr[len1][len2] = min(Arr[len1][len2], 1 + func(len1, len2 - 1));
		
		if (F_L[len1] == S_L[len2]) 
		{
			Arr[len1][len2] = min(func(len1 - 1, len2 - 1), Arr[len1][len2]);
		}
		else 
		{
			Arr[len1][len2] = min(Arr[len1][len2], 1 + func(len1 - 1, len2 - 1));
		}
	}

	return Arr[len1][len2];
}

int main()
{
	int n, m;
	cin >> n >> F_L >> m >> S_L;

	for (int i = 0; i < F_L.length(); i++)
	{
		vector<int> arr;
		
		for (int j = 0; j < S_L.length(); j++)
		{
			arr.push_back(-1);
		}
		
		Arr.push_back(arr);
	}

	cout << func(F_L.length() - 1, S_L.length() - 1) << endl;
}