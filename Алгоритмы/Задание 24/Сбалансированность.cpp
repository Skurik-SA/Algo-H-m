#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T data;

	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;

	int depth;
	int dif;

	Node(T value, Node<T>* par = NULL)
	{
		data = value;
		left = NULL;
		right = NULL;
		parent = par;

		depth = 1;
		dif = 0;
	}

	void Calc()
	{
		dif = (right == NULL ? 0 : right->depth) - (left == NULL ? 0 : left->depth);
	}

	bool operator >(Node<T> node)
	{
		return data > node.data;
	}
};

template<class T>
struct BinTree
{
	Node<T>* root;
	int count = 0;

	BinTree()
	{
		root = NULL;
	}

	void Add(T value)
	{
		Node<T>* temp = new Node<T>(value);

		if (count == 0)
		{
			root = temp;
			count++;
		}
		else
		{
			int res = Add(temp, root);

			if (!res)
				delete temp;
			else
				count++;
		}
	}

	bool Add(Node<T>* node, Node<T>* cur)
	{
		if (cur->data == node->data)
			return false;

		if (cur->data > node->data)
		{
			if (cur->right != NULL)
			{
				Add(node, cur->right);

				if (cur->right->depth == cur->depth)
					cur->depth++;
			}
			else
			{
				cur->right = node;

				if (cur->depth == 1)
					cur->depth++;
			}
		}
		else
		{
			if (cur->left != NULL)
			{
				Add(node, cur->left);

				if (cur->left->depth == cur->depth)
					cur->depth++;
			}
			else
			{
				cur->left = node;

				if (cur->depth == 1)
					cur->depth++;
			}
		}

		cur->Calc();

		return true;
	}

	bool Balance()
	{
		return count > 2 ? Calc(root) : true;
	}

	bool Calc(Node<T>* cur)
	{
		bool l = true;
		bool r = true;

		if (cur->left != NULL)
			l = Calc(cur->left);

		if (cur->right != NULL)
			r = Calc(cur->right);

		return (abs(cur->dif) <= 1) && l && r;
	}
};


int main()
{
	BinTree<int> bt;
	int temp;

	for (cin >> temp; temp != 0; cin >> temp)
		bt.Add(temp);

	cout << (bt.Balance() ? "YES" : "NO");

	return 0;
}