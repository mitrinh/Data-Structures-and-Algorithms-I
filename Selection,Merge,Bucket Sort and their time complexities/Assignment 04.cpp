// Michael Trinh

#include <iostream>
#include <string>
using namespace std;

void selectionsort(int arr[], int size, int& count)
{
	int pos; // position that increments at each iteration
	for (int i = 0; i < size-1; i++) // compare the first values with the values after it, the last value is always sorted 
	{
		pos = i; // set pos to i
		for (int j = i+1; j < size; j++) // compare every value after the i-value to see if its more or less than it
		{
			if (arr[j] < arr[pos]) // checks if the value after the i-value is less than the i-value
			{
				pos = j; // change pos to the value smaller than arr[i]
				count++;
			}
			count++;
		}
		if (pos != i)
		{
			int temp;
			temp = arr[i]; // swap arr[i] and the lowest value
			arr[i] = arr[pos];
			arr[pos] = temp;
			count++;
		}
		count++;
	}
	cout << "Selection Sorted Array:";
	for (int i = 0; i < size; i++) // print arr
	{
		cout << arr[i] << " ";
	}
	cout << "\n" << count << " comparisons\n" << endl;
}

void merge(int arr2[], int first, int mid, int last, int& count2)
{
	// merge both arrays back into one and sort them;
	int first1 = first; // start of 1st subarray
	int last1 = mid; // end of 1st subarray
	int first2 = mid + 1; // start of 2nd subarray
	int last2 = last; // end of 2nd subarray
	int tempArr[200]; // array to temporarily put the split array into one array
	int index = first1; // next available location in tempArr
	while ((first1 <= last1) && (first2 <= last2)) // move the smaller int into tempArr as long as both subarrays aren't empty
	{
		if (arr2[first1] <= arr2[first2])// if first int is less or eq to first int of right subarray, move the first val to tempArr
		{
			tempArr[index] = arr2[first1];
			first1++;
			count2++;
		}
		else // if not, move the first int of right subarray val to tempArr
		{
			tempArr[index] = arr2[first2];
			first2++;
			count2++;
		}
		index++; // move position of tempArr to next spot
		count2++;
	}
	while (first1 <= last1) // sort the 1st subarray and move any sorted values into tempArr
	{
		tempArr[index] = arr2[first1];
		first1++;
		index++;
		count2++;
	}
	while (first2 <= last2) // sort the 2nd subarray and move any sorted values into tempArr
	{
		tempArr[index] = arr2[first2];
		first2++;
		index++;
		count2++;
	}
	for (int i = first; i <= last; i++) // copy the data in tempArr to arr2, includes null terminator
	{
		arr2[i] = tempArr[i];
		count2++;
	}
}

void mergesorted(int arr2[], int first, int last, int& count2)
{
	int mid; // the last number in the first half
	if (first < last) // split the array into subarrays halves as long as the array isn't empty
	{
		mid = first + (last - first) / 2; // sets the midpoint
		mergesorted(arr2, first, mid, count2); // sorts the left subarray
		mergesorted(arr2, mid + 1, last, count2); // sorts the right subarray
		merge(arr2, first, mid, last, count2); // merge both subarrays into one array
		count2++;
	}
}

void mergesort(int arr2[], int first, int last, int& count2)
{
	mergesorted(arr2, first, last, count2); // sort the array
	cout << "Merged Sorted Array:"; // print sorted arr2
	for (int i = 0; i <= last; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "\n" << count2 << " comparisons\n" << endl;
}

void bucketsort(int arr3[], int size, int& count3)
{
	int count[101]; // create array of 101 buckets, from values 0 - 100
	for (int i = 0; i < 101; i++) // initialize all 101 values, function doesn't require this since it can be done manually, therefore no count3 needed 
	{
		count[i] = 0;
	}
	
	for (int i = 0; i < size; i++) // create buckets that each contain the number of times a value shows up in the array, if array=[0,2,2], count=[1,0,2,0,...] 
	{
		count[arr3[i]]++; // increment each time the same value in the array shows up
		count3++; // n
	}
	for (int i = 0, val = 0; i < 101; i++) // iteration for each bucket
	{
		for (int j = count[i]; j > 0; j--) // set values at arr3 with the # of times a value is in the bucket from lowest to highest, if count=[2,0,1,0,...], arr3=[0,0,2]
		{
			arr3[val] = i;
			val++;
			count3++; //2n+101
		}
		count3++; // n+n
	}
	cout << "Bucket Sorted Array:";
	for (int i = 0; i < size; i++) // print arr3
	{
		cout << arr3[i] << " ";
	}
	cout << "\n" << count3 << " comparisons\n" << endl;
}

int main()
{
	int arr[5] = {63,1,23,13,5};
	//int arr[128];
	int count=0;
	int arr2[7] = {21,1,2,37,8,55,4};
	//int arr2[128];
	int count2=0;
	int arr3[10] = {32,53,0,6,32,17,82,4,12,4};
	//int arr3[128];
	int count3=0;
	
	/*for (int i = 0; i < 128; i++) // make random numbers
	{
		arr2[i] = rand() % 100;
	}
	*/

	selectionsort(arr,5,count); // 21 comparisons, O(n^2)
	mergesort(arr2,0,6,count2); // 58 comparisons, O(n logn)
	bucketsort(arr3,10,count3); // 121 comparisons, O(n+n) -> O(2n+101) -> O(n) 
								// bucket sort is impractical as a general sorting algorithm because the algorithm takes up a lot of memory and time because
								// of the huge amount of buckets and the long range of values it needs and uses in the algorithm.
	system("pause");
    return 0;
}

// sample output
/*
Selection Sorted Array:1 5 13 23 63
22 comparisons

Merged Sorted Array:1 2 4 8 21 37 55
59 comparisons

Bucket Sorted Array:0 4 4 6 12 17 32 32 53 82
121 comparisons

*/
