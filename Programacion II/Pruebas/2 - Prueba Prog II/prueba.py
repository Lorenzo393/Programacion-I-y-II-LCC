#a) Las parejas entre un menor y un mayor de 18 a ̃nos no son aceptadas;
#b) Las parejas entre un menor de 11 a ̃nos y un mayor de 14 a ̃nos no son aceptadas;
#c) Las parejas entre un menor de 15 a ̃nos y un mayor de 18 a ̃nos no son aceptadas;
#d) Una persona de 10 a ̃nos o menos no puede estar en pareja;
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
        lista.append(quitar_terminador(linea))
    return lista

def file_diccionarios(file):
    listaFile = cargar_datos_lista(file)
    return listaFile

def main():
    file = open("salida.txt","r")
    dicPersonas = file_diccionarios(file)
    file.close()
    print(dicPersonas[0],"|",len(dicPersonas[0]))

main()