#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void LoadingScreen(string text, size_t millisecond = 100, int color = 6)
{
    try
    {
        SetColor(color);
        system("cls");

        SetConsoleCP(437);
        SetConsoleOutputCP(437);
        int block1 = 177, block2 = 219;

        cout << "\n\n\n\n\n\n\t\t\t\t\t" << text << "....";
        cout << "\n\n\t\t\t\t";

        for (size_t i = 0; i < 30; i++)
            cout << ((char)block1);

        cout << "\r";
        cout << "\t\t\t\t";

        for (size_t i = 0; i < 30; i++)
        {
            cout << ((char)block2);
            Sleep(millisecond);
        }

        SetConsoleCP(0);
        SetConsoleOutputCP(0);
        SetColor(color);
    }
    catch (exception& ex)
    {
        system("cls");
        cout << ex.what() << endl;
        system("pause");
    }
}

int main()
{
    LoadingScreen("Loading");
    return 0;
}
