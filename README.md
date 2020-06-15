# suckless-software
My builds of suckless software (https://suckless.org)
  - dwm
  - dmenu
  - slock
  - st (not yet)
  - dwmblocks (not yet)

Patching is done via the "flexipatch" system from https://github.com/bakkeby

## Installation

Clone this repository with something like:

git clone --recursive https://github.com/gx2b/suckless-software.git


You can find the selected patches and my config.h in the config directory.
There is a very simple build.sh script which builds everything and does the installation (this should be probably replaced with a proper Makefile).
