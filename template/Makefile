SRC=main.cpp
SAMPLE_IN=input.sample
SAMPLE_OUT=output.sample
TARGET_FILE=run
OUTPUT_FILE=output

diff:${TARGET_FILE}
	@  ./${TARGET_FILE} < ${SAMPLE_IN} > ${OUTPUT_FILE} \
	&& diff ${SAMPLE_OUT} ${OUTPUT_FILE} \
	&& echo "correct" \
	|| echo "no correct"

${TARGET_FILE}:${SRC}
	@g++ -std=c++98 ${SRC} -o ${TARGET_FILE}

copy-to-clip:${SRC}
	@xsel -b -i < ${SRC}

clean:
	@rm -rf ${OUTPUT_FILE} ${TARGET_FILE}

.PHONY: diff clean  copy-to-clip
