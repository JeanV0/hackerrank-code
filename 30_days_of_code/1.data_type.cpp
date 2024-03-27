#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int a;
    double b;
    string c;

    cin >> a;
    cin >> b;

    cin.get();

    getline(cin,c);

    cout << a+i << endl;
    printf("%.1lf\n", d + b);
    cout << s << c;
    return 0;
}