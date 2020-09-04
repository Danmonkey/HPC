// HPCProg1.cpp : Program 1 for High-Performance Computing, a DIS with Dr. Asai Asaithambi
// by James Daniel O'Conner, N01058671
// Purpose: 10 iterations of the Gauss-Jacobi method for iterative linear systems of equations.

#include <iostream>
using namespace std;


class Matrix {
    int width, height;
    double* body;
    double* keys;
public:
    Matrix(int rows, int cols) {
        width = cols;
        height = rows;
        body = new double[width * height];
        keys = new double[height];
    }
    double get_value(int rows, int cols) {
        return body[cols + rows * width];
    }
    void set_value(int rows, int cols, double val) {
        body[cols + rows * width] = val;
    }
    //prints the contents of the Matrix object in order.
    void print_me() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << body[j + i * width] << " ";
            }
            cout << endl;
        }
    }
    //Solves the matrix for xn = 1.
    void solve() {
        for (int i = 0; i < height; i++) {
            double solver = body[(i * width) + i];
            if (solver == 0) {
                cout << "can't solve for 0. Leaving line untouched." << endl;
                continue;
            }
            for (int j = 0; j < width; j++) {
                body[j + i * width] = body[j + i * width] / solver;
            }
            keys[i] = body[(i * width) + i];
        }
    }
    //prints the solved-for (xn) keys
    void print_keys() {
        for (int i = 0; i < height; i++) {
            cout << "x" << i + 1 << ":" << keys[i] << endl;
        }
    }
    //Performs the Gauss-Jacobi method on the matrix. 
    void Gauss_Jacobi() {
        for (int i = 0; i < height; i++) {
            double sum = 0;
            for (int j = 0; j < width; j++) {
                if ((j + i * width) != ((i * width) + i)) {
                    if ((j + i * width) == (((i + 1) * width))-1) {
                        sum +=body[j+i*width];
                    }
                    else {
                        sum -= body[j + i * width];
                    }
                }
            }
            keys[i] = sum;
        }
        for (int i = 0; i < width-1; i++) {
            for (int j = i; j < width * height; j += width) {
                if (j != (i * width) + 1&&j!=0) {
                    body[j] *= keys[i];
                }
            }
        }
    }
};


int main()
{
    int n, m = 0;
    cout << "Please input the number of rows in the matrix" << endl;
    cin >> n;
    cout << "Please input the number of columns the matrix (it is suggested that this be the number of rows + 1)" << endl;
    cin >> m;
    Matrix Matt(n, m);
    cout << "Please input each element of the matrix row-major (it is suggested that values not be 0 initially.)" << endl;
    //set the initial values of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double val;
            cin >> val;
            Matt.set_value(i, j, val);
            cout << "Set " << i+1 << " " << j+1 << " to " << val << endl;
        }
    }
    Matt.print_me();
    cout << "Solving for values..." << endl;
    Matt.solve(); // standardizes matrix such that each row is solved for its key value. I.E. the primary diagonal row should be expressed as 1x(subnm)
    Matt.print_me(); //we initially assume that each value is simply equal to 1.
    Matt.print_keys();
    for (int i = 0; i < 10; i++) {
        cout << "Iteration: " << i + 1 << endl;
        Matt.Gauss_Jacobi();
        Matt.print_me();
        Matt.print_keys();
    } // Professor asks for 10 iterations initially... it is posssible to bound the calculation based on difference between previous values with a bit of extra work.
    return 0;
}