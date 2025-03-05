from random import *

def listaPromociones():
    f = open("promociones.txt","r"); #AHORA FUNCIONA
    l = f.readlines()
    f.close()
    listaDividida = []
    listaLimpia = []
    for i in l:
        listaDividida.append(i.split(","))
    for (prod1,pre1,prod2,pre2,total) in listaDividida:
        listaLimpia.append([[prod1,int(pre1),prod2,int(pre2)],[int(total[:-1])]])    
    return listaLimpia

def dicCarrito():
    f = open("carrito.txt","r")
    l = f.readlines()
    f.close()
    listaDividida = []
    listaLimpia = []
    for i in l:
        listaDividida.append(i.split(","))
    for (prod,cant) in listaDividida:
        listaLimpia.append([(prod),(int(cant[:-1]))])
    dic = dict(listaLimpia)    
    return dic

def dicArticulos():
    f = open("articulos.txt","r")
    l = f.readlines()
    f.close()
    listaDividida = []
    listaLimpia = []
    for i in l:
        listaDividida.append(i.split(","))
    for (prod,pre) in listaDividida:
        listaLimpia.append([(prod),(int(pre[:-1]))])
    dic = dict(listaLimpia)
    return dic

def aclararCarrito():
    carrito = dicCarrito()
    articulos = dicArticulos()
    for i in articulos:
        carrito[i] = carrito.get(i,0)
    return carrito

def carritoVacio(carrito):
    bandera = 0
    for i in carrito:
        if(carrito[i]) != 0:
            bandera = 1
    if(bandera == 1):
        return False
    return True


def precioFinal():
    promociones = listaPromociones()
    carrito = aclararCarrito()
    articulos = dicArticulos()
    
    total = 0
    rand = randrange(len(promociones))
    
    print("Promociones:")
    while(len(promociones) > 0):
        promo = promociones[rand]
        
        prod1 = promo[0][0] 
        cant1 =  promo[0][1]
        prod2 = promo[0][2]
        cant2 = promo[0][3]
        precio = promo[1][0]
        
        if(carrito[prod1] >= cant1 and carrito[prod2] >= cant2):
            total += precio
            carrito[prod1] -= cant1
            carrito[prod2] -= cant2
            print(prod1,cant1,prod2,cant2,precio)
        else:
            promociones = promociones[0:rand] + promociones[rand+1:len(promociones)]
            if (len(promociones) != 0):
                rand = randrange(len(promociones))
    print("\n")
    print("Articulos Sueltos:")   
    for i in carrito:
        if carrito[i] > 0:
            prodSuelto = carrito[i]*articulos[i]
            total += prodSuelto
            print(i,carrito[i],articulos[i],prodSuelto)
            carrito[i] = 0
    print("\n")
    print("Total:")
    print(total)  

precioFinal()