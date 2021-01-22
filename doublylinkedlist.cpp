#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* prev;
	node* next;
};

class doublylinkedList{
	node* head;
	
	public:
	doublylinkedList(){
		head = NULL;
	}

	doublylinkedList(int data){
		node* newNode = new node;
		newNode->data = data;
		head = newNode;
	}
	void insertAfter(int data, int newData){
		node* currentNode = head;
		while (currentNode->next != NULL){
			if (currentNode->data == data){
				node* newNode = new node;
				newNode->data = newData;
				newNode->prev = currentNode;
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				currentNode->next->prev = newNode;
				return;
			}
			currentNode = currentNode->next;
		}
	}

	void insertBefore(int data, int newData){
		node* currentNode = head;
		while (currentNode->next != NULL){
			if (currentNode->next->data == data){
				node* newNode = new node;
				newNode->data = newData;
				newNode->prev = currentNode;
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				currentNode->next->prev = newNode;
				return;
			}
			currentNode = currentNode->next;
		}
	}

	void insertAtEnd(int data){
		node* currentNode = head;
		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		node* newNode = new node;
		newNode->data = data;
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}

	void display(){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->next != NULL){
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << currentNode->data << " ";
		cout << endl;
	}
	
	void delHead(){
		node* temp = head;
		head = head->next;
		delete temp;
	}

	void delTail(){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		delete currentNode;
	}

	void del(int data){
		node* currentNode = new node;
		currentNode = head;
		node* prevNode = newNode;
		prevNode = NULL;
		while(currentNode->data != data){
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		currentNode->next->prev = prevNode;
		prevNode->next = currentNode->next;
		delete currentNode;

	}

	void delBefore (int data){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->data != data){
			currentNode = currentNode->next;
		}
		node* temp = new bode;
		temp = currentNode->prev;
		temp->prev->next = currentNode;
		currentNode->prev = temp->prev;
		delete temp;
	}

	void delAfter (int data){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->data != data){
			currentNode = currentNode->next;
		}
		node* temp = new node;
		temp = currentNode->next;
		currentNode->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}

};

int main(){
	doublylinkedList ll(5);
	ll.insertAtEnd(10);
	ll.insertAtEnd(30);
	ll.insertAtEnd(70);
	ll.insertAtEnd(40);
	cout << "Linked List is: ";
	ll.display();
	ll.insertAfter(30, 25);
	cout << "After using insert after: "; 
	ll.display();
	ll.insertBefore(30, 35);
	cout << "After using insert before: ";
	ll.display();
	return 0;
}
