#pragma once

void swap(int* i, int* j);
void XorSwap(int* i, int* j);
int SelectMax(int arr[], int Max_pos, int Min_pos);
int SelectMin(int arr[], int Max_pos, int Min_pos);
void SelectSort(int arr[], int Max_pos, int Min_pos);

//��¼�ұ߽��λ���±꣨Max_pos��
int Max_pos = 0;
//��¼��߽�λ���±꣨Min_pos��
int Min_pos = 0;



//ѡ�������ܽ�
//ѡ������˼�룺ÿ���ҵ����ֵ���±꣬Ȼ�󽫴��±��ֵ����������һ��Ԫ�ؽ��������ִ��N -1 �μ���������ɣ�
//ѡ����������ʱ�临�Ӷ�ΪO��N^2��;
//�Ż�������
//1.ʹ�����ķ�ʽ����������������С��ʱ���������ģ��˴�Ҫע���������������ȣ����֮������Ϊ0����Ҫ�����жϣ�
//2.һ��ѡ�񽻻���ѭ���У�ͬʱ�������ֵ����Сֵ��ʹ��ѭ����������Ϊԭ����1/2;
//  ͬʱ�ڱ����ҳ����ֵ����Сֵ���±��ʱ��ÿ�ζ�����ѭ��һ��
