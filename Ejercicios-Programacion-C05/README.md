## AUTORES: 
### Mathias Castillo - Brallan Rubio

## Capítulo 5


### Pregunta 1
#### Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x? 
R// Después del Fork (), el valor de la variable tanto en el hijo como en el padre es x. Cada uno cuenta con una copia idéntica del valor y al cambiar el valor en alguno de ellos; no implica que cambie en el otro.


### Pregunta 2
#### Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?
R// Ambos procesos (Hijo y padre) pueden acceder al archivo abierto utilizando Open (). En cuanto al orden no es posible determinar cuál se ejecutará primero (Siempre y cuando no se utilice Wait para el proceso padre)

 
### Pregunta 3
#### Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
R// Puede ser posible sin el wait (), utilizando un operador para el padre y a su vez la orden de imprimir del proceso hijo este primero.

 
### Pregunta 4
#### Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the variants of exec(), including (on Linux) execl(), execle(), execlp(), execv(), execvp(), and execvpe(). Why do you think there are so many variants of the same basic call?
R// En nuestros sistemas no pudimos probar la variante “execvpe()”. Cada una de las variantes tiene una función específica; aunque hay algunas que son casi idénticas. La diferencia principal es el tipo de dato que recibe cada una, Por ejemplo: Argumentos separados por Comas, argumentos en arreglos, etc).

 
### Pregunta 5
#### Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?
R// Cuando el programa se ejecuta con éxito el wait() devuelve el valor de “-1”; el cual corresponde al identificador del proceso hijo. En el caso de usar wait() en el hijo este sigue devolviendo “-1”, porque no hay ningún otro proceso luego de su ejecución.

 
### Pregunta 6
#### Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?
R// El comando waitpid() es útil cuando queremos esperar a que terminen varios procesos, es decir cuando tenemos más de un hijo.

 
### Pregunta 7
#### Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
R// Al ejecutar el programa solo se ve por pantalla el proceso padre creado, sin embargo, el proceso hijo no se muestra en la terminal en lo absoluto. Al compilar no muestra ningún error.  
