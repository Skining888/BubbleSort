#include<iostream>
#include"ShellSort.h"
using namespace std;

void Diy_printf(int arr[], int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	return;
}

int Insort(int arr[], int n, int mid)
{
	int pos = mid;
	for (pos; pos < n; pos += mid)
	{
		if (arr[pos] < arr[pos - mid])
		{
			return pos;
		}
	}
	return 0;
}
void InsertSort(int arr[], int n,int mid)
{
	int count = mid;
	while (count < n)
	{
		int i = Insort(arr, n, mid);
		int key = arr[i];
		if (0 == i)
		{
			return;
		}
		for (i; i > 0; i -= mid)
		{
			if (key < arr[i - mid])
			{
				arr[i] = arr[i - mid];
				arr[i - mid] = key;
			}
			if (i == 0)
			{
				break;
			}
		}
		count++;
	}
}
void ShellSort(int arr[], int n)
{
	int mid = n / 2;
	while (mid >= 1)
	{
		InsertSort(arr, n, mid);
		mid = mid / 2;
	}
}

int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	//int arr[] = { 7,9,8,6,5 };
	int size_arr = sizeof(arr) / sizeof(arr[0]);
	Diy_printf(arr, size_arr);
	ShellSort(arr, size_arr);
	//InsertSort(arr, size_arr);
	Diy_printf(arr, size_arr);
	system("pause");
	return 0;
}