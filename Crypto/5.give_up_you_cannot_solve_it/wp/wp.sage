from Crypto.Util.number import *
import itertools
from Crypto.Cipher import AES

def small_roots(f, bounds, m=1, d=None):
    if not d:
        d = f.degree()

    R = f.base_ring()
    N = R.cardinality()

    f /= f.coefficients().pop(0)
    f = f.change_ring(ZZ)

    G = Sequence([], f.parent())
    for i in range(m+1):
        base = N^(m-i) * f^i
        for shifts in itertools.product(range(d), repeat=f.nvariables()):
            g = base * prod(map(power, f.variables(), shifts))
            G.append(g)

    B, monomials = G.coefficient_matrix()
    monomials = vector(monomials)

    factors = [monomial(*bounds) for monomial in monomials]
    for i, factor in enumerate(factors):
        B.rescale_col(i, factor)

    B = B.dense_matrix().LLL()

    B = B.change_ring(QQ)
    for i, factor in enumerate(factors):
        B.rescale_col(i, 1/factor)

    H = Sequence([], f.parent().change_ring(QQ))
    for h in filter(None, B*monomials):
        H.append(h)
        I = H.ideal()
        if I.dimension() == -1:
            H.pop()
        elif I.dimension() == 0:
            roots = []
            for root in I.variety(ring=ZZ):
                root = tuple(R(root[var]) for var in f.variables())
                roots.append(root)
            return roots

    return []

p=0x00d84f25dac222a11ed687458f9b1d947359b22f0d6ea9a0a5becd55d515b78d46916fb5c34659ff7238f91aa00a6887a330f1f232d3da9ed33bfef42ea66a3ce1
qh=0x00f040aa6183f5c42cdccdb7797cd73338418d105f981be9026a4aa3c9cc623de5906531c2157ed8
q_p=0x219a370670c765040018feb07d8102fd8d7d51b28a1d57c280de270a4e79fe36a8b51568b2df93d19ab3c19a345114dd6cee6b08a65fd42a332802a5d326dd91

P.<ql>=PolynomialRing(Zmod(p))
f=((qh<<200)+ql)*q_p-1
f=f.monic()
ql=int(f.roots()[0][0])
q=(qh<<200)+ql

give_up1=9314226478751671810529309749863069834019844218248409024747270790580507261648497523828251252617973199362476319291480712942325934315804836072131040570812211
s1=10272891091217436674984072707731968350530885269085806248397362418690279538111507629256748165205027984862551209788122695213575567371236386930154410760630553
give_up2=8833830470501606103755481842306698773723780295407165130562646859395408955937231411733792648064760202626923022497074090566844178059728660955899738364860497
s2=7929877910374262184104054067295620301309400536975152813900641649489423035128779248383107232692928385742885665341449333871651384223494204311105165285582158
enc=b'\xebk\x1d\x85#B\xda\x96\x9e\xdat\xe0si\xca\xab\xdaX\x8a\xc8_\xa4\xd6\x16\xb38b9pq6\xfc\xd6\x80\xce8\xd3\x10\x97\x9b\x88\xf8E|\x0e9\x97\x8d'

PR.<make_you_cry1,make_you_cry2>=PolynomialRing(Zmod(q))
f=give_up2*(s1-make_you_cry1)+give_up1*(make_you_cry2-s2)
ans=small_roots(f,[2^127,2^127],2,3)
make_you_cry1=int(ans[0][0])
make_you_cry2=int(ans[0][1])

key=((s1-make_you_cry1)*inverse_mod(give_up1,q))%q
aes = AES.new(long_to_bytes(key), AES.MODE_ECB)
flag=aes.decrypt(enc)
print(flag)