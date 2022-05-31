#include<stdio.h>
#include<iostream>
#include"SelectSort.h"
using namespace std;


void swap(int* i, int* j)
{
	int temp = 0;
	temp = *i;
	*i = *j;
	*j = temp;
	return;
}

void XorSwap(int* i, int* j)
{
	//如果两个变量相同，异或后结果为0，需要做下判断
	if (*i == *j)
	{
		return;
	}
	*i ^=  *j;
	*j ^=  *i;
	*i ^=  *j;
	return;
}
//返回最大值的下标
int SelectMax(int arr[], int n)
{
	int max = arr[0];
	int pos = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (max < arr[i + 1])
		{
			max = arr[i + 1];
			pos = i + 1;
		}
	}
	return pos;
}

//拿到最大值的下标。交换最大值与数组最后一位的数字
void SelectSort(int arr[], int n)
{
	//执行n-1次即可排序
	while (n > 1)
	{
		int pos = SelectMax(arr, n);
		//swap(&arr[pos], &arr[n - 1]);
		XorSwap(&arr[pos], &arr[n - 1]);
		n--;
	}
	return;
}
int main()
{
	int arr[] = { 7,8,5,4,9,2,3,1,6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << "arr_size = " << arr_size << endl;
	SelectSort(arr, arr_size);
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}