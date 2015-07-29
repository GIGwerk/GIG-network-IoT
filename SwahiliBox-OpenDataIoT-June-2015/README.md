# Open Data and the Internet of Things Bootcamp code

This code has been submitted by the Open Data IoT BootCamp developer team. It contains code that has been developed on 2 major projects to demonstrate the possibility of using IoT equipment to create open datasets that can be used to create smarter cities.

## Team

* Ahmed Maawy (Mentor)
* Aly Uweso Salim
* Dennis Onkange
* Fatah Noor
* Harris Mwashalo (Data Guru)
* Japeth Obala
* John Watt
* Kenga Jones
* Munir Abdulhakim
* Neville Lusimba
* Stephen Odhiambo

## Systems developed

There were two systems developed on Arduino and 1 system developed for the Raspberry Pi.The system developed on Pi is intended to be a data collector from the Arduino devices, which are charged with the responsibility of connecting to various sensors and boards, and sending the data collected from these devices and sensors using the USB port to the Pi, which collects the data and saves it to a local SQLite Database using a python script.

The 2 Arduino Projects are discussed below.


## Customer Feedback

Is a board configuration that makes use of 3 push buttons: "Good", "OK", "Bad" and 3 corresponding LEDs that are Green, Yellow and Red. The 3 LEDs light up in accordance to the feedback button clicked. The data is then sent to USB output and logged via the Pi using its data collection and storage script. These systems can be put up at strategic exits in areas where customer satisfaction rating is needed. The data trend is then analyzed.

## Traffic Monitor

Uses a proximity sensor and some smart logic to track whether cars on a specific road are moving or are stopped. If these sensors are deployed accross various roads each road can send data from various points on intervals in which cars are moving and stopped and for how long. This can be used to generate trends data. The data is then sent to USB output and logged via the Pi using its data collection and storage script.

## Raspberry Pi Data collection

The folder *pi-data-logger* has code that contains the python script that can poll the Arduino Board and log its values to an SQLite database using SQLAlchemy ORM. 
