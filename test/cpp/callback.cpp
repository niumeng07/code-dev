#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int getNextRandomValue() {
  return rand();
}

// 回调无参getNextRandomValue函数
void populate_vec(vector<int>& vec, int (*getNextValue)()) {
  for (size_t i = 0; i < vec.capacity(); i++)
    vec.emplace_back(getNextValue());
}

int getNextRandomValue(int x) {
  return rand() % x;
}
// 回调有参getNextRandomValue函数
void populate_vec(vector<int>& vec, int (*getNextValue)(int), int x) {
  for (size_t i = 0; i < vec.capacity(); i++)
    vec.emplace_back(getNextValue(x));
}


void print_vector(vector<int>& vec) {
  for (int i = 0; i < 10; i++) {
    cout << vec[i] << ",";
  }
  cout << endl;
}
int main() {
  vector<int> vec;
  vec.reserve(10);
  populate_vec(vec, getNextRandomValue);
  print_vector(vec);

  // getNextRandomValue是回调函数,不写(参数),只传指针
  vec.clear();
  vec.reserve(10);
  populate_vec(vec, getNextRandomValue, 100);
  print_vector(vec);
  return 0;
}
