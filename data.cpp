#include "data.h"

std::string src;
std::vector<std::string> block;

node parse[inf];
long top = 0;

namespace init {
    void set_src(char *s)
    {
        src = std::string(s);
    }

    void reset()
    {
        src.clear();
        block.clear();
        memset(parse, 0, sizeof(parse));
        top = 0;
    }

}

