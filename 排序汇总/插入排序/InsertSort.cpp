#include<iostream>
#include<stdio.h>
#include"InsertSort.h"
using namespace std;

int Insert(int arr[], int n, int count)
{
	int pos = 0;
	int i = count;
	for (i; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			pos = i;
			return pos;
		}
	}
	//return 0 说明元素有序，无需排序
	return 0;
}
void InsertSort(int arr[], int n)
{
	int count = 1;
	while (count < n)
	{
		int i = Insert(arr, n, count);
		//寻找的数组是有序的，无需进行排序
		if (0 == i)
		{
			return;
		}
		int key = arr[i];
		for (i; i > 0; i--)
		{
			if (key < arr[i - 1])
			{
				arr[i] = arr[i - 1];
				arr[i - 1] = key;
			}
			//此处注意，要插入的位置是第一个数字的时候，要结束遍历，否则会越界，因为是跟 i - 1 去比较的
			if (1 == i)
			{
				break;
			}
			
		}
		count++;
	}
	return;
}
int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << "arr_size = " << arr_size << endl;
	InsertSort(arr, arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}