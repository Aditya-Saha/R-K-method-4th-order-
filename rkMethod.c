#include <stdio.h>

// Function prototypes
double f(double x, double y);
void rk4_method(double x0, double y0, double h, double xn);

int main() {
    // Example usage:
    double x0 = 0.0; // Initial value of x
    double y0 = 1.0; // Initial value of y
    double h = 0.1;  // Step size
    double xn = 1.0; // Final value of x for which y needs to be approximated

    rk4_method(x0, y0, h, xn);

    return 0;
}

// Define the differential equation function y' = f(x, y)
double f(double x, double y) {
    // Example differential equation: y' = x + y
    return x + y;
}

// RK4 method to approximate the solution of the differential equation
void rk4_method(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;

    printf("Approximated values using RK4 method:\n");

    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        // Update y using RK4 formula
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;

        // Move to the next point
        x = x + h;

        // Print the current point and the corresponding value of y
        printf("x = %.2lf, y = %.6lf\n", x, y);
    }
}
