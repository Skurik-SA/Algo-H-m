#include <iostream>

using namespace std;

struct Node
{
	Node()
	{
		left = NULL;
		right = NULL;
	}
	int val;
	Node* left, * right;
}*root = NULL;

//Добавление

int ADD(Node** root, int val)
{

	Node* ToAdd = new Node;
	ToAdd->val = val;
	int temph = 1;

	if (*root == NULL)
	{
		*root = ToAdd;
	}

	else
	{
		Node* cur = *root;
		Node* prev = *root;

		//Поиск элемента перед добавляемым
		while (cur != NULL)
		{

			prev = cur;
			if (val > cur->val)
			{
				temph++;
				cur = cur->right;
			}

			else if (val < cur->val)
			{
				temph++;
				cur = cur->left;
			}

			else if (val == cur->val)
			{
				delete ToAdd;
				return temph;
			}
		}

		//Присвоение

		if (val > prev->val)
		{
			prev->right = ToAdd;
		}

		else if (val < prev->val)
		{
			prev->left = ToAdd;
		}
	}
	return temph;
}


int main()
{
	int temp;
	cin >> temp;
	int h = 0, temph;
	int n = 1;
	while (temp != 0)
	{
		temph = ADD(&root, temp);
		n++;
		if (temph > h)
		{
			h = temph;
		}
		cin >> temp;
	}
	cout << h;
}