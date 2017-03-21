/*****************************************************************
Name : 
Date : 2016/11/03
By   : CharlotteHonG
Final: 2016/11/03

�Q�κX�Цs���F�쭫��[][]�ĪG�A���L���ܦh�ʳ�
- Ū���⦸[]�A�ĤG���|�⦨[][]
- [][]��[]�������ȡA�]���L��^�ۤv���Ѧ�
- �a�}�Q���� �����ϥη|�^�Ǭ��������� �Aaddressof() ���o�u��a�}
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <memory>
using namespace std;
typedef unsigned char uch;
typedef unsigned int unt;

class raw{
public:
    // �غc
    raw(int y, int x): y(y),x(x), img(x*y){
        iota(img.begin(), img.end(), 1);
    }
    // �L�X
    void info(string name="Title"){
        cout << name << endl;
        // �L�X����
        for (unsigned j = 0; j < this->y; ++j){
            for (unsigned i = 0; i < this->x; ++i){
                cout << setw(3);
                cout << (int)img[(j*this->x)+i] << "";
            } cout << endl;
        } cout << endl;
    }
    // �G��Ū��
    uch & at2d(int y, int x){
        int pos = (y*this->y)+x;
        return this->img[pos];
    }
    const uch & at2d(int y, int x) const{
        int pos = (y*this->y)+x;
        return this->img[pos];
    }
    // ����
    operator uch&(){
        return this->img[this->idx];
    }
    raw & operator[](const size_t __n){
        if(this->flag==0) {
            // cout << "***1" << endl;
            this->flag = 1;
            this->idx = __n;
        }else{
            // cout << "***2" << endl;
            this->flag = 0;
            this->idx = (this->y*this->idx)+__n;
        }
        return (*this);
    }
private:
    unt y, x;
    vector<uch> img;
    int flag = 0;
    size_t idx = 0;
};
/*=======================================================*/
int main(int argc, char const *argv[]){
    raw a(3, 3);
    a.info("a");

    cout << "a[1][1] = " << (int)a[1][1] << endl;
    cout << "a[1]    = " << (int)a[1] << endl;

    return 0;
}
/*=======================================================*/