#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for an interval.
 */
class Interval {
public:
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    void print_self() { cout << start << "\t" << end << endl; }
};
void combine(vector<Interval>& intervals) {
    for (vector<Interval>::iterator iter = intervals.begin();
         iter != intervals.end() - 1;
         /**/) {
        vector<Interval>::iterator next = iter + 1;
        if ((*iter).end >= (*next).start) {
            if ((*iter).end < (*next).end) {
                (*iter).end = (*next).end;
                intervals.erase(next);
            } else
                intervals.erase(next);
        } else {
            iter++;
        }
    }
}
bool compare_intervals(Interval a, Interval b) {
    if (a.start <= b.start)
        return true;
    else
        return false;
}
class InsertInterval {
public:
    /*
     * 1. 对每个个intervals的元素item，判断newInterval与item的关系
     *    a. 若每一个item与newInterval无交集, 则把newInterval插入到intervals
     *    b. 若item完全覆盖newInterval, 则直接返回intervals
     *    c. 若item完全属于newInterval, 则用newInterval替代intervals中的item,
     * 并运行2合并 d. 若item与newInterval有条件的相交,则..
     * 2. 对每个item,若当前item的end大于下一个item的start，则合并
     *    erase当前item,下个item的start设为当前item的start
     * */
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // for( Interval item : intervals)
        for (int index = 0; index < intervals.size(); index++) {
            // b
            if (intervals[index].start <= newInterval.start &&
                intervals[index].end >= newInterval.end)
                return intervals;
            // c
            else if (intervals[index].start > newInterval.start &&
                     intervals[index].end < newInterval.end) {
                intervals[index].start = newInterval.start;
                intervals[index].end = newInterval.end;
                combine(intervals);
                return intervals;
            }
            // d
            else if (intervals[index].start < newInterval.start &&
                     intervals[index].end < newInterval.end &&
                     intervals[index].end > newInterval.start) {
                intervals[index].end = newInterval.end;
                combine(intervals);
                return intervals;
            } else if (intervals[index].start > newInterval.start &&
                       intervals[index].end > newInterval.end &&
                       newInterval.end > intervals[index].start) {
                intervals[index].start = newInterval.start;
                combine(intervals);
                return intervals;
            } else {
                continue;
            }
        }
        // a
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare_intervals);
        combine(intervals);
        return intervals;
    }
};
