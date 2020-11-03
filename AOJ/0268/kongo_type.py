
q = int(input())
for _ in range (q):
    bits = F'{int(input(), 16):32b}'
    sign = '-' if bits[0] == '1' else ''
    integer = sum([2**i for i, b in enumerate(bits[1:25][::-1]) if b == '1'])
    fraction = sum([0.5**i for i, b in enumerate(bits[25:], start=1) if b == '1'])
    print(sign + str(float(integer + fraction)))
