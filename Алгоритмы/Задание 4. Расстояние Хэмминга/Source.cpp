#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int count = 0;

	for (int i = 0; i < a.length() + 1; i++)
	{
		if (a[i] != b[i])
		{
			count++;
		}
	}

	cout << count;

	return 0;
}