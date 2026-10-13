NAME = inception
DATA_PATH = /home/whollebe/data

all: up

prepare:
	@sudo mkdir -p /home/whollebe
	@sudo chown $(USER):$(USER) /home/whollebe
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress

build:
	docker-compose -f srcs/docker-compose.yml build

up: prepare build
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

clean: down
	docker-compose -f srcs/docker-compose.yml down -v --rmi all

fclean: clean
	docker-compose -f srcs/docker-compose.yml down -v --rmi all
	sudo rm -rf $(DATA_PATH)

re: down all

.PHONY: all prepare build up down clean fclean re
