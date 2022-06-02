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

//������Сֵ���±�
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

//�õ����ֵ���±ꡣ�������ֵ���������һλ������(��Сֵͬ��)
void SelectSort(int arr[], int Max_pos, int Min_pos)
{
	//count������Ҫִ�еĴ�����һ��ѭ��ѡ��һ�����ֵ��һ����Сֵ�����ֻ��Ҫѭ�� N/2 ��
	//�˴���Ϊѡ��Max_posΪ�±꣬����ѭ�������ļ�����Ҫ(Max_pos + 1) / 2
	// �Ż�����ʹ��count���ѭ��������ʹ����߽�С���ұ߽���жϷ��������ٱ���������
	//int count = (Max_pos + 1) / 2;
	while (Min_pos < Max_pos)
	{
		int max_pos = SelectMax(arr, Max_pos, Min_pos);
		XorSwap(&arr[max_pos], &arr[Max_pos]);
		//Max_pos-- ����ʹ������Ѱ����Сֵ���±��ʱ���ٱ���һ�Σ����������ұ߽�
		Max_pos--;
		int min_pos = SelectMin(arr, Max_pos, Min_pos);
		XorSwap(&arr[min_pos], &arr[Min_pos]);
		//swap(&arr[pos], &arr[n - 1]);
		//Min_pos++ ����ʹ������Ѱ�����ֵ���±��ʱ���ٱ���һ�Σ�����������߽�
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