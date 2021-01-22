#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
};

class queue(){
	node* head;
	int top;
	public:
	
	queue(){
		top = 0;
		head = NULL;
	}

	bool isEmpty(){
		return (top == 0);
	}
	
	void enqueue(int data){
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		top++;
	}
	
	void dequeue(){
		node* temp;
		temp = head->next;
		delete head;
		head = temp;
	}

};
