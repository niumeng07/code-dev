#include <iostream>
using namespace std;
int diff(string a, string b)
{
    int pos = a.find_first_of(":");
    int minutes_a = stoi(a.substr(pos + 1, a.size() - pos).c_str()) + 60 * stoi(a.substr(0, pos).c_str());
    pos = b.find_first_of(":");
    int minutes_b = stoi(b.substr(pos + 1, b.size() - pos).c_str()) + 60 * stoi(b.substr(0, pos).c_str());
    if( minutes_b > minutes_a )
        return minutes_b - minutes_a;
    return 24 * 60 - minutes_a + minutes_b;
}
int main()
{
    cout << diff("23:59", "00:00") << endl;
    cout << diff("00:00", "10:10") << endl;
    return 0;
}
