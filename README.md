# Computer vision project with CPP and Python for fun

## Event encountered

### 2024-1-17

#### Todo for next step
1. Get a webcam or find out how to connect camera laptop
2. installing usbipd on windows and 
```{bash}
sudo apt install linux-tools-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/*-generic/usbip 20
```  
for wsl2 is ready to follow the instruction.

#### Installing computer vision libraries in WSL2

Installing C/C++ and python
```{bash}
sudo apt-get update && sudo apt-get install build-essential && sudo apt-get install python3
```

Installing OpenCV libraries
```{bash}
sudo apt-get update && sudo apt-get install libopencv-dev
```

#### Issue and solving the library import problem

```{c++}
#include <opencv2/opencv.hpp> // This library was crying that it couldn't find the library.
```
**Solution**: Add snippets as following

```{json}
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${default}",
                "/usr/include/opencv4" // Add this line in c_cpp_properties.json
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```
```{json}
    // Add these lines in settings.json
   
    "C_Cpp.default.includePath": [
        "/usr/include",
        "/usr/lib"
    ],
    "C_Cpp.intelliSenseEngine": "default"
```

#### Connecting USB devices: Using usbipd
install usbipd from https://github.com/dorssel/usbipd-win/releases usbipd-win_*.msi for windows

and followed: ![WSL 2: Connect USB devices](https://www.youtube.com/watch?v=I2jOuLU4o8E&ab_channel=MicrosoftDeveloper)

1. usbipd wsl list $\rightarrow$ usbipd list


Good reference: https://learn.microsoft.com/en-us/windows/wsl/connect-usb

