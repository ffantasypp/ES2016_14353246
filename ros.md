## LAB05_ROS  

由于配置的时候还没清楚整个流程，并没有进行截图，因此过程的截图借用了室友的，最后在自己的虚拟机运行了指令roscore；  

## 配置过程  
### setup sources list
sudo sh -c 'echo' "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'  
### setup my keys
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 0xB01FA116  
![0.jpg](https://ooo.0o0.ooo/2016/11/11/582574b33f19a.jpg)  
### installation
sudo apt-get update  
![0.jpg](https://ooo.0o0.ooo/2016/11/11/5825750f028a9.jpg)  
### desktop-full install
sudo apt-get install ros-jade-desktop-full  
![11.jpg](https://ooo.0o0.ooo/2016/11/11/582575c93cafc.jpg)  
![12.jpg](https://ooo.0o0.ooo/2016/11/11/582575c97cfd0.jpg)  
![13.jpg](https://ooo.0o0.ooo/2016/11/11/582575c97c30c.jpg)  
### initial rosdep
echo "source /opt/ros/jade/setup.bash" >> ~/.bashrcsource ~/.bashrc 
### getting rosinstall  
sudo apt-get install python-rsinstall  
![0.jpg](https://ooo.0o0.ooo/2016/11/11/582576e11f93d.jpg)  
  
  
  
## 结果截图  
![ros.png](https://ooo.0o0.ooo/2016/11/11/5825728934346.png)   
![ros1.png](https://ooo.0o0.ooo/2016/11/11/58257288c32e0.png)  
  
  
## 配置中出现的问题
首先是第一条指令的时候  
![10.png](https://ooo.0o0.ooo/2016/11/11/5825783f91d22.png)  
当时查了出错原因，发现可能是下载的版本和ubuntu的版本不匹配所以出错，查看了ubuntu的版本后发现匹配，再继续百度，有教程说需要更改镜像，因此换成了中科大镜像  
![12.png](https://ooo.0o0.ooo/2016/11/11/5825783faac99.png)  
但是对镜像文件不熟悉，在修改的时候也发生了其他错误  
![11.png](https://ooo.0o0.ooo/2016/11/11/5825783fb91a8.png)  
没有注销掉原来镜像文件中的内容导致重复，重新修改后运行通过  
![13.png](https://ooo.0o0.ooo/2016/11/11/5825784015c1f.png)  

在完成ros的安装后，想继续尝试安装cartographer，结果在安装依赖项时其中一项一直无法安装=。=  
因此就放弃了  
![001.png](https://ooo.0o0.ooo/2016/11/11/58257a3d8bef5.png)  
