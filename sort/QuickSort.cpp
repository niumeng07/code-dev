#include <iostream>
using namespace std;

/*交换函数，作用是交换数组中的两个元素的位置*/
void swap(int array[], int i, int j) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

/*将轴值放到数组的适当的位置*/
int partition(int array[], int left, int right) {
  int mid = (left + right) / 2;
  int tmp = array[mid];
  swap(array, mid, right);
  int i = left;
  int j = right;
  while (1) {
    /*i指针向右移动，直到找到一个大于轴值的值*/
    while (1) {
      /*如果i与j相遇则确定轴值位置，将其返回*/
      if (i == j) {
        array[i] = tmp;
        return i;
      }
      if (array[i] > tmp) {
        array[j] = array[i];
        j--;
        break;
      }
      i++;
    }
    /*j指针向左移动，直到找到一个小于轴值的值*/
    while (1) {
      /*如果i与j相遇则确定轴值位置，将其返回*/
      if (i == j) {
        array[j] = tmp;
        return j;
      }
      if (array[j] < tmp) {
        array[i] = array[j];
        i++;
        break;
      }
      j--;
    }
  }
}

/*快速排序*/
void quickSort(int array[], int left, int right) {
  if (right <= left)
    return;
  int pivot = partition(array, left, right);
  quickSort(array, left, pivot - 1);
  quickSort(array, pivot + 1, right);
}

int main() {
  int array[8] = {6, 8, 7, 3, 1, 2, 5, 4};
  quickSort(array, 0, 7);
  for (int i = 0; i < 8; i++)
    cout << array[i] << "  ";
  cout << endl;
  return 0;
}
