/*
 * This file contains patch control flags.
 *
 * In principle you should be able to mix and match any patches
 * you may want. In cases where patches are logically incompatible
 * one patch may take precedence over the other as noted in the
 * relevant descriptions.
 */

/* Patches */

/* This patch introduces an additional color to indicate the state of Caps Lock.
 * https://tools.suckless.org/slock/patches/capscolor/
 */
#define CAPSCOLOR_PATCH 1

/* Adds an additional configuration parameter, controlkeyclear. When set to 1, slock will no
 * longer change to the failure color if a control key is pressed while the buffer is empty.
 * This may be useful if, for example, you wake your monitor up by pressing a control key
 * and don't want to spoil the detection of failed unlocking attempts.
 * https://tools.suckless.org/slock/patches/control-clear/
 */
#define CONTROLCLEAR_PATCH 1

/* This patch interacts with the Display Power Signaling and automatically shuts down
* the monitor after a configurable amount of seconds.
* The monitor will automatically be activated by pressing a key or moving the mouse
* and the password can be entered then.
* https://tools.suckless.org/slock/patches/dpms/
*/
#define DPMS_PATCH 0

/* This patch allows media keys to be used while the screen is locked. Allows for volume
 * to be adjusted or to skip to the next song without having to unlock the screen first.
 * https://tools.suckless.org/slock/patches/mediakeys/
 */
#define MEDIAKEYS_PATCH 0

/* This patch lets you add a message to your lock screen. You can place a default message
 * in config.h and you can also pass a message with the -m command line option.
 * If you enable this then you also need to add the -lXinerama library to the LIBS
 * configuration in config.mk. Look for and uncomment the XINERAMA placeholder.
 * https://tools.suckless.org/slock/patches/message/
 */
#define MESSAGE_PATCH 0

/* Replaces shadow support with PAM authentication support.
 * Change variable pam_service in config.def.h to the corresponding PAM service.
 * The default configuration is for ArchLinux's login service.
 * If you enable this then you also need to add the -lpam library to the LIBS configuration
 * in config.mk. Look for and uncomment the PAM placeholder.
 * https://tools.suckless.org/slock/patches/pam_auth/
 */
#define PAMAUTH_PATCH 0

/* Cancel slock by moving the mouse within a certain time-period after slock started.
 * The time-period can be defined in seconds with the setting timetocancel in the config.h.
 * This can be useful if you forgot to disable xautolock during an activity that requires
 * no input (e.g. reading text, watching video, etc.).
 * https://tools.suckless.org/slock/patches/quickcancel/
 */
#define QUICKCANCEL_PATCH 0

/* Adds key commands that are commonly used in terminal applications (in particular the
 * login prompt) to slock.
 * https://tools.suckless.org/slock/patches/terminalkeys/
 */
#define TERMINALKEYS_PATCH 0

/* This patch keeps the screen unlocked but keeps the input locked. That is, the screen
 * is not affected by slock, but users will not be able to interact with the X session
 * unless they enter the correct password.
 * https://tools.suckless.org/slock/patches/unlock_screen/
 */
#define UNLOCKSCREEN_PATCH 0

/* This patch adds the ability to get colors via Xresources.
 * https://tools.suckless.org/slock/patches/xresources/
 */
#define XRESOURCES_PATCH 0
