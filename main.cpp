#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
void insert_sorted(vector<T>& v, T n) {
    typename vector<T>::iterator bound;
    bool inc=((*(v.begin())<(*(v.begin()+1)))?true:false);
    bound = stable_partition(v.begin(), v.end(), [n,inc](T i)
     {
        return (inc?(i<n):(i>n));
    });
    v.insert(bound,n);
};

int main()
{
    // ---- Task 1
    // Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
    // которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
    // чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted, которая
    // сможет аналогично работать с любым контейнером, содержащим любой тип значения.
    cout << "Task 1"<<endl;

     vector<int> v;
     for (int i=9; i>0; --i) if (i!=7) v.push_back(i*10);
//     for (int i=1; i<10; ++i) if (i!=7) v.push_back(i*10);
     for (auto t:v) cout<<t<<" ";
     insert_sorted<int>(v,70);
     cout<<endl<<"Inserted"<<endl;
     for (auto t:v) cout<<t<<" ";

    cout << endl<<endl;

    // ---- Task 2
    // Сгенерируйте вектор, состоящий из 100 вещественный чисел, представляющий собой значения аналогового сигнала,
    // изменяющегося по синусоиде. На основе этого массива чисел создайте другой вектор целых чисел, представляющий
    // цифровой сигнал, в котором будут откинуты дробные части чисел. Выведите получившиеся массивы чисел.
    // Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым по формуле: S(i=0,N-1)((Ai-Bi)^2)
    // Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.
    cout << "Task 2"<<endl;
    const int nn=100;
    const size_t data={nn};
    vector<double> v_doubl;
    v_doubl.reserve(data);
    size_t itr=0;
    double sum=0;
    generate_n(back_inserter(v_doubl), data, [&]() {
        double t=(nn*sin(6.28*itr++/nn));
        sum+=pow((t-int(t)),2);
        return t;
    });
    cout<<endl;
    cout<<"Double: ";
    //for (auto& t:v_doubl) cout<<t<<" ";
    copy(v_doubl.begin(), v_doubl.end(), ostream_iterator<double>{cout, " "});
    cout<<endl;
    cout<<"Integer: ";
    copy(v_doubl.begin(), v_doubl.end(), ostream_iterator<int>{cout, " "});
    //for (auto& t:v_doubl) cout<<int(t)<<" ";
    cout<<endl;
    cout<<"S(i=0:N-1)((Ai-Bi)^2="<<sum;
    cout <<endl<<endl;

    return 0;
}
