//Michael Trinh CS110C
#include <iostream>
#include <string>
using namespace std;

class stack
{
	private:
		char stackarr[50];//infix
		int top;
	public:
		stack();
		bool isEmpty();
		bool push(char newEntry);
		bool pop();
		char peek();
		int stack::getlength(string &entry);
		void Convert(string &infix);
};

stack::stack()//constructor
{
	top = -1;
}

bool stack::isEmpty()//isEmpty
{
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool stack::push(char newEntry)//push
{
	if (top < 50) {
		top++;
		stackarr[top] = newEntry;
		return true;
	}
	else {
		cout << "stack is full" << endl;
		return false;
	}
}

bool stack::pop()//pop
{
	if (isEmpty()) {
		cout << "stack is empty" << endl;
		return false;
	}
	else {
		stackarr[top] = ' ';
		top--;
		return true;
	}
}

char stack::peek() //peek
{
	if (isEmpty()) {
		cout << "stack is empty" << endl;
		return '\0';
	}
	else {
		return stackarr[top];
	}
}

int stack::getlength(string &entry) // length of expression
{
	int count = 0;
	while (entry[count] != '\0')
	{
		count++;
	}
	return count;
}

void stack::Convert(string &infix)//converts infix to postfix
{
	char postfixtemp[50]; // postfix
	int cur = 0; // current position in postfix
	for (int i = 0; i < getlength(infix); i++) {
		if (isdigit(infix[i])) { // encounters operand
			postfixtemp[cur] = infix[i];
			cur++;
		}
		else if (infix[i] == '(') { // encounters (
			push(infix[i]);
		}

		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') { // encounters operator
			if (isEmpty()) { // if empty, push onto stack
				push(infix[i]);
			}
			else {	
				for (int j = top; j > -1 /*isEmpty*/ ; j--) {// repeat until it encounters a '(', lower precedence, or isEmpty
					if (stackarr[j] == '(' /*(*/ || ((infix[i] == '+' || infix[i] == '-') && stackarr[j] == '*' || stackarr[j] == '/')) /*lower precedence*/ {
						break;
					}
					else if ((infix[i]=='*' || infix[i]=='/') && (stackarr[j] == '+' || stackarr[j] == '-')) { // greater or equal precedence
						postfixtemp[cur] = stackarr[j];
						cur++;
						pop();
					}
				}
				push(infix[i]); //push operator on stack
			}			
		} 
		else if (infix[i] == ')') { // encounters )
			for (int k = top; k > -1; k--) {
				if (stackarr[k] == '(') { // pop ( and end
					pop();
					break;
				}
				else if (stackarr[k] == '+' || stackarr[k] == '-' || stackarr[k] == '*' || stackarr[k] == '/'){ // pop and append operator
					postfixtemp[cur] = stackarr[k];
					cur++;
					pop();
					
				}
			}
		}
	}
	while (isEmpty() != true) { // pop off remaining stack operators
		postfixtemp[cur] = peek();
		cur++;
		pop();
	}
	cur = 0; // reset cur position
	int temp; // for calculations
	while (postfixtemp[cur] != '\0') {
		if (postfixtemp[cur] == '0' || postfixtemp[cur] == '1'|| postfixtemp[cur] == '2' || postfixtemp[cur] == '3' || postfixtemp[cur] == '4' || postfixtemp[cur] == '5' || postfixtemp[cur] == '6'|| postfixtemp[cur] == '7' || postfixtemp[cur] == '8' || postfixtemp[cur] == '9') { // if it's a digit push to stack
			push(postfixtemp[cur]);
		}
		if (postfixtemp[cur] == '+'){ //if it's a +
			temp = (peek()-'0') + (stackarr[top-1]-'0'); // add the two from stack;
			pop();
			pop();
			temp += '0';
			push(temp);
		}
		else if (postfixtemp[cur] == '-') { //if it's a -
			temp = (stackarr[top - 1] - '0') - (peek() - '0'); // subtract the two from stack;
			pop();
			pop();
			temp += '0';
			push(temp);
		}
		else if (postfixtemp[cur] == '*') { //if it's a *
			temp = (peek() - '0') * (stackarr[top - 1] - '0'); // multiply the two from stack;
			pop();
			pop();
			temp += '0';
			push(temp);
		}
		else if (postfixtemp[cur] == '/') { //if it's a /
			temp = (stackarr[top - 1] - '0') / (peek() - '0'); // divide the two from stack;
			pop();
			pop();
			temp += '0';
			push(temp);
		}
		cur++;
	}
	int result;
	result = (peek() - '0');
	cout << "result:" << result << endl;
}


int main() {
	stack stack;
	string infix;
	cout << "Enter infix expression: " << endl;
	getline(cin, infix);
	stack.Convert(infix);
	//system("pause");
    return 0;
}
