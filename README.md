# user-space-device-driver-in-c
A user-space device driver for a remotely connected cloud device (called a Lion Cloud device). Provides a filesystem interface on top of the virtual device. <br/>
At the highest level, file system commands are translated into device operations.<br/>
The file system commands include open, read, write, seek, close and shutdown for files that are written to the file system driver.<br/>
System and Project Overview
The basic device driver that sit between a virtual application and virtualized hardware devices. The application makes use of the abstraction you will provide called the LionCloud driver. The design of the system is shown in the figure here: <br/>
<img align="center"  width="400" height="400" src="https://raw.githubusercontent.com/xinbi99/user-space-device-driver-in-c/master/architecture.jpg">
