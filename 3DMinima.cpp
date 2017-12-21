/*****************************************************************
Name : 3D ��ĤG�̤p��
Date : 2017/11/13
By   : CharlotteHonG
Final: 2017/11/13
*****************************************************************/
#include <iostream>
using namespace std;

// �L�X�}�C
template<size_t N, size_t N2>
void priarr(int (&arr)[N][N2]) {
    for(unsigned j = 0; j < 3; ++j) {
        for(unsigned i = 0; i < 9; ++i) {
            cout << arr[j][i] << ", ";
        } cout << endl;
    }
};
// �Ѥp��j�Ƨ� a b c
void sort3(int& a, int& b, int& c) {
    if(a > b) {std::swap(a, b);}
    if(b > c) {std::swap(b, c);}
    if(a > b) {std::swap(a, b);}
};
//================================================================
int main(int argc, char const *argv[]) {
    int arr[][9] {
        {19, 20, 21, 22, 23, 24, 0, 26, 27},
        {10, 11, 12, 13, 14 ,2, 16, -1, 18},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}
    };

    // �Ĥ@���Ƨ�
    for(unsigned i = 0; i < 9; ++i) {
        sort3(arr[0][i], arr[1][i], arr[2][i]);
    } cout << endl;
    priarr(arr);
    // �ĤG���Ƨ�
    for(unsigned i = 0; i < 3; ++i) {
        sort3(arr[0][i*3+2], arr[0][i*3+1], arr[0][i*3+0]);
        sort3(arr[1][i*3+2], arr[1][i*3+1], arr[1][i*3+0]);
    } cout << endl;
    priarr(arr);
    // �ĤT���Ƨ�
    sort3(arr[0][1], arr[0][4], arr[0][7]);
    sort3(arr[0][2], arr[0][5], arr[0][8]);
    sort3(arr[1][2], arr[1][5], arr[1][8]);
    cout << endl;
    priarr(arr);
    // �ĥ|���Ƨ�
    sort3(arr[0][1], arr[0][5], arr[1][2]);
    cout << endl;
    priarr(arr);

    // ���G
    cout << "minima=" << arr[0][2] << endl;
    cout << "mini2=" << arr[0][1] << endl;
    return 0;
}
//================================================================
