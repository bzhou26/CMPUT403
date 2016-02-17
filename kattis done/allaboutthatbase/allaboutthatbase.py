'''
   Kattis ID: < allaboutthatbase >
   Topic: (Arithmetic)
   Level: 1 point
   Brief problem description: 

   we interpret the number 7234572345 as:
   7×10^4+2×10^3+3×10^2+4×10^1+5×10^0.   
   Your job is to determine the bases in which given arithmetic
   expressions are valid. We define an expression as valid in 
   base BB if two conditions are true. 
   First, all the operands used are interpretable in base BB
   as having values in the decimal range [1,232−1][1,232−1]. 
   Second, the expression is true. Any arbitrary expression might
   be valid in zero, one, or more bases. In this problem we will 
   only consider bases 11–3636, where base 11 is unary.

Solution Summary:

   Creat 2 dictionary for transfering from char to number
   and number to char.
   
   1. Find proper minimum base number by finding the highest value of 
      characters in the three numbers.
   2. Calculate each expression based on the base number (guess from
      minumum base number to 36), then check if it is valid.
   3. If you have found at least one valid base number, after that the
      next base number you guess is invalid, then break.
   
   Used Resources: None
   
   I hereby certify that I have produced the following solution myself 
   using the resources listed above in accordance with the CMPUT 403 
   collaboration policy.
   
   --- Bo Zhou
   
'''



import sys

inverse_base = {1:"1",
        2:"2",
        3:"3",
        4:"4",
        5:"5",
        6:"6",
        7:"7",
        8:"8",
        9:"9",
        10:"a",
        11:"b",
        12:"c",
        13:"d",
        14:"e",
        15:"f",
        16:"g",
        17:"h",
        18:"i",
        19:"j",
        20:"k",
        21:"l",
        22:"m",
        23:"n",
        24:"o",
        25:"p",
        26:"q",
        27:"r",
        28:"s",
        29:"t",
        30:"u",
        31:"v",
        32:"w",
        33:"x",
        34:"y",
        35:"z",
        36:"0"}

base = {"1":1,
            "2":2,
            "3":3,
            "4":4,
            "5":5,
            "6":6,
            "7":7,
            "8":8,
            "9":9,
            "a":10,
            "b":11,
            "c":12,
            "d":13,
            "e":14,
            "f":15,
            "g":16,
            "h":17,
            "i":18,
            "j":19,
            "k":20,
            "l":21,
            "m":22,
            "n":23,
            "o":24,
            "p":25,
            "q":26,
            "r":27,
            "s":28,
            "t":29,
            "u":30,
            "v":31,
            "w":32,
            "x":33,
            "y":34,
            "z":35,
            "0":0}

def valid(n1,op,n2,n3,base_number):
    global base
    i=0
    j=0
    k=0
    value1=0
    value2=0
    value3=0
    while(i<len(n1)):
        value1+=base.get(n1[i])*(base_number**(len(n1)-i-1))
        i+=1
    while(j<len(n2)):
        value2+=base.get(n2[j])*(base_number**(len(n2)-j-1))  
        j+=1
    if (op=="/"):
        result = value1/value2
    elif (op=="*"):
        result = value1*value2
    elif (op=="+"):
        result = value1+value2
    elif (op=="-"):
        result = value1-value2
    while(k<len(n3)):
        value3+=base.get(n3[k])*(base_number**(len(n3)-k-1))
        k+=1
    if result == value3:
        return 1
    else:
        return 0


def oneCheck(n1,n2,n3):
    for char in n1+n2+n3:
        if char != "1":
            return 0
    return 1

def findMinBase(n1,n2,n3):
    one_check = oneCheck(n1,n2,n3)
    if one_check == 1:
        return 1
    global inverse_base
    value = 0
    for char in n1+n2+n3:
        if base.get(char)>value:
            value = base.get(char)   
    return value+1

def main():
    global inverse_base
    #file_name = "a.in"
    #f = open(file_name,'r')
    next(sys.stdin)
    for line in sys.stdin:
        #print(line)
        count = 0
        read_list=line.split()
        base_number = findMinBase(read_list[0],read_list[2],read_list[4])
        #base_number = 0
        while(base_number<37):
            check = valid(read_list[0], read_list[1], read_list[2], read_list[4], base_number)
            if check == 1:
                count+=1
                print(inverse_base.get(base_number), end='')
            elif check == 0 and count != 0:
                break;
            base_number+=1
        if count == 0:
            print("invalid",end='')
        print()

#if __name__=="__main__":
main()