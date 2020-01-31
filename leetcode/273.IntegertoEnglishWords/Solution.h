#include <array>
#include <iostream>
using namespace std;

class Solution {
public:
  using DigitArray = std::array<std::int8_t, 10>;
  static DigitArray intToDigitArray(int, int &);
  static bool convert(std::int8_t hundred, std::int8_t ten, std::int8_t unit,
                      std::string &result);

public:
  std::string numberToWords(int);
};

Solution::DigitArray Solution::intToDigitArray(int num, int &digitCount) {
  DigitArray result;
  DigitArray::size_type i = 0;

  do {
    result[i++] = num % 10;
    num /= 10;
  } while (num);

  digitCount = i;

  while (i < result.size())
    result[i++] = -1;

  return result;
}

bool Solution::convert(std::int8_t hundred, std::int8_t ten, std::int8_t unit,
                       std::string &result) {
  constexpr std::array<const char *, 9> stringNumbers = {
      "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  constexpr std::array<const char *, 9> stringTens = {
      "Ten",   "Twenty",  "Thirty", "Forty", "Fifty",
      "Sixty", "Seventy", "Eighty", "Ninety"};
  constexpr std::array<const char *, 9> stringTeens = {
      "Eleven",  "Twelve",    "Thirteen", "Fourteen", "Fifteen",
      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  bool modified = false;

  if (hundred > 0) {
    modified = true;
    if (!result.empty())
      result.push_back(' ');
    result.append(stringNumbers[hundred - 1]);
    result.append(" Hundred");
  }

  if (ten > 0) {
    modified = true;
    if (ten == 1 && unit > 0) {
      if (!result.empty())
        result.push_back(' ');
      result.append(stringTeens[unit - 1]);
      return modified;
    } else {
      if (!result.empty())
        result.push_back(' ');
      result.append(stringTens[ten - 1]);
    }
  }

  if (unit > 0) {
    modified = true;
    if (!result.empty())
      result.push_back(' ');
    result.append(stringNumbers[unit - 1]);
  }

  return modified;
}

std::string Solution::numberToWords(int num) {
  int digitCount;
  DigitArray digits = intToDigitArray(num, digitCount);
  std::string result;

  switch (digitCount) {
  case 10:
    if (convert(0, 0, digits[9], result))
      result.append(" Billion");

  case 7:
  case 8:
  case 9:
    if (convert(digits[8], digits[7], digits[6], result))
      result.append(" Million");

  case 4:
  case 5:
  case 6:
    if (convert(digits[5], digits[4], digits[3], result))
      result.append(" Thousand");

  case 3:
  case 2:
  case 1:
    convert(digits[2], digits[1], digits[0], result);

    if (result.empty() && !digits[0])
      result = "Zero";
  }

  return result;
}
