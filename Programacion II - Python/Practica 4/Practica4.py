# LISTAS Y SECUENCIAS
#Ej 1
def apariciones(l,x):
    cant = x
    for i in l:
        if x == i:
            cant += 1
    print("En la lista:",l)        
    print("La cantidad de",x, "es :",cant)

#Agregar posibilidad de que el elemento no este en la lista
def primeraCoincidencia(l,x):
    pos = 0
    while x != l[pos]:
        pos += 1
    #print("En la lista:",l)
    #print("La primera aparicion del elemento",x,"es en:",pos)
    return pos

#Arreglar funcion - ver si es mejor hacerla recursiva
def posicionesCoincidencias(l,x):
    lista_posiciones = []
    j = 0
    i = 0
    while j < len(l):
        lista_posiciones.append(primeraCoincidencia(l[j:],x))
        j = lista_posiciones[i]+1
        i += 1
    print("La lista de posiciones es:",lista_posiciones)

#posicionesCoincidencias([1,2,1,1,51,12],1)

#Ej 2

# DICCIONARIOS
#Ej 4
def tuplas_a_diccionarios(l):
    d = {}
    i = 0
    for (x,y) in l:
        d[x] = y
    return d

#Ej 5
#a
def contarApariciones1(str):
    l = str.split()
    l.sort()
    cant = 0
    d = {}
    for i in range(0,len(l)-1):
        if l[i] == l[i+1]:
            cant += 1
        else:
            d[l[i]] = cant + 1
    return d

def contarApariciones2(str):
    l = str.split()
    cant = 0
    d = {}
    for i in l:
        if i not in d.keys():
            d[i] = 1
        else:
            d[i] += 1
    
    return d

#b
def contarCaracteres(str):
    d = {}
    for i in str:
        if i not in d.keys():
            d[i] = 1
        else:
            d[i] += 1
    return d

#c


#Ej 9
#d1:{prod:precio} d2:{prod:cant}
def suma_carritos(d1, d2):
    suma_total = 0
    for i in d1.keys():
        suma_total = d1[i]*d2[i]
    return suma_total
    


# CONJUNTOS
#Ej 10
def eliminaDuplicados(l):
    c = set(l)
    return c

#Ej 11 HACER QUE NO TENGA EN CUENTA MAYUSC NI MINUSC
def conjuntoPalabras(str1,str2):
    c = set()
    l = str1.split()
    c.update(l)
    l = str2.split()
    c.update(l)
    return c

#Ej 12
def difConjuntos(c1,c2):
    return c1-c2

#Ej 13
def menoresN(l):
    c = set(l)
    aux = 0
    largo = 0
    for i in c:
        largo += 1
        if i > aux:
            aux = i
    l = [0]*(aux-largo)
    j = 1
    for i in l:
        l[i] = j
        j += 1
    c = set(l)
    print(c)


menoresN([1,2,51,1,12,1,1,2,49,6,7,4,43,3,37])


