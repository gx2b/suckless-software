# suckless-software-builder
Automates patching and building of:
  - dwm
  - dmenu
  - slock
  - st (not yet)
  - dwmblocks (not yet)

See also: (https://suckless.org)
 
Patching is done via the "flexipatch" system from https://github.com/bakkeby

## Howto

1. Clone all repositories: git clone --recursive https://github.com/gx2b/suckless-software.git
2. Copy the patches from config/{dwm,slock,st,dmenu}/patches.h into the corresponding repositories
3. Apply flexipatch-finalizer.sh
4. Copy the remaining files from the config directory into the created build
5. make
6. sudo make install



