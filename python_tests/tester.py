import sys
from lager import lager
import serial
import requests
import uuid
import os

def main():
    gateway = lager.Lager()
    device = gateway.connect("nrf52", ignore_if_connected=True)
    with serial.Serial('/dev/ttyACM0', 115200, timeout=2) as ser:
        device.reset(halt=False)
        output = ser.read(512).decode()

    username = 'lager'
    password = os.environ['API_PASSWORD']
    api_base = 'https://inspector.fkops.net/receive'
    request_id = str(uuid.uuid4()).upper()
    api_url = f'{api_base}/{request_id}'

    response = requests.post(api_url, json={'hello': 'world', 'output': output}, auth=(username, password))
    response.raise_for_status()
    print(f'Success! review results at https://inspector.fkops.net/review/{request_id}')

if __name__ == '__main__':
    main()
