service nginx start

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

#MYSQL
service mysql start
echo "CREATE DATABASE wordpress_db;" | mysql -u root
echo "GRANT ALL ON wordpress_db.* TO 'mlaouedj'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#PHPMYADMIN
wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
tar xvf phpMyAdmin-5.1.0-all-languages.tar.gz
mv phpMyAdmin-5.1.0-all-languages var/www/localhost/phpmyadmin
mv config.inc.php var/www/localhost/phpmyadmin
chmod -R 755 var/www/localhost/phpmyadmin
chown -R www-data:www-data var/www/localhost/phpmyadmin
service php7.3-fpm start
echo "GRANT ALL ON *.* TO 'mlaouedj'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#WORDPRESS
wget https://wordpress.org/latest.tar.gz
tar xvf latest.tar.gz
cp -a wordpress var/www/localhost/wordpress
mv wp-config.php var/www/localhost/wordpress

#PHP INDEX
mv index.php var/www/localhost

#Lancement
service nginx restart
service php7.3-fpm restart
sleep infinity


