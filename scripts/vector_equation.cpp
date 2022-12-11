#include <iostream>
#include <cmath>

using namespace std;


double* gauss(double** matrix,  int n)
{
    double* sec = new double [n];

    for (int i = 0; i < n; i++)
    {
        double tmp = matrix[i][i];
        for (int j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (int k = n; k >= i; k--)
                matrix[j][k] -= tmp*matrix[i][k];
        }
    }

    sec[n - 1] = matrix[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        sec[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
            sec[i] -= matrix[i][j] * sec[j];
    }

    return sec;
}


int main() {

    int n, m;
    cout << "Dim Matrix: ";
    cin >> n;
    m = n;

    double **matrix = new double *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n + 1];


    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)
        {
            cout << ">> Element " << "[" << i << " , " << j << "]: ";
            cin >> matrix[i][j];
        }
    for (int j = 0; j < n; j++)
    {
        cout << ">> Vector " << "[ " << j << " ]: ";
        cin >> matrix[j][n];
    }

    double* result = new double [n];
    result = gauss(matrix, n);

    cout << "\nResult vector:\n";
    for (int i = 0; i < n; i++)
        cout << ">> Vector " << "[ " << i << " ]: " << result[i] << "\n";
    cout << endl;

    delete[] matrix;
    delete[] result;

    return 0;
}
