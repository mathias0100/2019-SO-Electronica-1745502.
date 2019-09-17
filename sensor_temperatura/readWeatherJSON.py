#!/usr/bin/env python
#
# Este script fue disenado para leer los datos arrojados por el API de 
# OpenWeatherMap y que han sido almacenados en un archivo JSON.
#
# Los datos por los cuales se espera el usuario pregunte son:
# - humedad,
# - temperatura,
# - velocidad del viento
#
# Para acceder a estos valores, el script se debe invocar:
#
# readWeatherJSON.py <archivo_json> main humidity
# readWeatherJSON.py <archivo_json> main temp
# readWeatherJSON.py <archivo_json> wind speed
#
# Author: John Sanabria - john.sanabria@correounivalle.edu.co
# Date: 2019-09-04
#
#Ruta archivo modificada por Mathias Castillo - Brallan Rubio - Diego Alban

import json 
import sys
import os

if not len(sys.argv) == 4:
    print("Uso %s <json_file> <campo1> <campo2>"%sys.argv[0])
    print("Si campo1 = 'main' entonces campo2 = [ 'humidity' | 'temp' ]")
    print("Si campo2 = 'wind' entonces campo2 = [ 'speed' ]")
    sys.exit(-1)

homedir = os.environ['HOME']
os.chdir("%s/sensor_temperatura"%homedir)
filename = sys.argv[1]
campo1 = sys.argv[2]
campo2 = sys.argv[3]
with open(filename) as json_file:
    data = json.load(json_file)
    print(data[campo1][campo2])
