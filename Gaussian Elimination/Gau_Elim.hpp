/*****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#ifndef GAU_ELIM_HPP
#define GAU_ELIM_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <initializer_list>

using namespace std;
#define priw 6

namespace gau {
class Gau_Elim{
public:
    Gau_Elim(initializer_list<vector<double>> arr): matrix{arr} {}
    Gau_Elim(vector<vector<double>> arr): matrix{arr} {}
    void forward(size_t n);
    void reverse(size_t n);
    void info();
private:
    void nlz(size_t n);
    void sub(size_t a, size_t b, int idx=-1);
    size_t high(size_t n)
    void zoom(size_t n, double in=1, double out=1);
private:
    vector<vector<double>> matrix;
};
} // gau

#endif
