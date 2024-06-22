#include<iostream>
using namespace std;
class node {
public:
	int value;
	node* next;
	node(int a) {
		next = NULL;
		value = a;
	}
};
class queue {
private:
	int length;
	node* first;
	node* last;
public:
	queue(int a) {
		node* newn = new node(a);
		first = newn;
		last = newn;
		length = 1;
	}
	void enqueue(int value) {
		node* newn = new node(value);
		if (length == 0) {
			first = newn;
			last = newn;
		}
		else {
			last->next = newn;
			last = newn;
		}
		length++;
	}
	int dequeue() {
		if (length == 0) {
			return INT_MAX;
		}
		node* temp = first;
		int dequeuevalue = temp->value;
		if (length == 1) {
			first = NULL;
			last = NULL;
		}
		else {
			first = first->next;
		}
		delete temp;
		length--;
		return dequeuevalue;
	}
	void print() {
		cout << endl;
		node* temp = first;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
	node* getfirst() {
		cout << endl<<"First:";
		return first;
	}
	node* getlast() {
		cout << endl<<"Last:";
		return last;
	}
	int getlength() {
		cout << endl<<"Length:";
		return length;
	}
};
int main() {
	queue* myqueue = new queue(6);
	myqueue->enqueue(4);
	myqueue->enqueue(2);
	myqueue->print();
	myqueue->enqueue(8);
	myqueue->dequeue();
	myqueue->print();
	cout <<  myqueue->getfirst()->value;
	cout << myqueue->getlast()->value;
	cout << myqueue->getlength();
	system("pause>0");


}