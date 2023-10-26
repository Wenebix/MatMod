#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long
long double eps = 1e-9;
bool kolmogorov_test(vector <long double>& seq) {
    int k = 1000;
    long double delta = 1.36;
    int sup = 0;
    int n = seq.size();
    for (int i = 0; i < k; i++) {
        int hits = 0;
        for (int j = 0; j < n; j++) {
            if (seq[j] <= (long double)j / (long double)k) {
                hits++;
            }
        }
        long double F = (long double)hits / n;
        if (sup < fabs(F - (long double)i / (long double)k)) sup = fabs(F - (long double)i / (long double)k);
    }
    return (delta - sqrt((long double)n) * sup) > eps;
}

bool pirson_test(vector <long double>& seq) {
    int k = 20;
    int n = seq.size();
    long double delta = 30.1;
    long double psi = 0;
    vector <long double> counting(k);
    for (int i = 0; i < n; i++) {
        int num = seq[i] * k;
        counting[num] ++;
    }
    for (int i = 0; i < k; i++) {
        long double tmp = n / k;
        psi += ((counting[i] - tmp) * (counting[i] - tmp)) / tmp;
    }
    return (delta - psi) > eps;
}

vector <long double> maclaren_marsaglia(int k, int n, vector <long double>& b, vector <long double>& c) {
    vector <long double> v(n + 1);
    vector <long double> a(n + 1);
    for (int t = 0; t < k; t++) {
        v[t] = b[t + 1];
    }
    for (int i = 0; i < n - k; i++) {
        int s = c[i] * k;
        a[i] = v[s];
        v[s] = b[i + k];
    }
    for (int i = n - k; i <= n; i++) {
        a[i] = b[i];
    }
    return a;
}

int32_t main() {
    int a0, b0;
    a0 = 848771989;
    long long m = (1LL << 31);
    b0 = max(m - 487906901LL, 487906901LL);
    int k = 96;
    int n = 1000;
    vector <long double> b;
    b.push_back((long double)a0 / (long double)m);
    for (int t = 1; t <= n; t++) {
        b.push_back((long double)((long long)(b[t - 1] * b0 * m) % m) / (long double)m);
    }
    vector <long double> e;
    int a1, b1;
    a1 = 358235167;
    b1 = max(35201247LL, m - 35201247LL);
    e.push_back((long double)a1 / (long double)m);
    for (int t = 1; t <= n; t++) {
        e.push_back((long double)((long long)(e[t - 1] * b1 * m) % m) / (long double)m);
    }



    vector <long double> answer = maclaren_marsaglia(k, n, b, e);
    //    cout << "KONGRU METHOD" << endl;
    //    for(int i = 1;i <= n;i++){
    //        cout << b[i] << " ";
    //    }
    //    cout << endl;
    cout << "MKM method !1, 15, 1000 ELEMENT - >\n" << b[1] << "\n" << b[15] << "\n" << b[1000] << endl;
    //    cout << "Maclaren Marsaglia method" << endl;
    //    for(int i = 1;i <= n;i++){
    //        cout << answer[i] << " ";
    //  }
    //    cout << endl;
    cout << "Maclaren Marsaglia method !1, 15, 1000 ELEMENT - >\n" << answer[1] << "\n" << answer[15] << "\n" << answer[1000] << endl;
    cout << "TEST PIRSONA FOR KONGRU METHOD - > " << pirson_test(b) << endl;
    cout << "TEST PIRSONA FOR Maclaren Marsaglia method - > " << pirson_test(answer) << endl;
    cout << "TEST KOLMOGOROVA FOR KONGRU METHOD - > " << kolmogorov_test(b) << endl;
    cout << "TEST KOLMOGOROVA FOR Maclaren Marsaglia method - > " << kolmogorov_test(answer) << endl;
}
