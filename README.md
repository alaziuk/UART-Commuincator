# UART Communicator

A simple GUI application written in C++ using Qt. It's purpose is to commuinicate with my [Autopilot emulator](https://github.com/alaziuk/Autopilot-emulator). It's controlling the speed of a BLDC Motor (from 0% to 100%).

The project sends 5-byte message for example "AT010" which means 10% of nominal speed. "AT" is the beggining of the command and following "xyz" mean a number. The command in application itself is capped at 100.

You can choose how board you're connected with will commuinicate with other boards. You have choice between no signal, PWM and CAN in corresponding dropbox in gui. It sends message similar to speed control:
- "ATNON" for no signal,
- "ATPWM" for PWM communication,
- "ATCAN" for CAN communication.

It also has a button to check what mode is currently chosen on the board.

### What's next?

In the future, I'm going to add CAN communication.
