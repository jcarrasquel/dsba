#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using  namespace std;

vector <string> survivors(ifstream& titanic)
{
    vector <string> names;
    int i;
    //vector<string> stroka; //FIXME This vector should not be here. We put it inside the first "while"
    string token; 
    string line; 
    //istringstream ss(line); //FIXME This stream should not be here. We put it inside the first "while"
    while (getline(titanic,line))
    {
        i = 0;
        
        vector<string> stroka;
        istringstream ss(line);

        while (getline(ss, token, ','))
            stroka.push_back(token);

        if (stroka[1] == "1") {
            string fullName = stroka[3];
            int pos = fullName.find(";", 0);
            string lastName = fullName.substr(0, pos); // Just to add the last name
            names.push_back(lastName);
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
