#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int index;
    Node* next;
    Node* prev;
    int val;

    Node(int val, int ind) {
        this->index = ind;
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
        this->head = new Node(0, -1);
        this->tail = new Node(0, -1);
        this->head->next = tail;
        this->tail->prev = head;
    }

    Node* ret_ind(int ind) {
        Node* tmp_head = head->next;
        for (int i = 0; i < ind; i++)
            tmp_head = tmp_head->next;
        return tmp_head;

    }

    void push_back(int val) {

        Node* tmp_tail = new Node(val, len);
        tmp_tail->next = this->tail;
        tmp_tail->prev = this->tail->prev;
        this->tail->prev->next = tmp_tail;
        this->tail->prev = tmp_tail;
        this->len++;

    }

    void print() {
        if (len != 0) {
            Node* tmp;
            tmp = head->next;

            while (tmp->next != NULL) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
        }
    }

    bool prov(int v) {
        Node* a = tail->prev->prev;
        Node* b = tail->prev;
        if (((a->val > b->val) && (b->val < v)) || ((a->val < b->val) && (b->val > v)))
            return true;
        return false;
    }
};

int main()
{
    dequeue mas;
    int kol;
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        int tmp;
        cin >> tmp;
        if (i > 1) {
            if (mas.prov(tmp))
                mas.push_back(tmp);
        }
        else mas.push_back(tmp);

        
    }
    mas.print();
}