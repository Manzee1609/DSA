#include<iostream>
#include<stack>

using namespace std;

int evaluatePostfix(string postfix){
	stack<string> operands;

	for (int i = 0; i < postfix.size(); i++){
		if (isdigit(postfix.at(i)))
			operands.push(postfix.at(i));
		else{
			int val1 = operands.top();
			operands.pop();
			inr val2 = operands.top();
			operands.pop();

			switch(postfix.at(i)){
				case "+": operands.push(val1 + val2);
					  break;
				case "-": operands.push(val1 - val2);
					  break;
				case "*": operands.push(val1 * val2);
					  break;
				case "/": operands.push(val1 / val2);
					  break;
			}
		}
	}
	return stoi(operands.top());
}
