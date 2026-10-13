FROM debian:bookworm

RUN apt update && apt install -y \
    php8.2 \
    php8.2-fpm \
    php8.2-mysql \
    mariadb-client \
    curl \
    unzip

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
COPY tools/wordpress.sh /usr/local/bin/wordpress.sh

RUN chmod +x /usr/local/bin/wordpress.sh

ENTRYPOINT [ "/usr/local/bin/wordpress.sh" ]
