#!/usr/bin/env python3
"""
Simple command line motor controller
Usage: python3 motor_control.py W  (for forward)
       python3 motor_control.py S  (for backward)
"""

import serial
import time
import sys
import glob

def find_arduino_port():
    """find Arduino port automatically"""
    ports = glob.glob('/dev/ttyACM*') + glob.glob('/dev/ttyUSB*')
    if ports:
        return ports[0]
    return None

def send_command(command):
    """send command to arduino i think"""
    # Find Arduino
    port = find_arduino_port()
    if not port:
        print("Error: Arduino not found")
        print("Make sure Arduino is connected via USB or something broke")
        return False

    try:
        arduino = serial.Serial(port, 9600, timeout=1)
        time.sleep(2)  # Wait for Arduino to reset

        while arduino.in_waiting:
            arduino.readline()

        arduino.write(command.encode())
        print(f"Sent command: {command}")

        # read 
        time.sleep(0.5)
        while arduino.in_waiting:
            response = arduino.readline().decode('utf-8').strip()
            if response:
                print(f"Arduino: {response}")

        arduino.close()
        return True

    except Exception as e:
        print(f"Error: {e}")
        return False

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 motor_control.py <command>")
        print("Commands:")
        print("  W = Forward")
        print("  S = Backward")
        sys.exit(1)

    command = sys.argv[1].upper()

    if command not in ['W', 'S']:
        print(f"Invalid command: {command}")
        print("Use W (forward) or S (backward)")
        sys.exit(1)

    send_command(command)

if __name__ == "__main__":
    main()
