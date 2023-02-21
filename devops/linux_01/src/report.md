## Part 1. Install OS
![part_1](screens/1.png)
>Скрин выполнения - `cat /etc/issue`.

## Part 2. Create user
- Флаг -G добавляет созданного пользователь в группу **adm**.

![part_2](screens/2_create_new_user.png)


- Вывод команды `cat /etc/passwd`

![part_2](screens/2_new_user.png)

## Part 3. Network settings
#### Изменил имя хоста в файле /etc/hostname на user-1

#### C помощью команды timedatectl вывел информацию о часовых поясах

#### С помощью команды timedatectl set-timezone Europe/Moscow поменял часовой пояс

#### С помощью команды ip link show вывел названия сетевых интерфейсов

![part_3](screens/3_interfaces.png)	

	lo - Виртуальный интерфейс который по умолчанию встроен в любую линукс систему. Он используется для отладки сетевых программ и запуска серверных приложений на локальной машине. С этим интерфейсом всегда связан адрес 127.0.0.1. У него есть dns-имя – localhost. Посмотреть привязку можно в файле /etc/hosts.

#### С помощью команды ip a show получил динамический ip адрес от DHCP

	DHCP (Dynamic Host Configuration Protocol) - протокол динамической настройки узла. Прикладной протокол позволяющий автоматически получать ip адреса, работает по модели клиент-сервер. На этапе конфигурации сетевого устройства сервер выдает ip адрес клиенту.

#### Выставил статические настройки сети(ip, gw, dns) в файле /etc/netplan/00-installer-config.yaml

![part_3](screens/3_set_static_ip_gw_dns.png)

#### После ребута системы прорерил статические настройки и пропинговал серверы 1.1.1.1 & ya.ru

![part_3](screens/3_6_ping_with _static_conf.png)

## Part 4. Update OS.

#### Обновил систему двумя командами
- `sudo apt update` - обновление репозиториев ubuntu.
- `sudo apt full-upgrade` - "Умное" обновление установленных пакетов, умнись заключается в приоритетной установке, если какие то пакеты будут конфликтовать друг с другом, то в этом случае будет установлен более приоритетный пакет.

![part_4](screens/4 upgrade_sys.png)    

## Part 5. Sudo.

- Sudo - утилита позволяющая выполнять команды из под любого пользователя, без фактического входа в учетную запись, по умолчанию команды выполняются с правами суперпользователя root.

![part_5](screens/5 new_hostname.png)

## Part 6. Setup and setting time services.

- Почитал про NTP, у меня он уже был активирован.

![part_6](screens/6 synch time.png)


## Part 7. Installing and using text editors.

#### Vim для сохранения ввел команду :qw

![part_7](screens/7_vim_txt.png)

#### Nano для сохранения ^X, y

![part_7](screens/7_nano_txt.png)

#### Joe для сохранения Ctrl+K, y

![part_7](screens/7_joe_txt.png)


#### Vim без сохранения ввел команду :q!

![part_7](screens/7_vim s21.png)

#### Nano без сохранения ^X, n

![part_7](screens/7_nano s21.png)

#### Joe без сохранения Ctrl+K, n

![part_7](screens/7_joe s21.png)

#### Joe поиск ^K, f, change_word, r(replace), new word

![part_7](screens/7_joe_search.png)

#### Vim %s/word/new_word/g

![part_7](screens/7_vim_search.png)

#### Nano ^\ -> word -> new_word -> y

![part_7](screens/7_nano_search.png)


## Part 8. Installing and basic settings sshd.

`sudo apt-get install ssh`
- `sudo systemctl enable ssh` -  добавил в автозагрузку.
- `sudo vim /etc/ssh/sshd_config` - изменил в файле значение порта на 2022.

![part_8](screens/8 port2022.png)

- `ps -A | grep ssh`
- (-A) - выводит все запущенные процессы.

![part_8](screens/8 ssh procces.png)

- Команда **netstat** - инструмент для мониторинга сетей TCP / IP, который может отображать таблицы маршрутизации, фактические сетевые подключения и информацию о состоянии каждого устройства сетевого интерфейса. Ключ **-t** отбражает порты протокола _TCP_, **-a** выводит все соединения, **-n** использует при выводе IP-адрес напрямую, а не через сервер доменных имен.

![part_8](screens/8 netstat.png)

	Значения столбцов:
- **Proto**: протокол, используемый сокетом.
- **Recv-Q**: количество байтов, не скопированных пользовательской программой, подключенной к этому сокету.
- **Send-Q**: количество неподтвержденных байтов удаленного хоста.
- **Local Address**: локальный адрес (имя локального хоста) и номер порта сокета. Если не указана опция -n, адрес сокета разрешается в соответствии с полным именем хоста (FQDN), а номер порта преобразуется в соответствующее имя службы.
- **State**: состояние сокета. 
- **Foreign Address**: удаленный адрес (имя удаленного хоста) и номер порта сокета.
- **0.0.0.0** означает, что никто не подключен, все соединения **LISTENING** имеют внешний адрес **0.0.0.0**.


## Part 9. Installing and using top and htop.

![part_9](screens/9 top upper.png)

- **Uptime** - 9 min.
- Авторизован **1** пользователь.
- Средняя загрузка **1, 5, 15** минут соответственно **0,00 0,03 0,03**.
- Общее количество процессов **97**.
- Загруженность CPU:
	us - 0 (пользовательские процессы)
	sy - 0 (системные процессы)
	id - 100 (неиспользованные ресурсы)
	wa - 0 (операции ввода/вывода (дисковые операции))
- Загруженность памяти
	total - 3932 mb (общий объем)
	free - 3383 mb (свободно)
	used - 148 mb
- PID процесса занимающего больше всего памяти
	PID - 660; mem 1.0%;
	pid процесса, занимающего больше всего процессорного времени
	PID - 1; cpu 0.0;

![part_9](screens/9htop PID.png)

![part_9](screens/9htop TIME.png)

![part_9](screens/9htop PERCENT_MEM.png)

![part_9](screens/9htop PERCENT_CPU.png)

![part_9](screens/9htop_sshd.png)

![part_9](screens/9sys_log.png)

![part_9](screens/9htop_time_host.png)


## Part 10. fdisk
- Name `hdd /dev/sda/`
- Model `box hard disk`
- Size `10 Gb, 20791565 sectors`
- Swap - 0 b


## Part 11. df
- Размер корневого раздела / **9336140 sectors**
- Used **3121172, 36%**
- Available **5720992**
- Еденица измерения 1 kb

#### df -Th
- Size **9.0GB**
- Used **3.0GB, 36%**
- Available **5.5GB**
- filesystem type **ext4**


## Part 12. du

#### home 
- 120 Kb
![part_12](screens/12home.png)

#### var
- 748 Mb
![part_12](screens/12var.png)

	
#### var/log
- 45 Mb
![part_12](screens/12var_log.png)

#### var/log each
![part_12](screens/12var_log_each.png)


## Part 13. ncdu

#### home 
![part_13](screens/13home.png)

#### var
![part_13](screens/13var.png)
	
#### var/log
![part_13](screens/13var_log.png)


## Part 14. system journal.
- Время последнего успешного логина в систему **22:21:49**, залогинился **shifter**, метод входа **systemd-logind**.

![part_14](screens/14_restart_sshd.png)


## Part 15. Cron.

![part_15](screens/crontab -l.png)

![part_15](screens/uptime_cron.png)

![part_15](screens/crontab finaly.png)			
