FROM php:5.6-apache
COPY start.sh /
RUN chmod +x /start.sh
COPY app /app/
COPY index.php /var/www/html/
EXPOSE 80
CMD ["/start.sh"]