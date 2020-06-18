#!/bin/bash

TEMPDIR=$(mktemp -d /tmp/suckless-build1.XXXXXXX)
BUILD1=$TEMPDIR/p1
BUILD2=$TEMPDIR/p2

mkdir -p $BUILD1 $BUILD2

if [ -d patch ]; then
    rm patch/*.patch >/dev/null
else
    mkdir patch
fi

for p in dwm slock dmenu st
do
    echo "--------- Patch $p ---------"
    echo "*** P1 ***"
    [ -f config/$p/p1/patches.h ] && cp config/$p/p1/patches.h $p-flexipatch
    flexipatch-finalizer/flexipatch-finalizer.sh -r -d $p-flexipatch -o $BUILD1/$p

    echo "*** P2 ***"
    flexipatch-finalizer/flexipatch-finalizer.sh -r -d $p-flexipatch -o $BUILD2/$p
    ( cd config/$p/p2 ; find . | cpio -pdumv $BUILD2/$p )

    diff -Ncr $BUILD1/$p $BUILD2/$p > patch/$p.patch
done

echo "============================================"
echo "Temp directory can be removed: ${TEMPDIR}"

exit 0
