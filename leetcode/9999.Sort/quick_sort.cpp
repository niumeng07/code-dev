#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &input) {
  for (auto x : input)
    cout << x << "\t";
  cout << endl;
}
int repartition(vector<int> &input, int left, int right) {
  int i = left, j = right - 1, middle = right;
  while (i < j) {
    if (input[i] > input[middle] && input[j] < input[middle])
      swap(input[i++], input[j--]);
    else if (input[i] <= input[middle])
      i++;
    else if (input[j] >= input[middle])
      j--;
  }
  if (input[right] < input[j])
    swap(input[right], input[j]);
  return i;
}
void quick_sort(vector<int> &input, int left, int right) {
  if (right <= left)
    return;
  if (right > left + 1) {
    int j = repartition(input, left, right);
    quick_sort(input, left, j);
    quick_sort(input, j, right);
  } else if (right == left + 1) {
    if (input[right] < input[left])
      swap(input[left], input[right]);
  }
}
int main() {
  vector<int> input({2, 1, 6, 2, 9, 6, 1, -1, 0, 8, 4, 3});
  print_vector(input);
  quick_sort(input, 0, input.size() - 1);
  print_vector(input);
}
