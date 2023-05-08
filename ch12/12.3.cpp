

#include <bits/stdc++.h>
#include "12.3.h"
using namespace std;

TextQuery::TextQuery(ifstream& is):data(new vector<string>){
        string s;
        int cur = 0;
        while(getline(is, s)){
            data->push_back(s);
            istringstream line(s);
            string text;
            while(line >> text){
                if(words_showup[text]){
                    words_showup[text]->insert(cur);
                }
                else{
                    words_showup[text].reset(new set<int>);
                    words_showup[text]->insert(cur);
                }
            }
            cur ++;
        }
        //cout << data->size() << endl;
    }

QueryResult TextQuery::query(const string& s){
        if(words_showup.count(s)){
            return QueryResult(s, data,words_showup[s]);
        }
        return QueryResult(s, data, shared_ptr<set<int>>(new set<int>));
    }



int main(){
    ifstream in;
    in.open("12.2.2.cpp");
    if(in.fail())
        cerr << "Error: " << strerror(errno);
    TextQuery tq(in);
    cout << tq.query("using");

    system("pause");
}