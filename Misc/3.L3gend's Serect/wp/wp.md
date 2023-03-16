# L3gend's Serect Write Up

## 前置：

下载，获取dmp内存文件，E01文件，哈希校验文件

## 第一阶段：考点：BitLocker的破解（教学使用passware kit可以秒穿）

E01线：磁盘镜像，其中包括二阶段需要的压缩包文件，导出E01文件的磁盘使用了BitLocker加密，加密的密钥在dmp内存镜像中

bitlocker密码：c8PUudTSHEMnt8H2i7Ez8nvQsAls+J2kWhN5JPaao2Q=

dmp线：在E01镜像导出之后，删除位于桌面的第二阶段需要的zip文件，重启虚拟机并且导出内存dmp文件，防止有人逃课

## 第二阶段：导出zip后，考点：mimikatz/或者是hashdump+哈希爆破的使用以及对基础的dumpfiles和screenshot的使用

zip线：压缩包使用了加密，密码是计算机管理员密码，解压出来会得到一个hint加上一个word文件

word线：word的密码藏在内存镜像文件中，使用screenshot截图可以查看到文件的名称，再使用filedump导出得到word密码

电脑密码：ccmyyy04230501

word密码：1145141919810tshe1145141919810

## 第三阶段：获得word之后，考点：社会工程学

ppt内含三张照片，指向杭州小河直街历史文化街区/小河历史文化街区，flag为该景点名字的前两个字进行md5计算（md5小写）

flag为：zjnuctf{508d2e738622efe3bada2cc2fa99004b}
