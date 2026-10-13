<p align="center">
  <img src="https://img.shields.io/badge/Project-Inception-blue?style=for-the-badge&logo=docker" alt="Inception"/>
  <img src="https://img.shields.io/badge/Documentation-User-green?style=for-the-badge" alt="User documentation"/>
</p>

[Home](../../README.md) · [Project README](README.md) · [Developer Documentation](DEV_DOC.md)

# Inception — Documentation utilisateur

This document explains, from an end-user and administrator point of view, how to use the
Inception stack: what it provides, how to start and stop it, how to access it, where the
credentials live, and how to check that everything is running correctly. For the
technical architecture and maintenance details, see [DEV_DOC.md](DEV_DOC.md). The
project overview is available in [README.md](README.md).

## 1. What services does the stack provide?

The Inception stack is a self-hosted **WordPress website**, served over **HTTPS only**,
backed by a **MariaDB** database. It is made of three containers working together:

| Container    | Role                                                          |
|--------------|----------------------------------------------------------------|
| `nginx`      | The single entry point of the site. Handles TLS (HTTPS) on port 443 and forwards PHP requests to WordPress. |
| `wordpress`  | Runs the WordPress site itself, through php-fpm (no built-in web server). |
| `mariadb`    | Stores all the WordPress data (posts, pages, users, settings). |

From a user's perspective, you only ever interact with the **website**, reachable
through NGINX — you never talk to WordPress or MariaDB directly.

## 2. Starting and stopping the project

All commands below are run from the root of the repository (where the `Makefile` is
located).

- **Start the project** (builds the images if needed and starts every container):
  ```sh
  make
  ```
  or explicitly:
  ```sh
  make up
  ```

- **Stop the project** (containers are stopped and removed, data is kept):
  ```sh
  make down
  ```

- **Restart everything**:
  ```sh
  make re
  ```

- **Fully reset the project** (removes containers, images, volumes **and** all stored
  data — use with caution):
  ```sh
  make fclean
  ```

The containers are configured to automatically **restart on crash**
(`restart: unless-stopped`), so you don't need to manually relaunch them if one of them
happens to fail.

## 3. Accessing the website and the administration panel

Once the stack is running, the site is reachable at:

```
https://whollebe.42.fr
```

> The domain name must resolve to the IP address of the VM running the project (for
> example via an entry in `/etc/hosts`). Only port `443` (HTTPS) is exposed — there is no
> plain HTTP access.

Since the TLS certificate is **self-signed** (generated locally at container startup),
your browser will show a security warning the first time you visit the site — this is
expected; you can safely proceed for this local/evaluation environment.

**WordPress administration panel**, to manage the site (posts, pages, plugins, users,
settings):

```
https://whollebe.42.fr/wp-login.php
```

Then, please enter either your USER_LOGIN or your ADMIN_LOGIN, along with their respective passwords.

## 4. Locating and managing credentials

Credentials are **never** stored in plain text inside the code, images, or the Git
repository. They live in the `secrets/` folder at the root of the project (outside of
`srcs/`, and excluded from Git):

| File                        | Used for                              |
|------------------------------|-----------------------------------------|
| `secrets/db_password.txt`         | Password of the WordPress database user (`wp_user`) |
| `secrets/db_root_password.txt`    | Password of the MariaDB `root` account |
| `secrets/wp_admin_password.txt`   | Password of the WordPress administrator account |
| `secrets/wp_password.txt`         | Password of the second (regular) WordPress user |

The corresponding **usernames and emails** (non-sensitive) are defined in `srcs/.env`:

- WordPress administrator: `WP_ADMIN_USER` (login) / `WP_ADMIN_EMAIL`
- Second WordPress user: `WP_USER` (login) / `WP_EMAIL`

> Note: for security reasons, the administrator's username cannot contain "admin" or
> "administrator" — this is why an admin account with a different-looking username is
> used, even though it holds the administrator role.

If you ever need to change a password, edit the relevant file in `secrets/` **before**
the first startup (the values are only applied when WordPress is installed for the
first time), then rebuild the project with `make fclean && make`.

## 5. Checking that the services are running correctly

- **Check that the containers are up and healthy:**
  ```sh
  docker ps
  ```
  You should see three containers (`nginx`, `wordpress`, `mariadb`), all with a status
  of `Up`.

- **Check the site is reachable:**
  Open `https://whollebe.42.fr` in a browser (or `curl -k https://whollebe.42.fr`) and
  confirm the WordPress homepage loads.

- **Check the logs of a specific service** if something looks wrong:
  ```sh
  docker logs nginx
  docker logs wordpress
  docker logs mariadb
  ```

- **Check that data persists across restarts:**
  Stop and restart the project (`make down` then `make up`); your posts, pages and
  users should still be there, since they live in the named volumes rather than inside
  the containers themselves.

---

[Home](../../README.md) · [Project README](README.md) · [Developer Documentation](DEV_DOC.md)

<p align="center">
  <i>Documentation utilisateur du projet Inception — Cercle 5</i>
</p>
