#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;

double WilsonSmoothing(double probability, double samples) {
  if (std::isnan(probability) || std::isnan(samples) || std::isinf(probability) ||
      std::isinf(samples) || probability <= 0 || samples <= 0) {
    return 0;
  }
  if (samples > 400000) {
    return probability;
  }

  const double z = 1.96;
  double numerator = probability + (1 / (2 * samples)) * z * z -
                     z * std::sqrt((probability * (1 - probability) / samples) +
                                   (z * z) / (4 * samples * samples));
  double denominator = 1 + (1 / samples) * z * z;

  return numerator / denominator;
}

int main(int argc, char *argv[])
{
  cout << WilsonSmoothing(0.4, 100) << endl;
  cout << WilsonSmoothing(0.4, 1000) << endl;
  cout << WilsonSmoothing(0.4, 10000) << endl;
  cout << WilsonSmoothing(0.4, 100000) << endl;
  cout << WilsonSmoothing(0.4, 1000000) << endl;
  return 0;
}
