rm  /start.sh
sed -i "s/zjnuctf{test_flag}/$FLAG/g" /db.sql
export FLAG="no_flag"
service mysql start
until mysql  -u "root" "-proot" -e 'SELECT 1'; do
  >&2 echo "MySQL is unavailable - sleeping"
  sleep 1
done
>&2 echo "MySQL is up - executing command"
mysql -u root -e "CREATE DATABASE ctf"
mysql -u root -proot ctf < /db.sql
mysql -e "CREATE USER 'ctf'@'%' IDENTIFIED BY 'ctf';"
mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'ctf'@'%';"
rm /db.sql
rm /flag
service apache2 start &
tail -f /dev/null