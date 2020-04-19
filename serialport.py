import serial
import serial.tools.list_ports
from signal import signal, SIGINT
from sys import exit


def handler(signal_received, frame):
    # Handle any cleanup here
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    exit(0)

signal(SIGINT, handler)


def comportDetect():
    dev = list(serial.tools.list_ports.comports())
    if not dev:
        return False;
    else:
        return dev




ports = comportDetect()
tmpports = []
portcount = 0;
for p in ports:
    print(portcount, p)
    tmpports.append(p)
    portcount = portcount + 1


input = input('Port to read? ')

print(tmpports[2].device)
ser = serial.Serial(tmpports[int(input)].device)

try:
    while True:
        arduino = ser.readline()
        print(arduino)

except KeyboardInterrupt:
    signal.signal(signal.SIGINT, signal_handler)