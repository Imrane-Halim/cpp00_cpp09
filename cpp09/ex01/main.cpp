#include "RPN.hpp"

void    performOP(char op, std::stack<float>& stk)
{
    if (stk.size() < 2) // return;
        throw(std::runtime_error("Invalid expression"));

    float a = stk.top(); stk.pop();
    float b = stk.top(); stk.pop();

    switch (op) {
    case '+': stk.push(b + a); break;
    case '-': stk.push(b - a); break;
    case '*': stk.push(b * a); break;
    case '/':
        if (a == 0)
            throw(std::runtime_error("division by 0"));
        stk.push(b / a);
        break;
    }
}

float   solve(std::stringstream& ss)
{
    std::string       tkn;
    std::stack<float> stk;
    char*             end;
    int               tmp;

    while (ss >> tkn)
    {
        tmp = strtol(tkn.c_str(), &end, 10);
        if (tmp >= 0 && tmp <= 9 && *end == '\0')
            stk.push(tkn[0] - '0');
        else if (tkn.length() == 1 && strchr("/*-+", tkn[0]))
            performOP(tkn[0], stk);
        else
            throw(std::runtime_error("Invalid token: " + tkn));
    }

    if (stk.size() != 1)
        throw(std::runtime_error("Invalid expression"));

    return stk.top();
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./RPN <exprestion>\n";
        return EXIT_FAILURE;
    }

    try
    {
        std::stringstream ss(av[1]);
        std::cout << solve(ss) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}