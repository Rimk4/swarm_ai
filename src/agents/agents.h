#include "agent_interface.h"


class IncrementAgent : public AgentBase
{

public:
    
    void* process (int input_data) override;
};

class DoubleAgent : public AgentBase
{

public:
    
    void* process (int input_data) override;
};

class AgentC : public AgentBase
{

public:

    void* process (int input_data) override;
};
