#!/bin/sh
touch /flag && \
echo $FLAG > /flag && \
sed -i "s/flag{test}/$FLAG/g" /var/www/html/flag.php && \
export FLAG="no_flag"