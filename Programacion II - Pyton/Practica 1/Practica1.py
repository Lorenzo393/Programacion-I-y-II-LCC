# Ej 1 y 2
def pares(n):
    if n > 1:
        print(n * 2)
        pares(n - 1)
    else:
        print(2)

#pares(25)
#pares(100)
 # 1. && 2. Esta misma solucion sirve para cualquiera de los dos ejercicios y 
 # para cualquier n natural

# Ej 3
def paresm(n , m):
    if n > 1:
        if (m % 2) == 0:
            m = m + 2
        else:
            m = m + 1
        print(m)
        paresm(n - 1 , m)
    else:
        print(m + 2)

#paresm(5 , 5)
 # En este caso no pude ya que estas dos funciones trabajan de distinta manera

# Ej 4
