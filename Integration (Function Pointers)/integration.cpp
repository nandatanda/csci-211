#include <iostream>
using namespace std;


typedef double (*FUNC)(double);

double line(double x);
double square(double x);
double cube(double x);
double integrate(FUNC f, double a, double b);


int main() {
    cout << "The integral of f(x) = x between 1 and 5 is: \t" << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x) = x^2 between 1 and 5 is: \t" << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x) = x^3 between 1 and 5 is: \t" << integrate(cube, 1, 5) << endl; 
}

double integrate(FUNC f, double a, double b) {
    double sum = 0;
    double dx = 0.0001;
    while (a < b) {
        sum += f(a) * dx;
        a += dx;
    }
    return sum;
}

double line(double x) {
    return x;
}

double square(double x) {
    return x * x;
}

double cube(double x) {
    return x * x * x;
}