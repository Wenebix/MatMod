#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

const long double PI = 3.14159265;
const long double eps = 1e-6;

vector <long double> ng;
vector <long double> lg;
vector <long double> vg;

std::random_device rd;
std::mt19937 e2(rd());
std::uniform_real_distribution<> dist(0, 1);

void NormalGenerator(long double m, long double s){
    for(int i = 0;i < ng.size();i++){
        long double a1 = dist(e2);
        long double a2 = dist(e2);
        long double item = sqrt(-2 * log(a1)) * sin(PI * 2 * a2);
        ng[i] = m + item * sqrt(s);
    }
}

void LaplaceGenerator(long double a){
    for(int i = 0;i < lg.size();i++){
        long double x = dist(e2);
        if(0.5 - x > eps){
            lg[i] = 1 / a * log(2 * x);
        }
        else{
            lg[i] = -1 / a * log(2 * (1. - x));
        }
    }
}

void VeibulaGenerator(long double a, long double b){
    for(int i = 0;i < vg.size();i++){
        long double x = dist(e2);
        vg[i] = pow((-1) / a * log(x), 1./b);
    }
}

void Print(int index_gen){
    if(index_gen == 1){
        cout << "Normal Generator - > " << endl;
        for(int i = 0;i < ng.size();i++) cout << ng[i] << " ";
        cout << endl;
    }
    if(index_gen == 2){
        cout << "Laplace Generator - > " << endl;
        for(int i = 0;i < lg.size();i++) cout << lg[i] << " ";
        cout << endl;
    }
    if(index_gen == 3){
        cout << "Veibula Generator - > " << endl;
        for(int i = 0;i < vg.size();i++) cout << vg[i] << " ";
        cout << endl;
    }
}

long double Mean(vector <long double> &a){
    long double sum = 0;
    for(int i = 0;i < a.size();i++){
        sum += a[i];
    }
    cout << "Mathematical Expectation - > " << sum / a.size() << endl;
    return sum / a.size();
}

void Despersion(vector <long double> & a, long double math){
    long double ans = 0;
    for(int i = 0;i < a.size();i++){
        ans += a[i] * a[i];
    }
    cout << "Despersion - > " << ans / a.size() - math * math << endl;
}



int main(){
    int n;
    cout << "Enter size " << endl;
    cin >> n;
    ng.resize(n);
    lg.resize(n);
    vg.resize(n);
    NormalGenerator(0, 1);
    LaplaceGenerator(0.5);
    VeibulaGenerator(1, 0.5);
    Print(1);
    Print(2);
    Print(3);
    long double ng1 = Mean(ng);
    long double lg1 = Mean(lg);
    long double vg1 = Mean(vg);
    Despersion(ng, ng1);
    Despersion(lg, lg1);
    Despersion(vg, vg1);

}
