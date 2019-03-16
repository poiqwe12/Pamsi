#include <cstdlib>
#include <iostream>

////////////////////////////////////////////////////////////////
template <typename Type, int Wymiar>
class Data
{
    Type tab[Wymiar];

  public:
    Data(int nr);
    const Type &operator[](unsigned int index) const
    {
        if (index < Wymiar)
        {
            return tab[index];
        }
        std::cout << " Przekroczono zakres tablicy!! const \n ";
        exit(1);
    }
    Type &operator[](unsigned int index)
    {
        if (index < Wymiar)
        {
            return tab[index];
        }
        std::cout << " Przekroczono zakres tablicy!! \n ";
        exit(1);
    }
    bool Check_Sort()
    {
        for (unsigned int i = 0; i < Wymiar - 1; ++i)
        {
            if (tab[i] > tab[i + 1])
                return false;
        }
        return true;
    }
};

template <typename Type, int Wymiar>
Data<Type, Wymiar>::Data(int nr)
{
    if (nr == 0)
    {
        for (unsigned int i = 0; i < Wymiar; ++i)
        {
            tab[i] = rand() % Wymiar;
        }
    }
    else if (nr == 1)
    {
        for (unsigned int i = 0; i < Wymiar; ++i)
        {
            tab[i] = i;
        }
    }
    else if (nr == 2)
    {
        for (unsigned int i = 0; i < Wymiar; ++i)
        {
            tab[i] = Wymiar - i;
        }
    }
}
template <typename Type, int Wymiar>
std::ostream &operator<<(std::ostream &stream, Data<Type, Wymiar> D)
{
    for (unsigned int i = 0; i < Wymiar; ++i)
    {
        std::cout << D[i] << "  ";
    }
    std::cout << std::endl;
    return stream;
}

/*   Swap two elements */
template <typename Type>
void Swap(Type &T1, Type &T2)
{
    Type T3 = T1;
    T1 = T2;
    T2 = T3;
    //std::cout<<"a";
}

/*   Bumble Sort         */
template <typename Type, int Wymiar>
Data<Type, Wymiar> Bumble_Sort(Data<Type, Wymiar> D)
{
    bool change = true;
    unsigned int shift = 1;
    while (change)
    {
        change = false;
        for (unsigned int i = 0; i < Wymiar - shift; ++i)
        {
            if (D[i+1] < D[i])
            {
                Swap(D[i + 1], D[i]);
                change = true;
            }
        }
        shift++;
    }
    return D;
}
/*   Insertion Sort      */
template<typename Type,int Wymiar>
Data<Type,Wymiar> Insertion_Sort(Data<Type,Wymiar> D)
{
    int j;
    for(unsigned int i = 1;i<Wymiar;++i)
    {
        Type r=D[i];
        j=i-1;
        while((j>=0)&&(r<D[j]))
        {
            D[j+1]=D[j];
            --j;
        }
        D[j+1]=r;

    }
    return D;
}