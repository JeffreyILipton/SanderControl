#!/usr/bin/env python
from enum import IntEnum
import serial
import struct
import time
import datetime
import csv
NO_SERIAL = False

class Recorder(object):
    """Serial Interface to Arduino"""
    def __init__(self,port):
        if NO_SERIAL:
            self.port = serial.Serial()
        else:
            self.port = serial.Serial(port,9600,parity = serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE,xonxoff=False,timeout=10.0)


        
    def record(self):
        name = datetime.datetime.now().strftime("%I-%M%p on %B %d, %Y") + ".csv"
        name = name.replace(":","-").replace("/","-").replace(" ","-").replace(",","-")
        with open(name,"w") as f:
            print 'opened csv at %s'%name
            writer = csv.writer(f,delimiter = ",")
            while True:
                line = self.port.readline().strip().replace(':','')
                print line
                parts = line.split(' ')
                #print parts
                if len(parts)>3:
                    t = time.time()
                    parts.append('time')
                    parts.append(t)
                    parts = filter(None,parts)
                    writer.writerow(parts)
                    print parts
                
    

if __name__ == '__main__':
    AI = Recorder("COM4")
    print "Port Open: ", AI.port.isOpen()
    AI.record()
    