import os
import socket
ip="10.206.0.11";
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
mkdir /data/tbase/gtm  \n \
mkdir /data/tbase/dn01 \n \
echo 'export TBASE_HOME=/data/bin/tbase' >> ~/.bashrc \n  \
echo 'export PATH=$TBASE_HOME/bin:$PATH' >> ~/.bashrc \n \
echo 'export LD_LIBRARY_PATH=$TBASE_HOME/lib:$LD_LIBRARY_PATH' >> ~/.bashrc \n \
source ~/.bashrc \n  \
initgtm -Z gtm -D /data/tbase/gtm/ \n \
"
updateGtmParam= "\
\n \
nodename = gtm_1 \n  \
listen_addresses = '*'  \n \
port = 21000  \n \
startup = ACT  \n \
";
updateDNO1Param = "\
\n \
port = 23001 \n  \
pooler_port = 24001  \n \
include_if_exists ='/data/tbase/global/dn.conf'   \n \
";
updateDNO1Pghba = "\
\n \
host    all             all             "+ip.rsplit(".",1)[0]+".0/24           trust \n  \
host    replication     all             "+ip.rsplit(".",1)[0]+".0/24           trust  \n \
";
startGtmParam="gtm_ctl -Z gtm -D /data/tbase/gtm/ start \n \
pg_ctl -Z datanode start -D /data/tbase/dn01/ \n \
";
dno1InitParam="initdb --locale=en_US.UTF-8 -U tbase -E utf8 -D /data/tbase/dn01 --nodename=dn01 --nodetype=datanode --master_gtm_nodename gtm_1 --master_gtm_ip "+ip+" --master_gtm_port 21000";

def baseConfigInit ():
    print("-----开始安装tbase----")
    baseConfigResult = os.system(baseConfigParam)
    createFile("/data/tbase/global/cn.conf",cnConfig)
    createFile("/data/tbase/global/dn.conf",dnConfig)
    print("基础配置"+str(baseConfigResult))

def updateGTMConfigInt():
    createFile("/data/tbase/gtm/gtm.conf",updateGtmParam)
def start():
    startGtmResult = os.system(startGtmParam)
    print("启动------gtm-dn01---" + str(startGtmResult))
def updateDN01ConfigInit():
    startGtmResult = os.system(dno1InitParam)
    print("初始化dn01----"+str(startGtmResult))
    createFile("/data/tbase/dn01/postgresql.conf",updateDNO1Param)
    createFile("/data/tbase/dn01/pg_hba.conf",updateDNO1Pghba)
def createFile(path,content):
    file = open(path, "a")
    file.write(content);
    file.close()
if __name__ == '__main__':
    baseConfigInit()
    updateGTMConfigInt()
    updateDN01ConfigInit()
    start()
    print("------------------安装完成--------------")
