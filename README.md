# SquigPipe
An open source remote memory tool.

## Table of Contents
- [Compiling](#compiling)
- [Installation](#installation)
- [Resources](#resources)
- [Requirements](#requirements)
- [License](#license)

## Compiling
To compile SquigPipe, you'll need the MSVC compiler. To anyone familiar with MSVC, compilation is straight forward, you just need to run the ```.\build.bat``` file in your developer command prompt from visual studio 2019.
If you want to compile from source, locate the downloaded directory's ```.\src``` folder, and run the following command.

```bash
cl .\main.c /FC /Zi /MDd /nologo user32.lib gdi32.lib kernel32.lib comdlg32.lib Comctl32.lib
```

You can also directly compile all the sources into object files and link them together to an executable using the ```link``` tool from visual studio 2019.

## Installation
For a better experience, you should add the executable to your enviroment's path variable. You can also use the ```.\Squig Installer.exe``` if you don't want to compile it yourself. 

## Requirements
You are required to own an AMD64 Windows 11 machine, with visual studio 2019 installed for the necessary command line tools used in this project.

## License
SquigPipe is licensed under the terms of the GNU General Public License v3.0, for further information read ```LICENSE.txt```.