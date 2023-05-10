ifconfig -a ether | grep ether | sed 's/.*ether.//' | tr -d ' '
