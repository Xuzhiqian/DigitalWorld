"""Configuration such as initial energy."""


import utils


height_aprox = 255
energy_aprox = 255


def initial_energy():
    return 100


def energy_cost_height(dh):
    return abs(dh)

energy_cost_per_update = 2

default_call_time_limit = 2


def limit_call_times(f):
    def wrapper(*args, **kwargs):
        en = kwargs['en']
        if en.call_time_limit <= 0:
            return
        en.call_time_limit -= 1
        f(*args, **kwargs)
    return wrapper
