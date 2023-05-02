FROM php:5.6-apache
COPY start.sh /
RUN chmod +x /start.sh && \
    mkdir /app
COPY app /app/
COPY index.php /var/www/html/
CMD "/start.sh"

EXPOSE 80