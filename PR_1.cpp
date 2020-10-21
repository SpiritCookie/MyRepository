#include <iostream>
#include <Windows.h>

/*Black = 0,
Blue = 1,
Green = 2,
Cyan = 3,
Red = 4,
Magenta = 5,
Brown = 6,
LightGray = 7,
DarkGray = 8,
LightBlue = 9,
LightGreen = 10,
LightCyan = 11,
LightRed = 12,
LightMagenta = 13,
Yellow = 14,
White = 15*/

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int one()
{
    std::cout << "\nКоличество байт отведённых в памяти под различные типы данных:\n\n";
    std::cout << "int: " << sizeof(int) << "\n" << "short int: " << sizeof(short int) << "\n" << "long int: " << sizeof(long int) << "\n";
    std::cout << "float: " << sizeof(float) << "\n" << "double: " << sizeof(double) << "\n" << "long double: " << sizeof(long double) << "\n";
    std::cout << "char: " << sizeof(char) << "\n" << "bool: " << sizeof(bool) << "\n\n";
    return 0;
}

int two()
{
    int a;
    int mask = 1 << 31;
    std::cout << "\nВаше число: ";
    std::cin >> a;
    std::cout << "\nЕго двоичное представление: ";
    for (int i = 0; i < 32; i++)
    {
        if (i != 0)
        {
            SetColor(1,0);
            putchar(a & mask ? '1' : '0');
            a <<= 1;
            SetColor(7,0);
        }
        else
        {
            SetColor(4, 0);
            putchar(a & mask ? '1' : '0');
            a <<= 1;
            SetColor(7, 0);
        }
    }
    std::cout << "\n";

    return 0;
}

float three()
{
    union
    {
        float a;
        int b;
    };
    int mask = 1 << 31;
    std::cout << "\nВаше число: ";
    std::cin >> a;
    std::cout << "\nЕго двоичное представление: ";
    for (int i = 0; i < 32; i++)
    {
        if (i > 8)
        {
            SetColor(1, 0);
            putchar(b & mask ? '1' : '0');
            b <<= 1;
            SetColor(7, 0);
        }
        else if (i > 0 && i < 9)
        {
            SetColor(2, 0);
            putchar(b & mask ? '1' : '0');
            b <<= 1;
            SetColor(7, 0);
        }
        else if (i == 0)
        {
            SetColor(4, 0);
            putchar(b & mask ? '1' : '0');
            b <<= 1;
            SetColor(7, 0);
        }
    }
    std::cout << "\n";

    return 0;
}

double four()
{
    union
    {
        double a;
        int b[2];
    };
    int mask = 1 << 31;
    std::cout << "\nВаше число: ";
    std::cin >> a;
    std::cout << "\nЕго двоичное представление: ";
    for (int j = 1; j >= 0; j--)
    {
        for (int i = 0; i < 32; i++)
        {
            if (j == 0 || i > 11)
            {
                SetColor(1, 0);
                putchar(b[j] & mask ? '1' : '0');
                b[j] <<= 1;
                SetColor(7, 0);
            }
            else if (j == 1 && i == 0)
            {
                SetColor(4, 0);
                putchar(b[j] & mask ? '1' : '0');
                b[j] <<= 1;
                SetColor(7, 0);
            }
            else if (j == 1 && i < 12)
            {
                SetColor(2, 0);
                putchar(b[j] & mask ? '1' : '0');
                b[j] <<= 1;
                SetColor(7, 0);
            }

        }
    }
    std::cout << "\n";

    return 0;
}

int main()
{
    int i;
    setlocale(0, "");
    std::cout << "1 - Вывод количества байт для различных типов данных\n2 - Двоичное представление целого числа\n3 - Двоичное представление типа float\n4 - Двоичное представление типа double\n5 - Выход\n";
    menu: std::cout << "\nВыберите пункт меню: ";
    std::cin >> i;
    switch (i)
    {
    case 1:
        one();
        goto menu;
    case 2:
        two();
        goto menu;
    case 3:
        three();
        goto menu;
    case 4:
        four();
        goto menu;
    case 5:
        break;
    default:
        std::cout << "\nТакого пункта не существует\n";
        goto menu;
    }
}