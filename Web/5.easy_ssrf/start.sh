#!/bin/bash
rm -rf /start.sh
echo $FLAG > /flag
export FLAG="no_flag"
chmod 700 /flag
chmod +s /bin/cp
useradd ctf
su -c "php -S 0.0.0.0:8082 -t /app/" ctf &
apache2-foreground &
tail -f /dev/null