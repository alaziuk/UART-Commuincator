# UART Communicator

A simple GUI application written in C++ using Qt. It's purpose is to commuinicate with my [Autopilot emulator](https://github.com/alaziuk/Autopilot-emulator). It's controlling the speed of a BLDC Motor (from 0% to 100%).

The project sends 5-byte message for example "AT010" which means 10% of nominal speed. "AT" is the beggining of the command and following "xyz" mean a number. The command in application itself is capped at 100.

It's currently being expanded with PWM/CAN options.
