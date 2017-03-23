/*****************************************************************
Name : operator=() 進階重載 具備多重語意
Date : 2017/03/21
By   : CharlotteHonG
Final: 2017/03/21
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cmath>
#include <typeinfo>
using namespace std;

class Raw {
public:
    Raw(size_t y, size_t x): col(x), img(y*x){
        iota(img.begin(), img.end(), 1);
    }
public: // 運算子
    // 重載下標符號
    int & operator[](size_t idx){
        return const_cast<int&>(static_cast<const Raw&>(*this)[idx]);
    }
    const int & operator[](size_t idx) const{
        return img[idx];
    }
    int & at2d(size_t y, size_t x){
        return const_cast<int&>(
            static_cast<const Raw&>(*this).at2d(y, x));
    }
    const int & at2d(size_t y, size_t x) const{
        return (*this)[y*col+x];
    }
public: // 基礎函式
    void info(){
        for(unsigned j = 0; j < img.size()/col; ++j) {
            for(unsigned i = 0; i < col; ++i) {
                cout << setw(3) << img[j*col+i];
            }cout << endl;
        }cout << endl;
    }
    void get_block(size_t h, size_t w);
private:// 資料成員
    size_t col;
    vector<int> img;
private:
    class Block;
    vector<Block> blk_p;
public:
    Block blk(size_t pos);
};


// 轉介的類別
class Raw::Block{
public:
    #define BlkSize 4 // 區塊大小
    Block(): p(BlkSize){}
    Block(Raw & img, size_t pos): p(BlkSize){
        size_t Sidelen = sqrt(BlkSize);
        // 取得對應位置
        size_t pos_y=((pos/((img.img.size())/img.col/Sidelen))*Sidelen);
        size_t pos_x=((pos%(img.col/Sidelen))*Sidelen);
        // 複製指標
        for(unsigned j=0, c=0; j < Sidelen; ++j)
            for(unsigned i = 0; i < Sidelen; ++i, ++c)
                p[c] = &img.at2d(pos_y+j, pos_x+i);
    }
    // 深層拷貝
    Block & operator=(Block const & rhs){
        cout << "C &" << endl;
        if (this == &rhs)
            return (*this);
        for (unsigned i = 0; i < p.size(); ++i)
            *(p[i]) = *(rhs.p[i]);
        return (*this);
    }
    // 淺層拷貝
    Block & copy(Block const & rhs){
        if (this == &rhs){
            return (*this);
        } else {
            p = rhs.p;
        } return (*this);
    }
    Block & copy(Block && rhs){
        if (this == &rhs){
            return (*this);
        } else {
            p = std::move(rhs.p);
        } return (*this);
    }
    void info(){
        for(auto&& i : p) {
            cout << setw(3) << *i ;
        }cout << endl;
    }
public:
    vector<int*> p;
};
auto Raw::blk(size_t pos)-> Block{
    return Block((*this), pos);
}

void Raw::get_block(size_t h=2, size_t w=2){
    size_t len = (img.size()/col/h) * (col/w);
    // cout << "len=" << len << endl;
    this->blk_p.resize(len);
    // blk_p 預載 len 個區塊
    for (unsigned i = 0; i < len; ++i){
        this->blk_p[i].copy( Block((*this), i) );
        // this->blk_p[i].info();
    }
}

/*==============================================================*/
int main(int argc, char const *argv[]){
    Raw a(4, 4);
    a.info();
    // 一般等號賦值
    a[0] = -1;
    a.at2d(0, 1) = -1;
    a.info();
    // 區塊等號賦值
    a.blk(2) = a.blk(3);
    a.info();
    // 不影響原本的等號
    Raw b(4, 4);
    a=b;
    a.info();
    return 0;
}
/*==============================================================*/