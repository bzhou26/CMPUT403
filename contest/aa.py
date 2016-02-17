import sys

def main():
    kase = int(input())
    while (kase>0):
        result = set()
        kase -= 1;
        num = int(input())
        while (num > 0):
            num -= 1
            dis = input()
            result.add(dis)
        print(len(result))
    

#if __name__=="__main__":
main()