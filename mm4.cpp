#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

long double real_answer_task1 = 8.50656;
long double real_answer_task2 = -1; // cant calculate;

long double task1(int size){
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(3., 3.5);
    long double l = 3.;
    long double r = 3.5;
    long double sum = 0;
    for(int i = 0;i < size;i++){
        long double x = dist(e2);
        sum += pow(x, x) * (1 + log(x)) * tan(x);
    }
    return sum / size * (r - l);
}

long double task2(int size){
    std::random_device xd;
    std::mt19937 x2(xd());
    std::uniform_real_distribution<> dist1(-2., 2.0);
    long double sum = 0;
    for(int i = 0;i < size;i++){
        long double x = dist1(x2);
        std::random_device yd;
        std::mt19937 y2(yd());
        std::uniform_real_distribution<> dist2(x * x, 4);
        long double y = dist2(y2);
        sum += sqrt(y + sin(x) * sin(x)) / (exp(-x * y));
    }
    return sum / size  * 8 / size;
}


int main(){
    cout << task1(1000) << endl;
    cout << task2(1000);
    return 0;
}
