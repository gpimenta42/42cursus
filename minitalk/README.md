## Objetive                                              

To create a communication program in the form of a client and a server.

## Server 

The server must be started first. 

After its launch, it has to print its PID.

The server has to print a string received by the client.
The server has to display the string pretty quickly.
The server should be able to receive strings from several clients in a row without
needing to restart.
Unicode characters support!

BONUS PART: 
The server acknowledges every message received by sending back a signal to the
client.



## Client

The client takes two parameters:
- The server PID.
- The string to send.

The client must send the string passed as a parameter to the server.

The communication between your client and your server has to be done only using
UNIX signals:
- It could only be used these two signals: SIGUSR1 and SIGUSR2.


## How to compile 

<sub>make 

<sub>make bonus 

<sub>./server (or) ./server_bonus

<sub>Server PID is < PID > 

<sub>./client (or) ./client_bonus < PID > < string to pass > </sub>

## Output

![image](https://user-images.githubusercontent.com/87911989/219957931-a1ebcf4d-3a9d-4fe9-817d-cc5dfed73590.png)

