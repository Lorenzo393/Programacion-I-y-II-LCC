def quitar_terminador(cadena):
    return cadena[:-1]

def cargar_datos_lista(fileArticulos):
    lista = []
    for linea in fileArticulos.readlines():
        lista.append(quitar_terminador(linea))
    return lista

def dividir_lista(lista):
    listaDividida = []
    for linea in lista:
        listaDividida.append(linea.split(","))
    return listaDividida

def listaDividida_listaTupla(listaDividida):
    listaTupla = []
    for (x,y) in listaDividida:
        tuplaAux = (x,int(y))
        listaTupla.append(tuplaAux)
    return listaTupla

def cargar_datos_diccionario(fileArticulos):
    lista = cargar_datos_lista(fileArticulos)
    listaDividida = dividir_lista(lista)
    listaTupla = listaDividida_listaTupla(listaDividida)
    return dict(listaTupla)

    
    
        





def main():
    fileArticulos = open("articulos.txt","r")
    diccionarioArticulos = cargar_datos_diccionario(fileArticulos)
    fileArticulos.close()
    print(diccionarioArticulos)

    fileCarrito = open("carrito.txt","r")
    diccionarioCarrito = cargar_datos_diccionario(fileCarrito)
    fileCarrito.close()
    print(diccionarioCarrito)

    
    
    
    
    







main()