OJ_DIR=poj.org
TARGET=
MAKE=make --no-print-directory

all:
	@  for VAR in `ls ${OJ_DIR}`; \
	   do \
		   echo -n "${OJ_DIR}/$${VAR} "; \
		   ${MAKE} -C "${OJ_DIR}/$${VAR}" ${TARGET}; \
		 done 

all-clean:
	@  ${MAKE} TARGET=clean all

.PHONY: all all-clean
