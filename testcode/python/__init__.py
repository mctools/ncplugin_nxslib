try:
    from ._cmakeinfo import ncplugin_name as _name
except ImportError:
    raise ImportError("Could not import . _cmakeinfo (you should first install with CMake before running)")
from .cbindings import hooks as _hooks
import numpy as np
import random
random.seed(123456)#reproducible random streams

def registerPlugin():
    """Activate the plugin by registering with NCrystal."""
    import NCrystal#Make sure NCrystal is loaded first
    _hooks['ncplugin_register']()

def pluginName():
    return _name

