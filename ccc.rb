require 'socket'
require 'ipaddr'
require 'bindata'

class Packet < BinData::Record
  endian :little
  string :name, :read_length => 200
  array :data, :type => :uint8, :initial_length => 200
  int32 :len
end

IP = "224.4.5.6"
PORT = 3334

ip = IPAddr.new(IP).hton + IPAddr.new("0.0.0.0").hton

sock = UDPSocket.new
sock.setsockopt(Socket::IPPROTO_IP, Socket::IP_ADD_MEMBERSHIP, ip)

sock.bind Socket::INADDR_ANY, PORT

loop do
  msg, info = sock.recvfrom(1024)
  p = Packet.new
  p.read msg
  puts p
end
