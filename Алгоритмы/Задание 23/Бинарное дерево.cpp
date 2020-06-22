#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	int val;
	Node* right = NULL;
	Node* left = NULL;
};

struct List
{
	Node* root = NULL;
};
List L;

bool ADD(List& l, int x)
{
	Node* ToAdd = new Node;
	ToAdd->val = x;
	if (l.root == NULL)
	{
		l.root = ToAdd;
		return 1;
	}
	else
	{
		Node* prew = l.root;
		Node* cur = l.root;
		while (cur != NULL)
		{
			prew = cur;
			if (x > cur->val)
				cur = cur->right;
			else if (x < cur->val)
				cur = cur->left;
			else
			{
				delete ToAdd;
				return 0;
			}
		}
		if (x > prew->val)
		{
			prew->right = ToAdd;
		}
		else
		{
			prew->left = ToAdd;
		}
		return 1;
	}
}

void Print(Node* cur, int lvl)
{
	if (cur == NULL)
		return;
	Print(cur->left, lvl + 1);
	for (int i = 0; i < lvl; i++)
		cout << '.';
	cout << cur->val << endl;
	Print(cur->right, lvl + 1);
}

void Dell(List& l, int val)
{
	if (l.root != NULL)
	{
		Node* Cur = l.root;
		Node* Prew = l.root;
		while (Cur != NULL)
		{
			Prew = Cur;
			if (Cur->val > val)
			{
				Cur = Cur->left;
			}
			else if (Cur->val < val)
			{
				Cur = Cur->right;
			}
			else break;
		}
		if (Cur != NULL)
		{
			if (Cur->right == NULL)
			{
				if (Cur == l.root)
				{
					if (Cur->left == NULL)
					{
						l.root = NULL;
					}
				}
				if (Prew->left == Cur)
					Prew->left = Cur->left;
				else
					Prew->right = Cur->left;
				delete Cur;
				cout << "DONE" << endl;
				return;
			}
			else if (Cur->left == NULL)
			{
				if (Cur == l.root)
				{
					if (Cur->right == NULL)
					{
						l.root = NULL;
					}
				}
				if (Prew->left == Cur)
					Prew->left = Cur->right;
				else
					Prew->right = Cur->right;
				delete Cur;
				cout << "DONE" << endl;
				return;
			}
			else
			{
				int NewVal;
				Prew = Cur->left;
				while (Prew->right != NULL)
				{
					Prew = Prew->right;
				}
				NewVal = Prew->val;
				Dell(l, NewVal);
				Cur->val = NewVal;
			}
		}
		else
		{
			cout << "CANNOT" << endl;
		}
	}
	else
	{
		cout << "CANNOT" << endl;
	}
}

void Search(Node* cur, int val)
{
	if (cur == NULL)
	{
		cout << "NO" << endl;
		return;
	}
	if (val == cur->val)
	{
		cout << "YES" << endl;
		return;
	}
	if (val > cur->val)
		Search(cur->right, val);
	else
		Search(cur->left, val);
}

int main()
{
	ifstream F("input.txt");
	string Com;
	int N;
	while (F >> Com)
	{
		if (Com == "ADD")
		{
			F >> N;
			if (ADD(L, N))
				cout << "DONE" << endl;
			else
				cout << "ALREADY" << endl;
		}
		else if (Com == "SEARCH")
		{
			F >> N;
			Search(L.root, N);
		}
		else if (Com == "DELETE")
		{
			F >> N;
			Dell(L, N);
		}
		else if (Com == "PRINTTREE")
		{
			Print(L.root, 0);
		}

	}
	F.close();
}