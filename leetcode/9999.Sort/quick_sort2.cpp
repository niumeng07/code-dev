#include <vector>
#include <iostream>
using namespace std;

void print_vector(vector<int> &input){
    for(auto x : input)
        cout << x << "\t";
    cout << endl;
    return;
}
int repartition(vector<int> &input, int left, int right) {
    int middle = right;
    int i = left, j = right - 1;
    while( i < j) {
        if( input[i] > input[middle] && input[j] < input[middle]) {
            swap(input[i], input[j]);
            i++;
            j--;
        }
        else {
            if( input[i] <= input[middle])
                i++;
            if( input[j] >= input[middle])
                j--;
        }
    }
    if(input[j] > input[middle])
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
    } else if ( right == left + 1 && input[right] < input[left]) {
        swap(input[left], input[right]);
    }
}
void quick_sort(vector<int> &input){
    qs_impl(input, 0, input.size() - 1);
}
int main(){
    vector<int> input({3,1,5,2,9,0});
    cout << "before qs: ";
    print_vector(input);
    quick_sort(input);
    cout << "after qs:  ";
    print_vector(input);
}
