#include <time.h>
#include <iostream>
using namespace std;

std::string getTimeStamp() {
    time_t rawtime;
    struct tm * timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    char hour[3];
    sprintf(hour, "%d", timeinfo->tm_hour);

    std::string hourStr = std::string(hour);
    if (hourStr.size() == 1) hourStr = "0" + hourStr;

    cout << hourStr << std::endl;
    return hourStr;
}

int main(int argc, char *argv[])
{
  getTimeStamp();
  return 0;
}
