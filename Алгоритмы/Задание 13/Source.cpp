#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<string> word;
vector<int> num;

struct Node
{
	int count;
	string val;
	Node* prev;
	Node* next;

	Node()
	{
		next = NULL;
		prev = NULL;
		count = 0;
	}

	Node(string val)
	{
		this->next = NULL;
		this->prev = NULL;
		this->val = val;
		this->count = 1;
	}
};

class Stack
{
	Node* head,
		* tail;
public:
	int count;

	Stack()
	{
		count = 0;

		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->prev = head;
	}

	void Add(string val)
	{
		Node* cur = tail;

		while (cur->prev != head && cur->prev->val < val)
		{
			cur = cur->prev;
		}

		if (cur->prev == head)
		{
			cur->prev = new Node(val);
			cur->prev->next = cur;
			head->next = cur->prev;
			cur->prev->prev = head;

			count++;
		}
		else if (cur->prev->val == val)
			cur->prev->count++;
		else
		{
			Node* temp = new Node(val);
			cur->prev->next = temp;
			temp->prev = cur->prev;
			temp->next = cur;
			cur->prev = temp;

			count++;
		}
	}

	void Sort()
	{
		Node* cur = head->next;
		for (int i = 0; i < count; i++)
		{
			cur = head->next;
			for (int j = 0; j < count - i - 1; j++, cur = cur->next)
			{
				if (cur->count > cur->next->count)
				{
					string temp = cur->val;
					cur->val = cur->next->val;
					cur->next->val = temp;

					int tmp = cur->count;
					cur->count = cur->next->count;
					cur->next->count = tmp;
				}
			}
		}
	}

	void Print()
	{
		Node* temp = tail->prev;
		while (temp != head)
		{
			word.push_back(temp->val);
			num.push_back(temp->count);
			temp = temp->prev;
		}
	}
};


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	string n;
	Stack s;
	while (fin >> n)
	{
		if (n == "")
		{
			break;
		}

		s.Add(n);
	}

	s.Sort();
	s.Print();

	for (int i = 0; i < num.size(); i++)
	{
		fout << word[i] << ' ' << num[i] << endl;
	}

	return 0;
}