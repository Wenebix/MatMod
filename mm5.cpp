#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

using namespace std;

std::random_device xd;
std::mt19937 x2(xd());
std::uniform_real_distribution<> dist(0, 1.0);


int32_t main(){
     int n;
     long double x = 0, y = 0, z = 0;
     n = 3;
     vector<vector<long double>> a, p(n, vector <long double> (n, 0.3333));
     vector <long double> f, h(n), pi(n, 0.3333), i, Q, ksi;
     long double alpha;
     int N = 1000; // length of markov
     i.resize(N + 1); // markov
     Q.resize(N + 1); // weight of markov

     int m = 10000;
     ksi.resize(m);
     a = {{0.83682, 0.0627615, 0.209205}, {0.0627615, 0.970711, -0.0251046}, {0.209205, -0.0251046, 0.052301}};
     f = {{-0.857741}, {0.104603}, {3.82845}};
     h = {1, 0, 0};
     for(int j = 0;j < m;j++){
        alpha = dist(xd);
        if(alpha < 0.33){
                i[0] = 0;
            }
        else{
            if(alpha < 0.66) i[0] = 1;
            else i[0] = 2;
        }
        for(int k = 1;k <= N;k++){
            alpha = dist(xd);
            if(alpha < 0.33){
                i[k] = 0;
            }
            else{
                if(alpha < 0.66) i[k] = 1;
                else i[k] = 2;
            }
        }

        if(pi[i[0]] > 0) Q[0] = h[i[0]] / pi[i[0]];
        else Q[0] = 0;
        for(int k = 1;k <= N;k++){
            if(p[i[k - 1]][i[k]] > 0) Q[k] = Q[k - 1] * a[i[k - 1]][i[k]] / p[i[k - 1]][i[k]];
            else Q[k] = 0;
        }
        for(int k = 0;k <= N;k++) ksi[j] = ksi[j] + Q[k] * f[i[k]];
    }
    for(int k = 0;k < m;k++){
        x = x + ksi[k];
       // cout << ksi[k] << endl;
    }
    x = x / m;
    cout << fixed << setprecision(10) << x;
}

/*
3
-1 -3 5
*/
