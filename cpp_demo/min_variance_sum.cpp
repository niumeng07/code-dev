#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<double> input({121.0, -3, 50.0, 1, 3, 9, 11, 5, 2, 1, 3.5, 12, 10, 100.0,
                      456.00});

double var_sum(vector<double> &vec, int start, int end) { // O(N)
  double mean = 0.0;
  for (int i = start; i <= end; i++) {
    mean += vec[i];
  }
  mean = mean / (end - start + 1);
  double var = 0.0;
  for (int i = start; i <= end; i++) {
    var += (vec[i] - mean) * (vec[i] - mean);
  }
  var = var / (end - start + 1);
  return var;
}
double function1() {
  double min_var_sum = 9999999.99;
  double min_var_left = 0.0;
  double min_var_right = 0.0;
  int minK = 0;
  for (int K = 0; K < input.size(); K++) {          // O(N) * O(2N)=O(N^2)
    double var_sum_left = var_sum(input, 0, K - 1); // O(N)
    double var_sum_right = var_sum(input, K, input.size() - 1); // O(N)
    if ((var_sum_left + var_sum_right) < min_var_sum) {
      min_var_sum = var_sum_left + var_sum_right;
      minK = K;
      min_var_left = var_sum_left;
      min_var_right = var_sum_right;
    }
  }
  // cout << "minK = " << minK << ", minVar = " << min_var_sum << endl;
  return min_var_sum;
}
double function2() {
  double left_sum = 0.0;
  double right_sum = 0.0;
  double left_square_sum = 0.0;
  double right_square_sum = 0.0;
  int N = input.size();
  double minK = 0.0;
  double min_var = 999999999.99;

  for (int K = 0; K < input.size(); K++) {
    right_sum += input[K];
    right_square_sum += (input[K] * input[K]);
  }
  double var;
  for (int K = 0; K <= N; K++) {
    var = 0.0;
    if (K != 0) {
      left_square_sum += (input[K - 1]) * (input[K - 1]);
      left_sum += input[K - 1];
      var += left_square_sum / K;
      var += left_sum * left_sum / (K * K);
      var += -2.0 / (K * K) * (left_sum) * (left_sum);
    }
    if (K != N) {
      double last_item = 0.0;
      if (K > 0) {
        last_item = input[K - 1];
      }
      right_square_sum -= (last_item) * (last_item);
      right_sum -= (last_item);
      var += right_square_sum / (N - K);
      var += right_sum * right_sum / ((N - K) * (N - K));
      var += -2.0 / ((N - K) * (N - K)) * (right_sum) * (right_sum);
    }
    if (var < min_var) {
      min_var = var;
      minK = K;
    }
  }
  // cout << "minK = " << minK << ", minVar = " << min_var << endl;
  return min_var;
}
int main(int argc, char *argv[]) {
  clock_t start, end;
  start = clock();
  for (int i = 0; i < 10000; i++) {
    function1();
  }
  end = clock();
  cout << end - start << endl;
  start = clock();
  for (int i = 0; i < 10000; i++) {
    function2();
  }
  end = clock();
  cout << end - start << endl;
  cout << function1() << endl;
  cout << function2() << endl;
  return 0;
}
