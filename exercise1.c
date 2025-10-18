/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

// Her starter delopg a (header file):
 #ifndef TAYLOR_SINE_H //Hvis TAYLOR_SINE_H ikke allerede er defineret, så fortsæt
 #define TAYLOR_SINE_H //Definer TAYLOR_SINE_H: undgår dobbelt inkludering

 double taylor_sine(double x, int n); //deklarerer funktionen

 #endif //Afslutter #ifndef

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */

// Her starter delopg a (source file):
#include "taylor_sine.h"

 //Beregning af tælleren x^n:
 double power(double x, int n){

    double result = 1; //starter ved 1, da x^0 = 1

    for(int i = 0; i < n; i++){ //løkken bliver ved indtil vi når n gange
        result = result * x; // ganger x ind n gange
    }
    return result; //returnerer x^n
 }

//Beregning af nævner n!:
double factorial(int n){

    double result = 1; //starter med 1, da 0! = 1 --> 0! og 1! er allerede dækket her

    for(int i = 2; i <= n; i++){
        result = result * i; //ganger ind med i ved hvert trin --> stopper når i<=n
    }

    return result; //returnerer n!
}

//Beregning af sin(x) vha. Taylor-rækken
double taylor_sine(double x, int n) {
    double sum = 0;

    for(int i = 0; i < n; i++){
        int expo = 2 * i + 1; //Her sørger vi for at exponenten er ulige tal: 1,3,5...
        double numerator = power(x, expo); //beregner x^(2*i+1) altså tælleren som også er ulige
        double denominator = factorial(expo); //beregner (2*i+1)! altså nævneren som også er ulige
        double term = numerator / denominator; //udregning af hvert led i Taylor-rækken

        if(i % 2 == 0) //fortegnsskift
            sum = sum + term; //lægger til, hvis tallet er lige tal

        else
            sum = sum - term; //trækker fra, hvis tallet er ulige tal
        
    }
    
    return sum; //returnerer den samlede approx. af sin(x)
}


// 
//Funktionen taylor_sine(x,n) blev testet i ”test_taylor_sine.c” som ligger under mappen ”tests”.
//Der blev testet med en fast x-værdi, hvor x=3,14, og en variende n-værdi. 
//Resultaterne blev sammenlignet med  den indbyggede sin⁡(x) funktion fra ANSI C math.h biblioteket.
//Testene viser, at Taylor-approksimationen er følsom over for antallet af n. 
//Ved en lav værdi af n (f.eks. n=4) så afviger resultatet markant fra den korrekte værdi, 
//som kan betyde, at Taylor-rækken ikke har konvergeret tilstrækkeligt endnu. 
//Allerede ved n=7 er der kommet en forbedring, da de to resultater kom tættere på hinanden end n=4 resultaterne. 
//Fra n=10 og opefter, så bliver Taylor-resultaterne identiske. 
//Så min taylor_sine() funktion afhænger af værdien af n, og den virker først når n=10 eller opefter. 
//
