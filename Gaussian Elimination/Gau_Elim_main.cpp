/****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25

�������h
1. ���W�ơר̷Ӷ��h���Y��1�A�O�U���W�ƭ���n (��^n)
2. ���V���h�צ����Ĥ@�檺n��
3. �ϦV�a�J�צ������U�U�Ҧ������h�]�o�Ӷ��h�n���H�Y���Y�H�K������^
*****************************************************************/
#include <iostream>
#include "Gau_Elim.hpp"
#include "Gau_Elim.cpp"// gcc ���ɽsĶ
using namespace std;
using namespace gau;
/*==============================================================*/
int main(int argc, char const *argv[]){
    Gau_Elim a{
        {2, 3, -1, -2}, 
        {1, -1, 1, 8}, 
        {3, -2, -9, 9}
    };
    // ���V���h
    cout << "forward" << endl;
    for(unsigned i = 0; i < 3; ++i) 
        a.forward(i);
    // �ϦV�a�J
    cout << "reverse" << endl;
    for(unsigned i = 3; i > 0; --i) {
        a.reverse(i-1);
    }
    return 0;
}
/*==============================================================*/