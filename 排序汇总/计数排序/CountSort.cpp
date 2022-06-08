#include<iostream>
#include"CountSort.h"
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

int FindMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int FindMin(int arr[], int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int Count(int arr[], int n, int pos)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == pos)
		{
			count++;
		}
	}
	return count;
}

void Sort(int arr[], int count_arr[], int max, int min)
{
	int size_count_arr = max - min + 1;
	int pos = 0;
	for (int i = 0; i < size_count_arr; i++)
	{
		int count = count_arr[i];
		while (count)
		{
			arr[pos] = min;
			pos++;
			count--;
		}
		min++;
	}
}

void CountSort(int arr[], int n)
{
	int max = FindMax(arr, n);
	int min = FindMin(arr, n);
	int* count_arr = new int[max - min + 1];
	int j = 0;
	for (int i = min; i <= max; i++)
	{
		count_arr[j] = Count(arr, n, i);
		j++;
	}
	Sort(arr, count_arr, max, min);
	delete[]count_arr;
}

int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int size_arr = sizeof(arr) / sizeof(arr[0]);
	Diy_printf(arr, size_arr);
	//cout << FindMax(arr, size_arr) << endl;
	//cout << FindMin(arr, size_arr) << endl;
	CountSort(arr, size_arr);
	Diy_printf(arr, size_arr);
	system("pause");
	return 0;
}