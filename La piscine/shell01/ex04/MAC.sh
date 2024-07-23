ifconfig | tr -d '\t' | grep ^ether | sed 's/ether //' | sed 's/ //'
