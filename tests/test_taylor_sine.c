/*
 * Test file for Exercise 1 - Taylor Sine Function
 * Assignment 7 - IPFCE 2025
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../include/taylor_sine.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


int main() {
  int n = 15;
  double pi = 3.14;

  printf("sin(pi) = %f\n", sin(pi));

  double result = taylor_sine(pi, n);
  printf("sin(pi) = %f\n", result);

  return 0;

}

//
//Funktionen taylor_sine(x,n) blev testet. 
//Der blev testet med en fast x-værdi, hvor x=3,14, og en variende n-værdi. 
//Resultaterne blev sammenlignet med  den indbyggede sin⁡(x) funktion fra ANSI C math.h biblioteket.
//Testene viser, at Taylor-approksimationen er følsom over for antallet af n. 
//Ved en lav værdi af n (f.eks. n=4) så afviger resultatet markant fra den korrekte værdi, 
//som kan betyde, at Taylor-rækken ikke har konvergeret tilstrækkeligt endnu. 
//Allerede ved n=7 er der kommet en forbedring, da de to resultater kom tættere på hinanden end n=4 resultaterne. 
//Fra n=10 og opefter, så bliver Taylor-resultaterne identiske. 
//Så min taylor_sine() funktion afhænger af værdien af n, og den virker først når n=10 eller opefter. 
//