#!/bin/bash

MYSQL_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_PASSWORD=$(cat /run/secrets/wp_password)

until mariadb-admin ping -h"mariadb" -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --silent; do
    sleep 2
done

mkdir -p /var/www/html
cd /var/www/html

if [ ! -f wp-config.php ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    wp core download --allow-root

    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost=mariadb:3306 \
        --allow-root

    sed -i "/\/\* That's all, stop editing!/i \
\$http_host = isset(\$_SERVER['HTTP_HOST']) ? \$_SERVER['HTTP_HOST'] : '$DOMAIN_NAME';\n\
define('WP_HOME', 'https://' . \$http_host);\n\
define('WP_SITEURL', 'https://' . \$http_host);\n\
define('FORCE_SSL_ADMIN', true);\n\
define('CONCATENATE_SCRIPTS', false);\n\
define('SCRIPT_DEBUG', true);\n\
if (isset(\$_SERVER['HTTP_X_FORWARDED_PROTO']) && \$_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') {\n\
    \$_SERVER['HTTPS'] = 'on';\n\
}" /var/www/html/wp-config.php

    wp core install \
        --url="$DOMAIN_NAME" \
        --title="Inception" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    wp user create \
        "$WP_USER" \
        "$WP_EMAIL" \
        --user_pass="$WP_PASSWORD" \
        --allow-root

    chown -R www-data:www-data /var/www/html
fi

mkdir -p /run/php

chown -R www-data:www-data /var/www/html

exec php-fpm8.2 -F
