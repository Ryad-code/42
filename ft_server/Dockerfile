FROM debian:buster
MAINTAINER mlaouedj@student.42.fr

RUN apt-get update
RUN apt-get install -y vim wget
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y php-fpm php-mysql

COPY srcs/script.sh ./
COPY srcs/site ./
COPY srcs/info.php ./

CMD bash script.sh

EXPOSE 80

