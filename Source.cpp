#include<iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class LinkedList {
	Node* head, * tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void insert(int x) {
		Node* ptr = new Node;
		ptr->data = x; ptr->next = NULL;
		if (head == NULL) { 
			head = ptr; tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
	}
	void deletion(int y) {
		Node* temp, * prev;
		temp = head; prev = head;
		while (temp->data != y) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == head) {
			head = temp->next;
			free(temp);
		}
		else if (temp == tail) {
			prev->next = NULL;
			tail = prev;
			free(temp);
		}
		else {
			prev->next = temp->next;
			free(temp);
		}
	}
	bool isFound(int x) {
		bool found = true;;
		Node* temp, * prev;
		temp = head; prev = head;
		while (temp != NULL) {
			if (temp->data == x) {
				return true;
			}
			else {
				prev = temp;
				temp = temp->next;
			}
		}
		return false;
	}
	void display() {
		Node* temp;
		temp = head;
		while (temp != NULL) {
			cout << "Display is:" << temp->data << endl;
			temp = temp->next;
		}
	}
};
int main() {
	LinkedList l1; LinkedList l2; int val;
	l1.insert(5);
	l1.insert(3);
	l1.insert(6);
	l1.display();
	cout << endl;
	cout << "Enter value: "; cin >> val;
	if (l1.isFound(val)) {
		cout << "Number found " << endl;
	}
	else {
		cout << "Number not found " << endl;
	}
	system("pause");
	return 0;

}