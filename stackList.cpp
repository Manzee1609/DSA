#include<iostream>

using namespace std;

class node{
public:
	int data;
	node* next;
};

class stack(){
	node* head;
	int top;
	public:
	
	stack(){
		top = 0;
		head = NULL;
	}

	bool isEmpty(){
		return (top == 0);
	}
	
	void push(int data){
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		top++;
	}
	
	void pop(){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		delete currentNode;
		top--;
	}

	int getTop(){
		node* currentNode = new node;
		currentNode = head;
		while (currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		return currentNode->data;
	}

};
