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

	int Deleted = 0;
	int counter = 0;

	while (Deleted < N - 1)
	{
		for (int i = 0; i < K; i++)
		{
			while (!Arr[counter])
			{
				counter++;

				if (counter >= N)
				{
					counter = 0;
				}
			}

			counter++;

			if (counter >= N)
			{
				counter = 0;
			}
		}

		counter--;

		if (counter < 0)
		{
			counter = N - 1;
		}

		while (!Arr[counter])
		{
			counter--;

			if (counter)
			{
				counter = N - 1;
			}
		}

		cout << counter + 1 << ' ';

		Arr[counter] = 0;
		Deleted++;
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