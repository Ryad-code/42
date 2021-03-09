service nginx start
service php7.3-fpm start

#SETTING UP SERVER BLOCKS
mkdir var/www/localhost
chown -R www-data /var/www/localhost
chmod -R 755 /var/www/localhost
mv index.html var/www/localhost
mv default etc/nginx/sites-available
ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/

#SSL
mkdir etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=12/L=ABC/O=1#/CN=mlaouedj"

#PHP
mv index.php var/www/localhost

#MYSQL
#service mysql start
#echo "CREATE DATABASE site_db;" | mysql -u root
#echo "GRANT ALL ON site_db.* TO 'mlaouedj'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
#echo "FLUSH PRIVILEGES;" | mysql -u root

#Lancement
service nginx restart
service php7.3-fpm restart
sleep infinity


