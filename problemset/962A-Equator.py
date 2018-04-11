import sys
        
def main():
    modular_table = {}
    n = int(sys.stdin.readline())
    number_list = list(map(int, sys.stdin.readline().split()))
    half_total_count = sum(number_list) / 2
    curr_count = 0
    for i in range(n):
        curr_count += number_list[i]
        if curr_count >= half_total_count:
            print(i + 1)
            break

if __name__ == '__main__':
    sys.exit(main())