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

def listaDividida_listaTupla_2elem(listaDividida):
    listaTupla = []
    for (x,y) in listaDividida:
        tuplaAux = (x,int(y))
        listaTupla.append(tuplaAux)
    return listaTupla

def listaDividida_listaTupla_5elem(listaDividida):
    listaTupla = []
    for (v,w,x,y,z) in listaDividida:
        tuplaAux = ((v,int(w),x,int(y)),int(z))
        listaTupla.append(tuplaAux)
    return listaTupla

def cargar_datos_diccionario(fileArticulos):
    lista = cargar_datos_lista(fileArticulos)
    listaDividida = dividir_lista(lista)
    listaTupla = []
    if(len(listaDividida[0]) == 2): 
        listaTupla = listaDividida_listaTupla_2elem(listaDividida)
    return dict(listaTupla)

def cargar_datos_listaTuplas(file):
    lista = cargar_datos_lista(file)
    listaDividida = dividir_lista(lista)
    listaTupla = []
    if(len(listaDividida[0]) == 5): 
        listaTupla = listaDividida_listaTupla_5elem(listaDividida)
    return listaTupla
    
        





def main():
    fileArticulos = open("articulos.txt","r")
    dicArticulos = cargar_datos_diccionario(fileArticulos)
    fileArticulos.close()
    print("Articulos: ",dicArticulos,"\n")

    fileCarrito = open("carrito.txt","r")
    dicCarrito = cargar_datos_diccionario(fileCarrito)
    fileCarrito.close()
    print("Carrito: ",dicCarrito,"\n")

    filePromociones = open("promociones.txt","r")
    listaPromociones = cargar_datos_listaTuplas(filePromociones)
    filePromociones.close()
    print("Promociones: ",listaPromociones,"\n")

    
    
    
    
    







main()