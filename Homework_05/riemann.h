//
// Created by patri on 04.12.2019.
//

#ifndef FUNCT_LIB_C_RIEMANN_H
#define FUNCT_LIB_C_RIEMANN_H
double differentiate(double (*f)(double x),double x,double h);
double integrate_left(double (*f)(double x), double a, double b, double h);
double integrate_midpoint(double (*f)(double x), double a, double b, double h);
#endif //FUNCT_LIB_C_RIEMANN_H
