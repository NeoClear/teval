#include "core.h"

namespace core {
    inline void calc()
    {
        int i = top - 1;
        while (parse[i].tp != 0)
            i--;
        int j = i + 1;
        if (j == top - 1) {
            top -= 2;
            return;
        }
        float ans = parse[j].val;
        for (int p = j + 2; p <= top - 1; p += 2) {
            if (parse[p - 1].tp == Plus)
                ans += parse[p].val;
            if (parse[p - 1].tp == Minus)
                ans -= parse[p].val;
        }
        parse[i].tp = 2;
        parse[i].val = ans;
        top = i + 1;
    }

    inline void multi()
    {
        parse[top - 3].val *= parse[top - 1].val;
        top -= 2;
    }

    inline void div()
    {
        parse[top - 3].val /= parse[top - 1].val;
        top -= 2;
    }

    void eval()
    {
        bool assign = false;
        std::string name;
        for (size_t i = 0; i < block.size(); i++) {
            if (block[i] == "let") {
                assign = true;
                i++;
                name = block[i];
                i++;
                if (block[i] != "=") {
                    printf("Didn't find a assigning operator\n");
                    return;
                }
                continue;
            } else if (block[i] == ";") {
                if (top != 1) {
                    printf("Didn't parse correctly.\n");
                    return;
                }
                if (assign) {
                    table[name] = parse[0].val;
                    std::cout<< name<< " -> "<< table[name]<< std::endl;
                    update_regis = false;
                } else {
                    regis = parse[0].val;
                    update_regis = true;
                }
                name.clear();
                assign = false;
                top = 0;
            }
            node_type kind = dependency::types_s(block[i]);
            parse[top].tp = kind;
            if (parse[top].tp == Number)
                parse[top].val = stof(block[i]);
            top++;
            if (parse[top - 1].tp == RParenthesis)
                calc();
            if (parse[top - 2].tp == Multi && parse[top - 1].tp == Number)
                multi();
            if (parse[top - 2].tp == Div && parse[top - 1].tp == Number)
                div();
        }
    }
}
