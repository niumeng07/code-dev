#include <iostream>
using namespace std;

/*���������������ǽ��������е�����Ԫ�ص�λ��*/
void swap(int array[], int i, int j) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

/*����ֵ�ŵ�������ʵ���λ��*/
int partition(int array[], int left, int right) {
  int mid = (left + right) / 2;
  int tmp = array[mid];
  swap(array, mid, right);
  int i = left;
  int j = right;
  while (1) {
    /*iָ�������ƶ���ֱ���ҵ�һ��������ֵ��ֵ*/
    while (1) {
      /*���i��j������ȷ����ֵλ�ã����䷵��*/
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
    /*jָ�������ƶ���ֱ���ҵ�һ��С����ֵ��ֵ*/
    while (1) {
      /*���i��j������ȷ����ֵλ�ã����䷵��*/
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

/*��������*/
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
