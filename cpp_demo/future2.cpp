#include <future>   // std::promise, std::future
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <unistd.h>

using namespace std;
std::promise<int> prom;

void print_global_promise() {
  std::future<int> fut = prom.get_future();
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}

int main() {
  std::thread th1(print_global_promise);
  cout << 1 << endl;
  prom.set_value(10); // print value 10
  // prom.set_value(30);// will cause error. Promise already satisfied
  sleep(1);
  cout << 2 << endl;
  th1.join();
  cout << 3 << endl;

  prom = std::promise<int>(); // prom 被move赋值为一个新的 promise 对象.

  std::thread th2(print_global_promise);
  prom.set_value(20);//同一个进程只获取一次
  th2.join();

  return 0;
}
