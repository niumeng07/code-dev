#include <functional> // std::ref
#include <future>     // std::promise, std::future
#include <iostream>   // std::cout
#include <thread>     // std::thread
#include <unistd.h>

using namespace std;
void print_int(std::future<int> &fut) {
  int x = fut.get();                   // 获取共享状态的值.
  std::cout << "value: " << x << '\n'; // 打印 value: 10.
}

std::promise<int> prom;
void print_global_promise() {
  std::future<int> fut = prom.get_future();
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}
int main() {
  std::promise<int> prom; // 生成一个 std::promise<int> 对象.
  std::future<int> fut = prom.get_future(); // 和 future 关联.
  std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.

  sleep(1);
  prom.set_value(10); // 设置共享状态的值, 此处和线程t保持同步.
  t.join();


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
