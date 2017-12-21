# compile
CC = g++

all: test

test:
        $(CC) -g -I/*lib_path*/include/ -D__STDC_LIMIT_MACROS -L/*lib_path*/lib/ ./readingvcf.cpp -lhts -lz -lgcov -lpthread -o test_readingvcf

# execute
        ./test_readingvcf ./test.vcf
