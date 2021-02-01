yum install -y git
git clone https://gitee.com/xinoso/tbase-bin.git
adduser tbase
mkdir -p /data/tbase
cd tbase-bin
mv * /data/
chown -R tbase:tbase /data/
su tbase
echo "初始化完成"