Simple implementation of smart pointer  
- [x] shared_ptr
- [x] weak_ptr
- [ ] unique_ptr

# Environment
 -Ubuntu 16.04
 -make 4.2
 -g++ 7.5.0

 **When using g++5, specify -std=c++11 in the makefile does not work, I am still not sure if g++5 was the cause, but when I upgraded to g++7, the problem disappeared.**  

# Appendix
 install gcc7 & g++7 in Ubuntu 16.04  
   
 ```shell
 sudo add-apt-repository ppa:ubuntu-toolchain-r/test
 sudo apt-get update
 sudo apt-get install gcc-7
 sudp apt-get install g++-7

 sudo update-alternative --install /usr/bin/gcc gcc /usr/bin/gcc-7 100
 sudo update-alternative --config gcc

 sudo update-alternative --install /usr/bin/g++ g++ /usr/bin/g++-7 100
 sudo update-alternative --config g++
 ```


 
