#include <iostream>
#include <queue>
#include <algorithm>

#include "../agents/agent_interface.h"


class Swarm
{

private:

    std::vector<AgentBase*> agents; // Вектор всех агентов в рое

public:

    // Добавление агента в рой
    AgentBase* addAgent (const char* name);

    // Добавление ребра между двумя узлами
    void addEdge (AgentBase* agent1, AgentBase* agent2);

    // Удаление ребра между двумя узлами
    void removeEdge (AgentBase* agent1, AgentBase* agent2);

    // Поиск узла по данным (если необходимо)
    AgentBase* findAgent (int data);

    // Вывод графа (со списком соседей для каждого узла)
    void printSwarm ();

    // Поиск в ширину (BFS)
    void BFS (AgentBase* startAgent);

    // Деструктор для освобождения памяти
    ~Swarm ();
};
