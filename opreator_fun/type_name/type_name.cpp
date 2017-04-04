/*****************************************************************
Name : 正確的顯示型態名稱
Date : 2017/04/04
By   : CharlotteHonG
Final: 2017/04/04

http://stackoverflow.com/questions/789402
*****************************************************************/
#include <iostream>
using namespace std;

#include <typeinfo>
#include <cxxabi.h>
class type_name{
public:
    template <class T>
    type_name(T const t): realname(
        abi::__cxa_demangle(typeid(T).name(), 0, 0, &status))
    {
        cout << realname << endl;
    }
    ~type_name(){
        free(realname);
    }
    int status;
    char *realname;
    #define type_name(i) type_name(move(i));
};
//================================================================
int main(int argc, char const *argv[]){
    type_name(1.0);
    type_name('a');
    type_name("a");

    void* i;
    type_name(i);

    class A{} a;
    type_name(a);

}
//================================================================