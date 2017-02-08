USBqemu-wheel
=============


[![Build status](https://ci.appveyor.com/api/projects/status/tg69jfcw5lllu8kl?svg=true)](https://ci.appveyor.com/project/jackun/USBqemu-wheel/branch/master)


PCSX2 usb plugin based on linuzappz, shadow, gigaherz et al. usb plugin using usb host emulation code from qemu.

USB packets with FFB commands are passed staight to the wheel when using raw input API mode.
As they are pretty much vendor specific, force feedback probably works with Logitech wheels only.

As such, DInput (DirectX) mode is recommended.

Linux note: if joystick is type of "gamepad" (xbox etc) then analog sticks/buttons should work mostly out-of-the-box.
No rumble effect though yet. Also axis input is (too) linear so steering is a little _spazzy_.

For info about Logitech's FF protocol, go to https://opensource.logitech.com/opensource/index.php/Technical_Information

Mass storage device
=======

Now includes preliminary support for usb mass storage devices. Create a image file and format it.
http://www.fysnet.net/mtools.htm or http://www.ltr-data.se/opencode.html/ might be of some help to windows users.

A 256MB and 4GB image file is included in `dist` folder.
You should be able to access files in image file with 7-zip ( http://7-zip.org/ ).

On linux:

	truncate -s 256M usb.img
	mkfs.vfat -F 32 usb.img
	
Optionally mount image for file transfer:

	losetup -f usb.img
	mount /dev/loopX /mnt #or somewhere else

or let `mount` automagically set up a loopback device:

	mount usb.img /mnt
	
Of course, if a PS2 game/program itself can format a drive then you can just use some random file, heh.

Singstar
========

You can use 2 mono/stereo mics or one stereo mic with separate per-channel input (select same microphone for both players; left channel = P1, right channel = P2).

Windows: Uses Core Audio API. As such, it needs Vista or newer.

Linux: PulseAudio only for now atleast.


Building
==========

Basically:

	cd some/where/USBqemu-wheel
	mkdir build
	cd build
	cmake ..

CMake defines:

* `PLUGIN_BUILD_RAW` (bool, TRUE) for raw api (windows)
* `PLUGIN_BUILD_DX` (bool, TRUE) for dinput (windows)
* `PLUGIN_BUILD_PULSE` (bool, TRUE) for PulseAudio (singstar) (linux)
* `PLUGIN_BUILD_DYNLINK_PULSE` (bool, TRUE) dlopen PulseAudio or link to lib (linux)
* `PLUGIN_BUILD_WITH_DXSDK` (bool, FALSE) build with DX2010 SDK (windows)
* `PLUGIN_FIND_WINSDK` (bool, FALSE) to find newest installed windows platform toolset/sdk. Probably unnecessary when building with Visual Studio. (windows)
* `PLUGIN_ENABLE_UNITY_BUILD` (bool, FALSE) concat source files into one huge one before building, WIP.

DInput should be using Windows platform toolset/sdk now.

Optionally, you can still use 2010 DirectX SDK. CMake looks for %DXSDK_DIR% environment variable.

http://www.microsoft.com/en-us/download/details.aspx?id=6812

Forum
=========
http://forums.pcsx2.net/Thread-Qemu-USB-Wheel-mod

Credits
=========

DirectX version by Racer_S ( http://www.tocaedit.com/ )

Original by linuzappz, shadow, gigaherz, PCSX2 team.
