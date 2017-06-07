/*****************************************************************
Name : 
Date : 2017/05/28
By   : CharlotteHonG
Final: 2017/05/28
*****************************************************************/
template<class T>
Num<T> Num<T>::operator+=(const Num& rhs) {
    this->num += rhs.num;
    return (*this);
}

template<class T2>
ostream& operator<<(ostream& os, const Num<T2>& rhs) {
    os << rhs.num;
    return os;
}
template<class T2>
istream& operator>>(istream& is, Num<T2>& rhs) {
    is >> rhs.num;
    return is;
}
// template<int>
Num<int> operator+(Num<int> const &lhs, Num<int> const &rhs) {
    return Num<int>(lhs) += rhs;
}

template<class T2>
bool operator!=(const Num<T2>& lhs, const Num<T2>& rhs){return !(lhs == rhs);}
template<class T2>
bool operator==(const Num<T2>& lhs, const Num<T2>& rhs){
    return lhs.num == rhs.num;
}

template<class T>
Num<T>::operator T&(){
    return this->num;
}