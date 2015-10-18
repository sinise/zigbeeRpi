#from a new installed jessi instal
#boot and use raspi-conf. do the following
#Expand filesystem
#set Internationalisation option
#set defoult login to shell without log in
# enable device tree if you use bcm2835

apt-get -y update
apt-get -y upgrade
apt-get -y dist-upgrade
rpi-update


# if using the bcm 2835 do this
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.46.tar.gz




#git clone git://git.drogon.net/wiringPi

#Disable power management for the wifi
#echo "# Disable power management" >> /etc/modprobe.d/8192cu.conf
#echo "options 8192cu rtw_power_mgnt=0 rtw_enusbss=0" >> /etc/modprobe.d/8192cu.conf

#copy rasp settings
#cp config.txt /boot/config.txt
#chmod 666 /boot/config.txt


#disabale logs
#to make outologin to shell open /etc/inittab and replace line
#   1:2345:respawn:/sbin/getty --noclear 38400 tty1
#with
#   1:2345:respawn:/bin/login -f pi tty1 </dev/tty1 2>&1
#cp inittab /etc/inittab

#write log and other stuff to ramdisk
#write log and other stuff to ram
echo "tmpfs    /tmp    tmpfs    defaults,noatime,nosuid,size=5m    0 0" >> /etc/fstab
echo "tmpfs    /var/tmp    tmpfs    defaults,noatime,nosuid,size=5m    0 0" >> /etc/fstab
echo "tmpfs    /var/log    tmpfs    defaults,noatime,nosuid,mode=0755,size=5m    0 0" >> /etc/fstab
echo "tmpfs    /var/run    tmpfs    defaults,noatime,nosuid,mode=0755,size=5m    0 0" >> /etc/fstab


#Register chromium as a service
#echo "add chromium as service"
#cp chromium.sh /etc/init.d/
#chmod 777 /etc/init.d/chromium.sh
#update-rc.d chromium.sh defaults
#echo "done"

#set .xinitrx and .xserverrc
#cp .xinitrc /home/pi/
#cp .xserverrc /home/pi/

#setup cron job
#append the cronjobs to the tmpcron file
#echo "setup cron jobs"
#echo "*/1 * * * * python /home/pi/pcloud/sendStatus.py" > tmpcron
#crontab tmpcron
#echo "added the following cronjobs"
#cat tmpcron
#rm tmpcron
#echo "done"
