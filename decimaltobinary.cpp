#include<iostream>
#include<stack>

using namespace std;

int convert(int no){
	stack<int> binary;
	
	while (no != 0){
		binary.push(no % 2);
		no = no / 2;
	}

	string binaryNo = 0;
	
	while(!binary.empty()){
		binaryNo += to_string(binary.top());
		binary.pop();	
	}
	return stoi(binaryNo);

}

int main(){

}
