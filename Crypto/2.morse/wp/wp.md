结合题面中给出的注意大小写以及题目名morse不难想到摩斯解密
尝试后发现将大写字母转为`.` ，小写字母转为 `-`，空格转为`/`，得到的结果可以被解密
```python
t = "zjNU Ctfz jN UCt fZjN u CTfZ jnucTfz jnucT fzJNU Ct F Z JNuct fzJNU cTFZ jNUCTf ZJnuc Tfzjn UCTFz JNUct fZJNUc TFZJn uctfz jnuct FZJNu cTFZJn uCTF zjNUC tFZ JNUct fZJNUc tfzjN Uctfz Jnuct Fzjnu CTFzj Nu C tFzJ nuctf zJnU cTF zJnU ctfzjNu"
res = ""
for i in t:
	if i.isupper():
		res += "."
	elif i.islower():
		res += "-"
	else:
		res += "/"

print(res)
```
得到
```
--../.---/-./..-/-.-./-/..-./----.--/----./--.../.-/././..---/--.../-.../-....-/..---/.----/....-/...--/-....-/....-/-----/-----/....-/-....-/-.../--.../-../...--/-....-/----./.----/.----/.----/...--/.-/./-.-./-----/-.-./-../-.-./-----.-
```
搜索摩斯解密随便找到一个解密网站进行解密即可得到flag
如:https://www.bejson.com/enc/morse/