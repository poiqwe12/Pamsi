

#include "dane.hh"
#include <iostream>


using namespace std;


#define ROZMIAR 10
int main()
{
    for(int i = 0;i<3;i++)
    {
    Data<int,ROZMIAR> *D=new Data<int,ROZMIAR>(i);
    cout<<"Nieposrtowane dane: "<<*D<<endl;
    //Marge(D,10,100);
    Data<int,ROZMIAR> Sorted_Data=Heap_Sort(*D);
    cout<<"Succes?  "<<Sorted_Data.Check_Sort()<< endl;
   cout<<"Niby posortowane    "<<Sorted_Data<<endl<<endl;
    }
    //Sorted_Data= Insertion_Sort(D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<<endl;
    //cout<< Sorted_Data;
    return 0;
}
