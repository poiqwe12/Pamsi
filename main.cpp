

#include "dane.hh"
#include <iostream>


using namespace std;


#define ROZMIAR 1000000
int main()
{
    for(int i = 0;i<3;i++)
    {
    Data<int,ROZMIAR> *D=new Data<int,ROZMIAR>(i);
    //cout<<*D<<endl;
    //Marge(D,10,100);
    Data<int,ROZMIAR> *Sorted_Data=new Data<int,ROZMIAR>(0);
    *Sorted_Data=Merge_Sort(*D);
    cout<<"Succes?  "<<Sorted_Data->Check_Sort()<< endl;
   //cout<<*Sorted_Data;
    }
    //Sorted_Data= Insertion_Sort(D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<<endl;
    //cout<< Sorted_Data;
    return 0;
}
