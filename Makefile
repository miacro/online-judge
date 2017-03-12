OJ_DIR=poj.org
TARGET=
MAKE=make --no-print-directory

all:
	@  cd ${OJ_DIR} \
	&& for VAR in `ls`; \
	   do \
		   ${MAKE} -C $${VAR} ${TARGET}; \
		 done 

all-clean:
	@  ${MAKE} TARGET=clean all

.PHONY: all all-clean
