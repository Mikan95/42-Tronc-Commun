#!/usr/bin/bash

#Create variables for all data types
#########################################################################################
#ARCHITECTURE
arc=$(uname -a)

#PHYSICAL CPU
cpu=$(lscpu | awk '$1 == "CPU(s):" {print $2}')

#VIRTUAL CPU
vcpu=$(nproc)

#MEMORY USAGE
total_mem=$(free --mega | awk '$1 == "Mem:" {print $2}')
used_mem=$(free --mega | awk '$1 == "Mem:" {print $3}')
mem_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

#DISK USAGE
total_disk=$(df -h --total | awk '$1=="total" {print $2}')
used_disk=$(df -h --total | awk '$1=="total" {print $3}')
disk_percent=$(df -h --total | awk '$1=="total" {print $5}')

#CPU LOAD
cpu_load=$(mpstat | awk '$3 == "all" {printf("%.1f"), 100-$13}')

#LAST BOOT TIME
last_boot=$(who -b | awk '$1 == "system" {print $3" "$4}')

#LVM USE
is_lvm=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)

#TCP CONNECTIONS
tcp=$(ss | grep "tcp" | wc -l)

#USER LOG
ulog=$(users | wc -w)

#NETWORK
ip=$(hostname -I)
mac=$(ip -4 link show | grep "ether" | awk '{print $2}')

#SUDO
cmd=$(cat /var/log/sudo | grep "COMMAND" | wc -l)
#########################################################################################

#Broadcast info to all users in a clean and readable format
wall "#Architecture: $arc
#CPU physical : $cpu
#vCPU : $vcpu
#Memory Usage: $used_mem/${total_mem}MB (${mem_percent}%)
#Disk Usage: $used_disk/$total_disk ($disk_percent)
##CPU load: $cpu_load%
#Last boot: $last_boot
#LVM use: $is_lvm
#Connections TCP : $tcp ESTABLISHED
#User log: $ulog
#Network: IP $ip ($mac)
#Sudo : $cmd cmd"
