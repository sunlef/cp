#include <bits/stdc++.h>
using namespace std;

void solve(){
    auto squr = [] (const double &a) { return a*a; };
    auto print = [] (const double &a) { cout << fixed << setprecision(6) << a << '\n'; };
    const double PI = acos(-1.0);
    double ra, xa, ya, rb, xb, yb, a;
    cin >> ra >> xa >> ya >> rb >> xb >> yb >> a;
    
    double Ra = sqrt(squr(ra) - squr(a/2)) - a / 2;
    double Rb = sqrt(squr(rb) - squr(a/2)) - a / 2;
    double d = sqrt(squr(xa - xb) + squr(ya - yb));
    
    if(sqrt(2.0) * rb < a || d > Ra + Rb){
        print(0);
    } else if(Ra > Rb){
        if(d > Ra - Rb){
            double angle1 = acos((squr(d) + squr(Ra) - squr(Rb)) / (2 * Ra * d));
            double angle2 = acos((squr(d) + squr(Rb) - squr(Ra)) / (2 * Rb * d));
            double jS = angle1 * squr(Ra) + angle2 * squr(Rb) - Rb * d * sin(angle2);
            print(jS / (PI * squr(Ra)));
        } else{
            print(squr(Rb) / squr(Ra));
        }     
    } else{
        if(d > Rb - Ra){
            double angle1 = acos((squr(d) + squr(Ra) - squr(Rb)) / (2 * Ra * d));
            double angle2 = acos((squr(d) + squr(Rb) - squr(Ra)) / (2 * Rb * d));
            double jS = angle1 * squr(Ra) + angle2 * squr(Rb) - Ra * d * sin(angle1);;
            print(jS / (PI * squr(Ra)));
        } else {
            print(1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}