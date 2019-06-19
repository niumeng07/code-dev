#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &vec) {
  for (auto x : vec)
    cout << x << "  ";
  cout << endl;
}
void swap_i(int &i, int &j) {
  i = i + j;
  j = i - j;
  i = i - j;
}

int repartition(vector<int> &input, int begin, int end) {
  int i = begin, j = end - 1;
  while (i < j) {
    if (input[i] > input[end] && input[j] < input[end]) {
      swap_i(input[i], input[j]);
      i++;
      j--;
    } else if (input[i] <= input[end])
      i++;
    else if (input[j] >= input[end])
      j--;
  }
  if (input[end] < input[j])
    swap_i(input[j], input[end]);
  return i;
}
void quick_sort(vector<int> &input, int start, int end) {
  if (end <= start)
    return;
  if (end >= start + 2) {
    int mid = repartition(input, start, end);
    quick_sort(input, start, mid);
    quick_sort(input, mid, end);
  } else if (end == start + 1) {
    if (input[start] > input[end])
      swap(input[start], input[end]);
  }
}
int main() {
  vector<int> init({2, 1, 6, 2, 9, 6, 1, -1, 0, 8, 4, 3});
  printVector(init);
  quick_sort(init, 0, init.size() - 1);
  printVector(init);
}
