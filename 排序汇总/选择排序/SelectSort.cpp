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
	//�������������ͬ��������Ϊ0����Ҫ�����ж�
	if (*i == *j)
	{
		return;
	}
	*i ^=  *j;
	*j ^=  *i;
	*i ^=  *j;
	return;
}
//�������ֵ���±�
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

//�õ����ֵ���±ꡣ�������ֵ���������һλ������
void SelectSort(int arr[], int n)
{
	//ִ��n-1�μ�������
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