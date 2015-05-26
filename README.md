# i2cnetwork
simple I2C network using arduino nanos

This was a school project, to create a network of devices communicating via I2C.

I programmed 3 arduinos, 1 master, 2 slaves.

One of the slaves controlled a stepper motor, based on the command from the master.
The other slave measured the tempreature with a DHT22 temp sensor, and displayed it on a 4 digit 7 segment display, 
with the help  of a maxim LED driver chip.
