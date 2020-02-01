#include "gtest/gtest.h"
#include "0057_insert_interval/insert_interval.h"
#include <iostream>
#include <time.h>

using namespace std;
int main(int argc, char **argv)
{
    InsertInterval su;
    vector<Interval> intervals;
    /*
    Interval i1(1,3);
    intervals.push_back(i1);
    Interval i2(6,9);
    intervals.push_back(i2);
    Interval ix(2,5);
    */
    Interval i1(1,2);
    intervals.push_back(i1);
    Interval i2(3,5);
    intervals.push_back(i2);
    Interval i3(6,7);
    intervals.push_back(i3);
    Interval i4(8,10);
    intervals.push_back(i4);
    Interval i5(12,16);
    intervals.push_back(i5);
    Interval ix(4,9);
    /*
    Interval i1(1,5);
    intervals.push_back(i1);
    Interval ix(5,9);
    */
    /*
    Interval i1(1,5);
    intervals.push_back(i1);
    Interval ix(0,1);
    */
    cout << intervals.size() << endl;
    for(auto inter : intervals)
        inter.print_self();
    clock_t start, end;
    start = clock();
    vector<Interval> result = su.insert(intervals, ix);
    end = clock();
    cout << "time: " << (end - start)/1000.0 << " ms" << endl;
    for(auto inter : result)
        inter.print_self();
    return 0;
}
