#include <iostream>

int main() {
  long x= (long(456) << 32) + 123;
  long y = (long(789) << 32) + 345;
  long z = (((x & 0x00000000ffffffff)+ (y & 0x00000000ffffffff)) & 0x00000000ffffffff) 
          + (((((x & 0xffffffff00000000)>>32)+ ((y & 0xffffffff00000000)>>32)) << 32) & 0xffffffff00000000);

  // 1958505087099, 3388729196889, 5347234283988
  std::cout << x << ", " << y << ", " << z << std::endl;

  std::cout << ((z & 0xffffffff00000000) >> 32) << ", " << (z & 0x00000000ffffffff) << std::endl;
  std::cout << 456 + 789 << ", " << 123 + 345 << std::endl;


  uint32_t report = 1 & 1 & 1 & 1 & 1;
  uint32_t report2 = 0 & 1 & 0 & 1 & 1;
  if (report) std::cout << "report "<< report << std::endl;
  if (report2) std::cout << "report2" << report2 << std::endl;
  return 0;
}
