#include <iostream>
#include <unordered_map>

using namespace std;

static std::unordered_map<int, int> mpStrategyKey = {
        {0, 18},  {1, 19},  {2, 20},  {3, 21},  {4, 22},  {5, 23},  {6, 24},
        {7, 25},  {8, 26},  {9, 27},  {10, 28}, {11, 29}, {12, 30}, {13, 31},
        {14, 58}, {15, 59}, {16, 60}, {17, 61}, {18, 62}, {19, 63}, {20, 64},
        {21, 65}, {22, 66}, {23, 67}, {24, 68}, {25, 69}, {26, 70}, {27, 71},
        {28, 72}, {29, 73}, {30, 74}, {31, 75}, {32, 76}, {33, 77}, {34, 78},
        {35, 79}, {36, 80}, {37, 81}, {38, 82}, {39, 83}, {40, 84}, {41, 85},
        {42, 86}, {54, 97}};
static std::unordered_map<int, int> mpStrategyKey2 = {
        {59, 0}, {90, 1}, {97, 2}, {107, 3}, {117, 4}, {118, 5}, {119, 6}};

int main(int argc, char *argv[]) {
  for (auto item : mpStrategyKey) {
    std::cout << item.first << ";" << item.second << std::endl;
  }
  return 0;
}
