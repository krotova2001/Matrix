#include <iostream>
#include "Matrix.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    Matrix<int> A;
    Matrix<int> B(5);
    Matrix<int> C(6,2);
   
    C.Init_random();

    C.Show();
    //C.Init_manual();
    cout << "max is "<<C.Show_min();
    cout << "-------------------------";

    Matrix<double> P(4), P1(4);  
    P.Init_random();  P1.Init_random();
    P.Show();  P1.Show();
    
    P + P1;
    P.Show();
    P - P1;
    P.Show();
    P * P1;
    P.Show();
    P / P1;
    P.Show();



}

