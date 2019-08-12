#include <iostream>
#include <vector>

using namespace std;

void combination(const string &str1, int k, int subK, vector<int> result)
{
    if (k == 0)
    {
        string output;
        for (int i = 0; i < result.size(); i++)
        {
            output += str1[result[i]];
        }
        cout << output << "\n";
    }
    else if (k != 0)
    {
        for (int i = subK; i < str1.size()-(k-1); i++)
        {
            result.push_back(i);
            combination(str1, k-1, i+1, result);
            result.pop_back();
        }
    }
}

void getSubString(const string &str1)
{
    string strCopy = str1;
    vector<int> result;
    for (int k = str1.size(); k >= 0; k--)
    {
        combination(str1, k, 0, result);
    }
}

int main(int argc, char* argv[])
{
//    vector<int> result;
    string str1 = argv[1];
    getSubString(str1);
//    combination(arr, k, 0, result);
    return 0;
}
