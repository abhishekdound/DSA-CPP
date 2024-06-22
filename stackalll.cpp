#include<iostream>
using namespace std;
class node {
public:
	node* next;
	int value;
	node(int a) {
		value = a;
		next = NULL;
	}
};
class stack {
private:
	int height;
	node* top;
public:
	stack(int a) {
		node* newn = new node(a);
		top = newn;
		height = 1;
	}
	void push(int value) {
		node* newn = new node(value);
		newn->next = top;
		top = newn;
		height++;
	}
	int pop() {
		if (height == 0) {
			return INT_MAX;
		}
		else {
			node* temp = top;
			int popvalue = temp->value;
			top = top->next;
			delete temp;
			height--;
			return popvalue;
		}
	}
	void print() {
		node* temp = top;
		cout << endl;
		while (temp) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
	node* gettop() {
		return top;
	}
	int getheight() {
		return height;
	}
};
int main() {
	stack* mystack = new stack(5);
	mystack->push(7);
	mystack->push(3);
	mystack->print();
	mystack->pop();
	mystack->print();
	cout<<endl<<"Top:"<<mystack->gettop()->value;
	cout << endl <<"Height: "<< mystack->getheight();
	system("pause>0");
}