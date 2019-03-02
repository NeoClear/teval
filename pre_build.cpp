#include "pre_build.h"

namespace pre_build {
    void gen()
    {
        src.insert(src.begin(), '(');
        src.push_back(')');
        std::vector<size_t> split;
        split.push_back(0);
        for (size_t i = 0; i < src.size(); i++) {
            node_type cur_t = dependency::types(src.c_str()[i]);
            if (cur_t != dependency::types(src.c_str()[i + 1])) {
                if (cur_t == Minus) {
                    if (i == 0 || dependency::types(src[i - 1]) == LParenthesis)
                        continue;
                    split.push_back(i + 1);
                } else {
                    split.push_back(i + 1);
                }
            } else {
                if (dependency::isOperator(cur_t) || dependency::isParenthesis(cur_t))
                    split.push_back(i + 1);
            }
        }
        for (size_t i = 0; i < split.size() - 1; i++) {
            block.push_back(src.substr(split[i], split[i + 1] - split[i]));
        }
    //    for (size_t i = 0; i < block.size(); i++)
    //        cout<< block[i]<< endl;
    }
}

