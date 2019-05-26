QT.network.enabled_features = networkinterface bearermanagement dnslookup ftp http localserver networkdiskcache networkproxy socks5 ssl udpsocket
QT.network.disabled_features = dtls opensslv11 sctp
QT.network.QT_CONFIG = networkinterface bearermanagement corewlan ftp getifaddrs http ipv6ifname localserver networkdiskcache networkproxy socks5 ssl udpsocket
QT.network.exports = 
QT.network_private.enabled_features = corewlan securetransport system-proxies
QT.network_private.disabled_features = openssl-linked openssl libproxy linux-netlink
QT.network_private.libraries = network
QMAKE_LIBS_NETWORK = 
