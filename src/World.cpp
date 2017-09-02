#include <dlfcn.h>

#include "World.h"
#include "Action.h"
#include "config.h"
#include "utils.h"

World::World(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(World&))dlsym(handle, "init");
    update = (void(*)(World&))dlsym(handle, "update");
    if (!init || !update) {
        crash("invalid shared library for world");
    }
    init(*this); }

World::~World() {
}

void World::Update() {
    update(*this);
    for (auto &e: entities) {
        if (e.energy <= 0) continue;
        e.energy -= config::update_cost;
        Action action = e.Act();
        TakeAction(e, action);
    }
    log("world updated");
}

int World::CreateEntity(const char *name) {
    Entity entity(name);
    int x, y;
    do {
        x = rand()%sizeX;
        y = rand()%sizeY;
    } while(grids[x][y].occupied);
    grids[x][y].occupied = true;
    entity.SetPosi(x, y);
   
    entity.energy = config::initial_energy;
    entity.SenseEnergy = [this](int x, int y){ return this->GetEnergy(x, y); };

    entities.push_back(entity);
}

void World::TakeAction(Entity &entity, Action action) {
    switch(action.type) {
        case Move:
            switch(action.param.direction) {
                case Up:
                    TakeActionMove(entity, 0, 1);
                    break;
                case Down:
                    TakeActionMove(entity, 0, -1);
                    break;
                case Left:
                    TakeActionMove(entity, -1, 0);
                    break;
                case Right:
                    TakeActionMove(entity, 1, 0);
                    break;
            }
            break;
        case Eat:
            TakeActionEat(entity);
            break;
    }
}

void World::TakeActionMove(Entity &entity, int dx, int dy) {
    int tx = entity.posiX + dx;
    int ty = entity.posiY + dy;
    if (0 <= tx && tx < sizeX
            && 0 <= ty && ty < sizeY
            && !grids[tx][ty].occupied) {
        grids[tx][ty].occupied = true;
        grids[entity.posiX][entity.posiY].occupied = false;
        entity.energy -= config::move_cost(grids[tx][ty].height - grids[entity.posiX][entity.posiY].height);
        entity.SetPosi(tx, ty);
    }
}

void World::TakeActionEat(Entity &entity) {
    std::cout << "!!!!" << grids[entity.posiX][entity.posiY].energy << endl;
    entity.energy += grids[entity.posiX][entity.posiY].energy;
    grids[entity.posiX][entity.posiY].energy = 0;
    std::cout << "!!!!" <<  grids[entity.posiX][entity.posiY].energy<< endl;
}

void World::SetSize(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    grids = vector< vector< Grid > >(sizeX, vector<Grid>(sizeY));
}

void World::SetHeight(int x, int y, int h) {
    grids[x][y].height = h;
}

void World::SetEnergy(int x, int y, int e) {
    grids[x][y].energy = e;
}

void World::GetSize(int &sizeX, int &sizeY) const {
    sizeX = this->sizeX;
    sizeY = this->sizeY;
}

int World::GetHeight(int x, int y) const {
    return grids[x][y].height;
}

int World::GetEnergy(int x, int y) const {
    return grids[x][y].energy;
}

const vector< Entity > & World::GetEntities() const{
    return entities;
}

bool World::IsOccupied(int x, int y) const {
    return grids[x][y].occupied;
}
