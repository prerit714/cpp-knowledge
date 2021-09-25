#include <iostream>
using namespace std;
using ll = long long;

ll gcd_recr(ll a=0, ll b=0) {
/*
    To find gcd using euclidian algorithm: i.e.
        gcd(a, b) -> gcd(b, a%b) -> ... -> gcd(b, 0) = b;
*/
    if (b==0)
        return a;
    return gcd_recr(b, a%b);
}

ll gcd(ll a=0, ll b=0) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a=0, ll b=0) {
    return a/gcd(a, b)*b;
}

ll lcm_lambda(ll a, ll b) {
    auto gcd_lambda {
        [](ll a, ll b) ->ll {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        }
    };
    return a/gcd_lambda(a, b)*b;
}

int main() {
    cout << gcd_recr(48, 108) << endl;
    cout << gcd(48, 108) << endl;
    cout << lcm(48, 180) << endl;
    cout << lcm_lambda(48, 180) << endl;
    return 0;
}
