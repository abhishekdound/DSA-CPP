#include<iostream>
using namespace std;
class node {
public:
	int value;
	node* next;
	node(int a) {
		value = a;
		next = NULL;
	}
};
class linkedlist {
private:
	node* head;
	node* tail;
	int length;
public:
	linkedlist(int a) {
		node* newn = new node(a);
		head = newn;
		tail = newn;
		length = 1;
	}
	void append(int a) {
		node* newn = new node(a);
		if (length == 0) {
			head = newn;
			tail = newn;
		}
		else {
			tail->next = newn;
			tail = newn;
		}
		length++;
	}
	void prepend(int a) {
		node* newn = new node(a);
		if (length == 0) {
			head = newn;
			tail = newn;
		}
		else {
			newn->next = head;
			head = newn;
		}
		length++;
	}
	void deletefirst() {
		if (length == 0) {
			return;
		}
		node* temp = head;
		if (length == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
		}
		delete temp;
		length--;
	}
	void deletelast() {
		if (length == 0) {
			return;
		}
		node* temp = head;
		if (length == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			node* pre = head;
			while (temp->next) {
				pre = temp;
				temp = temp->next;
			}
			tail = pre;
			tail->next = NULL;
		}
		delete temp;
		length--;
	}
	node* get(int index) {
		if (index < 0 || index >= length) {
			return NULL;
		}
		else {
			node* temp = head;
			for (int i = 0;i < index;i++) {
				temp = temp->next;
			}
			return temp;
		}
	}
	bool set(int index, int value) {
		node* temp = get(index);
		if (temp) {
			temp->value = value;
			return true;
		}
		else {
			return false;
		}
	}
	bool insert(int index, int value) {
		if (index<0 || index>length) {
			return false;
		}
		if (index == 0) {
			prepend(value);
			return true;
		}
		if (index == length) {
			append(value);
			return true;
		}
		else {
			node* temp = get(index - 1);
			node* newn = new node(value);
			newn->next = temp->next;
			temp->next = newn;
			length++;
			return true;
		}
	}
	void deletenode(int index) {
		if (index < 0 || index >= length) {
			return;
		}
		if (index == 0) {
			return deletefirst();
		}
		if (index == length - 1) {
			return deletelast();
		}
		else {
			node* temp = get(index - 1);
			node* pre = temp->next;
			temp->next = pre->next;
			delete pre;
			length--;
		}
	}
	void reverse() {
		node* temp = head;
		head = tail;
		tail = temp;
		node* after = temp->next;
		node* pre = NULL;
		for (int i = 0;i < length;i++) {
			after = temp->next;
			temp->next = pre;
			pre = temp;
			temp = after;
		}
	}
	void print() {
		cout << endl;
		node* temp = head;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
	node* gethead() {
		return head;
	}
	node* gettail() {
		return tail;
	}
	int getlength() {
		return length;
	}
};
int main() {
	linkedlist* mylinkedlist = new linkedlist(6);
	mylinkedlist->append(7);
	mylinkedlist->append(4);
	mylinkedlist->append(2);
	mylinkedlist->print();
	mylinkedlist->prepend(1);
	mylinkedlist->prepend(3);
	mylinkedlist->print();
	mylinkedlist->deletelast();
	mylinkedlist->print();
	mylinkedlist->deletefirst();
	mylinkedlist->print();
	mylinkedlist->deletenode(2);
	mylinkedlist->print();
	mylinkedlist->set(1, 7);
	mylinkedlist->print();
	mylinkedlist->insert(2, 5);
	mylinkedlist->print();
	cout << endl << "HEAD: " << mylinkedlist->gethead()->value;
	cout << endl << "TAIL: " << mylinkedlist->gettail()->value;
	cout << endl << "LENGTH: " << mylinkedlist->getlength();
	system("pause>0");
}