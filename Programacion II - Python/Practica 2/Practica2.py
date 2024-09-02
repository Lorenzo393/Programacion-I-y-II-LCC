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
def farCel():
    for i in range(0,121,10):
        print((i-32)*5/9)

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