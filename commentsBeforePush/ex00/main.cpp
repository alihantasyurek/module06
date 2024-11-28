#include "ScalarConverter.hpp"
#include "PseudoLiteral.hpp"

bool isAllNum(char* input)
{
    char *end;
    std::strtod(input, &end);
    return (end != input && *end == '\0') ||
           ((*end == 'f' || *end == 'F') && *(end + 1) == '\0'); 
    //end != input 1 verdin end'in null'a ilerlemis olmasi gerekli && *end == '\0' 12a almasin diye sonu f olabilir floating oldugundan end + 1 == '\0' checki sonunda fffff spamlemmesin diye
}

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "This function expects exactly one argument!" << std::endl;

    else if(std::string(argv[1]).length() == 1 || isAllNum(argv[1]) || pseudoLiteral::is_pseudo(argv[1]))
            ScalarConverter::convert(argv[1]);
    else
            std::cout << "Argument is undefined!" << std::endl;
    return 0;
}