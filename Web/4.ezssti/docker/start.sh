#!/bin/sh
echo $FLAG > /flag
chmod 644 /flag
export FLAG="no_flag"
useradd ctf
# chown -R ctf /app
su -c "python /app/app.py" ctf
rm -rf /start.sh
tail -f /dev/null