

#include "dane.hh"
#include <iostream>

using namespace std;

int main()
{
    {
        const int Wymiar = 1000;
        int typ = 0;
        Data<int, Wymiar> *D = new Data<int, Wymiar>;

        for (int j = 0; j < 8; ++j)
        {
            std::ofstream plik("Heap_Sort.txt", std::ios_base::app);
            if (plik.good() == true)
            {
                plik << Wymiar << " elementow typ: " << j << std::endl;
                plik.close();
            }
            std::ofstream plik1("Merge_Sort.txt", std::ios_base::app);
            if (plik.good() == true)
            {
                plik1 << Wymiar << " elementow typ: " << j << std::endl;
                plik1.close();
            }
            D->Innit(j);
            for (int i = 0; i < 100; ++i)
            {
                cout << Heap_Sort(*D).Check_Sort() << endl;
                cout << Merge_Sort(*D).Check_Sort() << endl;
            }
        }
        delete (D);
    }

    const int Wymiar = 10000;
    Data<int, Wymiar> *D = new Data<int, Wymiar>;

    for (int j = 0; j < 8; ++j)
    {
        std::ofstream plik("Heap_Sort.txt", std::ios_base::app);
        if (plik.good() == true)
        {
            plik << Wymiar << " elementow typ: " << j << std::endl;
            plik.close();
        }
        for (int i = 0; i < 100; ++i)
        {
            D->Innit(j);
            cout << Heap_Sort(*D).Check_Sort() << endl;
        }
    }
    delete (D);

    return 0;
}
