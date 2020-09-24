import sys
import pytest
from lager import lager
import serial

def test_good_serial_output():
    gateway = lager.Lager()
    device = gateway.connect("nrf52", ignore_if_connected=True)
    with serial.Serial('/dev/ttyACM0', 115200, timeout=2) as ser:
        device.reset(halt=False)
        output = ser.read(512)

    assert b'test_check_min_number_blinks' in output

def test_bad_serial_output():
    gateway = lager.Lager()
    device = gateway.connect("nrf52", ignore_if_connected=True)
    with serial.Serial('/dev/ttyACM0', 115200, timeout=2) as ser:
        device.reset(halt=False)
        output = ser.read(512)

    assert b'test_not_check_min_number_blinks' in output

if __name__ == '__main__':
   sys.exit(pytest.main([__file__]))
