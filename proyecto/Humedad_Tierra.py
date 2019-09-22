###Codigo para leer datos de un sensor de humedad del suelo por un pin analogo A1
###Mathias Castillo-1745502

#!/usr/bin/python

##Importando paquetes de Python
import mraa
import time

##Activando el pin A1 como entrada
ain = mraa.Aio(1)

##Leyendo los datos del sensor en el pin A1
a = ain.read()

##Imprimiendo los datos del sensor
print (a)

