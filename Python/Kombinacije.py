import re
import math  

v1 = "+"
v2 = "+"
v3 = "+"

results = []
equations = []
sorts = []
duplicates = []
lastint = -1

#0 = plus
#1 = minus
#2 = puta
#3 = podjeljeno

vars = ["+","-","*","/"]
dodatni = [" 1","-1"]
dodatni2 = ["2","2**2","2**3","2**4","2**5"]
dodatni3 = ["3","3**2","3**3","3**4","3**5"]
dodatni4 = ["4","4**2","4**3","4**4","4**5","math.sqrt(4)"]

def is_integer_num(num):
    if isinstance(num, int):
        return True
    return False

for i in range (0,len(vars)):
    v1 = vars[i]

    for j in range (0,len(vars)):
        v2 = vars[j]

        for k in range (0,len(vars)):
            v3 = vars[k]

            for l in range (0,2):
                v01 = dodatni[l]

                for m in range (0,len(dodatni2)):
                    v02 = dodatni2[m]

                    for n in range (0,len(dodatni3)):
                        v03 = dodatni3[n]

                        for o in range (0,len(dodatni4)):
                            v04 = dodatni4[o]

                            if(is_integer_num(eval(v01 + v1+v02+ v2+ v03 + v3 + v04))):
                                if(eval(v01 + v1+v02+ v2+ v03 + v3 + v04) >= 0):
                                    strings = str(v01+ v1+v02+ v2+ v03 + v3 + v04 + "=")
                                    strings2 = strings.replace("**2","^2")
                                    strings3 = strings2.replace("**3","^3")
                                    strings4 = strings3.replace("**4","^4")
                                    strings5 = strings4.replace("**5","^5")
                                    strings6 = strings5.replace("math.sqrt(4)","√4")
                                    newstr = (strings6, eval(v01+ v1+v02+ v2+ v03 + v3 + v04))
                                    equations.append(newstr)



sortirano = sorted(equations, key=lambda tup: tup[1])
for z in range(0,len(sortirano)):
    ints = str(sortirano[z][1])
    if(ints!=lastint):
        print(sortirano[z][0]+ints)
    lastint = ints



    