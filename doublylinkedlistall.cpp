#include<iostream>
using namespace std;
class node {
public:
	int value;
	node* next;
	node* prev;
	node(int a) {
		value = a;
		next = nullptr;
		prev = NULL;
	}
};
class doublylinkedlist {
private:
	int length;
	node* head;
	node* tail;
public:
	doublylinkedlist(int a) {
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
			tail->next=newn;
			newn->prev = tail;
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
			head->prev = newn;
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
			head->prev = NULL;
		}
		delete temp;
		length--;
	}
	void deletelast() {
		if (length == 0) {
			return;
		}
		node* temp = tail;
		if (length == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			tail = tail->prev;
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
			if (index < length / 2) {
				for (int i = 0;i < index;i++) {
					temp = temp->next;
				}
			}
			else {
				temp = tail;
				for (int j = length - 1;j > index;j--) {
					temp = temp->prev;
				}
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
			node* newn = new node(value);
			node* pre = get(index - 1);
			node* temp = pre->next;
			newn->next = temp;
			temp->prev = newn;
			pre->next = newn;
			newn->prev = pre;
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
			node* temp = get(index);
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			length--;
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
	void gethead() {
		cout << endl;
		cout << "HEAD: " << head->value;
	}
	void gettail() {
		cout << endl;
		cout << "TAIL: " << tail->value;
	}
	void leng() {
		cout << endl;
		cout << "LENGTH: " << length;
	}
};
int main() {
	doublylinkedlist* mydll = new doublylinkedlist(7);
	mydll->append(8);
	mydll->append(4);
	mydll->append(3);
	mydll->print();
	mydll->prepend(2);
	mydll->prepend(6);
	mydll->print();
	mydll->deletelast();
	mydll->print();
	mydll->deletefirst();
	mydll->print();
	mydll->insert(2, 10);
	mydll->print();
	mydll->set(1, 8);
	mydll->print();
	mydll->deletenode(2);
	mydll->print();
	cout << endl << mydll->get(1)->value;
	mydll->insert(2, 6);
	mydll->print();
	mydll->gethead();
	mydll->gettail();
	mydll->leng();
	system("pause>0");
	

}