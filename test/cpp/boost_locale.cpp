#include <boost/algorithm/string.hpp>
#include <string>
#include <locale>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Тысяча Онлайн HD";
  std::string upper_case1 = to_lower_copy(s);
  std::cout << s << std::endl;
  std::cout << upper_case1 << std::endl;
}
