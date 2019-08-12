#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int NResult = 0;
string SResult;

bool isSubString(const string &str2, const string &output, std::string::iterator itO, std::string::iterator itS)
{
    if (itO == output.end()-1)
    {
        //itFind = std::find(itS, str2.end(), *itO);
        while (itS != str2.end()){
            if (*itS == *itO) 
            {
                return true;
            }
            ++itS;
        }
        return false;
    }
    else if (itO != output.end()-1)
    {
        //itFind = std::find(itS, str2.end(), *itO);
        while (itS != str2.end())
        {
            if (*itS == *itO) 
            {
                bool isSubTemp = isSubString(str2, output, itO+1, itS+1);
                if (isSubTemp == true)
                {   return true;}
            }
            ++itS;
        }
    }
        return false;
}

void combination(const string &str1, const string &str2O, int k, int subK, vector<int> result)
{
    if (k == 0)
    {
        string output;
        for (int i = 0; i < result.size(); i++)
        {
            output += str1[result[i]];
        }
        //cout << output << "\n";
        std::string::iterator itO=output.begin();
        string str2 = str2O;
        std::string::iterator itS=str2.begin();
        if (isSubString(str2, output, itO, itS) == true)
        {
            NResult = output.size();
            SResult = output;
            cout << "RIGHT: " << NResult << " " << SResult << "\n";
        }
    }
    else if (k != 0)
    {
        for (int i = subK; i < str1.size()-(k-1); i++)
        {
            result.push_back(i);
            combination(str1, str2O, k-1, i+1, result);
            result.pop_back();
        }
    }
}

void getSubString(const string &str1, const string &str2)
{
    string strCopy = str1;
    vector<int> result;
    for (int k = str1.size(); k > 0; k--)
    {
        if (NResult == 0)
        {   combination(str1, str2, k, 0, result);}
        else
        {   break;}
    }
}

int main(int argc, char* argv[])
{
//    vector<int> result;
    std::string str1 = argv[1];
    std::string str2 = argv[2];
    getSubString(str1, str2);
//    combination(arr, k, 0, result);
    return 0;
}
