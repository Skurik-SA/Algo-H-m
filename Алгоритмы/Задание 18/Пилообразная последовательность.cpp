#include <iostream>
#include <vector>
using namespace std;

int ko()
{
	int n,
		k = 0,
		ans = 0;
	vector<int> numbers;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);

		if (numbers.size() > 2)
		{
			int first = numbers.size() - 3;
			int second = numbers.size() - 2;
			int third = numbers.size() - 1;

			if ((numbers[first] < numbers[second] && (numbers[second] > numbers[third])))
			{
				continue;
			}

			if ((numbers[first] > numbers[second]) && (numbers[second] < numbers[third]))
			{
				continue;
			}

			numbers.erase(numbers.begin() + second);

			ans++;
		}

		k++;
	}

	if ((k == n) && (numbers.size() == 2) && (numbers[0]) == numbers[1])
	{
		ans++;
		return ans;
	}
	else if (n == 1)
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