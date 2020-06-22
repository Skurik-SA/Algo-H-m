#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int k;
	string cypher, word;
	cin >> cypher >> k;
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	
	for (int i = 0; i < cypher.size(); i++)
	{
		for (int j = 0; j < alph.size(); j++)
		{
			if (cypher[i] == alph[j])
			{
				int temp = j - k;
				if (temp <= 26 && temp >= 0)
				{
					word.push_back(alph[temp]);
					break;
				}
				else if (temp < 0)
				{
					temp += 26;
					word.push_back(alph[temp]);
				}
			}
		}
	}

	cout << word;

	return 0;
}