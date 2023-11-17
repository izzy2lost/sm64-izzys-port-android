*****Note that termux only makes a build based off the device it's made with. So a 32 bit device will only make a build compatible with 32 bit. The same with a 64 bit device. It will only make a 64 bit compatible build*****

1. Get termux from f-droid https://f-droid.org/packages/com.termux/

2. Install termux and run the commands:
   ```pkg update``` & ```pkg upgrade```

You will get the following message multiple times:
![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/4b40f690-143d-41ac-90f3-9cc543a856ff)

Press the capital I followed by enter each time it asks you.

3. Add the following repo:
   
   ```pkg install x11-repo```
   
4. Give Termux storage access:
   
   ```termux-setup-storage```
   
   Click allow if a popup comes up.
   
5. Install the following:
   
   ```pkg install mesa-dev binutils git wget make python getconf zip apksigner clang```

6. Clone this repo:

   ```git clone https://github.com/izzy2fancy/sm64-izzys-port-android```

7. Now we need to put your Super Mario US rom in the root of the "sm64-izzys-port-android" folder. Which is inside Termux. The rom needs to be named "baserom.us.z64" We could use command prompt, but in this example we are going to use the Material Files app to get access to the Termux files.

    Get the Material Files app below:

<a href='https://play.google.com/store/apps/details?id=me.zhanghai.android.files&pcampaignid=pcampaignidMKT-Other-global-all-co-prtnr-py-PartBadge-Mar2515-1'><img alt='Get it on Google Play' src='https://play.google.com/intl/en_us/badges/static/images/badges/en_badge_web_generic.png'/></a>

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/2896f300-3bcb-42e0-97b5-316fc8152354)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/7bb03db5-ea09-4c43-9602-f6df39a95e1a)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/84ccb53c-19be-4843-9200-e1a1745908f5)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/f8182608-86ff-4a3c-af24-528f4c8f50c3)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/f0c39c97-c562-44f9-9ec9-7d3d503ef6f6)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/de93725b-5f98-404a-8844-f527325fba85)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/77b74f62-0480-48f3-a395-69fab1598d47)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/6a64efc9-8bd2-4b38-bbbe-2db163c62b12)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/0dab6c82-66c5-420f-9bbe-79447a7cfc9f)

![image](https://github.com/izzy2fancy/sm64-izzys-port-android/assets/121840901/00e3c958-2561-4ab1-b51e-04365499e396)

