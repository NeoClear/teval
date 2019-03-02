#include "data.h"

std::string src;
std::vector<std::string> block;

node parse[inf];
long top = 0;

std::map<std::string, float> table;

float regis;
bool update_regis;

namespace data {
    std::string node_type_s(node_type n)
    {
        switch (n) {
        case LParenthesis:
            return "LParenthesis";
        case RParenthesis:
            return "RParenthesis";
        case Number:
            return "Number";
        case Plus:
            return "Plus";
        case Minus:
            return "Minus";
        case Multi:
            return "Multi";
        case Div:
            return "Div";
        case Assign:
            return "Assign";
        case Default:
            return "Default";
        case Symbol:
            return "Symbol";
        case SemiColon:
            return "SemiColon";
        }
    }
}

namespace init {
    void set_src(char *s)
    {
        src = std::string(s);
    }

    void reset()
    {
        regis = 0;
        update_regis = false;
        block.reserve(inf);
        src.clear();
        block.clear();
        memset(parse, 0, sizeof(parse));
        top = 0;
    }

}

