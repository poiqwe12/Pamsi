

#include "dane.hh"
#include <iostream>


using namespace std;


#define ROZMIAR 1000
int main()
{
    /*
    for(int i = 0;i<3;i++)
    {
    Data<int,ROZMIAR> *D=new Data<int,ROZMIAR>(i);
    cout<<"Nieposrtowane dane: "<<*D<<endl;
    //Marge(D,10,100);
    Data<int,ROZMIAR> Sorted_Data=Heap_Sort(*D);
    cout<<"Succes?  "<<Sorted_Data.Check_Sort()<< endl;
   cout<<"Niby posortowane    "<<Sorted_Data<<endl<<endl;
   delete(D);
    }
    cout<<"-----Sortowanie Scalanie-------"<<endl;
    for(int i = 0;i<3;i++)
    {
    Data<int,ROZMIAR> *D=new Data<int,ROZMIAR>(i);
    cout<<"Nieposrtowane dane: "<<*D<<endl;
    //Marge(D,10,100);
    Data<int,ROZMIAR> Sorted_Data=Merge_Sort(*D);
    cout<<"Succes?  "<<Sorted_Data.Check_Sort()<< endl;
   cout<<"Niby posortowane    "<<Sorted_Data<<endl<<endl;
   delete(D);
    }
    */
    cout<<"++++++++++++++++++++++++++++++++++++++"<<endl;
    Data<int,ROZMIAR> *D=new Data<int,ROZMIAR>(0);
    cout<<"Nieposrtowane dane: "<<endl;
    //Marge(D,10,100);
   // Data<int,ROZMIAR> Sorted_Data(1);
    for(int i =0;i<100;++i)
    {
        D->Innit(1);
        Quick_Sort(*D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<< endl;
    }
   //cout<<"Niby posortowane    "<<Sorted_Data<<endl<<endl;
   delete(D);

    //Sorted_Data= Insertion_Sort(D);
    //cout<<"Succes?  "<<Sorted_Data.Check_Sort()<<endl;
    //cout<< Sorted_Data;
    
    
   
   return 0;
}
