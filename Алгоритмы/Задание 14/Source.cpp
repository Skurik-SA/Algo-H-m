#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> res;

struct Node
{
	int val;
	Node* next;

	Node(int val)
	{
		this->val = val;
		this->next = NULL;
	}

};

class Stack
{
	Node* head, * tail;
public:
	long long len;

	Stack() : head(NULL), tail(NULL), len(0)
	{

	}

	void push(int val)
	{
		Node* temp = new Node(val);
		len++;
		if (head != NULL)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			head = tail = temp;
		}
	}

	void pop()
	{
		if (len != 0)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			len--;
		}
	}

	void back()
	{
		if (len != 0)
		{
			cout << head->val << endl;
		}
	}

	void size()
	{
		cout << len << endl;
	}

	void clear()
	{
		if (len != 0)
		{
			while (len != 0)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
				len--;
			}
		}
	}


	void print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			res.push_back(temp->val);
			/*cout << temp->val << " ";*/
			temp = temp->next;
		}
	}

	long long LEN()
	{
		return len;
	}


};



int main()
{
	Stack s;
	string str = "";
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	while (fin >> str)
	{
		if (str[0] == '-')
		{
			if (s.len < 1)
			{
				s.len--;
				fout << "ERROR";
				break;
			}
			else
			{
				s.pop();
			}
		}
		else
		{
			string temp = str.substr(1);
			s.push(atoi(temp.c_str()));
		}
	}

	if (s.LEN() == 0)
	{
		fout << "EMPTY";
	}
	else if (s.len > 0)
	{
		s.print();
		for (int i = res.size() - 1; i > 0; i--)
		{
			fout << res[i] << ' ';
		}

		fout << res[0];
	}

	
	return 0;
}