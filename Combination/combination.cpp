#include <iostream>
#include <vector>

using namespace std;

void combination(const vector<int> &arr, int k, int subK, vector<int> result)
{
    if (k == 0)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "  ";
        }
        cout << "\n";
    }
    else if (k != 0)
    {
        for (int i = subK; i < arr.size()-(k-1); i++)
        {
            result.push_back(i);
            combination(arr, k-1, i+1, result);
            result.pop_back();
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr;
    vector<int> result;
    string temp = argv[1];
    int k = std::stoi(temp);
    for (int i=0; i<20 ; i++)
    {
        arr.push_back(i);
    }
    combination(arr, k, 0, result);
    return 0;
}
