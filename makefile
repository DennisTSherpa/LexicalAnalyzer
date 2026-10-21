#
# makefile
# A build configuration file for the Eagle progamming language scanner
# Author: Dennis Sherpa - sherpad@bc.edu
#

APP = eagle_scanner
LEX = eagle.lex
SRC = lex.yy.cc
FLAGS = -Wall -Werror -std=c++17

${APP} : ${LEX} eagle.h main.cpp
	flex ${LEX}
	g++ ${FLAGS} ${SRC} main.cpp -o $@

clean:
	rm -f ${APP} ${SRC}
