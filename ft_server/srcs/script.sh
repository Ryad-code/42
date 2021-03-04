#NGINX
mkdir var/www/site
chmod -R 755 /var/www/*
service nginx start

#MYSQL
mv site etc/nginx/sites-available
ln -s /etc/nginx/sites-available/site /etc/nginx/sites-enabled
service mysql start
mariadb
echo "CREATE DATABASE site_db;" | mysql -u root
echo "GRANT ALL ON site_db.* TO 'mlaouedj'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#PHP
mv info.php var/www/site

#Lancement
service nginx restart
sleep infinity


