#pragma once

void swap(int* i, int* j);
void XorSwap(int* i, int* j);
int SelectMax(int arr[], int n);
void SelectSort(int arr[], int n);




//选择排序总结
//选择排序思想：每次找到最大值的下标，然后将此下标的值与数组的最后一个元素交换，如此执行N -1 次即可排序完成；
//选择排序最大的时间复杂度为O（N^2）;
//优化方法：
//1.使用异或的方式交换两个变量，减小临时变量的消耗；此处要注意如果两个变量相等，异或之后结果就为0，需要做下判断；
