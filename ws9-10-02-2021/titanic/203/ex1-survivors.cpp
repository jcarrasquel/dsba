#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using  namespace std;

vector <string> survivors(ifstream& titanic)
{
    vector <string> names;
    int i;
    vector<string> stroka;
    string token;
    string line;
    istringstream ss(line);
    while (getline(titanic,line))
    {
        i = 0;
        while (getline(ss, token, ','))
            stroka.push_back(token);
        if (stroka[1] == "1") {
            string a = stroka[3];
            names.push_back(a);
        }
    }
    titanic.close();
    return names;
}


 int main(){

    ifstream t;
    t.open("titanic.csv");
    vector<string> ans;
    ans = survivors(t);
     for (int i = 0; i < ans.size(); i++)
     {
         cout << ans[i] <<endl;
     }
    return 0;
}