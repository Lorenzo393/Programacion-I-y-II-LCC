# Algunos ejercicios los hago de forma recursiva e iterativa
# Ej 1
def posMult(l,n):
    return l[::n]

#print(posMult([1,2,3,4,5,6,7,8,9,10],2))
#print(posMult([1,2,3,4,5,6,7,8,9,10],3))
#print(posMult([1,2,3,4,5,6,7,8,9,10],0)) SOLUCIONAR

# Ej 2
def sumaacR(l):
    def aux(l , r = [l[0]]):
        if l[1:] == []:
            return r
        else:
            r.append(l[1]+r[len(r)-1])
            return aux(l[1:],r)
    return aux(l)

#print(sumaacR([1,2,3,4,5,6,7,8]))
#print(sumaacR([1]))
#SOLUCIONAR print(sumaacR([]))

# Ej 3
def eliminaR(l):
    return l[1 : len(l)-1]

#print(eliminaR([1,2,3,4,5,6,7,8,9,10]))
#print(eliminaR([]))

# Ej 4
def ordenadaR(l):
    if l[1:] == []:
        return True
    if l[0] < l[1]:
        return ordenadaR(l[1:])
    else:
        return False
#print(ordenadaR([1,2,3,4,5,6]))
#print(ordenadaR(['a','b','c','d','e']))
#print(ordenadaR([]))
#print(ordenadaR([1,2,3,6,4]))