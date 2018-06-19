echo: tcpcli tcpserv

tcpcli: tcpcli.c ../llipter.h ../header/lerror.h ../header/../llipter.h \
  ../header/wrapper.h ../header/daemon.h ../header/readwrite.h \
  ../header/sig.h
	gcc tcpcli.c -o c.out

tcpserv: tcpserv.c ../llipter.h ../header/lerror.h \
  ../header/../llipter.h ../header/wrapper.h ../header/daemon.h \
  ../header/readwrite.h ../header/sig.h
	gcc tcpserv.c -o s.out

clean:
	rm *.out