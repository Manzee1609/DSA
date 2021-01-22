#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
};

class linkedList{
	node* head;
	
	public:
	linkedList(){
		head = NULL;
	}

	linkedList(int data){
		node* newNode = new node;
		newNode->data = data;
		head = newNode;
	}
	
	void insertAtHead(int data){
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	void insertAfter(int data, int newData){
		node* currentNode = head;
		while (currentNode->next != NULL){
			if (currentNode->data == data){
				node* newNode = new node;
				newNode->data = newData;
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				break;
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
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				break;
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

	void sort(){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode != NULL){
			node* newNode = currentNode->next;
			while (newNode != NULL){ 
				if (currentNode->data > newNode->data){
					int temp = currentNode->data;
					currentNode->data = newNode->data;
					newNode->data = temp;
				}
				newNode = newNode->next;
			}
			currentNode = currentNode->next;
		}
	}

	void reverse(){
		node* prevNode = NULL;
		node* currentNode = head;
		node* nextNode = NULL;

		while (currentNode != NULL){
			nextNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = nextNode;
		}
		head = prevNode;
	}
	
	void merge(linkedList l1, linkedList l2){
		l1.sort();
		l2.sort();
		node* temp1 = l1.head;
		node* temp2 = l2.head;
		node* currentNode = new node;
		
		if (temp1->data < temp2->data){
			node* newNode = new node;
			newNode->data = temp1->data;
			temp1 = temp1->next;
			this->head = newNode;
			currentNode = this->head;
		}
		else if (temp2->data < temp1->data){
			node* newNode = new node;
			newNode->data = temp2->data;
			temp2 = temp2->next;
			this->head = newNode;
			currentNode = this->head;
		}
		else {
			node* newNode = new node;
			newNode->data = temp1->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
			this->head = newNode;
			currentNode = this->head;
		}

		while (temp1 != NULL && temp2 != NULL){
			if (temp1->data < temp2->data){
				node* newNode = new node;
				newNode->data = temp1->data;
				currentNode->next = newNode;
				currentNode = currentNode->next;
				temp1 = temp1->next;
			}

			else if (temp2->data < temp1->data){
				node* newNode = new node;
				newNode->data = temp2->data;
				currentNode->next = newNode;
				currentNode = currentNode->next;
				temp2 = temp2->next;
			}

			else{
				node* newNode = new node;
				newNode->data = temp2->data;
				currentNode->next = newNode;
				currentNode = currentNode->next;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			
		}

		while (temp1 != NULL){
			node* newNode = new node;
			newNode->data = temp1->data;
			currentNode->next = newNode;
			currentNode = currentNode->next;
			temp1 = temp1->next;
		}

		while (temp2 != NULL){
			node* newNode = new node;
			newNode->data = temp2->data;
			currentNode->next = newNode;
			currentNode = currentNode->next;
			temp2 = temp2->next;
		}

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
		prevNode->next = currentNode->next;
		delete currentNode;

	}

	void delAfter(int data){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->data != data){
			currentNode = currentNode->next;
		}
		node* temp = new node;
		temp = currentNode->next;
		currentNode = temp->next;
		delete temp;
	}

};

int main(){
	linkedList ll(5);
	ll.insertAtEnd(10);
	ll.insertAtEnd(30);
	ll.insertAtEnd(70);
	ll.insertAtEnd(40);
	cout << "Linked List is: ";
	ll.display();
	ll.insertAfter(20, 25);
	cout << "After using insert after: "; 
	ll.display();
	ll.insertBefore(40, 35);
	cout << "After using insert before: ";
	ll.display();
	ll.sort();
	cout << "After sorting: ";
	ll.display();
	ll.reverse();
	cout << "After reversing: ";
	ll.display();
	linkedList l2(2);
	l2.insertAtEnd(36);
	l2.insertAtEnd(59);
	l2.insertAtEnd(12);
	cout << "First linked list: ";
	ll.display();
	cout << "Second linked list: ";
	l2.display();
	linkedList l3;
	l3.merge(ll, l2);
	cout << "Merged Lists: ";
	l3.display();
	return 0;
}
