#include "debug.h"

namespace debug {
    void print_parse()
    {
        for (int i = 0; i < top; i++)
            std::cout<< "Parse: "<< parse[i].tp<< ", "<< parse[i].val.real<< "d"<< parse[i].val.img<< std::endl;
        std::cout<< std::endl;
    }
    void print_block()
    {
        for (size_t i = 0; i < block.size(); i++)
            std::cout<< "Block: "<< block[i]<< std::endl;
    }

    void print_static_parse()
    {
        for (size_t i = 0; i < block.size(); i++) {
            std::cout<< data::node_type_s(dependency::types_s(block[i]))<< ", "<< block[i]<< std::endl;
        }
    }
    void print_table()
    {
        std::map<std::string, complex>::iterator iter;
        for (iter = table.begin(); iter != table.end(); iter++)
            std::cout<< iter->first<< " -> "<< iter->second.real<< "d"<< iter->second.img<< std::endl;
    }
    void test_complex()
    {
        complex a, b;
        a.real = 2;
        a.img = -2;
        b.real = 1;
        b.img = -1;
        dependency::print_complex(a / b);
    }
}
