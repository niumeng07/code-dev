#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int32_t SectionByThre(T time, const std::vector<T>& thre) {
  return std::lower_bound(thre.begin(), thre.end(), time) - thre.begin();
}

int main(int argc, char *argv[])
{
  
    const std::vector<double> discrete_ctr_thre{
        0.0, 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2, 0.3, 0.4, 0.5};
    std::cout << SectionByThre(0.9, discrete_ctr_thre) << endl;

  return 0;
}
