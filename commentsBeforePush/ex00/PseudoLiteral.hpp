#ifndef PSEUDOLITERAL_HPP
#define PSEUDOLITERAL_HPP  
#include <string.h>
#include "ScalarConverter.hpp"
    class pseudoLiteral : public ScalarConverter {
    public:
        static bool         is_pseudo(const std::string input);
        static void         print_pseudo(std::string input);
    };

#endif