#include <iostream>
#include <algorithm>
#include "mapset.hpp"

using namespace std;

string to_lowercase(const string& str)
{
    string low;
    ranges::transform(str, back_inserter(low), [](char c) { return tolower(c); });
    return low;
}

set<string> load_stopwords(istream& stopwords)
{
    set<string> s;
    transform(istream_iterator<string>(stopwords), istream_iterator<string>(), inserter(s, s.end()), to_lowercase);
    return s;
}

map<string, int> count_words(istream& document, const set<string>& stopwords)
{
    map<string, int> m;
    
    auto add = [&m, stopwords] (string w)
                {
                    w = to_lowercase(w);
                    if (stopwords.find(w) == stopwords.end())
                    {
                        if (m.count(w) > 0)
                            ++m[w];
                        else
                            m[w] = 1;
                    }
                };
    for_each(istream_iterator<string>(document), istream_iterator<string>(), add);

    return m;
}

void output_word_counts(const map<string, int>& word_counts, ostream& output)
{
    for (const auto& [word, count] : word_counts)
        output << word << ' ' << count << '\n';
}
