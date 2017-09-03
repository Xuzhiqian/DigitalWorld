#ifndef CONFIG_H
#define CONFIG_H

namespace config {
    extern const char *world_dir;
    extern const char *entity_dir;

    extern const int initial_energy;
    extern const int update_cost;
    extern int move_cost(int dh);
};

#endif
