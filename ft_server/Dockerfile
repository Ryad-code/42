FROM debian:buster
MAINTAINER mlaouedj@student.42.fr

RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y wget
RUN apt-get insatll -y openssl
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y php-fpm php-mysql
RUN apt-get install wordpress

COPY srcs/script.sh ./
COPY srcs/site ./
COPY srcs/index.html ./

CMD bash script.sh

EXPOSE 80

