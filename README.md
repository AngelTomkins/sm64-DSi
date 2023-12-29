# Super Mario 64 DSi

### Overview
This is a port of the Super Mario 64 decompilation project for the Nintendo DSi. It is the original N64 game, and not
the DS remake. It features rendering and audio code written specifically for the hardware in order to achieve good
performance. The DSi's higher CPU speed and larger RAM are required, so original DS models are unsupported.

### Downloads
Assets extracted from a legal copy of Super Mario 64 are required to build this, so downloads can't be provided. You'll
have to build it yourself; the process should be straightforward, but some technical knowledge is required.

### Building
**Docker (All Platforms):**
* Install [Docker Desktop](https://www.docker.com/get-started) and reboot your computer
* Download [the source code](https://github.com/Hydr8gon/sm64/archive/nds.zip) and extract it somewhere
* Rename an unmodified SM64 US ROM to `baserom.us.z64` and place it in the extracted folder
* Run the build script in the same folder
  * On Windows, find `build_docker.bat` and double-click it
  * On macOS/Linux, run `chmod +x build_docker.sh && ./build_docker.sh` from the terminal
* Once the build is complete, open the `build/us_nds` folder to find `sm64.us.nds`

**Linux:**
* Install [devkitPro](https://devkitpro.org/wiki/Getting_Started) and its `nds-dev` package
* Install tools according to your distro
  * Debian/Ubuntu: `sudo apt install -y build-essential git python sox`
  * Fedora: `sudo dnf install gcc make git python sox`
  * Arch/derivatives: `sudo pacman -S base-devel git python sox`
* Download the source code by running `git clone https://github.com/Hydr8gon/sm64.git`
* Rename an unmodified SM64 US ROM to `baserom.us.z64` and place it in the `sm64` folder
* Run `cd sm64 && make -j$(nproc)` to start building
* Once the build is complete, open the `build/us_nds` folder to find `sm64.us.nds`

### Contributing
Pull requests may be accepted, but reviewing them isn't a priority. Larger changes might be rewritten or implemented
differently. If you have a change in mind, consider bringing it up on Discord or opening an issue for discussion.

### Other Links
* [Hydra's Lair](https://hydr8gon.github.io) - Blog where I may or may not write about things
* [Discord Server](https://discord.gg/JbNz7y4) - A place to chat about my projects and stuff
