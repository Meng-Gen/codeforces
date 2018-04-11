import sys
        
def main():
    modular_table = {}
    n, k, m = map(int, sys.stdin.readline().split())
    for x in map(int, sys.stdin.readline().split()):
        modular_x = x % m
        if modular_x not in modular_table:
            modular_table[modular_x] = []
        modular_table[modular_x].append(x)

    for modular_x in modular_table:
        x_list = modular_table[modular_x]
        if len(x_list) >= k:
            print('Yes')
            print(' '.join(map(str, x_list[:k])))
            return
    print('No')
    
if __name__ == '__main__':
    sys.exit(main())