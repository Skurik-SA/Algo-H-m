#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	bool* Arr = new bool[N];

	for (int i = 0; i < N; i++)
	{
		Arr[i] = 1;
	}

	int losers = 0;
	int ck = 0;

	while (losers < N - 1)
	{
		for (int i = 0; i < K; i++)
		{
			while (!Arr[ck])
			{
				ck++;

				if (ck >= N)
				{
					ck = 0;
				}
			}

			ck++;

			if (ck >= N)
			{
				ck = 0;
			}
		}

		ck--;

		if (ck < 0)
		{
			ck = N - 1;
		}

		while (!Arr[ck])
		{
			ck--;

			if (ck)
			{
				ck = N - 1;
			}
		}

		cout << ck + 1 << ' ';

		Arr[ck] = 0;
		losers++;
	}

	for (int i = 0; i < N; i++)
	{
		if (Arr[i])
		{
			cout << i + 1;
			break;
		}
	}
}