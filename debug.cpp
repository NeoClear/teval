#include "debug.h"

namespace debug {
    void print_parse()
    {
        for (int i = 0; i < top; i++)
            std::cout<< "Parse: "<< parse[i].tp<< ", "<< parse[i].val<< std::endl;
        std::cout<< std::endl;
    }
    void print_block()
    {
        for (size_t i = 0; i < block.size(); i++)
            std::cout<< "Block: "<< block[i]<< std::endl;
    }
}
