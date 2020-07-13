#!/bin/bash

meson --prefix $PWD/_install _build
ninja -C _build all install
XDG_DATA_DIRS=_install/share:$XDG_DATA_DIRS ./_install/bin/simple-scan
