#include <iostream>
using namespace std;
int main()
{ //Declaration of varibles
    int dollars;
    float B, M, J, P, I, C, CH, A, NZ, R, SA, AF;
    //input American dollars
    cout << "Enter currency in American Dollars" << endl;
    cin >> dollars;
    //Calculations
    B = dollars * 0.725132; // Britain
    M = dollars * 20.189723; // Mexico
    J = dollars * 114.240308; // Japan
    P = dollars * 175.119986; // Pakistan
    I = dollars * 74.976398;  // India
    C = dollars * 1.236800;  // Canada
    CH = dollars * 6.382810; // China
    A = dollars * 1.331580; // Australia
    NZ = dollars * 1.394376; // New Zealand
    R = dollars * 69.603531; // Russia
    SA = dollars * 3.750000; // Saudi Arabia
    AF = dollars * 14.827011; // South Africa

    cout << dollars << " American dollars are equal to " << B << " British pounds" << endl;
    cout << dollars << " American dollars are equal to " << M << " Mexican pesos" << endl;
    cout << dollars << " American dollars are equal to " << J << " Japanese yen" << endl;
    cout << dollars << " American dollars are equal to " << P << " Pakistani rupees" << endl;
    cout << dollars << " American dollars are equal to " << I << " Indian rupees" << endl;
    cout << dollars << " American dollars are equal to " << C << " Canadian Dollar" << endl;
    cout << dollars << " American dollars are equal to " << CH << " Chinese Yuan Renminbi" << endl;
    cout << dollars << " American dollars are equal to " << A << " Australian Dollar" << endl;
    cout << dollars << " American dollars are equal to " << NZ << " New Zealand Dollar" << endl;
    cout << dollars << " American dollars are equal to " << R << " Russian Ruble" << endl;
    cout << dollars << " American dollars are equal to " << SA << " Saudi Arabian Riyal" << endl;
    cout << dollars << " American dollars are equal to " << AF << " South African Rand" << endl;
    system("pause");
    return 0;
}