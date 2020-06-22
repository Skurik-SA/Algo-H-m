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
	Node* head,
		* tail,
		*elite;

	int len;
	queue()
	{
		head = NULL;
		tail = NULL;
		elite = NULL;
		len = 0;
	}

	void push(int val) // Добавляет элемент
	{
		Node* temp = new Node(val);

		if (len > 0)
		{
			tail->next = temp;
			tail = temp;

			if (len % 2 == 0)
			{
				elite = elite->next;
			}
		}
		else
		{
			head = tail = elite = temp;
		}

		len++;
	}

	void ElitePush(int val)
	{
		if (len > 1)
		{
			Node* temp = new Node(val);
			temp->next = elite->next;
			elite->next = temp;

			if (len % 2 == 0)
			{
				elite = temp;
			}

			len++;
		}
		else
		{
			push(val);
		}

	}

	int pop() // Удаляет первый элемент и выводит удалённый элемент на экран
	{
		Node* temp = head;
		int val = head->val;
		head = head->next;

		if (len % 2 == 0 && len > 1)
		{
			elite = elite->next;
		}
		else if (len == 1)
		{
			elite = NULL;
		}

		len--;
		delete temp;
		return val;
	}
	
	void SHOW() // Показывает все элементы
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void clear() //Очищает все элементы
	{
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		cout << "ok" << endl;
	}


	void front() // Вывод первый элемент на экран
	{
		if (head != NULL)
		{
			cout << head->val << endl;
		}
		else
			cout << "error" << endl;
	}

	void size() // Вывод размера
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