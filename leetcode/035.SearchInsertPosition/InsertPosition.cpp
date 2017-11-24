#include <iostream>
#include <vector>
using namespace std;
int InsertPosition(vector<int> array, int target)
{
    if(target < array[0])
        return 0;
    if(target > array[array.size() - 1])
        return array.size();
    for(int i = 0; i < array.size(); i++)
    {
        if(target <= array[i])
            return i;
    }
}
int main()
{
    cout << InsertPosition({1,3,5,6}, 5) << endl;
    cout << InsertPosition({1,3,5,6}, 2) << endl;
    cout << InsertPosition({1,3,5,6}, 7) << endl;
    cout << InsertPosition({1,3,5,6}, 0) << endl;
    return 0;
}
