# Arduino Files

In this subfolder you, there is a track of the work done on arduino. Some of the experiments are no longer requried but it is a gread addition if you are starting out new.

## CheckIP

The checkIP command will give you the IP of your nodeMCU / generic ESP2866 device.

## tcpServer

tcpServer contains the most basic working prototype of how to send any data over as a clinet to any server. The current server is a simple socket coded / taken as a reference from python socket lib and is given under ```python/test_server.py```. In order for a unidirectional communication do the following:

* Know your computers IP address on your WiFi network, In Linux you can do this by using ```ifconfig``` command.
* Put this IP address in the host IP on the ```.ino``` file.
* Put your ```ssid``` and ```password``` for your network.

Run your python script and then flash your nodeMCU. 
