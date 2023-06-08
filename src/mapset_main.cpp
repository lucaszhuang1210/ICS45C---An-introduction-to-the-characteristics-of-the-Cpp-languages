#include <algorithm>
#include <fstream>
#include <iterator>
#include <ranges>

#include "map_array.hpp"
#include "set_list.hpp"

using namespace std;

string to_lowercase(const string& str) {
    auto lower_view = views::transform(str, ::tolower);
    return {lower_view.begin(), lower_view.end()};
}

SetList<string> load_stopwords(istream& stopwords) {
    return SetList<string>{ranges::istream_view<string>(stopwords) 
    | views::transform(to_lowercase)};
}

MapArray<string, int> count_words(istream& document, SetList<string>& stopwords) {
    auto words_view = ranges::istream_view<string>(document)
                    | views::transform(to_lowercase)
                    | views::filter([&](const string& s) 
                            { return !stopwords.contains(s); } );
    MapArray<string, int> result;

    for (const string& s: words_view) { ++result[s]; }

    return result;
}

void output_word_counts(MapArray<string, int>& word_counts, ostream& output) {
    for (const auto& [word, count] : word_counts) {
        output << word << ' ' << count << '\n';
    }
}

int main() {
    ifstream stopwords_file{"stopwords.txt"};
    ifstream document{"sample_doc.txt"};
    ofstream output{"frequency.txt"};

    auto stopwords = load_stopwords(stopwords_file);
    auto word_counts = count_words(document, stopwords);
    output_word_counts(word_counts, output);
}
