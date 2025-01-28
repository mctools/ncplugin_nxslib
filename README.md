NCrystal legacy plugin for loading .nxs files
=============================================

This repository includes a plugin for
[NCrystal](https://github.com/mctools/ncrystal/wiki) which can be used to load
the .nxs files associated with
[nxslib](http://dx.doi.org/10.1107/S0021889812016056). Before NCrystal release
v3.0.0, this plugin was included directly in the main NCrystal release. However,
as the .nxs loading relies on 3rd party libraries under licenses (see the
[LICENSE](LICENSE) file) different from the main NCrystal license (which is the
Apache-2.0 license), it was removed from the main NCrystal release and kept here
as an optional standalone plugin for anyone needing it and willing to abide by
those additional license terms.

Requiring NCrystal 4.0.0 or later, the plugin can most easily be installated by
pip installing it into an active virtual conda or Python environment (if you are
using a conda environment, it is best if you *first* install the `ncrystal`
conda package, to avoid mixing up conda and pip packages more than necessary):

```
python3 -mpip install git+https://github.com/mctools/ncplugin_nxslib.git
```
