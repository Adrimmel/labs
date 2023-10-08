#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double U(double x, double y) {
    return 4 * cos(pow(y, 1.0 / 3.0)) * sin(x * fabs(pow(y, 3) - 1.4));
}

int main() {
    double hx = 0.3;
    double hy = 0.4;
    double xn = 0.0;
    double xk = 2.0;
    double yn = 0.0;
    double yk = 1.0;

    double x, y;
    double minU = U(xn, yn);
    double min_x = xn;
    double min_y = yn;

    for (x = xn; x <= xk; x += hx) {
        for (y = yn; y <= yk; y += hy) {
            double currentU = U(x, y);
            if (currentU < minU) {
                minU = currentU;
                min_x = x;
                min_y = y;
            }
            printf("При x=%.2f, y=%.2f, U=%.2f\n", x, y, currentU);
        }
    }

    printf("\nМинимальное значение U: %.2f\n", minU);
    printf("Значения x и y, при которых достигается минимальное значение U: x=%.2f, y=%.2f\n", min_x, min_y);

    return 0;
}
