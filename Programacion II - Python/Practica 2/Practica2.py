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
        r = 1
        for i in range(1,n+1):
            r = i * r
        print(r)

#factoriales(2)

#Ej 5