1.openssl需要1.0，在1.1下编译有问题
    新MacOS下，通过brew install rbenv/tap/openssl@1.0可以安装1.0.2t的openssl，安装完后，还需要手工将/usr/local/Cellar/openssl@1.0/1.0.2t/lib/pkgconfig下的pc文件链接到/usr/local/lib/pkgconfig下，同时在/usr/local/opt创建openssl链接到openssl@1.0

    arm64 请尝试：
    curl -LO https://gist.github.com/minacle/e9dedb8c17025a23a453f8f30eced3da/raw/908b944b3fe2e9f348fbe8b8800daebd87b5966c/openssl@1.0.rb
    brew install --formula --build-from-source ./openssl@1.0.rb

    另请注意，安装python-ESL需要swig3，而MacOS 13下默认安装swig4。

2.configure命令参考：
    CPPFLAGS="-I/opt/homebrew/opt/libks/include/libks -I/opt/homebrew/opt/jpeg/include -I/opt/homebrew/opt/openssl@1.0/include -I/opt/homebrew/opt/sqlite/include -I/opt/homebrew/opt/libtiff/include -I/opt/homebrew/opt/lame/include" LDFLAGS="-L/opt/homebrew/opt/jpeg/lib -L/opt/homebrew/opt/openssl@1.0/lib -L/opt/homebrew/opt/sqlite/lib -L/opt/homebrew/opt/libtiff/lib -L/opt/homebrew/opt/lame/lib" CFLAGS="-g -w" ./configure --prefix=/usr/local/freeswitch-v1.6

3. mod_spandsp和mod_xml_rpc暂时有问题，先禁用