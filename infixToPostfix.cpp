#include<iostream>
#include<stack>

using namespace std;

bool isOperator (string op){
	return (op == "+" || op == "-" || op == "*" || op == "/");
}

string infixToPostfix(string infix){
	stack<string> operators;
	string postfix;

	for (int i = 0; i < infix.size(); i++){
		if (isalnum(infix.at(i))){
			postfix += infix.at(i);
		}
		else if (isOperator(infix.at(i))){
			operators.push(infix.at(i));
		}
		else if (infix.at(i) == ")"){
			while (!operators.isEmpty()){
				postfix += operators.top();
				operators.pop();
			}
		}
	}
	while (!operators.isEmpty()){
		postfix += operators.top();
		operators.pop();
	}
	return postfix;
}
