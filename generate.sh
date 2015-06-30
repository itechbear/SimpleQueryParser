#!/usr/bin/env bash

DIR=$( cd "$( dirname "$0" )" && pwd )

flex -o lexer.yy.c lexer.l
bison -d parser.y

cd ${DIR}/.out
make
cd ${DIR}
