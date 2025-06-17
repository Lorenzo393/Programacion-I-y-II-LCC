from random import *
#a) Las parejas entre un menor y un mayor de 18 años no son aceptadas;
#b) Las parejas entre un menor de 11 años y un mayor de 14 años no son aceptadas;
#c) Las parejas entre un menor de 15 años y un mayor de 18 años no son aceptadas;
#d) Una persona de 10 años o menos no puede estar en pareja;
#e) El genero de cada persona de la pareja debe coincidir con el genero de inter ́es de la restante;
#f) La localidad de residencia debe ser la misma.

# 0 - 10 || 11 - 14 || 15 - 17 || 18 - 99
#a) Tome una persona del grupo de forma aleatoria.
#b) Recorra el grupo restante buscando una persona que sea compatible con la primera seleccionada(segun los requisitos descriptos m ́as arriba).
#c) Si encuentra una persona compatible, emparejarlos y quitarlos del grupo ya que ya no est ́an disponibles.
#d) Si no existe una persona compatible, separe a la persona como persona soltera.
#e) Repita el proceso hasta que el grupo de personas est ́e vac ́ıo.

# 1 - Filtro de edades
# 2 - filtro localidades y genero de interes

def quitar_terminador(cadena):
    return cadena[:-1]

def cargar_datos_lista(file):
    lista = []
    for linea in file.readlines():
        lista.append(quitar_terminador(linea).split(","))
    return lista

def lista_listaTupla(lista):
    listaTupla = []
    for (nom,ape,gen,eda,genI,loc) in lista:
        tupla = (nom,ape,gen,int(eda),genI,loc)
        listaTupla.append(tupla)
    return listaTupla
    
def filtro_diccionario(listaTupla):
    dicPersonas = {(0,10):[],(11,14):[],(15,17):[],(18,99):[]}
    for (nom,ape,gen,eda,genI,loc) in listaTupla:
        if(eda <= 10):
            dicPersonas[(0,10)].append((nom,ape,gen,eda,genI,loc))
        elif(eda <= 14):
            dicPersonas[(11,14)].append((nom,ape,gen,eda,genI,loc))
        elif(eda <= 17):
            dicPersonas[(15,17)].append((nom,ape,gen,eda,genI,loc))
        elif(eda <= 99):
            dicPersonas[(18,99)].append((nom,ape,gen,eda,genI,loc))
        dicPersonas[(0,10)] = [] # Menores de 10 no pueden tener pareja
    return dicPersonas

def file_diccionario_edad(file):
    listaFile = cargar_datos_lista(file)
    listaTupla = lista_listaTupla(listaFile)
    dicPersonas = filtro_diccionario(listaTupla)
    return dicPersonas

def eliminar_persona(lista, nPersona):
    lista = lista[ : nPersona] + lista[nPersona + 1 : len(lista)]
    return lista

def agregar_pareja(lista, pAleatoria, pComparacion):
    nom1 = pAleatoria[0]
    ape1 = pAleatoria[1]
    eda1 = pAleatoria[3]
    nom2 = pComparacion[0]
    ape2 = pComparacion[1]
    eda2 = pComparacion[3]
    loc = pAleatoria[-1]
    tupla = (nom1,ape1,str(eda1),nom2,ape2,str(eda2),loc)
    lista.append(tupla)
    return lista

def agregar_soltero(lista, pAleatoria):
    nom = pAleatoria[0]
    ape = pAleatoria[1]
    eda = pAleatoria[3]
    loc = pAleatoria[-1]
    tupla = (nom,ape,str(eda),loc)
    lista.append(tupla)
    return lista

def matching(dicPersonas):
    dicMatch = {"parejas":[],"solteros":[]}
    for key in dicPersonas.keys():
        while dicPersonas[key] != []:
            if len(dicPersonas[key]) > 0:
                nAleatorio = randrange(len(dicPersonas[key]))
            else:
                nAleatorio = 0
            pAleatoria = dicPersonas[key][nAleatorio]
            nComparacion = 0
            soltero = True
            while soltero and len(dicPersonas[key]) > 1 and nComparacion != len(dicPersonas[key]):
                pComparacion = dicPersonas[key][nComparacion]
                if nAleatorio != nComparacion:
                    if (pAleatoria[-1] == pComparacion[-1]) and (pAleatoria[2] == pComparacion[-2]) and (pAleatoria[-2] == pComparacion[2]):
                        dicMatch["parejas"] = agregar_pareja(dicMatch["parejas"], pAleatoria, pComparacion)
                        dicPersonas[key] = eliminar_persona(dicPersonas[key], nAleatorio)
                        dicPersonas[key] = eliminar_persona(dicPersonas[key], nComparacion)
                        soltero = False
                nComparacion += 1
            if soltero:
                dicMatch["solteros"] = agregar_soltero(dicMatch["solteros"], pAleatoria)
                dicPersonas[key] = eliminar_persona(dicPersonas[key], nAleatorio)
    return dicMatch

def imprimir_parejas(fileMatching, dicMatch):
    listaParejas = dicMatch["parejas"]
    listaSolteros = dicMatch["solteros"]

    fileMatching.write("Parejas:\n")
    for (nom1,ape1,eda1,nom2,ape2,eda2,loc) in listaParejas:
        cadena = nom1 + ", " + ape1 + ", " + eda1 + " - " + nom2 + ", " + ape2 + ", " + eda2 + " - " + loc + "\n"
        fileMatching.write(cadena)

    fileMatching.write("\nPersonas Solteras:\n")
    for (nom,ape,eda,loc) in listaSolteros:
        cadena = nom + ", " + ape + ", " + eda + " - " + loc + "\n"
        fileMatching.write(cadena)


def main():
    filePersonas = open("salida.txt","r")
    dicPersonas = file_diccionario_edad(filePersonas)
    filePersonas.close()
    
    dicMatch = matching(dicPersonas)
    print(dicPersonas)

    fileMatching = open("matching.txt","w")
    imprimir_parejas(fileMatching, dicMatch)
    fileMatching.close()
    
    
main()