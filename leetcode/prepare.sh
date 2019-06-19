name=""
for i in $*
do
    name=${name}$i
done
mkdir $name

cp ./SConstruct CMakeLists.txt $name

echo "\
#include <iostream>
#include <vector>
using namespace std;
class Solution {
};" > $name/Solution.h

echo "\
#include \"Solution.h\"
#include <iostream>
using namespace std;

int main() {
    Solution su;
    return 0;
}" > $name/main.cpp

echo "" > $name/readme

