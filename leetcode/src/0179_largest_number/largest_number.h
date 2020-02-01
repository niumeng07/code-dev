#include <iostream>
#include <vector>
#include <string>
using namespace std;

int high_num(int num) {
    while(num / 10) {
        num = num/10;
    }
    return num % 10;
}
int repartition(vector<int> &input, int left, int right) {
    int middle = right;
    int i = left, j = right - 1;
    while( i < j) {
        if( high_num(input[i]) > high_num(input[middle]) && high_num(input[j]) < high_num(input[middle])) {
            swap(input[i], input[j]);
            i++;
            j--;
        }
        else {
            if( high_num(input[i]) <= high_num(input[middle]))
                i++;
            if( high_num(input[j]) >= high_num(input[middle]))
                j--;
        }
    }
    if(high_num(input[j]) > high_num(input[middle]))
        swap(input[j], input[middle]);
    return i;
}
void qs_impl(vector<int> &input, int left, int right){
    if(left >= right)
        return;
    if(right > left + 1){
        int middle = repartition(input, left, right);
        qs_impl(input, left, middle);
        qs_impl(input, middle, right);
    } else if ( right == left + 1 && high_num(input[right]) < high_num(input[left])) {
        swap(input[left], input[right]);
    }
}
void quick_sort(vector<int> &input){
    qs_impl(input, 0, input.size() - 1);
}
class LargestNumber {
public:
    //是一个排序算法,按最按位排序,最高位相同按第位排序,依次...
    string largestNumber(vector<int>& nums) {
        string result = "";
        quick_sort(nums);
        for(int i = nums.size() - 1; i >=0; i--) {
            result = result + to_string(nums[i]);
        }
        return result;
    }
};
