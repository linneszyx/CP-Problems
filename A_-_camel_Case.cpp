#include <iostream>
using namespace std;
int firstUpperCaseLetter(char str[], int pos)
{

    if (str[pos] == '\0')
    {
        return -1;
    }

    else if (str[pos] >= 'A' && str[pos] <= 'Z')
    {
        return pos;
    }
    else
    {
        return firstUpperCaseLetter(str, pos + 1);
    }
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    int index = firstUpperCaseLetter(str, 0);

    if (index == -1)
    {
        cout <<index<<endl;
    }

    else
    {
        cout << index + 1 << endl;
    }
    return 0;
}