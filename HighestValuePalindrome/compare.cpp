#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main (int argc, char *argv[])
{
    cout << "aaaaaaaaaaaaaa" << "\n";
    int count = 0;
    string temp1 = argv[1];
    string temp2 = argv[2];
    for (int i=0; i < temp1.size() ; i++)
    {
        if (temp1[i] != temp2[i])
        {
            count += 1;
        }
    }
    cout << count << "\n";
    return 0;
}
