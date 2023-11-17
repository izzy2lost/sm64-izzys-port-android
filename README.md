*****Note that termux only makes a build based off the device it's made with. So a 32 bit device will only make a build compatible with 32 bit. The same with a 64 bit device. It will only make a 64 bit compatible build*****

1. Get termux from f-droid https://f-droid.org/packages/com.termux/

2. Install termux and run the commands:
   ```pkg update``` & ```pkg upgrade```

You will get the following message multiple times:
![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/4b40f690-143d-41ac-90f3-9cc543a856ff)

Press the capital I followed by enter each time it asks you.

3. Add the following repo:
   
   ```pkg install x11-repo```
   
5. Give Termux storage access:
   
   ```termux-setup-storage```
   Click allow if a popup comes up.
   
6. Install the following:
   
   ```pkg install mesa mesa-dev binutils git wget make python getconf zip apksigner clang```

7. Do the following just in case:
   
   ```pkg remove libglvnd
pkg install git wget make python getconf zip \
apksigner clang binutils libglvnd-dev aapt which```

7. 




