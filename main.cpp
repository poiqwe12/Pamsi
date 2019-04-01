

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

    Data<int, rozmiar_0> *D = new Data<int, rozmiar_0>();
    Sortowanie2(*D);
    delete(D);
    Data<int, rozmiar_1> *E = new Data<int, rozmiar_1>();
    Sortowanie2(*E);
    delete(E);
    Data<int, rozmiar_2> *G = new Data<int, rozmiar_2>();
    Sortowanie2(*G);
    delete(G);
    Data<int, rozmiar_3> *H = new Data<int, rozmiar_3>();
    Sortowanie2(*H);
    delete(H);
  

    Data<int, rozmiar_4> *J = new Data<int, rozmiar_4>();
    ///Quick_Sort(*J);
    Sortowanie2(*J);
    delete(J);

    return 0;
}
