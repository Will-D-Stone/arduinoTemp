# arduinoTemp
Code for a 7805 processor on an arduino uno to display temperature on an OLED in both Fahrenheit and Celsius using a tmp36 temperature sensor. 

Included are the main file arduino, the makefile, and several support files for the OLED, uart, etc. 

New code and code changes applied for Umass ECE231 lab8.2 based on the below source code

Acknowlegement and License: i2c.c, ic2.h, SSD1306.c and SSD1306.h are user-defined libraries to operate the SSD1306/OLED over the i2C interface. These are open-source codes provided by Preston Sundar, via github, under the MIT license. That same licence covers all code herein. Contributed files are located here:
https://github.com/prestonsn/AVR-OLED-SSD1306-IIC-DRIVER and https://github.com/prestonsn/AtmegaXX-I2C-Library
