<p align="center">
  <img src="https://img.shields.io/badge/Project-Inception-blue?style=for-the-badge&logo=docker" alt="Inception"/>
  <img src="https://img.shields.io/badge/Documentation-Developer-orange?style=for-the-badge" alt="Developer documentation"/>
</p>

[Home](../../README.md) · [Project README](README.md) · [User Documentation](USER_DOC.md)

# Inception — Documentation développeur

This document describes how to set up, build, run, and maintain the Inception
infrastructure. For the project overview, see [README.md](README.md). For the
end-user and administrator workflow, see [USER_DOC.md](USER_DOC.md).

## 1. Setting up the environment from scratch

### Prerequisites

- A Linux Virtual Machine (the whole project must run inside a VM, not directly on the
  host).
- `docker` and `docker compose` (or `docker-compose`) installed.
- `sudo` rights for the current user (the `Makefile` creates `/home/whollebe` and
  `chown`s it).
- The domain `whollebe.42.fr` resolving to the VM's local IP address wherever you intend
  to browse the site from.

### Repository layout

```
.
├── Makefile
├── secrets/                       # NOT committed to Git — create it locally
│   ├── db_password.txt
│   ├── db_root_password.txt
│   ├── wp_admin_password.txt
│   └── wp_password.txt
└── srcs/
    ├── .env
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/50-server.cnf
        │   └── tools/mariadb.sh
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/nginx.conf
        │   └── tools/nginx.sh
        └── wordpress/
            ├── Dockerfile
            ├── conf/www.conf
            └── tools/wordpress.sh
```

### Configuration files

- **`srcs/.env`** — non-sensitive configuration consumed by `docker-compose.yml` via
  `env_file`. Currently defines:
  - `DOMAIN_NAME` — the site's domain (`whollebe.42.fr`)
  - `MYSQL_DATABASE`, `MYSQL_USER` — WordPress database name and application user
  - `WP_ADMIN_USER`, `WP_ADMIN_EMAIL` — WordPress administrator account
  - `WP_USER`, `WP_EMAIL` — a second, regular WordPress account

- **`secrets/*.txt`** — one password per file, mounted by Docker as read-only files
  under `/run/secrets/<secret_name>` in the relevant containers (declared in the
  `secrets:` section of `docker-compose.yml`). These files must exist locally before
  the first `make up` and must **never** be committed to Git.

- If the "secrets" folder does not exist or is empty, please create it and add the following .txt files to it:
- `- db_password.txt`
- `- db_root_password.txt`
- `- wp_admin_password.txt`
- `- wp_password.txt`


## 2. Building and launching the project

Everything goes through the root `Makefile`, which drives `docker compose` under the
hood.

| Command       | Effect |
|----------------|--------|
| `make` / `make all` / `make up` | Creates the host data directories (`prepare`), builds the images (`build`), then starts the stack in detached mode. |
| `make build`   | Builds the three images (`nginx`, `mariadb`, `wordpress`) from their respective Dockerfiles, without starting anything. |
| `make prepare` | Creates `/home/whollebe` and the `mariadb` / `wordpress` subfolders used by the named volumes, with correct ownership. |
| `make down`    | Stops and removes the containers (network is removed too), volumes and images are kept. |
| `make clean`   | `down` + removes volumes and all images built by Compose. |
| `make fclean`  | `clean` + removes the host data directory (`/home/whollebe/data`) entirely. |
| `make re`      | `down` followed by `all` (full rebuild/restart). |

Typical first-time workflow:

```sh
make            # build images + start containers
docker ps        # verify the three containers are Up
```

Typical "clean slate" workflow (e.g. after changing `.env` or a secret):

```sh
make fclean
make
```

## 3. Managing containers and volumes

### Containers

```sh
docker ps                       # list running containers
docker logs <nginx|wordpress|mariadb>   # inspect a service's logs
docker exec -it <container> bash        # shell into a running container
docker compose -f srcs/docker-compose.yml restart <service>   # restart one service
```

Each container's `ENTRYPOINT` runs a dedicated setup script
(`nginx.sh`, `mariadb.sh`, `wordpress.sh`) that performs first-run initialization (TLS
certificate generation, database/user creation, WordPress installation) before handing
off to the actual foreground process (`nginx -g "daemon off;"`, `mariadbd`, `php-fpm8.2
-F`), which is what keeps PID 1 as the real service process rather than a wrapper script
— no `tail -f`, `sleep infinity`, or similar hacks are used.

### Volumes

Two named volumes are declared in `docker-compose.yml`:

| Volume name       | Mounted in       | Host path (via `driver_opts`)       |
|---------------------|------------------|----------------------------------------|
| `mariadb_data`       | `mariadb:/var/lib/mysql` | `/home/whollebe/data/mariadb`    |
| `wordpress_data`     | `wordpress:/var/www/html` and `nginx:/var/www/html` | `/home/whollebe/data/wordpress` |

Useful commands:

```sh
docker volume ls                          # list Docker volumes
docker volume inspect mariadb_data         # see mount point / driver options
```

Even though these are Docker **named volumes** (not bind mounts, as required by the
subject), the `local` driver with `type: none` / `o: bind` `driver_opts` guarantees
their actual data is stored under `/home/whollebe/data/` on the host — this satisfies
both constraints ("must be named volumes" and "must end up in `/home/login/data`").

## 4. Where project data is stored and how it persists

- **Database data** (`mariadb_data` volume → `/home/whollebe/data/mariadb`): all
  WordPress tables (posts, users, options, etc.), managed entirely by MariaDB inside the
  `mariadb` container.
- **Website files** (`wordpress_data` volume → `/home/whollebe/data/wordpress`): the
  full WordPress codebase (core, themes, plugins, uploads) downloaded and configured by
  `wp-cli` on first run. This same volume is also mounted read-only-in-practice by
  `nginx`, so it can serve static assets directly and forward only `.php` requests to
  `wordpress:9000` via FastCGI.

Because both live in named volumes (not inside the containers' writable layers), the
data **survives** `make down` and even a full `make re`. It is only destroyed by
`make clean` (removes volumes) or `make fclean` (also wipes the host directory).

The WordPress installation itself is **idempotent**: the `wordpress.sh` script only runs
 the `wp core install` / `wp config create` / `wp user create` steps if `wp-config.php`
 doesn't already exist in the volume, so restarting the container without recreating the
 volume won't reset the site.

---

[Home](../../README.md) · [Project README](README.md) · [User Documentation](USER_DOC.md)

<p align="center">
  <i>Documentation développeur du projet Inception — Cercle 5</i>
</p>
