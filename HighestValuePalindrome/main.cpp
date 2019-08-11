#include <bits/stdc++.h>
#include <string>

using namespace std;

void changeIt(string::iterator &itB, string::iterator &itE)
{
    itB += 1;
    itE -= 1;
}
void replace(string &s, string::iterator &itE, char c, int &k)
{
    s.erase(itE);
    s.insert(itE,c);
    k -= 1;
    //cout << s << "\n";
}
vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int &k) {
    string::iterator itB = s.begin();
    string::iterator itE = s.end();
    itE -= 1;
    int countDiff = 0, canExchange = 0;
    for (int i=0 ; i<n/2 ; i++)
    {
        //cout << *itB << " " << *itE << "\n";
        if ( *itB != *itE)
        {   
            countDiff += 1;
            if (*itB != '9')
            {   canExchange += 1;}
            if (*itE != '9')
            {   canExchange += 1;}
        }
        changeIt(itB, itE);
    }

    cout << "countDiff: " << countDiff << " canExchange: " << canExchange << "\n";
    itB = s.begin();
    itE = s.end();
    itE -= 1;

    if (countDiff > k)
    {   return "-1";}
    else if (countDiff == k)
    {
        for (int i=0 ; i<n/2 ; i++)
        {   
            if (*itE != *itB)
            {
                if (*itE > *itB)
                {
                    replace(s,itB,*itE, k);
                }
                else
                {
                    replace(s,itE,*itB, k);
                }
            }
            changeIt(itB, itE);
        }
    }
    else if ((countDiff < k) && (canExchange > k))
    {
        int gap = k - countDiff;
        for (int i=0 ; i<n/2 ; i++)
        {
            if (*itB != *itE)
            {
                if (gap == 0)
                {
                    if (*itE > *itB)
                    {
                        replace(s,itB,*itE, k);
                    }
                    else
                    {
                        replace(s,itE,*itB, k);
                    }
                }
                else
                {
                    if ((*itE != '9')&&(*itB != '9'))
                    {   gap -= 1;}
                    if (*itE != '9')
                    { replace(s,itE,'9', k);}
                    if (*itB != '9')
                    {   replace(s,itB,'9', k);}
                }
            }
            changeIt(itB, itE);
        }
    }
    else if (canExchange == k)
    {
cout << "go her\n";
        for (int i=0 ; i<n/2 ; i++)
        {
            if (*itB != *itE)
            {
                if (*itE != '9')
                {   replace(s,itE,'9', k);}
                if (*itB != '9')
                {   replace(s,itB,'9', k);}
            }
            changeIt(itB, itE);
        }
    }
    else if (canExchange < k)
    {
        int gap = k - canExchange;
        if ((s.size()%2) == 1)
        {
            if ((gap % 2) == 1)
            {
                string::iterator it = s.begin()+(s.size()/2);
                replace(s,it,'9', k);
                gap -= 1;
            }
        }
        else
        {
            if ((gap % 2) == 1)
            {
                gap -= 1;
            }
        }
        cout << "gap: " << gap << "\n";
        for (int i=0 ; i<n/2 ; i++)
        {
            if (*itB != *itE)
            {
                if (gap >= 0){
                    if (*itE != '9')
                    {   replace(s,itE,'9', k);}
                    if (*itB != '9')
                    {   replace(s,itB,'9', k);}
                }
                else if (gap < 0)
                {
                    if (*itE > *itB)
                    {
                        replace(s,itB,*itE, k);
                    }
                    else
                    {
                        replace(s,itE,*itB, k);
                    }
                }
            }
            else if ((*itB == *itE) && (*itB != '9') && (gap > 0))
            {
                    replace(s,itE,'9', k);
                    replace(s,itB,'9', k);
                    gap -= 2;
            }
            changeIt(itB, itE);
        }
    }
    cout << s << "\n";
    return s;
}

int main(int argc, char *argv[])
{
    ofstream fout(getenv("OUTPUT_PATH"));

    //string nk_temp;
    //getline(cin, nk_temp);

    //vector<string> nk = split_string(nk_temp);

    //int n = stoi(nk[0]);
    string temp = argv[1];
    int n = std::stoi(temp);
    cout << "N: " << n << " ";

    //int k = stoi(nk[1]);
    temp = argv[2];
    int k = std::stoi(temp);
    cout << "K: " << k << "\n";

    //string s;
    //getline(cin, s);
    temp = argv[3];
    string s = temp;

    string result = highestValuePalindrome(s, n, k);
    cout << "value of K current: " << k << "\n";

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

