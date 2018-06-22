echoudp: udpcli udpserv


udpcli: udpcli.c ../llipter.h ../header/lerror.h ../header/../llipter.h \
  ../header/wrapper.h ../header/daemon.h ../header/readwrite.h \
  ../header/sig.h ../header/sockaddr.h
	gcc udpcli.c -o c.out

udpserv: udpserv.c ../llipter.h ../header/lerror.h \
  ../header/../llipter.h ../header/wrapper.h ../header/daemon.h \
  ../header/readwrite.h ../header/sig.h ../header/sockaddr.h
	gcc udpserv.c -o s.out

clean:
	rm *.out