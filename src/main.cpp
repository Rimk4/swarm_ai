#include <iostream>

#include "agents/agents.h"
#include "swarm/swarm.h"


int main ()
{
    Swarm swarm;

    AgentBase* agent0 = swarm.addAgent ("a0");
    agent0->setData (0);
    AgentBase* agent1 = swarm.addAgent ("a1");
    agent1->setData (1);
    AgentBase* agent2 = swarm.addAgent ("a2");
    agent2->setData (2);
    AgentBase* agent3 = swarm.addAgent ("a3");
    agent3->setData (3);

    swarm.addEdge (agent0, agent1);
    swarm.addEdge (agent0, agent2);
    swarm.addEdge (agent1, agent3);

    std::cout << "Swarm adjacency list:" << std::endl;
    swarm.printSwarm ();

    std::cout << "BFS traversal starting from agent " << agent0->getName () << ":" << std::endl;
    swarm.BFS (agent0);

    swarm.removeEdge (agent0, agent1);
    std::cout << "Swarm adjacency list after removing edge (" << agent0->getName () << "," << agent1->getName () << "):" << std::endl;
    swarm.printSwarm ();

    return 0;
}

