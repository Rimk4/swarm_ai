#include <iostream>

#include "agents.h"


void* IncrementAgent::process (int input_data)
{
    int result = input_data + 1;
    std::cout << "IncrementAgent processed input " << input_data << " to " << result << std::endl;

    return nullptr;
}

void* DoubleAgent::process (int input_data)
{
    int result = input_data * 2;
    std::cout << "DoubleAgent processed input " << input_data << " to " << result << std::endl;

    return nullptr;
}

void* AgentC::process (int input_data)
{
    int result = input_data - 3;
    std::cout << "AgentC processed input " << input_data << " to " << result << std::endl;

    return nullptr;
}
