#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main (int argc, char *argv[])
{
    string temp1 = argv[1];
    string::iterator itB = temp1.begin();
    string::iterator itE = temp1.end()-1;
    for (int i=0; i < temp1.size()/2 ; i++)
    {
        if (*itB != *itE)
        {
            cout << "NOT GOOD\n";
            return -1;
        }
        itB += 1;
        itE -= 1;
    }
    cout << "GOOD\n";
    return 0;
}
