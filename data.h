#ifndef DATA_H
#define DATA_H

#include <bits/stdc++.h>

#define inf 0xffff
typedef long long i64;
typedef double f64;

enum node_type
{
    LParenthesis,
    RParenthesis,
    Number,
    Plus,
    Minus,
    Multi,
    Div,
    Assign,
    SemiColon,
    Default,
    Symbol,
};

struct complex
{
    double real;
    double img;
    complex(): real(0.0), img(0.0) {}
};

struct node
{
    int tp;
    complex val;
    node(): tp(0) {
        memset(&val, 0, sizeof(val));
    }
};



extern std::string src;
extern std::vector<std::string> block;

extern node parse[inf];
extern long top;

extern std::map<std::string, complex> table;

extern complex regis;
extern bool update_regis;

namespace data {
    std::string node_type_s(node_type n);
}

namespace init {
    void set_src(char *s);
    void reset();
}

#endif // DATA_H
