#ifndef __MYCOMMON__
#define __MYCOMMON__
 
#include "pthread.h"
#include "common.h"
#define crear_puerta(m) pthread_mutex_init(&m, NULL)
#define cerrar_puerta(m) pthread_mutex_lock(&m)
#define abrir_puerta(m) pthread_mutex_unlock(&m)
#define destruir_puerta(m) pthread_mutex_destroy(&m)

#endif

