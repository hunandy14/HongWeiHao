/*****************************************************************
Name : istream ¤Á³Î¦r¦ê
Date : 2017/05/22
By   : CharlotteHonG
Final: 2017/05/24
*****************************************************************/
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
    istringstream input("1 22 333 44 5");
    istream_iterator<int> begin(input), end;
    cout << accumulate(begin, end, 0) << endl;
    return 0;
}
