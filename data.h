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
    const complex operator +(const complex n)
    {
        complex res;
        res.real = real + n.real;
        res.img = img + n.img;
        return res;
    }
    const complex operator -(const complex n)
    {
        complex res;
        res.real = real - n.real;
        res.img = img - n.img;
        return res;
    }
    const complex operator *(const complex n)
    {
        complex res;
        res.real = real * n.real - img * n.img;
        res.img = real * n.img + img * n.real;
        return res;
    }
    const complex operator /(const complex n)
    {
        complex res;
        double div = n.real * n.real + n.img * n.img;
        res.real = (real * n.real + img * n.img) / div;
        res.img = (img * n.real - real * n.img) / div;
        return res;
    }
    bool operator ==(const complex n)
    {
        if ((abs(real - n.real) < 0.00001) && (abs(img - n.img) < 0.00001))
            return true;
        return false;
    }
    void operator +=(const complex n)
    {
        real += n.real;
        img += n.img;
    }
    void operator -=(const complex n)
    {
        real -= n.real;
        img -= n.img;
    }
    void operator *=(const complex n)
    {
        complex res;
        res.real = real;
        res.img = img;
        real = (res * n).real;
        img = (res * n).img;
    }
    void operator /=(const complex n)
    {
        complex res;
        res.real = real;
        res.img = img;
        real = (res / n).real;
        img = (res / n).img;
    }
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
