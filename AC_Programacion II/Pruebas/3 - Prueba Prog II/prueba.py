from random import *

def lista_archivo(file):
    lista = []
    for i in file.readlines():
        lista.append(i[:-1])
    return lista





def main():
    file = open("salida.txt","r")
    lista = lista_archivo(file)
    file.close()

    cantAulas = lista[0]
    lista = lista[1:]
    




main()