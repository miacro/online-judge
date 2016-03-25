src=main.cpp
data=input.sample
result=output.sample
target=main
temp_file=/tmp/temp.sample

test:${data} ${target} ${result}
	-@./${target} < ${data} > ${temp_file} && \
	diff ${result} ${temp_file} && echo "correct" || echo "not correct"

${target}:${src}
	@g++ -std=c++11 ${src} -o ${target}

to_clip:${src}
	@xsel -b -i < ${src}
clean:
	-@rm -rf ${target}
