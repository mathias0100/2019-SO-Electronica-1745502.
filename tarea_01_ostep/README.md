# Reporte archivos de la tarea 1 Sistemas operativos

## Autores: Brallan Rubio 1745750 - Mathias Castillo 1745502.

En el presente trabajo se evidenciara el orden de desarrollo para:


[mem.c](mem.c): - Este punto se realizo basandose en el archivo original del repositorio Ostep-Code y que posteriormente trabajamos la clase del 06/06/2019, Antes de realizar la ejecución fue necesario ingresar como usuario Root a la computadora personal y cambiar los parametros de proceso del sistema base. Posteriormente se ejecuto el archivo de manera concurrente y se evidencio que los procesos accederieron a la misma direccion/region de memoria pero cada proceso tomó un valor distinto dentro de esa misma región. 




[threads.c](threads.c): - Para este punto nos basamos en el codigo original que se encuentra en el repositorio de Ostep-Code y que posteriormente trabajamos la clase del 06/06/2019. Al compilar y ejecutar el programa se evidenciaba que para datos grandes se presentaba un problema de concurrencia; es decir que por cada ejecucion arrojaba diferentes resultados. Para corregir este asunto fue necesario crear puertas para los hilos en la ejecucion del programa; la funcion de estas es mantener la variable a modificar con un solo proceso en el momento y una vez se termine, proceder a abrir la puerta y dejar ingresar el siguiente proceso, de esta manera se puede decir que el programa será mas confiable durante la ejecución.
Ahora, dentro del codigo se procedio a realizar varios cambios, el primero fue crear e incluir a [mycommon.h](mycommon.h); el cual contiene las funciones para manipular las puertas dentro del codigo principal, posteriormente se incluyeron estas funciones dentro del Main y la funcion de aumento de variable.  




[io.c](io.c):

