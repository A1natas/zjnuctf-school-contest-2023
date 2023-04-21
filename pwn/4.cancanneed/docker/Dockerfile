FROM ubuntu:22.04

ENV FLAG=flag{not_here}

RUN useradd -m ctf && sed -i 's/archive.ubuntu.com/asia-east1.gce.archive.ubuntu.com/g' /etc/apt/sources.list && apt update && apt-get install -y lib32z1 xinetd && rm -rf /var/lib/apt/lists/ && rm -rf /root/.cache && apt-get autoclean && rm -rf /tmp/* /var/lib/apt/* /var/cache/* /var/log/*

COPY ./ctf.xinetd /etc/xinetd.d/ctf
COPY ./start.sh /start.sh
COPY ./pwn /home/ctf/pwn

WORKDIR /home/ctf

# chown & chmod
RUN chown -R root:ctf /home/ctf && chmod -R 750 /home/ctf
# copy lib,/bin 
RUN rm -rf /home/ctf/lib /home/ctf/lib32 /home/ctf/lib64 /home/ctf/libx32 && \ 
    cp -R /usr/lib* /home/ctf && \ 
    touch /home/ctf/flag && \
    mkdir /home/ctf/bin && \
    mkdir /home/ctf/dev && \
    mknod /home/ctf/dev/null c 1 3 && \ 
    mknod /home/ctf/dev/zero c 1 5 && \
    mknod /home/ctf/dev/random c 1 8 && \ 
    mknod /home/ctf/dev/urandom c 1 9 && \ 
    chmod 666 /home/ctf/dev/* && \ 
    cp /bin/sh /home/ctf/bin/sh && \ 
    cp /bin/ls /home/ctf/bin/ls && \ 
    cp /bin/cat /home/ctf/bin/cat && \
    chown -R root:ctf /home/ctf && \
    chmod -R 750 /home/ctf && \
    chmod 740 /home/ctf/flag

CMD ["/start.sh"]

EXPOSE 70
