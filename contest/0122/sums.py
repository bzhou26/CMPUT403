import sys
from itertools import permutations



#def choose(l):
    #global cont
    #if cont = len(object)

def main():
    file_list = []
    num_set = []
    query_set = []
    distance = set()
    cont=0
    alldis=set()   
    #for line in sys.stdin:
        #n = int(line);
        #i=0
        #while(i<n):
            #for line in sys.stdin:
                #num_set.append(int(line))
            #i += 1
        #for line in sys.stdin:
        
    filename="F.0.in"
    f = open(filename,"r")
    for line in f:
        file_list.append(int(line))
    i=0
    pos = 0
    n=0
    m=0
    while (pos < len(file_list)):
        if i == 0:
            n = file_list[pos]
            pos += 1
            while (i<n):
                num_set.append(str(file_list[pos]))
                i+=1
                pos+=1
            i=0
            m = file_list[pos]
            pos += 1
            while (i<m):
                query_set.append(file_list[pos])
                i+=1
                pos +=1
            i=0
        ##
        ii=0
        num_string = "".join(num_set)
        distance = (list(permutations(num_string)))
        for c in distance:
            alldis.add(abs(int(c[1])-int(c[2])))
        mindis=
        iii = 0
        for p in alldis:
            if abs(p - query_set[iii])
        
        
        
           

main()