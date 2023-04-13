#include <iostream>
using namespace std;

string LETTER_CHART = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int char_to_index(char ch)
{
    char upperChar = toupper(ch);
    return LETTER_CHART.find(upperChar);
}

char index_to_char(int i)
{
    return LETTER_CHART.at(i);
}

void count(string s, int counts[])
{
    for(int i=0; i<s.size(); ++i)
    {
        if (isalpha(s.at(i)))
        {
            int index = char_to_index(s.at(i));
            ++counts[index];
        }
    }
}
void print_counts(int count[], int len)
{
    for(int i=0; i<len; ++i)
    {
        cout << index_to_char(i) << ' '
             << count[i] << endl;
    }
}
