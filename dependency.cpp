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
}
