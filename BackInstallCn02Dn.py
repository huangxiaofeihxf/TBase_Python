import os
import socket
dn01Ip="10.206.0.11";
dn02Ip="10.206.0.11";
gtmIp="";
configUser= "\
\n \
listen_addresses = '0.0.0.0' \n  \
max_connections = 500  \n \
max_pool_size = 65535 \n \
shared_buffers = 1GB  \n \
max_prepared_transactions =  \n \
maintenance_work_mem = 256MB \n \
wal_level = logical \n \
max_wal_senders = 64 \n \
max_wal_size = 1GB  \n \
min_wal_size = 256MB \n  \
log_destination = 'csvlog'  \n \
logging_collector = on \n \
log_directory = 'log' \n \
log_filename = 'postgresql-%Y-%m-%d_%H.log' \n \
log_min_duration_statement = 0 \n  \
synchronous_commit = local  \n \
synchronous_standby_names = '' \n \
dynamic_shared_memory_type = none \n \
";
cnConfig= "\
\n \
listen_addresses = '*' \n  \
port=15432 \n  \
max_connections = 500 \n  \
max_pool_size = 65535  \n  \
shared_buffers = 1GB \n \
max_prepared_transactions = 2000  \n  \
maintenance_work_mem = 256MB  \n  \
wal_level = logical  \n  \
max_wal_senders = 64  \n \
max_wal_size = 1GB \n \
min_wal_size = 256MB \n \
log_destination = 'csvlog' \n \
logging_collector = on \n \
log_directory = 'log' \n \
log_filename = 'postgresql-%Y-%m-%d_%H.log' \n \
log_min_duration_statement = 0  \n \
synchronous_commit = local \n \
synchronous_standby_names = '' \n \
";

dnConfig= "\
\n \
listen_addresses = '*'  \n  \
max_connections = 1000  \n  \
max_pool_size = 65535  \n  \
shared_buffers = 1GB \n \
max_prepared_transactions = 2000  \n  \
maintenance_work_mem = 256MB  \n  \
wal_level = logical  \n  \
max_wal_senders = 64  \n  \
max_wal_size = 1GB  \n  \
min_wal_size = 256MB  \n  \
log_destination = 'csvlog'  \n  \
logging_collector = on  \n  \
log_directory = 'log'  \n  \
log_filename = 'postgresql-%Y-%m-%d_%H.log'   \n  \
log_min_duration_statement = 0  \n  \
synchronous_commit = local  \n  \
synchronous_standby_names = ''  \n  \
";

baseConfigParam = " \
mkdir /data/tbase \n  \
mkdir /data/tbase/global \n  \
mkdir /data/tbase/cn02  \n \
mkdir /data/tbase/dn01  \n \
mkdir /data/tbase/dn02 \n \
chmod -R 0700 /data/tbase/dn01 \n \
chmod -R 0700 /data/tbase/dn02 \n \
echo 'export TBASE_HOME=/data/bin/tbase' >> ~/.bashrc \n  \
echo 'export PATH=$TBASE_HOME/bin:$PATH' >> ~/.bashrc \n \
echo 'export LD_LIBRARY_PATH=$TBASE_HOME/lib:$LD_LIBRARY_PATH' >> ~/.bashrc \n \
source ~/.bashrc \n  \
pg_basebackup -p 23001 -h "+dn01Ip+" -U tbase -D /data/tbase/dn01/ -X f -P -v \n \
pg_basebackup -p 23002 -h "+dn02Ip+" -U tbase -D /data/tbase/dn02/ -X f -P -v  \n \
initdb --locale=en_US.UTF-8 -U tbase -E utf8 -D /data/tbase/cn02/ --nodename=cn02 --nodetype=coordinator --master_gtm_nodename gtm_1 --master_gtm_ip "+gtmIp+" --master_gtm_port 21000\
"
updateCNO2Pghba = "\
\n \
host    all             all             "+dn01Ip.rsplit(".",1)[0]+".0/24           trust \n  \
host    replication     all             "+dn01Ip.rsplit(".",1)[0]+".0/24           trust  \n \
host    replication     all             "+dn02Ip.rsplit(".",1)[0]+".0/24           md5  \n \
";
updateCN01Param = "\
\n \
include_if_exists ='/data/tbase/global/cn.conf' \n  \
";

updateDN01Param = "\
\n \
standby_mode = on \n \
primary_conninfo = 'host = "+dn01Ip+" port = 23001 user = tbase application_name = s1' \
";
updateDN02Param = "\
\n \
standby_mode = on \n \
primary_conninfo = 'host = "+dn02Ip+" port = 23002 user = tbase application_name = s1' \
";
startParam="pg_ctl start -Z coordinator -D /data/tbase/cn02/ \n \
pg_ctl -Z datanode start -D /data/tbase/dn01/ \n \
pg_ctl -Z datanode start -D /data/tbase/dn02/ \n \
";
def baseConfigInit ():
    print("-----开始安装tbase----")
    baseConfigResult = os.system(baseConfigParam)
    createFile("/data/tbase/global/cn.conf",cnConfig)
    createFile("/data/tbase/global/dn.conf",dnConfig)
    print("基础配置"+str(baseConfigResult))
def updateBackDNConfig():
    createFile("/data/tbase/dn01/recovery.conf",updateDN01Param)
    createFile("/data/tbase/dn02/recovery.conf",updateDN02Param)
def updateCN02Config():
    createFile("/data/tbase/cn02/postgresql.conf",updateCN01Param)
    createFile("/data/tbase/cn02/pg_hba.conf", updateCNO2Pghba)
def start():
    startGtmResult = os.system(startParam)
    print("启动" + str(startGtmResult))
def createFile(path,content):
    file = open(path, "a")
    file.write(content);
    file.close()
if __name__ == '__main__':
    baseConfigInit();
    updateBackDNConfig()
    updateCN02Config()
    start();
    print("------------------安装完成--------------")