<p align="center">
  <img src="https://img.shields.io/badge/Project-Inception-blue?style=for-the-badge&logo=docker" alt="Inception"/>
  <img src="https://img.shields.io/badge/Stack-Docker%20Compose-2496ED?style=for-the-badge&logo=docker&logoColor=white" alt="Docker Compose"/>
  <img src="https://img.shields.io/badge/Services-NGINX%20%7C%20WordPress%20%7C%20MariaDB-brightgreen?style=for-the-badge" alt="Services"/>
</p>

[Home](../../README.md) · [Developer Documentation](DEV_DOC.md) · [User Documentation](USER_DOC.md)

# Inception — Infrastructure WordPress conteneurisée

> Projet réalisé dans le cadre du cursus 42 par whollebe.

## Présentation

Inception is a system administration project whose goal is to build a small, containerized web infrastructure from scratch using Docker and Docker Compose, without relying on any pre-built ready-made images (aside from the official `debian:bookworm` base image, which is explicitly allowed by the subject).

The stack is composed of three services, each running in its own dedicated container, built from a hand-written Dockerfile:

- NGINX: the only entrypoint of the infrastructure, exposed on port 443 and serving traffic exclusively over TLSv1.2 / TLSv1.3.
- WordPress + php-fpm: the WordPress application, installed and configured automatically via wp-cli, running without any embedded web server (php-fpm only).
- MariaDB: the database engine used to persist the WordPress data, configured with a dedicated application user and a root account.

All three containers communicate through a custom Docker bridge network called `inception`, and only NGINX is reachable from outside the infrastructure, on port 443.

Two named Docker volumes provide persistent storage:

- `mariadb_data` contains the MariaDB database files, and is stored on the host at `/home/whollebe/data/mariadb`.
- `wordpress_data` contains the WordPress website files (PHP code, themes, plugins, uploads), and is stored on the host at `/home/whollebe/data/wordpress`.

Sensitive values (database passwords, WordPress admin/user passwords) are never hard-coded in the Dockerfiles or committed to the repository. They are injected at runtime using Docker secrets (files under the `secrets/` folder, mounted read-only in `/run/secrets/` inside the containers), while non-sensitive configuration (domain name, database name, usernames, emails) is stored in a `.env` file consumed by `docker-compose.yml`.

### Sources included in the project

The repository is organized as follows:

- `Makefile`, at the root, drives the whole build/run process.
- `secrets/`, at the root, contains the password files used as Docker secrets. This folder is local-only and ignored by Git.
  - `db_password.txt`
  - `db_root_password.txt`
  - `wp_admin_password.txt`
  - `wp_password.txt`
- `srcs/`, containing everything needed to build and configure the stack.
  - `.env`, the non-sensitive configuration file.
  - `docker-compose.yml`, describing the three services, the network and the volumes.
  - `requirements/mariadb/`, with its `Dockerfile`, its `conf/50-server.cnf` configuration file, and its `tools/mariadb.sh` entrypoint script.
  - `requirements/nginx/`, with its `Dockerfile`, its `conf/nginx.conf` configuration file, and its `tools/nginx.sh` entrypoint script.
  - `requirements/wordpress/`, with its `Dockerfile`, its `conf/www.conf` configuration file, and its `tools/wordpress.sh` entrypoint script.

### Design choices and comparisons

**Virtual Machines vs Docker**

A VM virtualizes an entire operating system, including its own kernel, drivers and init system, on top of a hypervisor. This makes it heavier to run and slower to start, but strongly isolated from the host. Docker containers instead share the host kernel and only package the application and its dependencies, which makes them much lighter, faster to start, and easier to reproduce, at the cost of slightly weaker isolation than a full VM. In this project, Docker is used to isolate each service (nginx, WordPress, MariaDB) into its own lightweight, reproducible unit, while the whole stack still runs inside a VM as required by the subject.

**Secrets vs Environment Variables**

Environment variables, via the `.env` file and `env_file` directive, are convenient for non-sensitive configuration such as the domain name, the database name or the usernames, but they remain visible in `docker inspect`, in the container's environment, and can leak into logs or crash dumps. Docker secrets are mounted as read-only files under `/run/secrets/` inside the container, are not part of the container's environment variables or image layers, and are only accessible to the processes that actually need them. For this reason, all passwords are handled as Docker secrets in this project, while everything else non-sensitive stays in the `.env` file.

**Docker Network vs Host Network**

Using `network: host` makes a container share the host's network namespace directly, removing network isolation and any port mapping: any service inside can bind directly to a host port and can reach, or be reached by, anything on the host network. A custom bridge network, as used here with the `inception` network, instead gives each container its own isolated network namespace and its own IP address, with DNS-based service discovery by container name, so that for example the `wordpress` hostname resolves to the WordPress container from inside NGINX or MariaDB. Only the ports explicitly published are reachable from the host, and containers only talk to each other over the network that is defined for them. This is why `network: host` and `--link` are forbidden by the subject, and a dedicated bridge network is used instead.

**Docker Volumes vs Bind Mounts**

A bind mount maps an arbitrary path on the host filesystem directly into the container. It depends entirely on the host's directory structure and permissions, and is not managed by Docker itself. A named volume, on the other hand, is fully managed by the Docker daemon, including its creation, its lifecycle and its driver options, independently of where exactly the data physically lives on disk, which makes it easier to back up, migrate, or reattach to a new container. This project uses two named volumes, `mariadb_data` and `wordpress_data`, with a local driver and bind-type driver options, so that Docker still owns the volumes' lifecycle while their actual data is guaranteed to live under `/home/whollebe/data/`, as required by the subject.

## Utilisation

Les documents complémentaires détaillent les deux aspects opérationnels du projet :

- [DEV_DOC.md](DEV_DOC.md) explique l'installation, la compilation, la maintenance des conteneurs et la persistance des données ;
- [USER_DOC.md](USER_DOC.md) explique les services disponibles, l'accès au site, les identifiants et les vérifications courantes.

## Démarrage

### Prerequisites

- A Linux Virtual Machine with Docker and Docker Compose installed.
- Sudo rights for the current user, since the Makefile creates `/home/whollebe` and changes its ownership.
- The domain `whollebe.42.fr` configured to point to the VM's local IP address, for example through an entry in `/etc/hosts` on the machine used to browse the site.

### Setup

1. Clone the repository.
2. Create a `secrets/` folder at the repository root, containing one password per file: `db_password.txt`, `db_root_password.txt`, `wp_admin_password.txt` and `wp_password.txt`. This folder must not be committed to Git.
3. Check and, if needed, edit `srcs/.env` to set the domain name, the database name, and the WordPress usernames and emails.

### Build and run

Run the following command from the repository root, where the Makefile is located:

`make`

This prepares the host data folders, builds the three Docker images, and starts the whole stack in the background.

Other available Makefile targets:

- `make down` stops and removes the containers.
- `make clean` stops the containers and also removes the volumes and the images.
- `make fclean` does the same as clean, and additionally removes the host data folder.
- `make re` runs down followed by all, for a full rebuild and restart.

### Access

Once the stack is running, the website can be reached at `https://whollebe.42.fr`
**from inside the Virtual Machine** (or from a browser on a machine that has
`whollebe.42.fr` resolving directly to the VM's IP address).

If you are running the VM with VirtualBox's default **NAT network** and accessing it
from your **host machine**, the VM is not directly reachable on its own IP: instead,
a port forwarding rule redirects a port on the host to port `443` inside the guest
(for example `4433 -> 443`, configurable in *Settings > Network > Port Forwarding*).
In that case:

1. Add the following line to your host machine's `/etc/hosts` file (or `C:\Windows\System32\drivers\etc\hosts` on Windows):
   `127.0.0.1 whollebe.42.fr`
2. Browse to `https://whollebe.42.fr:4433` (replace `4433` with whatever host port you configured).

If you do not have `sudo` rights on the host, you can also browse directly to
`https://127.0.0.1:4433` when the port forwarding rule is configured.

The browser will show a warning about the self-signed TLS certificate the first time,
which is expected in this local evaluation environment.

## Resources

- Docker documentation, at docs.docker.com
- Docker Compose file reference, at docs.docker.com/compose/compose-file
- Docker secrets documentation, at docs.docker.com/engine/swarm/secrets
- NGINX documentation, at nginx.org/en/docs
- MariaDB documentation, at mariadb.com/kb/en/documentation
- WP-CLI documentation, at wp-cli.org
- PHP-FPM installation documentation, at php.net/manual/en/install.fpm.php
- The 42 Inception project subject itself

### Usage of AI tools

I used AI to investigate a few issues encountered while connecting to WordPress from a web browser, including access from Firefox without adding `127.0.0.1 whollebe.42.fr` to `/etc/hosts` when I did not have `sudo` privileges. I also used it to help write and structure `README.md`, `DEV_DOC.md` and `USER_DOC.md`.

---

[Home](../../README.md) · [Developer Documentation](DEV_DOC.md) · [User Documentation](USER_DOC.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 5</i>
</p>
