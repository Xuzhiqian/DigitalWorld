#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
    public:
        Entity(std::string name);
        ~Entity();
        void Act();
    private:
        int energy;
};

#endif
