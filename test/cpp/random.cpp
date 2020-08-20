#include <random>
#include "stdio.h"
#include <iostream>

using namespace std; 
int main(int argc, char *argv[]) {
  long all_count = 0;
  long select_count = 0;
  srand(time(NULL));
  std::cout << rand() << endl;
  for(int i = 0; i < 100000; i++) {
    if(rand() % 100 < 90) {
        select_count++;
    }
    all_count++;
  }
  cout << select_count << ", " << all_count << endl;
  cout << (float)select_count / (float)all_count << endl;
  srand(time(NULL));
  // cout << float(rand() % 100) /100 << endl;
  cout << "--------------------------------" << endl;
  srand((unsigned)time(NULL));
  all_count = 0;
  select_count = 0;
  for(int i = 0; i < 100000; i++) {
    if(random() % 100 < 90) {
        select_count++;
    }
    all_count++;
  }
  cout << select_count << ", " << all_count << endl;
  cout << (float)select_count / (float)all_count << endl;

  return 0;
}
