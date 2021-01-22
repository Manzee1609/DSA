#include<iostream>
#include<stack>

using namespace std;

bool isOperator(string op){
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

string reverse(string s){
	string reverse = "";
	stack<string> elems;
	for (int i = 0; i < s.size(); i++){
		elems.push(s.at(i));
	}
	while (!elems.isEmpty()){
		if (elems.top() == ")")
			reverse += "(";
		else if (elems.top() == "(")
			reverse += ")";
		else
			reverse += elems.top();
		elems.pop();
	}
	return reverse;

}


string infixToPrefix (string infix){
	
	string reverseInfix = reverse(infix);
	string postfix = infixToPostfix(reverseInfix);
	string prefix = reverse(postfix);
	
	return prefix;

}
