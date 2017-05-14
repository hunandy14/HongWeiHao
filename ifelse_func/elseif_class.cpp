/*****************************************************************
Name :
Date : 2017/05/15
By   :
Final: 2017/05/15

http://ideone.com/hEqekN
https://www.ptt.cc/bbs/C_and_CPP/M.1363233380.A.9EA.html
*****************************************************************/
#include <iostream>
#include <functional>
using namespace std;

#define CALL_TILL_FALIURE sequence_call_till_failure()

class sequence_call_till_failure {
public:
    sequence_call_till_failure() : success(false) { }
    template<typename Func, typename... Args>
    sequence_call_till_failure &
    operator()(Func func, Args... args) {
        if(!success){
            success = success || func(std::forward<Args>(args)...);
        } return *this;
    }
    operator bool() const {
        return success;
    }
private:
    bool success;
};

bool PlanA() { std::cout << __FUNCTION__ << std::endl; return false; }
bool PlanB() { std::cout << __FUNCTION__ << std::endl; return false; }
bool PlanC() { std::cout << __FUNCTION__ << std::endl; return false; }
bool is_odd(int value) { std::cout << __FUNCTION__ << std::endl; return value % 2 == 1; }
int add(int lhs, int rhs) { std::cout << __FUNCTION__ << std::endl; return lhs + rhs; }
bool Error() { std::cout << __FUNCTION__ << std::endl; return false; }

int main() {
    bool result = CALL_TILL_FALIURE
        (PlanA)(PlanB)(PlanC)(is_odd, 2)(add, 0, 0)(Error);
    cout << result << endl;
}