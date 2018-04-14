//Michael Trinh, CS 110C, Visual Studio Express 2015
#include <iostream>
#include <string>
using namespace std;

void rev(int n, int output)
{
	if (n == 0)//base case, if n is 0/when it's finished printing out the reverse number
	{
		return;//ends function
	}
	else
	{
			output=n % 10;//output=to last digit of n, remainder of a number gives last digit of that number
			cout << output;//prints last digit of n
			rev(n / 10, 0);//repeat the function with n divided by 10 to remove the last digit of the number, and output back to 0 to reset the output
			/*2015->print 5->[5],201->print 1->[51], 20->print 0->[510], 2->print 2->[5102], 0-> ends function*/
	}
}

void writeBackward(string s)
{
	cout << "Enter writeBackward with string: " << s << endl;
	int length = s.size();
	if (length == 0)//the string is empty
	{
		return;//Do nothing—this is the base case
	}
	else
	{
		cout << "About to write last character of string: "<< s << endl; 
		cout << s[length - 1] << endl;//Write the last character of s
		writeBackward(s.substr(0, length - 1)); // Point A
	}
	cout << "Leave writeBackward with string: " << s << endl;
}

void writeBackward2(string s)
{
	cout << "Enter writeBackward2 with string: " << s << endl;
	int length = s.size();
	if (length == 0)//the string is empty
	{
		return;//Do nothing—this is the base case
	}
	else
	{
		writeBackward2(s.substr(0 + 1, length)); //s minus its first character) Point A
		cout << "About to write first character of string: "<< s << endl;
		cout << s[0] << endl;//Write the first character of s
	}
	cout << "Leave writeBackward2 with string: " << s << endl;
}

int main()
{
	int n = 2015;//positive decimal integer
	rev(n, 0);
	cout << "\n"; //Problem 1

	string s = "cat";
	writeBackward(s);
	cout << "\n";
	writeBackward2(s);//Problem 2
	//system("pause");
	return 0;
}

/*	
1)	
	at 1, sample output =  
	
	1
	Press any key to continue . . . 
	
	at 2015, sample output = 
	
	5102
	Press any key to continue . . .
	
	at 1234567, sample output = 
	
	7654321
	Press any key to continue . . .

2) sample output:
Enter writeBackward with string: cat
About to write last character of string: cat
t
Enter writeBackward with string: ca
About to write last character of string: ca
a
Enter writeBackward with string: c
About to write last character of string: c
c
Enter writeBackward with string:
Leave writeBackward with string: c
Leave writeBackward with string: ca
Leave writeBackward with string: cat

Enter writeBackward2 with string: cat
Enter writeBackward2 with string: at
Enter writeBackward2 with string: t
Enter writeBackward2 with string:
About to write first character of string: t
t
Leave writeBackward2 with string: t
About to write first character of string: at
a
Leave writeBackward2 with string: at
About to write first character of string: cat
c
Leave writeBackward2 with string: cat
Press any key to continue . . .
*/