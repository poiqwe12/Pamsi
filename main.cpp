

#include "dane.hh"
#include <iostream>

using namespace std;

int main()
{

    const int rozmiar_0 = 10000;
    const int rozmiar_1 = 50000;
    const int rozmiar_2 = 100000;
    const int rozmiar_3 = 500000;
    const int rozmiar_4 = 1000000;
    
    Data<int, rozmiar_0> *A = new Data<int, rozmiar_0>();
    Sortowanie2(*A);
    delete (A);
    Data<int, rozmiar_1> *B = new Data<int, rozmiar_1>();
    Sortowanie2(*B);
    delete (B);
    Data<int, rozmiar_2>*C = new Data<int, rozmiar_2>();
    Sortowanie2(*C);
    delete(C);
    Data<int, rozmiar_3> *H = new Data<int, rozmiar_3>();
    Sortowanie2(*H);
    delete (H);
    Data<int, rozmiar_4> *J = new Data<int, rozmiar_4>();
    Sortowanie2(*J);
    delete (J);

    return 0;
}