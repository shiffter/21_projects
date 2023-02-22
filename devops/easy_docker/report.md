
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
