from gmpy2 import *
from Crypto.Util.number import *

f = open('output.txt', 'r')
e = int(f.readline()[2:])

n = []
c = []

while 1:
    nn = f.readline()
    if nn == '':
        break
    n.append(int(nn[2:-1]))
    c.append(int(f.readline()[2:-1]))

for i in range(len(n) - 1):
    for j in range(i + 1, len(n) - 1):
        if gcd(n[i], n[j]) != 1:
            print(i, j, gcd(n[i], n[j]))
            p = gcd(n[i], n[j])
            q = n[i] // p
            phi = (p - 1) * (q - 1)
            d = invert(e, phi)
            m = pow(c[i], d, n[i])
            print(long_to_bytes(m))
