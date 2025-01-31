#include <iostream>
#include <cmath>
using namespace std;  

int main() {

int num1, num2;
cout<<"Enter the two numbers below "<<endl;
cout<<"Enter the 1st number: ";
cin>>num1;
cout<<"Enter the 2nd number: ";
cin>>num2;

char sign;
cout<<"Enter the operator sign: (+ for addition, - for subtraction, * for multiplication and / for division): ";
cin>>sign;

switch(sign) {
    case '+':
        cout<<"the result is "<< num1+num2;
        break;
    case '-':
        cout<<"the result is "<<num1-num2;
        break;
    case '*':
        cout<<"the result is "<<num1*num2;
        break;
    case '/':
    if (num2!=0) {
        cout<<"the result is "<<num1/num2;}
    else {
        cout<<"Division by zero is not possible";
    }

        break;
    default:
        cout<<"Invalid operator";
        break;
}   

return 0;
}
