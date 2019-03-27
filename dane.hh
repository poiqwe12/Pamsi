#include <cstdlib>
#include <iostream>
#include <time.h>
////////////////////////////////////////////////////////////////
template <typename Type, int Wymiar>
class Data
{
    Type tab[Wymiar];

  public:
    Data(int nr);
    void Innit(int nr);
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
    bool Check_Sort() const
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
void Data<Type, Wymiar>::Innit(int nr)
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
    else if (nr == 3)
    {
        for (unsigned int i = 0; i < Wymiar; ++i)
        {
            tab[i] = -Wymiar - i;
        }
    }
}
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
    clock_t start, stop;
    start = clock();
    while (change)
    {
        change = false;
        for (unsigned int i = 0; i < Wymiar - shift; ++i)
        {
            if (D[i + 1] < D[i])
            {
                Swap(D[i + 1], D[i]);
                change = true;
            }
        }
        shift++;
    }
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;
    return D;
}
/*   Insertion Sort      */
template <typename Type, int Wymiar>
Data<Type, Wymiar> Insertion_Sort(Data<Type, Wymiar> D)
{
    int j;
    clock_t start, stop;
    start = clock();
    for (unsigned int i = 1; i < Wymiar; ++i)
    {
        Type r = D[i];
        j = i - 1;
        while ((j >= 0) && (r < D[j]))
        {
            D[j + 1] = D[j];
            --j;
        }
        D[j + 1] = r;
    }
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;
    return D;
}
/*   Merge Sort          */
template <typename Type, int Wymiar>
void Merge(Data<Type, Wymiar> &D, Type *copy, int start, int mid, int end)
{
    for (int i = start; i <= end; ++i)
    {
        copy[i] = D[i];
    }
    int var_L = start;
    int var_R = mid + 1;
    int var_D = start;

    while ((var_L <= mid) && (var_R <= end))
    {
        if (copy[var_L] < copy[var_R])
        {
            D[var_D] = copy[var_L];
            var_L++;
        }
        else
        {
            D[var_D] = copy[var_R];
            var_R++;
        }
        var_D++;
    }

    while (var_L <= mid)
    {
        D[var_D] = copy[var_L];
        var_D++;
        var_L++;
    }
    while (var_R <= end)
    {
        D[var_D] = copy[var_R];
        var_D++;
        var_R++;
    }
}
template <typename Type, int Wymiar>
void Merge_Sort2(Data<Type, Wymiar> &D, Type *copy, int start_array, int end_array)
{
    if (start_array < end_array)
    {
        int half = (start_array + end_array) / 2;
        Merge_Sort2(D, copy, start_array, half);
        Merge_Sort2(D, copy, half + 1, end_array);
        Merge(D, copy, start_array, half, end_array);
    }
}
template <typename Type, int Wymiar>
Data<Type, Wymiar> Merge_Sort(Data<Type, Wymiar> D)
{
    Type *copy = new Type[Wymiar]; //Tablica wymagana do sortowania
    clock_t start, stop;
    start = clock();
    Merge_Sort2(D, copy, 0, Wymiar - 1);
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;

    delete (copy);
    return D;
}
/*   Heap sort          */
template <typename Type, int Wymiar>
void Shift_Down(Data<Type, Wymiar> &D, int index_parent, int size)
{
    int index_L = 2 * index_parent + 1;
    int index_R = 2 * index_parent + 2;
    int index_Swap = index_parent;

    if (index_R < size)
    {
        if (D[index_R] > D[index_L])
        {
            index_Swap = index_R;
        }
        else
        {
            index_Swap = index_L;
        }
    }
    else
    {
        if (index_L < size)
            index_Swap = index_L;
    }

    if (D[index_Swap] > D[index_parent])
    {
        Swap(D[index_Swap], D[index_parent]);
        Shift_Down(D, index_Swap, size);
    }
}

template <typename Type, int Wymiar>
Data<Type, Wymiar> Heap_Sort(Data<Type, Wymiar> D)
{
    clock_t start, stop;
    start = clock();
    for (int i = (Wymiar / 2) - 1; i >= 0; --i)
    {
        Shift_Down(D, i, Wymiar);
    }
    for (int i = 1; i < Wymiar; ++i)
    {
        // std::cout<<D << "przed i=" <<Wymiar-i<<std::endl;
        Swap(D[0], D[Wymiar - i]);
        //std::cout<<D << "i=" <<i<<std::endl;
        Shift_Down(D, 0, Wymiar - i);
        // std::cout << D << "i=" << i << std::endl;
    }
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;
    return D;
}
/*          Quick Sort    */
template <typename Type, int Wymiar>
Data<Type, Wymiar> Quick_Sort(Data<Type, Wymiar> D)
{
    clock_t start, stop;
    start = clock();
    Quick_Sort2(D, 0, Wymiar - 1);
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;

    return D;
}
/*         Sposób wybierania piwota */
int Choose_lim(int index_l, int index_r)
{
    int lim = (index_r + index_l) / 2;
    return lim;
}
template <typename Type, int Wymiar>
int Div_array(Data<Type, Wymiar> &D, int index_left, int index_right)
{
    int index_lim = Choose_lim(index_left, index_right);
    int value_lim = D[index_lim];
    D[index_lim] = D[index_right];
    int position = index_left;
    for (int i = index_left; i < index_right; ++i)
    {
        if (D[i] < value_lim)
        {
            Swap(D[i], D[position]);
            ++position;
        }
    }
    D[index_right] = D[position];
    D[position] = value_lim;
    return position;
}
/*       Quick sort     */
template <typename Type, int Wymiar>
Data<Type, Wymiar> Quick_Sort2(Data<Type, Wymiar> &D, int index_left, int index_right)
{
    if (index_left < index_right)
    {
        int granica = Div_array(D, index_left, index_right);
        if (index_left < granica - 1)
            Quick_Sort2(D, index_left, granica);
        if (granica + 1 < index_right)
            Quick_Sort2(D, granica + 1, index_right);
    }
}
template <typename Type, int Wymiar>
Data<Type, Wymiar> Shell_Sort(Data<Type, Wymiar> D)
{
    clock_t start, stop;
    start = clock();
    bool change=1;
    int tab_odl[8] = {701, 301, 132, 57, 23, 10, 4, 1};
    for (int odl = 0; odl < 8; ++odl)
    {

        unsigned int shift = 0;
        while (change)
        {
            change = false;
            for (unsigned int i = 0; i < Wymiar - shift; ++i)
            {
                if (tab_odl[odl] + i < Wymiar)
                {
                    if (D[i + 1] < D[i])
                    {
                        Swap(D[i + 1], D[i]);
                        change = true;
                    }
                }
            }
            shift++;
        }
    }
    stop = clock();
    double czas = (double)(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas trwania: " << czas << std::endl;
    return D;
}
