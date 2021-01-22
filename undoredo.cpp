#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<string> undo;
stack<string> redo;

void undo(){
	redo.push(undo.top());
	undo.pop();
}

void redo(){
	undo.push(redo.top());
	redo.pop();	
}

void Do(string s){
	undo.push(s);
}

void display(){
	stack<string> temp;
	while (!undo.empty()){
		temp.push(undo.top());
		undo.pop();
	}
	while (!temp.empty()){
		cout << temp.top() << " ";
		undo.push(temp.top());
		temp.pop();
	}
	cout << endl;
}

int main(){

	return 0;
}
