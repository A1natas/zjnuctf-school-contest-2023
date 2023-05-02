FROM docker.io/python:3.9.7

COPY start.sh /start.sh
RUN chmod +x /start.sh && mkdir /app && pip install flask
COPY app /app/
CMD ["/start.sh"]