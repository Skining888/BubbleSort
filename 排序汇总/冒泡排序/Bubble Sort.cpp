#include<stdio.h>
#include<iostream>
#include"BubbleSort.h"
using namespace std;

//swap����Ϊ����ָ�룬�����޷���������Ԫ��
void swap(int *i, int *j)
{
	int temp = 0;
	temp = *i;
	*i = *j;
	*j = temp;
	return;
}

//��������������ֵ������ʹ����򷽷���������ʱ�����Ŀ���
void XorSwap(int* i, int* j)
{
	//���������ͬ���ֵ�ֵΪ0����Ҫ�����ж�
	if (*i == *j)
	{
		return;
	}
	*i = *i ^ *j;
	*j = *j ^ *i;
	*i = *i ^ *j;
	return;
}
//������ֵ֮����бȽ�
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

//�Ƚ�n-1��
void BubbleSort(int arr[], int n)
{
	int i;
	for (i = n; i >= 1; i--)
	{
		orderly = true;
		bubble(arr,i);
		//��־λorderlyΪtrue,˵��Ԫ���Ѿ����򣬽�������
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
	int arr_size = sizeof(arr) / sizeof(arr[0]); //���������С
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