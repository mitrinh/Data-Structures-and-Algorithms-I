// Array-based List Class for Playlists
// Max Luttrell CS 110C
// Michael Trinh

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
class List
{
private:
	static const int CHUNK_SIZE = 100;
	ItemType *list;
	int numItems;
	int maxItems;
public:
	// default constructor and destructor
	List() {
		numItems = 0; maxItems = CHUNK_SIZE;
		list = new ItemType[CHUNK_SIZE];
	}
	~List() { delete[] list; }

	// list member functions
	bool isEmpty() { return numItems == 0; }
	int getLength() { return numItems; }
	bool insert(int pos, const ItemType& item);
	bool remove(int pos);

	// clear can simply set numItems to zero.  The array list may still contain
	// items already inserted into the list, but since numItems is zero, there 
	// isn't any way to get at them using getEntry() or setEntry()
	void clear() { numItems = 0; }

	// throw invalid_argument if pos<1 or pos>getLength()
	ItemType getEntry(int pos) const throw(invalid_argument);

	// throw invalid_argument if pos<1 or pos>getLength()
	void setEntry(int pos, const ItemType& item) throw(invalid_argument);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
	bool canAdd;
	canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));
	if (canAdd)
	{
		// first, we have to move everything after our insertion point over one
		// position to make room for our new item.  start at the back of the list.
		// don't forget arrays start at postion zero and our list ADT starts at
		// position 1.
		for (int i = numItems; i >= pos; i--)
			list[i] = list[i - 1];
		// now put our item at position pos-1
		list[pos - 1] = item;
		numItems++;
	}
	//Currently, if you try to add an item to a full list, insert() returns false and does not add the item.
	//Improve this so that it dynamically allocates more memory to the list to make room for the new item using the new operator. 
	//You can add another CHUNK_SIZE amount of memory, or any other amount of memory you think makes sense.
	//Don't forget to deallocate any existing memory, e.g. using delete [].
	if (numItems == maxItems)
	{
		int * maxItems;
		maxItems = new int[100];
		delete[] maxItems;
	}
	return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const throw(invalid_argument)
{
	if (pos<1 || pos>numItems) {
		throw invalid_argument("ERROR: getEntry() using invalid position");
	}
	return list[pos - 1];
}

// TODO: add implementations for setEntry() and remove() functions

// replace item at position pos in the list with the new parameter item.  
// Throw the invalid_argument exception if pos<1 or pos>getLength().
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType & item) throw(invalid_argument)
{
	list[pos-1] = item;
	if (pos<1 || pos>numItems) {
		throw invalid_argument("ERROR: getEntry() using invalid position");
	}
}

// Remove the item at position pos.
// You need to update the state of the list, that is, shift items after pos over one to get rid of the gap left by the removed item and update numItems. 
// If the remove operation is successful, return true.
// If it was not successful, for example because pos is out of range, return false.
template<class ItemType>
bool List<ItemType>::remove(int pos)
{
	//shift items over 1
	for (int i=pos; i < numItems; i++)
	{
		list[i-1] = list[i];
	}
	numItems--;
	if (pos < 1 || pos > numItems)
	{
		return false;
	}
	else
	{
		return true;
	}
}	

// Utility function to input a track number with some input checking 
// to make sure it's a number
int getTrack()
{
	bool inputCheck;
	int trackNumber;
	do
	{
		inputCheck = true;
		cout << "Please enter the track number you'd like to view: ";
		if (!(cin >> trackNumber))
		{
			cout << "Please enter numbers only.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			inputCheck = false;
		}
	} while (!inputCheck);
	return trackNumber;
}

int main()
{
	List<string> songs;
	char goAgain = 'y';
	int trackNumber;
	string trackName;
	// Insert some songs into our list
	songs.insert(1, "One More Saturday Night");
	songs.insert(1, "Friday I'm in Love");
	songs.insert(3, "Sunday Morning Coming Down");
	songs.insert(1, "California Love");
	songs.setEntry(1, "test song");
	cout << "test song has replaced California Love at position 1\n";
	songs.remove(3);
	cout << "song: One More Saturday Night has been removed\n";
	cout << "\nWelcome!  There are " << songs.getLength() << " tracks.\n";
	while (goAgain != 'n')
	{
		trackNumber = getTrack();
		try
		{
			trackName = songs.getEntry(trackNumber);
		}
		catch (invalid_argument arg)
		{
			cout << arg.what() << endl;
			trackName = "No Track";
		}
		cout << "Your track name is " << trackName << endl;
		cout << "Go again? (y/n) ";
		cin >> goAgain;
	}
	cout << "Rock on!\n";
	//system("pause");
	return 0;
}

//sample output
/*
test song has replaced California Love at position 1
song: One More Saturday Night has been removed

Welcome!  There are 3 tracks.
Please enter the track number you'd like to view: 1
Your track name is test song
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is Friday I'm in Love
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is Sunday Morning Coming Down
Go again? (y/n) y
Please enter the track number you'd like to view: 4
ERROR: getEntry() using invalid position
Your track name is No Track
Go again? (y/n) n
Rock on!
*/

