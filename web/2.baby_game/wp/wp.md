在main.js中可以发现
```javascript
t.getVariable('GAME_SCORE') > 6666 && alert(atob("Q29uZ3JhdHVsYXRpb24hZmxhZzogempudWN0ZnthZTViNmQ2MC1mYjI1LTRmYmQtYTY4ZC1iOGQ5Y2I1MWQ2NmR9"))
```
直接在控制台执行
```javascript
alert(atob("Q29uZ3JhdHVsYXRpb24hZmxhZzogempudWN0ZnthZTViNmQ2MC1mYjI1LTRmYmQtYTY4ZC1iOGQ5Y2I1MWQ2NmR9"))
```
即可得到flag