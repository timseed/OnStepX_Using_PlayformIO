# OnStepX building using PlatformIO

I wanted to build the OnStepX codebase for my FYSTEC-E4 hardware (nothing extra just basic board at the moment), but I do not like using the Arduino IDE, I much prefer PlatformIO ... So this is my version of *how to do this*. 

I used an existing git repo to get me started, [https://github.com/qifeng0419/OnStepX-Platformio.git](https://github.com/qifeng0419/OnStepX-Platformio.git) 

# What changes do you need to make ? 

Well the OnStep code base is not linked in this repo - so any development that occurs there will **NOT** be reflected in this; So assuming you are looking for a generate Goto/nothing special solution, this may be a good place to start. 



## Clone this repo 

    git clone https://github.com/timseed/OnStepX_Using_PlayformIO.git 


## Build Software 

   - Visual Studio Code (it is Free and a very good editor)
     - A C++ compiler 
     - Now add the PlatformIO Extension. For the moment add nothing else to the PlatformIO environment.
      	 

## You need a new Config file 

The file we are talking about is **Config.h** 

The code relies on many *compiler definitions*, think of these as **switches**... i.e. this feature on, or this feature off. 

You can manually set these values, *BUT*.... It is much easier to use this project [https://christm45.github.io/OnStepX-Configurator/](https://christm45.github.io/OnStepX-Configurator/) 

You will need to know some info regarding 

  - Your Stepper motors 
  - Drive Wheel sizes 
  - what board are you using 
  - What Stepper drivers your board uses 

And then you can copy/generate the *Config.h* and replace what is in this repo.


## PlatformIO mods 

Depending on what hardware you are using, you will need to update the platformio.ini file in the OnStepX_Using_PlayformIO folder. 

This is the default GPS configuration, but should you need something different (and we are specifically) talking about the GPS, then this is where you add the configuration 

Original

```ini
; Optional - GPS
gps =
    https://github.com/mikalhart/TinyGPSPlus.git
```

Just add the repo
```ini
; Optional - GPS
gps =
    https://github.com/mikalhart/TinyGPSPlus.git
    https://github.com/SuperGpsMk3/SuperGpsMk3_2.git
```

When platformIO reloads the config, it will fetch this repo, and place it into the ArduinoEnviroment. 

**However** you need to make sure you are building with it ... 

Original

```ini
; Minimal build - core libraries only
lib_deps =
    ${common_libs.core}
```

There is **NO GPS** being used in the link/library phase. So you will get link errors if you turned on GPS Switches in the Config.h. What you need to do is ... 

```ini
; Minimal build - core libraries only
lib_deps =
    ${common_libs.core}
    ${common_libs.gps}
```

You could also add gps to the **core**, it just depends if you are building OnStepX for multiple hardware platforms.

## PlatformIO next steps 

A normal development lifecycle is 

   - Code 
   - build (compile/link)
   - deploy (send to device)
   - run/test 
   
 Just do this using PlatformIO ... 
 
 