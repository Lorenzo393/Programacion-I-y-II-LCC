# FOR
#Ej 1
def d10a20():
    for i in range(10,21):
        print(i)

#d10a20()

#Ej 2
def domino():
    for i in range(7):
        j = 1
        for j in range(i,7):
            print("_________")
            print("|", i ,"|", j ,"|")

#domino()

#Ej 3
def genfichas(n):
     for i in range(n+1):
        j = 1
        for j in range(i,n+1):
            print("_________")
            print("|", i ,"|", j ,"|")

#genfichas(2)

#Ej 4
def factoriales(m):
    for i in range(m):
        n = int(input("Ingrese un numero: "))
        for j in range(1,n):
            n = i * n
        print(n)

#factoriales(2)

#Ej 5
def farCel():
    for i in range(0,121,10):
        print("F:" , i , "C" , ((i-32)*5)/9)

#farCel()

#Ej 6
def numTriF(n):
    for i in range(1,n+1):
        j = 0
        for r in range(1 , i+1):
            j = j + r
        print(i," - ",j)

#numTriF(5)

def numTriS(n):
    for i in range(1,n+1):
        print(i ," - ",(i*(i+1))/2)

#numTriS(5)
# La version del bucle for anidado realiza mas operaciones

# WHILE
#Ej 7
def numPos():
    i = int(input("Ingrese un numero positivo: "))
    while(i < 0):
        i = int(input("Ingrese otro numero: "))

#Ej 8
def notas():
    notas = 0
    cant_notas = 0
    ingresar_notas = int(input("Quiere ingresar una nota: 1.Si 2.No: "))
    while ingresar_notas == 1:
        notas = notas + int(input("Ingrese una nota: "))
        cant_notas += 1
        ingresar_notas = int(input("Quiere ingresar otra nota: 1.Si 2.No: "))
    if cant_notas > 0:
        print("Promedio de las notas: " , notas/cant_notas)

#Ej 9
def numeros():
    num1 = int(input("Ingrese el primer numero: "))
    num2 = int(input("Ingrese el segundo numero: "))

    while num1 > num2:
        num2 = int(input("Ingrese nuevamente el segundo numero: "))

    print("No1: " , num1 , "No2: " , num2)

#Ej 10

def mulfor(n1 , n2):
    for i in range(1,n2):
        if n1 % i == 0:
            print(i)



#Ej 11
def passkey1():
    cont_real = "contraseña"
    cont_usuario = input("Ingrese la contraseña: ")
    while cont_real != cont_usuario:
        cont_usuario = input("Contraseña incorrecta: ")
    print("Acceso concedido")

def passkey2():
    cant_intentos = 3
    cont_real = "contraseña"
    while cont_real != input("Ingrese la contraseña: ") and cant_intentos > 0:
        print("Contraseña incorrecta.")
        cant_intentos -= 1
    if cant_intentos > 0:
        print("Acceso concedido")
    else:
        print("Acceso denegado")

#Solucionar 4 intentos

def passkey3():
    cant_intentos = 3
    cont_real = "contraseña"
    
    acceso = chequeocontraseña(cont_real , cant_intentos)

    if acceso:
        print("Acceso consedido")
    else:
        print("Acceso denegado")

def chequeocontraseña(cr , ci):
    while cr != input("Ingrese la contraseña: ") and ci > 0:
        print("Contraseña incorrecta.")
        ci -= 1
    if ci > 0:
        return True
    return False

#Ej 12
def primosMenores(n):
    for i in range(2,n):
        if esPrimo(i):
            print(i)

def esPrimo(n):
    i = 2
    while n % i != 0 and i != n:
        i += 1
    if i == n:
        return True
    return False

#primosMenores(100)

#Ej 13
def sumaRangoDeDos(x , y):
    suma = 0
    for i in range(x , y+1):
        if esPotenciaDeDos(i):
            suma += i
    print(suma)

def esPotenciaDeDos(n):
    i = 0
    while n % 2 == 0 and n != 1 and n != 0:
        n = n // 2

    if n == 1:
        return True
    return False

# RANDOM
#Ej 14
from random import *

# random()          -> Genera un numero aleatorio entre 0 y 1
# randint(x , y)    -> Genera un numero aleatorio entre x e y, incluyendo ambos
# randrange(x)      -> Genera un numero aleatorio entero entre 0 y x-1

def dadosHastaSeis():
    cant_tiradas = 0
    i = 0
    while i != 6:
        i = 1 + randrange(6)
        cant_tiradas += 1
        print("N°: " , i)
    print("Tiradas: " , cant_tiradas)

def lanzamientosDeDados():
    n = int(input("Ingrese la cantidad de lanzamientos: "))
    repeticion = 0
    for i in range(0,n):
        d1 = 1 + randrange(6)
        d2 = 1 + randrange(6)
        print("D1: " , d1 , " D2: " , d2)
        if d1 == d2:
            repeticion += 1
    print("Repetidas: " , repeticion)

def dadosGame():
    n = int(input("Quiere tirar el dado? 1.Si 2.No : "))
    dinero = 0
    while n != 2:
        i = 1 + randrange(6)
        if i == 6:
            dinero += 4
        if i == 3:
            dinero += 1185 #Precio del dolar a pesos 14/10/24
        if i == 2 or i == 4 or i == 5:
            dinero -= 2
        print("D: " , i)
        n = int(input("Quiere volver a tirar el dado? 1.Si 2.No : "))
    print("Dinero obtenido: " , dinero)