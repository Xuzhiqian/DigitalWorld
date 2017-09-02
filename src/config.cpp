#include "config.h"

const char *config::world_dir =  "./world/";
const char *config::entity_dir = "./entity/";

const int config::initial_energy = 100;
const int config::update_cost = 1;

extern int config::move_cost(int dh) {
    int tmp = dh>0?dh:(-dh);
    return tmp*tmp + 2;
}
