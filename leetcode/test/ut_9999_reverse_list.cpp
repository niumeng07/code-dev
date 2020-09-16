#include <iostream>
#include <vector>

#include "9999_reverse_list/reverse_list.h"
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    vector<int> input({1, 2, 3, 4, 5, 6});
    Node *head = BuildList(input);
    PrintList(head);
    Node *r = ReverseList(head);
    PrintList(r);
}
