import smbus #permite la comunicacion i2c de manera facil

bus = smbus.SMBus(1)#puerto i2c
direccion_teensy = 0x2f#direccion del esclavo

try:
        while(True):
                lectura_teensy = bus.read_i2c_block_data(direccion_teensy,0,10)#lectura desde el esclavo
                envio_teensy = [1,2,3,4,5]
                bus.write_i2c_block_data(direccion_teensy,0,envio_teensy)#envio de datos al esclavo
                print "Teensy Lectura: ", lectura_teensy, " Teensy Envio: ", envio_teensy
except KeyboardInterrupt:
        print " "
        print "Termino comunicacion"
