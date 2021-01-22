#include<iostream>

using namespace std;

int MAX = 20;

class queue{
	int top;
	int arr[MAX];

	public:

	queue(){
		top = 0;
	}

	bool isEmpty(){
		return (top == 0);
	}

	bool isFull(){
		return (top == MAX);
	}

	void enqueue(int val){
		if (!isFull())
			arr[++top] = val;
	}

	void dequeue(){
		if (!isEmpty()){
			int topVal = arr[0];
			for (int i = 0; i < top - 1; i++){
				arr[i] = arr[i + 1];
			}
			return topVal;
		}
		return 0;
	}
};
