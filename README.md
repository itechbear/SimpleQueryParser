# SimpleQueryParser
A simple query parser using flex and bison

Introduction
============

This is a simple query parser that recognizes logic queries like:

 - this AND that
 - this AND NOT that
 - this AND NOT (he and her)

Compile
=======

 - $ mkdir build
 - $ cd build
 - $ cmake ..
 - $ make

Usage
=====

./parser "this AND that"