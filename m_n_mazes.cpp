#include <bits/stdc++.h> //library to directly use cos and sin functions instead of computing them using taylor series
using namespace std;

// Computes log10 of the number of mazes 
long double log10NumMazes(int m, int n)
{
    long double logSum = 0.0L;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            long double term = (2 - 2 * cosl(M_PI * i / m)) + (2 - 2 * cosl(M_PI * j / n));
            logSum += log10l(term);
        }
    }
    logSum -= log10l(m * n);
    return logSum;
}

int main()
{
    int m = 42, n = 57; // change here for any grid size

    long double log10Value = log10NumMazes(m, n);
    long double exponentPart;
    long double mantissa = powl(10.0L, modfl(log10Value, &exponentPart));

    cout << fixed << setprecision(3);
    cout << m << " into " << n << " mazes = "
         << mantissa << "e" << (int)exponentPart << endl;

    return 0;
}
