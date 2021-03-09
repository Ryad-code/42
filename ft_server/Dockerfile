FROM debian:buster
MAINTAINER mlaouedj@student.42.fr

RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y wget
RUN apt-get install -y openssl
RUN apt-get install -y nginx
#RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y php7.3 php7.3-fpm php7.3-cli php7.3-common
#RUN apt-get install wordpress

COPY srcs/* ./

CMD bash script.sh

EXPOSE 80 443

