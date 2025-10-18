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