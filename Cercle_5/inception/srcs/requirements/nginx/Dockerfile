FROM debian:bookworm

RUN apt update && apt install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/nginx.sh /usr/local/bin/nginx.sh
RUN chmod +x /usr/local/bin/nginx.sh

ENTRYPOINT [ "/usr/local/bin/nginx.sh" ]
