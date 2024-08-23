# Ej 1 y 2
def pares(n):
    if n > 1:
        print(n * 2)
        pares(n - 1)
    else:
        print(2)

pares(25)
pares(100)
 # 1. && 2. Esta misma solucion sirve para cualquiera de los dos ejercicios y 
 # para cualquier n natural

 # Ej 3