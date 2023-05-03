FROM ctftraining/base_image_nginx_mysql_php_56

COPY file /var/www/html
COPY start.sh /start.sh

RUN chmod -R 777 /var/www/html

EXPOSE 80

CMD ["/start.sh"]