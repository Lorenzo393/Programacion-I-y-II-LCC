# Toma 3 numeros y hace una sucesion de fibonacci iniciando con los primeros 2 numeros
#y retorna el numero n del la sucesion

def lucasFL(f1 , f2 , n):
    l = [f1,f2]
    for i in range(n):
        l.append(l[-2] + l[-1])
    return l

print(lucasFL(2,1,9))

# Falta hacer lucasF que retorna el valor en n y no la lista completa

def lucasR(f1 , f2 , n):
    if n > 0:
        return lucasR(f2 , f1+f2 , n-1)
    else:
        return f2

print(lucasR(2,1,9))

# Hice el ejercicio de 3 maneras la primera te da la lista completa de la sucesion
#hasta n usando FOR el segundo retorna el numero n de la sucesion usando FOR y el
#tercero retorna el numero n de la sucesion usando RECURSION