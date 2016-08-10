
#include <iostream>

using namespace std;

const int N = 100010;
int lf[N]; // Lowest prime factor

void sieve( void ) {
    for(int i = 2; i < N; i += 2)
        lf[i] = 2;

    for(int i = 3; i < N; i += 2)
        if(lf[i] == 0) {
            lf[i] = i;
            for(int j = i + i; j < N; j += i) {
                if(lf[j] == 0)
                    lf[j] = i;
            }
        }
}

void factorize( int n ) {
    while(n > 1) {
        cout << lf[n] << " ";
        n /= lf[n];
    }
    cout << endl;
}

int main( void ) {
    
    sieve();
    for(int i = 1; i <= 100; i++)
        factorize(i);

    return 0;
}
