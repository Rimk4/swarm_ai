#pragma once

#include <vector>


/**
 * @brief Определение интерфейса AgentInterface
 */
class AgentInterface
{

public:

    virtual ~AgentInterface () {}

    /**
     * @brief Обработка данных
     */
    virtual void* process (int input_data) = 0;
};

/**
 * @brief Базовый класс для агентов, реализующий AgentInterface.
 */
class AgentBase : public AgentInterface
{
    const char* name;
    int data; // Данные, хранящиеся в узле
    std::vector<AgentBase*> neighbors; // Вектор указателей на соседние узлы

public:

    inline int getData () const { return data; }
    inline void setData (int data) { this->data = data; }
    inline const char* getName () const { return name; }
    inline std::vector<AgentBase*>& getNeighbors () { return neighbors; }
    AgentBase (const char* name) : name (name) {}

    // Важно: нужно переопределить виртуальную функцию process
    void* process (int input_data) override
    {
        // Здесь должна быть ваша логика обработки данных
        // По умолчанию возвращает nullptr
        return nullptr;
    }
};
