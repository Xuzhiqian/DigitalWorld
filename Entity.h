#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    public:
        Entity(const char *name);
        ~Entity();
        void Act();
    private:
        int energy;
}

#endif
