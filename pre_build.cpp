#include "pre_build.h"

namespace pre_build {
    void reduce()
    {
        for (std::vector<std::string>::iterator i = block.begin(); i != block.end();) {
            node_type cur = dependency::types_s(*i);
            if (cur == Default) {
                block.erase(i);
                continue;
            } else if (dependency::isFormula(cur) && (i == block.begin() || !dependency::isFormula(dependency::types_s(*(i - 1))))) {
                block.insert(i, "(");
                i++;
            } else if (dependency::isFormula(cur) && (i + 1 == block.end() || !dependency::isFormula(dependency::types_s(*(i + 1))))) {
                i++;
                block.insert(i, ")");
                i++;
            } else {
                i++;
            }
        }
    }
    void gen()
    {
        std::vector<size_t> split;
        split.push_back(0);
        for (size_t i = 0; i < src.size(); i++) {
            node_type cur_t = dependency::types(src[i]);
            if (cur_t != dependency::types(src[i + 1])) {
                if (cur_t == Minus) {
                    if (i == 0 || dependency::types(src[i - 1]) != Number)
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
        reduce();
//        debug::print_block();
    }

}

