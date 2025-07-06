from random import *

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

def carrito_vacio(dicCarrito):
    flag = True
    for i in dicCarrito.keys():
        if(dicCarrito[i] != 0):
            flag = False
    return flag

def calcular_promociones(dicCarrito,listaPromociones): #Calcula el precio total y al mismo tiempo modifica los valores del dicCarrito
    numeroPromociones = len(listaPromociones)
    indicePromocion = randrange(numeroPromociones)
    promocionesAplicadas = []
    costoTotal = 0
    promocionesProbadas = 0
    while(promocionesProbadas < numeroPromociones):
            while(indicePromocion in promocionesAplicadas):
                indicePromocion = randrange(numeroPromociones)
            promocionesAplicadas.append(indicePromocion)

            nombreProd1 = listaPromociones[indicePromocion][0][0]
            cantProd1 = listaPromociones[indicePromocion][0][1]
            nombreProd2 = listaPromociones[indicePromocion][0][2]
            cantProd2 = listaPromociones[indicePromocion][0][3]
            precioPromo = listaPromociones[indicePromocion][1]

            if(nombreProd1 in dicCarrito.keys() and nombreProd2 in dicCarrito.keys()):
                while(dicCarrito[nombreProd1] >= cantProd1 and dicCarrito[nombreProd2] >= cantProd2):
                    dicCarrito[nombreProd1] -= cantProd1
                    dicCarrito[nombreProd2] -= cantProd2
                    print(nombreProd1,", ",cantProd1, " - " ,nombreProd2,", ",cantProd2, " - " ,precioPromo)
                    costoTotal += precioPromo
            promocionesProbadas+=1
    return costoTotal

def calcular_articulos_sueltos(dicCarrito, dicArticulos):
    costoTotal = 0
    for producto in dicCarrito.keys():
        if(dicCarrito[producto] > 0):
            precioProducto = dicArticulos[producto]
            cantProducto = dicCarrito[producto]
            precioTotal = precioProducto * cantProducto
            costoTotal += precioTotal
            dicCarrito[producto] = 0
            print(producto,", ",cantProducto,", ",precioProducto," - ",precioTotal)
    return costoTotal

def ticket_costo_carrito(dicArticulos, dicCarrito, listaPromociones):
    costoTotal = 0
    if(len(listaPromociones) > 0):
        print("Promociones:")
        print(dicCarrito)
        costoTotal += calcular_promociones(dicCarrito,listaPromociones)
    print("Articulos Sueltos:")
    costoTotal += calcular_articulos_sueltos(dicCarrito, dicArticulos)
    print("Total:")
    print(costoTotal)

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

    ticket_costo_carrito(dicArticulos, dicCarrito, listaPromociones)
    
main()