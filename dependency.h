﻿#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "data.h"
#include <bits/stdc++.h>

namespace dependency {
    bool isOperator(node_type n);

    bool isParenthesis(node_type n);
    bool isFormula(node_type n);
    node_type types(char c);

    node_type types_s(std::string s);

    complex read_complex(const char *s);
    void print_complex(complex x);
}

#endif // DEPENDENCY_H
