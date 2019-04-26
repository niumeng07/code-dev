#include <iostream>
#include <vector>
using namespace std;

template <class T>
void func1( T &x, T &y )
{ T temp;
  temp = x;  x = y;  y = temp;
}

class Car {
    public:
        int x;
        Car (int y, int z) : x(y) {cout << "init" << endl;}
        void echo() {
            std::cout << "echo" << endl;
        }
};

int main()
{
  //Car *p=new Car(1,2);
  //p->echo();


  vector<int> vec({1,3,2,9,2});
  int x = 0;
  for(int i = 0; i<vec.size(); i++) {
      int xx = 0;
      for(int j=0;j<vec.size(); j++) {
          xx += vec[i]*vec[j];
      }
      x += xx;
  }
  cout << x << endl;
  cout << 17 * 17 << endl;


  return 0;
}

