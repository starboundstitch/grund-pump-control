# grund-pump-control

This is a heavily WIP program that can be used to control Grundfos pumps. It currently only uses the setpoint feature and the digital inputs to control the duty cycle. In the future, I would like to control it based on flow rate using the analog inputs.

The hardware used is a arduino nano, it should work on other arduinos, but ymmv.

## Makefile

For those of you who want to use the makefile, please understand that you will need to add the FQBN of your arduino and the serial port that it is connected on for it to function correctly. 

**WINDOWS USERS**

Do not use the makefile unless you know what you are doing, instead run the alternate commands.

## Arduino

**No instructions are provided for windows**

To build and run the code for arduino, you must install arduino-cli for your platform.

If you are on NixOS, you can use the provided nix-shell instead.

```
make c_comp
make c_up
```

Be advised, I have had some issues with reliability in compiling, if either command fails, try re-running it a few times.

Once they both succeed, your arduino should be programmed to use pins D5,D7, and D9 for outputs. I use a transistor switch to decouple the arduino from the pump, but ymmv.

## Python

To build and run the code for python, create a virtual environment, activate it, and install the dependencies.

```
python -m venv .venv

# Windows powershell
.\.venv\Scripts\Activate.ps1
# Windows cmd
.\.venv\Scripts\Activate.bat
# Linux
source .venv/bin/activate

pip install -r requirements.txt
```

Alternatively, you can install pyserial globally for your platform

For NixOS users, a dev shell has been provided for your usage.

**BEFORE RUNNING THE PROGRAM**

You must change the serial port to the one representing your arduino.

On Windows, you can find this by going into device manager and looking under the COM Ports option. It should be in the format `COM*`.

On Linux, it should be `/dev/ttyUSB*` or `/dev/ttyACM*`.

Once you have identified the correct serial port, you can run the program:

```
make s_start
# or
python application/app.py ${SERIAL_PORT}
```
