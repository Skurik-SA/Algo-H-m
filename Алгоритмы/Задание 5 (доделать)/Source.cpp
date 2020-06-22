#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
string F_line, S_line;

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

	if (vec[len1][len2] == -1) 
	{
		vec[len1][len2] = 1 + func(len1 - 1, len2);
		vec[len1][len2] = min(vec[len1][len2], 1 + func(len1, len2 - 1));
		
		if (F_line[len1] == S_line[len2]) 
		{
			vec[len1][len2] = min(func(len1 - 1, len2 - 1), vec[len1][len2]);
		}
		else 
		{
			vec[len1][len2] = min(vec[len1][len2], 1 + func(len1 - 1, len2 - 1));
		}
	}

	return vec[len1][len2];
}

int main()
{
	int n, m;
	cin >> n >> F_line >> m >> S_line;

	for (int i = 0; i < F_line.length(); i++)
	{
		vector<int> arr;
		
		for (int j = 0; j < S_line.length(); j++)
		{
			arr.push_back(-1);
		}
		
		vec.push_back(arr);
	}

	cout << func(F_line.length() - 1, S_line.length() - 1) << endl;
}