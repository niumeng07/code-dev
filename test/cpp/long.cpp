#include <iostream>
#include <limits>

int main(int argc, char *argv[])
{

  // long x = (std::numeric_limits<long>::max)();
  // uint64_t y = (std::numeric_limits<uint64_t>::max)();
  // std::cout << x << std::endl;
  // std::cout << y << std::endl;

  long x1 = 47; //当前时长1
  long x2 = 92;//浮层时长1
  long y1 = 49;//当前时长2
  long y2 = 93;//浮层时长2
  
  std::cout << "x1 + x2 = " << x1 + x2 << std::endl;
  std::cout << "y1 + y2 = " << y1 + y2 << std::endl;

  long z1 = (x1 & 0x00000000ffffffff) + ((y1 << 32) & 0xffffffff00000000); //时长1合并
  long z2 = (x2 & 0x00000000ffffffff) + ((y2 << 32) & 0xffffffff00000000); //时长2合并
  
  long target = x1 + y1 + ((x2 + y2) << 32); //总的合并时长
  std::cout << target << std::endl;

  // 要从z1中恢复出x1,y1, 从z2中恢复出x2,y2,target中恢复中(x1+y1),(x2+y2)

  long x1_ = z1 & 0x00000000ffffffff;
  std::cout << x1 << ", " << x1_ << std::endl;
  long x2_ = z2 & 0x00000000ffffffff;
  std::cout << x2 << ", " << x2_ << std::endl;

  long y1_ = (z1 & 0xffffffff00000000) >> 32;
  std::cout << y1 << ", " << y1_ << std::endl;
  long y2_ = (z2 & 0xffffffff00000000)>>32;
  std::cout << y2 << ", " << y2_ << std::endl;
  return 0;
}
