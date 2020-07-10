
CC=gcc

SRCS=main.c\
	log.c

OBJS=$(SRCS:.c=.o)

EXEC=TEST

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -lHCCoreDevCfg -lHCGeneralCfgMgr  -lhcnetsdk  -lhpr  -lHCCore
#	$(CC) -o $(EXEC) $(OBJS) -L../../lib64 -lhac_sqldual  -lsqlite3  -lxml2 -lxmlconfig -lunionencrypt

.cpp.o:
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS) $(EXEC) *.log
