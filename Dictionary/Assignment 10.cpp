// Michael Trinh CS 110C
#include <iostream>
#include <string>
using namespace std;

class dictionary // sorted array will be sorted alphabetically by name 
{
private:
	string birthdays[50]; // array format: [name1,birthday1,name2,birthday2,name3,birthday3,...]
						  //    index:       0      1        2       3       4       5      6...
	int KeyPosition; // found by getKeyPosition
public:
	int length(); // helper function
	bool getKeyPosition(string searchKey, int firstPos, int lastPos); // helper function
	bool add(string searchKey, string birthday); 
	bool reverse();
	bool remove(string searchKey); 
	string retrieveBirthday(string searchKey);
	bool displayAll();
	bool retrieveNamesinMonth(string month);
};

int dictionary::length() // length of dictionary
{
	int count = 0;
	while (birthdays[count] != "\0")
	{
		count++;
	}
	return count;
}

bool dictionary::getKeyPosition(string searchKey, int firstPos, int lastPos) // searches for the key via binary search, O(log n), and 
																		    // returns its position
																			// firstPos initialized to 0, lastPos initialized to length()
{
	int midPos = ((firstPos + lastPos) / 2);
	if (midPos % 2 != 0) // if midPos is an odd number, subtract 1 to prevent comparison of searchKey and birthday
	{
		midPos--;
	}
	if (searchKey == birthdays[midPos]) // if the key is located at the middle, return its position
	{
		KeyPosition = midPos;
		return true;
	}
	else if (searchKey < birthdays[midPos]) // if key is less than middle node, repeat with more restricted parameters
	{
		getKeyPosition(searchKey, firstPos, midPos);
	}
	else if (searchKey > birthdays[midPos]) // if k is greater than middle node, repeat with more restricted parameters
	{
		getKeyPosition(searchKey, midPos, lastPos);
	}
	else
	{
		cout << searchKey << " isn't located in dictionary." << endl;
		return false;
	}
}

bool dictionary::add(string searchKey, string birthday) // add an entry in mm/dd format
{
	for (int i = 0; i < 20; i = i + 2) // O(n) sortedInsertion
	{
		if (searchKey > birthdays[i]) // if >, readd the old nodes , this puts the array in descending alphabetical order 
		{
			string temp = birthdays[i];
			string temp2 = birthdays[i + 1];
			birthdays[i] = searchKey;
			birthdays[i + 1] = birthday;
			add(temp, temp2);
			return true;
		}
	}
	return false;
}

bool dictionary::reverse()
{
	for (int i = 0; i < length()/2; i=i+2) // reverse the array so it's in ascending order
	{
		string temp = birthdays[i]; // name
		string temp2 = birthdays[i + 1]; // birthday
		birthdays[i] = birthdays[length()-2-i]; // name
		birthdays[i + 1] = birthdays[length() - 1 - i]; // birthday
		birthdays[length() - 2 - i] = temp; // name
		birthdays[length() - 1 - i] = temp2; // birthday
	}
	return true;
}

bool dictionary::remove(string searchKey) // remove an entry
{
	getKeyPosition(searchKey, 0, length());
	while (KeyPosition != length()-2) // move everything above key by 2 nodes
	{
		birthdays[KeyPosition] = birthdays[KeyPosition+2];
		KeyPosition++;
	}
	birthdays[length() - 2] = "\0"; // hard fix
	return true;
}

string dictionary::retrieveBirthday(string searchKey) // search the dictionary for the birthday for a given name
													  // and return it
{
	getKeyPosition(searchKey, 0, length());
	return birthdays[KeyPosition+1];
}

bool dictionary::displayAll() // display the name and birthday of every entry in the dictionary
{
	int count = 0;
	cout << endl << "dictionary:" << endl;
	while (count != length()) // O(n)
	{
		cout << "name: " << birthdays[count] << " | birthday: " << birthdays[count + 1] << endl; 
		count = count + 2;
	}
	cout << endl;
	return true;
}

bool dictionary::retrieveNamesinMonth(string month) // list everyone in the dictionary who was born in a given month, mm format
{
	int count = 0;
	cout << "These people's birthdays are in month " << month << " : ";
	while (count != length()) // O(n)
	{
		if (birthdays[count].substr(0,2) == month) // first two characters of birthday is month
		{
			cout << birthdays[count-1] << " ";
		}
		count++;
	}
	cout << endl;
	return true;
}

int main()
{
	dictionary birthdays;
	birthdays.add("Tom", "11,15");
	birthdays.add("Sally", "08,13");
	birthdays.add("Dean", "12/05");
	birthdays.add("John","08/12");
	birthdays.add("Dan", "04/23");
	birthdays.add("Harry", "01,15");
	birthdays.reverse();
	birthdays.remove("Dean");
	birthdays.displayAll();
    birthdays.retrieveNamesinMonth("08");
	cout << "Sally's birthday: " << birthdays.retrieveBirthday("Sally") << endl;
	birthdays.remove("Sally");
	birthdays.displayAll();
	birthdays.retrieveNamesinMonth("08");
	birthdays.retrieveNamesinMonth("11");
	cout << "Dan's birthday: " << birthdays.retrieveBirthday("Dan") << endl;
	//system("pause");
    return 0;
}

