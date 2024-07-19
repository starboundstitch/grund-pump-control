import serial
import sys
import time

def write_read(x):
    arduino.write(bytes(x,  'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return  data

if __name__ == "__main__":
  
  arduino = serial.Serial(port=sys.argv[1],  baudrate=9600, timeout=.1)

  while True:
    num = input("Enter a number: ")
    value  = write_read(num)
    print(value)

