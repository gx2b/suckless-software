#!/bin/bash

# build "dwm" "slock" "dmenu" "st"
# needs the patchfiles from mkpatch.sh
#
#  -i : install with "sudo make install" (if make returned 0)
#
# Examples:
#   ./mkbuild.sh -i  dmenu slock     : build and install "dmenu" and "slock"
#   ./mkbuild.sh                     : build "dwm" "slock" "dmenu" "st"

TEMPDIR=$(mktemp -d /tmp/suckless-build2.XXXXXXX)

install=0
while getopts i name
do
    case $name in
    i)    install=1;;
    esac
done
shift $(($OPTIND - 1))


dest=$*
[ -z $dest ] && dest="dwm slock dmenu st"

for p in $dest
do
    echo "--------- Build $p ---------"
    [ -f config/$p/p1/patches.h ] && cp config/$p/p1/patches.h $p-flexipatch
    flexipatch-finalizer/flexipatch-finalizer.sh -r -d $p-flexipatch -o $TEMPDIR/$p

    patchfile=$(pwd)/patch/$p.patch
    if [ -f $patchfile ] ; then
        (
        cd $TEMPDIR/$p
        patch -p 5 < $patchfile
        make
        [ $? -eq 0 -a $install -eq 1 ] && sudo make install
        )
    fi

done

echo "============================================"
echo "Final build is in ${TEMPDIR}"

exit 0
