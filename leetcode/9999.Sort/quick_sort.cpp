#include <vector>
#include <iostream>
using namespace std;

void quick_sort(vector<int>& input){
};
void print_vector(vector<int>& input){
    for (auto x : input)
        cout << x << "\t";
    cout << endl;
}
int main(){
    vector<int> nums({1,4,2,8,9,0,5,6,7,9,1,2,6});
    print_vector(nums);
    quick_sort(nums);
    print_vector(nums);
}
