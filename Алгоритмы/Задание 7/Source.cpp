#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	

	int counter = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			counter++;
		}
	}

	if (str[str.size() - 1] == 'e' && counter % 2 == 0)
	{
		str[str.size() - 1] = '0';
	}
	else if (str[str.size() - 1] == 'e' && counter % 2 == 1)
	{
		str[str.size() - 1] = '1';
	}
	else if (str[str.size() - 1] == 'o' && counter % 2 == 0)
	{
		str[str.size() - 1] = '1';
	}
	else if (str[str.size() - 1] == 'o' && counter % 2 == 1)
	{
		str[str.size() - 1] = '0';
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	return 0;
}