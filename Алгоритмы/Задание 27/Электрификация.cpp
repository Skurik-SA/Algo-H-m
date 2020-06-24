#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

struct lol 
{
    int x;
    int y;
};

class Graph 
{
private:
    vector<pair<int, edge>> G; // graph
    vector<pair<int, edge>> T; // mst
    int* parent;
    int V; // number of vertices/nodes in graph

public:
    Graph(int V);

    void AddWeightedEdge(int u, int v, int w);

    int find_set(int i);

    void union_set(int u, int v);

    void kruskal();

    void print(vector<lol> &V);
};

Graph::Graph(int V) // конструктор
{
    parent = new int[V];

    //i 0 1 2 3 4 5
    //parent[i] 0 1 2 3 4 5
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w) // Добавить грань
{
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i)
{
    // Если i элемент - родитель
    if (i == parent[i])
        return i;
    else
        // Иначе если i элемент не родитель
        // То i элемент не входит в набор,
        // поэтому мы рекурсивно вызываем find_set для его нахождения его родителя

        return find_set(parent[i]);
}

void Graph::union_set(int u, int v) 
{
    parent[u] = parent[v];
}

void Graph::kruskal() 
{
    int i, 
		uRep, 
		vRep;

    sort(G.begin(), G.end()); 

    for (i = 0; i < G.size(); i++) 
	{
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);

        if (uRep != vRep) 
		{
            T.push_back(G[i]); // Добавить в дерево
            union_set(uRep, vRep);
        }
    }
}

void Graph::print(vector<lol> &V) 
{
    for (int i = 0; i < T.size(); i++) 
	{
        lol tmp;
        tmp.x = int(T[i].second.first) + 1;
        tmp.y = int(T[i].second.second) + 1;
        V.push_back(tmp);
        //cout << int(T[i].second.first) + 1 << " - " << int(T[i].second.second) + 1;
        //cout << endl;
    }
}

int main() 
{
    ifstream fin("input.txt");
    int n;
    in >> n;
    Graph g(n);
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
            if (mas[i][j])
                g.AddWeightedEdge(i, j, mas[i][j]);
        }
    }

    vector<lol> V;

    g.kruskal();
    g.print(V);

	for (int i = 0; i < V.size() - 1; i++)
	{
		for (int j = 0; j < V.size() - 1 - i; j++)
		{
			if (V[j].x > V[j + 1].x)
			{
				swap(V[j], V[j + 1]);
			}
			else
			{
				if (V[j].x == V[j + 1].x)
				{
					if (V[j].y > V[j + 1].y)
					{
						swap(V[j], V[j + 1]);
					}
				}
			}
		}
	}

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i].x << " " << V[i].y << endl;
	}

    fin.close();
}