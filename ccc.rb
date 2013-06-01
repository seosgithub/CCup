require 'socket'
require 'ipaddr'
require 'bindata'
require 'colorize'

class Packet < BinData::Record
  endian :little

  string :name, :length => 100
  uint8 :len
  array :message, :type => :uint8, :initial_length => 200
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

  print "> "
  name = p.name.to_s
  pos = name =~ /\x00/
  name = name[0...pos]
  print name.green + " ["

  p.len.times do |i|
    if p.message[i].to_i == 0
      print "#{p.message[i].to_i.to_s(16)}".red
    else
      print "#{p.message[i].to_i.to_s(16)}"
    end
    print ", " if i != p.len-1
  end
  print "]"
  print "\n"

  #require 'pry'; binding.pry
  #print "#{p.name}" 
  #p.len.times do |i|
    #print p.message[i].inspect
  #end
  #print "\n"
end
