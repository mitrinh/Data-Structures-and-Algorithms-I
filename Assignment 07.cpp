//Michael Trinh CS110C
#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
	char stackarr[50];
	int top;
public:
	stack();
	bool isEmpty();
	bool push(char newEntry);
	bool pop();
	char peek();
};

class queue
{
private:
	char queuearr[50];
	int front;
	int back;
public:
	queue();
	bool isEmpty();
	bool enqueue(char newEntry);
	bool dequeue();
	char peekfront();
	
};

class StackAndQueue : public stack, public queue //derived class of both stack and queue class
{
public:
	void movetoStackAndQueue(string &word);
	bool isPalindrome(string &word);
};

stack::stack() //constructor
{
	top = -1;
}

queue::queue() //constructor
{
	front = 0;
	back = front;
}

bool stack::isEmpty()//stack isEmpty
{
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool queue::isEmpty() //queue isEmpty
{
	if (front == back) {
		return true;
	}
	else {
		return false;
	}
}

bool stack::push(char newEntry) //push
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

bool queue::enqueue(char newEntry) //enqueue
{
	if (back < 50) {
		queuearr[back] = newEntry;
		back++;
		return true;
	}
	else {
		cout << "queue is full" << endl;
		return false;
	}
}

bool stack::pop() //pop
{
	if (isEmpty()) {
		cout << "stack is empty" << endl;
		return false;
	}
	else {
		top--;
		return true;
	}
}

bool queue::dequeue() //dequeue
{
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		return false;
	}
	else {
		front++;
		if (front == back) // resets the queue so it is empty again, so more words can be checked if it is palindrome
		{
			front = 0;
			back = front;
		}
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

char queue::peekfront() //peekfront
{
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		return '\0';
	}
	else {
		return queuearr[front];
	}
}

int getlength(string &entry) //gets the length of a word
{
	int count = 0;
	while (entry[count] != '\0')
	{
		count++;
	}
	return count;
}

void StackAndQueue::movetoStackAndQueue(string &word) //moves palindrome to stack and queue
{
	for (int i = 0; i < getlength(word); i++)
	{
		push(word[i]);
		enqueue(word[i]);
	}
}


bool StackAndQueue::isPalindrome(string &word) //compares stack and queue to check if word is a palindrome
{
	bool temp = true;
	for (int i = 0; i < getlength(word); i++) // checks if the beginning of the word is equal to the end of the word
	{
		if (peek() != peekfront()) // if they're not equal, it is not a palindrome
		{
			temp = false; // this is done instead of return false so the stack and queue pops and dequeues the whole word before returning
		}
		pop();
		dequeue();
	}
	if (temp == false) // return false after loop is ran
	{
		cout << word << " is not a palindrome." << endl;
		return false;
	}
	cout << word << " is a palindrome." << endl;
	return true; // else it is a palindrome (true)
}

int main()
{
	StackAndQueue StackAndQueue;
	string word;
	while (true)
	{
		cout << "Enter word (<50 characters) to check if it's a palindrome (type q to quit): ";
		getline(cin, word);
		if (word == "q")
		{
			//system("pause");
			return 0;
		}
		StackAndQueue.movetoStackAndQueue(word);
		StackAndQueue.isPalindrome(word);
	}
	//system("pause");
	return 0;
}

