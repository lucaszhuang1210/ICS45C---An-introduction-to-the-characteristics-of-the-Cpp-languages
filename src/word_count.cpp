#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void to_lowercase(string& str)
{
    int string_length = str.length();
    for(int i=0; i<string_length; ++i)
    {
        if(int(str[i]) <= 90 && int(str[i])>=65)
        {
            str[i] = str[i]+32;
         }
    }
}

set<string> load_stopwords(istream& stopwords)
{
    set<string> S;
    string w;

    while(stopwords >> w)
    {
        to_lowercase(w);
        S.insert(w);
    }

    return S;
}

map<string, int> count_words(istream& document, const set <string>& stopwords)
{
    map<string, int> M;
    string w;

    while(document >> w)
    {
        to_lowercase(w);
        if(stopwords.find(w) == stopwords.end())
        {
            if (M.count(w) > 0)
                ++M[w];
            else
                M[w] = 1;
        }
    }

    return M;
}

void output_word_counts(const map<string,int>& word_counts, ostream& output)
{
    for(auto [word,count]: word_counts)
        output << word << ' ' << count << endl;
}
