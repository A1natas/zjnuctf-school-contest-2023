FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
RUN sed -i 's/archive.ubuntu.com/asia-east1.gce.archive.ubuntu.com/g' /etc/apt/sources.list
RUN apt-get update \
    && apt-get install -y mysql-server-5.7 php7.2 php7.2-mysql --fix-missing

ENV MYSQL_ROOT_PASSWORD=root
RUN rm -rf /var/www/html/*
COPY file /var/www/html/
COPY db.sql /db.sql
COPY start.sh /start.sh
RUN chmod +x /start.sh
EXPOSE 80

CMD ["/start.sh"]