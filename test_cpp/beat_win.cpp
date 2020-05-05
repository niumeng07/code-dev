#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int a_win = 0;
  int b_win = 0;
  srand(time(NULL));
  for (int i = 0; i < 50000; i++) {
    int a = 100;
    int b = 10;
    while (1) {
      float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      ;
      if (r < 0.5) {
        a++;
        b--;
      } else {
        a--;
        b++;
      }
      if (a == 0 || b == 0) {
        if(b==0) a_win++;
        else b_win++;
        break;
      }
    }
  }
  cout << "a_win = " << a_win << "\tb_win = " << b_win << "a_win_rate=" << float(a_win) / (a_win+b_win)<< endl;
  return 0;
}
