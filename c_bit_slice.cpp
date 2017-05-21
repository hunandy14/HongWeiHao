/*****************************************************************
Name : 
Date : 2017/05/07
By   : CharlotteHonG
Final: 2017/05/07
*****************************************************************/
#include <iostream>
#include <bitset>
using namespace std;

using uch = unsigned char;
union Bit{
    struct Bit_dev{
        uch:3;
        uch data:4;
        uch:1;
    } bit;
    uch raw;
};
//================================================================
int main(int argc, char const *argv[]){
    Bit a;
    a.raw=0xf0;
    cout << "a.data=" << (bitset<4>)a.bit.data << endl;
    cout << "a.raw=" << (bitset<8>)a.raw << endl;
    return 0;
}
//================================================================
