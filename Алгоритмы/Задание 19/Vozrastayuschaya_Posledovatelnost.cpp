#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> mas, len, res;

	cin >> n;
	mas.resize(n); // содержит n элементов
	len.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}


	for (int i = 0; i < n; i++)
	{
		int maxLen = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (mas[j] < mas[i] && len[j] > maxLen)
			{
				maxLen = len[j];
			}
		}

		len[i] = maxLen + 1;
	}

	vector<int>::iterator ItPos = max_element(len.begin(), len.end());
	int lastPos = ItPos - len.begin();

	int amount = len[lastPos];

	res.resize(amount);

	int pos = amount - 1;

	for (int i = lastPos; i >= 0; i--)
	{
		if (len[i] == amount)
		{
			res[pos--] = mas[i];
			amount--;
		}
	}

	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}