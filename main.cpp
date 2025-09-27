#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>

double **A, **B, **C;

int main(int argc, char* argv[])
{
    long long N = 2000;

    A = new double*[N];
    B = new double*[N];
    C = new double*[N];

    srand(42);

    for (int i = 0; i < N; i++)
    {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
        for (int j=0; j<N; j++)
        {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            double total = 0;
            for (int k = 0; k < N; k++)
                total += A[i][k] *B[k][j];
            C[i][j] = total;
        }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    printf("%f seconds\n", duration.count());

    return 0;
}
