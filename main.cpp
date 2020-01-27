#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
unsigned long long int fibonacci_recursivo(int num)
{
    if (num < 2)

        return num;

    else

        return fibonacci_recursivo(num-2) + fibonacci_recursivo(num-1);
}

int main()
{
    int num = 30;
    auto start = high_resolution_clock::now();
    cout << "Para " << num << ", Fibonacci da " << fibonacci_recursivo(num) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo "<< duration.count()<< " microseconds" << endl;
    return 0;
}
//Para 30, Fibonacci da 832040
//Tiempo 6981 microseconds


#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
unsigned long long int fibonacci_iterativo(int num)
{
    long siguiente = 1, actual = 0, temporal = 0;
    for (long x = 1; x <= num; x++) {
        temporal = actual;
        actual = siguiente;
        siguiente = siguiente + temporal;
    }
    return actual;
}

int main()
{
    int num = 30;
    auto start = high_resolution_clock::now();
    cout << "Para " << num << ", Fibonacci da " << fibonacci_iterativo(num) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo "<< duration.count()<< " microseconds" << endl;
    return 0;
}

//Para 30, Fibonacci da 832040
//Tiempo 996 microseconds