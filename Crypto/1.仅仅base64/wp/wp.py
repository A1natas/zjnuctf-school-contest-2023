from base64 import *

m = b'Wlcxd2RXUlhUakJhYm5SWVdsZDRhbUl5TVd4WU0xRjNXREJPZVdWWVFqQmlNVGxZWWpOS2MxcERSams9'

while 1:
    try:
        m = b64decode(m)
        print(m)
    except:
        break
