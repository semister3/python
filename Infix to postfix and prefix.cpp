#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string exp , exp1 , op = "";
int i , loop = 1;
int priorityCheck(char op){
	if(op == '('){
		return 0;
	}else if(op == '+' || op ==  '-'){
		return 1;	
	}else if(op == '*' || op == '/'){
		return 2;
	}else if(op == '^'){
		return 3;
	}
}
void PostFixAndInFix(int val){
	stack<char> stack;
	op = "";
    stack.push('(');
    if(val == 1){
    	exp1 = exp;
    	reverse(exp1.begin() , exp1.end());
	}
    for(i = 0 ; i < exp.length() ; i++){
    	if(exp[i] == '('){
    		stack.push(exp[i]);
		}else if(exp[i] == ')'){
        	while(stack.top() != '('){
        		op += stack.top();
        		stack.pop();
			}
			stack.pop();
		}else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
			while(priorityCheck(stack.top()) >= priorityCheck(exp[i]) && !stack.empty()){
        		op += stack.top();
        		stack.pop();
			}
			stack.push(exp[i]);
        }else{
			op += exp[i];
		}
	}
    while(stack.top() != '('){
		op += stack.top();
		stack.pop();
	}
	if(val == 1){
		reverse(op.begin(), op.end());
	}
}
void menu(){
	do{
		system("cls");
		cout<<"\nExpression : ";
		cin>>exp;
		cout<<"\n1 ] PostFix\n2 ] Prefix\n\nChoice >>> ";
		cin>>i;
		system("cls");
		cout<<"\nInFix Expression : "<<exp;
		if(i == 1){
			PostFixAndInFix(0);
			cout<<"\nPostFix Expression : "<<op<<endl;
		}else if(i == 2){
			PostFixAndInFix(1);
			cout<<"\nPreFix Expression : "<<op<<endl;
		}
		cout<<"\n[1 | Home]\t\t[2 | Exit]\n\nChoice >>> ";
	    cin>>loop;
	    if(loop == 1){
			menu();
		}else if(loop == 2){
			exit(0);
		}
	}while(loop != 2);
}
int main(){
	menu();
}
