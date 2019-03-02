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

    float eval()
    {
        for (size_t i = 0; i < block.size(); i++) {
            parse[top].tp = dependency::types_s( block[i]);
            if (parse[top].tp == Number)
                parse[top].val = stof(block[i]);
            top++;
            if (parse[top - 1].tp == RParenthesis)
                calc();
            if (parse[top - 2].tp == Multi && parse[top - 1].tp == Number)
                multi();
            if (parse[top - 2].tp == Div && parse[top - 1].tp == Number)
                div();
//            debug::print_parse();
        }

        if (top == 1)
            return parse[0].val;
        return 0.0;
    }
}
