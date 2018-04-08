import sys

def get_piece(n, a):
    return int(n/a) + (1 if n % a != 0 else 0)
        
def main():
    n, m, a = map(int, sys.stdin.read().split())
    print(get_piece(n, a) * get_piece(m, a))
    
if __name__ == '__main__':
    sys.exit(main())