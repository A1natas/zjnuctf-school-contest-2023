# -*- conding:utf-8 -*-
from Crypto.Cipher import ARC4
from settings import key
import base64

def encrypt(plaintext):
    rc4 = ARC4.new(key)
    enc_data = rc4.encrypt(plaintext)
    return base64.b64encode(enc_data)
input_str = input('>请输入flag ')
enc = encrypt(input_str.encode())
if enc == b'IooakOXT29cj7xlyWGOLwE7XDk85':
    print("congratulations!")
else:
    print("wrong")

