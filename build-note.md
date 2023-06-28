MacOS Ventura下编译：
1. sqlite和libks的pkg-config有可能需要修改(或者直接通过CPPFLAGS LDFLAGS配置)
2. M1下若enable libvpx，需要在configure之后，修改Makefile，在libvpx的编译命令行中加入--target=generic-gnu选项，或者configure时--disable-libvpx；
3. 当前（2023-06-06）编译xml-rpc有问题，暂时禁用。

configure参数（CFLAGS -g则可debug，-w忽略所有警告）：
CPPFLAGS="-I/opt/homebrew/opt/libks/include/libks -I/opt/homebrew/opt/jpeg/include -I/opt/homebrew/opt/openssl@1.1/include -I/opt/homebrew/opt/sqlite/include -I/opt/homebrew/opt/libtiff/include -I/opt/homebrew/opt/lame/include" LDFLAGS="-L/opt/homebrew/opt/jpeg/lib -L/opt/homebrew/opt/openssl@1.1/lib -L/opt/homebrew/opt/sqlite/lib -L/opt/homebrew/opt/libtiff/lib -L/opt/homebrew/opt/lame/lib" CFLAGS="-g -w" ./configure --prefix=/usr/local/freeswitch-v1.10