#include<iostream>

using namespace std;

int MAX = 20;

class stack{

	int top;
	int arr[MAX];
	public:

	stack(){
		top = 0;
	}
	
	bool isEmpty(){
		return (top == 0);
	}

	bool isFull(){
		return (top == MAX);
	}

	void push(int val){
		if (!isFull()){
			arr[top++] = val;
		}
	}

	void pop(){
		if (!isEmpty()){
			arr[top--] = 0;
		}
	}

	int getTop(){
		return arr[top];
	}

};
