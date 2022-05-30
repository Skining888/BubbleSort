#include<stdio.h>

//swap����Ϊ����ָ�룬�����޷���������Ԫ��
void swap(int *i, int *j)
{
	int temp = 0;
	temp = *i;
	*i = *j;
	*j = temp;
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
			swap(&arr[i], &arr[i + 1]);
			/*temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;*/
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
		bubble(arr, i);
	}
	return;
}

int main()
{
	int arr[] = { 9,6,8,4,3,7,2,1,5 };
	int arr_size = sizeof(arr) / sizeof(arr[0]); //���������С
	printf("arr_size = %d\n", arr_size);
	BubbleSort(arr, arr_size);
	int i;
	for (i = 0; i < arr_size; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}