// HPCProg1.cpp : Program 1 for High-Performance Computing, a DIS with Dr. Asai Asaithambi
// by James Daniel O'Conner, N01058671
// Purpose: 10 iterations of the Gauss-Jacobi method for iterative linear systems of equations.

#include <iostream>
#include <future>
using namespace std;


class Matrix {
    int width, height;
    double* body;
public:
    Matrix(int rows, int cols) {
        width = cols;
        height = rows;
        body = new double[width*height];
    }
    double get_value(int rows, int cols) {
        return body[cols + rows * width];
    }
    void set_value(int rows, int cols, double val) {
        body[cols + rows * width] = val;
    }
    void print_me() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << body[j + i * width] << " ";
            }
            cout << endl;
        }
    }
    void solve() {
        int offset = 0;
        for (int i = 0; i < height; i++) {
            double solver = body[i * width +offset];
            if (solver == 0) {
                cout << "can't solve for 0." << endl;
                continue;
            }
            for (int j = 0; j < width; j++){
                body[j + i * width] = body[j + i * width] / solver;
            }
            offset++;
        }
    }
};


int main()
{
    int n, m;
    cout << "Please input the number of rows in the matrix" << endl;
    cin >> n;
    cout << "Please input the number of columns the matrix (it is suggested that this be the number of rows + 1)" << endl;
    cin >> m;
    Matrix Matt(n, m);
    cout << "Please input each element of the matrix row-major" << endl;
    //set the initial values of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double val;
            cin >> val;
            Matt.set_value(i, j, val);
            cout << "Set " << j+1 << " " << i+1 << " to " << val << endl;
        }
    }
    Matt.print_me();
    cout << "Solving for values..." << endl;
    Matt.solve(); // standardizes matrix such that each row is solved for its key value. I.E. the primary diagonal row should be expressed as 1x(subnm)
    Matt.print_me();
}