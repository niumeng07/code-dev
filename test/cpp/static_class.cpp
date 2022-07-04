#include <iostream>
using namespace std;

class Statistics {
public:
  float Ctr;
  float Time;
  float Transform;
  float ChdTime;
  float ChdNum;
};
class ImpressStatistics {
public:
  Statistics ShortVideo;
  Statistics MiniVideo;
  ImpressStatistics() {
    ShortVideo.Ctr = 0.090384483;
    ShortVideo.Time = 99.04880938;
    ShortVideo.Transform = 0.04519521;
    ShortVideo.ChdTime = 287.5667664;
    ShortVideo.ChdNum = 8.701545564;
    MiniVideo.Ctr = 0.195671062;
    MiniVideo.Time = 24.43356258;
    MiniVideo.Transform = 0.168559138;
    MiniVideo.ChdTime = 241.1847745;
    MiniVideo.ChdNum = 10.36960695;
  }
};
int main() {
  static ImpressStatistics s;
  cout << s.ShortVideo.Ctr << endl;
  cout << s.ShortVideo.Time << endl;
  cout << s.MiniVideo.Ctr << endl;
  cout << s.MiniVideo.Time << endl;
  s.MiniVideo.Time = 1000;
  cout << s.MiniVideo.Time << endl;
}
