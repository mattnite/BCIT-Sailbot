// Complex class testing

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

// normal of a complex number
template <typename T>
complex<T> normal(complex<T> a);

// dot product
template <typename T>
T dot(complex<T> a, complex<T> b);

// Projection
template <typename T>
complex<T> project(complex<T> a, complex<T> b);

int main (void)
{
    complex<float> s(1,0);
    complex<float> w(1, 1);

    cout << normal(w)  << endl;

}


// normal of a complex number
template <typename T>
complex<T> normal(complex<T> a)
{
    complex<T> b(real(a)/abs(a), imag(a)/abs(a));
    return b;
};

// dot product
template <typename T>
T dot(complex<T> a, complex<T> b)
{
    return (real(a)*real(b)) + (imag(a)*imag(b));
};

// Projection
template <typename T>
complex<T> project(complex<T> a, complex<T> b)
{
    
};
