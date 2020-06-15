#!/bin/bash

[ ! -d build ] && mkdir build

#[ ! -d dwm-flexipatch ] && git submodule add https://github.com/bakkeby/dwm-flexipatch.git dwm-flexipatch
#[ ! -d slock-flexipatch ] && git submodule add https://github.com/bakkeby/slock-flexipatch.git slock-flexipatch
#[ ! -d dmenu-flexipatch ] && git submodule add https://github.com/bakkeby/dmenu-flexipatch.git dmenu-flexipatch
#[ ! -d flexipatch-finalizer ] && git submodule add https://github.com/bakkeby/flexipatch-finalizer.git flexipatch-finalizer

for p in dwm slock dmenu
do
    echo "--------- Build $p ---------"
    [ -f config/$p/patches.h ] && cp config/$p/patches.h $p-flexipatch
    flexipatch-finalizer/flexipatch-finalizer.sh -r -d $p-flexipatch -o build/$p
    [ -f config/$p/config.h ] && cp config/$p/config.h build/$p/
    [ -f config/$p/config.mk ] && cp config/$p/config.mk build/$p/
    [ -f config/$p/Makefile ] && cp config/$p/Makefile build/$p/
    cd build/$p
    make
    [ $? -eq 0 ] && sudo make install
    cd ../..
done

exit 0
