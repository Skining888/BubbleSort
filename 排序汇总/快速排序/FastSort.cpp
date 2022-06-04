#include<stdio.h>
#include<iostream>
#include"FastSort.h"
using namespace std;
void OnceFastSort(int arr[], int& left, int& right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right)
		{
			if (arr[right] < key)
			{
				arr[left] = arr[right];
				left++;
				break;
			}
			else
			{
				right--;
			}
		}
		while (left < right)
		{
			if (arr[left] > key)
			{
				arr[right] = arr[left];
				right--;
				break;
			}
			else
			{
				left++;
			}
		}
	}
	arr[left] = key;
}
void FastSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	//要遍历的序列只有一个元素时，认为有序，return;
	if (left >= right)
	{
		return;
	}
	OnceFastSort(arr, left, right);
	//递归遍历左序列,遍历的右边界-1
	FastSort(arr, i, right - 1);
	//递归遍历右序列，遍历的左边界+1
	FastSort(arr, left + 1, j);
}


int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	FastSort(arr, 0, arr_size - 1);
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}