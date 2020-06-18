# suckless-software-builder
Automates patching and building of:
  - dwm
  - dmenu
  - slock
  - st
  - dwmblocks (not yet)

## Build
 - https://github.com/gx2b/dwm
 - https://github.com/gx2b/dmenu
 - https://github.com/gx2b/slock
 - https://github.com/gx2b/st


## Howto

1. git clone --recursive https://github.com/gx2b/suckless-software-builder.git
2. Select the desired patches: config/{dwm,slock,st,dmenu}/p1/patches.h 
3. Add configuration (config.h etc.) to config/{dwm,slock,st,dmenu}/p2
4. run ./mkpatch.sh
5. check output in the patch/ directory
5. run ./mkbuild.sh [ -i ]
6. check the final build


## Links
- Patching is done via the "flexipatch" system from https://github.com/bakkeby
- Suckless Software: https://suckless.org
- Luke's build: https://github.com/lukesmithxyz
