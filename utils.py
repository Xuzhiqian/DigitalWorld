"""This part provides convenient utilities for developing and debugging.

"""

import sys
from PyQt5 import QtWidgets


def warn(message):
    print('!', message, file=sys.stderr)
