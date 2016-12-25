// Andrew Torres
// HW3.cpp

#include <iostream>

using namespace std;

void merge(int *arr, int low, int mid, int high);
void mergeSort(int *arr, int low, int high);

int main()
{
	int userInput;
	int length;

	cout << "How many integers will you be inputting?" << endl;
	cin >> length;

	int *nums = new int[length];

	cout << "Begin inputting numbers" << endl;
	for (int c = 0; c < length; c++)
	{
		cout << c + 1 << ": ";
		cin >> userInput;

		nums[c] = userInput;


	}

	cout << endl << "The unsorted list:" << endl;
	for (int a = 0; a < length; a++)	
		cout << nums[a] << ", ";
	

	cout << endl << "Begin mergeSort" << endl;
	mergeSort(nums, 0, length - 1);

	cout << "The sorted list:" << endl;
	for (int b = 0; b < length; b++)
		cout << nums[b] << ", ";

	cout << endl << "Good Bye!" << endl;
	cin >> userInput; 
	delete[] nums;

}

void merge(int *arr, int low, int mid, int high)
{

	int i;		//lower index
	int j;		//higher index
	int k;		//index for temp
	i = low;
	k = low;
	j = mid + 1;
	int temp[100];

	//Go through top half and bot half until ones is used up
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else {
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	//Fill temp with all remaining values
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}

	//set original array to the sorted version of temp
	for (i = low; i < k; i++)
	{
		arr[i] = temp[i];
	}

}

void mergeSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int middle = (low + high) / 2;

		mergeSort(arr, low, middle);
		mergeSort(arr, middle + 1, high);

		merge(arr, low, middle, high);
	}
}