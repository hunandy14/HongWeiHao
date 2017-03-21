/*****************************************************************
Name : 
Date : 2017/03/18
By   : CharlotteHonG(整理)
Final: 2017/03/18

原文：https://www.ptt.cc/bbs/C_and_CPP/M.1478167551.A.5ED.html
原始代碼：http://ideone.com/Tm4Bgk
*****************************************************************/
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


template<class T>
class Middle {
public:
    using size_type=typename vector<T>::size_type;
public:
    // 建構子
    Middle(vector<T> &vec, const size_type column, 
        const size_type index) noexcept
        :vec_{addressof(vec)}, column_{column}, index_{index}{}
    // 複製建構子
    Middle(const Middle &) = default;
public:
    // 取址函式
    operator T&(){
        return (*vec_)[index_];
    }
    // 複製函式
    Middle& operator=(const Middle &) = delete;
    void operator=(T const & data){
        (*vec_)[index_] = move(data);
    }
    // 重載下標
    T& operator[](const size_t i){
        return (*vec_)[index_*column_+i];
    }
private:
    vector<T> *vec_;
    const size_type column_;
    const size_type index_;
};


template<class T>
class Const_Middle {
public:
    using size_type=typename vector<T>::size_type;
public:
    // 建構子
    Const_Middle(const vector<T> &vec, const size_type column, 
        const size_type index) noexcept
        :vec_{addressof(vec)}, column_{column}, index_{index}{}
    // 複製建構子
    Const_Middle(const Const_Middle &) = default;
public:
    // 取址存取
    operator const T&(){
        return (*vec_)[index_];
    }
    // 複製函式
    Const_Middle& operator=(const Const_Middle &) = delete;
    // 重載下標
    const T& operator[](const size_t i){
        return (*vec_)[index_*column_+i];
    }
private:
    const vector<T> *vec_;
    const size_type column_;
    const size_type index_;
};


template<class T>
class Test {
public:
    using size_type=typename vector<T>::size_type;
public:
    // 建構子
    Test(const size_type row,const size_type column)
        :vec_(row*column), column_{column}{}
    Test const& pri() const{
        for(unsigned j = 0; j < vec_.size()/column_; ++j) {
            for(unsigned i = 0; i < column_; ++i) {
                cout << vec_[j*column_ + i] << ", ";
            } cout << endl;
        } cout << endl;
        return (*this);
    }
public:
    // 重載下標
    Middle<T> operator[](const size_t i){
        return Middle<T>{vec_,column_,i};
    }
    Const_Middle<T> operator[](const size_t i) const{
        return Const_Middle<T>{vec_,column_,i};
    }
public:
    vector<T> vec_;
private:
    const size_type column_;
};


int main(int argc, char const *argv[]){
    // 初始化
    Test<int> test(3, 4);
    iota(begin(test.vec_), end(test.vec_), 0);
    const Test<int> & test2 = test;
    // 測試
    test.pri();
    test[0][0] = 7;
    test[1] = 7;
    test.pri();
    test2.pri();
}