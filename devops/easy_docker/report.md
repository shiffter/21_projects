## Part 1. nginx


#### Take the official docker image **nginx**.

![part1](part_1/pull_nginx.png "Pull nginx image") 

#### Check images.

![part1](part_1/images.png "Show available images") 


#### Check running proccess.

![part1](part_1/docker_ps.png "Nginx process is running") 


- Container size: "ShmSize": 67108864 (67 Mb)
- Mapped Port -80(not bound) None. 
- Container IPAddress: "172.17.0.2",


#### Stop current nginx

![part1](part_1/stop.png "Stop curr nginx image") 

#### Start with ports 80 and 453.
![part1](part_1/welcome_ngnix.png "80 port for container connect")

#### Restart and still working.
![part1](part_1/res_work.png "Restart and still working")


## Part 2. Operation with container.

#### nginx.conf inside container
![part2](part_2/exec.png "nginx.conf")

#### Shown status nginx page
![part2](part_2/status.png "current nginx status")

#### Export container
![part2](part_2/export.png "docker export")

#### Import and run container
![part2](part_2/import_and_run.png "delete->import->run")


## Part 3. Mini web server.

#### Write hello world page and spawn fcgi on 8080 port
![part3](part_3/spawn.png "source code and swapn on 8080")

#### Nginx configure
![part3](part_3/nginx.png "nginx conf")

#### Get Hello World Page
![part3](part_3/curl.png "Get page")


## Part 4. Own docker.

#### Build image and spawn on 81 ports.
![part4](part_4/build_t.png "build and run")

#### Curl from localhost and nginx conf.
![part4](part_4/curl.png)

#### Local nginx conf.
![part4](part_4/local_nginx.conf)

#### Run with mount new nginx conf.
![part4](part_4/new_nginx)

#### Get status page.
![part4](part_4/final.png)
