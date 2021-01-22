#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string eqn){
	stack<char> brackets;
	for (int i = 0; i < eqn.size(); i++){
		if (eqn.at(i) == "{")
			brackets.push(eqn.at(i));
		else{
			if (eqn.at(i) == "}" && brackets.top != "{")
				return false;
			else
				brackets.pop();
		}
	}
	return true;
}

int main(){

	return 0;
}
