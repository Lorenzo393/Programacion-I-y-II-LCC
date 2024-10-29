# LISTAS
#Ej 1
def posMult(l,n):
    return l[::n]

#Ej 2
def sumaacR(l):
    def aux(l , r = [l[0]]):
        if l[1:] == []:
            return r
        else:
            r.append(l[1]+r[len(r)-1])
            return aux(l[1:],r)
    return aux(l)

#Ej 3
def eliminaR(l):
    return l[1 : len(l)-1]

#Ej 4
def ordenadaR(l):
    if l[1:] == []:
        return True
    if l[0] < l[1]:
        return ordenadaR(l[1:])
    else:
        return False

#Ej 5

def duplicado(l):
    lista_ordenada = l.sort()
    i = 0
    while lista_ordenada[i] != lista_ordenada[i+1] and i < len(l)-2:
        i += 1
    if i == len(l)-2:
        return False
    return True

#Ej 6
def elimina_duplicado(l):
    l.sort()
    aux = l[0]
    r = [l[0]]
    for i in range(len(l)):
        if aux != l[i]:
            r.append(l[i])
            aux = l[i]
    return r

#Ej 7
def cant_duplicados(l):
    return len(elimina_duplicado(l))

#Ej 8 AVANZAR
from math import floor
from math import ceil

def busquedaDicotomica(l , palabra):
    l.sort()
    ini = 0
    fin = len(l)-1
    mid = floor((ini+fin)/2)
    contador = 1
    while l[mid] != palabra and (fin-ini) != 1:
        contador += 1
        if palabra > l[mid]:
            ini = mid+1
        if palabra < l[mid]:
            fin = mid - 1
        mid = floor((ini+fin)/2)

    print("lista:",l)
    print("palabra:",palabra)
    print("operaciones:",contador)
    if l[fin] == palabra or l[ini] == palabra or l[mid] == palabra:
        return True
    return False
    
    
#print(busquedaDicotomica([1,2,3,7,9,4,8,84,25,79,262,234,723,4384,22,14,63,13,53,15,16,17,18],17))

# CADENAS
#Ej 9
def voltear(str):
    return str[-1:(-len(str))-1:-1]

#Ej 10
def contar(str , x):
    cantidad = 0
    for i in str:
        if x == i:
            cantidad += 1
    print("Cantidad de" , x , ":" , cantidad)
    

#Ej 11
def vocales(str):
    cantidad = 0
    for i in str:
        a = i.lower()
        if a == "a" or a == "e" or a == "i" or a == "o" or a == "u":
            cantidad += 1
    print("Cantidad de vocales: " , cantidad)

#Ej 12
def palabrasMasCinco(str):
    cantidad = 0
    aux = 0
    for i in str:
        if i != " ":
            aux += 1
        elif aux >= 5:
            aux = 0
            cantidad += 1
    print("Cantidad de palabras de mas de 5 letras: " , cantidad)

# TUPLAS
#Ej 13
# represento a las cartas mediante tuplas 
# carta: (N° , Palo)
def barajaFrancesa():
    for i in range(0,4):
        print("")
        for j in range(1,14):
            if i == 0:
                if j == 1:
                    t = ("A","D")
                elif j == 11:
                    t = ("J","D")
                elif j == 12:
                    t = ("Q","D")
                elif j == 13:
                    t = ("K","D")
                else:
                    t = (j,"D")
            if i == 1:
                if j == 1:
                    t = ("A","P")
                elif j == 11:
                    t = ("J","P")
                elif j == 12:
                    t = ("Q","P")
                elif j == 13:
                    t = ("K","P")
                else:
                    t = (j,"P")
            if i == 2:
                if j == 1:
                    t = ("A","T")
                elif j == 11:
                    t = ("J","T")
                elif j == 12:
                    t = ("Q","T")
                elif j == 13:
                    t = ("K","T")
                else:
                    t = (j,"T")
            if i == 3:
                if j == 1:
                    t = ("A","C")
                elif j == 11:
                    t = ("J","C")
                elif j == 12:
                    t = ("Q","C")
                elif j == 13:
                    t = ("K","C")
                else:
                    t = (j,"C")
            print(t)

# Terminar
def poker(c1,c2,c3,c4,c5):
    contador = 0


#Ej 14
# Represento al tiempo mediante una tupla
# tiempo: (horas , minutos , segundos)

def sumaTiempo(t1,t2):
    seg = t1[2] + t2[2]
    min = t1[1] + t2[1]
    h = t1[0] + t2[0]

    while seg > 60:
        seg -= 60
        min += 1
    while min > 60:
        min -= 60
        h += 1
    suma_tiempo = (h , min , seg)
    print(suma_tiempo)

#sumaTiempo((2,30,45),(5,31,27))

#Ej 15
# fecha: (dia,mes,año)

# 31 dias: 1 - 3 - 5 - 7 - 8 - 10 - 12 
# 30 dias: 4 - 6 - 9 - 11
# 28/29 dias : 2

def diaSiguiente(t):
    dia = t[0] + 1
    mes = t[1]
    año = t[2]
    
    meses_31 = [1,3,5,7,8,10,12]
    
    if mes in meses_31 and dia > 31:
        mes += 1
        dia = 1
    elif mes == 2:
        if año % 4 == 0 and dia > 29:
            mes += 1
            dia = 1
        elif dia > 28:
            mes += 1
            dia = 1
    elif dia > 30:
        mes += 1
        dia = 1
    if mes > 12:
        año += 1
        mes = 1
        dia = 1
    diaSig = (dia,mes,año)
    return diaSig

#Ej 16
def diaSiguienteT(t):
    diaSig = diaSiguiente(t)
    mesTraducido = traducirMes(diaSig[1])
    diaSigT = (diaSig[0],mesTraducido,diaSig[2])
    return diaSigT

def traducirMes(m):
    traduccion = ["ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"]
    return traduccion[m-1]

print(diaSiguienteT((31,12,2012)))