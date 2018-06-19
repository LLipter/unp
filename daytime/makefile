daytime: daytimetcpcli daytimetcpsrv daytimetcpsrvdaemon

daytimetcpcli: daytimetcpcli.c ../llipter.h ../header/lerror.h \
  ../header/../llipter.h ../header/wrapper.h ../header/daemon.h \
  ../header/readwrite.h ../header/sig.h
	gcc daytimetcpcli.c -o c.out

daytimetcpsrv: daytimetcpsrv.c ../llipter.h ../header/lerror.h \
  ../header/../llipter.h ../header/wrapper.h ../header/daemon.h \
  ../header/readwrite.h ../header/sig.h
	gcc daytimetcpsrv.c -o s.out


daytimetcpsrvdaemon: daytimetcpsrvdaemon.c ../llipter.h \
  ../header/lerror.h ../header/../llipter.h ../header/wrapper.h \
  ../header/daemon.h ../header/readwrite.h ../header/sig.h
	gcc daytimetcpsrvdaemon.c -o sd.out

clean:
	rm *.out