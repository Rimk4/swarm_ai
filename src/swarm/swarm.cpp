#include "swarm.h"


AgentBase* Swarm::addAgent (const char* name)
{
    AgentBase* newAgent = new AgentBase (name);
    agents.push_back (newAgent);
    return newAgent;
}

void Swarm::addEdge (AgentBase* agent1, AgentBase* agent2)
{
    agent1->getNeighbors ().push_back (agent2);
    agent2->getNeighbors ().push_back (agent1);
}

void Swarm::removeEdge (AgentBase* agent1, AgentBase* agent2)
{
    // Удаляем agent2 из списка соседей agent1
    auto it1 = std::find (agent1->getNeighbors ().begin (), agent1->getNeighbors ().end (), agent2);
    if (it1 != agent1->getNeighbors ().end ())
    {
        agent1->getNeighbors ().erase (it1);
    }

    // Удаляем agent1 из списка соседей agent2 (для неориентированного графа)
    auto it2 = std::find (agent2->getNeighbors ().begin (), agent2->getNeighbors ().end (), agent1);
    if (it2 != agent2->getNeighbors ().end ())
    {
        agent2->getNeighbors ().erase (it2);
    }
}

AgentBase* Swarm::findAgent (int data)
{
    for (AgentBase* agent : agents)
    {
        if (agent->getData () == data)
        {
            return agent;
        }
    }
    return nullptr; // Узел не найден
}

void Swarm::printSwarm ()
{
    for (AgentBase* agent : agents)
    {
        std::cout << agent->getName () << ": ";
        for (AgentBase* neighbor : agent->getNeighbors ())
        {
            std::cout << neighbor->getName () << " ";
        }
        std::cout << std::endl;
    }
}

void Swarm::BFS (AgentBase* startAgent)
{
    std::vector<AgentBase*> visited;
    std::queue<AgentBase*> queue;

    visited.push_back (startAgent);
    queue.push (startAgent);

    while (!queue.empty ())
    {
        AgentBase* current = queue.front ();
        std::cout << current->getName () << " ";
        queue.pop ();

        for (AgentBase* neighbor : current->getNeighbors ())
        {
            if (std::find (visited.begin (), visited.end (), neighbor) == visited.end ())
            {
                visited.push_back (neighbor);
                queue.push (neighbor);
            }
        }
    }
    std::cout << std::endl;
}

Swarm::~Swarm ()
{
    for (AgentBase* agent : agents)
    {
        delete agent;
    }
}
