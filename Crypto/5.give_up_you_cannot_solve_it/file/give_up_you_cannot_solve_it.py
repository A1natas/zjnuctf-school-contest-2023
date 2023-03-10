from Crypto.PublicKey import RSA
import rsa
from Crypto.Util.number import *
from Crypto.Cipher import AES
from secret import key, flag


def MyCrypto(key, q):
    give_up = getPrime(512)
    make_you_cry = getPrime(127)
    print(give_up)
    print((give_up * key + make_you_cry) % q)


def add_to_16(s):
    while len(s) % 16 != 0:
        s += b'\0'
    return s


rsa1 = RSA.generate(1024)
pk = rsa1.publickey().exportKey()
sk = rsa1.exportKey()

with open('./priv.pem', 'wb') as f:
    f.write(sk)

f = open('priv.pem', 'r').read()
q = eval(str(rsa.PrivateKey.load_pkcs1(f))[10:])[-1]

for i in range(2):
    MyCrypto(bytes_to_long(key), q)

aes = AES.new(key, AES.MODE_ECB)
enc = aes.encrypt(add_to_16(flag))
print(enc)

'''
9314226478751671810529309749863069834019844218248409024747270790580507261648497523828251252617973199362476319291480712942325934315804836072131040570812211
10272891091217436674984072707731968350530885269085806248397362418690279538111507629256748165205027984862551209788122695213575567371236386930154410760630553
8833830470501606103755481842306698773723780295407165130562646859395408955937231411733792648064760202626923022497074090566844178059728660955899738364860497
7929877910374262184104054067295620301309400536975152813900641649489423035128779248383107232692928385742885665341449333871651384223494204311105165285582158
b'\xebk\x1d\x85#B\xda\x96\x9e\xdat\xe0si\xca\xab\xdaX\x8a\xc8_\xa4\xd6\x16\xb38b9pq6\xfc\xd6\x80\xce8\xd3\x10\x97\x9b\x88\xf8E|\x0e9\x97\x8d'
'''





