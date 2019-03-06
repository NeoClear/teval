#include "dependency.h"

namespace dependency {
    bool isOperator(node_type n)
    {
        if (n == Plus || n == Minus || n == Multi || n == Div)
            return true;
        return false;
    }

    bool isParenthesis(node_type n)
    {
        if (n == LParenthesis || n == RParenthesis)
            return true;
        return false;
    }
    bool isFormula(node_type n)
    {
        if (n != Assign && n != Symbol && n != SemiColon)
            return true;
        return false;
    }
    node_type types(char c)
    {
        if (c == '(')
            return LParenthesis;
        else if (c == ')')
            return RParenthesis;
        else if (isdigit(static_cast<int>(c)) || c == '.')
            return Number;
        else if (c == '+')
            return Plus;
        else if (c == '-')
            return Minus;
        else if (c == '*')
            return Multi;
        else if (c == '/')
            return Div;
        else if (c == '=')
            return Assign;
        else if (c == ';')
            return SemiColon;
        else if (isalpha(c))
            return Symbol;
        else
            return Default;
    }
    node_type types_s(std::string s)
    {
        if (s.size() == 1)
            return types(s[0]);
        if (s[0] == '-' && types(s[1]) == Number)
            return Number;
        return types(s[0]);
    }
    complex read_complex(const char *s)
    {
        size_t i = 0;
        double f = 1.0;
        bool flag = false;
        double div = 1.0;
        double real = 0.0;
        double img = 0.0;
        char ch;
        while (i < strlen(s)) {
            ch = s[i];
            i++;
            if (ch == '-') {
                f = -1.0;
                continue;
            }
            if (ch == '.') {
                flag = true;
                continue;
            }
            if (ch == 'd') {
                break;
            }
            if (flag)
                div *= 10;
            real = real * 10 + ch - '0';
        }
        real *= f / div;
        f = 1.0;
        flag = false;
        div = 1.0;
        while (i < strlen(s)) {
            ch = s[i];
            i++;
            if (ch == '-') {
                f = -1.0;
                continue;
            }
            if (ch == '.') {
                flag = true;
                continue;
            }
            if (flag)
                div *= 10;
            img = img * 10 + ch - '0';
        }
        img *= f / div;
        complex res;
        res.real = real;
        res.img = img;
        return res;
    }
    void print_complex(complex x)
    {
        if (abs(x.img) < 0.000001)
            std::cout<< x.real<< std::endl;
        else
            std::cout<< x.real<< "d"<< x.img<< std::endl;
    }
}
