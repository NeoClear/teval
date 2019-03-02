#include <bits/stdc++.h>
#include <algorithm>
#include "data.h"
#include "pre_build.h"
#include "core.h"
#include "dependency.h"
#include "debug.h"

using namespace std;

char *read(char *file)
{
    char *tmp = static_cast<char *>(malloc(sizeof(char) * inf));
    FILE *pf = fopen(file, "r");
    fseek(pf, 0, SEEK_END);
    size_t ls = static_cast<size_t>(ftell(pf));
    rewind(pf);
    fread(tmp, sizeof(char), ls, pf);
    tmp[ls] = '\0';
    return tmp;
}

inline void repl()
{
    i64 flag = 0;
    char cache[inf];
    while (++flag) {
        printf("Please insert your formulae > ");
        init::reset();
        gets(cache);
        if (strcmp(cache, ":quit") == 0 || strcmp(cache, ":q") == 0)
            return;
        else if (strcmp(cache, ":p") == 0 || strcmp(cache, ":print") == 0)
            debug::print_table();

        init::set_src(cache);
        pre_build::gen();
        core::eval();
//        debug::print_static_parse();
        if (update_regis)
            cout<< regis<< endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            init::reset();
            init::set_src(read(argv[i]));
            pre_build::gen();
            core::eval();
        }
        return 0;
    }
    repl();
    return 0;
}
