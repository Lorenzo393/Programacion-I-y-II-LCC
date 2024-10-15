# EJERCICIOS
#Ej 1 y 2
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

#Ej 3
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

#Ej 4 y 5
def spn(n):
    if n == 0:
        return 0
    else:
        return n + spn(n-1)

#print(spn(50))
#print(spn(34))

#Ej 6
def spnm(n , m):
    if n > m:
        return 0
    else:
        return n + spnm(n + 1 , m)

#print(spnm(0 , 50))
#print(spnm(10 , 20))

#Ej 7
def duplica():
    name = input("Ingrese un nombre: ")
    return name*2

#print(duplica())

#Ej 8
def multstr(n):
    name = input("Ingrese un nombre: ")
    return name*n

#print(multstr(4))

#Ej 9

def suma(x , y):
    return x + y

def resta(x , y):
    return x - y

def multiplica(x , y):
    return x * y

def divide(x , y):
    return x / y

def calculador():
    op = int(input("Ingrese operacion\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n5.Salir\n"))
    if op == 5:
        return 0
    x = int(input("Primer numero: "))
    y = int(input("Segundo numero: "))
    if op == 1:
        print(suma(x , y))
    if op == 2:
        print(resta(x , y))
    if op == 3:
        print(multiplica(x , y))
    if op == 4:
        print(divide(x , y))
    else:
        calculador()