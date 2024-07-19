# grund-pump-control

This is a heavily WIP program that can be used to control Grundfos pumps. It currently only uses the setpoint feature and the digital inputs to control the duty cycle. In the future, I would like to control it based on flow rate using the analog inputs.

The hardware used is a arduino nano, it should work on other arduinos, but ymmv.

## Arduino

To build and run the code for arduino, you must install arduino-cli for your platform.

If you are on NixOS, you can use the provided nix-shell instead.

Once that is installed, edit the makefile to point to the serial device and FBN of your arduino and then run:

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
.\.venv\Scripts\Activate.bat
# Windows cmd
.\.venv\Scripts\Activate.ps1
# Linux
source .venv/bin/activate

pip install < requirements.txt
```

Alternatively, you can install pyserial globally for your platform

For NixOS users, a dev shell has been provided for your usage.

To run the program, type:

```
make s_start
# or
python application/app.py
```
