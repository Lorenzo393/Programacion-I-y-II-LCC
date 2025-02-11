# CADENAS 
#
# s = "hola"
# s[inicio:fin:paso]
# s * 2 = "holahola" - multiplica la cadena
#
# LISTAS
# l = [1,2,3,4]
# 
# l[3] = l[-1] = 4
# l[-4] = 1
#
# l.append(x) - agrega un elemento al final de la lista
# l * 2 = [1,2,3,4,1,2,3,4] - multiplica la lista
# l[inicio:fin:paso]
#
# FOR
# for elemento in lista - recorre la lista si printeo el elemento muestra el elemento de la lista
# for elemento in range(inicio:fin:paso) - recorre una lista que creamos
#
# WHILE
# while condicion - mientras se cumpla la condicion ejecuta el bucle
#
# TUPLAS
# t = (1,2,3,4)
#
#
# DICCIONARIOS
# d = {clave inmutable:valor mutable}
# d.items - devuelve una lista de tuplas con su primera la clave y segunda su valor
# d.keys - devuelve una lista con las claves
# d.values - devuelve una lista con los valores
# dict(l) - crea un diccionario con una lista de tuplas clave valor
#
# CONJUNTOS
# c = set()
# c = {valor1, valor2, valor3}
# c.add() - agrega un valor al conjunto
# c.update() - agrega una lista o un conjunto al conjunto
# c.discard() - elimina un elemento
# c.remove() - elimina un elemento si no existe genera una excepcion
#
# c.union(b) ó c | b - union en conjuntos
# c.intersection(b) ó c & b - interseccion en conjuntos
# c.difference(b) ó c - b - diferencia en conjuntos
#
# ARCHIVOS
#
# f = open("nombre-archivo","modo")
# "r" - lectura
# "w" - escritura
# "r+" o "w+" el archivo es abierto para lectura y escritura
# "a" el archivo se abre para escribir al final de este
# f.close() - cierra el archivo
#
# f.readlines() - lee el archivo completo y retorna una lista
#formada por las lineas encontradas
# f.read(n) - lee la cantidad de caracteres n
# f.readline() - lee una linea del archivo
#Tanto read como readline cuando llegan al final devuelven ""
# f.seek(n) - se desplaza n posiciones
# f.write("Cualquier cosa") - funcion para escribir en un archivo



#------------------------------------------------------------------------------------#
# PRACTICA 1

#EJ 1
def pares25():
    for i in range(1,26):
        print(i*2)
#pares25()

#EJ 2
def pares100():
    for i in range(1,101):
        print(i*2)
#pares100()

#EJ 3
def paresMasM(n,m):
    if m % 2 == 0:
        for i in range(m + 2, m + (n*2) + 1, 2):
            print(i)
    else:
        for i in range(m + 1, m + (n*2) + 1, 2):
            print(i)
#paresMasM(5,9)

#EJ 4
def suma50(n = 0):
    if n == 50:
        return n
    else:
        return n + suma50(n+1)
#print(suma50())

#EJ 5
def sumaN(n , cont = 0):
    if cont == n:
        return cont
    else:
        return cont + sumaN(n,cont+1)
#print(sumaN(50))

#EJ 6
def sumaNM(n , m , cont = 0):
    if n == m:
        return cont
    else:
        cont = n
        return cont + sumaNM(n + 1, m, cont+1)
#print(sumaNM(2,50))

#EJ 7
def duplica(s):
    return s * 2
#print(duplica("hola"))

#EJ 8
def duplicaN(s,n):
    return s * n
#print(duplicaN("hola",3))

#EJ 9
def suma():
    x = int(input("Primero: "))
    y = int(input("Segundo: "))
    return x+y
def resta():
    x = int(input("Primero: "))
    y = int(input("Segundo: "))
    return x-y
def multiplicacion():
    x = int(input("Primero: "))
    y = int(input("Segundo: "))
    return x*y
def division():
    x = int(input("Primero: "))
    y = int(input("Segundo: "))
    return x/y
def programa():
    x = 0
    while(x != 5):
        print("\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir")
        x = int(input("Ingrese un valor: "))
        if x == 1: print(suma())
        if x == 2: print(resta())
        if x == 3: print(multiplicacion())
        if x == 4: print(division())
#programa()

#------------------------------------------------------------------------------------#
# PRACTICA 2

#EJ 1
def entre10y20():
    for i in range(10,21):
        print(i)
#entre10y20()

#EJ 2
def domino():
    for i in range(0,7):
        for j in range(i,7):
            print("| ",i," | ",j," |")
#domino()

#EJ 3
def dominoN(n):
    for i in range(0,n+1):
        for j in range(i,n+1):
            print("| ",i," | ",j," |")
#dominoN(6)

#EJ 4
def factorial(n):
            if n == 1:
                return n
            else:
                return n * factorial(n-1)

def factorialM():
    m = int(input("Ingrese la cantidad de valores: "))
    while(m != 0):
        n = int(input("Ingrese el valor: "))
        print(factorial(n))
        m -= 1
#factorialM()

#EJ 5
def temperatura():
    for i in range(0,121,10):
        print("Fahrenheit: ",i,"- Celsius: ",((i-32)*5)/9)
#temperatura()

#EJ 6
def numerosTriangulares(n):
    for i in range(1,n+1):
        print(i," - ",(i*(i+1))/2)
#numerosTriangulares(50)

#EJ 7
def positivo():
    x = int(input("Ingrese un numero positivo: "))
    while(x < 0):
        x = int(input("Error ingrese un numero positivo: "))
#positivo()

#EJ 8
def notas():
    bandera = 1
    sumaNotas = 0
    cantNotas = 0
    while(bandera):
        sumaNotas += int(input("Ingrese una nota: "))
        cantNotas += 1
        bandera = int(input("Quiere ingresar mas notas 1.Si 0.No: "))
    print("Promedio de notas: ",sumaNotas/cantNotas)
#notas()

#EJ 9
def masSegundo():
    x = int(input("Ingrese el primer numero: "))
    y = int(input("Ingrese el segundo numero: "))
    while(y < x):
        y = int(input("Ingrese nuevamente el segundo numero: "))
    print("Primer: ",x,"- Segundo: ",y,)
#masSegundo()

#EJ 10
def multiplosFor(x,y):
    for i in range(x,y+1,x):
        print(i)
#multiplosFor(4,50)


def multiplosWhile(x,y):
    multiplo = 1
    while(x * multiplo <= y):
        print(x*multiplo)
        multiplo += 1
#multiplosWhile(5,50)

#EJ 11
def gestorContra():
    contra = "obamaneitor"
    intentos = 3
    prueba = input("Ingrese la contra: ")
    while(contra != prueba and intentos > 0):
        print(intentos)
        prueba = input("Ingrese nuevamente la contra: ")
        intentos -= 1
    if prueba == contra: return True
    return False
#print(gestorContra())

#EJ 12
def esPrimo(n):
    multiplo = 2
    while(n % multiplo != 0 and n != multiplo and n != 1):
        multiplo += 1
    if n == multiplo: return True
    return False

def primosMenoresN(n):
    primo = 1
    while(primo <= n):
        if esPrimo(primo): print(primo)
        primo += 1
#primosMenoresN(111)

#EJ 13
def esPotenciaDe2(n):
    potencia = 0
    while(2 ** potencia < n and n != 1):
        potencia += 1
    if n == 2**potencia: return True
    return False

def potenciaDe2Rango(x,y): 
    contador = 0
    while(x <= y):
        if(esPotenciaDe2(x)): contador += x
        x += 1
    return contador
#print(potenciaDe2Rango(2,4))

#EJ 14
import random 
from random import*

def lanzarHasta6():
    x = 0
    while(x != 6):
        x = randint(1,6)
        print(x)
#lanzarHasta6()

def lanzarIguales():
    n = int(input("Ingrese el numero de tiradas: "))
    contador = 0
    while(n != 0):
        if(randint(1,6) == randint(1,6)): contador += 1
        n -= 1
    return contador
#print(lanzarIguales())

def valoresGambling(x): #Precio dolar 29/1/2025 1200 pesos
    if x == 6: return 4
    if x == 3: return 1200
    if x in {2,4,5}: return -2
    return 0

def gamblingIsGoodPesificado():
    n = randint(1,100)
    contador = 0
    while(n != 0):
        x = randint(1,6)
        contador += valoresGambling(x)
        n -= 1
    return contador
#print(gamblingIsGoodPesificado())

#------------------------------------------------------------------------------------#
# PRACTICA 3

#EJ 1
def posicionesMultiplo(l,n):
    print(l)
    return l[::n]
#print(posicionesMultiplo([1,2,3,4,5,6,7,8,9,19,27],2))

#EJ 2
def sumaAcumulada(l):
    print(l)
    acumulado = 0
    i = 0
    for n in l:
        l[i] = n + acumulado
        acumulado = l[i]
        i += 1
    return l
#print(sumaAcumulada([1,2,3,4,5,6]))

#EJ 3
def elimina(l):
    print(l)
    return l[1:len(l)-1]
#print(elimina([1,2,3,4,5,6,7,8]))

#EJ 4
def ordenada(l):
    if l[1:] == []: return True
    if l[0] < l[1]: return ordenada(l[1:])
    else: return False
#print(ordenada([2,3,4,5]))

#EJ 5
def duplicado(l):
    replicas = 0
    for i in range(len(l)):
        for j in l:
            if l[i] == j: replicas += 1
    if replicas != len(l): return True
    return False 
#print(duplicado([1,5,7,3,2]))

#EJ 6
def eliminaDuplicados(l):
    l.sort()
    aux = []
    if l != []:
        for i in range(len(l)-1):
            if l[i] != l[i+1]: aux.append(l[i])
        aux.append(l[-1])
    return aux
#print(eliminaDuplicados([1,2,154,12,312,125,1,23,12]))

#EJ 7
def cantidadDistinta(l):
    return len(eliminaDuplicados(l))
#print(cantidadDistinta([1,2,154,12,312,125,1,23,12]))

#EJ 8
def busquedaDicotomica(l,n):
    l = eliminaDuplicados(l)
    inicio = 0
    fin = len(l) - 1
    medio = (inicio + fin) // 2
    while(n != l[medio] and inicio <= fin):
        if n > l[medio]: 
            inicio = medio + 1
        if n < l[medio]:
            fin = medio - 1
        medio = (inicio + fin) // 2
    if n == l[medio]: return True
    return False
#print(busquedaDicotomica([1,2,154,12,3131,125,1,23,12],1))

#EJ 9
def mostrarCaracteres(s):
    for i in s:
        print(i)
#mostrarCaracteres("P.Diddy")

#EJ 10
def contar(s,x):
    contador = 0
    for i in s:
        if i == x: contador += 1
    return contador
#print(contar("Cuantas veces aparece la letra a en aaaaaaaaaaaaaaaaaaaaaaaa","e"))

#EJ 11
def contarVocales(s):
    vocales = {"a","e","i","o","u","A","E","I","O","U"}
    contador = 0
    for i in s:
        if i in vocales: contador += 1
    return contador
#print(contarVocales("Cuantas vocales hay en la palabra vocales"))

#EJ 12
def contarPalabrasMas(s):
    contadorPalabras = 0
    contadorLetras = 0
    largoPalabra = 5
    for i in s:
        if i != " ": 
            contadorLetras += 1
        if i == " ":
            if contadorLetras > largoPalabra: 
                contadorPalabras += 1
            contadorLetras = 0
    if contadorLetras > largoPalabra: 
        contadorPalabras += 1
    return contadorPalabras
#print(contarPalabrasMas("Cuantas palabras de mas de cinco letras hay en cinco letras"))

#EJ 13
# Represento a la baraja francesa como una tupla de tuplas con la teniendo en su primera
#posicion el valor de la carta y en la segunda posicion la inicial de su palo siendo
#de trebol T de corazones C de picas P y de diamantes D 
# Una tupla puede almacenar varias cartas de esta manera t = (("A","P"),(7,"T"),(9,"D"))
def pokerNumero(s):
    if s == "A": return 1
    if s == "J": return 11
    if s == "Q": return 12
    if s == "K": return 13
    return s

def poker(t):
    l = []
    for i in t:
        l.append(pokerNumero(i[0]))
    if cantidadDistinta(l) == 2:
        return True
    return False
#print(poker(((9,"T"),(8,"T"),(7,"D"),(7,"C"),(7,"P"))))
#print(poker((("A","T"),("A","P"),("A","C"),("A","D"),("J","D"))))

#EJ 14
# Represento al tiempo de la forma (segundos, minutos, horas) siendo estos todos enteros
def sumaTiempo(t1,t2):
    segundos = t1[0] + t2[0]
    minutos = t1[1] + t2[1] + segundos // 60
    horas =  t1[2] + t2[2] + minutos // 60
    return (segundos % 60 , minutos % 60 , horas)
#print(sumaTiempo((104,23,12),(123,213,111)))

#EJ 15
# t = (Dia,Mes,Año) - Int Int Int
# 31 dias: 1,3,5,7,8,10,12
# 30 dias: 4,6,9,11
# 28 dias: 2
# bisiesto es si es divisible por 4 o si es divisible por 100 y por 400 a la vez
def diaSiguienteE(t):
    di = t[0]+1
    me = t[1]
    an = t[2]
    if me in {1,3,5,7,8,10,12}:
        if di > 31:
            di = 1
            me += 1
    if me in {4,6,9,11}:
        if di > 30:
            di = 1
            me += 1
    if me == 12:
        if di > 31:
            di = 1
            me = 1
            an += 1
    if me == 2:
        if (an % 4 == 0 or (an % 100 == 0 and an % 400 == 0)):
            if di > 29:
                di = 1
                me += 1
        elif di > 28:
            di = 1
            me += 1
    return (di,me,an)
#print(diaSiguienteE((31,12,2000)))

#EJ 16
# t = (Dia,Mes,Año) - Int Str Int
def diaSiguienteT(t):
    meses = ["Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"]
    temp = diaSiguienteE((t[0],meses.index(t[1])+1,t[2]))
    return (temp[0],meses[temp[1]-1],temp[2])
#print(diaSiguienteT((32,"Ene",2015)))

#EJ 17
# t = (Domino1,Domino2) - Int Int
def encajaTuplas(t1,t2):
    dom1 = set([t1[0],t1[1]])
    dom2 = set([t2[0],t2[1]])
    if dom1 & dom2: return True
    return False
#print(encajaTuplas((2,3),(3,4)))

def encajaLista(s):
    dominoes = s.split()
    dom1 = set(dominoes[0].split("-"))
    dom2 = set(dominoes[1].split("-"))
    if dom1 & dom2: return True
    return False
#print(encajaLista("3-5 5-1"))

#------------------------------------------------------------------------------------#
# PRACTICA 4

#EJ 1
def esta(l,n):
    if n in l : return True
    return False
#print(esta([12,2,2,5,6,7,54,33,5,6,8,9,4,242,5,5,5,2,23,25,25,5,25,235,23,52,5,235],111))

def apariciones(l,n):
    contador = 0
    for i in l:
        if i == n: contador += 1
    return contador
#print(apariciones([12,2,2,5,6,7,54,33,6,8,9,4,242,5,2,23,25,25,25,235,23,52,5,235],5))

def posicionElemento(l,n):
    contador = 0
    while(contador <= len(l) and l[contador] != n):
        contador += 1
    return contador + 1
#print(posicionElemento([12,2,2,5,6,7,54,33,6,8,9,4,242,5,2,23,25,25,25,235,23,52,5,235],5))

def posicionElementos(l,n):
    posiciones = []
    pos = 0
    while(esta(l,n)):
        posiciones.append(posicionElemento(l,n))
        l = l[posiciones[pos]:]
        pos += 1
    return sumaAcumulada(posiciones)
#print(posicionElementos([12,2,2,5,6,7,54,33,5,6,8,9,4,242,5,5,5,2,23,25,25,5,25,235,23,52,5,235],5))

#EJ 2
def valMax(l):
    return max(l)
#print(valMax([1,2,312,31,12,3123,123,123,123,1231,231,231,2,51,5,262,43,2,42,6,27,4,57,48,48]))

# t = (valMax,pos)
def posValMax(l):
    v = valMax(l)
    contador = 0
    while(contador <= len(l) and v != l[contador]):
        contador += 1
    return (v,contador+1)
#print(posValMax([1,2,312,31,12,3123,123,123,123,1231,231,231,2,51,5,262,43,2,42,6,27,4,57,48,48]))

#EJ 3
def posicionBinaria(l,n):
    l = eliminaDuplicados(l)
    inicio = 0
    fin = len(l) - 1
    medio = (inicio + fin) // 2
    while(n != l[medio] and inicio <= fin):
        if n > l[medio]: 
            inicio = medio + 1
        if n < l[medio]:
            fin = medio - 1
        medio = (inicio + fin) // 2
    if n == l[medio]: return medio+1
    l.insert(medio+1,n)
    return l
#print(posicionBinaria([1,2,312,31,12,3123,123,123,123,1231,231,231,2,51,5,262,43,2,42,6,27,4,57,48,48],123))

#EJ 4
def tuplasDiccionarios(l):
    d = {}
    for (clave,valor) in l:
        d[clave] = valor
    return d
#print(tuplasDiccionarios([("n",2),(2,3),("o","magic"),("ogt",[1,2,3]),("h",(1,2)),("n",57)]))

#EJ 5
def aparicionesPalabras(s):
    l = s.split()
    d = {}
    for i in l:
        d[i] = d.get(i,0) + 1
    return d
#print(aparicionesPalabras("que lindo que es el lindo dia de hoy"))

def aparicionesCaracteres(s):
    d = {}
    for i in s:
        d[i] = d.get(i,0) + 1
    return d
#print(aparicionesCaracteres("que lindo que es el lindo dia de hoy"))

def diccioDados(n):
    d = {}
    while(n != 0):
        d1 = randint(1,6)
        d2 = randint(1,6)
        d[d1+d2] = d.get(d1+d2,0)+1
        n -= 1
    return d
#print(diccioDados(17))

#EJ 6
def caracterPalabra(s):
    l = s.split()
    d = {}
    for palabra in l:
        for caracter in set(palabra):
            if caracter not in d or len(palabra) > len(d[caracter]): d[caracter] = palabra
    return d
#print(caracterPalabra("hola que lindo dia que hace este lindo dia hace calor tambien no"))

#EJ 7
def promL(l):
    return sum(l) / len(l)

def promedioEstudiante(d,n):
    if n in d:
        return promL(d[n])
    return None
#print(promedioEstudiante({"juan":[1,2,3,4,5,6,7,8,9,10],"pedro":[10,9,10,10],"zapata":[1,1,0,-1]},"juan"))

def mayorPromedio(d):
    mPromedio = 0
    estudiante = ""
    for k in d:
        promedio = promedioEstudiante(d,k)
        if promedio > mPromedio: 
            mPromedio = promedio
            estudiante = k
    return estudiante
#print(mayorPromedio({"juan":[1,2,3,4,5,6,7,8,9,10,10,10,10],"pedro":[10,9,10,10],"zapata":[1,1,0,-1]}))

#EJ 8
def sinonimos(d,s):
    print(s)
    palabras = s.split()
    i = 0
    for p in palabras:
        if p in d:
            palabras[i] = d[p][randrange(0,len(d[p]))]
        i += 1
    return " ".join(palabras)
#print(sinonimos({"hola":["ola","jola"],"estan":["etan","tan"],"mis":["mi","my"],"personas":["hente","jente"],},"hola como estan mis personas"))

#EJ 9
def compra(precio,cantidad):
    compra = 0
    for i in precio:
        compra += precio[i] * cantidad[i]
    return compra
#print(compra({"fernet":200,"coca":55,"pepsi":50},{"coca":2,"fernet":5,"pepsi":3}))

#EJ 10
def elimDup(l):
    return set(l)
#print(elimDup([1,1,1,1,1,2,31,23,123,123,1241,415,1512,23,1234124,12,1231,2312,312]))

#EJ 11
def unionPalabras(s1,s2):
    return set(s1.lower().split()) | set(s2.lower().split())
#print(unionPalabras("perro casa Arbol","Arbol pero comadreja"))

#EJ 12
def eliminarComunes(c1,c2):
    return (c1 - c2) | (c2 - c1)
#print(eliminarComunes({1,2,3},{2,3,4}))

#EJ 13
def menorMax(l):
    elemLista = set(l) - {max(l)}
    i = max(l) - 1
    c = set()
    while(i != 0):
        if i not in elemLista: c.add(i)
        i -= 1
    return c
#print(menorMax([1,100,100,12,35,1,31,25,12,31,51,2,31,54,26,83,83,13,15,74,1,26,84,99]))

#EJ 14
def reunion(d):
    c = set()
    for i in d:
        temp = set(d[i])
        if c == set(): c = temp
        c = c & temp
    return c
#print(reunion({"juan":["lunes","martes","miercoles","domingo"],"jose":["lunes","domingo"],"camila":["domingo","lunes","jueves"],"pedro":["lunes","viernes","sabado","domingo"],"kuagmire":["lunes","domingo"]}))

#------------------------------------------------------------------------------------#
# PRACTICA 5

#EJ 1
def nLineasArchivo(n):
    f = open("EJ1.txt","r")
    for i in range(0,n):
        print(f.readline())
    f.close()
#nLineasArchivo(4)

#EJ 2
def copiarArchivos():
    c = open("EJ2-C.txt","r")
    p = open("EJ2-P.txt","w")
    letra = c.read(1)
    while(letra != ""):
       p.write(letra)
       letra = c.read(1)
    c.close()
    p.close()
#copiarArchivos()

#EJ 3
def statsArchivo(): 
    f = open("EJ3.txt","r")
    contLetras = 0
    contPalabras = 0
    contLineas = 0
    letra = f.read(1)
    while(letra != ""):
        if(letra != " "):
            contLetras += 1
        if(letra == "\n"):
            contLineas += 1
        if(letra == " " or letra == "\n"):
            contPalabras += 1
        letra = f.read(1)
    if(contLineas > 0): contLineas += 1
    f.close()
    print(contLetras,contPalabras,contLineas)
#statsArchivo()

#EJ 4
def buscarExpresion(s):
    f = open("EJ4.txt","r")
    linea = f.readline()
    while(linea != ""):
        bandera = 0
        for i in linea.split():
            if i == s:
                bandera = 1
        if bandera: print(linea)
        linea = f.readline()
    f.close()
#buscarExpresion("know")

#EJ 5
def encriptadoArchivo():
    c = open("EJ5-C.txt","r")
    p = open("EJ5-P.txt","w")
    letra = c.read(1)
    while(letra != ""):
        if (letra >= 'a' and letra <= 'z') or (letra >= 'A' and letra <= 'Z'): letra = chr((ord(letra)+13)%26)
        p.write(letra)
        letra = c.read(1)
    c.close()
    p.close()
#encriptadoArchivo()

#EJ 6
def cargarDatos():
    f = open("EJ6-C.txt","r")
    linea = f.readline()
    d = {}
    while(linea != ""):
        l = linea.split()
        d[l[0]] = l[1]
        linea = f.readline()
    f.close()
    return d
#print(cargarDatos())

def guardarDatos(d):
    f = open("EJ6-P.txt","w")
    for i in d:
        s = i + " " + d[i] + "\n"
        f.write(s)
    f.close()
#guardarDatos(cargarDatos())