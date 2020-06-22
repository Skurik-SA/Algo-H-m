#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<int> res;

struct Node
{
	int val;
	Node* next;

	Node(int val)
	{
		this->next = NULL;
		this->val = val;
	}
};

struct queue
{
	Node* head, * tail, *middle;
	int count;
	queue()
	{
		count = 0;
		head = NULL;
		tail = NULL;
		middle = NULL;
	}

	void push(int val) // ��������� �������
	{
		Node* temp = new Node(val);

		if (count > 0)
		{
			tail->next = temp;
			tail = temp;

			if (count % 2 == 0)
			{
				middle = middle->next;
			}
		}
		else
		{
			head = temp;
			tail = temp;
			middle = temp;
		}

		count++;
	}

	void ElitePush(int val)
	{
		if (count > 1)
		{
			Node* temp = new Node(val);
			temp->next = middle->next;
			middle->next = temp;

			if (count % 2 == 0)
			{
				middle = temp;
			}

			count++;
		}
		else
		{
			push(val);
		}

	}

	int pop() // ������� ������ ������� � ������� �������� ������� �� �����
	{
		int temp = head->val;
		Node* toDel = head;
		head = head->next;

		if (count % 2 == 0 && count > 1)
		{
			middle = middle->next;
		}
		else if (count == 1)
		{
			middle = NULL;
		}

		count--;
		delete toDel;
		return temp;
	}
	
	void SHOW() // ���������� ��� ��������
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void clear() //������� ��� ��������
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		cout << "ok" << endl;
	}


	void front() // ����� ������ ������� �� �����
	{
		if (head != NULL)
		{
			cout << head->val << endl;
		}
		else
			cout << "error" << endl;
	}

	void size() // ����� �������
	{
		int k = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			k++;
		}
		cout << k << endl;
	}
};

int main()
{
	queue q;
	char command;
	int temp;
	int n;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> command;
		if (command == '+')
		{
			fin >> temp;
			q.push(temp);
		}
		else if (command == '-')
		{
			fout << q.pop() << endl;
		}
		else if (command == '*')
		{
			fin >> temp;
			q.ElitePush(temp);
		}
	}




	return 0;
}