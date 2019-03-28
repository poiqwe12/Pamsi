

#include "dane.hh"
#include <iostream>

using namespace std;

int main()
{
    /*
    std::ofstream plik("Heap_Sort.txt");
            if (plik.good() == true)
            {
                plik.close();
            }
            */
    const int rozmiar_0 = 10000;
    const int rozmiar_1 = 50000;
    const int rozmiar_2 = 100000;
    const int rozmiar_3 = 500000;
    const int rozmiar_4 = 1000000;

      Data<int, rozmiar_2> *D = new Data<int, rozmiar_2>();
      Sortowanie(*D);
  //  delete (D);
   // D->Innit(0);
    //cout<<Shell_Sort(*D).Check_Sort()<<endl;
    return 0;
}
