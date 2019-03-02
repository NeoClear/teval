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
    Default,
    Symbol,
};

struct node
{
    int tp;
    float val;
    node(): tp(0), val(0.0) {}
};

extern std::string src;
extern std::vector<std::string> block;

extern node parse[inf];
extern long top;

namespace init {
    void set_src(char *s);
    void reset();
}

#endif // DATA_H
