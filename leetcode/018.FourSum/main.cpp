#include "Solution.h"
#include <vector>
using namespace std;

int main()
{
    Solution su;
    vector<int> vec({1,2,3,-1,2,0,4});
    vector<vector<int> > result = su.findNSum(vec, 6, 3);
    /*
    for(auto vec : result)
    {
        for(auto x : vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    */
    vector<int> vec2({1, 0, -1, 0, -2, 2});
    vector<vector<int> > result2 = su.fourSum(vec2, 0);
    for( auto vec : result2 )
    {
        for( auto x : vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
    vector<int> vec3({-483,-476,-475,-460,-450,-431,-428,-419,-410,-374,-347,-345,-311,-303,-299,-286,-278,-271,-260,-257,-240,-227,-217,-203,-196,-191,-189,-179,-171,-151,-150,-144,-134,-130,-112,-107,-97,-96,-94,-70,-62,-54,-38,-38,-23,-12,-11,-2,2,4,30,33,38,51,51,54,69,90,108,111,112,112,121,129,163,182,184,194,198,199,210,228,229,232,236,237,249,249,259,282,303,312,317,329,329,342,349,368,375,380,384,393,420,433,441,446,460,474,497});
    vector<vector<int> > result3 = su.fourSum(vec3, 34);
    for( auto vec : result3 )
    {
        for( auto x : vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
    vector<int> vec4({-1,0,1,2,-1,-4});
    vector<vector<int> > result4 = su.fourSum(vec4,-1);
    for(auto vec : result4 )
    {
        for( auto x : vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
    vector<int> vec5({-493,-470,-464,-453,-451,-446,-445,-407,-406,-393,-328,-312,-307,-303,-259,-253,-252,-243,-221,-193,-126,-126,-122,-117,-106,-105,-101,-71,-20,-12,3,4,20,20,54,84,98,111,148,149,152,171,175,176,211,218,227,331,352,389,410,420,448,485});
    vector<vector<int> > result5 = su.fourSum(vec5, 1057);
    for(auto vec : result5 )
    {
        for( auto x : vec)
            cout << x << "\t" << ends;
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
    return 0;
}
