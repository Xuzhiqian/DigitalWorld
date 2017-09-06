"""Configuration such as initial energy."""


height_aprox = 255
energy_aprox = 255


def initial_energy():
    return 2500


def energy_cost_height(h):
    return (h*h+1) if h >= 0 else int(0.5*h*h+1)

energy_cost_per_update = 10
