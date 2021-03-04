#NGINX
mkdir var/www/site
chmod -R 755 /var/www/site
service nginx start

#SETTING UP SERVER BLOCKS
mkdir -p /var/www/site/html
#chown -R $USER:$USER /var/www/site/html
mv index.html var/www/site/html
mv site etc/nginx/sites-available
ln -s /etc/nginx/sites-available/site /etc/nginx/sites-enabled/

#SSL_CERTIFICATE
mkdir etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj ‘/C=FR/ST=12/L=ABC/O=1#/CN=mlaouedj’ -keyout /etc/nginx/ssl/localhost.key -out /etc/nginx/ssl/localhost.crt
#openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Paris/L=Paris/0=42 School/OU=ryad/CN=localhost"

#MYSQL
#mv site etc/nginx/sites-available
#ln -s /etc/nginx/sites-available/site /etc/nginx/sites-enabled
service mysql start
echo "CREATE DATABASE site_db;" | mysql -u root
echo "GRANT ALL ON site_db.* TO 'mlaouedj'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#Lancement
service nginx restart
sleep infinity


