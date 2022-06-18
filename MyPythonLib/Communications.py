from numpy import true_divide
import serial as ser

class Communications():
    
    __port_name = ""
    __baud_rate = 0   
    __serial = None 
    
    # default constructor
    def __init__(self, port_name : str, baud_rate : int):
        self.__baud_rate = baud_rate
        self.__port_name = port_name
        if(port_name != None and baud_rate != None):
            self.__serial = ser.Serial(self.__port_name, self.__baud_rate)
            
    def close():
        return True
    
    def open():
        return True

    def sendMessage():
        return True
    
    def recieveMessage():
        return True
    
    def peek():
        return True
    
    def clear():
        return True

