#include <iostream>

int binarySearch(int arr[], int left, int right, int val)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == val)
		{
			return mid;
		}
		else if (arr[mid] < val)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 5, 6, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, size - 1, 5);
	if (result < 0)
	{
		std::cout << "Element is not present";
	}
	else
	{
		std::cout << "Element is present at index " << result;
	}
	return 0;
}