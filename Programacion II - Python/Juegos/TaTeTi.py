# USAR TESTEO
# USAR CASOS DE ERROR

from random import randrange
# randrange(x)      -> Genera un numero aleatorio entero entre 0 y x-1



def iniciar_tablero():
    tablero = [["-","-","-"],["-","-","-"],["-","-","-"]]
    return tablero

def mostrar_tablero(tablero):
    for i in tablero:
        print(i)
            
