###Script para subir datos a ThingSpeak
###Mathias Castillo 1745502

##API write key
api_key=V9UEPQ3J6O8T505V

##llamando al programa de python
pga=`/usr/bin/python /home/root/proyecto/Humedad_Tierra.py`

##Tomando los datos del programa python
command=`echo $pga | awk '{print $1}'`
#command2=`echo $pga | awk '{print $2}'`

##Subiendo los datos al servidor ThingSpeak
curl --data "api_key=$api_key&field1=$command&field2=$(date)" https://api.thingspeak.com/update


echo " "
echo $command
echo "Datos enviados al servidor satisfactoriamente"

