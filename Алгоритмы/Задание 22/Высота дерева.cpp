#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* left, * right;

	Node()
	{
		left = NULL;
		right = NULL;
	}

}*root = NULL;

//Добавление

int ADD(Node** root, int val)
{
	Node* temp = new Node;
	temp->val = val;
	
	int len = 1;

	if (*root == NULL)
	{
		*root = temp;
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
				len++;
				cur = cur->right;
			}
			else if (val < cur->val)
			{
				len++;
				cur = cur->left;
			}
			else if (val == cur->val)
			{
				delete temp;
				return len;
			}
		}

		//Присвоение

		if (val > prev->val)
		{
			prev->right = temp;
		}

		else if (val < prev->val)
		{
			prev->left = temp;
		}
	}
	return len;
}


int main()
{
	int value;
	cin >> value;
	int h = 0,
		n = 1,
		len;

	while (value != 0)
	{
		len = ADD(&root, value);
		n++;

		if (len > h)
		{
			h = len;
		}

		cin >> value;
	}

	cout << h;
}