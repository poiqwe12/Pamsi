

#include "dane.hh"
#include <iostream>


using namespace std;


#define ROZMIAR 1000000
int main()
{
    Data<int,ROZMIAR> D(0);
    cout<<D<<endl;
    //Data<int,ROZMIAR> Sorted_Data=Bumble_Sort(D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<< endl;
    //cout<<Sorted_Data;
    //Sorted_Data= Insertion_Sort(D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<<endl;
    //cout<< Sorted_Data;
    return 0;
}
