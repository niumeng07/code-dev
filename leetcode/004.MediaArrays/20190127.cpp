#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> left({1, 3, 4});
    vector<int> right({2});
    int ll = 0, lr = left.size() - 1;
    int rl = 0, rr = right.size() - 1;
    while(true) {
        if( ll >= lr && rl >= rr) break;
        else if (ll < lr) rl++ && rr--;
        else ll++ && lr--;
    }
    int _min = max(left[ll], right[rl]);
    int _max = min(left[lr], right[rr]);
    cout << _min << "\t" << _max << "\t" << (_min + _max)/2.0 << endl; 

    return 0;
}
