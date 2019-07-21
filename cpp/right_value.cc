#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>

uint64_t GetSecond() {
    struct    timeval tm;
    gettimeofday(&tm, NULL);
    return (tm.tv_sec * 1000000 + tm.tv_usec) / 100;
}

std::vector<int> CopyFun() {
    std::vector<int> a(8000*1000, 0);
    return a;
}

//std::vector<int> MoveFun(std::vector<int>* b) {
void PrintFun(const std::vector<int> v) {
    printf("v[0]: %d\n", v[0]);
}
//void PrintFunRight(std::vector<int>&& v) {
//    printf("v[0]: %d\n", v[0]);
//}

void CheckValue(std::vector<int>& v) {
    printf("lv: %d\n", v[0]);
}
//void CheckValue(std::vector<int>&& v) {
//    printf("rv: %d\n", v[0]);
//}

std::vector<int> ReturnFun() {
    uint64_t start_sec = GetSecond();
    std::vector<int> a(1000*1000, 1);
    uint64_t use_sec = GetSecond() - start_sec;
    printf("init vector a sec: %lu\n", use_sec);

    start_sec = GetSecond();
    std::vector<int> b(a);
    use_sec = GetSecond() - start_sec;
    printf("init vector b sec: %lu\n", use_sec);
    
    return a;
}




int main() {

    //std::vector<int> a(1000*1000, 1);
    
    std::vector<int> a(1000*1000, 1);
    std::vector<int> b(1000*1000, 1);
    uint64_t start_sec = GetSecond();
    //std::vector<int> b(a);
    //PrintFun(a);
    //std::vector<int> b = CopyFun();
    //std::vector<int> b = ReturnFun();
    //printf("b[0]: %d\n", b[0]);
    std::vector<std::vector<int>> v_s;
    //for (int i = 0; i < 50; ++i) {
    //    std::vector<int> a(1000*1000, 1);
    //    v_s.push_back(a);
    //}
    v_s.push_back(a);
    v_s.push_back(b);
    uint64_t use_sec = GetSecond() - start_sec;
    printf("copy use sec: %lu\n", use_sec);
    
    std::vector<int> a2(1000*1000, 1);
    std::vector<int> b2(1000*1000, 1);
    start_sec = GetSecond();
    //std::vector<int> c = a;
    //std::vector<int> c(std::move(a));
    //printf("c[0]: %d\n", c[0]);
    //std::vector<int> c = std::move(MoveFun());
    //PrintFunRight(std::move(a));
    //std::vector<int> right_a = ReturnFun();
    //std::vector<int> right_a(ReturnFun());
    //std::vector<int> right_a = 0 ? a: std::move(b);
    //std::vector<int>&& right_a = std::move(a);
    //printf("right_a:%d \n", right_a[0]);
    //printf("right_a:%d \n", right_a[0]);
    //printf("left_a:%d \n", a[0]);

    std::vector<std::vector<int>> v_s2;
    //for (int i = 0; i < 50; ++i) {
    //    std::vector<int> a2(1000*1000, 1);
    //    v_s2.push_back(std::move(a2));
    //}
    //v_s2.push_back(std::move(a2));
    //v_s2.push_back(std::move(b2));
    v_s2.emplace_back(a2);
    v_s2.emplace_back(b2);
    use_sec = GetSecond() - start_sec;
    printf("move use sec: %lu\n", use_sec);

    //printf("a:%d \n", a[0]);
    //CheckValue(ReturnFun());

    return 0;
}
