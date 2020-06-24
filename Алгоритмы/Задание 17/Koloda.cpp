
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct Node {
	Node* next;
	Node* prev;
	string val;
	Node(string val) {
		this->val = val;
		this->next = NULL;
		this->prev = NULL;
	}
};

struct dequeue {
	int len;
	Node* head;
	Node* tail;
	dequeue() {
		this->len = 0;
		this->head = new Node("");
		this->tail = new Node("");
		this->head->next = tail;
		this->tail->prev = head;
	}

	void push_front(string val) {
			Node* tmp_head = new Node(val);
			tmp_head->prev = this->head;
			tmp_head->next = this->head->next;
			this->head->next->prev = tmp_head;
			this->head->next = tmp_head;
			this->len++;
	}

	void push_back(string val) {
		Node* tmp_tail = new Node(val);
		tmp_tail->next = this->tail;
		tmp_tail->prev = this->tail->prev;
		this->tail->prev->next = tmp_tail;
		this->tail->prev = tmp_tail;
		this->len++;
	}
	bool pop_front() {
		if (len != 0) {
			Node* tmp = this->head->next;

			this->head->next = tmp->next;
			tmp->next->prev = this->head;

			free(tmp);
			this->len--;
			return true;
		}
		else return false;
	}
	bool pop_back() {

		if (len != 0) {
			Node* tmp = this->tail->prev;

			this->tail->prev = tmp->prev;
			tmp->prev->next = this->tail;

			free(tmp);
			this->len--;
			return true;
		}
		else return false;
	}
	bool find_val(string val) {
		if (len != 0) {
			Node* tmp;
			tmp = head->next;
			while (tmp->next != NULL) {
				if (tmp->val == val)
					return false;
				tmp = tmp->next;
			}
		}
		return true;
	}


	void print() {
		ofstream out("output.txt");
		if (len != 0) {
			Node* tmp;
			tmp = head->next;

			while (tmp->next != NULL) {
				out << tmp->val << " ";
				tmp = tmp->next;
			}
		}
		else out << "EMPTY";
		out.close();
	}


};
int main()
{
	ofstream out("output.txt");
	ifstream in("input.txt");
	dequeue d;
	string com;
	bool F = true;
	getline(in, com);
	while (com != "") {
		if (com[0] == '+') {
			com.erase(0, 1);
			if(d.find_val(com))
				d.push_front(com);
			else {
				out << "ERROR" << endl;
				F = false;
				break;
			}
		}
		else if(com[0]=='#') {
			com.erase(0, 1);
			if (d.find_val(com))
				d.push_back(com);
			else {
				out << "ERROR" << endl;
				F = false;
				break;
			}
		}
		else if (com[0] == '^') {
			F = d.pop_front();
			if (!F) {
				out << "ERROR" << endl;
				break;
			}
		}
		else if(com[0] == '/'){
			F = d.pop_back();
			if (!F) {
				out << "ERROR" << endl;
				break;
			}
		}

		getline(in, com);
	}
	if (F)d.print();
	out.close();
	in.close();
}