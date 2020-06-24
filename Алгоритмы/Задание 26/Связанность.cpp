#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
#define INF 9999999


struct vivod {
    int x;
    int y;
};

int main()
{
    ifstream fin("input.txt");
    setlocale(LC_ALL, "rus");
    int n;
		fin >> n;
			int** mas = new int* [n];

    for (int i = 0; i < n; i++) 
	{
        mas[i] = new int[n];
    }

    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            fin >> mas[i][j];
        }

    }

    int no_edge;
		int* selected = new int[n];
    vector<vivod>V;

	for (int i = 0; i < n; i++)
	{
		selected[i] = 0;
	}

    no_edge = 0;
    selected[0] = true;

    int x;
    int y;

    while (no_edge < n - 1) {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++) 
		{
            if (selected[i]) 
			{
                for (int j = 0; j < n; j++) 
				{
                    if (!selected[j] && mas[i][j]) 
					{
                        if (min > mas[i][j]) 
						{
                            min = mas[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }

        vivod tmp;
        tmp.x = x + 1;
        tmp.y = y + 1;

        V.push_back(tmp);

        selected[y] = true;
        no_edge++;
    }

    bool check = true;

	for (int i = 0; i < V.size(); i++)
	{
		if (V[i].x == V[i].y) 
		{
			check = false;
			cout << "NO";
			break;
		}
	}

    if (check)
        cout << "YES";
    fin.close();
}