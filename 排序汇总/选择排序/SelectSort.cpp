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
int SelectMax(int arr[], int Max_pos,int Min_pos)
{
	int max = arr[Min_pos];
	int max_pos = Min_pos;
	for (Min_pos; Min_pos < Max_pos; Min_pos++)
	{
		if (max < arr[Min_pos + 1])
		{
			max = arr[Min_pos + 1];
			max_pos = Min_pos + 1;
		}
	}
	return max_pos;
}

//返回最小值的下标
int SelectMin(int arr[], int Max_pos, int Min_pos)
{
	int min = arr[Min_pos];
	int min_pos = Min_pos;
	for (Min_pos; Min_pos < Max_pos; Min_pos++)
	{
		if (min > arr[Min_pos + 1])
		{
			min = arr[Min_pos + 1];
			min_pos = Min_pos + 1;
		}
	}
	return min_pos;
}

//拿到最大值的下标。交换最大值与数组最后一位的数字(最小值同理)
void SelectSort(int arr[], int Max_pos, int Min_pos)
{
	//count计算需要执行的次数，一次循环选择一个最大值，一个最小值，因此只需要循环 N/2 次
	//此处因为选择Max_pos为下标，所以循环次数的计算需要(Max_pos + 1) / 2
	// 优化：不使用count标记循环次数，使用左边界小于右边界的判断方法，减少变量的消耗
	//int count = (Max_pos + 1) / 2;
	while (Min_pos < Max_pos)
	{
		int max_pos = SelectMax(arr, Max_pos, Min_pos);
		XorSwap(&arr[max_pos], &arr[Max_pos]);
		//Max_pos-- 可以使接下来寻找最小值的下标的时候，少遍历一次，即遍历的右边界
		Max_pos--;
		int min_pos = SelectMin(arr, Max_pos, Min_pos);
		XorSwap(&arr[min_pos], &arr[Min_pos]);
		//swap(&arr[pos], &arr[n - 1]);
		//Min_pos++ 可以使接下来寻找最大值的下标的时候，少遍历一次，即遍历的左边界
		Min_pos++;
		//count--;
	}
	return;
}
int main()
{
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//int arr[] = { 7,8,5,4,9,2,3,1,6 };
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int Max_pos = arr_size - 1;
	int Min_pos = 0;
	cout << "arr_size = " << arr_size << endl;
	SelectSort(arr, Max_pos, Min_pos);
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}