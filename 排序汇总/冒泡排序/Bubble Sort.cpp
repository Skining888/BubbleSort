#include<stdio.h>
#include<iostream>
#include"BubbleSort.h"
using namespace std;

//swap传参为数组指针，否则无法交换数组元素
void swap(int *i, int *j)
{
	int temp = 0;
	temp = *i;
	*i = *j;
	*j = temp;
	return;
}

//交换两个变量的值，可以使用异或方法，减少临时变量的开销
void XorSwap(int* i, int* j)
{
	//异或两个相同数字的值为0，需要做下判断
	if (*i == *j)
	{
		return;
	}
	*i = *i ^ *j;
	*j = *j ^ *i;
	*i = *i ^ *j;
	return;
}
//两个数值之间进行比较
void bubble(int arr[],int n)
{
	int i;
	int temp = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			//swap(&arr[i], &arr[i + 1]);
			/*temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;*/
			XorSwap(&arr[i], &arr[i + 1]);
			orderly = false;
		}
	}
	return;
}

//比较n-1次
void BubbleSort(int arr[], int n)
{
	int i;
	for (i = n; i >= 1; i--)
	{
		orderly = true;
		bubble(arr,i);
		//标志位orderly为true,说明元素已经有序，结束排序
		if (orderly)
		{
			break;
		}

	}
	return;
}

int main()
{
	//int arr[] = { 9,6,8,4,3,7,2,1,5 };
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]); //计算数组大小
	cout << "arr_size = " << arr_size << endl;
	BubbleSort(arr, arr_size);
	int i;
	for (i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
 	}
	system("pause");
	return 0;
}