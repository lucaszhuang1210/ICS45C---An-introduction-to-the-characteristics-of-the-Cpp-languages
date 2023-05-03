#include <iostream>

using namespace std;

#include "string.hpp"


//*************String class interface methods****************
String::String(const char *s)
:buf(strdup(s))
{
}

String::String(const String &s)
:buf(strdup(s.buf))
{
}

String::String(String &&s)
:buf(s.buf)
{
    s.buf = nullptr;
}

String::String(int length)
:buf(new char[length+1])
{
}

void String::swap(String &s)
{
    std::swap(buf, s.buf);
}

String &String::operator=(const String &s)
{
    delete[] buf;
    buf = strdup(s.buf);
    return *this;
}

String &String::operator=(String &&s)
{
    delete[] buf;
    buf = s.buf;
    s.buf = nullptr;
    return *this;
}

char & String::operator[](int index)
{
    if (!in_bounds(index))
    {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }else{
        return buf[index];
    }
}

const char & String::operator[](int index) const
{
    if (!in_bounds(index))
    {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }else{
        return buf[index];
    }
}

int String::size() const
{
    return strlen(buf);
}

String String::reverse() const
{
    String output{size()};
    reverse_cpy(output.buf, buf);
    return output;
}

int String::indexOf(char c) const
{
    const char *p = strchr(buf, c);
    if (p == nullptr)
        return -1;
    return p - buf;
}

int String::indexOf(const String &s) const
{
    const char *p = strstr(buf, s.buf);
    if (p == nullptr)
        return -1;
    return p - buf;
}

bool String::operator==(const String &s) const
{
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const
{
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String &s) const
{
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String &s) const
{
    return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String &s) const
{
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const
{
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const
{
    String output{size() + s.size()};
    strcpy(output.buf, buf);
    strcat(output.buf, s.buf);
    return output;
}

String & String::operator+=(const String &s)
{
    String temp = *this + s;
    this->swap(temp);
    return *this;
}

void String::print(ostream &out) const
{
    out << buf;
}

void String::read(istream &in)
{
    char input[1024];
    in >> input;
    const char *ptr = input;
    String temp{ptr};
    this->swap(temp);
}


String::~String() 
{
    delete[] buf;
}




//*************functions****************
ostream &operator <<(ostream &out, const String &s)
{
    s.print(out);
    return out;
}

istream &operator >>(istream &in, String &s)
{
    s.read(in);
    return in;
}




//*************static helper methods****************
int String::strlen(const char *s)
{
    int i=0;
    for ( ; s[i] != '\0'; ++i) {}
    return i;
}

char *String::strcpy(char *dest, const char *src)
{
    int i=0;
    for ( ; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strdup(const char *src)
{
    return strcpy(new char[strlen(src)+1], src);
}

char *String::strncpy(char *dest, const char *src, int n )
{
    int i=0;
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
    int i=0;
    int len = strlen(dest);
    for ( ; src[i] != '\0'; ++i)
        dest[len+i] = src[i];
    dest[len+i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i=0;
    int len = strlen(dest);
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[len+i] = src[i];
    dest[len+i] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right)
{
    int i;
    for (i=0; right[i] != '\0'; ++i)
        if (left[i] != right[i])
            break;
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n)
{
    int i;
    for(i=0; i < n; ++i)
        if (left[i] != right[i] || (left[i] == '\0' && right[i] == '\0'))
            return left[i] - right[i];
    return 0;
}

void String::reverse_cpy(char *dest, const char *src)
{
    int i;
    int len = strlen(src);
    for (i=0; src[i] != '\0'; ++i)
        dest[len-1-i] = src[i];
    dest[i] = '\0';
}


const char *String::strchr(const char *str, char c)
{
    const char *p;
    for (p = str; *p != '\0'; ++p)
        if (*p == c)
            return p;
    if (c == '\0')
        return p;
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
    if (strlen(needle) == 0)
        return haystack;
    int len = strlen(needle);
    for(const char *p = haystack; (p = strchr(p, needle[0])); ++p)
        if(strncmp(p, needle, len) == 0)
            return p;
    return nullptr;
}
