#!/bin/bash #>> you are telling your environment/ os to use bash as a command interpreter
arc=$(uname -a) #uname displays information about the system and -a means all information


#grep or "global regular expression print” is a command used in searching
#and matching text files contained in the regular expressions

#awk is a kind of super command with which you can do many things
#for example awk '{ print $2; }' prints the second field of each line

#The /proc/cpuinfo command provides information about
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)

vcpu=$(grep "^processor" /proc/cpuinfo | wc -l) #Provides each processor with an identifying number.
						#If you have one processor it will display a 0.
						#If you have more than one processor it will display
						#all processor information separately counting the processors
						#using zero notation.

#The free command provides information about the total amount of the physical and
#swap memory, as well as the free and used memory
# -m displays the amount of memory in mebibytes
fram=$(free -m | awk '$1 == "Mem:" {print $2}') #Display the free/unused memory

uram=$(free -m | awk '$1 == "Mem:" {print $3}') #Diplay the used memory

pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}') #Display the usage rate as a percentage


#The df command (short for disk free), is used to display information related to
# file systems about total space and available space.
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')

udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')

pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')


cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')


lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')


#here the goal is to know if your VM has dynamic partitions.
#so if you have more than 0 partitions when you type the lsblk command
#then you can display "yes
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)

ctcp=$(ss -neopt state established | wc -l)

ulog=$(users | wc -w)

#hostname command displays the system hostname
ip=$(hostname -I) # -I is used to get all IP(network) addresses

mac=$(ip link show | grep "ether" | awk '{print $2}')

cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#here you will call all the variables that you created above
#and display eveything in an aesthetic way
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
