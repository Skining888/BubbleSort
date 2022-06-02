#pragma once

void swap(int* i, int* j);
void XorSwap(int* i, int* j);
int SelectMax(int arr[], int Max_pos, int Min_pos);
int SelectMin(int arr[], int Max_pos, int Min_pos);
void SelectSort(int arr[], int Max_pos, int Min_pos);

//记录右边界的位置下标（Max_pos）
int Max_pos = 0;
//记录左边界位置下标（Min_pos）
int Min_pos = 0;



//选择排序总结
//选择排序思想：每次找到最大值的下标，然后将此下标的值与数组的最后一个元素交换，如此执行N -1 次即可排序完成；
//选择排序最大的时间复杂度为O（N^2）;
//优化方法：
//1.使用异或的方式交换两个变量，减小临时变量的消耗；此处要注意如果两个变量相等，异或之后结果就为0，需要做下判断；
//2.一次选择交换的循环中，同时交换最大值与最小值，使得循环次数减少为原来的1/2;
//  同时在遍历找出最大值与最小值的下标的时候，每次都会少循环一次
