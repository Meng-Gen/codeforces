import sys
    
def main():
    n = int(sys.stdin.read().strip())
    print('YES') if n > 2 and n % 2 == 0 else print('NO')
    
if __name__ == '__main__':
    sys.exit(main())