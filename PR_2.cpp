#include <iostream>
#include <chrono>
#include <ctime>

int binary_search(int *O, int a)
{
    int start = 0, end = 99;
    int middle;
    bool check = false;
    do
    {
        middle = (start + end) / 2;
        if (O[middle] == a)
        {
            std::cout << "\nЧисло найденно";
            check = true;
            break;
        }
        else if (O[middle] > a)
            end = middle;
        else if (O[middle] < a)
            start = middle;
    } while (start < end);
    if(check == false)
        std::cout << "\nЧисло не найденно";
    return 0;
}

int max_min(int *N)
{
    int max = -99, min = 99;
    for (int i = 0; i < 100; i++)
    {
        if (N[i] > max)
            max = N[i];
        if (N[i] < min)
            min = N[i];
    }
    std::cout << "\n\nМинимальный элемент: " << min << "\nМаксимальный элемент: " << max;
    return 0;
}

void quick_sort(int *O, int  end, int begin)
{
    int mid, a;
    int f = begin;
    int l = end;
    mid = O[(f + l) / 2];
    while (f < l)
    {
        while (O[f] < mid) f++;
        while (O[l] > mid) l--;
        if (f <= l)
        {
            a = O[f];
            O[f] = O[l];
            O[l] = a;
            f++;
            l--;
        }
    }
    if (begin < l) quick_sort(O, l, begin);
    if (f < end) quick_sort(O, end, f);
}

int one(int *N)
{
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        N[i] = rand() % 198 - 99;
        std::cout << N[i] << " ";
    }
    return 0;
}

int two(int *N, int *O)
{    
    for (int i = 0; i < 100; i++)
        O[i] = N[i];
    auto start = std::chrono::steady_clock::now();
    quick_sort(O, 99, 0);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration<double>(end - start);
    for (int i = 0; i < 100; i++)
        std::cout << O[i] << " ";
    std::cout << "\n\nВремя сортировки массива методом быстрой сортировкой: " << std::fixed << time.count() << " секунд";
    return 0;
}

int three(int *N, int *O)
{
    auto start = std::chrono::steady_clock::now();
    max_min(N);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration<double>(end - start);
    std::cout << "\nВремя поиска в неотсортированном массиве: " << std::fixed << time.count() << " секунд";
    start = std::chrono::steady_clock::now();
    int max = O[99];
    int min = O[0];
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration<double>(end - start);
    std::cout << "\n\nМинимальный элемент: " << min << "\nМаксимальный элемент: " << max << "\nВремя поиска в отсортированном массиве: " << std::fixed << time.count() << " секунд";
    return 0;
}

int four(int *O)
{
    int middle = (O[0]+O[99])/2;
    int count = 0;
    std::cout << "\nСреднее значение элементов массива(max/min): " << middle;
    for (int i = 0; i < 99; i++)
    {
        if (O[i] == middle)
        {
            count++;
            std::cout << "\nИндекс элемента со значением равным среднему: " << i;
        }
    }
    std::cout << "\nКоличество совпадений: " << count;
    return 0;
}

int five(int *O)
{
    int a;
    int count = 0;
    std::cout << "\nВведите число для сравнения: ";
    std::cin >> a;
    for (int i = 0; i < 100; i++)
    {
        if (O[i] < a)
            count++;
    }
    std::cout << "\nКоличество элементов массива менших заданного числа: " << count;
    return 0;
}

int six(int *O)
{
    int b;
    int count = 0;
    std::cout << "\nВведите число для сравнения: ";
    std::cin >> b;
    for (int i = 0; i < 100; i++)
    {
        if (O[i] > b)
            count++;
    }
    std::cout << "\nКоличество элементов массива больших заданного числа: " << count;
    return 0;
}

int seven(int *O)
{
    int a;
    std::cout << "\nВведите искомое число: ";
    std::cin >> a;
    auto start = std::chrono::steady_clock::now();
    binary_search(O, a);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration<double>(end - start);
    std::cout << "\nВремя потраченное на поиск бинарным методом: " << std::fixed << time.count();
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 99; i++)
    {
        if (O[i] == a)
        {
            std::cout << "\nЧисло найденно";
            break;
        }
        if (O[i] > a || i>97)
        {
            std::cout << "\nЧисло не найденно";
            break;
        }
    }
    end = std::chrono::steady_clock::now();
    time = std::chrono::duration<double>(end - start);
    std::cout << "\nВремя потраченное на поиск перебором: " << std::fixed << time.count();
    return 0;
}

int eight(int* O)
{
    int a, b, swap;
    std::cout << "\nВведите индекс первого числа для обмена: ";
    std::cin >> a;
    std::cout << "\nВведите индекс второго числа для обмена: ";
    std::cin >> b;
    auto start = std::chrono::steady_clock::now();
    swap = O[a];
    O[a] = O[b];
    O[b] = swap;
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration<double>(end - start);
    std::cout << "\nВремя потраченное на обмен: " << std::fixed << time.count();
    return 0;
}

int main()
{
    int N[100];
    int O[100];
    int i;
    setlocale(0, "");
    std::cout << "1 - Создание массива случайных чисел\n2 - Сортировка массива\n3 - Поиск минимального и максимального элементов\n4 - Среднее значение\n\
5 - Поиск значений меньших заданного\n6 - Поиск значений больших заданного\n7 - Поиск заданного числа\n8 - Обмен местами двух элементов\n9 - Выход";
menu: std::cout << "\n\nВыберите пункт меню: ";
    std::cin >> i;
    switch (i)
    {
    case 1:
        std::cout << "\nМассив случайных чисел: ";
        one(N);
        goto menu;
    case 2:
        std::cout << "\nОтсортированный массив случайных чисел: ";
        two(N, O);
        goto menu;
    case 3:
        three(N, O);
        goto menu;
    case 4:
        four(O);
        goto menu;
    case 5:
        five(O);
        goto menu;
    case 6:
        six(O);
        goto menu;
    case 7:
        seven(O);
        goto menu;
    case 8:
        eight(O);
        goto menu;
    case 9:
        break;
    default:
        std::cout << "\nТакого пункта не существует\n";
        goto menu;
    }
}