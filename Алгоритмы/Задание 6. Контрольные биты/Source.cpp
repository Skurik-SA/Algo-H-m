#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	vector<int> a, a1, out(21);
	vector<int> b, a2;
	char ch1, ch2;
	cin >> ch1 >> ch2;
	int l1 = int(ch1);
	int l2 = int(ch2);
	cout << l1 << " " << l2 << endl;

	for (int i = 7; i >= 0; i--)
	{
		a.push_back((ch1 >> i) % 2);
		a1.push_back((ch2 >> i) % 2);
	}

	for (int i = 0; i < a.size() + a1.size(); i++)
	{
		if (i < a.size())
		{
			b.push_back(a[i]);
		}
		else
		{
			b.push_back(a1[i - a.size()]);
		}
	}

	for (int i = 0, j = 1, s = 0; i < 16; s++)
	{
		if (i == j - 1)
		{
			j *= 2; 
			continue;
		}
		out[s] = b[i++];
	}

	cout << endl;


	int temp;
	for (int i = 1; i < 21; i *= 2)
	{
		out[i - 1] = 0;
		temp = 0;
		for (int j = i - 1; j < 21; j += 2 * i)
		{
			for (int k = 0; k < i && j + k < 21; k++)
			{
				temp += out[j + k];
			}
		}
		out[i - 1] = temp % 2;
	}

	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i];
	}

	cout << endl;

	for (int i = 0; i < out.size(); i++)
	{
		cout << out[i];
	}

	cout << endl;


	return 0;
}
