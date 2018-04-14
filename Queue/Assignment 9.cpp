// Michael Trinh CS 110C
#include <iostream>
#include <string>
using namespace std;

class heap
{
private:
	string patients[9];
public:
	bool add(string newPatient);
	string peekTop();
	bool remove();
};

bool heap::add(string newPatient)
{
	if (isdigit(newPatient[0])){ // checks if newPatient has a priority; if it doesn't, return false
		for (int i = 0; i < 9; i++) { // compares newPatient with other patients in queue, and adds newPatient to queue in correct place
			if (newPatient > patients[i]) { // If newPatient has greater priority than a patient, 
				                            //    take its spot on the queue and readd that patient to the queue.
											// If new Patient has less priority, move to the next patient
				string temp = patients[i];
				patients[i] = newPatient;
				add(temp);
				break;
			}
		}
		return true;
	}
    else 
		return false;
}

string heap::peekTop()
{ 
	cout << "Queue: " << patients[0] << " " << patients[1] << " " << patients[2] << " " << patients[3] << " " 
		 << patients[4]<< " " << patients[5] << " " << patients[6] 
		 << " " << patients[7] << " " << patients[8] << endl; // print queue
	return patients[0]; // return patient with most priority 
}

bool heap::remove()
{
	int count=1;
	while (count < 9) { // moves the queue down by 1
		patients[count - 1] = patients[count];
		if (patients[count - 1] != patients[count]) // if copy procedure fails, return false
			return false;
		count++;
	}
	return true;
}

int main()
{
	heap ER;
	ER.add("5 Bob");
	ER.add("9 Mary");
	ER.add("1 Max");
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	ER.add("3 Julio");
	ER.add("7 Stacy");
	ER.add("4 Paul");
	ER.add("2 Reiko");
	ER.add("6 Jennifer");
	ER.add("5 Chang");
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	cout << ER.peekTop() << " will now see the doctor.\n";
	ER.remove();
	//system("pause");
    return 0;
}

