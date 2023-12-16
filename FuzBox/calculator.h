#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;
void calculator(){
    int a, b;
    float sum;
    char op;
    cout << "Enter first number: \n";
    cin >> a;
    cout << "Enter second number: \n";
    cin >> b;
    cout << "Enter operator: \n";
    cin >> op;
    switch(op){
        case '+':
            sum = a+b;
            cout << sum << endl;
            break;
        case '-':
            sum = a-b;
            cout << sum << endl;
            break;
        case '*':
            sum = a*b;
            cout << sum << endl;
            break;
        case '/':
            sum = a/b;
            cout << sum << endl;
            break;
    }
}

#endif