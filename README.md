# GPS-GSM-Based-Vehicle-Tracking-System
![image](https://github.com/Zeeshanx186/GPS-GSM-Based-Vehicle-Tracking-System/assets/101282364/ac407cce-48eb-44b2-b016-f2fd8a918c37)

# ABSTRACT
The objective of this project is to design and construct a GSM and GPS based advanced vehicle tracking system. In this project, a device was developed that would track and provide complete vehicle location and send the information to a control unit at the user side. This kind of device is able to provide complete location information to user over mobile phone by sending SMS through GSM modem. This SMS contains longitude and latitude of the location of vehicle. Microcontroller is the central processing unit CPU of this project. Microcontroller gets the coordinates from GPS modem and then it sends this information to the user in Text SMS. GSM modem is used to send this information via SMS. 

# OBJECTIVE
Here our objective is to design a GSM based GPS vehicle tracker. So, for that we have to take Arduino of any type, GSM which also can be any type and GPS module with antenna additionally we can also use LCD to show the location in form of latitude and longitude. Initially, when we started working on this project we took Arduino UNO with GSM Sim 7600. But we did not find enough material to complete our task so, we start working sim 900.

# INTRODUCTION
Global System for Mobile Communication (GSM) and Global Positioning System (GPS) based vehicle location and tracking system provided effective, real time vehicle location, mapping and reporting this information value and add by improving this level of service provided. The GPS based vehicle tracking system is designed to find out the exact location of any vehicle and intimate the position to the concerned authority about through an SMS. The system includes a GPS modem that it retrieves the location of a vehicle in terms of its longitude and latitude. The system uses geographic position and time information from the GPS. The system has an onboard module that it resides in the vehicle to be tracked and a based station that monitors data from the various vehicles. The onboard module consists of GPS receiver, a GSM modem. This hardware is fitted on to the vehicle in such a manner that it was not visible to anyone. That system sends the location data to the monitoring unit continuously therefore it is used as a covert unit. The location data from tracking system uses to find the location and to give the information to police when the vehicle is stolen. This gives an edge over other pieces of technology for the same purpose. The system automatically sends a return reply to that particular mobile indicating the position of the vehicle in terms of latitude and longitude when a request by user is sent to the number at the modem. A program has been developed that it is used to locate the exact position of the vehicle and also to navigated track of the moving vehicle on Google map.

# High LEVEL DESIGN
![image](https://github.com/Zeeshanx186/GPS-GSM-Based-Vehicle-Tracking-System/assets/101282364/e49c3360-1528-4386-8fb4-424e2bd63ac5)
![image](https://github.com/Zeeshanx186/GPS-GSM-Based-Vehicle-Tracking-System/assets/101282364/fec07fc5-ea94-45a7-b841-27ae907cbc04)

# Description 

First of all we send the SMS through our mobile to GSM module, then if GSM is powered on and connected to network, then it will send that message to micro-controller. Further, microcontroller again communicate with GPS module and if GPS is powered on and connected to different satellites then it will give us the longitude, and latitude of our Vehicle's current location. Then micro-controller again communicate with GSM and then message sent to the user in the form of longitude, latitude, and with google link. The result will also show to the separate LCD for just displaying purpose.

So we jumbled these electrical components in a way that they can give us our desired output. Firstly, we just combined all devices with micro controller like GSM is directly connected with UNO board so when user send message GSM to communicate with the micro-controller and process the things and after understanding message it sends this particular message to GPS and then GPS transfer this message to the Global Positioning Satellites. And the GPS which we used can track up to 22 satellites over 50 channels and achieve the industry’s highest level of tracking sensitivity i.e. -161 dB, while consuming only 45 mA current. Unlike other GPS modules, it can perform 5 location updates in a second with 2.5m horizontal position accuracy. The U-blox 6 positioning engine also has a Time-To-First-Fix (TTFF) of less than 1 second. And this GPS only fetches location if it catches satellite signals and the blinking LED shows its signal-catching ability. Finally, after going through these all process the satellite gives the desired location in form of link in user’s phone and it also shows the position in form of longitude and latitude.
Literature Review:

There are a lot of ways to design a GPS tracker like you can choose GSM sim 900A, 800 or any other and these all are 2G based Sims even though sim 900 is also 2G networking, but if we find it suitable and appropriate. However, we also worked on other Sims but we faced many troubles except sim 900. Thus, the components which we used are given below:

# MICROCONTROLLER

- GPS neo-6M module
- SIM900 GSM GPRS MODULE
- OLED 1.44’ SPI 128*128 DISPLAY
- SIM card (It can be Zong, Telenor, Jazz, etc.)

