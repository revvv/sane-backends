### SANE scanner driver for Canon CanoScan LiDE 20 on Windows 10 64 bit
* Motivation: Canon does not provide a 64 bit driver
* Tested with CanoScan N670/676U/LiDE20 (Plustek chip: `VID = 04A9 PID = 220D`)
* Compatible with all [Plustek Scanners](http://www.sane-project.org/man/sane-plustek.5.html) (*untested*)

### HOWTO ###
* Connect your scanner
* Install [Zadig USB driver](https://zadig.akeo.ie) (_only required for N670/676U/LiDE20 or if you have no Windows driver for your scanner_)
* Install [cygwin 64 bit](http://cygwin.org): Use defaults and add these packages: **libusb, libjpeg8, libpng16 and zlib**.
* Download my SANE driver from the [release](https://github.com/revvv/sane-backends-cygwin/releases/) area (all files go into one directory)
    1. Execute `setup.bat` to install the cygwin package
    2. Execute `scan.bat` to scan a page with 300dpi

### NOTES ###
* There is no GUI, but you can open a cygwin shell and use the SANE command line tools: `scanimage -L` etc.
* There is no TWAIN interface. You always have to use `scan.bat` or the cygwin shell.

### Sources ###
* Personal fork of [https://gitlab.com/sane-project/backends](https://gitlab.com/sane-project/backends).
* Might become out of sync. Be warned!
* I just wanted to host my cygwin binaries, that's all.

### Disclaimer
This software comes without any warranty. I am not responsible for any damage to your devices.
