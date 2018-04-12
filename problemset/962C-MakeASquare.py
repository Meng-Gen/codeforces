import sys

def get_square_literal_map():
    literal_map = {}
    for i in range(1, 44722):
        literal = str(i * i)
        literal_len = len(literal)
        if literal_len not in literal_map:
            literal_map[literal_len] = set()
        literal_map[literal_len].add(literal)
    return literal_map

def is_subsequence(x, y):
    it = iter(y)
    return all(any(c == ch for c in it) for ch in x)

def main():
    literal_map = get_square_literal_map()

    n = int(sys.stdin.readline())
    n_literal = str(n)
    n_len = len(n_literal)

    for i in range(n_len, 0, -1):
        for j in literal_map[i]:
            if is_subsequence(j, n_literal):
                found = True
                print(n_len - i)
                return
    print(-1)

if __name__ == '__main__':
    sys.exit(main())