#include <iostream>
#include <vector>
using namespace std;

int ko()
{
	int N,
		k = 0,
		ans = 0;

	vector<int> Numbers;
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Numbers.push_back(temp);

		if (Numbers.size() > 2)
		{
			int first = Numbers.size() - 3;
			int second = Numbers.size() - 2;
			int third = Numbers.size() - 1;

			if ((Numbers[first] >= Numbers[second] && (Numbers[second] >= Numbers[third])) || (Numbers[first] <= Numbers[second]) && (Numbers[second] <= Numbers[third]))
			{
				Numbers.erase(Numbers.begin() + second);

				ans++;
			}
		}

		k++;
	}

	if ((k == N) && (Numbers.size() == 2) && (Numbers[0]) == Numbers[1])
	{
		ans++;
		return ans;
	}
	else if (N == 1)
	{
		return ans;
	}

	return ans;
}

int main()
{
	cout << ko();
	return 0;
}